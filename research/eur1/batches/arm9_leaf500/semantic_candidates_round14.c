/* Zelda: Spirit Tracks, EUR Rev1, overlay 000 (25 Oct 2026).
 * 26 new readable C interpretations of functions ALREADY listed in
 * research/eur1/batches/arm9_leaf500/manifest_fifth500.json.
 * All offsets/arithmetic are inferred from the existing ARM register-state
 * C translations. These are RESEARCH CANDIDATES, not byte-matched sources
 * nor verified gameplay algorithms. No Nintendo ROM code included.
 */
#include <stdint.h>
#include <stddef.h>

#define ST_R32(base, off) (*(const volatile uint32_t *)((base) + (off)))
#define ST_R16(base, off) (*(const volatile uint16_t *)((base) + (off)))
#define ST_RS16(base, off) (*(const volatile int16_t *)((base) + (off)))
#define ST_W32(base, off, value) (*(volatile uint32_t *)((base) + (off)) = (uint32_t)(value))
#define ST_W16(base, off, value) (*(volatile uint16_t *)((base) + (off)) = (uint16_t)(value))
#define ST_W8(base, off, value) (*(volatile uint8_t *)((base) + (off)) = (uint8_t)(value))

/* 0x0205AED0: fixed-point-like rounding followed by a signed shift. */
uint32_t st_ov000_0205AED0(uint32_t value, uint32_t shift) {
    uint32_t v = value - 0x80000u;
    uint32_t rounded = v + ((uint32_t)((int32_t)v >> 6) >> 25);
    uint32_t result = (uint32_t)((int32_t)rounded >> 7);
    return (uint32_t)(int32_t)(int16_t)((uint32_t)((int32_t)result >> (shift & 31u)));
}

/* 0x0205D500: sentinel selects one of two halfword layouts. */
uint32_t st_ov000_0205D500(volatile uint8_t *out, uint32_t value, uint32_t selector) {
    if (selector == UINT32_MAX) {
        ST_W16(out, 2, value);
        ST_W16(out, 0, 0x100u);
    } else {
        ST_W16(out, 0, 0x101u);
        ST_W16(out, 2, selector);
    }
    return (uint32_t)(uintptr_t)out;
}

/* 0x02068504: low halfword of (3 * n + 4). */
uint32_t st_ov000_02068504(uint32_t value) {
    return (uint16_t)(value * 3u + 4u);
}

/* 0x0206AEB4: preserve signed-shift sequence and exceptional divisor value. */
uint32_t st_ov000_0206AEB4(const volatile uint8_t *state, uint32_t value) {
    uint32_t scale = ST_R32(state, 48);
    if (scale == 0x100u) return value;
    uint32_t product = scale * value;
    uint32_t corrected = product + ((uint32_t)((int32_t)product >> 7) >> 24);
    return (uint32_t)((int32_t)corrected >> 8);
}

/* 0x0206AF94: reset flags and five 32-bit fields in exact store order. */
uint32_t st_ov000_0206AF94(volatile uint8_t *state) {
    ST_W8(state, 16, 0);
    ST_W8(state, 17, 0);
    ST_W8(state, 18, 0);
    ST_W8(state, 19, 0);
    ST_W32(state, 20, 127);
    ST_W32(state, 24, 0);
    ST_W32(state, 28, 0);
    ST_W32(state, 32, 40);
    ST_W32(state, 36, 0);
    return (uint32_t)(uintptr_t)state;
}

/* 0x0206D32C: lower ten bits of a value. */
uint32_t st_ov000_0206D32C(uint32_t value) {
    return value & 0x3ffu;
}

/* 0x02070138: initialize byte flag and duration, defaulting -1 to 180. */
uint32_t st_ov000_02070138(volatile uint8_t *object, uint32_t duration) {
    if (duration == UINT32_MAX) duration = 180u;
    ST_W8(object, 5, 0);
    ST_W32(object, 8, duration);
    return (uint32_t)(uintptr_t)object;
}

/* 0x020712B4: any of three byte flags set? */
uint32_t st_ov000_020712B4(const volatile uint8_t *object) {
    return (object[12] != 0u || object[48] != 0u || object[92] != 0u);
}

/* 0x020771D0: compare two indexed 32-bit values at +4 and +12. */
uint32_t st_ov000_020771D0(const volatile uint8_t *base, uint32_t index) {
    const volatile uint8_t *entry = base + index * 4u;
    return ST_R32(entry, 4) == ST_R32(entry, 12);
}

/* 0x02078EA0: read indexed word in 24-byte records, field +24. */
uint32_t st_ov000_02078EA0(const volatile uint8_t *base, uint32_t index) {
    return ST_R32(base, index * 24u + 24u);
}

/* 0x02079304: initialize a small object, starting with a fixed descriptor. */
uint32_t st_ov000_02079304(volatile uint8_t *object) {
    ST_W32(object, 0, 0x020b259cu);
    ST_W16(object, 4, 0);
    ST_W16(object, 6, 0);
    ST_W16(object, 8, 0);
    return (uint32_t)(uintptr_t)object;
}

/* 0x0207995C: reset short fields and set enabled flag. */
uint32_t st_ov000_0207995C(volatile uint8_t *object) {
    ST_W16(object, 48, 0x148u);
    ST_W16(object, 42, 0);
    ST_W16(object, 44, 0);
    ST_W16(object, 46, 0);
    ST_W8(object, 80, 1);
    return (uint32_t)(uintptr_t)object;
}

