#!/usr/bin/env python3
"""Cross-check fifth-batch overlay-000 C research against original C++ ownership.

Uses only already committed EUR1 manifest/symbol/delink metadata. It DOES NOT
infer C++ ownership for addresses outside explicit delink text ranges. A named
mangled C++ symbol may be an alias/wrapper rather than a distinct source body.
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[4]
MANIFEST = ROOT / "research/eur1/batches/arm9_leaf500/manifest_fifth500.json"
SYMBOLS = ROOT / "config/eur1/arm9/overlays/ov000/symbols.txt"
DELINKS = ROOT / "config/eur1/arm9/overlays/ov000/delinks.txt"

SYMBOL_RE = re.compile(
    r"^(\S+) kind:function\((?:arm|thumb),size=0x([0-9a-f]+)\) addr:(0x[0-9a-f]+)$"
)
TEXT_RE = re.compile(
    r"^\s*\.text\s+start:(0x[0-9a-f]+)\s+end:(0x[0-9a-f]+)(?:\s|$)"
)
PATH_RE = re.compile(r"^(src/[^:]+):$")


def load_symbol_map() -> dict[int, dict]:
    parsed = {}
    for line in SYMBOLS.read_text(encoding="utf-8").splitlines():
        m = SYMBOL_RE.match(line)
        if m:
            address = int(m[3], 16)
            if address in parsed:
                raise ValueError(f"Duplicated symbol boundary 0x{address:08X}")
            parsed[address] = {"name": m[1], "size": int(m[2], 16)}
    if not parsed:
        raise ValueError("No symbols found; EUR1 config may have changed")
    return parsed


def load_owned_ranges() -> list[dict]:
    owner = None
    ranges = []
    for line in DELINKS.read_text(encoding="utf-8").splitlines():
        p = PATH_RE.match(line)
        if p:
            owner = p[1]
            continue
        if line and not line.startswith((" ", "\t")):
            owner = None
        m = TEXT_RE.match(line)
        if m and owner is not None:
            start, end = int(m[1], 16), int(m[2], 16)
            if end <= start:
                raise ValueError(f"Invalid delink text range in {owner}")
            ranges.append({"owner": owner, "start": start, "end": end})
    ranges.sort(key=lambda r: r["start"])
    for first, second in zip(ranges, ranges[1:]):
        if second["start"] < first["end"]:
            raise ValueError(f"Overlapping delink source ranges: {first}, {second}")
        if not (ROOT / first["owner"]).is_file():
            raise FileNotFoundError(f"Delink source missing: {first['owner']}")
    return ranges


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out", type=Path,
                        default=ROOT / "build/eur1/overlay000_fifthbatch_ownership.json")
    args = parser.parse_args()
    entries = json.loads(MANIFEST.read_text(encoding="utf-8"))["functions"]
    selected = [r for r in entries if str(r["module"]) == "0"]
    if len(entries) != 500 or not selected:
        raise ValueError("Expected full fifth-500 manifest including overlay 000")
    symbols = load_symbol_map()
    ranges = load_owned_ranges()
    result = []
    for source in selected:
        address = int(source["address"], 16)
        label = symbols.get(address)
        owner = next((r["owner"] for r in ranges
                      if r["start"] <= address < r["end"]), None)
        # Symbol name preservation is intentional; demangling the Itanium-like
        # C++ string can falsely assign a source function to a neighboring thunk.
        mangled = label is not None and label["name"].startswith("_ZN")
        result.append({
            "address": source["address"], "direct_bl_references": source["direct_BL_references"],
            "original_size": source["size_bytes"],
            "original_name": label["name"] if label else None,
            "symbol_size_agrees": (label["size"] == source["size_bytes"])
                                  if label else False,
            "cpp_mangled_symbol": mangled,
            "delink_cpp_owner": owner,
            "candidate_status": source["clang_standalone_status"],
            "integration_evidence": (
                "configured_source_range_only" if owner else "no_configured_source_range"
            ),
        })
    count_mangled = sum(row["cpp_mangled_symbol"] for row in result)
    count_owned = sum(row["delink_cpp_owner"] is not None for row in result)
    owned_mangled = sum(row["cpp_mangled_symbol"] and
                       row["delink_cpp_owner"] is not None for row in result)
    ui = next((row for row in result if row["address"].lower() == "0x0206590c"), None)
    if ui is None or ui["delink_cpp_owner"] != "src/000_Second/code_020657fc.cpp":
        raise ValueError("Integration unit 0x0206590C no longer matches EUR1 delink")
    if not ui["cpp_mangled_symbol"] or not ui["symbol_size_agrees"]:
        raise ValueError("Original UI C++ symbol/size evidence invalid")
    report = {
        "source": "Original fifth 500 C research targets, overlay 000 only",
        "overlay_candidates": len(result), "mangled_cpp_symbols": count_mangled,
        "configured_cpp_source_ranges": count_owned,
        "both_mangled_and_configured_owner": owned_mangled,
        "not_a_game_decomp_completion_percentage": True,
        "cautions": (
            "Source ownership comes only from explicit EUR1 delinks; "
            "C++ mangled symbol may be an alias, wrapper or constructor; "
            "no CodeWarrior objdiff or game build proved"
        ),
        "functions": result,
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"PASS: {len(result)} overlay-000 fifth-batch targets classified")
    print(f"C++ symbols: {count_mangled}; configured owning sources: {count_owned}; "
          f"both: {owned_mangled}")
    print("Confirmed EUR1 owner 0x0206590C:", ui["delink_cpp_owner"])
    print("Report:", args.out)


if __name__ == "__main__":
    main()
