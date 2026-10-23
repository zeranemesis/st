# Spirit Tracks EUR Rev 1: 100 additional ARM9 BL-target C reconstructions

This sixth research batch adds **100 original ARM9 direct-call target addresses**,
with no `(module,address)` repeats in the earlier 100 + 165 + 500 + 500 +
1,000 + 500 published research manifests. The reference data is the owner's
SHA-1-verified European Rev 1 BKIP ROM. **No ROM bytes are included in this repository.**

## Audited results (2026-10-23)

| Check | Result |
| --- | ---: |
| New C function bodies | **100** |
| Distinct ARM9 modules | **28** |
| Original code spans cross-checked against local ROM | **100/100 (2,080 bytes)** |
| Functions independently compiled by Clang ARMv5TE -O2 | **100/100** |
| Clang exact instruction and size match | **37 / 100 (428 bytes)** |
| Of the 37 exact: new readable typed C memory routines | **17** |
| Of the 37 exact: other small C return/accessor routines | **20** |
| Compiles, original-sized but different instructions | **21** |
| Compiles with different instruction size | **42** |
| CodeWarrior exact matching | **Not run** |
| Normal Nintendo DS C++ source integration and objdiff matching | **Not performed** |

All 100 entries have at least one **direct ARM BL reference in the same
original code module**, which provides evidence of original entrypoints.
The exact original C++ types, method owners and complete CFGs still require
reverse engineering. In particular, the 63 **nonmatching** candidates are
provisional register-oriented translations that have **not been runtime
behavior-tested** and may have C semantic errors. Do not count the 100 as
100 complete matching C++ source functions or working gameplay subsystems.

## Files

- `arm9_new100_part1.c` and `arm9_new100_part2.c`: 50 independent C definitions each;
  exact and provisional C code are clearly labeled by original module/address.
- `manifest_new100.json`: 100 original module/addresses, proof type, reference
  SHA256, exact/different-size/different-instructions classifications, module
  SHA1 and RAM bases.
- `local_validation.json`: summary of completed local Clang verification.
- `verify_new100.py`: reproducible source/ROM/Clang validation.
- `verify_codewarrior_new100.py`: optional Windows-installed CodeWarrior
  `dsi/1.2p1` standalone comparison with automatic failed-batch bisection.

## Reproduce byte-exact Clang checks

Extract the EUR Rev 1 overlays into a local `working_code` directory containing
files such as `arm9.bin` and `overlay_016.bin`, then from repository root run:

```powershell
python research/eur1/batches/arm9_new100/verify_new100.py --working-code "C:\path\to\working_code"
```

It verifies the complete original module SHA1 then recompiles and compares
each function code section with its original ARM9 ROM instruction span.

## Check with the actual Nintendo DS CodeWarrior compiler on Windows

```powershell
cd C:\st
git pull --ff-only origin main
python research/eur1/batches/arm9_new100/verify_codewarrior_new100.py
```

Writes `C:\st\build\eur1\codewarrior_new100.json` with per-function
machine-code SHA256, generated size, relocation and errors, plus a count of
`exact_codewarrior_standalone` matches. All original compiler results remain
**unknown** until this is run on Windows. On Linux, `--backend clang` performs
a regression-only smoke check (37/100), **not** CodeWarrior matching.

The source code remains outside the actual game build. Next substantive work
is confirming C++ ownership/signatures, rewriting the 63 provisional functions
into accurate higher-level semantics, and checking integration via the actual
CodeWarrior build + `objdiff`.
