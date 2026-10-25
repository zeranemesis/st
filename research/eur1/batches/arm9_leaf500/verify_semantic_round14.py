#!/usr/bin/env python3
"""ROM-free Clang ARMv5TE audit of 26 newly readable existing overlay-0 targets.

Only byte-for-byte Clang code equality with the original ROM-derived
manifest SHA-256 counts as a Clang match. No original CodeWarrior matching
or game C++ integration is claimed. Never silently accept missing symbols,
missing hashes, duplicate references, relocations or absent ARM backend.
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
SOURCE = HERE / "semantic_candidates_round14.c"
MANIFEST = HERE / "manifest_fifth500.json"
ADDRESSES = (
    "0205AED0", "0205D500", "02068504", "0206AEB4", "0206AF94",
    "0206D32C", "02070138", "020712B4", "020771D0", "02078EA0",
    "02079304", "0207995C", "020816A0", "020816D8", "02089FC0",
    "02089FE4", "0208E770", "02096C7C", "020A2B0C", "020A3950",
    "020A44D0", "020A4B40", "020A6B70", "020A7764", "0208AED0",
    "020A7880",
)


def main() -> None:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--clang", default="clang")
    p.add_argument("--out", type=Path,
                   default=Path("build/eur1/semantic_round14_hashes.json"))
    args = p.parse_args()

    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    refs = {(str(f["module"]), int(f["address"], 16)): f
            for f in manifest["functions"]}
    if len(manifest["functions"]) != 500 or len(refs) != 500:
        raise ValueError("Original fifth batch manifest missing or duplicate")
    with tempfile.TemporaryDirectory(prefix="st_round14_") as tmp:
        obj = Path(tmp) / "round14.o"
        cmd = [args.clang, *FLAGS, "-c", str(SOURCE), "-o", str(obj)]
        proc = subprocess.run(cmd, capture_output=True, text=True)
        if proc.returncode:
            raise RuntimeError("Clang ARM compile error: " + proc.stderr[-3000:])
        code = elf32_sections(obj.read_bytes())

    expected = {".text.st_ov000_" + addr for addr in ADDRESSES}
    if set(code) != expected or len(ADDRESSES) != 26 or len(set(ADDRESSES)) != 26:
        raise ValueError("Expected exactly 26 distinct ARM function sections: " +
                         str(sorted(set(code) ^ expected)))
    rows = []
    for address in ADDRESSES:
        reference = refs.get(("0", int(address, 16)))
        if not reference or reference["clang_standalone_status"] == "exact_original_machine_bytes":
            raise ValueError("Target must be a previously NONMATCHING overlay-0 function: " + address)
        machine_code = code[".text.st_ov000_" + address]
        identical = (len(machine_code) == reference["size_bytes"] and
                     hashlib.sha256(machine_code).hexdigest() ==
                     reference["original_span_sha256"])
        rows.append({
            "module": "overlay_000",
            "address": "0x" + address,
            "symbol": "st_ov000_" + address,
            "direct_bl_references": reference["direct_BL_references"],
            "original_size": reference["size_bytes"],
            "generated_size": len(machine_code),
            "clang_standalone_exact": identical,
            "status": ("exact_clang_standalone" if identical
                       else "different_size" if len(machine_code) != reference["size_bytes"]
                       else "different_instructions"),
        })
    exact = sum(row["clang_standalone_exact"] for row in rows)
    out = {
        "game": "Zelda Spirit Tracks", "revision": "EUR Rev1",
        "original_batch": "arm9_leaf500",
        "scope": "26 alternative readable C bodies for existing nonmatching originals",
        "compiler": "Clang ARMv5TE -O2 standalone",
        "candidates": len(rows), "additional_exact_in_this_candidate_set": exact,
        "unchanged_fifth_batch_original_baseline": "33/500 Clang-exact",
        "not_tested": "Nintendo CodeWarrior, complete DS C++ build, runtime semantics",
        "functions": rows,
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(out, indent=2) + "\n", encoding="utf-8")
    print(f"PASS: {len(rows)}/26 existing targets compiled in ARM mode; "
          f"{exact}/26 standalone Clang SHA256-exact")
    print("Report:", args.out)


if __name__ == "__main__":
    main()
