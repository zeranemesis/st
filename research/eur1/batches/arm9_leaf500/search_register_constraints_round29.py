#!/usr/bin/env python3
"""Round29: compare alternative *zero-byte* ARM compiler register constraints.

This explores Clang ARMv5TE output changes from input-only, early-clobber
read/write, combined-register and compiler memory barriers, applied to
previously unmatched original C register-state translations.

All candidate ARM opcode spans are checked against the *whole* original
function's reference SHA256, with referenced 4-byte Clang literal-pool
trailers tracked independently from strict complete-section SHA256 matches.

Read-only search: never edits original C shards or manifest; requires no
original Nintendo ROM data or proprietary CodeWarrior.
"""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import tempfile

from verify_fifth500 import FLAGS, elf32_sections
from audit_literal_pools_round20 import arm_pc_literal_references
from search_barriers_round23 import symbol

HERE=Path(__file__).resolve().parent
FUNCTION=re.compile(r"^uint32_t (st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$",re.M)
REGISTER_ASSIGN=re.compile(r"\b(r(?:0|1|2|3|12))\s*=\s*[^;{}]+;")
TAIL=re.compile(r"\s*return r0;\s*}\s*$")
VOL=re.compile(r"\*\(\((u?int(?:8|16|32)_t)\s*\*\)")
FORMS=[
    ("readonly",lambda r,prev:f'__asm__ __volatile__("" : : "r"({r}));'),
    ("earlyclobber",lambda r,prev:f'__asm__ __volatile__("" : "+&r"({r}));'),
    ("memory_read",lambda r,prev:f'__asm__ __volatile__("" : : "r"({r}) : "memory");'),
    ("tied_input",lambda r,prev:f'__asm__ __volatile__("" : "=r"({r}) : "0"({r}));'),
    ("memory_only",lambda r,prev:'__asm__ __volatile__("" ::: "memory");'),
    ("readpair",lambda r,prev:f'__asm__ __volatile__("" : : "r"({r}), "r"({prev}));' if prev is not None and prev!=r else None),
]

