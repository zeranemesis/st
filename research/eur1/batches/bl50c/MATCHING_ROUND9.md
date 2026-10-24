# Spirit Tracks EUR1 — Round 9 (24 October 2026)

This round **does not add 18 new game functions**: it supplies **18 alternative, readable
C interpretations of 18 of the existing 20 nonmatching functions** in the bl50c
research batch. The earlier reconstructed_50.c and manifest_50.json remain
unchanged. That preserves the established **30/50 Clang ARMv5TE byte matches,
848/1,528 original bytes**. The original Nintendo CodeWarrior game build is
not involved.

## Actual changes

- Added semantic_candidates_round9.c: 18 C candidates with ordinary control
  flow and typed loads/stores, avoiding the old artificial processor flag
  variables. The functions cover the ARM9 main module and overlays 000, 003,
  026, 030, 070, 090 and 092.
- Added test_semantic_round9.c: **11 host test groups** covering signature
  validation, paired fields, signed clamp, mode selection (including negative
  counts), history updates, bit limits, indexed loads/stores, word fill and
  copying. Run with Clang AddressSanitizer + UndefinedBehaviorSanitizer.
- Added verify_semantic_round9.py: compile each candidate to an ARMv5TE
  function section and compare the complete generated code's SHA-256 to the
  verified original instruction-span SHA-256 in manifest_50.json.
  This requires **no ROM**: the reference hashes are already recorded in
  the existing manifest. It does NOT validate original CodeWarrior matching
  or full Nintendo DS link-time behavior.

## Measurements (local Clang 17 ARMv5TE)

| Measurement | Result |
| --- | ---: |
| Candidate C functions | 18 |
| ARMv5TE compilation | 18/18 PASS |
| Clang original-span SHA-256 matches | **0/18** |
| Host semantic test groups (ASan + UBSan) | **11 PASS** |
| Remaining nonmatching functions in original batch | **20** |
| Original 50-function research baseline | **30/50**, unchanged |

The other two nonmatching functions not rewritten in this round are
arm9:0x0202694C (linked list removal) and overlay_038:0x0211988C
(list traversal/replacement), where the initial register-state descriptions
still need more evidence.

## Reproduce

From the repository root:

    python3 research/eur1/batches/bl50c/verify_semantic_round9.py --out build/eur1/semantic_candidates_round9.json

    clang -std=c11 -O1 -g -fsanitize=address,undefined -fno-omit-frame-pointer research/eur1/batches/bl50c/test_semantic_round9.c -o /tmp/st_round9_test
    /tmp/st_round9_test

Expected verifier output: PASS: 18 compiled candidates, 0/18 Clang SHA256-exact; 18 still nonmatching.

### Strict limits

The readable alternatives are **semantic hypotheses**, mainly extracted
from the earlier preliminary register-state translations, and should NOT be
substituted for production DS sources until call conventions, original memory
accesses, lifetime, and actual CodeWarrior instruction matching are checked.
Passing host tests does not show equivalence with the original executable.
No ROM, extracted binary code, console SDK, or game assets are committed.
