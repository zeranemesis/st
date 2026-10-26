#!/usr/bin/env python3
"""Match the 10 readable EUR1 overlay-000 round-11 functions with original CodeWarrior.

Default backend: original Nintendo dsi/1.2p1 on Windows (requires user-installed
compiler and sjiswrap). --backend clang is a PORTABLE SMOKE TEST, never proof
of CodeWarrior/objdiff matching. The ten functions are isolated, each in its
own translation unit, to reveal per-function compiler errors. No ROM required:
the reference sizes/hashes were previously extracted from the owner's EUR1 ROM.
"""
from __future__ import annotations

import argparse
from collections import Counter
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import tempfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]
MANIFEST = HERE / "manifest_fifth500.json"
SOURCE = HERE / "semantic_refactors_round11.c"
DEFAULT_COMPILER = ROOT / "tools/mwccarm/dsi/1.2p1/mwccarm.exe"
DEFAULT_WRAPPER = ROOT / "tools/sjiswrap.exe"
TARGET_ADDRESSES = (
    "0x02057D6C", "0x020590E4", "0x0205B090", "0x0205C5A0",
    "0x02060738", "0x02060804", "0x02062E44", "0x02065460",
    "0x0206547C", "0x0206590C",
)

# Share the maintained ELF32 symbol/relocation parser and compiler switches
# with the already existing fifth-batch CodeWarrior verifier.
from verify_codewarrior_fifth500 import (
    CW_FLAGS, CLANG_FLAGS, LOCAL_TYPES, parse_arm_elf_symbols,
)

FUNCTION_PATTERN = re.compile(
    r"\buint32_t\s+(st_ov000_[0-9A-F]{8})\s*\([^;{}]*\)\s*\{"
)


def recover_functions(code: str) -> dict[str, str]:
    blocks: dict[str, str] = {}
    for match in FUNCTION_PATTERN.finditer(code):
        depth = 0
        for i in range(match.end() - 1, len(code)):
            if code[i] == "{":
                depth += 1
            elif code[i] == "}":
                depth -= 1
                if depth == 0:
                    if match.group(1) in blocks:
                        raise ValueError("Duplicate C definition: " + match.group(1))
                    blocks[match.group(1)] = code[match.start():i + 1]
                    break
        else:
            raise ValueError("Unterminated C definition: " + match.group(1))
    return blocks


def source_shim(original: str) -> str:
    """Remove modern C99 header dependencies for historical CodeWarrior."""
    macros = [s for s in original.splitlines() if s.startswith("#define ST_")]
    if len(macros) != 4:
        raise ValueError("Expected the four shared read/write macros")
    return LOCAL_TYPES + "\n#define UINT16_MAX 65535u\n" + "\n".join(macros) + "\n"


