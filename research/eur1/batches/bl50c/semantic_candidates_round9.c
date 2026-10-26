/* Spirit Tracks EUR Rev 1: semantic C candidates for previously nonmatching functions.
 * Source-level hypotheses derived from the existing register-state translations.
 * Research only: not Nintendo CodeWarrior matching or game sources.
 */
#include <stddef.h>
#include <stdint.h>

#define READ32(base, off) (*(const volatile uint32_t *)((base) + (off)))
#define WRITE32(base, off, val) (*(volatile uint32_t *)((base) + (off)) = (val))

/* arm9:0x0200371C -- acquire a non-overlapping bit mask at 0x02045CCC. */
uint32_t st_arm9_0200371C(uint32_t bits) {
    volatile uint32_t * const registered = (volatile uint32_t *)(uintptr_t)0x02045CCCu;
    uint32_t old = *registered;
    if (old & bits) return 0;
    *registered = old | bits;
    return 1;
}

/* arm9:0x020131EC -- wait for bit zero to clear, then to become set. */
uint32_t st_arm9_020131EC(void) {
    const volatile uint16_t * const status = (const volatile uint16_t *)(uintptr_t)0x04000004u;
    uint32_t value;
    do { value = *status; } while (value & 1u);
    do { value = *status; } while ((value & 1u) == 0u);
    return value;
}

/* arm9:0x02014704 -- check four-character magic and return word at +36. */
uint32_t st_arm9_02014704(const volatile uint8_t *data) {
    if (data == NULL || READ32(data, 0) != 0x554E5348u) return 0;
    return READ32(data, 36);
}

/* arm9:0x0202CE2C -- either both pair members are nonzero or both are zero. */
uint32_t st_arm9_0202CE2C(volatile uint8_t *object, uint32_t first, uint32_t second) {
    if (second == 0) first = 0;
    else if (first == 0) second = 0;
    WRITE32(object, 84, first);
    WRITE32(object, 88, second);
    return (uint32_t)(uintptr_t)object;
}

/* overlay_003:0x020B7E2C -- indexed halfword from bounded signed counter. */
uint32_t st_ov003_020B7E2C(const volatile uint8_t *object) {
    int32_t index = (int32_t)(READ32(object, 272) - 1u);
    int32_t limit = (int32_t)READ32(object, 256);
    if (index > limit) index = limit;
    else if (index < 0) index = 0;
    return *(const volatile uint16_t *)(object + 224 + (uint32_t)index * 2u);
}

/* overlay_026:0x020FC9C0 -- translate a bounded mode into one of 0..3. */
uint32_t st_ov026_020FC9C0(volatile uint32_t *out, int32_t mode, int32_t upper) {
    uint32_t value;
    if (mode >= 4 || mode >= upper) value = 0;
    else if (mode == 3) value = 1;
    else if (mode == 2) value = 2;
    else value = 3;
    *out = value;
    return (uint32_t)(uintptr_t)out;
}

/* overlay_026:0x0211E0F0 -- test bit 5 of field +20 of active object. */
uint32_t st_ov026_0211E0F0(void) {
    uintptr_t object = *(const volatile uint32_t *)(uintptr_t)0x027E09B8u;
    return ((*(const volatile uint32_t *)(object + 20u)) & 0x20u) != 0;
}

/* overlay_030:0x0214D724 -- test bit 18 of field +52. */
uint32_t st_ov030_0214D724(void) {
    uintptr_t object = *(const volatile uint32_t *)(uintptr_t)0x027E09B8u;
    return ((*(const volatile uint32_t *)(object + 52u)) & 0x40000u) != 0;
}

/* overlay_030:0x0214D744 -- test bit 11 of field +20. */
uint32_t st_ov030_0214D744(void) {
    uintptr_t object = *(const volatile uint32_t *)(uintptr_t)0x027E09B8u;
    return ((*(const volatile uint32_t *)(object + 20u)) & 0x800u) != 0;
}

/* overlay_070:0x0214B2A0 -- recognize either of two mode values. */
uint32_t st_ov070_0214B2A0(void) {
    uintptr_t object = *(const volatile uint32_t *)(uintptr_t)0x027E09A4u;
    uint32_t mode = *(const volatile uint32_t *)object;
    return mode == 0x20u || mode == 0x4Du;
}

/* overlay_090:0x02170E18 -- accept mode 1 or mode 2 with signed count <= 1. */
uint32_t st_ov090_02170E18(const volatile uint8_t *object) {
    uint16_t mode = *(const volatile uint16_t *)(object + 108);
    if (mode == 1u) return 1;
    if (mode != 2u) return 0;
    return *(const volatile int16_t *)(object + 72) <= 1;
}

/* overlay_092:0x0217A7E4 -- shift history and update repeat counter. */
uint32_t st_ov092_0217A7E4(volatile uint32_t *state, uint32_t new_value) {
    uint32_t previous = state[0];
    state[0] = new_value;
    state[1] = previous;
    state[2] = (previous == new_value) ? state[2] + 1u : 0u;
    return (uint32_t)(uintptr_t)state;
}

/* overlay_000:0x02072FF0 -- set indexed halfword, then a ready flag. */
uint32_t st_ov000_02072FF0(volatile uint8_t *base, uint32_t index, uint32_t value) {
    *(volatile uint16_t *)(base + index * 2u) = (uint16_t)value;
    base[16] = 1u;
    return (uint32_t)(uintptr_t)base;
}

/* overlay_000:0x020816C4 -- read a bit from the word at +172. */
uint32_t st_ov000_020816C4(const volatile uint8_t *object, uint32_t bit) {
    uint32_t bits = READ32(object, 172);
    return bit < 32u && ((bits >> bit) & 1u);
}

/* overlay_000:0x020816FC -- read a bit from the word at +176. */
uint32_t st_ov000_020816FC(const volatile uint8_t *object, uint32_t bit) {
    uint32_t bits = READ32(object, 176);
    return bit < 32u && ((bits >> bit) & 1u);
}

/* overlay_000:0x0207749C -- select one of two indexed word arrays. */
uint32_t st_ov000_0207749C(const volatile uint8_t *object, uint32_t index, uint32_t alternative) {
    if (index == UINT32_MAX) return READ32(object, alternative * 4u + 12u);
    return READ32(object, index * 4u + 20u);
}

/* arm9:0x02028C4C -- repeat a 32-bit word in a byte-sized destination span. */
uint32_t st_arm9_02028C4C(uint32_t value, volatile uint32_t *dst, uint32_t byte_count) {
    uintptr_t end = (uintptr_t)dst + byte_count;
    while ((intptr_t)(uintptr_t)dst < (intptr_t)end) *dst++ = value;
    return value;
}

/* arm9:0x02028C60 -- copy 32-bit words, returning the advanced source. */
volatile uint32_t *st_arm9_02028C60(volatile uint32_t *src, volatile uint32_t *dst, uint32_t byte_count) {
    uintptr_t end = (uintptr_t)dst + byte_count;
    while ((intptr_t)(uintptr_t)dst < (intptr_t)end) *dst++ = *src++;
    return src;
}
