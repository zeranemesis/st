#!/usr/bin/env python3
"""Rank nonmatching EUR1 fifth-batch ARM functions using compiled evidence.

Default: compile the 500 actual research C source bodies, validate their
standalone Clang SHA256 statuses against owner-ROM-derived manifest hashes,
and rank 448 remaining mismatches without a ROM or CodeWarrior.

Optionally supply YOUR OWN decompressed EUR1 working_code/ directory
(arm9.bin, overlay_000.bin, ...), authenticated by the manifest SHA1 hashes.
Then compare each original 32-bit ARM instruction word against Clang output
to identify close misses. Never uploads/publishes original game bytes.
"""
from __future__ import annotations

import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import subprocess
import tempfile

from verify_fifth500 import FLAGS, elf32_sections

HERE = Path(__file__).resolve().parent
MANIFEST = HERE / "manifest_fifth500.json"


def key_for(row: dict) -> str:
    module = row["module"]
    prefix = "arm9" if module == "arm9" else f"ov{int(module):03d}"
    return f".text.st_{prefix}_{int(row['address'], 16):08X}"


def compile_research(clang: str) -> tuple[dict[str, bytes], dict[str, str]]:
    all_code = {}
    origins = {}
    with tempfile.TemporaryDirectory(prefix="st_eur1_mismatch_rank_") as tmp:
        for part in range(1, 6):
            path = HERE / f"arm9_leaf_500_part{part}.c"
            output = Path(tmp) / f"part{part}.o"
            proc = subprocess.run(
                [clang, *FLAGS, "-c", str(path), "-o", str(output)],
                text=True, capture_output=True, timeout=120,
            )
            if proc.returncode:
                raise RuntimeError("Clang ARM compilation error: " + proc.stderr[-3500:])
            sections = elf32_sections(output.read_bytes())
            overlap = sections.keys() & all_code.keys()
            if overlap:
                raise ValueError(f"Duplicate ARM symbols in research shards: {sorted(overlap)}")
            all_code.update(sections)
            origins.update({name: path.name for name in sections})
    return all_code, origins


def original_spans(data: dict, directory: Path) -> dict[str, bytes]:
    source_binary = {}
    for module, expected_sha1 in data["overlay_sha1"].items():
        name = "arm9.bin" if module == "arm9" else f"overlay_{int(module):03d}.bin"
        path = directory / name
        if not path.is_file():
            raise FileNotFoundError(f"Missing decompressed original module: {path}")
        blob = path.read_bytes()
        if hashlib.sha1(blob).hexdigest() != expected_sha1:
            raise ValueError(f"Original SHA1 disagrees with EUR1 manifest for {name}")
        source_binary[module] = blob
    out = {}
    for f in data["functions"]:
        base = int(data["overlay_ram_base"][str(f["module"])], 16)
        address = int(f["address"], 16)
        offset, length = address-base, f["size_bytes"]
        module = source_binary[str(f["module"])]
        original = module[offset:offset+length] if offset >= 0 else b""
        if len(original) != length or hashlib.sha256(original).hexdigest() != f["original_span_sha256"]:
            raise ValueError(f"Original function span disagrees with manifest: {f['address']}")
        out[key_for(f)] = original
    return out


