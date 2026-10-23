# Seven newly Clang-exact ARM9 C rewrites — fifth batch

**2026-10-23.** These are replacements of **seven existing fifth-batch C bodies**, not seven new ROM addresses. This audit preserves the game ROM/proprietary compiler outside GitHub.

## Verified standalone Clang results

| Module | Address | Original instruction bytes | Original direct BL references | C operation |
| --- | --- | ---: | ---: | --- |
| Overlay 0 | `0x0207901C` | 20 | 2 | Zero 16-bit fields at +16/+18 and 32-bit field at +20 |
| Overlay 0 | `0x02087DE0` | 20 | 4 | Zero first 32-bit field, store input halfword at +4, zero halfword at +6 |
| Overlay 26 | `0x020D9710` | 16 | 6 | Zero 32-bit fields at +0 and +288 |
| Overlay 26 | `0x020EEB00` | 16 | 3 | Clear status byte at +385 and store input 32-bit field at +0 |
| Overlay 66 | `0x02158FD4` | 20 | 2 | Clear bytes +64/+65 and 32-bit word +60 |
| Overlay 89 | `0x0216635C` | 16 | 2 | Zero halfwords at +84/+126 |
| Overlay 91 | `0x02175828` | 12 | 2 | Write input words at +112 and +120 |

For all seven, LLVM Clang ARMv5TE `-O2 -ffunction-sections` emits a function code section whose **length and every instruction byte match the exact SHA-256 fingerprint of the original decoded EUR Rev 1 overlay**. No per-function relocations were present in the compiled code.

The C implementations use typed pointers and `volatile` where the ARM code has ordered stores, rather than the previous register-state interpreter. Some C signatures are intentionally `void` because the original machine code returns via `BX LR` without placing a new return value in `r0`; final C++ signature and translation-unit ownership must still be independently recovered.

## Reproduction

From the repository root, with a locally extracted/decompressed EUR Rev 1 ROM:

```powershell
python research/eur1/batches/arm9_leaf500/verify_fifth500.py --working-code "C:\path\to\working_code"
python research/eur1/batches/arm9_leaf500/verify_codewarrior_fifth500.py --backend clang
```

Revalidated results: **33/500 Clang-exact** (+7), **138/500 instruction-different** (−7), **329/500 size-different** (unchanged). All 500 still compile with Clang; all 500 original SHA-256 spans are authentic.

**CodeWarrior ARM dsi/1.2p1 has NOT been run for these seven revised C bodies.** The original Windows-only standalone compiler probe remains available (`verify_codewarrior_fifth500.py` with default backend), and game build/objdiff integration is still **zero**. Do not count these as seven newly integrated original C++ functions or complete subsystems.
