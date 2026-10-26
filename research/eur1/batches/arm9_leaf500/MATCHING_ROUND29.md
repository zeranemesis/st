# Zelda: Spirit Tracks (EUR Rev1) — round 29: register-constraint matching (+2 strict)

**26 October 2026.** Working research branch `decomp/eur1-100-new-bl-reconstructions-20261023b`, draft PR #15. No Nintendo CodeWarrior, no source ROM uploads.

## Verified improvement — 152 → 154 complete original ARM opcode spans

Following the negative searches in rounds 26–28, the new read-only `search_register_constraints_round29.py` compiled **37,928 distinct Clang ARMv5TE -O2 source variants** for **307 previously unmatched original game function addresses**.

Rather than merely changing C memory qualifiers and operand expressions, it tests several forms of **zero-byte compiler constraints** on individual intermediate ARM registers:

- **Input-only** `__asm__ __volatile__("" : : "r"(value));`
- **Read/write early-clobber** `__asm__ __volatile__("" : "+&r"(value));`
- **Input with memory clobber** `__asm__ __volatile__("" : : "r"(value) : "memory");`
- **Tied register input/output** `__asm__ __volatile__("" : "=r"(value) : "0"(value));`
- **Memory-only** `__asm__ __volatile__("" ::: "memory");`
- **Paired register read** `__asm__ __volatile__("" : : "r"(value), "r"(other));`

These operations emit **no target ARM instructions**. They change which combinations of expressions Clang reorders or merges, and can influence live register allocation. None is portable ISO C.

Two previously nonmatching game function spans matched their **entire original ARM instruction-section SHA-256**.

| Game function | Module | Strict ARM machine code | Winning source constraint |
| --- | --- | ---: | --- |
| `st_ov000_02063FE4` | Overlay 000 | **24/24 bytes** | Empty compiler memory clobber before memory operations, volatile typed load/store, provisional `void` ABI |
| `st_ov000_020A5568` | Overlay 000 | **20/20 bytes** | Input-only fence referencing both the loaded `r0` and preserved `r12`; provisional `void` ABI |

The two complete, tested C formulations were copied **verbatim from the GitHub Actions candidate-search artifact** into `arm9_leaf_500_part1.c`. Their `clang_standalone_status` was promoted to `exact_original_machine_bytes` in the existing `manifest_fifth500.json`.

**Important semantics caveat:** Their winning source functions use a provisional **`void` return type**, whereas the original register-state placeholder returned `r0`. The matching ARM code therefore does **not** establish that the game’s true original C++ function signatures, side effects, or object ownership are recovered. The strict binary result is an instruction-equivalence result only.

## Independently verified counters, same 500 original game addresses

| Metric | Previous | Round 29 |
| --- | ---: | ---: |
| Strict complete Clang ELF sections matching original instruction SHA-256 | 82 | **84** |
| Extra matches of all original instruction bytes with one referenced Clang literal-pool word | 70 | **70** |
| **Total exact original ARM opcode spans** | **152/500** | **154/500** |
| Original instruction opcode spans still unmatched | 348 | **346** |
| Complete Clang ELF sections still nonmatching | 418 | **416** |

The extra-literal cases are **not** included in the 84 strict whole-section matches. The 70 extra-literal cases still belong to the 416 sections not identical in full ELF section contents.

After the sources and manifest were modified, multiple **independent** GitHub Actions runs compiled the **actual 500 published source functions**, verified every full-section match and the manifest counts, independently decoded the ARM `LDR` reference to each of the 70 appended four-byte constants, and ran the existing 26 semantic regression groups:

- [Round 29 source variant discovery: 37,928 Clang variants, 2 strict matches — PASS](https://github.com/zeranemesis/st/actions/runs/40328470927)
- [Full 500-source Clang SHA-256 recompilation and 26 semantic tests — PASS](https://github.com/zeranemesis/st/actions/runs/40328978794)
- [500-source literal-pool audit, 84 strict + 70 separate exact ARM opcode matches — PASS](https://github.com/zeranemesis/st/actions/runs/40328979100)

## Reproduction (Clang + Python, no proprietary game compiler)

```sh
python3 research/eur1/batches/arm9_leaf500/search_register_constraints_round29.py
python3 research/eur1/batches/arm9_leaf500/verify_fifth500_romfree.py
python3 research/eur1/batches/arm9_leaf500/audit_literal_pools_round20.py
```

The search works in **1,250-function chunks** to keep each produced ARM ELF relocatable object within the standard parser’s supported section count. It only reads previously unmatched original game function addresses and never automatically changes the manifest.

The 500-function research batch **is not** the entire game decompiled. No actual original Nintendo CodeWarrior `objdiff`, whole DS game rebuild, verified gameplay equivalence, or native PC port is claimed.