def compare_words(actual: bytes, original: bytes) -> dict:
    matched = 0
    differing = []
    total = max(len(actual), len(original)) // 4
    for byte_offset in range(0, 4*total, 4):
        expected = original[byte_offset:byte_offset+4]
        generated = actual[byte_offset:byte_offset+4]
        if expected == generated:
            matched += 1
        elif len(differing) < 10:
            differing.append({
                "instruction_offset": byte_offset,
                "original_arm_word": expected.hex() if expected else None,
                "clang_arm_word": generated.hex() if generated else None,
            })
    return {
        "matching_instruction_words": matched,
        "total_instruction_words_max": total,
        "first_differences": differing,
    }


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clang", default="clang")
    ap.add_argument("--working-code", type=Path, help="Your own verified decompressed EUR1 modules")
    ap.add_argument("--out", type=Path,
                    default=Path("build/eur1/fifth500_mismatch_priorities.json"))
    ap.add_argument("--limit", type=int, default=30)
    args = ap.parse_args()
    if args.limit < 1 or args.limit > 448:
        ap.error("limit must be between 1 and 448")

    data = json.loads(MANIFEST.read_text(encoding="utf-8"))
    functions = data["functions"]
    if len(functions) != 500:
        raise ValueError("Expected 500 EUR1 function boundaries")
    compiled, origins = compile_research(args.clang)
    expected = {key_for(f) for f in functions}
    if compiled.keys() != expected:
        raise ValueError("Unexpected or missing Clang ARM sections: " +
                         str(sorted(compiled.keys() ^ expected)))
    originals = original_spans(data, args.working_code) if args.working_code else {}
    rows = []
    tally = Counter()
    for f in functions:
        key = key_for(f)
        code = compiled[key]
        equal_size = len(code) == f["size_bytes"]
        matches = equal_size and hashlib.sha256(code).hexdigest() == f["original_span_sha256"]
        expected_status = f["clang_standalone_status"] == "exact_original_machine_bytes"
        if matches != expected_status:
            raise ValueError(f"Incorrect Clang matching status recorded for {key}")
        if matches:
            tally["exact"] += 1
            continue
        tally["not_exact"] += 1
        tally["same_size" if equal_size else "different_size"] += 1
        result = {
            "symbol": key.removeprefix(".text."),
            "module": f["module"],
            "address": f["address"],
            "original_size_bytes": f["size_bytes"],
            "clang_size_bytes": len(code),
            "size_delta_bytes": len(code)-f["size_bytes"],
            "same_size": equal_size,
            "direct_bl_references": f["direct_BL_references"],
            "source": origins[key],
            "original_verified_sha256": f["original_span_sha256"],
            "clang_sha256": hashlib.sha256(code).hexdigest(),
            "clang_byte_exact": False,
        }
        if originals:
            result.update(compare_words(code, originals[key]))
        rows.append(result)

    if tally["exact"] != data["summary"]["standalone_clang_exact"] or (
        tally["not_exact"] != data["summary"]["standalone_clang_nonmatching"]
    ):
        raise ValueError("The full compiled baseline disagrees with the original manifest")

    # Better first: already same-size and high BL-reference demand. When
    # authenticated original bytes are available, prioritize near-exact
    # instruction-word matches, which is stronger evidence than length alone.
    def priority(x: dict) -> tuple:
        return (
            -int(x.get("matching_instruction_words", -1)),
            -int(x["same_size"]),
            -x["direct_bl_references"],
            abs(x["size_delta_bytes"]),
            x["original_size_bytes"],
            x["symbol"],
        )

    rows.sort(key=priority)
    report = {
        "game": "The Legend of Zelda: Spirit Tracks", "revision": "EUR Rev1",
        "compiler": "Clang ARMv5TE -O2 standalone, no CodeWarrior",
        "original_binary_authenticated": bool(originals),
        "original_binary_bytes_written": False if not originals else "Only selected instruction word differences in local report",
        "compiled_functions": 500,
        "exact": tally["exact"],
        "not_exact": tally["not_exact"],
        "same_size_but_different_code": tally["same_size"],
        "different_size": tally["different_size"],
        "ranking_heuristic": "Word-level agreement (if original supplied), then same size, then BL refs",
        "top_candidates": rows[:args.limit],
        "all_nonmatching": rows,
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print("PASS: 500/500 true C source bodies compile and match manifest status")
    print(f"EXACT: {tally['exact']}/500; NONMATCHING: {tally['not_exact']}")
    print(f"Same size/different instructions: {tally['same_size']}; different size: {tally['different_size']}")
    print("Authenticated original working_code:", bool(originals))
    for candidate in rows[:min(15, args.limit)]:
        score = candidate.get("matching_instruction_words")
        print(f"CANDIDATE {candidate['symbol']}: original {candidate['original_size_bytes']}B"
              f", Clang {candidate['clang_size_bytes']}B,"
              f" BL refs={candidate['direct_bl_references']}"
              + (f", identical ARM words={score}" if score is not None else ""))
    print("Report:", args.out)


if __name__ == "__main__":
    main()
