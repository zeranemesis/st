#!/usr/bin/env python3
"""Audit ARM instructions excluding Clang-generated trailing literal-pool words.

The fifth500 strict SHA256 baseline compares complete Clang ELF sections to
original instruction spans. Clang ARM may append *literal pool data* to
.text.<function>, making a section longer even if its first N instruction
bytes match the original N instruction bytes.

This tool does NOT promote full-section exact matches or update the manifest.
It reports byte-for-byte matching code prefixes as a secondary, explicitly
distinct metric. Trailing bytes need independent literal-pool classification.
No original ROM is needed; only stored owner-ROM SHA256 fingerprints.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import tempfile

from verify_fifth500 import FLAGS, elf32_sections

HERE = Path(__file__).resolve().parent
SOURCE = HERE / "manifest_fifth500.json"


def symbol(rec: dict) -> str:
    mod = "arm9" if rec["module"] == "arm9" else f"ov{int(rec['module']):03d}"
    return f".text.st_{mod}_{int(rec['address'], 16):08X}"


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--clang", default="clang")
    parser.add_argument("--out", type=Path,
                        default=Path("build/eur1/literal_pools_round20.json"))
    args = parser.parse_args()

    manifest = json.loads(SOURCE.read_text(encoding="utf-8"))
    records = manifest["functions"]
    if len(records) != 500 or len({symbol(rec) for rec in records}) != 500:
        raise ValueError("Expected 500 original function symbols")

    with tempfile.TemporaryDirectory(prefix="st_literal_pool_round20_") as tmp:
        sections = {}
        for shard in range(1, 6):
            src = HERE / f"arm9_leaf_500_part{shard}.c"
            obj = Path(tmp) / f"p{shard}.o"
            proc = subprocess.run(
                [args.clang, *FLAGS, "-c", str(src), "-o", str(obj)],
                capture_output=True, text=True, timeout=120,
            )
            if proc.returncode:
                raise RuntimeError(
                    f"Compilation failed for {src.name}: " + proc.stderr[-3500:]
                )
            emitted = elf32_sections(obj.read_bytes())
            if emitted.keys() & sections.keys():
                raise ValueError("Duplicate ARM compiled function symbols")
            sections.update(emitted)

    if sections.keys() != {symbol(rec) for rec in records}:
        raise ValueError("Sections differ from original fifth500 symbols")
    exact = []
    instruction_prefix_matches = []
    trailing_length_histogram = {}
    for f in records:
        key = symbol(f)
        full = sections[key]
        needed = f["size_bytes"]
        reference = f["original_span_sha256"]
        is_exact = len(full) == needed and hashlib.sha256(full).hexdigest() == reference
        recorded = f["clang_standalone_status"] == "exact_original_machine_bytes"
        if is_exact != recorded:
            raise ValueError("Manifest mismatch: " + key)
        if is_exact:
            exact.append(key)
            continue
        if len(full) <= needed or hashlib.sha256(full[:needed]).hexdigest() != reference:
            continue
        trailing = full[needed:]
        if len(trailing) % 4 != 0:
            raise ValueError("Unexpected unaligned trailing data: " + key)
        length = len(trailing)
        trailing_length_histogram[str(length)] = trailing_length_histogram.get(str(length), 0) + 1
        instruction_prefix_matches.append({
            "name": key.removeprefix(".text."),
            "module": f["module"],
            "address": f["address"],
            "original_instruction_span_size": needed,
            "complete_clang_section_size": len(full),
            "trailing_bytes": length,
            "appended_words_hex": [trailing[i:i+4].hex() for i in range(0, len(trailing), 4)],
            "original_instruction_sha256": reference,
            "code_prefix_sha256": hashlib.sha256(full[:needed]).hexdigest(),
            "strict_match": False,
            "classification": "Exact original instruction prefix; appended bytes UNVERIFIED as literal pool",
        })
    if len(exact) != 54:
        raise ValueError(f"Current expected baseline of 54/500 lost: {len(exact)}")
    instruction_prefix_matches.sort(key=lambda x: (x["trailing_bytes"], x["name"]))
    out = {
        "scope": "500 real fifth-batch ARM C functions, no ROM, no CodeWarrior",
        "strict_full_section_matches": len(exact),
        "full_section_nonmatching": 500 - len(exact),
        "additional_instruction_prefix_matches": len(instruction_prefix_matches),
        "appended_data_length_histogram": trailing_length_histogram,
        "caution": "A matching code prefix proves original instructions identical, not full function section / literal pool identity. Inspect appended bytes before classifying.",
        "candidates": instruction_prefix_matches,
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(out, indent=2) + "\n", encoding="utf-8")
    print(f"PASS: 500 ARM source functions recompiled; {len(exact)} full-section SHA256 exact")
    print(f"ADDITIONAL_PREFIX_EXACT: {len(instruction_prefix_matches)} functions")
    for row in instruction_prefix_matches:
        print(f"PREFIX_EXACT: {row['name']} {row['original_instruction_span_size']}"
              f" ARM bytes, +{row['trailing_bytes']} extra bytes in Clang ELF")
    print("Report:", args.out)


if __name__ == "__main__":
    main()
