# Spirit Tracks EUR Rev 1 — 50 additional ARM9 research functions

This is a continuation of the 100-function batch in `bl100b`, now fully
published as C source, 50-entry manifest, and standalone verification script.

**Target:** owner's *The Legend of Zelda: Spirit Tracks* Europe Rev 1 (BKIP)
ROM, SHA-1 `dcb221a89acb894503a461c2c7d4cfdad9a06b68`.

## Result (measured on locally extracted EUR1 code)

| Check | Result |
| --- | ---: |
| New source C function bodies | **50** |
| Original ARM spans verified by SHA-256 | **1,528 bytes** |
| Standalone Clang ARMv5TE code byte-exact | **1 / 50** |
| Matched code bytes | **32 bytes** |
| Provisional, nonmatching C interpretations | **49 / 50** |
| Register-level C interpretations | **40** |
| Human-readable C functions | **10** |
| Standalone CodeWarrior or game objdiff verified | **No** |
| Original Nintendo DS ROM rebuilt/tested | **No** |

The single Clang byte-identical function is **ARM9 `0x02002EB8`**.
The 49 other functions compile to ARMv5TE but **do not** reproduce the
reference instruction bytes. They are research hypotheses, not verified
runtime-equivalent implementations. Original source structure, C++ owner,
ABI, function boundaries, and symbol linkage still require investigation.

All source code is research-only; it is **not integrated into normal DS
`src/` translation units**. No ROM or original ARM binary bytes are included.

## Files

- `reconstructed_50.c`: 50 C source definitions with module, address and
  SHA-256 of original instruction span.
- `manifest_50.json`: 50 unique (module, address) entries including
  expected original byte length and known Clang matching status.
- `verify_50.py`: check original image SHA-1, each span's SHA-256,
  compile to ARMv5TE with Clang, compare isolated ELF function sections.

## Reproduce the test

From your repository checkout, after extracting EUR1 from your own ROM:

```powershell
python research/eur1/batches/bl50c/verify_50.py --working-code research/eur1/working_code --overlays-csv research/eur1/reports/overlays.csv
```

The `working_code` directory may have been created elsewhere; supply its
actual location. Required: `clang` with the ARMv5TE target and Python 3.

Expected: `PASS: 1 Clang-exact and 49 nonmatching functions; 50 source bodies`.
This check has been repeated successfully with locally extracted EUR1 code.

## Next

1. Recover accurate C++ signatures, data structures and control flow for
   49 nonmatching functions instead of counting provisional C as matching.
2. Check actual CodeWarrior `dsi/1.2p1` and integrate into `src/` only
   after matching source and ABI are established.
3. Use the full game `objdiff` and emulator tests before claiming progress
   toward a playable native PC port.

Research function count alone does **not** change the official decompilation
percentage, and the ROM cannot run from these sources alone.
