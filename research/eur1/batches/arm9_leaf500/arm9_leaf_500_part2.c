/* Spirit Tracks EUR Rev 1 (BKIP): research C leaf functions, part 2/5. */
/* Every function has a direct ARM BL-reference; signatures/types remain provisional. */
/* 32-bit register-state translation. Standalone compiler equality is separately marked. */
/* NO PC port, original C++ class recovery, or official DS build integration. */
#include <stdint.h>

/* original module: 0, addr: 0x020A89C8, 12 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A89C8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020afc9cu; r0 = (r1 + ((r0 << 5))); return r0; }

/* original module: 0, addr: 0x020A8EF0, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A8EF0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r3 = *((uint32_t*)(uintptr_t)(r1 + (4u))); r2 = *((uint32_t*)(uintptr_t)(r1 + (8u))); r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (192u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (196u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (200u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (188u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x020A9254, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_ov000_020A9254(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r1 = (0x0u); *((volatile uint32_t*)(uintptr_t)(object + (188u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (192u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (196u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (200u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (212u))) = (uint32_t)r1;;
}

/* original module: 105, addr: 0x02187588, 64 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_ov105_02187588(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r1 = (0x0u); *((volatile uint8_t*)(uintptr_t)(object + (0u))) = (uint8_t)r1; *((volatile uint16_t*)(uintptr_t)(object + 2u)) = (uint16_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (4u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (8u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (12u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (16u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (20u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (24u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (28u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (32u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (36u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (40u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (44u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (48u))) = (uint32_t)r1;;
}

/* original module: 105, addr: 0x02188BCC, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov105_02188BCC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 56u))); r2 = (0x1u); r1 = (0x0u); *((uint16_t*)(uintptr_t)(r0 + 58u)) = (uint16_t)r3; *((uint8_t*)(uintptr_t)(r0 + (66u))) = (uint8_t)r2; *((uint32_t*)(uintptr_t)(r0 + (68u))) = (uint32_t)r1; return r0; }

/* original module: 107, addr: 0x02184E98, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_ov107_02184E98(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r1 = (0xffu); *((volatile uint8_t*)(uintptr_t)(object + (4u))) = (uint8_t)r1; *((volatile uint8_t*)(uintptr_t)(object + (5u))) = (uint8_t)r1; *((volatile uint8_t*)(uintptr_t)(object + (6u))) = (uint8_t)r1; *((volatile uint8_t*)(uintptr_t)(object + (7u))) = (uint8_t)r1;;
}

/* original module: 108, addr: 0x02184C40, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov108_02184C40(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = 0x021860e8u; r3 = 0x020b19a8u; r2 = (0x1u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint8_t*)(uintptr_t)(r0 + (12u))) = (uint8_t)r2; return r0; }

/* original module: 108, addr: 0x02184DD0, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov108_02184DD0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = 0x02186110u; r3 = 0x020b19a8u; r2 = (0x1u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint8_t*)(uintptr_t)(r0 + (12u))) = (uint8_t)r2; return r0; }

/* original module: 111, addr: 0x02184DEC, 12 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov111_02184DEC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x02186018u; r0 = *((uint8_t*)(uintptr_t)(r1 + (r0))); return r0; }

/* original module: 15, addr: 0x020B73E8, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov015_020B73E8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x02157fb8u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 16, addr: 0x020B78D0, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov016_020B78D0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = (0x1u); r1 = (r0 + (0x100u)); r3 = (0x5u); r2 = (0x0u); *((uint8_t*)(uintptr_t)(r0 + (388u))) = (uint8_t)r12; *((uint8_t*)(uintptr_t)(r0 + (138u))) = (uint8_t)r12; *((uint16_t*)(uintptr_t)(r1 + 138u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r1 + 136u)) = (uint16_t)r2; return r0; }

/* original module: 17, addr: 0x020BBAD4, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov017_020BBAD4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02049b80u; r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; return r0; }

/* original module: 17, addr: 0x020C19E0, 44 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov017_020C19E0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint8_t*)(uintptr_t)(r0 + (48u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = *((uint8_t*)(uintptr_t)(r0 + (128u))); } if (Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r1 = *((uint8_t*)(uintptr_t)(r0 + (210u))); } if (Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = *((uint8_t*)(uintptr_t)(r0 + (211u))); } if (Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 18, addr: 0x020C4B98, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov018_020C4B98(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020443d8u; r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 8u)) = (uint16_t)r1; *((uint8_t*)(uintptr_t)(r0 + (10u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (11u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (12u))) = (uint8_t)r1; return r0; }

/* original module: 18, addr: 0x020C55AC, 52 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov018_020C55AC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r12 = 0x020442b4u; r1 = (r2 - (0x1u)); r3 = (0x1u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r0 + 12u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 14u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 16u)) = (uint16_t)r2; *((uint8_t*)(uintptr_t)(r0 + (18u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (19u))) = (uint8_t)r2; return r0; }

/* original module: 19, addr: 0x020CB788, 32 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov019_020CB788(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (28u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x15u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x15u)); V = (((r0 ^ (0x15u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x2u)); V = (((r0 ^ (0x2u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x16u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x16u)); V = (((r0 ^ (0x16u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0xcu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0xcu)); V = (((r0 ^ (0xcu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 19, addr: 0x020CBB50, 44 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov019_020CBB50(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020b62f0u; r2 = *((uint8_t*)(uintptr_t)(r0 + (0u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (536u))); r0 = (0x2700u); r0 = (r2 * r0 + r1); r0 = (r0 + (0xd00u)); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 162u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 19, addr: 0x020CC5EC, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_ov019_020CC5EC(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r2 = (uint32_t)(*((volatile uint16_t*)(uintptr_t)(r1 + 0u))); r1 = (uint32_t)(*((volatile uint16_t*)(uintptr_t)(r1 + 2u))); *((volatile uint16_t*)(uintptr_t)(object + 24u)) = (uint16_t)r2; *((volatile uint16_t*)(uintptr_t)(object + 26u)) = (uint16_t)r1;;
}

/* original module: 19, addr: 0x020CC89C, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov019_020CC89C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (28u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r1)); V = (((r2 ^ (r1)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r2 = (0x1u); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (28u))) = (uint32_t)r1; } if (!Z) { *((uint8_t*)(uintptr_t)(r0 + (32u))) = (uint8_t)r2; } return r0; }

/* original module: 19, addr: 0x020CDC1C, 48 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov019_020CDC1C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x1000u)); r1 = *((uint8_t*)(uintptr_t)(r0 + (110u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = *((uint8_t*)(uintptr_t)(r0 + (1064u))); } if (Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r1 = *((uint8_t*)(uintptr_t)(r0 + (1868u))); } if (Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = *((uint8_t*)(uintptr_t)(r0 + (2672u))); } if (Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 19, addr: 0x020CE870, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov019_020CE870(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020d2508u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 20, addr: 0x020C4954, 24 bytes, BL refs: 51 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020C4954(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020dbec0u; r2 = *((uint32_t*)(uintptr_t)(r1 + (16u))); r2 = (r2 - (0x9u)); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x1u)); V = (((r2 ^ (0x1u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((C && !Z)) { *((uint32_t*)(uintptr_t)(r1 + (40u))) = (uint32_t)r0; } return r0; }

/* original module: 20, addr: 0x020C5DD0, 12 bytes, BL refs: 9 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020C5DD0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020dbec0u; r0 = *((uint32_t*)(uintptr_t)(r0 + (16u))); return r0; }

/* original module: 20, addr: 0x020C70BC, 16 bytes, BL refs: 9 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020C70BC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020df5e4u; r1 = (0x1cu); r0 = (r1 * r0 + r2); return r0; }

/* original module: 20, addr: 0x020C9430, 24 bytes, BL refs: 12 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020C9430(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x48u); r0 = (r1 * r2 + r0); r1 = *((uint8_t*)(uintptr_t)(r0 + (68u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 20, addr: 0x020CC648, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020CC648(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020dbe4cu; r0 = (r0 + (0x3000u)); r2 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (4u))); *((uint32_t*)(uintptr_t)(r0 + (392u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (396u))) = (uint32_t)r1; return r0; }

/* original module: 20, addr: 0x020CC968, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020CC968(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 + (0x3100u)); r3 = (0x1eu); r2 = 0x020dbe6cu; *((uint16_t*)(uintptr_t)(r1 + 176u)) = (uint16_t)r3; r3 = *((uint32_t*)(uintptr_t)(r2 + (0u))); r1 = *((uint32_t*)(uintptr_t)(r2 + (4u))); r0 = (r0 + (0x3000u)); *((uint32_t*)(uintptr_t)(r0 + (392u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (396u))) = (uint32_t)r1; return r0; }

/* original module: 20, addr: 0x020CC9BC, 48 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020CC9BC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 + (0x3000u)); r12 = (0x1u); r0 = (r0 + (0x3100u)); r3 = (0x1eu); r2 = 0x020dbe74u; *((uint32_t*)(uintptr_t)(r1 + (408u))) = (uint32_t)r12; *((uint16_t*)(uintptr_t)(r0 + 176u)) = (uint16_t)r3; r3 = *((uint32_t*)(uintptr_t)(r2 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r2 + (4u))); *((uint32_t*)(uintptr_t)(r1 + (392u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r1 + (396u))) = (uint32_t)r0; return r0; }

/* original module: 20, addr: 0x020CD2F8, 52 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020CD2F8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 + (0x3100u)); r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 88u))); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 90u))); r0 = (r0 + (0x3000u)); r3 = (0x0u); r12 = (0x1u); *((uint8_t*)(uintptr_t)(r0 + (350u))) = (uint8_t)r12; { uint64_t z = (uint64_t)r2 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r1)); V = (((r2 ^ (r1)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } *((uint8_t*)(uintptr_t)(r0 + (352u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r0 + (351u))) = (uint8_t)r3; if (Z) { *((uint8_t*)(uintptr_t)(r0 + (350u))) = (uint8_t)r3; } if (Z) { *((uint8_t*)(uintptr_t)(r0 + (352u))) = (uint8_t)r12; } return r0; }

/* original module: 20, addr: 0x020CD32C, 48 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020CD32C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 + (0x3100u)); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 88u))); r0 = (r0 + (0x3000u)); r3 = (0x0u); r2 = (0x1u); *((uint8_t*)(uintptr_t)(r0 + (351u))) = (uint8_t)r2; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } *((uint8_t*)(uintptr_t)(r0 + (352u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r0 + (350u))) = (uint8_t)r3; if (Z) { *((uint8_t*)(uintptr_t)(r0 + (351u))) = (uint8_t)r3; } if (Z) { *((uint8_t*)(uintptr_t)(r0 + (352u))) = (uint8_t)r2; } return r0; }

/* original module: 20, addr: 0x020CDD90, 52 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020CDD90(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (r0 + (0x2c00u)); r1 = (r0 + (0xf4u)); r2 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 244u))); r1 = (r1 + (0x2c00u)); r3 = (uint32_t)(*((int16_t*)(uintptr_t)(r1 + 2u))); r1 = (r0 + (0x3100u)); r2 = (r2 + (0x100u)); r0 = (r0 + (0x3000u)); r12 = (0x1u); *((uint8_t*)(uintptr_t)(r0 + (436u))) = (uint8_t)r12; *((uint16_t*)(uintptr_t)(r1 + 166u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r1 + 164u)) = (uint16_t)r2; return r0; }

/* original module: 20, addr: 0x020CDDC4, 48 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020CDDC4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 + (0xf4u)); r2 = (r1 + (0x2c00u)); r1 = (r0 + (0x2c00u)); r3 = (uint32_t)(*((int16_t*)(uintptr_t)(r1 + 244u))); r1 = (r0 + (0x3100u)); r2 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 2u))); r0 = (r0 + (0x3000u)); r12 = (0x0u); *((uint8_t*)(uintptr_t)(r0 + (436u))) = (uint8_t)r12; *((uint16_t*)(uintptr_t)(r1 + 164u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r1 + 166u)) = (uint16_t)r2; return r0; }

/* original module: 20, addr: 0x020CEB40, 20 bytes, BL refs: 24 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020CEB40(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020e8d34u; r2 = *((uint32_t*)(uintptr_t)(r2 + (4u))); r0 = (r2 + ((r0 << 2))); *((uint32_t*)(uintptr_t)(r0 + (24u))) = (uint32_t)r1; return r0; }

/* original module: 20, addr: 0x020CECD4, 12 bytes, BL refs: 18 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020CECD4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020e8d34u; r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); return r0; }

/* original module: 20, addr: 0x020CECE4, 24 bytes, BL refs: 10 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020CECE4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020e8d34u; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x0u); } if (Z) { r0 = (0x3u); } return r0; }

/* original module: 20, addr: 0x020CF180, 28 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020CF180(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x027fff96u; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 0u))); { uint32_t z = r1 & (0x1u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = 0x0000fffeu; } if (!Z) { r0 = (r1 & (r0)); } if (!Z) { *((uint16_t*)(uintptr_t)(r2 + 0u)) = (uint16_t)r0; } return r0; }

/* original module: 20, addr: 0x020D3780, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020D3780(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020e9868u; r1 = (0x0u); *((uint8_t*)(uintptr_t)(r0 + (37u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (38u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (39u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (40u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (41u))) = (uint8_t)r1; return r0; }

/* original module: 20, addr: 0x020D3A80, 44 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020D3A80(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020e9868u; r3 = (0x1u); r0 = *((uint32_t*)(uintptr_t)(r1 + (28u))); r2 = (0x5u); r0 = (r0 + (0x400u)); *((uint16_t*)(uintptr_t)(r0 + 176u)) = (uint16_t)r3; r0 = *((uint32_t*)(uintptr_t)(r1 + (28u))); r0 = *((uint8_t*)(uintptr_t)(r0 + (1204u))); *((uint8_t*)(uintptr_t)(r1 + (38u))) = (uint8_t)r0; *((uint8_t*)(uintptr_t)(r1 + (36u))) = (uint8_t)r2; return r0; }

/* original module: 20, addr: 0x020D3E0C, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020D3E0C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x10000u); r2 = ((0x0u) - r2); r3 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 72u))); r2 = (r1 & (r2)); r2 = ((r2 >> 16)); r12 = (0x20u); *((uint16_t*)(uintptr_t)(r0 + 10u)) = (uint16_t)r12; *((uint16_t*)(uintptr_t)(r0 + 12u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 14u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 16u)) = (uint16_t)r3; return r0; }

/* original module: 20, addr: 0x020D4908, 40 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020D4908(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020e9868u; r2 = (0x1u); r3 = *((uint32_t*)(uintptr_t)(r1 + (12u))); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 2u))); { uint32_t z = r1 & ((r2 << (r0&31u))); Z = (z==0); N = (z>>31); } if (Z) { r0 = (0x0u); } if (!Z) { r2 = (r3 + (0x10u)); } if (!Z) { r1 = (0x590u); } if (!Z) { r0 = (r1 * r0 + r2); } return r0; }

/* original module: 20, addr: 0x020D64B8, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020D64B8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020e99e0u; r0 = *((uint32_t*)(uintptr_t)(r0 + (8u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (8u))); return r0; }

/* original module: 20, addr: 0x020D64CC, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020D64CC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020e99e0u; r0 = *((uint32_t*)(uintptr_t)(r0 + (8u))); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 12u))); return r0; }

/* original module: 20, addr: 0x020D683C, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov020_020D683C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020e9a20u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 21, addr: 0x020EA8A8, 16 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov021_020EA8A8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x02106c9cu; r1 = (0x18u); r0 = (r1 * r0 + r2); return r0; }

/* original module: 21, addr: 0x020EB3A8, 40 bytes, BL refs: 34 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov021_020EB3A8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020e8584u; r3 = (r1 & (0xffu)); r12 = *((uint32_t*)(uintptr_t)(r2 + (0u))); r2 = (0x1u); r12 = (uint32_t)(*((uint16_t*)(uintptr_t)(r12 + 40u))); { uint32_t z = r12 & ((r2 << (r3&31u))); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (r0 + ((r1 << 2))); } if (!Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (16u))); } if (Z) { r0 = 0x027e07d4u; } return r0; }

/* original module: 21, addr: 0x020EB468, 48 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov021_020EB468(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020e8584u; r3 = (r1 & (0xffu)); r12 = *((uint32_t*)(uintptr_t)(r2 + (0u))); r2 = (0x1u); r12 = (uint32_t)(*((uint16_t*)(uintptr_t)(r12 + 40u))); { uint32_t z = r12 & ((r2 << (r3&31u))); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (r0 + ((r1 << 2))); } if (!Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (16u))); } if (!Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (144u))); } if (!Z) { r0 = (r0 + (0x38u)); } if (Z) { r0 = 0x027e07d4u; } return r0; }

/* original module: 21, addr: 0x020ECC98, 40 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov021_020ECC98(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r12 = (0x0u); r2 = *((uint32_t*)(uintptr_t)(r1 + (4u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (8u))); *((uint8_t*)(uintptr_t)(r0 + (0u))) = (uint8_t)r12; *((uint8_t*)(uintptr_t)(r0 + (1u))) = (uint8_t)r12; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; return r0; }

/* original module: 21, addr: 0x020F6640, 16 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov021_020F6640(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020e8584u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint8_t*)(uintptr_t)(r0 + (42u))); return r0; }

/* original module: 21, addr: 0x020F87BC, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_ov021_020F87BC(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r1 = (0x0u); *((volatile uint32_t*)(uintptr_t)(object + (0u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (12u))) = (uint32_t)r1; *((volatile uint8_t*)(uintptr_t)(object + (16u))) = (uint8_t)r1; *((volatile uint16_t*)(uintptr_t)(object + 4u)) = (uint16_t)r1; *((volatile uint16_t*)(uintptr_t)(object + 6u)) = (uint16_t)r1; *((volatile uint16_t*)(uintptr_t)(object + 8u)) = (uint16_t)r1;;
}

/* original module: 21, addr: 0x020FB1D0, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov021_020FB1D0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x18u); r3 = (r2 * r3); r2 = (r0 + (0x18u)); r0 = *((uint32_t*)(uintptr_t)(r2 + (r3))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; } r0 = *((uint32_t*)(uintptr_t)(r2 + (r3))); r0 = (r0 + (0x4u)); *((uint32_t*)(uintptr_t)(r2 + (r3))) = (uint32_t)r0; return r0; }

/* original module: 21, addr: 0x020FB684, 28 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov021_020FB684(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = 0x02108c0cu; r3 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; return r0; }

/* original module: 21, addr: 0x020FB81C, 12 bytes, BL refs: 12 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov021_020FB81C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e0994u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); return r0; }

/* original module: 21, addr: 0x020FE15C, 52 bytes, BL refs: 17 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov021_020FE15C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + ((r1 << 2))); r0 = *((uint32_t*)(uintptr_t)(r0 + (40u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = 0x0210990du; } if (!Z) { r0 = *((uint8_t*)(uintptr_t)(r0 + (r1))); } if (!Z) { r0 = (r0 + (0x1u)); } if (!Z) { r0 = (r0 & (0xffu)); } if (Z) { r0 = 0x0210990du; } if (Z) { r0 = *((uint8_t*)(uintptr_t)(r0 + (r1))); } return r0; }

/* original module: 21, addr: 0x02105C50, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov021_02105C50(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 4u))); r12 = (0x0u); r3 = (0x1u); *((uint8_t*)(uintptr_t)(r0 + (11u))) = (uint8_t)r3; { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } *((uint8_t*)(uintptr_t)(r0 + (12u))) = (uint8_t)r12; *((uint16_t*)(uintptr_t)(r0 + 8u)) = (uint16_t)r1; *((uint8_t*)(uintptr_t)(r0 + (10u))) = (uint8_t)r12; if (Z) { *((uint8_t*)(uintptr_t)(r0 + (11u))) = (uint8_t)r12; } if (Z) { *((uint8_t*)(uintptr_t)(r0 + (12u))) = (uint8_t)r3; } return r0; }

/* original module: 21, addr: 0x02106B1C, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov021_02106B1C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020431b8u; r2 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (4u))); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (48u))) = (uint32_t)r1; return r0; }

/* original module: 22, addr: 0x020EAB98, 12 bytes, BL refs: 8 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov022_020EAB98(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020ee3e4u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); return r0; }

/* original module: 22, addr: 0x020EAFC0, 32 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov022_020EAFC0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020e879cu; r0 = (r1 + ((r0 << 5))); r0 = *((uint8_t*)(uintptr_t)(r0 + (23u))); r0 = ((r0 << 31)); r0 = ((r0 >> 31)); Z = (r0==0); N = (r0>>31); if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 22, addr: 0x020EAFE4, 16 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov022_020EAFE4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020e879cu; r0 = (r1 + ((r0 << 5))); r0 = (r0 + (0x4u)); return r0; }

/* original module: 22, addr: 0x020EB058, 32 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov022_020EB058(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020e879cu; r0 = (r1 + ((r0 << 5))); r0 = *((uint8_t*)(uintptr_t)(r0 + (23u))); r0 = ((r0 << 30)); r0 = ((r0 >> 31)); Z = (r0==0); N = (r0>>31); if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 22, addr: 0x020EDC28, 36 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov022_020EDC28(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0xaf000u)); r1 = (0x0u); *((uint16_t*)(uintptr_t)(r0 + 62u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 64u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 66u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 68u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 70u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 72u)) = (uint16_t)r1; return r0; }

/* original module: 22, addr: 0x020EE020, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov022_020EE020(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0xaf000u)); r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (52u))) = (uint32_t)r1; *((uint8_t*)(uintptr_t)(r0 + (81u))) = (uint8_t)r1; return r0; }

/* original module: 22, addr: 0x020EE05C, 24 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov022_020EE05C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0xaf000u)); r0 = *((uint32_t*)(uintptr_t)(r0 + (48u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0xbu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0xbu)); V = (((r0 ^ (0xbu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 23, addr: 0x020E9AE0, 12 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov023_020E9AE0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020f1c00u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); return r0; }

/* original module: 23, addr: 0x020EE1D0, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov023_020EE1D0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 + (0x2000u)); r2 = (0x0u); r0 = (r0 + (0x2100u)); *((uint8_t*)(uintptr_t)(r1 + (322u))) = (uint8_t)r2; *((uint16_t*)(uintptr_t)(r0 + 52u)) = (uint16_t)r2; return r0; }

/* original module: 23, addr: 0x020EE954, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov023_020EE954(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 4u))); r12 = (0x0u); r3 = (0x1u); *((uint8_t*)(uintptr_t)(r0 + (11u))) = (uint8_t)r3; { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } *((uint8_t*)(uintptr_t)(r0 + (12u))) = (uint8_t)r12; *((uint16_t*)(uintptr_t)(r0 + 8u)) = (uint16_t)r1; *((uint8_t*)(uintptr_t)(r0 + (10u))) = (uint8_t)r12; if (Z) { *((uint8_t*)(uintptr_t)(r0 + (11u))) = (uint8_t)r12; } if (Z) { *((uint8_t*)(uintptr_t)(r0 + (12u))) = (uint8_t)r3; } return r0; }

/* original module: 23, addr: 0x020EEE74, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov023_020EEE74(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (144u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(r2); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r2)); V = (((r1 ^ (r2)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r2 = (0x1u); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (144u))) = (uint32_t)r1; } if (!Z) { *((uint8_t*)(uintptr_t)(r0 + (148u))) = (uint8_t)r2; } return r0; }

/* original module: 23, addr: 0x020F131C, 12 bytes, BL refs: 10 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov023_020F131C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020fbdecu; r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); return r0; }

/* original module: 23, addr: 0x020F132C, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov023_020F132C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020fbdecu; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = (r0 + (0x5000u)); r0 = *((uint32_t*)(uintptr_t)(r0 + (528u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x4u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x4u)); V = (((r0 ^ (0x4u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 23, addr: 0x020F1350, 44 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov023_020F1350(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020fbdecu; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r1 = (r0 + (0x5200u)); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 6u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 4u))); } if (!Z) { r2 = (0x1u); } if (!Z) { r0 = (r0 | ((r2 << (r1&31u)))); } if (!Z) { r0 = ((r0 << 16)); } if (!Z) { r0 = ((r0 >> 16)); } return r0; }

/* original module: 25, addr: 0x020C596C, 56 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov025_020C596C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x4000000u); r0 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r0 = (r0 & ~(0xe000u)); r0 = (r0 | (0x8000u)); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 74u))); r0 = (r0 & ~(0x3f00u)); r0 = (r0 | (0x1900u)); *((uint16_t*)(uintptr_t)(r1 + 74u)) = (uint16_t)r0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 74u))); r0 = (r0 & ~(0x3fu)); r0 = (r0 | (0x9u)); *((uint16_t*)(uintptr_t)(r1 + 74u)) = (uint16_t)r0; return r0; }

/* original module: 25, addr: 0x020C59A4, 36 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov025_020C59A4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x4000000u); r0 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r0 = (r0 & ~(0xe000u)); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 74u))); r0 = (r0 & ~(0x3fu)); r0 = (r0 | (0x30u)); *((uint16_t*)(uintptr_t)(r1 + 74u)) = (uint16_t)r0; return r0; }

/* original module: 26, addr: 0x020D9710, 16 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
void st_ov026_020D9710(volatile unsigned int *obj) {
    obj[0] = 0u;
    obj[72] = 0u;
}

/* original module: 26, addr: 0x020DA588, 24 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020DA588(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e0ce0u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (56u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (88u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (508u))); return r0; }

/* original module: 26, addr: 0x020E6CD4, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020E6CD4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x02138e30u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 26, addr: 0x020E7A64, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020E7A64(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } r0 = (r0 + (0x300u)); if (!Z) { r2 = (0x1eu); } r1 = (0x0u); if (!Z) { *((uint16_t*)(uintptr_t)(r0 + 54u)) = (uint16_t)r2; } if (Z) { *((uint16_t*)(uintptr_t)(r0 + 54u)) = (uint16_t)r1; } *((uint16_t*)(uintptr_t)(r0 + 52u)) = (uint16_t)r1; return r0; }

/* original module: 26, addr: 0x020E7A84, 28 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020E7A84(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x300u)); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 52u))); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 54u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r0 = (0x1u); } if (C) { r0 = (0x0u); } return r0; }

/* original module: 26, addr: 0x020EA7FC, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020EA7FC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (20u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x8u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x8u)); V = (((r2 ^ (0x8u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r2 = (r0 + ((r2 << 2))); } if (!C) { *((uint32_t*)(uintptr_t)(r2 + (32u))) = (uint32_t)r1; } if (!C) { r1 = *((uint32_t*)(uintptr_t)(r0 + (20u))); } if (!C) { r1 = (r1 + (0x1u)); } if (!C) { *((uint32_t*)(uintptr_t)(r0 + (20u))) = (uint32_t)r1; } return r0; }

/* original module: 26, addr: 0x020EB284, 16 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020EB284(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r0 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (r1)); V = (((r0 ^ (r1)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!Z && N == V)) { r0 = (r0 - (r1)); } if ((Z || N != V)) { r0 = (r1 - (r0)); } return r0; }

/* original module: 26, addr: 0x020EC1C8, 44 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020EC1C8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (uint32_t)(*((int8_t*)(uintptr_t)(r2 + 11u))); r0 = (0xcu); r2 = 0x02132634u; r3 = (r3 + (0x2u)); r0 = (r3 * r0); r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + r0))); r1 = *((uint32_t*)(uintptr_t)(r1 + (12u))); r0 = (0x1u); { uint32_t z = r2 & ((r0 << (r1&31u))); Z = (z==0); N = (z>>31); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 26, addr: 0x020ECBF8, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020ECBF8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x24u); r3 = (r2 * r3); r1 = *((uint32_t*)(uintptr_t)(r1 + (r3))); r2 = (uint32_t)(*((int8_t*)(uintptr_t)(r1 + 7u))); r1 = (uint32_t)(*((int8_t*)(uintptr_t)(r1 + 6u))); *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r2; return r0; }

/* original module: 26, addr: 0x020ECC18, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020ECC18(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x24u); r1 = (r2 * r3 + r1); r1 = *((uint32_t*)(uintptr_t)(r1 + (16u))); r2 = (uint32_t)(*((int8_t*)(uintptr_t)(r1 + 7u))); r1 = (uint32_t)(*((int8_t*)(uintptr_t)(r1 + 6u))); *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r2; return r0; }

/* original module: 26, addr: 0x020ECC38, 28 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020ECC38(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } r2 = (0x24u); if (!Z) { r2 = (r1 * r2); } if (!Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (r2))); } if (Z) { r0 = (r1 * r2 + r0); } if (Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (16u))); } return r0; }

/* original module: 26, addr: 0x020EDC1C, 20 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020EDC1C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x3cu); r0 = (r1 * r3 + r0); r0 = (r0 + ((r2 << 2))); r0 = *((uint32_t*)(uintptr_t)(r0 + (1152u))); return r0; }

/* original module: 26, addr: 0x020EDDA4, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020EDDA4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x24u); r0 = (r1 * r3 + r0); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (8u))); } if (Z) { r1 = *((uint32_t*)(uintptr_t)(r0 + (16u))); } if (Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (24u))); } if (Z) { r1 = *((uint32_t*)(uintptr_t)(r1 + (16u))); } if (Z) { r0 = (r1 - (r0)); } return r0; }

/* original module: 26, addr: 0x020EE624, 52 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020EE624(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = (0x0u); r3 = (0x10u); r2 = (0x20u); r1 = (0x8u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (20u))) = (uint32_t)r1; *((uint8_t*)(uintptr_t)(r0 + (384u))) = (uint8_t)r12; *((uint8_t*)(uintptr_t)(r0 + (385u))) = (uint8_t)r12; return r0; }

/* original module: 26, addr: 0x020EEB00, 16 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
void st_ov026_020EEB00(unsigned char *obj, unsigned int value) {
    *(volatile unsigned char *)(obj + 385u) = 0u;
    *(volatile unsigned int *)obj = value;
}

/* original module: 26, addr: 0x020EEB10, 20 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020EEB10(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = ((r1 << 4)); r2 = (0x1u); *((uint8_t*)(uintptr_t)(r0 + (385u))) = (uint8_t)r2; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; return r0; }

/* original module: 26, addr: 0x020EEB24, 20 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_ov026_020EEB24(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if ((((*((unsigned char*)((unsigned char*)(a0) + (384))))) != (0u))) { *((unsigned char*)((unsigned char*)(a0) + (384))) = (((((*((unsigned char*)((unsigned char*)(a0) + (384))))) != (0u)) ? (0u) : ((*((unsigned char*)((unsigned char*)(a0) + (384))))))); } }

/* original module: 26, addr: 0x020EEB38, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020EEB38(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (60u))); r1 = (r1 + (0x2u)); r1 = (r1 & (0x3u)); *((uint32_t*)(uintptr_t)(r0 + (60u))) = (uint32_t)r1; return r0; }

/* original module: 26, addr: 0x020F4C80, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020F4C80(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r1 = (r2 - (0x1u)); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 10u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 8u)) = (uint16_t)r2; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; return r0; }

/* original module: 26, addr: 0x020F4F50, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020F4F50(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (((r1 << 4)) - r1); r0 = (r0 + (r1)); r0 = (uint32_t)(*((int8_t*)(uintptr_t)(r2 + r0))); r0 = ((r0 << 24)); r0 = (((uint32_t)((int32_t)r0 >> 28))); return r0; }

/* original module: 26, addr: 0x020F4F68, 24 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020F4F68(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (((r1 << 4)) - r1); r0 = (r0 + (r1)); r0 = (uint32_t)(*((int8_t*)(uintptr_t)(r2 + r0))); r0 = ((r0 << 28)); r0 = (((uint32_t)((int32_t)r0 >> 28))); return r0; }

/* original module: 26, addr: 0x020F5030, 32 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020F5030(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = 0x02135ea0u; r3 = (r0 + (0x4u)); r2 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r12; *((uint16_t*)(uintptr_t)(r0 + 32u)) = (uint16_t)r1; *((uint8_t*)(uintptr_t)(r0 + (34u))) = (uint8_t)r2; *((uint32_t*)(uintptr_t)(r0 + (28u))) = (uint32_t)r3; return r0; }

/* original module: 26, addr: 0x020F51AC, 40 bytes, BL refs: 9 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020F51AC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (28u))); r2 = (r0 + (0x4u)); r3 = (r3 - (r2)); r2 = (((uint32_t)((int32_t)r3 >> 1))); r2 = (r3 + ((r2 >> 30))); { uint64_t z = (uint64_t)r1 - (uint64_t)(((uint32_t)((int32_t)r2 >> 2))); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (((uint32_t)((int32_t)r2 >> 2)))); V = (((r1 ^ (((uint32_t)((int32_t)r2 >> 2)))) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r0 = (r0 + ((r1 << 2))); } if (!C) { r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); } if (C) { r0 = (0x0u); } return r0; }

/* original module: 26, addr: 0x020F51D4, 40 bytes, BL refs: 12 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020F51D4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (28u))); r2 = (r0 + (0x4u)); r3 = (r3 - (r2)); r2 = (((uint32_t)((int32_t)r3 >> 1))); r2 = (r3 + ((r2 >> 30))); { uint64_t z = (uint64_t)r1 - (uint64_t)(((uint32_t)((int32_t)r2 >> 2))); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (((uint32_t)((int32_t)r2 >> 2)))); V = (((r1 ^ (((uint32_t)((int32_t)r2 >> 2)))) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r0 = (r0 + ((r1 << 2))); } if (!C) { r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); } if (C) { r0 = (0x0u); } return r0; }

/* original module: 26, addr: 0x020F653C, 12 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020F653C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x021327fcu; r0 = *((uint32_t*)(uintptr_t)(r1 + ((r0 << 2)))); return r0; }

/* original module: 26, addr: 0x020F7D84, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020F7D84(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (8u))); r1 = 0x0000ffffu; r0 = ((r0 << 16)); r0 = ((r0 >> 16)); { uint64_t z = (uint64_t)r0 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (r1)); V = (((r0 ^ (r1)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 26, addr: 0x020F903C, 16 bytes, BL refs: 16 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020F903C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x3u); } if (!Z) { r0 = (0x1u); } return r0; }

/* original module: 26, addr: 0x020FA478, 20 bytes, BL refs: 9 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020FA478(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (452u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N == V)) { r0 = (0x1u); } if ((N != V)) { r0 = (0x0u); } return r0; }

/* original module: 26, addr: 0x020FA48C, 36 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020FA48C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r1 + (452u))); r3 = (r1 + (0x184u)); r1 = ((r2 << 2)); r12 = (r3 + ((r2 << 2))); r2 = (uint32_t)(*((int16_t*)(uintptr_t)(r3 + r1))); r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r12 + 2u))); *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r1; return r0; }
