# Matching round 3 — EUR Rev 1 (23 October 2026)

This round continues ARM9/overlay **Clang** byte-matching on the existing
`bl50c` research batch of fifty Spirit Tracks EUR Rev 1 functions.
No ROM, overlay binaries or original machine-code blobs are stored here.

## Results independently recompiled and compared

| Metric | Round 2 | Round 3 | Change |
| --- | ---: | ---: | ---: |
| Standalone Clang ARMv5TE byte-exact functions | 17/50 | **20/50** | **+3** |
| Exact original code bytes | 412 | **448** | **+36** |
| Examined original code bytes | 1,528 | **1,528** | — |
| Still nonmatching | 33 | **30** | −3 |
| Nintendo original CodeWarrior matches established | 0 | 0 | — |
| Nintendo DS integrated `objdiff` matches established | 0 | 0 | — |

### Newly matched C reconstructions

| Module | Address | Size | Notes |
| --- | --- | ---: | --- |
| Main ARM9 | `0x0202815C` | 12 | Reconstructs unsigned subtraction loop using Clang `__builtin_usub_overflow` and an empty GNU register barrier. Verifies the original ARM condition-code behavior. |
| Main ARM9 | `0x02028390` | 8 | Reconstructs ARM `CLZ` using `__builtin_clz` and a Clang nonzero assumption to suppress an extra conditional sequence. **The assumption is a source-level precondition, NOT proven true of the original game.** The emitted binary `CLZ` still handles zero in hardware. |
| Overlay 032 | `0x0211DA50` | 16 | Reconstructs a two-word swap using two ARM register constraints to reproduce the original load order and `STMIB`. |

### Reproduction

The full standalone C translation unit has been tested successfully against
the original code images extracted from the owner's EUR1 (BKIP) ROM.
Compilation options: Clang 17 ARMv5TE, `-marm -O2 -ffreestanding
-fomit-frame-pointer -ffunction-sections`. Each reference ROM module is
checked by SHA-1, and each of the 50 instruction spans is checked by SHA-256
before comparing the generated per-function ELF text section.

```powershell
python research/eur1/batches/bl50c/verify_50.py --working-code C:\path\to\working_code --overlays-csv C:\path\to\overlays.csv
```

Expected: `PASS: 20 Clang-exact and 30 nonmatching functions; 50 source bodies`.

The updated GitHub C file's Git blob SHA is
`9527c935cd79832e1e5196e13c54eb1bc71c789a`, exactly matching the
source file used for the successful full-suite local comparison.

## Critical limitations

- These are **isolated ARMv5TE byte matches under Clang**, not proof of
  matching with original Nintendo CodeWarrior `dsi/1.2p1`.
- `__builtin_assume(x != 0)`, register annotations and GNU empty-assembly
  barriers constrain Clang optimization. They are **not original Nintendo
  C++ source** and may change C-level semantics if their assumptions fail.
- CodeWarrior matching, integration into normal DS `src/` units,
  `objdiff` and a rebuilt/tested game are still outstanding.
- No progress percentage toward the eventual native PC port can be inferred
  from these standalone matching numbers.

The 30 remaining nonmatching routines are intentionally left marked
`clang_byte_exact: false` in the manifest until truly reproduced.
