/* Zelda: Spirit Tracks EUR1, 26 independent semantic regression groups.
 * These host vectors test the readable RECONSTRUCTIONS, not real game runtime.
 * They do not prove source correctness or original CodeWarrior matching.
 * Build: clang -std=c11 -O1 -g -Wall -Wextra -Werror
 *        -fsanitize=address,undefined -fno-omit-frame-pointer
 *        test_semantic_round14.c -o /tmp/round14-tests
 */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "semantic_candidates_round14.c"

static union {
    uint64_t alignment;
    uint8_t bytes[512];
} data;

static void reset(void) {
    memset(data.bytes, 0xA5, sizeof data.bytes);
}

static uint32_t low_ptr(const volatile void *ptr) {
    return (uint32_t)(uintptr_t)ptr;
}

int main(void) {
    uint8_t *p = data.bytes;
    unsigned groups = 0;

    /* 01: signed fixed-point conversion and masked ARM shifts. */
    assert(st_ov000_0205AED0(0x80000u, 0) == 0);
    assert(st_ov000_0205AED0(0x80000u, 32) == 0);
    assert(st_ov000_0205AED0(0x80080u, 0) == 1);
    groups++;

    /* 02: two halfword variants with an all-ones sentinel. */
    reset();
    assert(st_ov000_0205D500(p, 0x1234, UINT32_MAX) == low_ptr(p));
    assert(ST_R16(p, 0) == 0x100u && ST_R16(p, 2) == 0x1234u);
    st_ov000_0205D500(p, 0x5678, 9);
    assert(ST_R16(p, 0) == 0x101u && ST_R16(p, 2) == 9);
    groups++;

    /* 03: linear halfword truncation. */
    assert(st_ov000_02068504(0) == 4);
    assert(st_ov000_02068504(1) == 7);
    assert(st_ov000_02068504(UINT32_MAX) == 1);
    groups++;

    /* 04: fixed-point conversion, and 256 fast-path. */
    reset(); ST_W32(p,48,0x100);
    assert(st_ov000_0206AEB4(p,1024) == 1024);
    ST_W32(p,48,0x80);
    assert(st_ov000_0206AEB4(p,1024) == 512);
    ST_W32(p,48,0);
    assert(st_ov000_0206AEB4(p,42) == 0);
    groups++;

    /* 05: sparse initialized fields and untouched prefix. */
    reset(); st_ov000_0206AF94(p);
    for (int i=16; i<20; ++i) assert(p[i]==0);
    assert(ST_R32(p,20)==127 && ST_R32(p,24)==0 && ST_R32(p,28)==0);
    assert(ST_R32(p,32)==40 && ST_R32(p,36)==0 && p[15]==0xA5);
    groups++;

    /* 06: ten-bit mask. */
    assert(st_ov000_0206D32C(UINT32_MAX)==1023);
    assert(st_ov000_0206D32C(0)==0);
    assert(st_ov000_0206D32C(0x400)==0);
    groups++;

    /* 07: default duration, both branches. */
    reset(); st_ov000_02070138(p,UINT32_MAX);
    assert(p[5]==0 && ST_R32(p,8)==180);
    st_ov000_02070138(p,321);
    assert(ST_R32(p,8)==321);
    groups++;

    /* 08: three independently tested flag bytes. */
    reset(); p[12]=p[48]=p[92]=0;
    assert(st_ov000_020712B4(p)==0);
    p[12]=1; assert(st_ov000_020712B4(p)==1); p[12]=0;
    p[48]=2; assert(st_ov000_020712B4(p)==1); p[48]=0;
    p[92]=3; assert(st_ov000_020712B4(p)==1);
    groups++;

    /* 09: comparisons across four-byte indexed slots. */
    reset(); ST_W32(p,12,123); ST_W32(p,20,123);
    assert(st_ov000_020771D0(p,2)==1);
    ST_W32(p,20,124); assert(st_ov000_020771D0(p,2)==0);
    groups++;

    /* 10: 24-byte record stride with +24 field. */
    reset(); ST_W32(p,24,11); ST_W32(p,48,22); ST_W32(p,72,33);
    assert(st_ov000_02078EA0(p,0)==11);
    assert(st_ov000_02078EA0(p,1)==22);
    assert(st_ov000_02078EA0(p,2)==33);
    groups++;

    /* 11: constant descriptor and short-sized field zeros. */
    reset(); st_ov000_02079304(p);
    assert(ST_R32(p,0)==0x020b259cu);
    assert(ST_R16(p,4)==0 && ST_R16(p,6)==0 && ST_R16(p,8)==0);
    assert(p[10]==0xA5);
    groups++;

    /* 12: short initializer and enabled byte. */
    reset(); st_ov000_0207995C(p);
    assert(ST_R16(p,48)==0x148u && ST_R16(p,42)==0);
    assert(ST_R16(p,44)==0 && ST_R16(p,46)==0 && p[80]==1);
    groups++;

    /* 13: set/clear and shift-count wrap on first bitset. */
    reset(); ST_W32(p,172,0);
    st_ov000_020816A0(p,31,1); assert(ST_R32(p,172)==0x80000000u);
    st_ov000_020816A0(p,32,1); assert(ST_R32(p,172)==0x80000001u);
    st_ov000_020816A0(p,31,0); assert(ST_R32(p,172)==1);
    groups++;

    /* 14: same semantics for second independent bitset. */
    reset(); ST_W32(p,176,UINT32_MAX);
    st_ov000_020816D8(p,1,0); assert(ST_R32(p,176)==UINT32_MAX-2u);
    st_ov000_020816D8(p,1,1); assert(ST_R32(p,176)==UINT32_MAX);
    groups++;

    /* 15: copy existing halfword and reset status fields. */
    reset(); ST_W16(p,16,0xCAFE);
    st_ov000_02089FC0(p);
    assert(ST_R16(p,6)==0xffff && ST_R16(p,8)==0 && ST_R16(p,10)==0);
    assert(ST_R32(p,12)==0 && ST_R16(p,18)==0xCAFE);
    assert(ST_R16(p,16)==0xCAFE);
    groups++;

    /* 16: signed >= update and rejection. */
    reset(); ST_W16(p,6,10);
    st_ov000_02089FE4(p,9,5,123);
    assert(ST_R16(p,6)==10 && ST_R16(p,10)==0xA5A5u);
    st_ov000_02089FE4(p,10,5,123);
    assert(ST_R16(p,6)==10 && ST_R16(p,10)==5 && ST_R32(p,12)==123);
    ST_W16(p,6,0xFFFF);
    st_ov000_02089FE4(p,0,7,456);
    assert(ST_R16(p,6)==0 && ST_R16(p,10)==7 && ST_R32(p,12)==456);
    groups++;

    /* 17: on key change reset counter, otherwise accumulate modulo 2^16. */
    reset(); ST_W32(p,0,10); ST_W16(p,4,100);
    st_ov000_0208E770(p,10,5);
    assert(ST_R16(p,4)==105 && ST_R16(p,6)==15);
    st_ov000_0208E770(p,11,3);
    assert(ST_R32(p,0)==11 && ST_R16(p,4)==3 && ST_R16(p,6)==15);
    groups++;

    /* 18: five-word object reset sentinels. */
    reset(); st_ov000_02096C7C(p);
    assert(ST_R32(p,0)==0 && ST_R32(p,4)==UINT32_MAX);
    assert(ST_R32(p,8)==UINT32_MAX && ST_R32(p,12)==UINT32_MAX);
    assert(ST_R32(p,16)==0 && p[20]==0xA5);
    groups++;

    /* 19: nested byte offset, pointer return truncation on host. */
    reset();
    assert(st_ov000_020A2B0C(p,0xDCA5u)==low_ptr(p+0x100u));
    assert(ST_R16(p,0x170)==0xDCA5u && p[0x16F]==0xA5);
    groups++;

    /* 20: presence -> sixteen, absence -> zero. */
    reset(); ST_W32(p,12,0);
    assert(st_ov000_020A3950(p)==0);
    ST_W32(p,12,5);
    assert(st_ov000_020A3950(p)==16);
    groups++;

    /* 21: signed-positive 32-bit field. */
    reset(); ST_W32(p,312,0);
    assert(st_ov000_020A44D0(p)==0);
    ST_W32(p,312,1); assert(st_ov000_020A44D0(p)==1);
    ST_W32(p,312,UINT32_MAX); assert(st_ov000_020A44D0(p)==0);
    groups++;

    /* 22: compare short to 96 including negatives and equality. */
    reset(); ST_W16(p,30,0xFFFF);
    assert(st_ov000_020A4B40(p)==1);
    ST_W16(p,30,95); assert(st_ov000_020A4B40(p)==1);
    ST_W16(p,30,96); assert(st_ov000_020A4B40(p)==0);
    groups++;

    /* 23: clear seven fields and leave padding alone. */
    reset(); st_ov000_020A6B70(p);
    assert(ST_R32(p,0)==0 && ST_R32(p,4)==0 && ST_R32(p,8)==0);
    assert(p[12]==0 && p[13]==0 && p[14]==0xA5);
    assert(ST_R32(p,24)==0 && ST_R32(p,28)==0 && p[32]==0xA5);
    groups++;

    /* 24: saturating 32-bit accumulation. */
    reset(); ST_W32(p,4,10);
    st_ov000_020A7764(p,20); assert(ST_R32(p,4)==30);
    st_ov000_020A7764(p,UINT32_MAX); assert(ST_R32(p,4)==UINT32_MAX);
    st_ov000_020A7764(p,1); assert(ST_R32(p,4)==UINT32_MAX);
    groups++;

    /* 25: table address with six-byte stride, no table dereference. */
    assert(st_ov000_0208AED0(0)==0x020ace0cu);
    assert(st_ov000_0208AED0(3)==0x020ace1eu);
    groups++;

    /* 26: table address with 28-byte stride, no table dereference. */
    assert(st_ov000_020A7880(0)==0x020af7d4u);
    assert(st_ov000_020A7880(3)==0x020af828u);
    groups++;

    assert(groups==26);
    puts("PASS: 26 distinct semantic regression groups for 26 C research candidates");
    puts("NOT PROVEN: original ROM byte matches, DS runtime equivalence, or CodeWarrior");
    return 0;
}
