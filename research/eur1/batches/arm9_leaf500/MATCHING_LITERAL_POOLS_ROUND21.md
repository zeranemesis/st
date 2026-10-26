# Spirit Tracks EUR Rev1 — round 21: exact instruction streams with one-word literal pools

**Date:** 25 October 2026. **Repository:** `zeranemesis/st` (draft PR #15).

## Discovery: 43 more exact ARM instruction spans, distinct from 54 strict full-section matches

The fifth-500 research manifest previously marked as byte-exact **only** the
functions whose entire standalone Clang `.text.<symbol>` ELF section had
the same byte size and SHA-256 as the original function code span.
That is still a useful *strict* metric: **54/500**.

The new `audit_literal_pools_round20.py` compiled the **500 actual
published C functions** with unchanged Clang ARMv5TE `-O2` flags,
then separately compared the leading **N bytes of ARM instructions**
with the original EUR1 function's **complete original code-span SHA-256**.

**43 additional previously strict-nonmatching functions have perfectly
identical original instruction bytes**, but Clang's ELF section contains
**one extra four-byte word**. For **all 43**, the audit decoded a real
ARM-mode PC-relative `LDR` within the exact instruction span, whose
computed target references that appended word; this corroborates that
the extra four bytes form a **compiler literal-pool constant** and not
another trailing instruction.

A function that compiled as 12 ARM instruction bytes plus a four-byte
constant is therefore **12/12 byte-exact for the code stream**, but still
**16 bytes versus 12 bytes** as a whole Clang section. The script
deliberately does **not** mark it `exact_original_machine_bytes` in the
existing strict field.

### Distinct, non-inflated metrics

| Measurement | Verified | Remaining |
| --- | ---: | ---: |
| Exact **full** standalone Clang ELF function section | **54** | 446 |
| Additional exact **original ARM instruction spans**, with extra referenced 4-byte literal in Clang | **43** | — |
| **Original ARM instruction spans confirmed exact** (two separate categories) | **97/500** | 403 |
| Full DS game build, original CodeWarrior or official `objdiff` verified | **0** | — |

The `manifest_fifth500.json` retains **54** under
`summary.standalone_clang_exact` and **446** under
`summary.standalone_clang_nonmatching`. It adds the secondary fields:

```json
"standalone_clang_exact_instruction_prefix_with_one_verified_literal": 43,
"standalone_clang_exact_original_instruction_spans_total": 97
```

Each of the 43 original function entries has a separate
`clang_instruction_prefix_status` field, **not** a changed strict
`clang_standalone_status` value. A fresh CI recompilation validates
all these statuses and checks that the reference SHA-256 and ARM PC
literal-load decoding still agree.

## All 43 independently validated functions

| Original module | Original address | Exact instruction bytes | Clang literal-pool trailer |
| --- | --- | ---: | ---: |
| ARM9 | `0x02003A54` | 12/12 | 4 bytes |
| ARM9 | `0x02003F58` | 24/24 | 4 bytes |
| ARM9 | `0x02031E58` | 12/12 | 4 bytes |
| Overlay 000 | `0x0205B5A8` | 16/16 | 4 bytes |
| Overlay 000 | `0x0208009C` | 20/20 | 4 bytes |
| Overlay 000 | `0x020A89C8` | 12/12 | 4 bytes |
| Overlay 009 | `0x020B6910` | 16/16 | 4 bytes |
| Overlay 015 | `0x020B73E8` | 16/16 | 4 bytes |
| Overlay 017 | `0x020BBAD4` | 16/16 | 4 bytes |
| Overlay 019 | `0x020CE870` | 16/16 | 4 bytes |
| Overlay 021 | `0x020F6640` | 16/16 | 4 bytes |
| Overlay 021 | `0x020FB81C` | 12/12 | 4 bytes |
| Overlay 022 | `0x020EAB98` | 12/12 | 4 bytes |
| Overlay 026 | `0x020DA588` | 24/24 | 4 bytes |
| Overlay 026 | `0x020E6CD4` | 16/16 | 4 bytes |
| Overlay 026 | `0x02102A44` | 12/12 | 4 bytes |
| Overlay 026 | `0x02108368` | 12/12 | 4 bytes |
| Overlay 026 | `0x02108378` | 12/12 | 4 bytes |
| Overlay 026 | `0x02117570` | 16/16 | 4 bytes |
| Overlay 026 | `0x021204C8` | 20/20 | 4 bytes |
| Overlay 026 | `0x021204E0` | 20/20 | 4 bytes |
| Overlay 026 | `0x021315C8` | 20/20 | 4 bytes |
| Overlay 026 | `0x02131714` | 20/20 | 4 bytes |
| Overlay 029 | `0x02147090` | 16/16 | 4 bytes |
| Overlay 030 | `0x021473A0` | 16/16 | 4 bytes |
| Overlay 030 | `0x0214C43C` | 16/16 | 4 bytes |
| Overlay 030 | `0x0214DDB0` | 16/16 | 4 bytes |
| Overlay 031 | `0x020F1534` | 20/20 | 4 bytes |
| Overlay 049 | `0x02134524` | 16/16 | 4 bytes |
| Overlay 058 | `0x02142A64` | 16/16 | 4 bytes |
| Overlay 058 | `0x0214A9F0` | 16/16 | 4 bytes |
| Overlay 058 | `0x0214AC98` | 16/16 | 4 bytes |
| Overlay 058 | `0x0214D7B4` | 16/16 | 4 bytes |
| Overlay 062 | `0x0215B494` | 16/16 | 4 bytes |
| Overlay 073 | `0x0215F7EC` | 16/16 | 4 bytes |
| Overlay 075 | `0x02155674` | 16/16 | 4 bytes |
| Overlay 084 | `0x02159DAC` | 16/16 | 4 bytes |
| Overlay 088 | `0x0216F18C` | 16/16 | 4 bytes |
| Overlay 088 | `0x02172798` | 16/16 | 4 bytes |
| Overlay 089 | `0x021680C8` | 20/20 | 4 bytes |
| Overlay 091 | `0x0216A4B0` | 16/16 | 4 bytes |
| Overlay 091 | `0x0216F1B4` | 16/16 | 4 bytes |
| Overlay 092 | `0x0216F5FC` | 16/16 | 4 bytes |

These are **existing original function addresses**: no new code
addresses or game function boundaries have been invented.

## How it works and reproduction

- Compile `arm9_leaf_500_part1.c` through `part5.c` with Clang
  `--target=armv5te-none-eabi -march=armv5te -marm -O2`.
- Collect all 500 emitted ELF function sections and match each to
  original EUR1 module/address and original instruction SHA-256.
- Preserve **54 whole-section byte matches** unchanged.
- Among the nonmatching sections, find those with extra trailing bytes
  for which the complete original instruction span equals the first
  `size_bytes` of Clang's section by full SHA-256.
- Decode all ARM instructions in that span and verify a PC-relative
  `LDR` specifically targets the **single appended 4-byte constant**.
  Do **not** infer the original ROM literal-pool value, matching game
  module data placement, source C++ class signature or linkage from that
  result.

```sh
python3 research/eur1/batches/arm9_leaf500/audit_literal_pools_round20.py
python3 research/eur1/batches/arm9_leaf500/verify_fifth500_romfree.py
```

Evidence:
- <https://github.com/zeranemesis/st/actions/runs/40192086820>
  (43 prefix-exact functions, 43 referenced one-word Clang literal pools,
  54 strict full-section exact).
- Source `research/eur1/batches/arm9_leaf500/audit_literal_pools_round20.py`.
- CI `.github/workflows/research-eur1-literal-pools.yml`.

**Limit:** The original EUR1 reference provides the complete *instruction*
SHA-256 but no per-function original literal-pool value/placement here.
The 43 functions are therefore best described as **exact ARM opcode spans
with Clang-appended literal data**, not verified complete object-file or
DS reconstruction matches. No CodeWarrior used, and no original ROM bytes
have been uploaded.

This is an evidence improvement complementary to
[MATCHING_ROUND20.md](MATCHING_ROUND20.md), which contains **two genuinely
new strict Clang full-section matches**, increasing that count from
52 to 54.
