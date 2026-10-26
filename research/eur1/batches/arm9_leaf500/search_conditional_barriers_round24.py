#!/usr/bin/env python3
"""Search Clang ARMv5TE exact EUR1 matches with conditional C + empty barriers.

New round24 search targets previously unmatched functions with conditional
control flow. It combines the original register-state translation or typed
single-CMP/TST reconstructions with compiler-only zero-byte asm barriers
after individual assignments inside their branches.

Compares SHA256 of *every* original ARM instruction against owner-reference
hash; permits a single trailing PC-relative LDR literal only when separately
verified. All operations are read-only; never use CodeWarrior or original ROM.
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
import search_conditional_round16 as conditional
import search_grouped_round16 as grouped
import search_bit_tests_round17 as bit

HERE = Path(__file__).resolve().parent
SYM = re.compile(r"^uint32_t (st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$", re.M)
SEPARATOR = "unsigned Z=0,N=0,C=0,V=0;"
ASSIGN = re.compile(r"\b(r(?:0|1|2|3|12))\s*=\s*[^;{}]+;")
HEADER = "#include <stdint.h>\n"


def name_of(rec: dict) -> str:
    m = "arm9" if rec["module"] == "arm9" else f"ov{int(rec['module']):03d}"
    return f"st_{m}_{int(rec['address'], 16):08X}"


def source_bases(raw_line: str, name: str):
    # Keep the unmodified C simulation as one candidate family:
    # this code is already known to compile, so the only change is
    # an empty compiler barrier on a register value.
    result = [("original", raw_line + "\n")]
    if SEPARATOR not in raw_line:
        return result
    body = raw_line.split(SEPARATOR, 1)[1]
    for i in [0, 1, 6, 7, 12, 13]:
        src = grouped.variant(body, name + "_grp", i)
        if src is not None:
            result.append((f"group{i}", src))
    for i in [0, 1]:
        src = conditional.variant(body, name + "_cond", i)
        if src is not None:
            result.append((f"cond{i}", src))
    for i in [0, 4]:
        src = bit.gen(body, name + "_bits", i)
        if src is not None:
            result.append((f"bits{i}", src))
    return result


def barriers(source: str, name: str):
    # Look only at assignment expressions in the *function body*.
    # All generated C uses explicit block bodies for conditionals.
    locations = [(m.end(), m[1]) for m in ASSIGN.finditer(source)]
    if not locations:
        return []
    # Keep this search bounded and deterministic, while including the
    # last instructions that control the compiler's return ABI.
    placements = []
    for j in list(range(min(len(locations), 8))) + list(range(max(8, len(locations)-3), len(locations))):
        if j < len(locations):
            placements.append((f"one{j}", [j]))
    for j in range(min(7, len(locations)-1)):
        placements.append((f"pair{j}", [j,j+1]))
    placements.extend([
        ("all", list(range(len(locations)))),
        ("ends", [0,len(locations)-1]),
        ("last3", list(range(max(0,len(locations)-3),len(locations)))),
        ("all_but_last", list(range(max(0,len(locations)-1)))),
    ])
    seen = set()
    variants = []
    for label, indices in placements:
        positions = frozenset(indices)
        if not positions or positions in seen:
            continue
        seen.add(positions)
        # An empty "+r" asm imposes the same value-register dependency
        # as the former successful round23 source rewrites.
        parts = []
        prev = 0
        for idx in sorted(positions):
            end, reg = locations[idx]
            parts.append(source[prev:end])
            parts.append(f' __asm__ __volatile__("" : "+r"({reg})); ')
            prev = end
        parts.append(source[prev:])
        candidate = "".join(parts)
        variants.append((label,candidate))
        # Also try LLVM memory clobber (no runtime instructions);
        # unlike adding volatile to all pointers, it preserves types.
        clobbered = candidate.replace('__asm__ __volatile__("" : "+r"(', '__asm__ __volatile__("" : "+r"(')
        clobbered = clobbered.replace(')); ', ') : : "memory"); ')
        variants.append((label+"_memory",clobbered))
    return variants


def main() -> None:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--clang", default="clang")
    p.add_argument("--out", type=Path, default=Path("build/eur1/round24_conditional_barriers.json"))
    args = p.parse_args()
    data = json.loads((HERE/"manifest_fifth500.json").read_text(encoding="utf-8"))
    outstanding = {name_of(row):row for row in data["functions"]
                   if row["clang_standalone_status"] != "exact_original_machine_bytes"
                   and not row.get("clang_instruction_prefix_status")}
    emitted = []
    candidates = {}
    original_names = set()
    by_family = {}
    for shard in range(1, 6):
        code = (HERE/f"arm9_leaf_500_part{shard}.c").read_text(encoding="utf-8")
        for mat in SYM.finditer(code):
            name = mat[1]
            if name not in outstanding or SEPARATOR not in mat[0]:
                continue
            if "if (" not in mat[0] and "{ uint" not in mat[0]:
                continue
            for kind, source in source_bases(mat[0],name):
                body_start = source.find("{")
                if body_start < 0:
                    raise ValueError("No function block for "+name)
                for j,(strategy,version) in enumerate(barriers(source,name)):
                    suffix = f"_{kind}_v{j}"
                    variant_name = name + "_conditionalbar" + suffix
                    # Both source families begin with one function symbol,
                    # either our name or an old generator's temp suffix.
                    header = re.search(
                        r"\b(?:uint32_t|void)\s+([A-Za-z0-9_]+)\(",
                        version
                    )
                    if header is None:
                        raise ValueError("No generated C function signature")
                    code_name = header[1]
                    renamed = version.replace(code_name+"(",variant_name+"(",1)
                    if variant_name in candidates:
                        raise ValueError("Duplicate function symbol "+variant_name)
                    candidates[variant_name]=(outstanding[name],strategy,kind,renamed)
                    emitted.append(renamed)
                    original_names.add(name)
                    by_family[kind] = by_family.get(kind,0)+1
    if len(candidates)<1000 or len(original_names)<50:
        raise ValueError(f"Insufficient conditional candidates: {len(candidates)} / {len(original_names)}")
    with tempfile.TemporaryDirectory(prefix="st_round24_conditional_") as tmp:
        src=Path(tmp)/"conditional.c"
        obj=Path(tmp)/"conditional.o"
        src.write_text(HEADER+"\n".join(emitted),encoding="utf-8")
        proc=subprocess.run([args.clang,*FLAGS,"-c",str(src),"-o",str(obj)],
                            capture_output=True,text=True,timeout=180)
        if proc.returncode:
            raise RuntimeError("Clang candidate compile failed: "+proc.stderr[-5000:])
        compiled=elf32_sections(obj.read_bytes())
    if len(compiled)!=len(candidates):
        raise ValueError(f"Unexpected sections: {len(compiled)}/{len(candidates)}")
    matches={}
    counts={"strict":0,"prefix":0}
    for name,(rec,strategy,kind,source) in candidates.items():
        opcodes=compiled[".text."+name]
        size=rec["size_bytes"]
        digest=rec["original_span_sha256"]
        if len(opcodes)==size and hashlib.sha256(opcodes).hexdigest()==digest:
            level="strict"
        elif (len(opcodes)==size+4
              and hashlib.sha256(opcodes[:size]).hexdigest()==digest
              and any(r["literal_target_offset"]==size
                      for r in arm_pc_literal_references(opcodes,size))):
            level="prefix"
        else:
            continue
        counts[level]+=1
        original=name.split("_conditionalbar",1)[0]
        candidate={
            "name":original,"module":rec["module"],"address":rec["address"],
            "original_size":size,"level":level,
            "strategy":strategy,"family":kind,
            "source":source.replace(name+"(",original+"(",1),
            "original_sha256":digest,
        }
        previous=matches.get(original)
        if previous is None or (level=="strict" and previous["level"]!="strict"):
            matches[original]=candidate
    result={
        "phase":"Round24 conditional C reconstruction with compiler-only register barriers",
        "candidate_original_functions":len(original_names),
        "compiled_variants":len(candidates),
        "families":by_family,
        "matching_variants":counts,
        "new_unique_matches":len(matches),
        "strict_new":sum(x["level"]=="strict" for x in matches.values()),
        "prefix_new":sum(x["level"]=="prefix" for x in matches.values()),
        "matches":sorted(matches.values(),key=lambda x:x["name"]),
        "starting_exact_original_instruction_spans":data["summary"]["standalone_clang_exact_original_instruction_spans_total"],
    }
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(result,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {len(candidates)} candidate C variants for {len(original_names)} conditional functions")
    print(f"NEW_EXACT: {len(matches)} (strict={result['strict_new']}, literal={result['prefix_new']})")
    for x in result["matches"]:
        print(f"NEW_MATCH: {x['name']} level={x['level']} size={x['original_size']} family={x['family']} strategy={x['strategy']}")
    print("Report:",args.out)


if __name__=="__main__":
    main()