def run_one(
    symbol: str, code: str, source_prefix: str, directory: Path,
    backend: str, compiler: Path, wrapper: Path,
) -> tuple[dict | None, str | None]:
    src = directory / (symbol + ".c")
    obj = directory / (symbol + ".o")
    src.write_text(source_prefix + code + "\n", encoding="ascii")
    if backend == "clang":
        cmd = [str(compiler), *CLANG_FLAGS, "-c", str(src), "-o", str(obj)]
    else:
        dest = directory / ("object_" + symbol)
        dest.mkdir()
        cmd = [str(wrapper), str(compiler), *CW_FLAGS,
               "-c", str(src), "-o", str(dest)]
    try:
        proc = subprocess.run(
            cmd, cwd=ROOT, capture_output=True, text=True,
            errors="replace", timeout=180,
        )
        if proc.returncode:
            return None, (proc.stdout + "\n" + proc.stderr)[-2500:].strip()
        if backend == "codewarrior":
            objs = list(dest.glob("*.o"))
            if len(objs) != 1:
                return None, f"Expected one CodeWarrior ELF object, found {len(objs)}"
            obj = objs[0]
        found = parse_arm_elf_symbols(obj.read_bytes(), {symbol})
        return found.get(symbol), None
    except (OSError, subprocess.SubprocessError, ValueError) as error:
        return None, str(error)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--backend", choices=("codewarrior", "clang"),
                        default="codewarrior")
    parser.add_argument("--compiler", type=Path)
    parser.add_argument("--wrapper", type=Path, default=DEFAULT_WRAPPER)
    parser.add_argument("--out", type=Path)
    args = parser.parse_args()

    if args.backend == "codewarrior" and os.name != "nt":
        parser.error("Original CodeWarrior requires Windows")
    compiler = args.compiler or (
        DEFAULT_COMPILER if args.backend == "codewarrior" else Path("clang")
    )
    if args.backend == "codewarrior":
        if not compiler.is_file() or not args.wrapper.is_file():
            parser.error("Missing local mwccarm.exe or sjiswrap.exe")
        compiler = compiler.resolve()
        wrapper = args.wrapper.resolve()
    else:
        wrapper = args.wrapper

    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    candidates = {(str(row["module"]), row["address"].upper()): row
                  for row in manifest["functions"]}
    if len(candidates) != 500:
        raise ValueError("Original fifth-500 manifest is not unique")
    original = SOURCE.read_text(encoding="utf-8")
    prefix = source_shim(original)
    functions = recover_functions(original)
    wanted = {f"st_ov000_{int(a, 16):08X}" for a in TARGET_ADDRESSES}
    if set(functions) != wanted:
        raise ValueError("Round-11 source does not contain exactly ten targets")
    rows: list[dict] = []
    with tempfile.TemporaryDirectory(prefix="st_cw_round11_") as tmp:
        for address in TARGET_ADDRESSES:
            f = candidates.get(("0", address.upper()))
            if f is None:
                raise ValueError("No overlay 0 evidence for " + address)
            symbol = f"st_ov000_{int(address, 16):08X}"
            record, error = run_one(
                symbol, functions[symbol], prefix, Path(tmp), args.backend,
                compiler, wrapper,
            )
            row = {
                "module": "overlay_000", "address": address, "symbol": symbol,
                "expected_size": f["size_bytes"],
                "reference_sha256": f["original_span_sha256"],
            }
            if error:
                row.update(status="compiler_error", error=error)
            elif record is None:
                row["status"] = "not_emitted"
            elif "error" in record:
                row["status"] = record["error"]
            else:
                row["generated_size"] = record["size"]
                row["generated_sha256"] = record["sha256"]
                row["relocations"] = record["relocations"]
                if record["relocations"]:
                    row["status"] = "unresolved_relocations"
                elif record["size"] != f["size_bytes"]:
                    row["status"] = "different_size"
                elif record["sha256"] == f["original_span_sha256"]:
                    row["status"] = (
                        "exact_codewarrior_standalone" if args.backend == "codewarrior"
                        else "exact_clang_smoke"
                    )
                else:
                    row["status"] = "different_instructions"
            rows.append(row)

    counts = dict(sorted(Counter(x["status"] for x in rows).items()))
    out = args.out or ROOT / "build/eur1" / (
        "codewarrior_round11.json" if args.backend == "codewarrior"
        else "clang_round11_smoke.json"
    )
    report = {
        "game": "The Legend of Zelda: Spirit Tracks", "revision": "EUR Rev 1",
        "backend": args.backend, "standalone_only": True,
        "functions_checked": len(rows), "counts": counts, "results": rows,
        "limitations": (
            "Standalone machine-code comparison only; no verified game C++ "
            "translation unit, objdiff, full DS rebuild, or native PC port."
        ),
    }
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"PASS: {len(rows)}/10 candidate functions examined with {args.backend}")
    print("Counts:", counts)
    print("Report:", out)
    return 0 if len(rows) == 10 else 1


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (ValueError, OSError, RuntimeError, subprocess.SubprocessError) as exc:
        print("FAIL:", exc, file=sys.stderr)
        raise SystemExit(1)
