#!/usr/bin/env python3
"""Round25: nonadjacent 2/3 empty compiler barriers for ARM straight-line C.

The already published round23 scanner explored isolated barriers, adjacent
pairs, all/last barriers and all-volatile. This scanner explores NEW separated
pairs and sparse triples, with and without volatile memory effects, for
previously unmatched straight-line ARM register translations only.

All candidate instructions are SHA256-checked against original EUR Rev1
function spans. A one-word trailing Clang ARM PC-relative LDR literal may
qualify as a *separate opcode-prefix* match, never a strict section match.
Neither original ROM bytes nor Nintendo CodeWarrior is required.
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
from search_barriers_round23 import FUNCTION, BEGIN, ENDING, REG_WRITE, symbol

HERE=Path(__file__).resolve().parent
RET="return r0;"
BAR='__asm__ __volatile__("" : "+r"({reg}));'

def make_variants(body: str, name: str):
    if not ENDING.search(body):
        return []
    code=ENDING.sub("",body).strip()
    if any(t in code for t in ("if (","uint64_t z","uint32_t z","goto","for (","while (","switch")):
        return []
    if "{" in code or "}" in code:
        return []
    statements=[x.strip()+";" for x in code.split(";") if x.strip()]
    assigned=[(i,m[1]) for i,x in enumerate(statements)
              if (m:=REG_WRITE.fullmatch(x))]
    if len(assigned)<3:
        return []
    indices=list(range(len(assigned)))
    # Pairs that were NOT explored by round23: nonadjacent writes.
    # Triples inserted sparsely; reject three consecutive writes, which
    # is usually equivalent to the existing broad "all" search.
    subsets=[x for x in itertools.combinations(indices,2) if x[1]-x[0]>=2]
    subsets += [x for x in itertools.combinations(indices,3)
                if max(x)-min(x)>=3 and not (x[1]==x[0]+1 and x[2]==x[1]+1)]
    # Restrict explosion on rare huge straight-line functions, while
    # keeping earliest and latest register lifetimes represented.
    if len(subsets)>220:
        subsets=subsets[:120]+subsets[-100:]
    result=[]
    for group_index,group in enumerate(subsets):
        positions={assigned[i][0] for i in group}
        for volatility in (False,True):
            for returned in (True,False):
                lines=[]
                for i,st in enumerate(statements):
                    if volatility:
                        st=re.sub(r"\*\(\((u?int(?:8|16|32)_t)\s*\*\)",
                                  r"*((volatile \1*)",st)
                    lines.append(st)
                    if i in positions:
                        reg=next(reg for ix,reg in assigned if ix==i)
                        lines.append(BAR.format(reg=reg))
                label=f"s{group_index}_v{int(volatility)}_r{int(returned)}"
                signature="uint32_t" if returned else "void"
                tail="\nreturn r0;" if returned else ""
                body_src=(
                    f"{signature} {name}_round25({', '.join('uint32_t r'+str(i) for i in range(4))}) {{\n"
                    "uint32_t r12=0;\n"+"\n".join(lines)+tail+"\n}\n"
                )
                result.append((label,body_src,group,volatility,returned))
    return result


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--clang",default="clang")
    p.add_argument("--out",type=Path,
                   default=Path("build/eur1/round25_sparse_barriers.json"))
    args=p.parse_args()
    manifest=json.loads((HERE/"manifest_fifth500.json").read_text(encoding="utf-8"))
    pending={symbol(r):r for r in manifest["functions"]
             if r["clang_standalone_status"]!="exact_original_machine_bytes"
             and not r.get("clang_instruction_prefix_status")}
    sources=[]
    registry={}
    visited=set()
    for shard in range(1,6):
        text=(HERE/f"arm9_leaf_500_part{shard}.c").read_text(encoding="utf-8")
        for m in FUNCTION.finditer(text):
            name=m[1]
            if name not in pending or BEGIN not in m[0]:
                continue
            body=m[0].split(BEGIN,1)[1]
            variants=make_variants(body,name)
            for j,(label,source,group,volatility,returned) in enumerate(variants):
                generated=f"{name}_r25_v{j}"
                renamed=source.replace(name+"_round25(",generated+"(",1)
                if generated in registry:
                    raise ValueError("Duplicated variant "+generated)
                registry[generated]=(pending[name],label,group,volatility,returned,renamed)
                sources.append(renamed)
                visited.add(name)
    if len(visited)<30 or len(registry)<1000:
        raise ValueError(f"Insufficient straight-line candidates {len(visited)}/{len(registry)}")
    sections={}
    with tempfile.TemporaryDirectory(prefix="st_round25_sparse_") as tmp:
        for start in range(0,len(sources),1400):
            end=min(start+1400,len(sources))
            src=Path(tmp)/f"c{start}.c"
            obj=Path(tmp)/f"c{start}.o"
            src.write_text("#include <stdint.h>\n"+"\n".join(sources[start:end]),encoding="utf-8")
            proc=subprocess.run([args.clang,*FLAGS,"-c",str(src),"-o",str(obj)],
                                capture_output=True,text=True,timeout=180)
            if proc.returncode:
                raise RuntimeError(f"ARM Clang failed batch {start}-{end}: "+proc.stderr[-4000:])
            compiled=elf32_sections(obj.read_bytes())
            if sections.keys() & compiled.keys():
                raise ValueError("Duplicate generated ARM ELF section")
            sections.update(compiled)
            print(f"COMPILED_BATCH: {end}/{len(sources)} ARM variants",flush=True)
    if len(sections)!=len(registry):
        raise ValueError(f"Compiled {len(sections)}/{len(registry)} ARM source candidates")
    matches={}
    levels={"strict":0,"opcode_literal":0}
    for name,(original,label,group,volatile,returned,source) in registry.items():
        binary=sections[".text."+name]
        size=original["size_bytes"]
        expected=original["original_span_sha256"]
        if len(binary)==size and hashlib.sha256(binary).hexdigest()==expected:
            level="strict"
        elif (len(binary)==size+4
              and hashlib.sha256(binary[:size]).hexdigest()==expected
              and any(x["literal_target_offset"]==size
                      for x in arm_pc_literal_references(binary,size))):
            level="opcode_literal"
        else:continue
        levels[level]+=1
        base=name.rsplit("_r25_v",1)[0]
        row={
            "name":base,"module":original["module"],"address":original["address"],
            "original_size":size,"compiled_size":len(binary),"level":level,
            "source":source.replace(name+"(",base+"(",1),
            "subset_assignment_indices":list(group),
            "volatile_memory":volatile,"return_r0":returned,"variant":label,
            "original_sha256":expected,
        }
        if base not in matches or (level=="strict" and matches[base]["level"]!="strict"):
            matches[base]=row
    ordered=sorted(matches.values(),key=lambda x:x["name"])
    results={
        "phase":"sparse compiler barrier combinations on previous nonmatching unbranched functions",
        "original_functions_tested":len(visited),
        "compiled_variants":len(registry),
        "baseline_exact_opcodes":manifest["summary"]["standalone_clang_exact_original_instruction_spans_total"],
        "matching_variants":levels,
        "unique_new_matches":len(ordered),
        "new_strict":sum(x["level"]=="strict" for x in ordered),
        "new_opcode_literal":sum(x["level"]=="opcode_literal" for x in ordered),
        "matches":ordered,
    }
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(results,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {len(registry)} compiled ARM variants for {len(visited)} original functions")
    print(f"NEW_EXACT: {len(ordered)} (strict={results['new_strict']}, literal={results['new_opcode_literal']})")
    for row in ordered:
        print(f"NEW_MATCH: {row['name']} level={row['level']} size={row['original_size']} strategy={row['variant']} barriers={row['subset_assignment_indices']}")
    print("Report:",args.out)


if __name__=="__main__":main()
