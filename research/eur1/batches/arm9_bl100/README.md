# Spirit Tracks EUR Rev 1 — 100 new BL-referenced ARM9 C candidates

This is an **experimental decompilation research batch** for the user's personal fork.
The objective is eventually to reconstruct the original DS game's source, not
start the native PC port. **No Nintendo ROM, overlay, or copyrighted game asset
is stored in this directory.**

## Actual reproducible result (23 October 2026)

| Check | Result |
| --- | ---: |
| Newly catalogued `(module,address)` starts | **100** |
| Direct ARM `BL` callsites referencing the 100 starts | **123** |
| Modules covered (ARM9 main + 27 overlays) | **28** |
| All research C functions compile in Clang ARMv5TE | **100/100** |
| Standalone Clang `-O2` function-code sections byte-identical to original EUR1 ROM | **16/100** |
| Original executable instruction bytes independently checked against local EUR1 ROM | **2,144** |
| Instruction bytes of the 16 exact Clang functions | **260** |
| Other C reconstructions that compile but **do not match** | **84** |
| Standalone original CodeWarrior matches measured | **Not tested** |
| Integrated normal DS C++/objdiff matches | **0** |

All 100 addresses have at least one recorded direct ARM `BL` caller in the same executable
module. This is stronger entry evidence than an isolated epilogue, but **still
not a proof of the original function's full bounds, C++ owner, ABI, or semantics**.
The research C parameter types are deliberately provisional.

The 100 recorded `(module,address)` pairs are disjoint from the older 2,600
research entries **and** the newer 185 unique catalog entries contributed in
`research/eur1/batches/new100` and `arm9_new34`. Overlay 0 entries were also
checked against the separate 165-function research catalog.

## Files

- `reconstructed_100_new.c`: 100 actual standalone C bodies (not stubs or TODO declarations).
- `manifest_100_new.json`: original addresses, source module, byte lengths,
  SHA-256, original `BL` callsites, per-function `clang_armv5te_exact` result.
- `verify_100_new.py`: independently compiles all C functions for ARMv5TE,
  validates each local original executable image by SHA-1, checks the 100
  original span hashes, checks ELF function sections without unresolved
  relocations, and fails if the 16/84 result changes.
- `local_verify_results.json`: summary of the author's local test, not a
  CodeWarrior result.

## Verify from Windows (with local EUR Rev 1 overlays)

The repository's existing EUR1 research workflow can extract and decode the
original ROM into a `working_code` directory with `arm9.bin` and
`overlay_000.bin` through `overlay_113.bin`. Supply the location of your own
local extracted directory (no ROM bytes need to be uploaded).

```powershell
cd C:\st
git pull --ff-only origin main
python research/eur1/batches/arm9_bl100/verify_100_new.py --working-code "C:\path\to\working_code"
```

The verifier needs LLVM Clang with an ARM target (`clang --version`). It should
report **16/100 Clang byte-exact**. A reported `PASS` means the regression
checks succeeded, **not** that all 100 original source functions are matched.

## Next reverse-engineering work

1. Recover original signatures, class ownership and complete boundaries for
   the direct `BL` targets; inspect documented callers.
2. Use Nintendo-target **CodeWarrior ARM dsi/1.2p1**, not Clang, for the next
   comparison. It may produce a different matching count.
3. Prioritize 84 nonmatching C bodies, examining original instructions and
   compiler register/optimization differences. Avoid treating provisional C
   behavior as a verified Nintendo implementation.
4. Integrate only independently verified functions into their original game
   C++ translation units and measure matching with `objdiff` and the full
   `ninja ... check_eur1` build.

No normal DS game source file is modified in this research batch.

## Original CodeWarrior standalone verification (Windows)

The optional [`verify_codewarrior_100_new.py`](verify_codewarrior_100_new.py)
uses the same original **Nintendo-target CodeWarrior dsi/1.2p1** and working
compiler flags as the previously successful first-100 verifier. It reads
the original EUR1 instruction SHA-256 from this batch manifest and does
not need a ROM during the test.

```powershell
cd C:\st
git pull --ff-only origin main
python research/eur1/batches/arm9_bl100/verify_codewarrior_100_new.py
```

It will write `C:\st\build\eur1\codewarrior_bl100_new.json`. **No
CodeWarrior matching result has been obtained for these new 100 yet.** The
verified 50/100 number above is from Clang, not CodeWarrior. The game
C++ build and objdiff baseline remain unchanged.
