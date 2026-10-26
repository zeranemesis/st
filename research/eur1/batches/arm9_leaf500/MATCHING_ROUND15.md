# The Legend of Zelda: Spirit Tracks (EUR Rev1) — matching round 15

**Date:** 25 October 2026. **Repository:** `zeranemesis/st`, PR #15 research branch.

## Result: +14 standalone Clang ARMv5TE byte-exact functions

The user requested **10 additional matches without CodeWarrior**. This round
discovered and promoted **14** actual new matches, exceeding that target.

The script `search_simple_round15.py` extracted existing simple leaf-like
ARM register-state transcriptions from the five original C research shards,
generated **848 alternative typed C implementations for 106 previously
nonmatching original addresses**, and compiled them with the same Clang
ARMv5TE `-O2` settings as the established verification suite. It found
**14 previously nonmatching original function addresses** whose entire
generated machine-code span has the **same size and full SHA-256** as the
owner-ROM-derived original ARM function.

No compiler settings were changed to manufacture a match. No original
game instruction bytes, ROM dumps or proprietary compiler are committed.

## Fourteen functions promoted to the real research shards

| Module | Address | Original ARM size | Original research shard |
| --- | --- | ---: | --- |
| Overlay 000 | `0x0207E7A4` | 40 bytes | `arm9_leaf_500_part1.c` |
| Overlay 000 | `0x020A9254` | 28 bytes | `arm9_leaf_500_part2.c` |
| Overlay 019 | `0x020CC5EC` | 20 bytes | `arm9_leaf_500_part2.c` |
| Overlay 021 | `0x020F87BC` | 32 bytes | `arm9_leaf_500_part2.c` |
| Overlay 031 | `0x020DB6D4` | 32 bytes | `arm9_leaf_500_part3.c` |
| Overlay 031 | `0x020E0A8C` | 32 bytes | `arm9_leaf_500_part3.c` |
| Overlay 032 | `0x0211CD50` | 56 bytes | `arm9_leaf_500_part3.c` |
| Overlay 075 | `0x0215D858` | 40 bytes | `arm9_leaf_500_part4.c` |
| Overlay 088 | `0x02172A08` | 24 bytes | `arm9_leaf_500_part4.c` |
| Overlay 105 | `0x02187588` | 64 bytes | `arm9_leaf_500_part2.c` |
| Overlay 107 | `0x02184E98` | 24 bytes | `arm9_leaf_500_part2.c` |
| Main ARM9 | `0x02001F30` | 24 bytes | `arm9_leaf_500_part5.c` |
| Main ARM9 | `0x020271D0` | 40 bytes | `arm9_leaf_500_part5.c` |
| Main ARM9 | `0x020273C8` | 24 bytes | `arm9_leaf_500_part5.c` |
| **Total** | **14 distinct existing original addresses** | **480 bytes** | **5 shards** |

The 14 accepted candidates all use the first `v0` source variant from the
search (`void` function, `volatile uint8_t *object` argument and volatile
typed memory access), keeping the original register-derived store order.
The temporary search suffix `_v0` is dropped on promotion; the original
research symbol is preserved. These are C reconstructions, **not original
C++ method declarations**.

## Mandatory full verification

After changing each actual source shard, the original `manifest_fifth500.json`
was updated to mark **only these 14 addresses** as newly byte-exact. A
separate ROM-free compiler audit `verify_fifth500_romfree.py` then compiled
**all 500 published C functions across five shards**, required their emitted
sections to match the 500 original symbol names, and checked each complete
machine-code SHA-256 against the previously authenticated EUR Rev1 reference
hash. It also required every manifest matching status to agree with the
new compilation.

| Result | Before | After |
| --- | ---: | ---: |
| Exact full Clang ARM SHA-256 matches | 34/500 | **48/500** |
| Nonmatching Clang ARM spans | 466/500 | **452/500** |
| Distinct source addresses in this fifth research batch | 500 | 500 |
| Additional matching functions in this pass | — | **14** |

The successful verification run also retained all 26 semantic regression
groups from round 14. GitHub Actions (the **48/500** recheck):

https://github.com/zeranemesis/st/actions/runs/40175714473

Original automated search discovery:

https://github.com/zeranemesis/st/actions/runs/40175464181

### Reproduce (no CodeWarrior and no ROM required)

From the repository root with Python 3 and an ARMv5TE-capable Clang:

```sh
python3 research/eur1/batches/arm9_leaf500/verify_fifth500_romfree.py
python3 research/eur1/batches/arm9_leaf500/verify_semantic_round14.py
```

Search the remaining not-yet-matching functions:

```sh
python3 research/eur1/batches/arm9_leaf500/search_simple_round15.py
```

The search script uses the current manifest to exclude functions already
promoted, so it should not count these same 14 addresses as discoveries
again.

## Limits

- **Full byte-for-byte matching is confirmed with standalone Clang ARMv5TE
  only.** This is not a Nintendo CodeWarrior compiler match.
- The original C++ class ownership, DS translation-unit assembly,
  `objdiff`, rebuild, emulator and native PC port are **not validated**.
- This did not invent 14 new original functions: all 14 had existed in the
  fifth batch as low-level research transcriptions. The achievement is
  replacing them with readable C bodies which actually reproduce the
  original instructions under this compiler configuration.
- Source-level function signatures are still provisional, especially
  `void` where the original ARM code may simply preserve `r0`.
- The `main` branch is unchanged; commits are in draft PR #15.
