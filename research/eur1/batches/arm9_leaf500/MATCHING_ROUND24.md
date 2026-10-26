# Spirit Tracks (EUR Rev1) — Round 24: +3 Clang strict ARM matches

**26 October 2026.** Research branch `decomp/eur1-100-new-bl-reconstructions-20261023b`, draft PR #15.

## Result: 147 → 150/500 exact original ARM instruction spans

The new `search_conditional_barriers_round24.py` compiled **43,460** C variants for **353 previously unmatched original ARM functions**, combining single-comparison/grouped conditional reconstructions with compiler-only empty register barriers. Candidate code was hashed against the **entire original EUR1 instruction span** using the owner-ROM-reference SHA256 digest in `manifest_fifth500.json`. A literal-pool match would also require a correctly decoded ARM PC-relative `LDR` targeting exactly one additional trailing four-byte word.

Exactly **three original functions** matched the **entire Clang ARMv5TE -O2 ELF function section**, without an extra trailing pool:

| Original EUR1 address | Module | Strict Clang code match | Selected matching source |
| --- | --- | ---: | --- |
| `0x02058FC4` | Overlay 000 | **52/52 bytes** | grouped single-`CMP` reconstruction, volatile loads/stores, empty barrier on intermediate `r3` |
| `0x021687BC` | Overlay 090 | **24/24 bytes** | original signed halfword read and comparison, empty barriers after `r0` and `r1` updates |
| `0x02168B54` | Overlay 092 | **20/20 bytes** | grouped signed comparison, empty barrier after `r0 += 0x100` |

**96 original ARM machine-code bytes** across the three already known function addresses are now strictly reproduced. The previous C register simulations have been **replaced by their matching source formulations** in `arm9_leaf_500_part1.c` and `arm9_leaf_500_part5.c`. These are real source edits, not hypothetical candidates.

The matching sources use `__asm__ __volatile__("" : "+r"(rX))`, an **empty compiler-only barrier that emits no instructions** but constrains LLVM's optimizations and ARM register allocation. This is a compiler extension, **not pure ISO C**. Original C++ function signatures, semantics, memory ownership and original compiler settings are not established.

## Independently verified categories

| Measurement within fifth batch | Before | After |
| --- | ---: | ---: |
| **Strict full Clang ELF function section SHA256 matches** | 77 | **80** |
| Additional **exact original instruction spans**, separate 4-byte referenced Clang literal | 70 | **70** |
| **Total exact original ARM instruction spans** | 147 | **150/500** |
| Functions with no matching original instruction stream | 353 | **350** |
| Whole Clang sections not byte-for-byte exact | 423 | **420** |

In the remaining **420 whole-section nonmatches**, **70** are already matching code spans with separately referenced literal-pool data, and **350** lack an exact opcode match. The separate classification prevents inflation of the strict whole-section count.

Every already promoted **80** strict match and **70** PC-relative literal-prefix match is cross-checked against the exact SHA256 of the entire original code span. The full 500-function source batch still compiles with Clang, and existing 26 semantic regression groups remain green.

## Search reproducibility and evidence

- Candidate search GitHub Actions **PASS**, 43,460 variants, three strict matches: https://github.com/zeranemesis/st/actions/runs/40285467601
- Full independent C recompilation/sha validation **PASS** — 500 functions, 80 exact and the 26 semantic regression groups: https://github.com/zeranemesis/st/actions/runs/40285865418
- Full original instruction/pool validation of the complete fifth batch: `audit_literal_pools_round20.py` and `.github/workflows/research-eur1-literal-pools.yml`.

```sh
python3 research/eur1/batches/arm9_leaf500/search_conditional_barriers_round24.py
python3 research/eur1/batches/arm9_leaf500/verify_fifth500_romfree.py
python3 research/eur1/batches/arm9_leaf500/audit_literal_pools_round20.py
```

The read-only search compiles in **2,000-variant batches** to avoid ELF32 limits on section count. Initial CI feedback revealed a bug in the optional memory-clobber insertion. It was corrected to only modify assembly barrier statements. An additional runner failure from generating too many ELF sections into one object was fixed by independent chunked object compilation. Only the successful complete run is counted.

**Not claimed:** original Nintendo CodeWarrior match, actual game object `objdiff`, native game runtime correctness, full Nintendo DS build, or a working PC port. These numbers describe only this distinct 500-function ROM-backed research batch.
