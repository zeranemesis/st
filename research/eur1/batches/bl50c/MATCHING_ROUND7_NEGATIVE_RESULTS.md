# Matching round 7 — 20 remaining functions (24 October 2026)

This round **did not** produce further byte-identical functions. It is a
reproducible negative result, not a declaration that these 20 functions match.

## Verified baseline

- Nintendo DS game: **The Legend of Zelda: Spirit Tracks**, Europe Rev 1.
- Standalone compiler: **Clang 17 ARMv5TE**, `-marm -O2`.
- Existing research functions: **30/50 Clang byte-identical**, **848/1,528**
  reference instruction bytes matched. **20 functions are not matching**.
- All 50 were recompiled after this round and their per-function sections
  compared to SHA-1 authenticated ARM9/overlays and SHA-256 checked spans.
  **Regression verification: PASS; no matching count changed.**
- **569 independent C source replacements** explored in four candidate
  families, evaluated with **eight parallel compilation workers**.
  Of these, 541 compiled successfully and 28 did not.
- **Zero** candidate variants generated a new byte-identical function.
  Failed candidates were **not** merged into `reconstructed_50.c`.
- The eight workers are parallel compiler/test processes, **not autonomous
  AI coding agents**. No agent-dispatch capability was available here.

### Partition for independent future coding-agent work

A single function belongs to exactly one group.

| Group | Executable module | Target addresses |
|---|---|---|
| A — ARM9 core and OS | ARM9 | `0x0200371C`, `0x020131EC`, `0x02014704`, `0x0202694C`, `0x0202CE2C` |
| B — clamps and conditional masks | overlay 003, 026, 030 | `ov003:0x020B7E2C`, `ov026:0x020FC9C0`, `ov026:0x0211E0F0`, `ov030:0x0214D724`, `ov030:0x0214D744` |
| C — traversal and state logic | overlay 038, 070, 090, 092, 000 | `ov038:0x0211988C`, `ov070:0x0214B2A0`, `ov090:0x02170E18`, `ov092:0x0217A7E4`, `ov000:0x0207749C` |
| D — bit tests and memory routines | overlay 000 and ARM9 | `ov000:0x02072FF0`, `ov000:0x020816C4`, `ov000:0x020816FC`, `arm9:0x02028C4C`, `arm9:0x02028C60` |

## Closest cases and blockers

- `arm9:0x02014704`: best independent variant had **9/10** ARM
  instructions matching exactly; only `CMP r0,#0` and `MOV r3,#0` were
  emitted in the opposite order. **Not a full match**.
- `ov000:0x020816C4` and `0x020816FC`: generated **20-byte**
  versions with three instructions matching, but Clang selects `ANDS/MOVNE`
  instead of the original `TST/MOVEQ` instruction pair. **No match**.
- `ov000:0x02072FF0`: Clang uses an indexed address `ADD` followed
  by `STRH`, rather than one register-offset `STRH`.
- `ov090:0x02170E18`: prior near-match has the original function length,
  but Clang rewrites a signed comparison with an alternative immediate and
  branch condition. **No match**.
- `ov003:0x020B7E2C`: after reconstructing a readable clamp with a
  fallthrough else branch, Clang still schedules comparisons and registers
  differently from the original ARM. **No match**.
- In-memory allocator and low-level ARM helper functions likely require
  matching the target toolchain or suitable ARM-specific intrinsic handling,
  rather than merely more Clang `-O2` formulations.

## Next-pass acceptance criteria

1. Begin from the checked-in `bl50c/reconstructed_50.c` and
   `manifest_50.json`. Work in **isolated branches** per group.
2. Never insert original ARM machine-code bytes into the source to fake a
   C reconstruction. A short ARM ASM implementation is not equivalent to
   decompiling a function into C/C++.
3. For each function, preserve original behavior and expected ABI where
   it can be established; compile the **entire** 50-function C file.
4. Authenticate the owner's **local** EUR1 ROM-derived modules before
   comparing code. Never upload/publish ROMs or proprietary assets.
5. Mark `clang_byte_exact:true` only after exact whole-function ARM
   byte equality; run `verify_50.py` and update its count/byte thresholds.
6. **CodeWarrior `dsi/1.2p1`, game `objdiff`, source-translation-unit
   integration, and gameplay behavior remain untested**. Do not equate
   isolated Clang matching with official game decompilation completion.

## Exact reproduction of the existing results

```powershell
python research/eur1/batches/bl50c/verify_50.py --working-code YOUR_WORKING_CODE --overlays-csv YOUR_OVERLAYS_CSV
```

Expected baseline: `PASS: 30 Clang-exact and 20 nonmatching functions; 50 source bodies`.

No production DS `src/` files were modified and no original ROM or
machine-code dumps were committed as part of this round.
