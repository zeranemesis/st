#!/usr/bin/env python3
"""Search EUR1 fifth-batch single-compare C routines for ARMv5TE byte matches.

Use existing owner-ROM SHA256 references, with NO CodeWarrior and no original
game executable bytes. This explores typed C for previously nonmatching
originals (one ARM CMP, multiple conditional assignments). No manifest writes.
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
PATTERN = re.compile(r"^uint32_t (st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$", re.M)
CMP = re.compile(r"\{\s*uint64_t z = \(uint64_t\)(r\d+) - \(uint64_t\)\((r\d+|0x[0-9a-f]+u)\);[^{}]+?\}")
RETURN = re.compile(r"\s*return r0;\s*\}\s*$")
# The variances combine signed flag simplification with typed loads/stores,
# and keep one ABI name per generated candidate.
MODES = ("integer", "volatile_pointer", "pointer")
VOLATILITY = (False, True)


def name_from_record(r: dict) -> str:
    module = r["module"]
    prefix = "arm9" if module == "arm9" else f"ov{int(module):03d}"
    return f"st_{prefix}_{int(r['address'], 16):08X}"


def variant(body: str, symbol: str, index: int) -> str | None:
    matches = list(CMP.finditer(body))
    if len(matches) != 1 or body.count("uint64_t z") != 1:
        return None
    m = matches[0]
    lhs, rhs = m.group(1), m.group(2)
    # Original ARM signed comparison flag combination N==V translates
    # to a direct signed >= comparison. Capture CMP registers before
    # subsequent assignments; never re-evaluate changed operands.
    replacement = (
        "uint32_t cmp_lhs = " + lhs + ", cmp_rhs = " + rhs + "; "
        "unsigned Z = (cmp_lhs == cmp_rhs); "
        "unsigned C = (cmp_lhs >= cmp_rhs); "
        "unsigned GE = ((int32_t)cmp_lhs >= (int32_t)cmp_rhs);"
    )
    src = body[:m.start()] + replacement + body[m.end():]
    src = re.sub(r"N\s*==\s*V", "GE", src)
    src = re.sub(r"N\s*!=\s*V", "!GE", src)
    if re.search(r"\b(?:N|V)\b", src):
        return None
    if not RETURN.search(src):
        return None
    src = RETURN.sub("", src)

    mode = MODES[index // 2]
    use_volatile = VOLATILITY[index % 2]
    if mode != "integer":
        if re.search(r"\br0\s*=", src):
            return None
        if re.search(r"\br0\b(?!\s*\+)", src):
            return None
        if re.search(r"\br(?:[1-9]|1[0-2])\s*=\s*\(\s*r0\s*\+", src):
            return None
        src = re.sub(r"\br0\b", "object", src)
        arg = "volatile uint8_t *object" if mode == "volatile_pointer" else "uint8_t *object"
        ret = "return (uint32_t)(uintptr_t)object;"
    else:
        arg = "uint32_t r0"
        ret = "return r0;"

    if use_volatile:
        src = re.sub(
            r"\*\(\((u?int(?:8|16|32)_t)\s*\*\)",
            r"*((volatile \1*)", src,
        )
    return (
        f"uint32_t {symbol}_v{index}({arg}, uint32_t r1, "
        "uint32_t r2, uint32_t r3) {\n"
        "uint32_t r12 = 0;\n" + src + "\n" + ret + "\n}\n"
    )


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--clang", default="clang")
    parser.add_argument("--out", type=Path, default=Path("build/eur1/round16_conditional.json"))
    args = parser.parse_args()
    manifest = json.loads((HERE / "manifest_fifth500.json").read_text())
    pending = {name_from_record(r): r for r in manifest["functions"]
               if r["clang_standalone_status"] != "exact_original_machine_bytes"}
    variants = {}
    bodies = []
    candidates = set()
    for part in range(1, 6):
        text = (HERE / f"arm9_leaf_500_part{part}.c").read_text(encoding="utf-8")
        for match in PATTERN.finditer(text):
            symbol = match[1]
            record = pending.get(symbol)
            if record is None:
                continue
            line = match[0]
            separator = "unsigned Z=0,N=0,C=0,V=0;"
            if separator not in line:
                continue
            body = line.split(separator, 1)[1]
            for index in range(6):
                code = variant(body, symbol, index)
                if code is not None:
                    variants[f"{symbol}_v{index}"] = (record, code, index)
                    bodies.append(code)
                    candidates.add(symbol)
    if len(candidates) < 50:
        raise ValueError(f"Only {len(candidates)} conditional candidates")
    with tempfile.TemporaryDirectory(prefix="st_round16_") as tmp:
        src = Path(tmp) / "source.c"
        obj = Path(tmp) / "source.o"
        src.write_text("#include <stdint.h>\n" + "\n".join(bodies), encoding="utf-8")
        run = subprocess.run([args.clang, *FLAGS, "-c", str(src), "-o", str(obj)],
                             capture_output=True, text=True, timeout=180)
        if run.returncode:
            raise RuntimeError("ARM compilation failed: " + run.stderr[-5000:])
        compiled = elf32_sections(obj.read_bytes())
    if len(compiled) != len(variants):
        raise ValueError(f"Missing sections: {len(compiled)} / {len(variants)}")
    exacts = {}
    for name, (record, source, index) in variants.items():
        code = compiled[".text." + name]
        if len(code) != record["size_bytes"]:
            continue
        if hashlib.sha256(code).hexdigest() != record["original_span_sha256"]:
            continue
        base = name.rsplit("_v", 1)[0]
        if base not in exacts or index < exacts[base]["variant"]:
            exacts[base] = {
                "symbol": base, "module": record["module"],
                "address": record["address"], "size": record["size_bytes"],
                "variant": index,
                "generated_source": source.replace(f"{base}_v{index}", base),
                "sha256": record["original_span_sha256"],
            }
    ordered = sorted(exacts.values(), key=lambda r: r["symbol"])
    report = {
        "kind": "Clang ARMv5TE -O2 single-CMP source search (not CodeWarrior)",
        "eligible_original_functions": len(candidates),
        "compiled_variants": len(variants),
        "new_full_sha256_matches": len(ordered),
        "matches": ordered,
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"PASS: {len(variants)} ARM variants for {len(candidates)} functions")
    print(f"EXACT_NEW: {len(ordered)}")
    for row in ordered:
        print("EXACT:", row["symbol"], row["size"], "bytes, variant", row["variant"])
    print("Report:", args.out)


if __name__ == "__main__":
    main()
