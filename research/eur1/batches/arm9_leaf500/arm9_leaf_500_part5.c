/* Spirit Tracks EUR Rev 1 (BKIP): research C leaf functions, part 5/5. */
/* Every function has a direct ARM BL-reference; signatures/types remain provisional. */
/* 32-bit register-state translation. Standalone compiler equality is separately marked. */
/* NO PC port, original C++ class recovery, or official DS build integration. */
#include <stdint.h>

/* original module: 90, addr: 0x02165B64, 28 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov090_02165B64(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02177100u; r1 = 0x02177120u; r0 = *((uint32_t*)(uintptr_t)(r0 + (48u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (r1)); V = (((r0 ^ (r1)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 90, addr: 0x021687BC, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, conditional C with empty barrier (round 24). */
uint32_t st_ov090_021687BC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x400u)); __asm__ __volatile__("" : "+r"(r0));  r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 40u))); __asm__ __volatile__("" : "+r"(r1));  { uint64_t z = (uint64_t)r1 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x2u)); V = (((r1 ^ (0x2u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = (0x3u); } if (Z) { *((uint16_t*)(uintptr_t)(r0 + 40u)) = (uint16_t)r1; } return r0; }

/* original module: 90, addr: 0x0216CED4, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov090_0216CED4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x200u)); r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 28u))); r1 = 0x0217720cu; r2 = (r2 | (0x2u)); *((uint16_t*)(uintptr_t)(r0 + 28u)) = (uint16_t)r2; r0 = *((uint8_t*)(uintptr_t)(r1 + (0u))); r0 = (r0 + (0x1u)); *((uint8_t*)(uintptr_t)(r1 + (0u))) = (uint8_t)r0; return r0; }

/* original module: 90, addr: 0x02170EF4, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov090_02170EF4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 108u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x2u)); V = (((r0 ^ (0x2u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = 0x0000059au; } if (!Z) { r0 = (0x400u); } return r0; }

/* original module: 91, addr: 0x0216A4B0, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov091_0216A4B0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09bcu; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); return r0; }

/* original module: 91, addr: 0x0216F1B4, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov091_0216F1B4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x02178ec0u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 91, addr: 0x02175828, 12 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
void st_ov091_02175828(volatile unsigned int *obj,
                             unsigned int first, unsigned int second) {
    obj[28] = first;
    obj[30] = second;
}

/* original module: 92, addr: 0x02168B54, 20 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, conditional C with empty barrier (round 24). */
uint32_t st_ov092_02168B54(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) {
uint32_t r12 = 0;
 r0 = (r0 + (0x100u)); __asm__ __volatile__("" : "+r"(r0));  r2 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 8u))); uint32_t cmp_lhs = r2, cmp_rhs = r1; unsigned Z = (cmp_lhs == cmp_rhs); unsigned C = (cmp_lhs >= cmp_rhs); unsigned GE = ((int32_t)cmp_lhs >= (int32_t)cmp_rhs); if ((!GE)) { *((uint16_t*)(uintptr_t)(r0 + 8u)) = (uint16_t)r1; }
return r0;
}

/* original module: 92, addr: 0x0216922C, 52 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov092_0216922C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x0u); r1 = (0x300u); r2 = (0x80u); *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 8u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 10u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 12u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 14u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 16u)) = (uint16_t)r3; return r0; }

/* original module: 92, addr: 0x0216F4AC, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov092_0216F4AC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (12u))); r0 = 0xfffb7800u; { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N != V)) { r0 = (0x1u); } if ((N == V)) { r0 = (0x0u); } return r0; }

/* original module: 92, addr: 0x0216F5FC, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov092_0216F5FC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0d88u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 92, addr: 0x0217242C, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov092_0217242C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (412u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x6u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x6u)); V = (((r0 ^ (0x6u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 92, addr: 0x02172440, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov092_02172440(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (412u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x2u)); V = (((r0 ^ (0x2u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!C || Z)) { r0 = (0x1u); } if ((C && !Z)) { r0 = (0x0u); } return r0; }

/* original module: 92, addr: 0x021738A8, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
uint32_t st_ov092_021738A8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (120u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r1)); V = (((r2 ^ (r1)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r2 = (0xau); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (120u))) = (uint32_t)r1; } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (124u))) = (uint32_t)r2; } return r0; }

/* original module: 92, addr: 0x02177DD8, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: instruction SHA256 BYTE-EXACT, +4-byte PC-LDR literal (round 23); full section differs. */
uint32_t st_ov092_02177DD8(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) {
uint32_t r12=0;
r1 = 0x0217e098u;
__asm__ __volatile__("" : "+r"(r1));
r2 = (0x0u);
*((uint32_t*)(uintptr_t)(r1 + (4u))) = (uint32_t)r2;
return r0;
}

