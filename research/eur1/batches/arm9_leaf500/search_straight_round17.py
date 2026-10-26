#!/usr/bin/env python3
"""Search unbranched fifth-batch Spirit Tracks EUR1 functions for new Clang matches.

Only ROM-reference SHA256 hashes, no CodeWarrior, no game build. Generates
typed source alternatives for original ARM register-state transcriptions
without branch/condition flags. Never updates baseline manifest automatically.
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
BASE = "unsigned Z=0,N=0,C=0,V=0;"
EXIT = re.compile(r"\s*return r0;\s*\}\s*$")
VOLATILE = re.compile(r"\*\(\((u?int(?:8|16|32)_t)\s*\*\)")
POINTER = re.compile(r"\br0\b(?!\s*\+)")
ADDRESS_ASSIGN = re.compile(r"\br(?:[1-9]|1[0-2])\s*=\s*\(\s*r0\s*\+")


def sym(row: dict) -> str:
    module = "arm9" if row["module"] == "arm9" else f"ov{int(row['module']):03d}"
    return f"st_{module}_{int(row['address'], 16):08X}"


def rewrite(body: str, symbol: str, variant: int) -> str | None:
    if not EXIT.search(body) or "if (" in body or "uint64_t z" in body or "uint32_t z" in body:
        return None
    if "{" in body[:-1] or "}" in body[:-1] or "goto" in body:
        return None
    body = EXIT.sub("", body)
    # 0: original pointer volatility; 1: volatile all; 2-5: typed base
    if variant in (2, 3, 4, 5):
        if re.search(r"\br0\s*=", body) or POINTER.search(body) or ADDRESS_ASSIGN.search(body):
            return None
        body = re.sub(r"\br0\b", "object", body)
        typ = "volatile uint8_t *" if variant in (2, 3) else "uint8_t *"
        signature = f"{typ}object"
        returns = "return (uint32_t)(uintptr_t)object;" if variant in (3, 5) else ""
        rettype = "uint32_t" if variant in (3, 5) else "void"
    else:
        signature = "uint32_t r0"
        returns = "return r0;"
        rettype = "uint32_t"
    if variant in (1, 2, 3):
        body = VOLATILE.sub(r"*((volatile \1*)", body)
    return (f"{rettype} {symbol}_v{variant}({signature}, uint32_t r1, "
            f"uint32_t r2, uint32_t r3) {{\nuint32_t r12=0;\n"
            f"{body}\n{returns}\n}}\n")


def main() -> None:
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clang",default="clang")
    ap.add_argument("--out",type=Path,default=Path("build/eur1/round17_straight.json"))
    args=ap.parse_args()
    manifest=json.loads((HERE/"manifest_fifth500.json").read_text(encoding="utf-8"))
    outstanding={sym(r):r for r in manifest["functions"] if r["clang_standalone_status"]!="exact_original_machine_bytes"}
    generated={}
    emitted=[]
    names=set()
    for shard in range(1,6):
        src=(HERE/f"arm9_leaf_500_part{shard}.c").read_text(encoding="utf-8")
        for entry in FUN.finditer(src):
            name=entry[1]
            if name not in outstanding or BASE not in entry[0]:
                continue
            text=entry[0].split(BASE,1)[1]
            for i in range(6):
                made=rewrite(text,name,i)
                if made is not None:
                    generated[f"{name}_v{i}"]=(outstanding[name],made,i)
                    emitted.append(made)
                    names.add(name)
    if len(names)<70:
        raise ValueError(f"Only {len(names)} eligible straight-line functions")
    with tempfile.TemporaryDirectory(prefix="st_round17_") as tmp:
        src=Path(tmp)/"variants.c"
        obj=Path(tmp)/"variants.o"
        src.write_text("#include <stdint.h>\n"+"\n".join(emitted),encoding="utf-8")
        result=subprocess.run([args.clang,*FLAGS,"-c",str(src),"-o",str(obj)],
                              capture_output=True,text=True,timeout=180)
        if result.returncode:
            raise RuntimeError("Clang compilation failed: "+result.stderr[-5000:])
        sections=elf32_sections(obj.read_bytes())
    if len(sections)!=len(generated):
        raise ValueError(f"Clang emitted {len(sections)} / {len(generated)} sections")
    matches={}
    for name,(reference,source,i) in generated.items():
        section=sections[".text."+name]
        if len(section)!=reference["size_bytes"] or hashlib.sha256(section).hexdigest()!=reference["original_span_sha256"]:
            continue
        original=name.rsplit("_v",1)[0]
        if original not in matches or i<matches[original]["variant"]:
            matches[original]={
                "symbol":original,"module":reference["module"],
                "address":reference["address"],"original_size":reference["size_bytes"],
                "variant":i,"source":source.replace(f"{original}_v{i}",original),
                "sha256":reference["original_span_sha256"]
            }
    verified=sorted(matches.values(),key=lambda x:x["symbol"])
    result={"backend":"Clang ARMv5TE standalone -O2","eligible_functions":len(names),
            "compiled_variants":len(generated),
            "new_exact_matches":len(verified),"matches":verified,
            "not_tested":"CodeWarrior, DS C++ integration and real-game runtime"}
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(result,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {len(generated)} ARM variants for {len(names)} distinct original functions")
    print(f"EXACT_NEW: {len(verified)}")
    for row in verified:
        print(f"EXACT: {row['symbol']} {row['original_size']} bytes, variant={row['variant']}")
    print("Report:",args.out)


if __name__=="__main__":
    main()
