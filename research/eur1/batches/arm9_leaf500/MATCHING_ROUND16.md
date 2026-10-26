# Spirit Tracks EUR1 — round 16/17 (25 October 2026)

This round continues **standalone Clang ARMv5TE matching without CodeWarrior**.
The work is on `zeranemesis/st` PR #15 research branch, not `main`.

## Four new exact machine-code matches (48 → 52/500)

The new search `search_conditional_round16.py` found four functions
which previously compiled but did **not** match the original ARM code.
It compiled **400 variants from 144 original C function transcriptions**,
replacing synthetic N/Z/C/V flag calculations with captured comparisons
and testing integer versus typed pointer memory access.

These four now have readable C implementations in the **original fifth-batch
research shards** and are marked exact in `manifest_fifth500.json`.

| Module | Function address | ARM size | New C style | Source shard |
| --- | --- | ---: | --- | --- |
| ARM9 main | `0x02002D88` | 20 B | Integer register and volatile byte store with captured comparison | `part5.c` |
| Overlay 000 | `0x020A61D0` | 28 B | Integer pointer, conditional 32-bit store and increment | `part1.c` |
| Overlay 019 | `0x020CC89C` | 24 B | Typed object pointer, changed-value comparison and conditional field writes | `part2.c` |
| Overlay 071 | `0x0215F21C` | 28 B | Integer pointer, conditional 32-bit store and increment | `part4.c` |
| **Total** | **4 functions** | **100 B** | **Complete SHA-256 code spans match** | |

Search discovery log: https://github.com/zeranemesis/st/actions/runs/40179496431

The four variants were reproduced from the exact source template emitted
by `search_conditional_round16.py`, with their temporary variant suffixes
removed. A separate full-batch verification then recompiled the **real five
source shards**, not the candidate search files, and compared every complete
function section with the original hashes.

Verification: https://github.com/zeranemesis/st/actions/runs/40179715404

- **500/500** research functions compile as ARMv5TE via Clang.
- **52/500** complete Clang machine-code SHA-256 exact (was 48/500).
- **448/500** still differ (was 452/500).
- **26/26** existing round-14 host regression groups still pass.

### Further exploration (honest negative results)

After these four were promoted, no **new** matches were found in:

- `search_conditional_round16.py`: 380 remaining candidate variants,
  representing 140 eligible original functions.
- `search_grouped_round16.py`: 1,140 variants of the same 140 functions,
  combining repeated guards and certain if/else pairs.
- `search_straight_round17.py`: 852 variants of 242 unbranched functions,
  varying pointer types and access qualifiers.
- `search_bit_tests_round17.py`: 232 variants of 29 bit-mask/TST routines.

All these searches compiled and completed successfully on:
https://github.com/zeranemesis/st/actions/runs/40180045748

The repeated candidate investigations are intentionally **not** counted as
matching or decompiled C++ game functions.

## Reproduce without Nintendo tooling

With `clang` supporting ARMv5TE and Python 3, at repository root:

```sh
python3 research/eur1/batches/arm9_leaf500/verify_fifth500_romfree.py
python3 research/eur1/batches/arm9_leaf500/search_conditional_round16.py
python3 research/eur1/batches/arm9_leaf500/search_grouped_round16.py
python3 research/eur1/batches/arm9_leaf500/search_straight_round17.py
python3 research/eur1/batches/arm9_leaf500/search_bit_tests_round17.py
```

Each script only reads existing hashes extracted from the owner's original
EUR1 executable; no copyrighted original executable bytes need to be
committed.

**Important limitations:** The matches are with **standalone Clang
ARMv5TE -O2**, not the Nintendo compiler. The signatures/types and
whole-program behavior remain provisional; there was no original game
translation-unit `objdiff`, full DS build, emulator validation or native
PC port integration in this pass. The other independent `bl50c` batch
remains at **30/50** Clang standalone matches.