/* original module: 92, addr: 0x02178618, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: instruction SHA256 BYTE-EXACT, +4-byte PC-LDR literal (round 23); full section differs. */
uint32_t st_ov092_02178618(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) {
uint32_t r12=0;
r1 = 0x0217e0e8u;
__asm__ __volatile__("" : "+r"(r1));
r2 = (0x0u);
*((uint32_t*)(uintptr_t)(r1 + (4u))) = (uint32_t)r2;
return r0;
}

/* original module: 92, addr: 0x0217A278, 16 bytes, BL refs: 11 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT (round 20). */
uint32_t st_ov092_0217A278(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t value = *(uint32_t *)(uintptr_t)(r0 + 36u);
    value += 2u;
    /* Empty compiler-only barrier: preserve separate ARM ADD and AND. */
    __asm__ __volatile__("" : "+r"(value));
    return value & 3u;
}

/* original module: 93, addr: 0x0216C02C, 36 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_0216C02C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (44u))); r2 = (r0 + (0x24u)); r2 = (r3 - (r2)); r2 = (r2 + ((r2 >> 31))); { uint64_t z = (uint64_t)r1 - (uint64_t)(((uint32_t)((int32_t)r2 >> 1))); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (((uint32_t)((int32_t)r2 >> 1)))); V = (((r1 ^ (((uint32_t)((int32_t)r2 >> 1)))) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r0 = (r0 + ((r1 << 1))); } if (!C) { r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 36u))); } if (C) { r0 = (0x0u); } return r0; }

/* original module: 93, addr: 0x0216D5AC, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_0216D5AC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (72u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x1u)); V = (((r1 ^ (0x1u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = *((uint8_t*)(uintptr_t)(r0 + (297u))); } if (!Z) { r0 = (0x1u); } return r0; }

/* original module: 93, addr: 0x0216E420, 24 bytes, BL refs: 8 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_0216E420(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (192u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); } if (!Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 93, addr: 0x0216F680, 44 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_0216F680(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0d70u; r2 = (0x0u); *((uint8_t*)(uintptr_t)(r0 + (305u))) = (uint8_t)r2; r0 = *((uint32_t*)(uintptr_t)(r1 + (0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = (r0 + (0x100u)); } if (!Z) { r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 218u))); } if (!Z) { r0 = 0x0000fffdu; } if (!Z) { r0 = (r2 & (r0)); } if (!Z) { *((uint16_t*)(uintptr_t)(r1 + 218u)) = (uint16_t)r0; } return r0; }

/* original module: 93, addr: 0x0216F6B4, 20 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_0216F6B4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint8_t*)(uintptr_t)(r0 + (305u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0xau); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0xau)); V = (((r0 ^ (0xau)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (C) { r0 = (0x1u); } if (!C) { r0 = (0x0u); } return r0; }

/* original module: 93, addr: 0x021718C0, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_021718C0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (32u))); r1 = 0x02177ebcu; r0 = (0xcu); r0 = (r2 * r0 + r1); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 8u))); { uint32_t z = r0 & (0x2u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 93, addr: 0x021718E8, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_021718E8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (32u))); r1 = 0x02177ebcu; r0 = (0xcu); r0 = (r2 * r0 + r1); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 8u))); { uint32_t z = r0 & (0x4u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 93, addr: 0x02171910, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_02171910(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (32u))); r1 = 0x02177ebcu; r0 = (0xcu); r0 = (r2 * r0 + r1); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 8u))); { uint32_t z = r0 & (0x10u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 93, addr: 0x0217199C, 36 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_0217199C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (32u))); r1 = 0x02177ebcu; r0 = (0xcu); r0 = (r2 * r0 + r1); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 8u))); { uint32_t z = r0 & (0x1000u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 93, addr: 0x021719C4, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_021719C4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (72u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1u)); V = (((r0 ^ (0x1u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 93, addr: 0x021719DC, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_021719DC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (72u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1u)); V = (((r0 ^ (0x1u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 93, addr: 0x021753BC, 16 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov093_021753BC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 * r1); r0 = (r1 + (0x800u)); r0 = (((uint32_t)((int32_t)r0 >> 12))); return r0; }

/* original module: 94, addr: 0x0216F6C4, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov094_0216F6C4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r1 = (0x1u); *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r2; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; return r0; }

/* original module: 96, addr: 0x0217B558, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov096_0217B558(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (r0 + (0x300u)); r12 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 58u))); r1 = 0x0000fffdu; r3 = (0x0u); r1 = (r12 & (r1)); *((uint16_t*)(uintptr_t)(r2 + 58u)) = (uint16_t)r1; *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r2 + 44u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r2 + 42u)) = (uint16_t)r3; return r0; }

/* original module: 96, addr: 0x0217D8F8, 24 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_ov096_0217D8F8(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if ((((*((unsigned char*)((unsigned char*)(a0) + (321))))) != (0u))) { *((unsigned int*)((unsigned char*)(a0) + (12))) = (((((*((unsigned char*)((unsigned char*)(a0) + (321))))) != (0u)) ? ((((((*((unsigned char*)((unsigned char*)(a0) + (321))))) != (0u)) ? (*((unsigned int*)((unsigned char*)(a0) + (12)))) : (*((unsigned char*)((unsigned char*)(a0) + (321))))) + 1u)) : (((((*((unsigned char*)((unsigned char*)(a0) + (321))))) != (0u)) ? (*((unsigned int*)((unsigned char*)(a0) + (12)))) : (*((unsigned char*)((unsigned char*)(a0) + (321)))))))); } }

/* original module: 96, addr: 0x0217DB3C, 52 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov096_0217DB3C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x0u); r2 = (0x2u); r1 = 0x0217e5ecu; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (316u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r1 + 0u)) = (uint16_t)r3; *((uint8_t*)(uintptr_t)(r0 + (320u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r0 + (322u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r0 + (26u))) = (uint8_t)r3; *((uint32_t*)(uintptr_t)(r0 + (28u))) = (uint32_t)r3; return r0; }

/* original module: arm9, addr: 0x02001F30, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_arm9_02001F30(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r1 = (0x0u); *((volatile uint32_t*)(uintptr_t)(object + (4u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (0u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (12u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (8u))) = (uint32_t)r1;;
}

/* original module: arm9, addr: 0x02001FA4, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02001FA4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (8u))); r1 = *((uint32_t*)(uintptr_t)(r0 + (12u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r1)); V = (((r2 ^ (r1)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N != V)) { r1 = (r2 + (0x1u)); } if ((N != V)) { *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; } return r0; }

/* original module: arm9, addr: 0x02001FBC, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02001FBC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (8u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (12u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N == V)) { r0 = (0x1u); } if ((N != V)) { r0 = (0x0u); } return r0; }

/* original module: arm9, addr: 0x02002D88, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT (round 16). */
uint32_t st_arm9_02002D88(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) {
uint32_t r12 = 0;
 r2 = *((volatile uint32_t*)(uintptr_t)(r0 + (0u))); uint32_t cmp_lhs = r2, cmp_rhs = 0x0u; unsigned Z = (cmp_lhs == cmp_rhs); unsigned C = (cmp_lhs >= cmp_rhs); unsigned GE = ((int32_t)cmp_lhs >= (int32_t)cmp_rhs); if (!Z) { r0 = *((volatile uint32_t*)(uintptr_t)(r0 + (0u))); } if (!Z) { *((volatile uint8_t*)(uintptr_t)(r0 + (64u))) = (uint8_t)r1; }
return r0;
}

