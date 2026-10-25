# Spirit Tracks EUR1 — fifth 500-function research batch: next matching passes

**2026-10-23.** This document describes the reproducible standalone compilation
status, not normal game C++ source/objdiff integration.

> **Mise à jour du 25 octobre 2026 :** le matching **Clang ARMv5TE isolé est à 48/500**, contre 33/500 lors de la rédaction initiale ci-dessous. Il reste **452 corps nonmatching**. Voir [le rapport de la passe 15](MATCHING_ROUND15.md). La table détaillée 33/138/329 ci-dessous est conservée comme **historique du 23 octobre**, pas comme état courant.

## Confirmed baseline (local Clang ARMv5TE)

All 500 distinct original BL-target C transcriptions recompile with Clang ARMv5TE
at `-O2` and their original ROM code spans have independently verified SHA-256
hashes. Of these:

| Status | Count | Description |
| --- | ---: | --- |
| `exact_clang_smoke` | **33** | Full instruction bytes identical to original |
| `different_instructions` | **138** | Compiled byte count agrees, instructions differ |
| `different_size` | **329** | Source emits different code length |
| **Total** | **500** | 15,092 original instruction bytes across 74 modules |

The 467 C implementations without byte matching require *real algorithm and
control-flow verification*. There is no evidence that they are semantically
equivalent simply because they compile. None have been integrated in official
Nintendo DS source files. **Original CodeWarrior results for this fifth batch
are not yet available** until the owner runs the Windows test.

## Test the original CodeWarrior compiler on Windows

From the project checkout at `C:\st`:

```powershell
cd C:\st
git pull --ff-only origin main
python research/eur1/batches/arm9_leaf500/verify_codewarrior_fifth500.py
```

This script compiles each of the 500 functions through the project's existing
`tools/mwccarm/dsi/1.2p1/mwccarm.exe` and `tools/sjiswrap.exe`, in temporary
batches of 25. Failed batches are automatically split down to individual
functions. The script reads the ARM ELF32 CodeWarrior symbol-table ranges,
accounts for relocations, and hashes exact machine-code bytes. It does not
require the original ROM and does not write to game source files.

Output: `C:\st\build\eur1\codewarrior_fifth500.json`.

If memory or compilation becomes problematic, try `--batch-size 5`.

The script can also reproduce the Clang baseline on a development computer:

```bash
python research/eur1/batches/arm9_leaf500/verify_codewarrior_fifth500.py --backend clang
```

A Clang result is **not** a CodeWarrior result.

## Prioritized next-matching shortlist

These entries have exactly the right byte count under Clang but differ in
instructions. They also have multiple direct BL references; repairing them
may contribute more than revisiting unreferenced returns.

| Module | Address | Original size | Direct BL references |
| --- | --- | ---: | ---: |
| Overlay 26 | `0x020FA8E0` | 28 | 71 |
| ARM9 main | `0x0201E8D4` | 36 | 50 |
| Overlay 0 | `0x0208A7F0` | 40 | 26 |
| Overlay 0 | `0x0206678C` | 36 | 13 |
| Overlay 20 | `0x020C9430` | 24 | 12 |
| Overlay 92 | `0x0217A278` | 16 | 11 |
| Overlay 0 | `0x020669B4` | 24 | 10 |
| Overlay 31 | `0x020D8840` | 24 | 10 |
| Overlay 71 | `0x021530DC` | 36 | 10 |
| ARM9 main | `0x0202CF08` | 40 | 9 |

The BL count indicates call-site priority, **not** source-function size or
importance to gameplay. After the CodeWarrior report, re-rank by actual
original-compiler matching status and confirmed owning C++ source unit.

## Human-readable reverse-engineering proposals

`semantic_refactors_3.c` contains three C implementations inferred manually
from ARM instructions, with field names and types explicitly **provisional**:

1. `ov000 0x02054548`: adds a node at the head of a doubly linked list
   (head at +0, count at +4, tail at +8), original 64 bytes.
2. `ov000 0x02058FC4`: copies a three-word payload and advances a pointer
   cursor from context+128, original 52 bytes.
3. `ov000 0x02067BB4`: conditionally loads a 32-bit field from object+12
   or object+16, original 16 bytes.

All three candidates compile for ARMv5TE, but they are **not CodeWarrior- or
Clang-byte-matched** as complete original functions. Their C++ owner/type
signatures, observable register side effects, pointer aliases, and runtime
behavior must be independently checked before substituting in game code.
They are separate research functions with distinct names, preventing any
accidental modification of the real DS build.

## Matching follow-up: seven Clang-exact typed C functions

[The seven-function matching audit](MATCHING_REWRITES_7.md) describes typed C fixes for original overlays 0, 26, 66, 89 and 91. They are already applied to the fifth-batch source and manifest; the full Clang test reports **33/500 exact**. They are **not** counted as CodeWarrior-exact or Nintendo DS C++ build-integrated until separately verified.
