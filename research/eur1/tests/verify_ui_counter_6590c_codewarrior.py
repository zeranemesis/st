#!/usr/bin/env python3
"""Check the integrated Spirit Tracks EUR1 overlay-000 C++ method at 0x0206590C.

Requires owner-installed Nintendo CodeWarrior dsi/1.2p1 on Windows by default.
--backend clang is an ARMv5TE smoke test ONLY. This compiles the ACTUAL C++
method extracted from the repository source using a minimal 32-bit class shim,
not the full game translation unit; passing would not prove DS link/objdiff.
The 36-byte original ROM code span is represented by a SHA256 fingerprint only.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
import tempfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "research/eur1/batches/arm9_leaf500"))
from verify_codewarrior_fifth500 import CW_FLAGS  # noqa: E402
from test_ui_counter_6590c_integration import load_actual_method, SHIM  # noqa: E402

COMPILER = ROOT / "tools/mwccarm/dsi/1.2p1/mwccarm.exe"
WRAPPER = ROOT / "tools/sjiswrap.exe"
MANIFEST = ROOT / "research/eur1/batches/arm9_leaf500/manifest_fifth500.json"

# The project uses -lang=c++ in config.cflags_base plus -str reuse for
# GameLib("Overlay 0", ...) ; see tools/configure.py.
CW_CPP_FLAGS = [("-lang=c++" if flag == "-lang c" else flag)
                for flag in CW_FLAGS if flag not in ("-lang", "c")]
CW_CPP_FLAGS = [flag for flag in CW_CPP_FLAGS if flag != "-lang"]
CW_CPP_FLAGS.extend(["-lang=c++", "-str", "reuse"])

# CodeWarrior is a C++98 compiler; do not inject C++11 static_assert checks.
# The separate Clang ARM/host integration test verifies layout offsets.
CLASS_DECLARATION = SHIM.split("static_assert(", 1)[0]
CLANG_FLAGS = [
    "--target=armv5te-none-eabi", "-march=armv5te", "-marm",
    "-O2", "-std=c++11", "-ffreestanding", "-fno-exceptions", "-fno-rtti",
    "-c",
]


def read_text_sections(blob: bytes) -> tuple[bytes, int, list[str]]:
    """Reject ambiguous/relocated sections. Never report unlinked code as exact."""
    if len(blob) < 52 or blob[:6] != b"\x7fELF\x01\x01":
        raise ValueError("Expected little-endian ARM ELF32 object")
    h = struct.unpack_from("<16sHHIIIIIHHHHHH", blob)
    if h[1] != 1 or h[2] != 40 or h[11] != 40:
        raise ValueError("Expected relocatable ARM ELF32")
    sec_off, count, idx = h[6], h[12], h[13]
    if count == 0 or idx >= count or sec_off + 40 * count > len(blob):
        raise ValueError("Bad ELF section table")
    sections = [struct.unpack_from("<10I", blob, sec_off + 40 * i)
                for i in range(count)]
    names_row = sections[idx]
    if names_row[4] + names_row[5] > len(blob):
        raise ValueError("Bad ELF section name strings")
    names = blob[names_row[4]:names_row[4] + names_row[5]]
    chosen = []
    for section_index, row in enumerate(sections):
        if row[0] >= len(names):
            continue
        end = names.find(b"\0", row[0])
        if end == -1:
            raise ValueError("Unterminated ELF section name")
        name = names[row[0]:end].decode("ascii", "replace")
        if row[1] == 1 and (name == ".text" or name.startswith(".text.")) and row[5]:
            if row[4] + row[5] > len(blob):
                raise ValueError("Truncated text section")
            chosen.append((section_index, name, blob[row[4]:row[4] + row[5]]))
    if len(chosen) != 1:
        raise ValueError(
            "Expected exactly one text section containing the single C++ method; "
            f"found {[x[1] for x in chosen]}"
        )
    section_idx, name, code = chosen[0]
    nrel = 0
    for row in sections:
        if row[1] in (4, 9) and row[7] == section_idx:
            stride = row[9] or (12 if row[1] == 4 else 8)
            if stride < (12 if row[1] == 4 else 8) or row[5] % stride:
                raise ValueError("Malformed ELF relocation entries")
            nrel += row[5] // stride
    return code, nrel, [name]


def read_reference() -> dict:
    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    matches = [f for f in manifest["functions"]
               if str(f["module"]) == "0" and f["address"].lower() == "0x0206590c"]
    if len(matches) != 1 or matches[0]["size_bytes"] != 36:
        raise ValueError("Expected one original 36-byte EUR1 overlay-000 routine")
    return matches[0]


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--backend", choices=("codewarrior", "clang"), default="codewarrior")
    ap.add_argument("--compiler", type=Path)
    ap.add_argument("--wrapper", type=Path, default=WRAPPER)
    ap.add_argument("--out", type=Path)
    args = ap.parse_args()

    reference = read_reference()
    original_method = load_actual_method()
    source = CLASS_DECLARATION + "\n" + original_method + "\n"
    backend = args.backend
    if backend == "codewarrior":
        if os.name != "nt":
            ap.error("Original CodeWarrior requires Windows")
        compiler = (args.compiler or COMPILER).resolve()
        wrapper = args.wrapper.resolve()
        if not compiler.is_file() or not wrapper.is_file():
            ap.error("Missing local CodeWarrior mwccarm.exe or sjiswrap.exe")
    else:
        compiler = args.compiler or Path("clang++")
        wrapper = None

    with tempfile.TemporaryDirectory(prefix="st_cw_ui6590c_") as tmp:
        folder = Path(tmp)
        source_path = folder / "ui_counter_6590c.cpp"
        source_path.write_text(source, encoding="ascii")
        if backend == "codewarrior":
            out_folder = folder / "output"
            out_folder.mkdir()
            command = [
                str(wrapper), str(compiler), *CW_CPP_FLAGS,
                "-c", str(source_path), "-o", str(out_folder),
            ]
        else:
            obj_path = folder / "function.o"
            command = [
                str(compiler), *CLANG_FLAGS, str(source_path),
                "-o", str(obj_path),
            ]
        proc = subprocess.run(
            command, cwd=ROOT, capture_output=True, text=True,
            errors="replace", timeout=180,
        )
        if proc.returncode:
            raise RuntimeError("Compiler failed: " + (proc.stdout + "\n" + proc.stderr)[-3000:])
        if backend == "codewarrior":
            objects = list(out_folder.glob("*.o"))
            if len(objects) != 1:
                raise ValueError(f"CodeWarrior wrote {len(objects)} objects, expected exactly 1")
            obj_path = objects[0]
        generated, relocations, sections = read_text_sections(obj_path.read_bytes())
    exact = (relocations == 0 and len(generated) == reference["size_bytes"] and
             hashlib.sha256(generated).hexdigest() == reference["original_span_sha256"])
    if relocations:
        status = "unresolved_relocations"
    elif exact:
        status = ("exact_codewarrior_standalone" if backend == "codewarrior"
                  else "exact_clang_cpp_smoke")
    elif len(generated) != reference["size_bytes"]:
        status = "different_size"
    else:
        status = "different_instructions"
    report = {
        "game": "The Legend of Zelda: Spirit Tracks",
        "revision": "EUR Rev 1", "backend": backend,
        "source": "src/000_Second/code_020657fc.cpp",
        "method": "UnkStruct_020d8698_24_5C_Base::func_ov000_0206590c",
        "address": reference["address"], "module": "overlay_000",
        "reference_size": reference["size_bytes"],
        "generated_size": len(generated),
        "reference_sha256": reference["original_span_sha256"],
        "generated_sha256": hashlib.sha256(generated).hexdigest(),
        "relocations": relocations,
        "text_sections": sections,
        "status": status,
        "exact_byte_match": exact,
        "limitations": (
            "Compilation of actual extracted method + minimal class shim, "
            "not original complete C++ translation unit or full DS objdiff/rebuild."
        ),
    }
    dest = args.out or ROOT / "build/eur1" / (
        "codewarrior_ui_counter_6590c.json" if backend == "codewarrior"
        else "clang_ui_counter_6590c_smoke.json"
    )
    dest.parent.mkdir(parents=True, exist_ok=True)
    dest.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"PASS: {backend} standalone C++ method compiled, {status}")
    print(f"Generated {len(generated)} bytes vs {reference['size_bytes']} original")
    print("Report:", dest)
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as exc:
        print("FAIL:", exc, file=sys.stderr)
        raise SystemExit(1)
