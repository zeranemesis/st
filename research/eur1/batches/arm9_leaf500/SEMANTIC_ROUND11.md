# Spirit Tracks EUR Rev 1 — semantic rewrite round 11

**Project:** The Legend of Zelda: Spirit Tracks (Nintendo DS), EUR Rev 1.
**Scope:** overlay 000, ten functions already in the fifth 500-function research
manifest. This adds **10 alternative, readable C candidate bodies**, not ten
new or completed decompiled game functions.

## C reconstructions

All candidates were recovered from the existing register-state source
in `arm9_leaf_500_part1.c` and are now separately expressed in typed
C without the artificial per-instruction ARM flag variables.

| Address | Reconstructed behavior | Original ARM bytes | Standalone Clang bytes | Byte match |
|---|---|---:|---:|---|
| `0x02057D6C` | Nonzero base offset plus 88-byte index | 24 | 24 | No |
| `0x020590E4` | Initialize object words including a fixed vtable value | 32 | 36 | No |
| `0x0205B090` | Arithmetic shifting and rounding | 28 | 28 | No |
| `0x0205C5A0` | Indexed byte shuffle | 24 | 20 | No |
| `0x02060738` | Signed byte counter and wrapping | 36 | 36 | No |
| `0x02060804` | Mixed-width reset with sentinel values | 40 | 44 | No |
| `0x02062E44` | Two signed halfwords copied from nested data | 24 | 24 | No |
| `0x02065460` | Two fields zero test | 28 | 32 | No |
| `0x0206547C` | Signed comparisons of two products and counters | 48 | 60 | No |
| `0x0206590C` | Initialize structure members and metadata | 36 | 36 | No |

No new exact hashes were confirmed. **This does not change the fifth
500-function research batch's established result: 33/500 Clang matches,
467 provisional functions.** It also does not change the unrelated
`bl50c` batch's 30/50.

## Evidence / reproducibility

Source: `semantic_refactors_round11.c`

Standalone compiler/hash audit: `verify_semantic_round11.py`. Compiles the
ten candidates with Clang ARMv5TE `-O2`, extracts the individual function
sections, and compares their **entire** compiled SHA-256 with the owner
ROM-backed reference hashes in `manifest_fifth500.json`.

Host semantic check: `test_semantic_round11.c`. Nine function groups
tested using AddressSanitizer and UndefinedBehaviorSanitizer. The tenth
function (`0x02062E44`) dereferences a stored 32-bit Nintendo DS pointer;
this is **not safe to simulate using ordinary 64-bit host pointers**. Its
code generation is audited by the ARM cross-compiler but its host behavior
was not executed.

From repository root on Linux:

```sh
python3 research/eur1/batches/arm9_leaf500/verify_semantic_round11.py --out /tmp/st-round11-hash-results.json
clang -std=c11 -O1 -g -fsanitize=address,undefined -fno-omit-frame-pointer -Wall -Wextra -Werror research/eur1/batches/arm9_leaf500/test_semantic_round11.c -o /tmp/st-round11-host
/tmp/st-round11-host
```

## Strict limitations

- These new candidates are research hypotheses, not proven semantic matches
  of the retail ROM.
- SHA-256 comparison verifies machine-code identity only when it matches;
  none of these candidates match as written.
- No game asset, ROM, original ARM instructions or Nintendo proprietary SDK
  executable is included.
- No CodeWarrior `dsi/1.2p1` matching, `objdiff`, DS executable rebuild,
  or native PC port work is claimed.
- The original `arm9_leaf_500_part1.c` source, game C++ build and main
  branch remain unchanged.
