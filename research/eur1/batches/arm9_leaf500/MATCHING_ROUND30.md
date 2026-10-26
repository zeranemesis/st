# Zelda: Spirit Tracks (EUR Rev1) — round 30: exact short original ARM reconstruction and readable C

**26 October 2026.** Draft PR #15, branch `decomp/eur1-100-new-bl-reconstructions-20261023b`.

## Summary: 16/16 short original instruction streams recovered, C match count unchanged

This round **does not claim new original compiler matching**. It solves a separate
reverse-engineering problem: what exact ARM instructions could produce the
already authenticated **complete original function-code SHA-256**, when the
original ROM bytes are unavailable within GitHub?

The Python research tool `recover_short_arm_round30.py` tries **680,640
constrained ARMv5TE instruction sequences** of 12 or 16 bytes, constructed
from a small explicit grammar: PC-relative literals, data loads, AND, MOV,
MLA, CMP and conditional ARM instructions, halfword indexed table loads,
fixed-point arithmetic and BX LR. Each candidate is hashed in the original
little-endian ARM instruction-byte order.

**All 16 previously opcode-unmatched original EUR Rev1 short functions
(12/16 bytes)** in this specific 500-function research set have a
**full-function SHA-256-exact sequence** recovered. The report artifact
lists *every 32-bit ARM instruction word* and the decoded register roles;
none is copied from an uploaded ROM.

This is **evidence of original ARM instruction bytes**, not proof that
Clang generated those bytes from any particular C expression, not proof
of original C++ signatures, and not a game-wide decompilation percentage.

## All 16 original functions — whole-instruction-span SHA-256 verified

| Original function | Original code length | Recovered ARM instruction structure |
| --- | ---: | --- |
| `st_ov000_02067BB4` | 16 bytes | CMP; conditional word loads from offsets +12 / +16; BX LR |
| `st_ov000_0206D32C` | 12 bytes | PC-relative literal LDR; AND mask register; BX LR |
| `st_ov000_02078EA0` | 16 bytes | MOV #24; MLA for indexed address; LDR word at +24; BX LR |
| `st_ov000_0208AED0` | 16 bytes | PC-relative base LDR; MOV stride #6; MLA; BX LR |
| `st_ov000_020A7880` | 16 bytes | PC-relative base LDR; MOV stride #28; MLA; BX LR |
| `st_ov020_020C70BC` | 16 bytes | PC-relative base LDR; MOV stride #28; MLA; BX LR |
| `st_ov021_020EA8A8` | 16 bytes | PC-relative base LDR; MOV stride #24; MLA; BX LR |
| `st_ov023_020E9AE0` | 12 bytes | PC-relative base LDR; indirect LDR word; BX LR |
| `st_ov026_020EB284` | 16 bytes | CMP; SUBgt / SUBle signed conditional absolute difference; BX LR |
| `st_ov026_020F903C` | 16 bytes | CMP #0; MOVEQ #3; MOVNE #1; BX LR |
| `st_ov026_02102A54` | 16 bytes | PC-relative base LDR; MOV stride #96; MLA; BX LR |
| `st_ov026_02108340` | 16 bytes | PC-relative base LDR; MOV stride #44; MLA; BX LR |
| `st_ov026_02108354` | 16 bytes | PC-relative base LDR; MOV stride #12; MLA; BX LR |
| `st_ov070_02148870` | 16 bytes | LDRH +110; PC-relative global table pointer; indexed word LDR; BX LR |
| `st_ov071_02150D80` | 16 bytes | PC-relative base LDR; MOV stride #24; MLA; BX LR |
| `st_ov093_021753BC` | 16 bytes | MUL; ADD #0x800; arithmetic right shift #12; BX LR |

**Source provenance:** all entries already existed in
`manifest_fifth500.json`, with original game addresses, original ROM-backed
per-function SHA256 digests and direct branch-call evidence. The new code
records the proof template for each rather than claiming 16 newly discovered
function boundaries. The decoder recomputes each digest over the complete
candidate instruction span; partial/prefix matches are **not** accepted here.

