#!/usr/bin/env python3
"""Exercise the ACTUAL EUR1 overlay-000 C++ method at 0x0206590C.

Extracts the implementation from src/000_Second/code_020657fc.cpp, compiles
it using a minimal C++ layout shim matching the owning header's field offsets,
and checks writes/ABI-neutral host behavior. Also compiles for ARMv5TE.
This does NOT validate Nintendo CodeWarrior/objdiff or game link readiness.
"""
from __future__ import annotations

import argparse
from pathlib import Path
import re
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[3]
CPP = ROOT / "src/000_Second/code_020657fc.cpp"
HEADER = ROOT / "include/Unknown/UICounterManager.hpp"
NAME = "UnkStruct_020d8698_24_5C_Base::func_ov000_0206590c"

# Opaque region mirrors offsets in UICounterManager.hpp, not implementation.
SHIM = """
typedef unsigned short u16;
typedef unsigned int unk32;
struct Vec2s { short x; short y; };
class UnkStruct_020d8698_24_5C_Base {
public:
    Vec2s mUnk_00;
    u16 mUnk_04;
    u16 mUnk_06;
    unsigned char opaque_08_to_7f[0x78];
    unk32 mUnk_80;
    unk32 mUnk_84;
    unk32 mUnk_88;
    unk32 mUnk_8C;
    unk32 mUnk_90;
    unk32 mUnk_94;
    void func_ov000_0206590c(u16 param1, unk32 param2);
};
static_assert(sizeof(Vec2s) == 4, "Vec2s size");
static_assert(__builtin_offsetof(UnkStruct_020d8698_24_5C_Base, mUnk_04) == 4, "param1 offset");
static_assert(__builtin_offsetof(UnkStruct_020d8698_24_5C_Base, mUnk_80) == 0x80, "opaque structure offset");
static_assert(__builtin_offsetof(UnkStruct_020d8698_24_5C_Base, mUnk_8C) == 0x8C, "param2 offset");
static_assert(__builtin_offsetof(UnkStruct_020d8698_24_5C_Base, mUnk_90) == 0x90, "mode offset");
static_assert(__builtin_offsetof(UnkStruct_020d8698_24_5C_Base, mUnk_94) == 0x94, "clear field offset");
static_assert(sizeof(UnkStruct_020d8698_24_5C_Base) == 0x98, "base class size");
"""

HOST = """
#include <cassert>
#include <cstring>
#include <cstdint>
int main() {
    const uint16_t inputs[] = {0u, 0x1234u, 0xFFFFu};
    const uint32_t data[] = {0u, 0xDEADBEEFu, 0xFFFFFFFFu};
    for (int i = 0; i < 3; ++i) {
        UnkStruct_020d8698_24_5C_Base instance;
        std::memset(&instance, 0xA5, sizeof(instance));
        instance.func_ov000_0206590c(inputs[i], data[i]);
        assert(instance.mUnk_00.x == 0 && instance.mUnk_00.y == 0);
        assert(instance.mUnk_04 == inputs[i]);
        assert(instance.mUnk_06 == 0xA5A5u);
        for (unsigned j = 0; j < sizeof(instance.opaque_08_to_7f); ++j) {
            assert(instance.opaque_08_to_7f[j] == 0xA5u);
        }
        assert(instance.mUnk_80 == 0xA5A5A5A5u);
        assert(instance.mUnk_84 == 0xA5A5A5A5u);
        assert(instance.mUnk_88 == 0xA5A5A5A5u);
        assert(instance.mUnk_8C == data[i]);
        assert(instance.mUnk_90 == 2u);
        assert(instance.mUnk_94 == 0u);
    }
    return 0;
}
"""


def load_actual_method() -> str:
    header = HEADER.read_text(encoding="utf-8")
    if "void func_ov000_0206590c(u16 param1, unk32 param2);" not in header:
        raise ValueError("Owning class declaration or signature changed")
    original = CPP.read_text(encoding="utf-8")
    pattern = r"void\s+" + re.escape(NAME) + r"\s*\(\s*u16\s+param1\s*,\s*unk32\s+param2\s*\)\s*\{"
    matches = list(re.finditer(pattern, original))
    if len(matches) != 1:
        raise ValueError("Expected one C++ method definition")
    match = matches[0]
    depth = 0
    for pos in range(match.end() - 1, len(original)):
        if original[pos] == "{":
            depth += 1
        elif original[pos] == "}":
            depth -= 1
            if depth == 0:
                return original[match.start():pos + 1]
    raise ValueError("Unterminated C++ method")


def compile_checked(cmd: list[str]) -> None:
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode:
        raise RuntimeError("Compiler failed: " + result.stderr[-3000:])


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clangxx", default="clang++")
    args = ap.parse_args()
    method = load_actual_method()
    with tempfile.TemporaryDirectory(prefix="st_cpp6590c_") as tmp:
        directory = Path(tmp)
        src = directory / "recovered.cpp"
        src.write_text(SHIM + "\n" + method + "\n", encoding="utf-8")
        out = directory / "recovered_arm.o"
        compile_checked([
            args.clangxx, "--target=armv5te-none-eabi", "-march=armv5te", "-marm",
            "-std=c++11", "-O2", "-ffreestanding", "-fno-exceptions",
            "-fno-rtti", "-c", str(src), "-o", str(out),
        ])
        if not out.is_file() or out.stat().st_size == 0:
            raise RuntimeError("No ARMv5TE object produced")
        src.write_text(SHIM + "\n" + method + "\n" + HOST, encoding="utf-8")
        host = directory / "test_host"
        compile_checked([
            args.clangxx, "-std=c++11", "-O1", "-g", "-Wall", "-Wextra",
            "-Werror", "-fsanitize=address,undefined",
            "-fno-omit-frame-pointer", str(src), "-o", str(host),
        ])
        run = subprocess.run([str(host)], capture_output=True, text=True)
        if run.returncode:
            raise RuntimeError("Host semantic tests failed: " + run.stderr[-3000:])
    print("PASS: production C++ method 0x0206590C compiles as ARMv5TE C++")
    print("PASS: header signature/field offsets and 3 host semantic vectors")
    print("NOT TESTED: Nintendo CodeWarrior objdiff or complete DS game build")


if __name__ == "__main__":
    main()
