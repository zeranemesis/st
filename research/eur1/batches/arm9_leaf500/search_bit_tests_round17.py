#!/usr/bin/env python3
"""Exact Clang ARMv5TE search for 29 pending EUR1 ARM TST/AND flag functions.

Translate synthetic ARM Z/N flag state into C masked Boolean expressions,
optionally fold adjacent complementary assignments, and hash entire machine
code against owner-ROM-derived EUR1 manifest SHA256. No CodeWarrior/ROM used.
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
SYM = re.compile(r"^uint32_t (st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$", re.M)
BIT = re.compile(r"\{\s*uint32_t z = (.*?); Z = \(z==0\); N = \(z>>31\); \}")
TAIL = re.compile(r"\s*return r0;\s*\}\s*$")
BOOL_PAIR = re.compile(
    r"if \(!Z\) \{\s*r0 = \(0x1u\);\s*\}\s*"
    r"if \(Z\) \{\s*r0 = \(0x0u\);\s*\}"
)
BOOL_PAIR_REV = re.compile(
    r"if \(Z\) \{\s*r0 = \(0x0u\);\s*\}\s*"
    r"if \(!Z\) \{\s*r0 = \(0x1u\);\s*\}"
)
BIT_SIMPLE = re.compile(r"if \(Z\) \{\s*r0 = \(0x0u\);\s*\}")
IF_SAME = re.compile(r"if \((.*?)\) \{([^{}]*)\}\s+if \(\1\) \{([^{}]*)\}")


def symbol_for(record: dict) -> str:
    module = "arm9" if record["module"] == "arm9" else f"ov{int(record['module']):03d}"
    return f"st_{module}_{int(record['address'],16):08X}"


def fold_same(src: str) -> str:
    while True:
        new = IF_SAME.sub(lambda m: f"if ({m[1]}) {{ {m[2]} {m[3]} }}", src)
        if new == src:
            return src
        src = new


def gen(body: str, name: str, mode: int) -> str | None:
    blocks = list(BIT.finditer(body))
    if len(blocks) != 1 or body.count("uint32_t z = ") != 1:
        return None
    expr = blocks[0][1]
    if not TAIL.search(body):
        return None
    src = body[:blocks[0].start()] + f"unsigned hit = (({expr}) != 0u);" + body[blocks[0].end():]
    src = TAIL.sub("", src)
    # N is an unused byproduct of this particular ARM TST pattern.
    if re.search(r"\bN\b", src):
        return None
    if mode % 4 == 0:
        # Keep individual guards, but use a cached Boolean condition.
        src = src.replace("!Z", "hit").replace("Z", "!hit")
    elif mode % 4 == 1:
        src = BOOL_PAIR.sub("r0 = (hit);", src)
        src = BOOL_PAIR_REV.sub("r0 = (hit);", src)
        src = src.replace("!Z", "hit").replace("Z", "!hit")
    elif mode % 4 == 2:
        src = BOOL_PAIR.sub("r0 = (hit);", src)
        src = BOOL_PAIR_REV.sub("r0 = (hit);", src)
        src = BIT_SIMPLE.sub("r0 &= (uint32_t)-(int32_t)(hit);", src) if False else src
        src = src.replace("!Z", "hit").replace("Z", "!hit")
        src = fold_same(src)
    else:
        src = BOOL_PAIR.sub("r0 = (hit);", src)
        src = BOOL_PAIR_REV.sub("r0 = (hit);", src)
        src = src.replace("!Z", "hit").replace("Z", "!hit")
        src = fold_same(src)
    # Source variants: regular typed loads/stores and volatile typed access.
    if mode >= 4:
        src = re.sub(r"\*\(\((u?int(?:8|16|32)_t)\s*\*\)",
                     r"*((volatile \1*)", src)
    return (f"uint32_t {name}_v{mode}(uint32_t r0,uint32_t r1,"
            "uint32_t r2,uint32_t r3) {\nuint32_t r12=0;\n"
            + src + "\nreturn r0;\n}\n")


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clang", default="clang")
    ap.add_argument("--out", type=Path, default=Path("build/eur1/round17_bits.json"))
    args=ap.parse_args()
    manifest=json.loads((HERE/"manifest_fifth500.json").read_text(encoding="utf-8"))
    pending={symbol_for(m):m for m in manifest["functions"]
             if m["clang_standalone_status"]!="exact_original_machine_bytes"}
    sources={}
    outputs=[]
    targets=set()
    for shard in range(1,6):
        text=(HERE/f"arm9_leaf_500_part{shard}.c").read_text(encoding="utf-8")
        for m in SYM.finditer(text):
            name=m[1]
            if name not in pending or "unsigned Z=0,N=0,C=0,V=0;" not in m[0]:
                continue
            src=m[0].split("unsigned Z=0,N=0,C=0,V=0;",1)[1]
            for v in range(8):
                output=gen(src,name,v)
                if output is not None:
                    sources[f"{name}_v{v}"]=(pending[name],output,v)
                    outputs.append(output)
                    targets.add(name)
    if len(targets)<20:
        raise ValueError(f"Expected at least 20 TST functions; got {len(targets)}")
    with tempfile.TemporaryDirectory(prefix="st_round17_bits_") as tmp:
        p=Path(tmp)/"bits.c"
        obj=Path(tmp)/"bits.o"
        p.write_text("#include <stdint.h>\n"+"\n".join(outputs),encoding="utf-8")
        proc=subprocess.run([args.clang,*FLAGS,"-c",str(p),"-o",str(obj)],
                            capture_output=True,text=True,timeout=180)
        if proc.returncode:
            raise RuntimeError("Failed to compile candidate: "+proc.stderr[-4000:])
        compiled=elf32_sections(obj.read_bytes())
    if len(compiled)!=len(sources):
        raise ValueError(f"Missing ARM function sections {len(compiled)} / {len(sources)}")
    exact={}
    for n,(ref,src,v) in sources.items():
        blob=compiled[".text."+n]
        if len(blob)!=ref["size_bytes"] or hashlib.sha256(blob).hexdigest()!=ref["original_span_sha256"]:
            continue
        orig=n.rsplit("_v",1)[0]
        if orig not in exact or v<exact[orig]["variant"]:
            exact[orig]={
                "symbol":orig,"module":ref["module"],"address":ref["address"],
                "original_size":ref["size_bytes"],"variant":v,
                "source":src.replace(f"{orig}_v{v}",orig),
                "sha256":ref["original_span_sha256"],
            }
    accepted=sorted(exact.values(),key=lambda row:row["symbol"])
    result={"backend":"Clang ARMv5TE standalone -O2", "eligible_functions":len(targets),
            "compiled_variants":len(sources),"new_exact_matches":len(accepted),
            "matches":accepted,"not_tested":"CodeWarrior, game C++ DS object/objdiff"}
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(result,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {len(sources)} ARM variants of {len(targets)} test-bit functions")
    print(f"EXACT_NEW: {len(accepted)}")
    for row in accepted:
        print(f"EXACT: {row['symbol']} {row['original_size']} bytes variant={row['variant']}")
    print("Report:",args.out)


if __name__=="__main__":
    main()
