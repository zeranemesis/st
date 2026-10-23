# Spirit Tracks EUR Rev 1 — 100 additional ARM9 C research functions

**Sixth research batch**, built from the user's own ROM SHA-1 `dcb221a89acb894503a461c2c7d4cfdad9a06b68`.

- **100 new `(module,address)` C bodies**, excluding the 2,600 addresses from the previous five published research batches. Each address was identified by at least one direct ARM `BL` call in the original module, but owning C++ classes and ABI still need to be recovered.
- Source: [`new100.c`](new100.c); 100 standalone, small ARM9 leaf translations with provisional register-oriented C signatures.
- Original code spans: **2,320 instruction bytes across 37 modules**. The manifest records SHA-256 of the original bytes and SHA-1 of each extracted module.
- **100/100 sources compile** with Clang targeting ARMv5TE `-O2`; **17/100 have identical original ARM bytes**, **30 more have identical size but different instructions**, **53 have different sizes**.
- **83 C translations are not byte-exact**. They may have incorrect semantics, especially for low-level register/memory behavior, and should remain research only. **Original CodeWarrior matching: not tested. Official DS game-source integration: not done.**

## Reproduce the check on your own extracted ROM

Run at the root of the personal `zeranemesis/st` repo, with `clang` on PATH and the existing EUR1 extraction workflow output:

```powershell
python research/eur1/batches/new100/verify_new100.py --working-code "C:\path\to\working_code"
```

This command recompiles the 100 C bodies, validates all original module SHA-1s, checks all 100 original ROM span SHA-256 values and compares the exact bytes of every emitted ELF function. It uses the project's existing standalone ELF reader from `research/eur1/batches/overlay_candidates_1000/verify_candidates_1000.py`.

An isolated Clang match is not a CodeWarrior/objdiff match. No ROM, overlays, executable binaries, or proprietary compiler binaries are included.
