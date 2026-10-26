/* Zelda Spirit Tracks EUR Rev1: readable overlay 000 C reconstructions.
 * 10 independent provisional C interpretations of existing arm9_leaf500 entries.
 * Not integrated Nintendo DS CodeWarrior translation units.
 */
#include <stdint.h>
#include <stddef.h>

#define ST_READ32(b,o) (*(const volatile uint32_t*)((b)+(o)))
#define ST_WRITE32(b,o,v) (*(volatile uint32_t*)((b)+(o)) = (v))
#define ST_WRITE16(b,o,v) (*(volatile uint16_t*)((b)+(o)) = (v))
#define ST_WRITE8(b,o,v) (*(volatile uint8_t*)((b)+(o)) = (v))

/* overlay_000 @ 0x02057D6C: return nonzero base offset plus 0x58-sized index. */
uint32_t st_ov000_02057D6C(const volatile uint8_t *object, uint32_t index) {
    uint32_t base_offset = ST_READ32(object, 60);
    return base_offset == 0 ? 0 : base_offset + index * 0x58u;
}

/* overlay_000 @ 0x020590E4: reset an object and initialize its vtable pointer. */
uint32_t st_ov000_020590E4(volatile uint8_t *object) {
    ST_WRITE32(object, 0, 0x020B1BA8u);
    ST_WRITE32(object, 16, 0);
    ST_WRITE32(object, 4, 0);
    ST_WRITE32(object, 8, 0);
    ST_WRITE32(object, 12, 0);
    return (uint32_t)(uintptr_t)object;
}

/* overlay_000 @ 0x0205B090: original arithmetic-shift/rounding flow. */
uint32_t st_ov000_0205B090(uint32_t input) {
    uint32_t base = input - 0x80u;
    uint32_t scaled = base << 12;
    uint32_t correction = (uint32_t)((int32_t)scaled >> 6);
    uint32_t wrapped = scaled + (correction >> 25);
    return (uint32_t)(int32_t)(int16_t)(wrapped << 9);
}

/* overlay_000 @ 0x0205C5A0: shuffle two fields of indexed 8-bit records. */
uint32_t st_ov000_0205C5A0(volatile uint8_t *object, uint32_t index, uint8_t next_value) {
    uint8_t old_value = object[index + 8u];
    object[index + 10u] = old_value;
    object[index + 8u] = next_value;
    return (uint32_t)(uintptr_t)(object + index);
}

/* overlay_000 @ 0x02060738: step a signed byte counter, wrap above limit. */
uint32_t st_ov000_02060738(volatile uint8_t *object) {
    int8_t limit = *(const volatile int8_t *)(object + 101);
    uint8_t next = (uint8_t)((int8_t)object[99] + 1);
    object[99] = next;
    if ((int8_t)object[99] > limit) {
        object[99] = object[100];
    }
    return (uint32_t)(uintptr_t)object;
}

/* overlay_000 @ 0x02060804: mixed-width reset with sentinel 0xFFFF. */
uint32_t st_ov000_02060804(volatile uint8_t *object) {
    ST_WRITE32(object, 88, 0);
    ST_WRITE32(object, 96, 0);
    ST_WRITE32(object, 104, 0);
    ST_WRITE16(object, 108, UINT16_MAX);
    ST_WRITE8(object, 110, 1);
    ST_WRITE8(object, 111, 0);
    return (uint32_t)(uintptr_t)object;
}

/* overlay_000 @ 0x02062E44: pair of signed halfwords from nested pointer. */
uint32_t st_ov000_02062E44(volatile uint8_t *dst, const volatile uint8_t *owner) {
    uintptr_t child = ST_READ32(owner, 12);
    ST_WRITE16(dst, 0, *(const volatile int16_t *)(child + 10));
    ST_WRITE16(dst, 2, *(const volatile int16_t *)(child + 12));
    return (uint32_t)(uintptr_t)dst;
}

/* overlay_000 @ 0x02065460: both flags at offsets 88 and 92 must be zero. */
uint32_t st_ov000_02065460(const volatile uint8_t *object) {
    if (ST_READ32(object, 88) != 0) return 0;
    return ST_READ32(object, 92) == 0;
}

/* overlay_000 @ 0x0206547C: two signed comparisons against scaled limits. */
uint32_t st_ov000_0206547C(const volatile uint8_t *object) {
    uint32_t count = *(const volatile uint8_t *)(object + 113);
    uint32_t scale_first = ST_READ32(object, 80);
    uint32_t value_first = ST_READ32(object, 88);
    if ((int32_t)value_first < (int32_t)(scale_first * count)) return 0;
    uint32_t scale_second = ST_READ32(object, 84);
    uint32_t value_second = ST_READ32(object, 92);
    return (int32_t)value_second >= (int32_t)(scale_second * count);
}

/* overlay_000 @ 0x0206590C: initial fields and preserve supplied metadata. */
uint32_t st_ov000_0206590C(volatile uint8_t *object, uint32_t param1, uint32_t param2) {
    ST_WRITE16(object, 0, 0);
    ST_WRITE16(object, 2, 0);
    ST_WRITE32(object, 148, 0);
    ST_WRITE16(object, 4, param1);
    ST_WRITE32(object, 140, param2);
    ST_WRITE32(object, 144, 2);
    return (uint32_t)(uintptr_t)object;
}