**Literal-pool caveat:** for the PC-relative LDR candidates the SHA256 verifies
the original *function instruction* bytes, not the referenced four-byte
constant's original placement/value. That is why this research is not
promoted to a strict whole-Clang-ELF-section match.

## Actual C source improvements

The 16 original automatically generated ARM-register simulations have been
**replaced with readable, compact C semantics in the existing fifth500 C
research shards** `arm9_leaf_500_part1.c` to `part5.c`:

- Eight global-table/base-address stride computations now express a
  `uint32_t` base + stride times index directly.
- One ten-bit `AND` mask has a single expression.
- A single fixed global-address word dereference is expressed directly.
- Conditional field selection, index-and-load, signed two-input difference,
  ternary comparison, indexed halfword-table lookup and signed fixed-point
  arithmetic use explicit C constructs that preserve their earlier
  register-state translation's apparent operation.
- The manifest marks these functions as **readable C research semantics** and
  adds a distinct `original_arm_code_sha256_template_recovered` field.

The new C versions are **not** asserted to produce identical Clang ARM opcode
streams; in fact the compiler may replace literal loads with MOV/ORR or
strength-reduce multiplications rather than reproduce the original MLA
register allocation. They are not proof of Nintendo original source code.

### Semantic host regressions

`verify_short_semantics_round30.py` links the **actual published fifth500 C
shards** as native host C and executes **208** arithmetic boundary-case tests
across **12** of these functions: eight global-array stride helpers,
the mask, signed difference, equality selection and signed fixed-point
conversion. It includes `0xffffffff` and `0x7fffffff` boundary inputs,
so unsigned 32-bit wraparound and signed right shifts are covered.

Four Nintendo-DS-address dereference functions are deliberately **not
executed on the host**, because valid DS addresses are not valid x86-64
process-memory addresses. Host arithmetic tests do not validate DS gameplay
semantics or memory ownership.

## Independent GitHub Actions validation

- [Original code reconstruction CI — **PASS**, 16/16 SHA256-exact,
  680,640 candidate sequences](https://github.com/zeranemesis/st/actions/runs/40346796699)
- [Recovered instruction + actual host-C regression CI — **PASS**,
  16/16 and **208 host test cases**](https://github.com/zeranemesis/st/actions/runs/40347394480)
- [Full 500-source Clang strict matching regression — **PASS**,
  84 strict sections](https://github.com/zeranemesis/st/actions/runs/40347334554)
- [Full 500-source separately referenced one-word-literal opcode audit —
  **PASS**, 70 additional exact instruction spans](https://github.com/zeranemesis/st/actions/runs/40347334537)

```sh
python3 research/eur1/batches/arm9_leaf500/recover_short_arm_round30.py
python3 research/eur1/batches/arm9_leaf500/verify_short_semantics_round30.py
python3 research/eur1/batches/arm9_leaf500/verify_fifth500_romfree.py
python3 research/eur1/batches/arm9_leaf500/audit_literal_pools_round20.py
```

## Do not confuse the two measures

| Metric, only within this fifth500 research lot | Before | After |
| --- | ---: | ---: |
| **Strict complete Clang ARM section SHA256 matching original code** | 84 | **84** |
| **Additional original ARM code spans matching Clang, but with extra Clang literal word** | 70 | **70** |
| **Total original ARM opcode spans reproduced by published Clang C sources** | 154/500 | **154/500** |
| **Previously unconfirmed short original instruction sequences recovered separately by constrained SHA search** | 0 documented | **16/16** |
| **Readable new C translations replacing generated register simulations** | — | **16** |
| **Native host arithmetic checks on these translations** | — | **208 cases on 12 functions** |

**346 original opcode spans still do not match their current Clang C
reconstructions, including these 16 newly understood short assembly routines.**
The decoder makes the exact register/instruction targets clear for future
compiler-constraint work, but does not imply that matching is now 170/500.

No Nintendo CodeWarrior, official DS C++ objdiff, complete ROM rebuild,
gameplay validation or native PC port is claimed.
