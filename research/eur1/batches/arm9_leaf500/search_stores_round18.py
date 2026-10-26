#!/usr/bin/env python3
"""Explore remaining unbranched ARM object mutations using typed C stores.

The fifth-500 previous passes promoted simple functions whose object pointer
was never reassigned. This search extends that evidence-preserving rewrite to
functions with updated r0, nested pointers and dynamic offsets. Candidates
are strictly checked against complete EUR1 owner-ROM SHA256 code spans.
Original compiler, ROM rebuild and C++ linkage are NOT tested.
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

HERE = Path(__file__).resolve().parent
FUN = re.compile(r"^uint32_t (st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$", re.M)
MARK = "unsigned Z=0,N=0,C=0,V=0;"
ENDING = re.compile(r"\s*return r0;\s*}\s*$")
ACCESS = re.compile(r"\*\(\((u?int(?:8|16|32)_t)\s*\*\)")
CAST = re.compile(r"\(uint32_t\)\s*\(\s*\*")

def symbol(x: dict) -> str:
    m = "arm9" if x["module"] == "arm9" else f"ov{int(x['module']):03d}"
    return f"st_{m}_{int(x['address'], 16):08X}"


def try_variant(body: str, name: str, index: int) -> str:
    # Three independent dimensions:
    #     original or pointer-derived r0 input,
    #     explicit volatile stores/loads,
    #     keep or discard output register (candidate ABI).
    pointer_arg = bool(index & 1)
    volatile_access = bool(index & 2)
    returns = bool(index & 4)
    cast_pointer = bool(index & 8)
    if not ENDING.search(body):
        raise ValueError("Not a complete register function")
    src = ENDING.sub("", body)
    if volatile_access:
        src = ACCESS.sub(r"*((volatile \1*)", src)
    if cast_pointer:
        src = src.replace("(uintptr_t)(", "(uintptr_t)(")
        # Keep exact underlying pointer expressions, while exposing
        # 32-bit register loads with their original ARM size and sign.
    if pointer_arg:
        params = "uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3"
        prefix = "uint32_t r0 = (uint32_t)(uintptr_t)object;"
    else:
        params = "uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3"
        prefix = ""
    result = "return r0;" if returns else ""
    rtype = "uint32_t" if returns else "void"
    return (
        f"{rtype} {name}_v{index}({params}) {{\n"
        f"{prefix}\nuint32_t r12=0;\n"
        + src + "\n" + result + "\n}\n"
    )


def main() -> None:
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--clang",default="clang")
    p.add_argument("--out",type=Path,default=Path("build/eur1/round18_store.json"))
    args=p.parse_args()
    orig=json.loads((HERE/"manifest_fifth500.json").read_text(encoding="utf-8"))
    pending={symbol(x):x for x in orig["functions"]
             if x["clang_standalone_status"]!="exact_original_machine_bytes"}
    targets=set()
    variants={}
    codes=[]
    for part in range(1,6):
        text=(HERE/f"arm9_leaf_500_part{part}.c").read_text(encoding="utf-8")
        for mat in FUN.finditer(text):
            name=mat[1]
            if name not in pending or MARK not in mat[0]:
                continue
            body=mat[0].split(MARK,1)[1]
            if (not ENDING.search(body) or
                not re.search(r"\*\(\((?:u?int(?:8|16|32)_t)\*\)",body) or
                "uint64_t z" in body or "uint32_t z" in body or
                "if (" in body or "{" in body[:-1]):
                continue
            targets.add(name)
            for idx in range(16):
                code=try_variant(body,name,idx)
                variants[f"{name}_v{idx}"]=(pending[name],code,idx)
                codes.append(code)
    if len(targets)<80:
        raise ValueError(f"Not enough eligible unbranched stores: {len(targets)}")
    with tempfile.TemporaryDirectory(prefix="st_volatile_round18_") as tmp:
        src=Path(tmp)/"types.c"
        obj=Path(tmp)/"types.o"
        src.write_text("#include <stdint.h>\n"+"\n".join(codes),encoding="utf-8")
        process=subprocess.run([args.clang,*FLAGS,"-c",str(src),"-o",str(obj)],
                               capture_output=True,text=True,timeout=180)
        if process.returncode:
            raise RuntimeError("Clang ARM compilation failed: "+process.stderr[-4500:])
        compiled=elf32_sections(obj.read_bytes())
    if len(compiled)!=len(variants):
        raise ValueError(f"Expected {len(variants)} sections, emitted {len(compiled)}")
    exact={}
    for name,(ref,src,idx) in variants.items():
        insn=compiled[".text."+name]
        if (len(insn)!=ref["size_bytes"] or
            hashlib.sha256(insn).hexdigest()!=ref["original_span_sha256"]):
            continue
        original=name.rsplit("_v",1)[0]
        if original not in exact or idx<exact[original]["variant"]:
            exact[original]={
                "name":original,"module":ref["module"],"address":ref["address"],
                "size":ref["size_bytes"],"variant":idx,
                "source":src.replace(f"{original}_v{idx}",original),
                "sha256":ref["original_span_sha256"]
            }
    found=sorted(exact.values(),key=lambda x:x["name"])
    report={
        "goal":"Existing fifth-batch ROM-free Clang ARM matches",
        "eligible_original_functions":len(targets),
        "compiled_variants":len(variants),
        "new_exact_matches":len(found),
        "matches":found,
        "backend":"Clang ARMv5TE -O2, not Nintendo CodeWarrior"
    }
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(report,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {len(variants)} Clang ARM variants across {len(targets)} original stores")
    print(f"EXACT_NEW: {len(found)}")
    for row in found:
        print("EXACT:",row["name"],row["size"],"bytes variant",row["variant"])
    print("Report:",args.out)


if __name__=="__main__":
    main()
