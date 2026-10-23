#!/usr/bin/env python3
"""Test real EUR1 C++ source snippets (not standalone research duplicates).

No Nintendo ROM/toolchain needed. Run from any directory with a C++11 compiler:
    python research/eur1/tests/test_integrated_entry_input.py
CodeWarrior objdiff matching is deliberately NOT asserted.
"""
from __future__ import annotations

import os
from pathlib import Path
import re
import shlex
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[3]


def extract_cpp_function(path: Path, pattern: str) -> str:
    text = path.read_text(encoding="utf-8")
    matches = list(re.finditer(pattern, text, re.MULTILINE))
    if len(matches) != 1:
        raise AssertionError(f"Expected exactly one body in {path}: {pattern}")
    begin = matches[0].start()
    brace = text.index("{", matches[0].start())
    depth = 0
    for i in range(brace, len(text)):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return text[begin : i + 1]
    raise AssertionError(f"Unterminated function in {path}")


def test_layout() -> None:
    config = (ROOT / "config/eur1/arm9/delinks.txt").read_text()
    for path, start, end in (
        ("src/Main/Player/Input.cpp", "0x02013b10", "0x02013b24"),
        ("src/Main/Player/InputClearEdges.cpp", "0x02013b88", "0x02013b98"),
    ):
        pattern = re.escape(path) + r":\s*\.text\s+start:" + start + r"\s+end:" + end
        assert re.search(pattern, config), f"Missing delink range for {path}"


def test_source_semantics() -> None:
    main = extract_cpp_function(ROOT / "src/Main/Main.cpp", r"\bu32\s+func_0200093c\s*\([^;{}]*\)\s*\{")
    init = extract_cpp_function(ROOT / "src/Main/Player/Input.cpp", r"\bvoid\s+Input::Init\s*\([^;{}]*\)\s*\{")
    clear = extract_cpp_function(ROOT / "src/Main/Player/InputClearEdges.cpp", r"\bvoid\s+func_02013b88\s*\([^;{}]*\)\s*\{")
    generated = r"""
#include <cassert>
#include <cstdint>
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
struct Input { u16 cur; volatile u16 press; u16 release; void Init(); };
static_assert(sizeof(Input) == 6, "Unexpected Nintendo DS Input layout");
""" + main + "\n" + init + "\n" + clear + r"""
int main() {
    const u32 counts[] = {0, 1, 4, 5, 8, 16};
    for (u32 count : counts) {
        u32 words[8];
        for (auto &word : words) word = 0xdeadbeef;
        assert(func_0200093c(0x12345678u, words + 1, count) == 0x12345678u);
        for (unsigned i = 0; i < 8; ++i) {
            const bool written = (i >= 1 && i < 1 + (count + 3) / 4);
            assert(words[i] == (written ? 0x12345678u : 0xdeadbeefu));
        }
    }
    Input input = {};
    input.cur = input.press = input.release = 0xffff;
    input.Init();
    assert(input.cur == 0 && input.press == 0 && input.release == 0);
    input.cur = 0x1234;
    input.press = 0x4321;
    input.release = 0xffff;
    func_02013b88(&input);
    assert(input.cur == 0x1234 && input.press == 0 && input.release == 0);
}
"""
    compiler = shlex.split(os.environ.get("CXX", "c++"))
    with tempfile.TemporaryDirectory(prefix="st_eur1_input_") as td:
        source = Path(td) / "regression.cpp"
        executable = Path(td) / ("regression.exe" if os.name == "nt" else "regression")
        source.write_text(generated, encoding="utf-8")
        subprocess.run([*compiler, "-std=c++11", "-O2", "-Wall", "-Wextra", "-Werror", str(source), "-o", str(executable)], check=True)
        subprocess.run([str(executable)], check=True)


if __name__ == "__main__":
    test_layout()
    test_source_semantics()
    print("PASS: delink ranges + host semantic tests against integrated game C++ source")
    print("UNTESTED: CodeWarrior / objdiff / DS ROM build and runtime")
