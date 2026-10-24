# Spirit Tracks EUR1 — matching / semantic round 10 (24 October 2026)

The two remaining bl50c functions now have explicit, typed, independent
C candidates. This brings **candidate-source coverage to 20/20 of the
previously nonmatching functions**. It does NOT turn these functions into
Nintendo DS matching or finished decompilation.

## Two typed implementations (new candidate source, not new game functions)

| Module | ARM9 address | Behavior interpreted from existing register-state trace | Original size | New Clang size | Byte exact |
| --- | --- | --- | ---: | ---: | --- |
| arm9 | `0x0202694C` | Pop head of doubly linked list, repair next.prev or clear tail | 48 | 44 | NO |
| overlay_038 | `0x0211988C` | Walk list rooted at `0x021215C4`, splice matching target, return successor if found / target if absent | 52 | 60 | NO |

Source: `semantic_candidates_round10.c`. Pointer layouts are asserted
at compilation time on 32-bit ARM (list head/tail +0/+4; node next/prev +16/+20;
chain next +660). The second candidate has a test-only seam that accepts
an explicit head slot, so host tests do not need to map the original DS address.

Nine host tests include empty, singleton and multi-node doubly linked lists,
unlinking at the chain head/middle/tail, and a missing target.

## Commands

Run from the repository root:

    clang --target=armv5te-none-eabi -march=armv5te -marm -O2 -ffreestanding -fomit-frame-pointer -ffunction-sections -std=c11 -c research/eur1/batches/bl50c/semantic_candidates_round10.c -o /tmp/st-round10-arm.o
    clang -std=c11 -O1 -g -fsanitize=address,undefined -fno-omit-frame-pointer -Wall -Wextra -Werror research/eur1/batches/bl50c/test_semantic_round10.c -o /tmp/st-round10-test
    /tmp/st-round10-test
    python3 research/eur1/batches/bl50c/verify_semantic_round10.py --out /tmp/st-round10-matching.json

The Python verifier recompiles both research source files from rounds 9 and 10,
ensures they cover **all 20 unique nonmatching manifest symbols exactly once**,
and checks complete Clang-generated machine-code SHA-256 against each original
manifest span. It requires no ROM file because the original game-image hashes
are already in the manifest.

### Scope and remaining work

- Locally verified Clang 17 ARMv5TE compile of the two candidates and 9
  sanitizer host cases: PASS. New byte-exact matches: **0/2**.
- The prior bl50c baseline remains **30/50 standalone Clang matches,
  848/1,528 original bytes**; **20/50 remain nonmatching**.
- Host semantic tests check explicit scenarios only, not full equivalence.
- The original Nintendo CodeWarrior dsi/1.2p1 compiler, official game
  translation units, objdiff, full ROM rebuild and PC port remain unverified.
- No ROM, Nintendo assets, or original machine-code byte strings are published.

Next matching work should focus on actual CodeWarrior compilation and C++
ownership/signatures; varying thousands of Clang snippets without fixing
the compiler/ABI discrepancy is unlikely to improve real game integration.
