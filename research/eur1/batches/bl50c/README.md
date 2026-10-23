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
| Standalone Clang ARMv5TE code byte-exact | **24 / 50** |
| Matched code bytes | **584 bytes** |
| Provisional, nonmatching C interpretations | **26 / 50** |
| Register-level C interpretations | **40** |
| Human-readable C functions | **10** |
| Standalone CodeWarrior or game objdiff verified | **No** |
| Original Nintendo DS ROM rebuilt/tested | **No** |

Five Clang byte-identical functions are ARM9 `0x02002EB8` (32 bytes), overlay 0 `0x0205B1CC` (12 bytes), overlay 0 `0x020A6C60` (12 bytes), overlay 26 `0x020F7A3C` (8 bytes) and overlay 31 `0x020E0398` (12 bytes).
The 26 other functions compile to ARMv5TE but **do not** reproduce the
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

Expected: `PASS: 24 Clang-exact and 26 nonmatching functions; 50 source bodies`.
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

## Corrections additionnelles

Des erreurs d'offset de mémoire ont été corrigées dans les fonctions des overlays 0, 23 et 32 aux adresses `0x0205B1CC`, `0x020EF9A4` et `0x0211DA50`. La première est maintenant reproduite octet pour octet avec Clang ARMv5TE. Ces modifications ont été revalidées sur la ROM EUR1 originale (2/50 matching Clang isolés); les deux autres corrections sont sémantiques seulement et restent non matching. La signature C++ originale et CodeWarrior ne sont toujours pas validés.

Trois reconstructions de stockage multiple ARM supplémentaires (`0x020A6C60`, `0x020F7A3C`, `0x020E0398`) reproduisent désormais les octets de la ROM avec Clang après correction du type de pointeur. Cette équivalence Clang ne vaut pas confirmation de l'ABI et des signatures CodeWarrior.

## Matching round 2 (23 October 2026)

The full research unit has been recompiled and compared against the owner's SHA-1 checked EUR1 ARM9/overlay code: **17/50 isolated Clang matches, 412 exact bytes out of 1,528**. This adds twelve byte-identical C implementations in module/address slots #9, #10, #11, #25, #26, #30, #32, #33, #34, #35, #40 and #43. New exact addresses: `0x0202EDF4`, `0x0205FDD0`, `0x0205FDF8`, `0x02121258`, `0x021212A0`, `0x0211FCDC`, `0x0212C6D0`, `0x02159738`, `0x02159F14`, `0x0215A954`, `0x021686D4` and `0x020EF9A4` (module identity matters). See `MATCHING_ROUND2.md` for limitations and source details.

**Important:** To control Clang allocation and optimization, several corrected C functions use empty GNU extended assembly (`asm volatile(\"\" ...)`) barriers or register constraints. These emit **no original machine instructions** but are compiler-specific. They do **not** mean verified matching with Nintendo CodeWarrior, original C++ signatures, or game rebuild.

## Matching round 3 — three more full-unit byte matches

A complete 50-function Clang ARMv5TE compilation and 1,528-byte ROM comparison
was rerun on 23 October 2026. Results: **20/50 byte-identical C functions,
448 matched bytes**, and 30 unmatched. Added:

- `arm9:0x0202815C` (12 bytes): unsigned-subtraction loop using Clang's
  `__builtin_usub_overflow` and an empty register constraint to preserve the
  correct ARM carry/borrow loop.
- `arm9:0x02028390` (8 bytes): ARM `CLZ` via a Clang intrinsic and
  `__builtin_assume(x != 0)` to suppress a compiler-generated zero branch.
  **C-level precondition is unproven; original machine code still handles zero,
  but source semantics are not fully established.**
- `overlay_032:0x0211DA50` (16 bytes): correct two-word field swap via
  fixed register constraints and an empty compiler barrier.

These are **isolated Clang byte matches only**. Nintendo CodeWarrior,
original C++ ownership, in-game safety and DS rebuild remain untested.
The standalone verification script enforces the new 20/50 threshold.

## Matching round 4 — three confirmed loop reconstructions

The user-owned EUR1 ROM extracted ARM9/overlay images were authenticated, and the **entire 50-function C translation unit** was compiled at Clang ARMv5TE `-O2` and byte-compared with the original source spans. The result is **23/50 Clang exact; 548/1,528 original instruction bytes identical; 27 nonmatching**. This pass adds:

- `arm9:0x020092CC`, 32 bytes: three-entry word initializer with signed loop condition
- `overlay_026:0x020EA81C`, 36 bytes: eight-entry zero initializer and final field reset
- `overlay_026:0x020F169C`, 32 bytes: five-entry fixed-point initializer (`0x00400000`)

These C implementations use GNU register binding and empty optimization barriers to suppress loop unrolling and reproduce original ARM instruction order; **not** portable CodeWarrior C++ and **not** integrated into the DS game. No original ROM or binary code is committed. See `MATCHING_ROUND4.md` for details.

## Matching round 5 — additional overlay-26 indirect-pointer loop

After matching the three direct-write loops, we recovered the control flow of overlay 26 `0x0211F1CC` (36 bytes), which visits three object pointers and writes one byte to each non-null object. A GNU empty inline-assembly input constraint ensures Clang loads each pointer *before* advancing its loop register. The full 50-function Clang ARMv5TE verifier reports **24/50 byte-exact** and **584/1,528 identical original bytes**, with **26 functions still provisional**. This was compared against locally extracted EUR Rev 1 ROM and verified by original per-function SHA-256. Nintendo CodeWarrior and DS game integration remain untested.
