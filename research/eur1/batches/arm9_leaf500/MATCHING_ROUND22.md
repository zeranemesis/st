# Spirit Tracks EUR Rev1 — round 22 (25 October 2026)

**Branch:** `decomp/eur1-100-new-bl-reconstructions-20261023b` (draft PR #15)

**Goal:** Continue binary matching without Nintendo CodeWarrior, keeping
original ARM instruction SHA-256 comparisons distinguishable from complete
Clang ELF section comparisons.

## +2 new original ARM instruction matches

The new `search_literal_candidates_round22.py` reused seven families of
C source reconstructions to compile **6,074 candidate functions** for
**366 previously nonmatching original functions**. Each generated ARM
function was evaluated against the *whole original EUR Rev1 instruction
span SHA-256*, with the further requirement that a four-byte section
trailer is targeted by a decoded ARM PC-relative `LDR` in the exact code.

Two **new original addresses** met all the tests and were then promoted
to readable C in the fifth-batch research source shard
`arm9_leaf_500_part2.c`.

| Module | Original function address | Identical original ARM instructions | Extra Clang section data | Reconstruction |
| --- | --- | ---: | ---: | --- |
| Overlay 020 | `0x020D3780` | **32/32 bytes** | 4-byte referenced PC-relative literal | C writes five volatile bytes at constant global address `0x020E9868` |
| Overlay 021 | `0x02106B1C` | **24/24 bytes** | 4-byte referenced PC-relative literal | C reads two volatile words from `0x020431B8`, copies to object fields `+44` and `+48`, returns original pointer |

Both are **existing ROM function addresses** with previously provisional
ARM register-state translations, not newly found original functions.

The second C function was also independently compiled with and without
`return r0` using the same ARMv5TE Clang flags. Both emitted **exactly
the same ARM instructions and original SHA-256**, allowing its readable C
signature to preserve the original input-register return behavior.

### Evidence, unchanged flags

- Candidate discovery PASS (6,074 Clang ARM variants, two new original
  instruction matches): https://github.com/zeranemesis/st/actions/runs/40205984182
- Complete fifth-500 recompile and new PC-relative `LDR` literal
  classification PASS: https://github.com/zeranemesis/st/actions/runs/40206142219
- Full research Clang compilation / regression workflow PASS:
  https://github.com/zeranemesis/st/actions/runs/40206146621

## Matching categories (not interchangeable)

| Metric | Before | After |
| --- | ---: | ---: |
| Strict full standalone Clang ELF sections byte-exact | 54/500 | **54/500** |
| Additional exact original ARM instruction spans with a referenced one-word Clang literal | 43 | **45** |
| Exact original ARM instruction spans across both categories | 97/500 | **99/500** |
| Functions without evidence of exact original instruction spans | 403 | **401** |
| Full-section nonmatches (including functions with matching opcode prefixes) | 446 | **446** |

The manifest retains the strict
`clang_standalone_status=compiles_but_machine_bytes_differ`
classification for both promoted functions because their complete Clang
ELF sections contain an **extra 4-byte literal**. Their independent
`clang_instruction_prefix_status` indicates precisely the verified
original opcode-span match. The 500-function verifier checks that **all
54 strict matches are preserved**, while the literal-pool verifier
recompiles all 500 and requires **45 validated referenced pool trailers**.

### Reproduce (no ROM and no CodeWarrior)

```sh
python3 research/eur1/batches/arm9_leaf500/verify_fifth500_romfree.py
python3 research/eur1/batches/arm9_leaf500/audit_literal_pools_round20.py
python3 research/eur1/batches/arm9_leaf500/search_literal_candidates_round22.py
```

The last search **skips already recognized opcode matches**, so after
promotion it will not rediscover these same two addresses.

**Not established:** original Nintendo compiler matching, literal-pool
value/placement in the linked original game module, original game C++
translation-unit matching, gameplay/emulator validation or a PC port.
This pass proves exactly the stated ARM opcode-span SHA-256 equality with
a locally referenced Clang literal trailer, nothing broader.
