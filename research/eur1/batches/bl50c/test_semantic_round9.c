/*
 * Host semantic smoke checks for the round-nine *hypotheses*.
 * These exercise boundary cases and memory effects, not matching against ROM code.
 *
 * clang -std=c11 -O1 -g -fsanitize=address,undefined \
 *   research/eur1/batches/bl50c/test_semantic_round9.c -o /tmp/st_round9_test
 * /tmp/st_round9_test
 */
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "semantic_candidates_round9.c"

int main(void) {
    union { uint32_t align; uint8_t raw[512]; } object;
    memset(&object, 0, sizeof object);
    /* Signature/header read from arm9. */
    assert(st_arm9_02014704(object.raw) == 0);
    *(uint32_t *)(object.raw) = 0x554E5348u;
    *(uint32_t *)(object.raw+36) = 0x12345678u;
    assert(st_arm9_02014704(object.raw) == 0x12345678u);
    assert(st_arm9_02014704(NULL) == 0);
    /* Paired fields: both nonzero or both zero. */
    st_arm9_0202CE2C(object.raw, 7, 9);
    assert(READ32(object.raw,84) == 7 && READ32(object.raw,88) == 9);
    st_arm9_0202CE2C(object.raw, 7, 0);
    assert(READ32(object.raw,84) == 0 && READ32(object.raw,88) == 0);
    st_arm9_0202CE2C(object.raw, 0, 9);
    assert(READ32(object.raw,84) == 0 && READ32(object.raw,88) == 0);
    /* Signed clamping and indexed halfword at +224. */
    *(uint32_t *)(object.raw+256) = 2;
    *(uint16_t *)(object.raw+224) = 101;
    *(uint16_t *)(object.raw+226) = 102;
    *(uint16_t *)(object.raw+228) = 103;
    *(uint32_t *)(object.raw+272) = 0;
    assert(st_ov003_020B7E2C(object.raw)==101);
    *(uint32_t *)(object.raw+272) = 2;
    assert(st_ov003_020B7E2C(object.raw)==102);
    *(uint32_t *)(object.raw+272) = 99;
    assert(st_ov003_020B7E2C(object.raw)==103);
    /* Mode reducer. */
    uint32_t out=100;
    st_ov026_020FC9C0(&out, 2, 5); assert(out==2);
    st_ov026_020FC9C0(&out, 3, 5); assert(out==1);
    st_ov026_020FC9C0(&out, 1, 5); assert(out==3);
    st_ov026_020FC9C0(&out, 4, 5); assert(out==0);
    st_ov026_020FC9C0(&out, 2, 2); assert(out==0);
    /* Mode 2 accepts signed <= 1, not > 1. */
    *(uint16_t *)(object.raw+108) = 1;
    assert(st_ov090_02170E18(object.raw)==1);
    *(uint16_t *)(object.raw+108) = 2;
    *(int16_t *)(object.raw+72) = -2;
    assert(st_ov090_02170E18(object.raw)==1);
    *(int16_t *)(object.raw+72) = 1;
    assert(st_ov090_02170E18(object.raw)==1);
    *(int16_t *)(object.raw+72) = 2;
    assert(st_ov090_02170E18(object.raw)==0);
    *(uint16_t *)(object.raw+108) = 3;
    assert(st_ov090_02170E18(object.raw)==0);
    /* History shift and counter. */
    uint32_t state[3]={7,0,1};
    st_ov092_0217A7E4(state,7);
    assert(state[0]==7 && state[1]==7 && state[2]==2);
    st_ov092_0217A7E4(state,4);
    assert(state[0]==4 && state[1]==7 && state[2]==0);
    /* Volatile bit access, bit range guard. */
    *(uint32_t *)(object.raw+172)=0x80000001u;
    *(uint32_t *)(object.raw+176)=0x80000002u;
    assert(st_ov000_020816C4(object.raw,0)==1);
    assert(st_ov000_020816C4(object.raw,31)==1);
    assert(st_ov000_020816C4(object.raw,32)==0);
    assert(st_ov000_020816FC(object.raw,1)==1);
    assert(st_ov000_020816FC(object.raw,0)==0);
    /* Indexed word array and write-order flag. */
    *(uint32_t *)(object.raw+12)=77;
    *(uint32_t *)(object.raw+20)=88;
    assert(st_ov000_0207749C(object.raw, UINT32_MAX, 0)==77);
    assert(st_ov000_0207749C(object.raw,0,0)==88);
    st_ov000_02072FF0(object.raw,2,0xA511u);
    assert(*(uint16_t *)(object.raw+4)==0xA511u && object.raw[16]==1);
    /* Word-fill, copy and returned advanced source. */
    uint32_t target[4]={0}, input[4]={11,22,33,44};
    assert(st_arm9_02028C4C(0xDEADBEEFu,target,12)==0xDEADBEEFu);
    assert(target[0]==0xDEADBEEFu && target[1]==0xDEADBEEFu && target[2]==0xDEADBEEFu && target[3]==0);
    assert(st_arm9_02028C60(input,target,12)==input+3);
    assert(target[0]==11 && target[1]==22 && target[2]==33);
    puts("PASS: 11 host semantic test groups (research candidates, not byte matches)");
}
