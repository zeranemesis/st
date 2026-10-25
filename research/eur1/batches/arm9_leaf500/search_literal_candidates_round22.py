#!/usr/bin/env python3
"""Search C candidate families for new exact EUR Rev1 ARM *instruction* spans.

Unlike full-function-section tests, this checks the entire original instruction
stream SHA256 against the leading Clang ARM code and confirms the ONLY trailing
4-byte word is referenced by an ARM PC-relative LDR from the matching code.
Read-only search. Never updates manifest, and requires NO ROM/CodeWarrior.
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
import search_simple_round15 as simple
import search_conditional_round16 as conditional
import search_grouped_round16 as grouped
import search_bit_tests_round17 as bit
import search_straight_round17 as straight
import search_stores_round18 as stores
import search_short_round18 as short

HERE = Path(__file__).resolve().parent
PATTERN = re.compile(r"^uint32_t (st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$", re.M)
MARKER = "unsigned Z=0,N=0,C=0,V=0;"


def function_name(row: dict) -> str:
    mod = "arm9" if row["module"] == "arm9" else f"ov{int(row['module']):03d}"
    return f"st_{mod}_{int(row['address'],16):08X}"


def variants_for(line: str, name: str):
    body = line.split(MARKER, 1)[1]
    out = []
    sem = simple.extract_body(line)
    if sem is not None:
        for i in range(8):
            out.append(("simple", i, simple.emit(sem, name+"_simple", i)))
    for i in range(6):
        src = conditional.variant(body, name+"_cond", i)
        if src is not None:
            out.append(("cond", i, src))
    for i in range(18):
        src = grouped.variant(body, name+"_group", i)
        if src is not None:
            out.append(("group", i, src))
    for i in range(6):
        src = straight.rewrite(body, name+"_straight", i)
        if src is not None:
            out.append(("straight", i, src))
    for i in range(8):
        src = bit.gen(body, name+"_bit", i)
        if src is not None:
            out.append(("bit", i, src))
    if (stores.ENDING.search(body)
            and "if (" not in body and "uint64_t z" not in body
            and "uint32_t z" not in body and "{" not in body[:-1]
            and stores.ACCESS.search(body)):
        for i in range(16):
            out.append(("stores", i, stores.try_variant(body, name+"_store", i)))
    if line.startswith("uint32_t " + name + "("):
        desc = short.detect(line)
        if desc:
            for i in range(16):
                statement, tail = short.formulation(desc, i)
                if not statement and not tail:
                    continue
                rettype = "uint32_t" if tail or not desc.startswith("store") else "void"
                key = name + "_short_v" + str(i)
                src = (
                    f"{rettype} {key}({short.FIXED_POINTER_PREFIX})"
                    " {\n" + statement + "\n" + tail + "\n}\n"
                )
                out.append(("short", i, src))
    return out


def main() -> None:
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clang",default="clang")
    ap.add_argument("--out",type=Path,
                    default=Path("build/eur1/round22_new_literal_prefixes.json"))
    args=ap.parse_args()
    manifest=json.loads((HERE/"manifest_fifth500.json").read_text(encoding="utf-8"))
    pending={function_name(row):row for row in manifest["functions"]
             if row["clang_standalone_status"]!="exact_original_machine_bytes"
             and not row.get("clang_instruction_prefix_status")}
    generated={}
    emitted=[]
    scanned=set()
    families={}
    for part in range(1,6):
        source=(HERE/f"arm9_leaf_500_part{part}.c").read_text(encoding="utf-8")
        for found in PATTERN.finditer(source):
            name=found[1]
            if name not in pending or MARKER not in found[0]:
                continue
            found_one=False
            for family,idx,code in variants_for(found[0],name):
                generated_name=f"{name}_{family}_v{idx}"
                if generated_name in generated:
                    raise ValueError(f"Candidate collision: {generated_name}")
                # All previous tools generate the symbol as name_FAMILY_vINDEX.
                signature=re.search(r"^\w+\s+([a-zA-Z0-9_]+)\(",code)
                if signature is None or signature[1]!=generated_name:
                    raise ValueError(f"Invalid emitted function symbol {generated_name}: {signature}")
                generated[generated_name]=(pending[name],family,idx,code)
                emitted.append(code)
                families[family]=families.get(family,0)+1
                found_one=True
            if found_one:
                scanned.add(name)
    if len(generated)<1000 or len(scanned)<100:
        raise ValueError(f"Unexpectedly few C candidates: {len(generated)} on {len(scanned)} functions")
    with tempfile.TemporaryDirectory(prefix="st_prefix_round22_") as tmp:
        source=Path(tmp)/"candidates.c"
        output=Path(tmp)/"candidates.o"
        source.write_text("#include <stdint.h>\n"+"\n".join(emitted),encoding="utf-8")
        process=subprocess.run([args.clang,*FLAGS,"-c",str(source),"-o",str(output)],
                               capture_output=True,text=True,timeout=180)
        if process.returncode:
            raise RuntimeError("Candidate compile failed: "+process.stderr[-4500:])
        sections=elf32_sections(output.read_bytes())
    if len(sections)!=len(generated):
        raise ValueError(f"Compiled {len(sections)}/{len(generated)} generated sections")
    matches={}
    variants_with_opcode_match=0
    for emitted_name,(record,family,idx,source_code) in generated.items():
        data=sections[".text."+emitted_name]
        n=record["size_bytes"]
        if len(data)!=n+4 or hashlib.sha256(data[:n]).hexdigest()!=record["original_span_sha256"]:
            continue
        pc_refs=arm_pc_literal_references(data,n)
        if not any(r["literal_target_offset"]==n for r in pc_refs):
            continue
        variants_with_opcode_match+=1
        original=emitted_name.rsplit("_"+family+"_v",1)[0]
        if original not in matches or len(source_code)<len(matches[original]["source"]):
            matches[original]={
                "name":original,"module":record["module"],
                "address":record["address"],"original_arm_instruction_size":n,
                "clang_section_size":len(data),
                "family":family,"variant":idx,
                "sha256_of_original_instruction_span":record["original_span_sha256"],
                "appended_constant_le_hex":data[n:].hex(),
                "pc_relative_ldr_references":pc_refs,
                "source":source_code.replace(emitted_name, original),
                "caveat":"New opcode-span match only; not strict full Clang section match",
            }
    results=sorted(matches.values(),key=lambda x:x["name"])
    report={
        "kind":"Read-only C-variant search for exact original ARM instruction spans plus referenced Clang literal",
        "baseline_strict_full_sections":54,
        "baseline_already_verified_opcode_literal_prefixes":43,
        "original_pending_opcode_functions_scanned":len(scanned),
        "compiled_source_variants":len(generated),
        "variants_by_family":families,
        "all_matching_variants":variants_with_opcode_match,
        "new_unique_opcode_span_matches":len(results),
        "new_matches":results,
    }
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(report,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {len(generated)} Clang ARM candidate C functions, {len(scanned)} original functions")
    print(f"ARM opcode + referenced literal matches (unique NEW addresses): {len(results)}")
    for r in results:
        print(f"NEW_OPCODE_MATCH: {r['name']} ({r['family']} v{r['variant']}, {r['original_arm_instruction_size']} ARM bytes)")
    print("Report:",args.out)


if __name__=="__main__":
    main()
