# Spirit Tracks EUR Rev1 — round 26–28: search results and opcode-first ranking

**Date:** 26 October 2026. **Branch:** `decomp/eur1-100-new-bl-reconstructions-20261023b`, PR #15 (draft).

## Result: 28,430 candidate C variants compiled, 0 new exact matches

Three **new, reproducible, ROM-free and CodeWarrior-free** matching
searches were added to GitHub and run on GitHub Actions. Unlike the
earlier work, these source variants **did not yield any newly matching
original ARM instruction streams**:

| Search | New script | C variants compiled | Distinct original candidates scanned within search | New exact ARM spans |
| --- | --- | ---: | ---: | ---: |
| 26: independently volatile single/pair/triple memory accesses, optional compiler memory barrier | `search_selective_volatile_round26.py` | 25,548 | 329 | **0** |
| 27: multiply/accumulate operand reorder, split expressions and stride shifts | `search_multiply_round27.py` | 554 | 21 | **0** |
| 28: flatten terminal ARM CMP/TST guarded constant selections into Boolean C | `search_boolean_round28.py` | 2,328 | 66 | **0** |
| **Total C variants tested** | | **28,430** | Overlapping groups | **0** |

**Do not add these variants to the original research C shards or
change the SHA256 match counter.** The baseline remains **82 strictly
exact full Clang ELF function sections** and **70 additional original
instruction streams exact with an extra PC-relative literal in Clang**,
i.e. **152/500 original ARM instruction streams matched**.

Evidence:
- [Round26 search CI — PASS](https://github.com/zeranemesis/st/actions/runs/40325965104).
- [Round27 search CI — PASS](https://github.com/zeranemesis/st/actions/runs/40326310002).
- [Round28 search CI — PASS](https://github.com/zeranemesis/st/actions/runs/40326701121).

These are **search progress / negative results**; they do not establish
gameplay equivalence, original C++ structure, a Nintendo compiler
match, or a playable PC port.

## Important diagnostic improvement: count opcode matches separately from ELF section length

The existing `rank_mismatches_round18.py` originally ranked all **418
not-entirely-exact Clang sections**, including **70 functions whose
entire original ARM instruction stream was already byte-exact**, but
which Clang emitted with an additional four-byte literal-pool word.

The ranker now **independently decodes a PC-relative ARM LDR**, confirms
its exact target is the appended four-byte constant, hashes the full
original ARM instruction span and cross-checks the manifest annotation.
That provides separate, mechanically verified result fields:

```json
{
  "compiled_functions": 500,
  "exact": 82,
  "not_exact": 418,
  "prefix_opcode_exact": 70,
  "opcode_unmatched": 348,
  "original_opcode_exact_total": 152,
  "same_size_but_different_code": 103,
  "different_size": 315
}
```

The 348 genuinely unmatched instruction streams break down into **103
Clang sections of the same size but different instructions** and **245
of a different size**. The other **70 of the 315 different-size Clang
sections are already opcode-exact**, differing only by a verified
Clang trailing literal.

New `top_opcode_unmatched` and `all_opcode_unmatched` report keys
**exclude those 70 already matched instructions**. The old
`all_nonmatching` key remains for backward compatibility with other
research workflows. A new GitHub CI assertion verifies
**82 + 70 + 348 = 500** and confirms the original reference checksums
are still honored.

## Highest-priority still unmatched functions

These functions retain **the same instruction-stream byte length under
Clang as the original**, but are *not* SHA256 exact. They are ranked by
the number of known in-module original-game branch-and-link references,
a heuristic for relevance, **not a claim of near-match**:

| Original function | Original/Clang code size | Original BL references |
| --- | ---: | ---: |
| `st_ov026_020FA8E0` | 28/28 B | 71 |
| `st_ov000_0208A7F0` | 40/40 B | 26 |
| `st_ov000_0206678C` | 36/36 B | 13 |
| `st_ov020_020C9430` | 24/24 B | 12 |
| `st_ov000_020669B4` | 24/24 B | 10 |
| `st_ov031_020D8840` | 24/24 B | 10 |
| `st_ov071_021530DC` | 36/36 B | 10 |
| `st_arm9_0202CF08` | 40/40 B | 9 |
| `st_ov026_0210C158` | 20/20 B | 8 |

The **next useful step** is to compare **individual original ARM
instructions vs generated Clang instructions**, starting with high-use
same-size candidates, rather than continuing tens of thousands of
random C edits. The ranker already supports optional **locally held**
decompressed EUR1 modules with SHA1/SHA256 authentication:

```powershell
cd C:\st
python research/eur1/batches/arm9_leaf500/rank_mismatches_round18.py --limit 30
```

For exact opcode difference diagnostics, the same script accepts
`--working-code C:\path\to\your\decompressed\eur1`,
keeping original game binary bytes **only on the owner's local PC**;
the repo does not contain or request Nintendo ROM bytes.

**Nothing in this report increases the confirmed 152/500 count.**
