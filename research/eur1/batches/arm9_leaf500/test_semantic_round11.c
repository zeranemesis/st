/* Host regression for ten typed C interpretations from the fifth 500 batch.
 * clang -std=c11 -O1 -g -fsanitize=address,undefined -fno-omit-frame-pointer \
 *   -Wall -Wextra -Werror test_semantic_round11.c -o /tmp/st-round11-tests
 * /tmp/st-round11-tests
 * Passing host tests does not establish Nintendo DS ROM byte matching.
 */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "semantic_refactors_round11.c"

int main(void) {
    union { uint64_t aligned; uint8_t bytes[512]; } u;
    uint8_t *p = u.bytes;
    memset(p, 0, sizeof u.bytes);
    assert(st_ov000_02057D6C(p, 7) == 0);
    ST_WRITE32(p, 60, 100);
    assert(st_ov000_02057D6C(p, 7) == 716);
    assert(st_ov000_02057D6C(p, UINT32_MAX) == (uint32_t)(100u + UINT32_MAX * 88u));

    memset(p, 0xAA, sizeof u.bytes);
    assert(st_ov000_020590E4(p) == (uint32_t)(uintptr_t)p);
    assert(ST_READ32(p,0) == 0x020B1BA8u);
    assert(ST_READ32(p,4) == 0 && ST_READ32(p,8) == 0
           && ST_READ32(p,12) == 0 && ST_READ32(p,16) == 0);

    p[8+3] = 0xAA; p[10+3] = 0xBB;
    assert(st_ov000_0205C5A0(p,3,0xCC) == (uint32_t)(uintptr_t)(p+3));
    assert(p[11] == 0xCC && p[13] == 0xAA);

    p[99] = 0; p[100] = 3; p[101] = 2;
    st_ov000_02060738(p); assert(p[99] == 1);
    st_ov000_02060738(p); assert(p[99] == 2);
    st_ov000_02060738(p); assert(p[99] == 3);
    st_ov000_02060738(p); assert(p[99] == 3);
    p[99] = 127; p[101] = 1;
    st_ov000_02060738(p); assert(p[99] == 128);

    memset(p, 0xAB, sizeof u.bytes);
    st_ov000_02060804(p);
    assert(ST_READ32(p,88) == 0 && ST_READ32(p,96) == 0 && ST_READ32(p,104) == 0);
    assert(*(uint16_t*)(p+108) == UINT16_MAX && p[110] == 1 && p[111] == 0);

    ST_WRITE32(p,88,0); ST_WRITE32(p,92,0);
    assert(st_ov000_02065460(p) == 1);
    ST_WRITE32(p,88,1); assert(st_ov000_02065460(p) == 0);
    ST_WRITE32(p,88,0); ST_WRITE32(p,92,1); assert(st_ov000_02065460(p) == 0);

    p[113] = 3;
    ST_WRITE32(p,80,10); ST_WRITE32(p,88,30);
    ST_WRITE32(p,84,5); ST_WRITE32(p,92,15);
    assert(st_ov000_0206547C(p) == 1);
    ST_WRITE32(p,88,29); assert(st_ov000_0206547C(p) == 0);
    ST_WRITE32(p,88,30); ST_WRITE32(p,92,14); assert(st_ov000_0206547C(p) == 0);
    ST_WRITE32(p,80,0xffffffffu); ST_WRITE32(p,88,0xffffffffu);
    ST_WRITE32(p,84,0xffffffffu); ST_WRITE32(p,92,0xffffffffu);
    p[113] = 1; assert(st_ov000_0206547C(p) == 1);

    memset(p, 0xEA, sizeof u.bytes);
    st_ov000_0206590C(p,0x12345678u,0xBADC0FFEu);
    assert(*(uint16_t*)(p+0) == 0 && *(uint16_t*)(p+2) == 0);
    assert(*(uint16_t*)(p+4) == 0x5678u);
    assert(ST_READ32(p,140) == 0xBADC0FFEu
           && ST_READ32(p,144) == 2 && ST_READ32(p,148) == 0);

    assert(st_ov000_0205B090(0x80) == 0);
    assert(st_ov000_0205B090(0x81) == (uint32_t)(int16_t)(1u<<21));

    /* The 10th source function 0x02062E44 is ARM32-only due to a stored
     * 32-bit pointer. It is compiled and hashed by the ARM verification.
     * Do not reinterpret a host 64-bit pointer as a Nintendo DS pointer. */
    puts("PASS: 9 host semantic function groups; NOT game/ROM matching");
    return 0;
}
