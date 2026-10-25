#!/usr/bin/env python3
"""Find new standalone Clang ARMv5TE matches among simple fifth-batch functions.

Rewrites existing simple straight-line ARM register translations into typed C,
under several choices of pointer qualifiers and return signatures. This is a
SEARCH: printed matches must be explicitly verified and promoted; it never
changes the original 500-function manifest automatically. No ROM required.

Supported original bodies: a preserved input r0 base pointer, no branch or
condition flags, return r0, simple stores/loads through typed pointers.
No instruction bytes from original ROM are included.
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
MANIFEST = HERE / "manifest_fifth500.json"
LINE_RE = re.compile(r"^uint32_t\s+(st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$", re.M)
STORES = re.compile(r"\*\(\((?:u?int(?:8|16|32)_t)\s*\*\)")
REGS = re.compile(r"\br(?:[1-9]|1[0-2])\b")
RETURN = re.compile(r"\s*return r0;\s*}\s*$")
EXCLUDED = ("if (", "uint64_t z", "uint32_t z", "asm", "goto", "while (",
            "for (", "switch (", " Z ", " N ", " C ", " V ")
# 8 explicit source variants. This is original source semantics tuning, not
# matching compiler switches; all variants use the same ARMv5TE flags.
VARIANTS = (
    ("volatile", True, False),
    ("volatile", False, False),
    ("nonvolatile", True, False),
    ("nonvolatile", False, False),
    ("volatile", True, True),
    ("volatile", False, True),
    ("nonvolatile", True, True),
    ("nonvolatile", False, True),
)


def symbol_name(record: dict) -> str:
    mod = record["module"]
    kind = "arm9" if mod == "arm9" else f"ov{int(mod):03d}"
    return f"st_{kind}_{int(record['address'], 16):08X}"


def extract_body(line: str) -> str | None:
    marker = "unsigned Z=0,N=0,C=0,V=0;"
    if marker not in line:
        return None
    body = line.split(marker, 1)[1]
    if not RETURN.search(body) or any(p in body for p in EXCLUDED):
        return None
    if re.search(r"\br0\s*=", body):
        return None
    if not STORES.search(body):
        return None
    body = RETURN.sub("", body)
    # Skip r0 used in any expression that is not a pointer or a return
    # (the targeted register translations use the r0 base as an address).
    if re.search(r"\br0\b(?!\s*\+)", body):
        return None
    if "{" in body or "}" in body:
        return None
    if re.search(r"\br(?:4|5|6|7|8|9|10|11)\b", body):
        return None
    return body.strip()


def emit(body: str, name: str, v: int) -> str:
    mode, volatile_access, returns = VARIANTS[v]
    rtype = "uint32_t" if returns else "void"
    base = "volatile uint8_t *object" if mode == "volatile" else "uint8_t *object"
    body = re.sub(r"\br0\b", "object", body)
    if volatile_access:
        body = re.sub(r"\*\(\((u?int(?:8|16|32)_t)\s*\*\)",
                      r"*((volatile \1*)", body)
    # Use a direct pointer argument. Preserve all observed C statements;
    # only synthetic ARM register-state declarations were removed.
    tail = "\nreturn (uint32_t)(uintptr_t)object;" if returns else ""
    return (
        f"{rtype} {name}_v{v}({base}, uint32_t r1, uint32_t r2, "
        f"uint32_t r3) {{\nuint32_t r12 = 0;\n"
        + body + ";" + tail + "\n}\n"
    )


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clang", default="clang")
    ap.add_argument("--out", type=Path,
                    default=Path("build/eur1/simple_candidates_round15.json"))
    args = ap.parse_args()
    data = json.loads(MANIFEST.read_text(encoding="utf-8"))
    candidates = {symbol_name(r): r for r in data["functions"]
                  if r["clang_standalone_status"] != "exact_original_machine_bytes"}
    lines = []
    for shard in range(1, 6):
        src = (HERE / f"arm9_leaf_500_part{shard}.c").read_text(encoding="utf-8")
        lines.extend(LINE_RE.findall(src))
    # findall returns symbols only, so use finditer for full lines below.
    variants: dict[str, tuple[dict, int, str]] = {}
    originals = 0
    text_lines = []
    for shard in range(1, 6):
        src = (HERE / f"arm9_leaf_500_part{shard}.c").read_text(encoding="utf-8")
        for match in LINE_RE.finditer(src):
            line = match[0]
            name = match[1]
            reference = candidates.get(name)
            if reference is None:
                continue
            body = extract_body(line)
            if body is None:
                continue
            originals += 1
            for v in range(len(VARIANTS)):
                key = f"{name}_v{v}"
                variants[key] = (reference, v, body)
                text_lines.append(emit(body, name, v))

    if originals < 50:
        raise ValueError(f"Unexpectedly few eligible original functions: {originals}")
    source_code = "#include <stdint.h>\n" + "\n".join(text_lines)
    with tempfile.TemporaryDirectory(prefix="st_round15_simple_") as tmp:
        source = Path(tmp) / "variants.c"
        obj = Path(tmp) / "variants.o"
        source.write_text(source_code, encoding="utf-8")
        proc = subprocess.run(
            [args.clang, *FLAGS, "-c", str(source), "-o", str(obj)],
            capture_output=True, text=True, timeout=150,
        )
        if proc.returncode:
            raise RuntimeError("Clang failed to compile candidate search: " +
                               proc.stderr[-3500:])
        compiled = elf32_sections(obj.read_bytes())

    if len(compiled) != len(variants):
        raise ValueError(
            f"Emitted {len(compiled)} / {len(variants)} expected function sections"
        )
    matches: dict[str, dict] = {}
    for name, (reference, variant, body) in variants.items():
        original_size = reference["size_bytes"]
        code = compiled[".text." + name]
        if len(code) != original_size:
            continue
        if hashlib.sha256(code).hexdigest() != reference["original_span_sha256"]:
            continue
        base_name = name.rsplit("_v", 1)[0]
        prior = matches.get(base_name)
        if prior is None or variant < prior["variant"]:
            matches[base_name] = {
                "name": base_name,
                "module": reference["module"],
                "address": reference["address"],
                "size": original_size,
                "variant": variant,
                "generated_source": emit(body, base_name, variant),
                "sha256": reference["original_span_sha256"],
            }
    ordered = sorted(matches.values(), key=lambda x: (str(x["module"]), x["address"]))
    output = {
        "status": "experimental Clang standalone matching search",
        "source_candidate_functions": originals,
        "compiled_variants": len(variants),
        "unique_new_matches_not_yet_promoted": len(ordered),
        "matching_sources": ordered,
        "limitations": "Not CodeWarrior, DS integration, or verified runtime semantics",
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(output, indent=2) + "\n", encoding="utf-8")
    print(f"PASS: {len(variants)} Clang ARM variants of {originals} existing candidates")
    print(f"EXACT_NEW: {len(ordered)} distinct previous nonmatching addresses")
    for row in ordered:
        print(f"EXACT: {row['name']} variant={row['variant']} bytes={row['size']}")
    print("Report:", args.out)


if __name__ == "__main__":
    main()
