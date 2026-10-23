# EUR1 game-source integration — ARM9 entry and input

This branch promotes two small previously recovered **input** routines from
standalone research into real `src/` translation units, and corrects the
semantics of one existing ARM9 startup routine.

| ARM9 address | Symbol / location | Change | Evidence | Remaining verification |
| --- | --- | --- | --- | --- |
| `0x0200093C` | `func_0200093c`, `src/Main/Main.cpp` | Corrected destination progression, byte length, return register | Original five-instruction disassembly recorded in `research/eur1/src/entry_fill32_semantics.c` | Build CodeWarrior and compare original function bytes |
| `0x02013B10` | `Input::Init`, `src/Main/Player/Input.cpp` | New C++ translation unit implementing three 16-bit zero stores | **Actual C++ body** Clang ARMv5TE byte equality, 20 bytes | CodeWarrior + original project `objdiff` |
| `0x02013B88` | `func_02013b88`, `src/Main/Player/InputClearEdges.cpp` | New C++ translation unit resetting both edge masks | **Actual C++ body** Clang ARMv5TE byte equality, 16 bytes | CodeWarrior + original project `objdiff` |

The two new source units are mapped to exact symbol ranges in
`config/eur1/arm9/delinks.txt`. Other code in the gap is intentionally left
unimplemented; this is **not** a claim that the entire input subsystem matches.

**No new ROM-byte matches have been established by this integration.**
The 20- and 16-byte addresses had already been counted in the previous standalone C research batches. The two **new integrated C++ implementations** have now independently reproduced those same 36 original ARM9 bytes with Clang ARMv5TE using a six-byte mock `Input` layout. This is stronger source-level evidence, but **not** original Nintendo CodeWarrior matching; the official matching count remains unchanged.

## Host regression test (no ROM needed)

From the repository root:

```sh
python research/eur1/tests/test_integrated_entry_input.py
python research/eur1/tests/test_integrated_arm_cpp_bytes.py
```

The first test compiles extracts from the **actual C++ source files** and runs startup fill and input reset host tests. The second separately compiles those same input C++ bodies as ARMv5TE with `clang++`, extracts function sections using `llvm-objcopy`, and verifies the original SHA-256 digests (**20/20 + 16/16 matched** in the local toolchain). Neither verifies CodeWarrior, DS object linkage, or gameplay.

## DS verification (owner's legally dumped EUR1 ROM required)

1. Build the `eur1` target using `BUILD_WINDOWS.md`.
2. Check for `Input::Init` / `func_02013b88` in the resulting object list and compare `0x02013B10..0x02013B24` and `0x02013B88..0x02013B98` in `objdiff`.
3. Compare startup `0x0200093C..0x02000950` in the same way.
4. Fix C++ code generation and source linkage if size, relocations, or bytes differ.
5. Rebuild/run EUR1 in a DS emulator and verify keys, transitions and startup.

The original ROM and game assets remain outside Git.
