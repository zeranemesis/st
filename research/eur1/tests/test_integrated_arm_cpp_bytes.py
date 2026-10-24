#!/usr/bin/env python3
"""Recheck two real EUR1 Input C++ source bodies against known ROM hashes.

Requires clang++ and llvm-objcopy. The ROM is NOT needed: the original
20-byte/16-byte SHA-256 digests were independently established from the
legitimately extracted EUR1 ARM9 and are pinned below. This tests *Clang*
standalone ARMv5TE codegen, not CodeWarrior or actual DS game linking.
"""
from __future__ import annotations

import hashlib
from pathlib import Path
import os
import subprocess
import tempfile

from test_integrated_entry_input import ROOT, extract_cpp_function

EXPECTED = (
    ("src/Main/Player/Input.cpp", r"\bvoid\s+Input::Init\s*\([^;{}]*\)\s*\{", ".text._ZN5Input4InitEv", "ccc6541a7f0c702cc6c20c2a515b80fb904a0e0428eef6213cda5539b5363129", 20, ""),
    ("src/Main/Player/InputClearEdges.cpp", r"\bvoid\s+func_02013b88\s*\([^;{}]*\)\s*\{", ".text.func_02013b88", "c3af8a6939c13ddd13ea093ed140316b635c27636afd071b6286cd1884b79373", 16, 'extern "C" '),
)

STUB = """using u16 = unsigned short;
struct Input { u16 cur; volatile u16 press; u16 release; void Init(); };
static_assert(sizeof(Input) == 6, "Unexpected Nintendo DS input ABI");
"""


def main():
    compiler = os.environ.get("CLANGXX", "clang++")
    objcopy = os.environ.get("LLVM_OBJCOPY", "llvm-objcopy")
    with tempfile.TemporaryDirectory(prefix="st_input_arm_exact_") as d:
        dirpath = Path(d)
        for i, (path, regex, section, sha, size, linkage) in enumerate(EXPECTED):
            body = extract_cpp_function(ROOT / path, regex)
            source = dirpath / f"input_{i}.cpp"
            obj = dirpath / f"input_{i}.o"
            blob = dirpath / f"input_{i}.bin"
            source.write_text(STUB + linkage + body + "\n", encoding="utf-8")
            subprocess.run([compiler, "--target=armv5te-none-eabi", "-march=armv5te", "-marm", "-O2", "-ffreestanding", "-ffunction-sections", "-fomit-frame-pointer", "-c", str(source), "-o", str(obj)], check=True)
            subprocess.run([objcopy, "-O", "binary", f"--only-section={section}", str(obj), str(blob)], check=True)
            code = blob.read_bytes()
            actual = hashlib.sha256(code).hexdigest()
            if len(code) != size or actual != sha:
                raise AssertionError(f"ARM C++ code differs for {path}: {len(code)} bytes, SHA-256 {actual}; expected {size} / {sha}")
            print(f"PASS {path}: {size} original ARM instruction bytes matched with standalone Clang C++")
    print("UNTESTED: CodeWarrior and full DS objdiff")


if __name__ == "__main__":
    main()
