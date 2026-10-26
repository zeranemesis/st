#!/usr/bin/env python3
"""ROM-free, strict full-500 Clang ARMv5TE SHA256 audit of fifth research batch.

Compiles the *actual five published C shards*, hashes complete per-function ARM
machine-code sections and validates all 500 records against the existing
owner-ROM-backed SHA256 reference manifest. No ROM or CodeWarrior is needed.
A Clang match is NOT a Nintendo CodeWarrior or game C++ objdiff match.
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


def symbol_for(row: dict) -> str:
    module = row["module"]
    prefix = "arm9" if module == "arm9" else f"ov{int(module):03d}"
    return f".text.st_{prefix}_{int(row['address'], 16):08X}"


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clang", default="clang")
    ap.add_argument("--out", type=Path,
                    default=Path("build/eur1/fifth500_full_clang_sha256.json"))
    args = ap.parse_args()

    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    targets = manifest["functions"]
    if len(targets) != 500 or len({symbol_for(r) for r in targets}) != 500:
        raise ValueError("Expected 500 unique original C functions")
    all_sections: dict[str, bytes] = {}
    with tempfile.TemporaryDirectory(prefix="st_fifth500_recheck_") as tmp:
        for number in range(1, 6):
            source = HERE / f"arm9_leaf_500_part{number}.c"
            obj = Path(tmp) / f"part{number}.o"
            result = subprocess.run(
                [args.clang, *FLAGS, "-c", str(source), "-o", str(obj)],
                capture_output=True, text=True,
            )
            if result.returncode:
                raise RuntimeError(
                    f"Failed to compile {source.name}: " + result.stderr[-3000:]
                )
            current = elf32_sections(obj.read_bytes())
            shared = all_sections.keys() & current.keys()
            if shared:
                raise ValueError("Duplicate compiled function: " + str(sorted(shared)))
            all_sections.update(current)
    expected = {symbol_for(r) for r in targets}
    if all_sections.keys() != expected:
        raise ValueError(
            "Missing/unexpected ARM function sections: " +
            str(sorted(all_sections.keys() ^ expected))
        )

    results = []
    for target in targets:
        symbol = symbol_for(target)
        actual = all_sections[symbol]
        expected_size = target["size_bytes"]
        exact = (
            len(actual) == expected_size
            and hashlib.sha256(actual).hexdigest() == target["original_span_sha256"]
        )
        recorded = target["clang_standalone_status"] == "exact_original_machine_bytes"
        if recorded != exact:
            raise ValueError(
                "Manifest Clang-matching mismatch: " + symbol +
                f" (measured={exact}, recorded={recorded})"
            )
        results.append({
            "symbol": symbol.removeprefix(".text."),
            "original_size": expected_size,
            "generated_size": len(actual),
            "clang_exact": exact,
        })
    counts = Counter("exact" if r["clang_exact"] else "not_exact" for r in results)
    if counts["exact"] != 80 or counts["not_exact"] != 420:
        raise ValueError("Unexpected revised fifth-batch exact count")
    report = {
        "scope": "Published fifth batch of 500 actual C functions",
        "backend": "standalone Clang ARMv5TE -O2, NOT CodeWarrior",
        "compiled_functions": 500,
        "exact_clang_sha256": counts["exact"],
        "not_exact": counts["not_exact"],
        "limitations": "Original ROM reference hashes only; no DS C++ or game rebuild",
        "functions": results,
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"PASS: 500/500 original functions compiled; {counts['exact']}/500 "
          "machine-code SHA256-exact with standalone Clang")
    print("Round 23: 23 more Clang ARM C functions promoted; 80/500 strictly exact")
    print("Report:", args.out)


if __name__ == "__main__":
    main()
