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
import struct

from verify_fifth500 import FLAGS, elf32_sections

HERE = Path(__file__).resolve().parent
SOURCE = HERE / "manifest_fifth500.json"


def symbol(rec: dict) -> str:
    mod = "arm9" if rec["module"] == "arm9" else f"ov{int(rec['module']):03d}"
    return f".text.st_{mod}_{int(rec['address'], 16):08X}"


def arm_pc_literal_references(code: bytes, appended_start: int) -> list[dict]:
    """Find concrete ARM-mode LDR pc-relative words targeting trailing data.

    Instruction format must be immediate pre-indexed 32-bit LDR from Rn=PC
    with writeback disabled. ARM PC is current instruction offset + 8.
    This only validates Clang's local section layout, NOT the original
    game's linker layout or the exact literal pool value.
    """
    refs = []
    for instruction_offset in range(0, appended_start, 4):
        word = struct.unpack_from("<I", code, instruction_offset)[0]
        # ARM single-word transfer: bits27:26=01; I=0; P=1;
        # byte=0, W=0, load=1, base Rn=PC (r15).
        if ((word >> 26) & 3) != 1 or (word & (1 << 25)):
            continue
        if not (word & (1 << 24)) or (word & (1 << 22)) or (word & (1 << 21)):
            continue
        if not (word & (1 << 20)) or ((word >> 16) & 15) != 15:
            continue
        signed_offset = (word & 0xFFF) * (1 if (word & (1 << 23)) else -1)
        target = instruction_offset + 8 + signed_offset
        if appended_start <= target < len(code) and target % 4 == 0:
            refs.append({
                "instruction_offset": instruction_offset,
                "literal_target_offset": target,
                "literal_target_within_trailer": target-appended_start,
                "destination_register": (word >> 12) & 15,
            })
    return refs


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
            if f.get("clang_instruction_prefix_status") is not None:
                raise ValueError("Strict exact function must not be tagged as literal-prefix-only: " + key)
            exact.append(key)
            continue
        if len(full) <= needed or hashlib.sha256(full[:needed]).hexdigest() != reference:
            continue
        trailing = full[needed:]
        if len(trailing) % 4 != 0:
            raise ValueError("Unexpected unaligned trailing data: " + key)
        length = len(trailing)
        literal_references = arm_pc_literal_references(full, needed)
        is_single_word_literal = length == 4 and any(
            ref["literal_target_offset"] == needed for ref in literal_references
        )
        annotated = f.get("clang_instruction_prefix_status")
        expected_annotation = (
            "full_original_ARM_instruction_span_sha256_exact__clang_section_has_one_referenced_4byte_literal_pool"
            if is_single_word_literal else None
        )
        if annotated != expected_annotation:
            raise ValueError(f"Incorrect literal prefix classification in manifest: {key}")

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
            "one_word_literal_pool_confirmed_in_clang_elf": is_single_word_literal,
            "pc_literal_loads_targeting_trailer": literal_references,
            "classification": ("Exact original ARM instruction prefix + referenced one-word Clang literal pool"
                               if is_single_word_literal else "Exact original ARM instruction prefix; trailer not fully classified"),
        })
    if len(exact) != 82:
        raise ValueError(f"Current expected baseline of 82/500 lost: {len(exact)}")
    tagged = sum(f.get("clang_instruction_prefix_status") is not None
                 for f in records)
    if tagged != manifest["summary"]["standalone_clang_exact_instruction_prefix_with_one_verified_literal"]:
        raise ValueError(f"Annotation count disagrees with manifest summary: {tagged}")
    instruction_prefix_matches.sort(key=lambda x: (x["trailing_bytes"], x["name"]))
    confirmed_literal = sum(x["one_word_literal_pool_confirmed_in_clang_elf"]
                            for x in instruction_prefix_matches)
    if (confirmed_literal != manifest["summary"].get("standalone_clang_exact_instruction_prefix_with_one_verified_literal")
            or len(exact) + confirmed_literal != manifest["summary"].get("standalone_clang_exact_original_instruction_spans_total")):
        raise ValueError("Manifest instruction-span matching summary does not match independent code audit")

    out = {
        "scope": "500 real fifth-batch ARM C functions, no ROM, no CodeWarrior",
        "strict_full_section_matches": len(exact),
        "full_section_nonmatching": 500 - len(exact),
        "additional_instruction_prefix_matches": len(instruction_prefix_matches),
        "confirmed_single_word_literal_pool_prefix_matches": confirmed_literal,
        "unclassified_prefix_matches": len(instruction_prefix_matches) - confirmed_literal,
        "appended_data_length_histogram": trailing_length_histogram,
        "caution": "A matching code prefix proves original instructions identical, not full function section / literal pool identity. Inspect appended bytes before classifying.",
        "candidates": instruction_prefix_matches,
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(out, indent=2) + "\n", encoding="utf-8")
    print(f"PASS: 500 ARM source functions recompiled; {len(exact)} full-section SHA256 exact")
    print(f"ADDITIONAL_PREFIX_EXACT: {len(instruction_prefix_matches)} functions")
    print(f"CONFIRMED_CLANG_ONE_WORD_LITERAL: {confirmed_literal} functions")
    for row in instruction_prefix_matches:
        print(f"PREFIX_EXACT: {row['name']} {row['original_instruction_span_size']}"
              f" ARM bytes, +{row['trailing_bytes']} extra bytes in Clang ELF")
    print("Report:", args.out)


if __name__ == "__main__":
    main()