/* original module: arm9, addr: 0x02003740, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: instruction SHA256 BYTE-EXACT, +4-byte PC-LDR literal (round 23); full section differs. */
void st_arm9_02003740(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) {
uint32_t r12=0;
r1 = 0x02045cccu;
r0 = (~(r0));
__asm__ __volatile__("" : "+r"(r0));
r2 = *((uint32_t*)(uintptr_t)(r1 + (0u)));
r0 = (r2 & (r0));
*((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r0;
}

/* original module: arm9, addr: 0x020037A0, 28 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020037A0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x02045cccu; r2 = (0x1u); r0 = (~((r2 << (r0&31u)))); r2 = *((uint32_t*)(uintptr_t)(r1 + (4u))); r0 = (r2 & (r0)); *((uint32_t*)(uintptr_t)(r1 + (4u))) = (uint32_t)r0; return r0; }

/* original module: arm9, addr: 0x02003A3C, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02003A3C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0200u; r2 = *((uint32_t*)(uintptr_t)(r1 + (0u))); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r0; r0 = (r2); return r0; }

/* original module: arm9, addr: 0x02003A54, 12 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02003A54(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e0200u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); return r0; }

/* original module: arm9, addr: 0x02003DF8, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02003DF8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0200u; r1 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r2 = *((uint32_t*)(uintptr_t)(r1 + (132u))); r1 = *((uint32_t*)(uintptr_t)(r2 + (8u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (r1)); V = (((r0 ^ (r1)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (C) { r0 = (0x0u); } if (!C) { r0 = (r2 + ((r0 << 4))); } if (!C) { r0 = *((uint32_t*)(uintptr_t)(r0 + (12u))); } return r0; }

/* original module: arm9, addr: 0x02003E20, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02003E20(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0200u; r1 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r2 = *((uint32_t*)(uintptr_t)(r1 + (132u))); r1 = *((uint32_t*)(uintptr_t)(r2 + (8u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (r1)); V = (((r0 ^ (r1)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (C) { r0 = (0x0u); } if (!C) { r0 = (r2 + ((r0 << 4))); } if (!C) { r0 = *((uint32_t*)(uintptr_t)(r0 + (16u))); } return r0; }

/* original module: arm9, addr: 0x02003F30, 36 bytes, BL refs: 14 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02003F30(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0200u; r1 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r2 = *((uint32_t*)(uintptr_t)(r1 + (132u))); r1 = *((uint32_t*)(uintptr_t)(r2 + (8u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (r1)); V = (((r0 ^ (r1)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (C) { r0 = (0x0u); } if (!C) { r0 = (r2 + ((r0 << 4))); } if (!C) { r0 = *((uint32_t*)(uintptr_t)(r0 + (20u))); } return r0; }

/* original module: arm9, addr: 0x02003F58, 24 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02003F58(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x027e0200u; r2 = *((uint32_t*)(uintptr_t)(r2 + (0u))); r2 = *((uint32_t*)(uintptr_t)(r2 + (132u))); r0 = (r2 + ((r0 << 4))); *((uint32_t*)(uintptr_t)(r0 + (20u))) = (uint32_t)r1; return r0; }

/* original module: arm9, addr: 0x020051EC, 44 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020051EC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (332u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = (0x0u); } if (!Z) { *((uint32_t*)(uintptr_t)(r2 + (0u))) = (uint32_t)r1; } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (332u))) = (uint32_t)r1; } r1 = *((uint32_t*)(uintptr_t)(r0 + (272u))); r1 = (r1 & ~(0x1u)); r1 = (r1 & ~(0x4u)); r1 = (r1 & ~(0x2u)); *((uint32_t*)(uintptr_t)(r0 + (272u))) = (uint32_t)r1; return r0; }

/* original module: arm9, addr: 0x020070C4, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020070C4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 12u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: arm9, addr: 0x02007350, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
uint32_t st_arm9_02007350(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 8u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = (r0 + ((r1 << 4))); return r0; }

/* original module: arm9, addr: 0x02007360, 16 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
uint32_t st_arm9_02007360(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 10u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = (r0 + ((r1 << 4))); return r0; }

/* original module: arm9, addr: 0x020075E0, 12 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
uint32_t st_arm9_020075E0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); return r0; }

/* original module: arm9, addr: 0x020092EC, 12 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
unsigned int st_arm9_020092EC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { *((unsigned int*)((unsigned char*)((a0 + ((a1) << 2))) + (8))) = (a2); return (a0 + ((a1) << 2)); }

/* original module: arm9, addr: 0x0200990C, 52 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
uint32_t st_arm9_0200990C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r1 + (0u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (24u))) = (uint32_t)r2; } r2 = *((uint32_t*)(uintptr_t)(r1 + (4u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (28u))) = (uint32_t)r2; } r2 = *((uint32_t*)(uintptr_t)(r1 + (8u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (12u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (32u))) = (uint32_t)r2; } { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (36u))) = (uint32_t)r1; } return r0; }

/* original module: arm9, addr: 0x0200B5D0, 20 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_arm9_0200B5D0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if (((a1) != (0u))) { *((unsigned int*)((unsigned char*)(a0) + (8))) = (a1); } if (((a2) != (0u))) { *((unsigned int*)((unsigned char*)(a0) + (24))) = (a2); } }

/* original module: arm9, addr: 0x02013ADC, 44 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02013ADC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x02043750u; r2 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 0u))); r3 = *((uint8_t*)(uintptr_t)(r3 + ((r1 << 1)))); { uint64_t z = (uint64_t)r2 - (uint64_t)(r3); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r3)); V = (((r2 ^ (r3)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N != V)) { *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r3; } r3 = 0x02043751u; r2 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 2u))); r1 = *((uint8_t*)(uintptr_t)(r3 + ((r1 << 1)))); { uint64_t z = (uint64_t)r2 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r1)); V = (((r2 ^ (r1)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N != V)) { *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r1; } return r0; }

/* original module: arm9, addr: 0x02013B98, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02013B98(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027fffa8u; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 0u))); r0 = (r0 & (0x8000u)); r0 = (((uint32_t)((int32_t)r0 >> 15))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1u)); V = (((r0 ^ (0x1u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: arm9, addr: 0x02013E18, 28 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02013E18(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (196u))); { uint64_t z = (uint64_t)r3 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r3 >= (0x0u)); V = (((r3 ^ (0x0u)) & (r3 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (196u))) = (uint32_t)r1; } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (200u))) = (uint32_t)r2; } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: arm9, addr: 0x020143F0, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020143F0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027fffa8u; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 0u))); r0 = (r0 & (0x8000u)); r0 = (((uint32_t)((int32_t)r0 >> 15))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1u)); V = (((r0 ^ (0x1u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: arm9, addr: 0x020147A8, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020147A8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02043e50u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: arm9, addr: 0x020147C4, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020147C4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02043e50u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: arm9, addr: 0x0201667C, 12 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_arm9_0201667C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { *((unsigned int*)((unsigned char*)(a0) + (0))) = (a0); *((unsigned int*)((unsigned char*)(a0) + (4))) = (a0); }

/* original module: arm9, addr: 0x02019514, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
uint32_t st_arm9_02019514(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (3564u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = *((uint8_t*)(uintptr_t)(r0 + (336u))); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: arm9, addr: 0x0201BE08, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0201BE08(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x0u); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; } if (Z) { r0 = (0x1u); } return r0; }

/* original module: arm9, addr: 0x0201BE20, 12 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_arm9_0201BE20(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { *((unsigned char*)((unsigned char*)(a0) + (4))) = (1u); }

/* original module: arm9, addr: 0x0201E8D4, 36 bytes, BL refs: 50 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, empty compiler-barrier C (round 23). */
void st_arm9_0201E8D4(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) {
uint32_t r12=0;
r2 = *((volatile uint32_t*)(uintptr_t)(r1 + (20u)));
__asm__ __volatile__("" : "+r"(r2));
r1 = *((volatile uint32_t*)(uintptr_t)(r1 + (16u)));
__asm__ __volatile__("" : "+r"(r1));
r2 = (r2 + (0x800u));
__asm__ __volatile__("" : "+r"(r2));
r1 = (r1 + (0x800u));
__asm__ __volatile__("" : "+r"(r1));
r2 = (((uint32_t)((int32_t)r2 >> 12)));
__asm__ __volatile__("" : "+r"(r2));
r1 = (((uint32_t)((int32_t)r1 >> 12)));
__asm__ __volatile__("" : "+r"(r1));
*((volatile uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1;
*((volatile uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r2;
}

/* original module: arm9, addr: 0x0201EAA0, 20 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, empty compiler-barrier C (round 23). */
uint32_t st_arm9_0201EAA0(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) {
uint32_t r12=0;
r0 = *((uint32_t*)(uintptr_t)(r0 + (16u)));
r0 = (r0 + (0x800u));
r0 = (((uint32_t)((int32_t)r0 >> 12)));
__asm__ __volatile__("" : "+r"(r0));
r0 = (r0 & (0xffu));
return r0;
}

/* original module: arm9, addr: 0x02020268, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: instruction SHA256 BYTE-EXACT, +4-byte PC-LDR literal (round 23); full section differs. */
void st_arm9_02020268(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) {
uint32_t r12=0;
r3 = 0x020443e8u;
r2 = (0x0u);
__asm__ __volatile__("" : "+r"(r2));
*((volatile uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r3;
*((volatile uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r2;
*((volatile uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2;
*((volatile uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1;
*((volatile uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r1;
*((volatile uint16_t*)(uintptr_t)(r0 + 20u)) = (uint16_t)r2;
*((volatile uint16_t*)(uintptr_t)(r0 + 22u)) = (uint16_t)r2;
*((volatile uint8_t*)(uintptr_t)(r0 + (24u))) = (uint8_t)r2;
}

/* original module: arm9, addr: 0x02020DF8, 20 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
uint32_t st_arm9_02020DF8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 32u))); { uint32_t z = r1 & (0x1u); Z = (z==0); N = (z>>31); } if (!Z) { r1 = (0x1u); } if (!Z) { *((uint8_t*)(uintptr_t)(r0 + (948u))) = (uint8_t)r1; } return r0; }

/* original module: arm9, addr: 0x0202349C, 48 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0202349C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x04000004u; { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 0u))); if (!Z) { r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 0u))); } r0 = (r0 & (0x10u)); if (!Z) { r1 = (r1 | (0x10u)); } if (!Z) { *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r1; } if (Z) { r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 0u))); } if (Z) { r1 = 0x0000ffefu; } if (Z) { r1 = (r2 & (r1)); } if (Z) { *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r1; } return r0; }

/* original module: arm9, addr: 0x02023548, 60 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02023548(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x0204e664u; r1 = 0x0204453cu; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 0u))); r0 = (0x1u); *((uint16_t*)(uintptr_t)(r1 + 0u)) = (uint16_t)r0; r1 = (0x4000000u); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = *((uint32_t*)(uintptr_t)(r1 + (0u))); } if (!Z) { r0 = (r0 & ~(0x30000u)); } if (!Z) { r0 = (r0 | ((r2 << 16))); } if (!Z) { *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r0; } if (Z) { r0 = *((uint32_t*)(uintptr_t)(r1 + (0u))); } if (Z) { r0 = (r0 | (0x10000u)); } if (Z) { *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r0; } return r0; }

/* original module: arm9, addr: 0x020235F4, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020235F4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x04001000u; r1 = *((uint32_t*)(uintptr_t)(r2 + (0u))); r1 = (r1 & ~(0x7u)); r0 = (r1 | (r0)); *((uint32_t*)(uintptr_t)(r2 + (0u))) = (uint32_t)r0; return r0; }

/* original module: arm9, addr: 0x020244C4, 48 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020244C4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x04000008u; r0 = (0x4000000u); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = (r0 & (0x38000000u)); r0 = ((r0 >> 27)); r1 = (r1 & (0x1f00u)); r0 = ((r0 << 16)); r1 = (((uint32_t)((int32_t)r1 >> 8))); r0 = (r0 + (0x6000000u)); r0 = (r0 + ((r1 << 11))); return r0; }

/* original module: arm9, addr: 0x02024518, 48 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02024518(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x0400000au; r0 = (0x4000000u); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = (r0 & (0x38000000u)); r0 = ((r0 >> 27)); r1 = (r1 & (0x1f00u)); r0 = ((r0 << 16)); r1 = (((uint32_t)((int32_t)r1 >> 8))); r0 = (r0 + (0x6000000u)); r0 = (r0 + ((r1 << 11))); return r0; }

/* original module: arm9, addr: 0x0202475C, 48 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0202475C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x04000008u; r0 = (0x4000000u); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = (r0 & (0x7000000u)); r0 = ((r0 >> 24)); r1 = (r1 & (0x3cu)); r0 = ((r0 << 16)); r1 = (((uint32_t)((int32_t)r1 >> 2))); r0 = (r0 + (0x6000000u)); r0 = (r0 + ((r1 << 14))); return r0; }

/* original module: arm9, addr: 0x020247B0, 48 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020247B0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x0400000au; r0 = (0x4000000u); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = (r0 & (0x7000000u)); r0 = ((r0 >> 24)); r1 = (r1 & (0x3cu)); r0 = ((r0 << 16)); r1 = (((uint32_t)((int32_t)r1 >> 2))); r0 = (r0 + (0x6000000u)); r0 = (r0 + ((r1 << 14))); return r0; }

/* original module: arm9, addr: 0x02024ED8, 40 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02024ED8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x04000600u; r1 = *((uint32_t*)(uintptr_t)(r2 + (0u))); { uint32_t z = r1 & (0x4000u); Z = (z==0); N = (z>>31); } if (Z) { r1 = *((uint32_t*)(uintptr_t)(r2 + (0u))); } if (!Z) { r0 = (~(0x0u)); } if (Z) { r1 = (r1 & (0x1f00u)); } if (Z) { r1 = ((r1 >> 8)); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; } if (Z) { r0 = (0x0u); } return r0; }

/* original module: arm9, addr: 0x02024F04, 40 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02024F04(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x04000600u; r1 = *((uint32_t*)(uintptr_t)(r2 + (0u))); { uint32_t z = r1 & (0x4000u); Z = (z==0); N = (z>>31); } if (Z) { r1 = *((uint32_t*)(uintptr_t)(r2 + (0u))); } if (!Z) { r0 = (~(0x0u)); } if (Z) { r1 = (r1 & (0x2000u)); } if (Z) { r1 = ((r1 >> 13)); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; } if (Z) { r0 = (0x0u); } return r0; }

/* original module: arm9, addr: 0x02026390, 40 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02026390(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x04000208u; r1 = (0x0u); r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 0u))); *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r1; r1 = *((uint32_t*)(uintptr_t)(r3 + (8u))); *((uint32_t*)(uintptr_t)(r3 + (8u))) = (uint32_t)r0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 0u))); r0 = (r1); *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r2; return r0; }

/* original module: arm9, addr: 0x020263BC, 44 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020263BC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x04000208u; r1 = (0x0u); r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 0u))); *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r1; r1 = *((uint32_t*)(uintptr_t)(r3 + (8u))); r0 = (r1 | (r0)); *((uint32_t*)(uintptr_t)(r3 + (8u))) = (uint32_t)r0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 0u))); r0 = (r1); *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r2; return r0; }

/* original module: arm9, addr: 0x020263EC, 44 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020263EC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = 0x04000208u; r2 = (0x0u); r3 = (uint32_t)(*((uint16_t*)(uintptr_t)(r12 + 0u))); r1 = (~(r0)); *((uint16_t*)(uintptr_t)(r12 + 0u)) = (uint16_t)r2; r0 = *((uint32_t*)(uintptr_t)(r12 + (8u))); r1 = (r0 & (r1)); *((uint32_t*)(uintptr_t)(r12 + (8u))) = (uint32_t)r1; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r12 + 0u))); *((uint16_t*)(uintptr_t)(r12 + 0u)) = (uint16_t)r3; return r0; }

/* original module: arm9, addr: 0x0202641C, 40 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0202641C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x04000208u; r1 = (0x0u); r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 0u))); *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r1; r1 = *((uint32_t*)(uintptr_t)(r3 + (12u))); *((uint32_t*)(uintptr_t)(r3 + (12u))) = (uint32_t)r0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 0u))); r0 = (r1); *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r2; return r0; }

/* original module: arm9, addr: 0x020271D0, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_arm9_020271D0(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r3 = (0x0u); *((volatile uint32_t*)(uintptr_t)(object + (4u))) = (uint32_t)r3; *((volatile uint32_t*)(uintptr_t)(object + (0u))) = (uint32_t)r3; *((volatile uint32_t*)(uintptr_t)(object + (12u))) = (uint32_t)r3; *((volatile uint32_t*)(uintptr_t)(object + (8u))) = (uint32_t)r3; *((volatile uint32_t*)(uintptr_t)(object + (16u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (20u))) = (uint32_t)r2; *((volatile uint32_t*)(uintptr_t)(object + (24u))) = (uint32_t)r3; *((volatile uint32_t*)(uintptr_t)(object + (28u))) = (uint32_t)r3;;
}

/* original module: arm9, addr: 0x020273C8, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_arm9_020273C8(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r1 = (0x0u); *((volatile uint32_t*)(uintptr_t)(object + (4u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (0u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (8u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (12u))) = (uint32_t)r1;;
}

/* original module: arm9, addr: 0x02027568, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02027568(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (140u))); r2 = (0x0u); { uint64_t z = (uint64_t)r3 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r3 >= (0x0u)); V = (((r3 ^ (0x0u)) & (r3 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (136u))) = (uint32_t)r1; } if (!Z) { *((uint32_t*)(uintptr_t)(r3 + (16u))) = (uint32_t)r1; } *((uint32_t*)(uintptr_t)(r1 + (20u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r1 + (16u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (140u))) = (uint32_t)r1; return r0; }

/* original module: arm9, addr: 0x0202758C, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0202758C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r1 + (16u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (20u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (140u))) = (uint32_t)r1; } if (!Z) { *((uint32_t*)(uintptr_t)(r2 + (20u))) = (uint32_t)r1; } { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (136u))) = (uint32_t)r2; } if (!Z) { *((uint32_t*)(uintptr_t)(r1 + (16u))) = (uint32_t)r2; } return r0; }

/* original module: arm9, addr: 0x0202AFC8, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0202AFC8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0xcu); r3 = (r0 * r3); r0 = 0x02050460u; *((uint32_t*)(uintptr_t)(r0 + (r3))) = (uint32_t)r1; r1 = (r0 + (r3)); *((uint32_t*)(uintptr_t)(r1 + (4u))) = (uint32_t)r2; r0 = *((uint8_t*)(uintptr_t)(r1 + (8u))); r0 = (r0 + (0x1u)); *((uint8_t*)(uintptr_t)(r1 + (8u))) = (uint8_t)r0; r0 = (r0 & (0xffu)); return r0; }

/* original module: arm9, addr: 0x0202B6E0, 32 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0202B6E0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x027ffc00u; r3 = (0x1u); r1 = (r2 + ((r1 << 2))); r1 = *((uint32_t*)(uintptr_t)(r1 + (904u))); { uint32_t z = r1 & ((r3 << (r0&31u))); Z = (z==0); N = (z>>31); } if (Z) { r3 = (0x0u); } r0 = (r3); return r0; }

/* original module: arm9, addr: 0x0202CF08, 40 bytes, BL refs: 9 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0202CF08(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r1 = (0xeu); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (28u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (24u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; return r0; }

/* original module: arm9, addr: 0x0202D674, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0202D674(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (28u))); r2 = ((r1 >> 24)); { uint32_t z = r2 & (0x1u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = ((r1 << 8)); } if (!Z) { r0 = ((r0 >> 8)); } if (Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (8u))); } return r0; }

/* original module: arm9, addr: 0x0202F2BC, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0202F2BC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x0205062cu; r0 = *((uint32_t*)(uintptr_t)(r1 + (28u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x0u); } if (Z) { r0 = (0x1u); } if (Z) { *((uint32_t*)(uintptr_t)(r1 + (28u))) = (uint32_t)r0; } return r0; }

/* original module: arm9, addr: 0x0202FDCC, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0202FDCC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x04000304u; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 0u))); { uint32_t z = r0 & (0x1u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: arm9, addr: 0x02031E58, 12 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02031E58(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02050f60u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); return r0; }

/* original module: arm9, addr: 0x0203216C, 48 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0203216C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x04000204u; r2 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 0u))); r1 = (r1 & ~(0xcu)); r1 = (r1 | ((r2 << 2))); *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r1; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 0u))); r2 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r0 = (r1 & ~(0x10u)); r0 = (r0 | ((r2 << 4))); *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r0; return r0; }

/* original module: arm9, addr: 0x02032784, 56 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02032784(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x55555555u; r2 = 0x33333333u; r1 = (r1 & ((r0 >> 1))); r0 = (r0 - (r1)); r1 = (r0 & (r2)); r0 = (r2 & ((r0 >> 2))); r1 = (r1 + (r0)); r0 = 0x0f0f0f0fu; r1 = (r1 + ((r1 >> 4))); r0 = (r1 & (r0)); r0 = (r0 + ((r0 >> 8))); r0 = (r0 + ((r0 >> 16))); r0 = (r0 & (0xffu)); return r0; }

/* original module: arm9, addr: 0x02032DDC, 44 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
uint32_t st_arm9_02032DDC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r2 = *((uint32_t*)(uintptr_t)(r0 + (4u))); } if (!Z) { *((uint8_t*)(uintptr_t)(r2 + (0u))) = (uint8_t)r1; } if (!Z) { r1 = *((uint32_t*)(uintptr_t)(r0 + (0u))); } if (!Z) { r1 = (r1 - (0x1u)); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; } r1 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r1 = (r1 + (0x1u)); *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; return r0; }

/* original module: arm9, addr: 0x020338F0, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_020338F0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (24u))); r1 = *((uint32_t*)(uintptr_t)(r0 + (44u))); r12 = *((uint32_t*)(uintptr_t)(r0 + (28u))); r3 = *((uint32_t*)(uintptr_t)(r0 + (32u))); r1 = (r2 & (r1)); r1 = (r3 - (r1)); *((uint32_t*)(uintptr_t)(r0 + (36u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (40u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (52u))) = (uint32_t)r2; return r0; }

/* original module: arm9, addr: 0x0203BC54, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0203BC54(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (8u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = *((uint8_t*)(uintptr_t)(r0 + (0u))); } if (!Z) { r0 = (r0 & (0x1fu)); } if (Z) { r0 = (0x0u); } r0 = (r0 & (0xffu)); return r0; }

/* original module: arm9, addr: 0x0203CE74, 28 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0203CE74(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x02051ad4u; r12 = *((uint32_t*)(uintptr_t)(r3 + (0u))); *((uint32_t*)(uintptr_t)(r2 + (0u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r2 + (4u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r2 + (8u))) = (uint32_t)r0; *((uint32_t*)(uintptr_t)(r3 + (0u))) = (uint32_t)r2; return r0; }

/* original module: arm9, addr: 0x0204834C, 44 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0204834C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x04000280u; r1 = (0x1u); *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r1; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r3 + (16u))) = (uint32_t)r2; r1 = (0x1000u); *((uint32_t*)(uintptr_t)(r3 + (20u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r3 + (24u))) = (uint32_t)r0; r0 = (r2); *((uint32_t*)(uintptr_t)(r3 + (28u))) = (uint32_t)r0; return r0; }

/* original module: arm9, addr: 0x0204837C, 48 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_0204837C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x040002b0u; { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!Z && N == V)) { r2 = (0x1u); } if ((!Z && N == V)) { *((uint16_t*)(uintptr_t)(r1 + 0u)) = (uint16_t)r2; } if ((!Z && N == V)) { r2 = (0x0u); } if ((!Z && N == V)) { *((uint32_t*)(uintptr_t)(r1 + (8u))) = (uint32_t)r2; } if ((Z || N != V)) { r0 = (0x1u); } if ((Z || N != V)) { *((uint16_t*)(uintptr_t)(r1 + 0u)) = (uint16_t)r0; } if ((Z || N != V)) { r0 = (0x0u); } if ((Z || N != V)) { *((uint32_t*)(uintptr_t)(r1 + (8u))) = (uint32_t)r0; } *((uint32_t*)(uintptr_t)(r1 + (12u))) = (uint32_t)r0; return r0; }

/* original module: arm9, addr: 0x02048404, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_arm9_02048404(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x04000280u; r2 = (0x1u); *((uint16_t*)(uintptr_t)(r3 + 0u)) = (uint16_t)r2; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r3 + (16u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r3 + (20u))) = (uint32_t)r0; *((uint32_t*)(uintptr_t)(r3 + (24u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r3 + (28u))) = (uint32_t)r2; return r0; }
