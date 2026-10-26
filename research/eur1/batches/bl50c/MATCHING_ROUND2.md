# Second byte-matching pass — 23 October 2026

Target: *The Legend of Zelda: Spirit Tracks*, EUR Rev 1 BKIP, owner-provided ROM.
No ROM contents or executable instruction bytes are committed.

## Measured results
The complete 50-function `reconstructed_50.c` research unit was compiled with
**Clang 17.0.0**, `--target=armv5te-none-eabi -march=armv5te -marm -O2
-ffreestanding -fomit-frame-pointer -ffunction-sections` and independently
compared to the SHA-1-authenticated ARM9 and overlay code, then SHA-256 checks
for every corresponding function span.

| Outcome | Before | After |
|---|---:|---:|
| C source functions | 50 | 50 |
| Standalone ARM byte-identical under Clang | **5** | **17** |
| Original instruction bytes identical | **76** | **412** |
| Original instruction bytes inspected | **1,528** | **1,528** |
| Nonmatching ARM C reconstructions | **45** | **33** |
| Nintendo CodeWarrior matches verified | 0 | 0 |
| Integrated Nintendo DS C++ matching | 0 | 0 |

### Twelve newly byte-identical functions

| Module | Address | Size | Reconstruction / purpose |
|---|---|---:|---|
| ARM9 | `0x0202EDF4` | 24 | Poll hardware halfword with a bit mask |
| Overlay 0 | `0x0205FDD0` | 40 | Initialize structured fields and pointer |
| Overlay 0 | `0x0205FDF8` | 40 | Matching sibling initializer |
| Overlay 26 | `0x02121258` | 24 | Store two constructor constants |
| Overlay 26 | `0x021212A0` | 24 | Store two constructor constants |
| Overlay 32 | `0x0211FCDC` | 24 | Store an object signature and pointer |
| Overlay 40 | `0x0212C6D0` | 28 | Set object fields and halfword type |
| Overlay 62 | `0x02159738` | 36 | Load signed halfwords and store three fields |
| Overlay 69 | `0x02159F14` | 24 | Initialize object signature and pointer |
| Overlay 69 | `0x0215A954` | 24 | Initialize object signature and pointer |
| Overlay 93 | `0x021686D4` | 36 | Read signed halfwords into object fields |
| Overlay 23 | `0x020EF9A4` | 12 | `stmib` register pair followed by a word store |

Changes were compiled and verified **together in the whole 50-function
translation unit**, not only as isolated candidate snippets. GitHub
`reconstructed_50.c` was independently checked against the validated local
copy by Git blob SHA `790bd4e99848654e8af02f8e0adb3d17284f7606`.

## Important matching limitations

- This is **Clang** ARMv5TE `-O2` matching and is **not** Nintendo original
  CodeWarrior `dsi/1.2p1` matching or an official `objdiff` DS progress figure.
- Several functions use empty GNU `asm volatile("")` barriers or
  register-specific GNU C variables. These insert **no executable
  instructions**, but constrain the compiler's register allocator and memory
  optimizer to match original instruction order. This is valid reproducible
  Clang research and **not portable C / not a CodeWarrior-ready source patch**.
- Functions with corrected Clang output still have provisional real game ABI,
  original source names and structures; no game binary was rebuilt or tested.
- The remaining 33/50 functions still compile but are **not** byte-identical.

## Re-run

```powershell
python research/eur1/batches/bl50c/verify_50.py --working-code <path-to-your-EUR1-working_code> --overlays-csv <path-to-your-EUR1-overlays.csv>
```

Expected: `PASS: 17 Clang-exact and 33 nonmatching functions; 50 source bodies`.

Next engineering step: run the real Nintendo target compiler, recover exact C++
translation units and signatures, and integrate validated functions into
`src/` using `objdiff`.
