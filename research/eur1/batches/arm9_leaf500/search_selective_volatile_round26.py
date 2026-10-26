#!/usr/bin/env python3
"""Round26: selectively qualify individual original C memory accesses volatile.

Unlike prior all-or-nothing volatile searches, try one, two, or three
selected ARM memory accesses from each original unmatched function,
including conditional (CMP/TST) functions. Optionally add a compiler-only
memory clobber before return, or use a provisional void signature. Source
candidates are read-only; promote matches only after full source-shard CI.

A result is counted only for full SHA256 of the original EUR1 ARM code span:
either exact complete Clang ARM function section, or exact ARM prefix plus
exactly one 4-byte PC-relative literal proven with LDR decoding.
No CodeWarrior, ROM binary, or privileged DS assets required.
"""
from __future__ import annotations

import argparse
import hashlib
import itertools
import json
from pathlib import Path
import re
import subprocess
import tempfile

from verify_fifth500 import FLAGS, elf32_sections
from audit_literal_pools_round20 import arm_pc_literal_references
from search_barriers_round23 import symbol

HERE=Path(__file__).resolve().parent
FUN=re.compile(r"^uint32_t (st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$",re.M)
POINTER=re.compile(r"\*\(\((u?int(?:8|16|32)_t)\s*\*\)")
RETURN=re.compile(r"\s*return r0;\s*}\s*$")

def variants(line, name):
    accesses=list(POINTER.finditer(line))
    if not accesses or not RETURN.search(line):
        return []
    n=len(accesses)
    singles=[(i,) for i in range(n)]
    pairs=list(itertools.combinations(range(n),2))
    triples=list(itertools.combinations(range(n),3))
    # prioritize first-last and widely separated accesses if many operations
    subsets=singles+pairs+triples
    if len(subsets)>115:
        subsets=subsets[:60]+subsets[-55:]
    outcomes=[]
    for selected in subsets:
        sel=set(selected)
        parts=[];last=0
        for j,m in enumerate(accesses):
            parts.append(line[last:m.start()])
            parts.append(f"*(({'volatile ' if j in sel else ''}{m[1]}*)")
            last=m.end()
        parts.append(line[last:])
        transformed="".join(parts)
        if transformed==line:
            raise ValueError("Selected subset did not alter C memory qualifier")
        for signature in ("uint32","void"):
            for barrier in ("none","memory"):
                tmp=transformed
                if signature=="void":
                    tmp=tmp.replace(f"uint32_t {name}(",f"void {name}(",1)
                    tmp=RETURN.sub(" }",tmp)
                if barrier=="memory":
                    end=tmp.rfind("}")
                    if end<0:raise ValueError("Missing function close")
                    tmp=tmp[:end]+' __asm__ __volatile__("" ::: "memory"); '+tmp[end:]
                outcomes.append((selected,signature,barrier,tmp))
    return outcomes

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clang",default="clang")
    ap.add_argument("--out",type=Path,default=Path("build/eur1/round26_selective_volatile.json"))
    args=ap.parse_args()
    m=json.loads((HERE/"manifest_fifth500.json").read_text(encoding="utf-8"))
    pending={symbol(x):x for x in m["functions"]
             if x["clang_standalone_status"]!="exact_original_machine_bytes"
             and not x.get("clang_instruction_prefix_status")}
    srcs=[];registry={};scanned=set()
    for shard in range(1,6):
        content=(HERE/f"arm9_leaf_500_part{shard}.c").read_text(encoding="utf-8")
        for f in FUN.finditer(content):
            name=f[1]
            if name not in pending:continue
            for i,(group,signature,barrier,code) in enumerate(variants(f[0],name)):
                emitted=f"{name}_v26_{i}"
                code=code.replace(name+"(",emitted+"(",1)
                registry[emitted]=(pending[name],group,signature,barrier,code)
                srcs.append(code)
                scanned.add(name)
    if len(registry)<500 or len(scanned)<70:
        raise ValueError(f"Too few candidates: {len(registry)}, functions {len(scanned)}")
    compiled={}
    with tempfile.TemporaryDirectory(prefix="st_round26_") as tmp:
        for start in range(0,len(srcs),1200):
            end=min(start+1200,len(srcs))
            path=Path(tmp)/f"c{start}.c"
            obj=Path(tmp)/f"c{start}.o"
            path.write_text("#include <stdint.h>\n"+"\n".join(srcs[start:end]),encoding="utf-8")
            process=subprocess.run([args.clang,*FLAGS,"-c",str(path),"-o",str(obj)],
                                   capture_output=True,text=True,timeout=180)
            if process.returncode:
                raise RuntimeError(f"Clang ARM compilation failure {start}:{end}: "+process.stderr[-4500:])
            sections=elf32_sections(obj.read_bytes())
            if sections.keys() & compiled.keys():
                raise ValueError("Duplicate function section")
            compiled.update(sections)
            print(f"COMPILED_BATCH: {end}/{len(srcs)}",flush=True)
    if len(compiled)!=len(registry):
        raise ValueError(f"Missing Clang function sections: {len(compiled)} vs {len(registry)}")
    exact={};levels={"strict":0,"opcode_literal":0}
    for name,(ref,group,signature,barrier,src) in registry.items():
        arm=compiled[".text."+name];size=ref["size_bytes"];digest=ref["original_span_sha256"]
        if len(arm)==size and hashlib.sha256(arm).hexdigest()==digest:
            level="strict"
        elif len(arm)==size+4 and hashlib.sha256(arm[:size]).hexdigest()==digest and any(
                 x["literal_target_offset"]==size for x in arm_pc_literal_references(arm,size)):
            level="opcode_literal"
        else:continue
        levels[level]+=1
        original=name.rsplit("_v26_",1)[0]
        row={"name":original,"module":ref["module"],"address":ref["address"],
             "original_size":size,"compiled_size":len(arm),"level":level,
             "qualify_memory_access_indices":list(group),"signature":signature,
             "compiler_memory_clobber":barrier=="memory",
             "source":src.replace(name+"(",original+"(",1),
             "original_span_sha256":digest}
        old=exact.get(original)
        if old is None or (level=="strict" and old["level"]!="strict"):
            exact[original]=row
    results={
        "phase":"selective per-access C volatile qualifiers with optional memory clobber",
        "original_functions_scanned":len(scanned),
        "compiled_variants":len(registry),
        "starting_opcode_matches":m["summary"]["standalone_clang_exact_original_instruction_spans_total"],
        "matching_variants":levels,
        "new_unique_matches":len(exact),
        "new_strict":sum(x["level"]=="strict" for x in exact.values()),
        "new_opcode_literal":sum(x["level"]=="opcode_literal" for x in exact.values()),
        "matches":sorted(exact.values(),key=lambda x:x["name"]),
    }
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(results,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {len(registry)} compiled Clang variants on {len(scanned)} original EUR1 functions")
    print(f"NEW_EXACT: {len(exact)} (strict={results['new_strict']}, literal={results['new_opcode_literal']})")
    for x in results["matches"]:
        print(f"NEW_MATCH: {x['name']} level={x['level']} size={x['original_size']} access={x['qualify_memory_access_indices']} signature={x['signature']} memory_clobber={x['compiler_memory_clobber']}")
    print("Report:",args.out)

if __name__=="__main__":
    main()
