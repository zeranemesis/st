#!/usr/bin/env python3
"""ROM-free typed C search for short EUR1 functions (12-16 ARM bytes).

Specialize the original straight-line ARM register translations into direct
global loads, global stores and constant-stride address calculations. Generate
multiple semantically motivated C formulations with identical -O2 ARM flags.
All candidate machine-code sections are SHA256-compared to owner-ROM-derived
reference spans; no matching status is changed by this search.
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
DECL = "unsigned Z=0,N=0,C=0,V=0;"
# The safe extractor handles only exactly recognized full-body templates.
STORE = re.compile(
    r"r([01]) = (0x[0-9a-f]+u); r2 = \((0x[01]u)\); "
    r"\*\(\(uint32_t\*\)\(uintptr_t\)\(r\1 \+ \((\d+u)\)\)\) = \(uint32_t\)r2; return r0; }"
)
LOAD = re.compile(
    r"r0 = (0x[0-9a-f]+u); r0 = \*\(\((uint32_t|uint8_t)\*\)"
    r"\(uintptr_t\)\(r0 \+ \((\d+u)\)\)\); return r0; }"
)
LOAD_R1 = re.compile(
    r"r1 = (0x[0-9a-f]+u); r0 = \*\(\((uint32_t|uint8_t)\*\)"
    r"\(uintptr_t\)\(r1 \+ \((?:r0|(?:\(r0 << \d+\)))\)\)\); return r0; }"
)
RETADDR = re.compile(
    r"r1 = (0x[0-9a-f]+u); r0 = \(r1 \+ \(\(r0 << (\d+)\)\)\); return r0; }"
)
STRIDE = re.compile(
    r"r2 = (0x[0-9a-f]+u); r1 = \((0x[0-9a-f]+u)\); "
    r"r0 = \(r1 \* r0 \+ r2\); return r0; }"
)
SIGNED_CONDITIONAL = re.compile(
    r"\{\s*uint64_t z = \(uint64_t\)r0 - \(uint64_t\)\((r1|0x0u)\);"
    r"[^{}]+\}\s*.*return r0; }"
)
FIXED_POINTER_PREFIX = r"uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3"


def name_of(r: dict) -> str:
    mod = "arm9" if r["module"] == "arm9" else f"ov{int(r['module']):03d}"
    return f"st_{mod}_{int(r['address'], 16):08X}"


def formulation(base: str, n: int) -> tuple[str, str]:
    # Forms deliberately vary types, volatile qualifiers and literal offsets,
    # while retaining original arithmetic and memory effects.
    fields = base.split("|")
    kind = fields[0]
    if kind == "store":
        addr, val = int(fields[1], 0), int(fields[2], 0)
        decl = (
            f"*(volatile uint32_t *)(uintptr_t)0x{addr:08x}u = {val}u;",
            f"*(uint32_t *)(uintptr_t)0x{addr:08x}u = {val}u;",
            f"volatile uint32_t *global = (volatile uint32_t *)(uintptr_t)0x{addr:08x}u; *global = {val}u;",
            f"uint32_t *global = (uint32_t *)(uintptr_t)0x{addr:08x}u; *global = {val}u;",
            f"*((volatile uint8_t *)(uintptr_t)0x{addr:08x}u + 0) = {val}u;",
        )
        if n >= len(decl) * 2:
            return "", ""
        statement = decl[n % len(decl)]
        ret = "return r0;" if n < len(decl) else ""
        return statement, ret
    if kind == "load":
        addr, ty = int(fields[1], 0), fields[2]
        cast = {"uint32_t": "uint32_t", "uint8_t": "uint8_t"}[ty]
        expr = [
            f"*(volatile {cast} *)(uintptr_t)0x{addr:08x}u",
            f"*({cast} *)(uintptr_t)0x{addr:08x}u",
            f"*(const volatile {cast} *)(uintptr_t)0x{addr:08x}u",
            f"*(const {cast} *)(uintptr_t)0x{addr:08x}u",
        ]
        if n >= 8:
            return "", ""
        return "", f"return (uint32_t)({expr[n % 4]});"
    if kind == "address":
        baseaddr, shift = int(fields[1], 0), int(fields[2], 0)
        expr = [
            f"0x{baseaddr:08x}u + (r0 << {shift})",
            f"0x{baseaddr:08x}u + (r0 * {1 << shift}u)",
            f"(uintptr_t)((uint8_t *)(uintptr_t)0x{baseaddr:08x}u + r0 * {1 << shift}u)",
            f"(uintptr_t)((uint32_t *)(uintptr_t)0x{baseaddr:08x}u + r0 * {(1 << shift) // 4}u)" if shift >= 2 else "0",
        ]
        if n >= 8:
            return "", ""
        return "", f"return (uint32_t)({expr[n % 4]});"
    if kind == "stride":
        addr, stride = int(fields[1], 0), int(fields[2], 0)
        expr = [
            f"0x{addr:08x}u + r0 * {stride}u",
            f"r0 * {stride}u + 0x{addr:08x}u",
            f"(uintptr_t)((char *)(uintptr_t)0x{addr:08x}u + r0 * {stride}u)",
            f"0x{addr:08x}u + (r0 << 2) * {stride // 4}u" if stride % 4 == 0 else f"r0 * {stride}u + 0x{addr:08x}u",
        ]
        if n >= 8:
            return "", ""
        return "", f"return (uint32_t)({expr[n % 4]});"
    if kind == "select":
        if n >= 8:
            return "", ""
        expr = [
            "r0 != 0u ? 1u : 3u",
            "r0 == 0u ? 3u : 1u",
            "r0 ? 1u : 3u",
            "3u - ((r0 != 0u) << 1)",
        ]
        return "", f"return {expr[n % 4]};"
    if kind == "absdiff":
        if n >= 12:
            return "", ""
        expr = [
            "r0 >= r1 ? r0 - r1 : r1 - r0",
            "(int32_t)r0 >= (int32_t)r1 ? r0 - r1 : r1 - r0",
            "r0 < r1 ? r1 - r0 : r0 - r1",
            "((int32_t)r0 < (int32_t)r1) ? r1 - r0 : r0 - r1",
            "r0 - r1",
            "r1 - r0",
        ]
        return "", f"return {expr[n % 6]};"
    return "", ""


def detect(src: str) -> str | None:
    body = src.split(DECL, 1)[1].strip()
    st = STORE.fullmatch(body)
    if st:
        return f"store|{hex(int(st[2][:-1], 16) + int(st[4][:-1]))}|{int(st[3][:-1], 16)}"
    ld = LOAD.fullmatch(body)
    if ld:
        return f"load|{hex(int(ld[1][:-1], 16) + int(ld[3][:-1]))}|{ld[2]}"
    adr = RETADDR.fullmatch(body)
    if adr:
        return f"address|{hex(int(adr[1][:-1], 16))}|{adr[2]}"
    mul = STRIDE.fullmatch(body)
    if mul:
        return f"stride|{hex(int(mul[1][:-1], 16))}|{hex(int(mul[2][:-1], 16))}"
    if "if (Z) { r0 = (0x3u); } if (!Z) { r0 = (0x1u); } return r0; }" in body and "r0 - (0x0u)" in body:
        return "select"
    if SIGNED_CONDITIONAL.search(body) and "r0 = (r0 - (r1));" in body and "r0 = (r1 - (r0));" in body:
        return "absdiff"
    return None


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clang", default="clang")
    ap.add_argument("--out", type=Path, default=Path("build/eur1/round18_short.json"))
    args = ap.parse_args()
    data = json.loads((HERE / "manifest_fifth500.json").read_text(encoding="utf-8"))
    targets = {name_of(r):r for r in data["functions"]
               if r["size_bytes"] <= 16 and r["clang_standalone_status"] != "exact_original_machine_bytes"}
    candidates = {}
    variant_parts = []
    for part in range(1,6):
        content = (HERE/f"arm9_leaf_500_part{part}.c").read_text(encoding="utf-8")
        for m in FUN.finditer(content):
            name = m[1]
            if name not in targets or DECL not in m[0]:
                continue
            desc = detect(m[0])
            if desc is None:
                continue
            for v in range(16):
                statement, ret = formulation(desc, v)
                if not statement and not ret:
                    continue
                if desc.startswith("store"):
                    rtype = "uint32_t" if ret else "void"
                else:
                    rtype = "uint32_t"
                code = (
                    f"{rtype} {name}_v{v}({FIXED_POINTER_PREFIX}) {{ "
                    f"{statement} {ret} }}\n"
                )
                candidates[f"{name}_v{v}"] = (targets[name],code,desc,v)
                variant_parts.append(code)
    if len(candidates) < 100:
        raise ValueError(f"Not enough eligible candidates: {len(candidates)}")
    with tempfile.TemporaryDirectory(prefix="st_round18_") as tmp:
        s = Path(tmp)/"functions.c"
        obj = Path(tmp)/"functions.o"
        s.write_text("#include <stdint.h>\n"+"\n".join(variant_parts),encoding="utf-8")
        proc = subprocess.run([args.clang,*FLAGS,"-c",str(s),"-o",str(obj)],
                              text=True,capture_output=True,timeout=120)
        if proc.returncode:
            raise RuntimeError("ARM candidate compiler failed: "+proc.stderr[-3500:])
        compiled = elf32_sections(obj.read_bytes())
    if len(compiled) != len(candidates):
        raise ValueError(f"Missing sections {len(compiled)} / {len(candidates)}")
    exact={}
    for candidate,(record,source,category,idx) in candidates.items():
        machine=compiled[".text."+candidate]
        if (len(machine)!=record["size_bytes"] or
            hashlib.sha256(machine).hexdigest()!=record["original_span_sha256"]):
            continue
        name=candidate.rsplit("_v",1)[0]
        if name not in exact or idx<exact[name]["variant"]:
            exact[name]={
                "name":name,"module":record["module"],"address":record["address"],
                "size":record["size_bytes"],"category":category,"variant":idx,
                "source":source.replace(candidate,name),
                "sha256":record["original_span_sha256"]
            }
    found=sorted(exact.values(),key=lambda d:d["name"])
    report={
        "scope":"Previously nonmatching short 12/16-byte original ARM functions",
        "distinct_targets":len({x[0]["address"]+str(x[0]["module"]) for x in candidates.values()}),
        "compiled_variants":len(candidates),
        "new_exact_matches":len(found),
        "matches":found,
        "compiler":"Clang ARMv5TE -O2 standalone, no CodeWarrior"
    }
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(report,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {len(candidates)} ARM source variants across {report['distinct_targets']} short functions")
    print(f"EXACT_NEW: {len(found)}")
    for m in found:
        print(f"EXACT: {m['name']} ({m['category']}) {m['size']} bytes variant={m['variant']}")
    print("Report:",args.out)


if __name__ == "__main__":
    main()
