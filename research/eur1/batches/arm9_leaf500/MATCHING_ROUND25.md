# The Legend of Zelda: Spirit Tracks EUR Rev1 — Round 25 (26 October 2026)

## Two more byte-identical ARM sections, independently compiled

On draft PR #15, `search_sparse_barriers_round25.py` searched **13,924 Clang ARMv5TE -O2 C variants** for **128 previously opcode-nonmatching existing original game function addresses**. It explores nonadjacent compiler-only register barrier pairs and triples, in contrast to round23's single barriers and adjacent pairs.

Exactly **two source variants matched the *entire* original machine-code section SHA256**, without Clang trailing literal-pool data:

| Module | Address | Original ARM code match | Matching strategy |
| --- | --- | ---: | --- |
| Overlay 000 | `0x02072D08` | **36/36 bytes** | two nonadjacent barriers on loaded `r0` and `r1`; volatile halfword/word accesses |
| Overlay 080 | `0x0215A7AC` | **48/48 bytes** | three barriers on intermediate `r3`, `r2`, `r0`; volatile word accesses |

Both use **`uint32_t` signatures with `return r0`**, copied from the exact matching candidate evidence, and the original signed halfword and 32-bit memory operations remain visible in the C. The **empty `__asm__ __volatile__("" : "+r"(reg))` emits no ARM instructions**, but affects LLVM's register dependencies and optimization decisions. This is a **compiler-specific C extension**, not pure ISO C. The `uint32_t` signature still remains provisional and is not proof of the game's original C++ function type.

**Both actual C implementations are now in the published fifth-batch source shards**, replacing their old ARM register-state simulation bodies:

- `research/eur1/batches/arm9_leaf500/arm9_leaf_500_part1.c`
- `research/eur1/batches/arm9_leaf500/arm9_leaf_500_part4.c`

Their exact SHA256 machine-code statuses have been entered into `manifest_fifth500.json`, and the existing 500-function full recompile and instruction-prefix regressions have been updated.

### Matching categories, measured over this 500-function research set

| Measurement | Previous | Round25 |
| --- | ---: | ---: |
| Strict byte-identical Clang ARM ELF function sections | 80/500 | **82/500** |
| Additional original ARM instruction spans exact, but Clang has a referenced 4-byte literal | 70/500 | **70/500** |
| **Total original ARM instruction streams whose entire SHA256 matches** | **150/500** | **152/500** |
| Original instruction streams still nonmatching | 350 | **348** |
| Full Clang ELF section nonmatches (including the 70 code-only literal cases) | 420 | **418** |

This pass additionally matches **84 original ARM machine-code bytes**, not 2 newly discovered game function addresses: both were previously recorded candidate function boundaries.

### Search and validation

- [Round25 sparse register barrier SHA256 source search (13,924 variants) — PASS](https://github.com/zeranemesis/st/actions/runs/40286940985).
- Fifth500 strict full-source validation: `verify_fifth500_romfree.py` (Clang -O2; records must agree with original ROM-derived SHA256 spans).
- Literal-pool-aware byte audit: `audit_literal_pools_round20.py` (require a genuine decoded PC-relative LDR referencing the one-word Clang literal).
- Existing 26 semantic regression groups are also executed in `.github/workflows/research-eur1-round14.yml`.

```sh
python3 research/eur1/batches/arm9_leaf500/search_sparse_barriers_round25.py
python3 research/eur1/batches/arm9_leaf500/verify_fifth500_romfree.py
python3 research/eur1/batches/arm9_leaf500/audit_literal_pools_round20.py
```

**Scope limitation:** the 82 and 70 counts describe standalone Clang ARMv5TE **instruction equality**, not the original Nintendo CodeWarrior compiler or ROM linker, recovered C++ ownership/signatures, the full DS game build, verified gameplay behavior, or a native PC port. No original ROM bytes are published.