/* 0x020816A0: set/clear a flag in the word at object +172. */
uint32_t st_ov000_020816A0(volatile uint8_t *object, uint32_t bit, uint32_t enabled) {
    uint32_t bits = ST_R32(object, 172);
    uint32_t mask = 1u << (bit & 31u); /* ARM register shift semantics */
    bits = enabled ? bits | mask : bits & ~mask;
    ST_W32(object, 172, bits);
    return (uint32_t)(uintptr_t)object;
}

/* 0x020816D8: analogous flag word at object +176. */
uint32_t st_ov000_020816D8(volatile uint8_t *object, uint32_t bit, uint32_t enabled) {
    uint32_t bits = ST_R32(object, 176);
    uint32_t mask = 1u << (bit & 31u);
    bits = enabled ? bits | mask : bits & ~mask;
    ST_W32(object, 176, bits);
    return (uint32_t)(uintptr_t)object;
}

/* 0x02089FC0: initialize record and preserve the former +16 halfword. */
uint32_t st_ov000_02089FC0(volatile uint8_t *object) {
    uint16_t previous = ST_R16(object, 16);
    ST_W16(object, 6, UINT16_MAX);
    ST_W16(object, 8, 0);
    ST_W16(object, 10, 0);
    ST_W32(object, 12, 0);
    ST_W16(object, 18, previous);
    return (uint32_t)(uintptr_t)object;
}

/* 0x02089FE4: update three fields when the new signed value is >= old. */
uint32_t st_ov000_02089FE4(volatile uint8_t *object, uint32_t value,
                           uint32_t associated, uint32_t descriptor) {
    int32_t previous = (int32_t)ST_RS16(object, 6);
    if ((int32_t)value >= previous) {
        ST_W16(object, 6, value);
        ST_W16(object, 10, associated);
        ST_W32(object, 12, descriptor);
    }
    return (uint32_t)(uintptr_t)object;
}

/* 0x0208E770: reset an accumulator on key change, advance and set 15. */
uint32_t st_ov000_0208E770(volatile uint8_t *state, uint32_t key, uint32_t delta) {
    uint32_t previous_key = ST_R32(state, 0);
    if (previous_key != key) ST_W16(state, 4, 0);
    uint16_t value = ST_R16(state, 4);
    ST_W32(state, 0, key);
    ST_W16(state, 4, (uint16_t)(value + delta));
    ST_W16(state, 6, 15);
    return (uint32_t)(uintptr_t)state;
}

/* 0x02096C7C: reset a 5-word structure, with three -1 sentinels. */
uint32_t st_ov000_02096C7C(volatile uint8_t *object) {
    ST_W32(object, 0, 0);
    ST_W32(object, 4, UINT32_MAX);
    ST_W32(object, 8, UINT32_MAX);
    ST_W32(object, 12, UINT32_MAX);
    ST_W32(object, 16, 0);
    return (uint32_t)(uintptr_t)object;
}

/* 0x020A2B0C: write halfword at +0x170, return object+0x100. */
uint32_t st_ov000_020A2B0C(volatile uint8_t *object, uint32_t value) {
    volatile uint8_t *subobject = object + 0x100u;
    ST_W16(subobject, 112, value);
    return (uint32_t)(uintptr_t)subobject;
}

/* 0x020A3950: return 16 when the word at +12 is present. */
uint32_t st_ov000_020A3950(const volatile uint8_t *object) {
    return ST_R32(object, 12) != 0u ? 16u : 0u;
}

/* 0x020A44D0: signed-positive field at +312. */
uint32_t st_ov000_020A44D0(const volatile uint8_t *object) {
    return (int32_t)ST_R32(object, 312) > 0;
}

/* 0x020A4B40: compare a signed short at +30 to 96. */
uint32_t st_ov000_020A4B40(const volatile uint8_t *object) {
    return ST_RS16(object, 30) < 96;
}

/* 0x020A6B70: clear seven sparse fields, including two single bytes. */
uint32_t st_ov000_020A6B70(volatile uint8_t *object) {
    ST_W32(object, 0, 0);
    ST_W32(object, 4, 0);
    ST_W32(object, 8, 0);
    ST_W8(object, 12, 0);
    ST_W8(object, 13, 0);
    ST_W32(object, 24, 0);
    ST_W32(object, 28, 0);
    return (uint32_t)(uintptr_t)object;
}

/* 0x020A7764: saturating increment with UINT32_MAX sentinel. */
uint32_t st_ov000_020A7764(volatile uint8_t *object, uint32_t amount) {
    uint32_t before = ST_R32(object, 4);
    uint32_t result = (UINT32_MAX - before <= amount)
                    ? UINT32_MAX : before + amount;
    ST_W32(object, 4, result);
    return (uint32_t)(uintptr_t)object;
}

/* 0x0208AED0: address of 6-byte indexed entry in a fixed ROM table. */
uint32_t st_ov000_0208AED0(uint32_t index) {
    return 0x020ace0cu + index * 6u;
}

/* 0x020A7880: address of 28-byte indexed entry in fixed ROM table. */
uint32_t st_ov000_020A7880(uint32_t index) {
    return 0x020af7d4u + index * 28u;
}
