# Spirit Tracks EUR Rev1 — round 20: two new exact Clang ARM C reconstructions

**25 October 2026.** Draft PR #15, branch
`decomp/eur1-100-new-bl-reconstructions-20261023b`. No CodeWarrior.

## Verified advance: 52 → 54 exact standalone Clang matches

Two functions in the **existing 500-function research batch** were changed
from generated ARM-register simulations to readable C definitions. The
ENTIRE 12-byte and 16-byte original ARM instruction spans respectively
match the original EUR Rev1 reference SHA-256 under the existing unchanged
Clang `--target=armv5te-none-eabi -march=armv5te -marm -O2` backend.

### Overlay 000: `0x020A2B0C` (12/12 bytes, pure C)

```c
uint32_t st_ov000_020A2B0C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint8_t *subobject = (uint8_t *)(uintptr_t)(r0 + 0x100u);
    *(uint16_t *)(subobject + 112u) = (uint16_t)r1;
    return (uint32_t)(uintptr_t)subobject;
}
```

The typed intermediate pointer makes Clang emit **three ARM instructions**
with the original instruction order and exact bytes:

```asm
add   r0, r0, #256
strh  r1, [r0, #112]
bx    lr
```

Other ostensibly equivalent C forms were generating four instructions:
they accessed the halfword via `r0 + 0x170` before incrementing the
return pointer.

### Overlay 092: `0x0217A278` (16/16 bytes, C with compiler-only barrier)

```c
uint32_t st_ov092_0217A278(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t value = *(uint32_t *)(uintptr_t)(r0 + 36u);
    value += 2u;
    /* Empty compiler-only barrier: preserve separate ARM ADD and AND. */
    __asm__ __volatile__("" : "+r"(value));
    return value & 3u;
}
```

This matches the original **four ARM instructions**:

```asm
ldr   r0, [r0, #36]
add   r0, r0, #2
and   r0, r0, #3
bx    lr
```

The `__asm__ __volatile__` statement is **empty**: it emits no ARM
machine code. It deliberately prevents Clang `-O2` from changing
`(value + 2) & 3` into `(value & 3) ^ 2`, which has the same semantics
but a different binary. This is **not ISO C** and requires a compatible
compiler extension. It should not be presented as a pure-C compiler match.

Both original SHA-256 reference digests were verified against the
actual locally compiled ARM ELF function sections before publication,
and independently rechecked on GitHub Actions after the original research
shards were updated.

## Validation

| Result | Before | After |
| --- | ---: | ---: |
| Clang ARMv5TE exact function sections | 52/500 | **54/500** |
| Clang nonmatching research function sections | 448/500 | **446/500** |
| Same size but different machine instructions | 122 | **121** |
| Different compiled size | 326 | **325** |
| Original functions present in the fifth batch | 500 | 500 |

The full-batch verifier recompiles **all five actual C research shards**,
validates every original function's exact SHA-256 match status against
`manifest_fifth500.json`, and checks that none of the other 498 original
functions regressed. The previous 26 semantic regression groups remain
green. Source candidates and the original manifest are both updated.

- Full batch CI, 54/500 and 26 semantic tests **PASS**:
  https://github.com/zeranemesis/st/actions/runs/40191666592
- Additional 54/500 mismatch-classification audit and research searches
  **PASS**: https://github.com/zeranemesis/st/actions/runs/40191662291

## How this was found (no CodeWarrior)

Instead of trying additional blind source rewrites, this round hypothesized
very short, semantically plausible ARM instruction sequences and checked
their **full SHA-256 fingerprints** against the known original EUR1
function-reference hashes. That established the expected exact three/four
ARM instructions without needing to inspect or publish the original ROM
bytes. Local source experiments then recovered C forms Clang compiled to
those sequences; the full source/shard GitHub verifier confirmed the
result, not just a separately generated example.

## Not claimed

- **Not** Nintendo CodeWarrior exact matching; **not** original game
  C++ translation-unit `objdiff`, rebuilt DS ROM, gameplay verification,
  or native PC port.
- These are **two improved implementations of existing recorded function
  addresses**, not two new original game addresses.
- The fifth-batch matching percentage (54/500) is **not** the percentage
  of the full game decompiled or playable.
- The overlay 092 function is **compiler-specific C plus an empty
  inline-assembly optimization barrier**, not strictly portable C.

For further precise C matching, the optional instruction-level comparison
mode in `rank_mismatches_round18.py` can use authenticated EUR1 binaries
locally without uploading them or requiring Nintendo CodeWarrior.