def transform(line,name):
    if not TAIL.search(line):return []
    assignments=[(m.end(),m[1]) for m in REGISTER_ASSIGN.finditer(line)]
    if not assignments:return []
    # Preserve meaningful signed comparisons and condition blocks.
    positions=list(range(min(9,len(assignments))))
    positions.extend(range(max(9,len(assignments)-4),len(assignments)))
    positions=sorted(set(positions))
    output=[]
    for pos in positions:
        end,reg=assignments[pos]
        prev=assignments[pos-1][1] if pos else None
        for mode,make in FORMS:
            asm=make(reg,prev)
            if asm is None:continue
            for use_volatile in (False,True):
                for has_return in (False,True):
                    patched=line[:end]+" "+asm+" "+line[end:]
                    if use_volatile:
                        patched=VOL.sub(r"*((volatile \1*)",patched)
                    if not has_return:
                        patched=patched.replace(f"uint32_t {name}(",f"void {name}(",1)
                        patched=TAIL.sub(" }",patched)
                    signature=(
                        f"{mode}_{pos}_volatile{int(use_volatile)}_return{int(has_return)}"
                    )
                    output.append((signature,patched))
    return output

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clang",default="clang")
    ap.add_argument("--out",type=Path,default=Path("build/eur1/round29_register_constraints.json"))
    args=ap.parse_args()
    manifest=json.loads((HERE/"manifest_fifth500.json").read_text(encoding="utf-8"))
    outstanding={symbol(x):x for x in manifest["functions"]
                 if x["clang_standalone_status"]!="exact_original_machine_bytes"
                 and not x.get("clang_instruction_prefix_status")}
    generated={}
    srcs=[]
    searched=set()
    for shard in range(1,6):
        content=(HERE/f"arm9_leaf_500_part{shard}.c").read_text(encoding="utf-8")
        for line in FUNCTION.finditer(content):
            name=line[1]
            rec=outstanding.get(name)
            if rec is None:continue
            # Small instruction spans and high-reference functions are
            # most actionable for selective optimization analysis.
            if rec["size_bytes"]>44 and rec["direct_BL_references"]<9:
                continue
            variants=transform(line[0],name)
            for j,(description,source) in enumerate(variants):
                new_name=f"{name}_r29_v{j}"
                source=source.replace(f"{name}(",f"{new_name}(",1)
                if new_name in generated:
                    raise ValueError("Candidate symbol collision "+new_name)
                generated[new_name]=(rec,description,source)
                srcs.append(source)
                searched.add(name)
    if len(searched)<100 or len(srcs)<5000:
        raise ValueError(f"Too few generated candidates {len(searched)} functions, {len(srcs)} variants")
    sections={}
    with tempfile.TemporaryDirectory(prefix="st_round29_") as tmp:
        for start in range(0,len(srcs),1250):
            end=min(len(srcs),start+1250)
            src=Path(tmp)/f"variants_{start}.c"
            obj=Path(tmp)/f"variants_{start}.o"
            src.write_text("#include <stdint.h>\n"+"\n".join(srcs[start:end]),encoding="utf-8")
            proc=subprocess.run([args.clang,*FLAGS,"-c",str(src),"-o",str(obj)],
                                capture_output=True,text=True,timeout=180)
            if proc.returncode:
                raise RuntimeError(f"Clang ARM variant compilation failed {start}-{end}: "+
                                   proc.stderr[-5500:])
            compiled=elf32_sections(obj.read_bytes())
            if sections.keys() & compiled.keys():
                raise ValueError("Duplicate compiled ELF sections")
            sections.update(compiled)
            print(f"COMPILED_BATCH {end}/{len(srcs)}",flush=True)
    if len(sections)!=len(generated):
        raise ValueError(f"Compiled {len(sections)} of {len(generated)} source variants")
    matches={}
    matched_variants={"strict":0,"opcode_literal":0}
    for name,(rec,description,source) in generated.items():
        candidate=sections[".text."+name]
        n=rec["size_bytes"]
        digest=rec["original_span_sha256"]
        if len(candidate)==n and hashlib.sha256(candidate).hexdigest()==digest:
            mode="strict"
        elif (len(candidate)==n+4
              and hashlib.sha256(candidate[:n]).hexdigest()==digest
              and any(ref["literal_target_offset"]==n
                      for ref in arm_pc_literal_references(candidate,n))):
            mode="opcode_literal"
        else:continue
        matched_variants[mode]+=1
        base=name.rsplit("_r29_v",1)[0]
        row={
            "name":base,"module":rec["module"],"address":rec["address"],
            "original_size":n,"compiled_size":len(candidate),
            "match_level":mode,"variant_description":description,
            "source":source.replace(f"{name}(",f"{base}(",1),
            "original_instruction_sha256":digest,
        }
        prior=matches.get(base)
        if prior is None or (mode=="strict" and prior["match_level"]!="strict"):
            matches[base]=row
    results={
        "phase":"Round29 alternative compiler register constraints, no ROM",
        "baseline_opcode_exact":manifest["summary"]["standalone_clang_exact_original_instruction_spans_total"],
        "original_candidates_scanned":len(searched),
        "compiled_variants":len(generated),
        "matching_variants":matched_variants,
        "new_exact_original_functions":len(matches),
        "new_strict":sum(x["match_level"]=="strict" for x in matches.values()),
        "new_opcode_literal":sum(x["match_level"]=="opcode_literal" for x in matches.values()),
        "matches":sorted(matches.values(),key=lambda x:x["name"]),
    }
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(results,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {len(generated)} Clang ARM functions compiled for {len(searched)} original candidates")
    print(f"NEW_EXACT {len(matches)} strict={results['new_strict']} opcode_literal={results['new_opcode_literal']}")
    for item in results["matches"]:
        print(f"NEW_MATCH {item['name']} {item['match_level']} {item['variant_description']} {item['original_size']} ARM bytes")
    print("Report:",args.out)

if __name__=="__main__":
    main()
