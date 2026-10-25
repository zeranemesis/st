/* Spirit Tracks EUR Rev 1 (BKIP): research C leaf functions, part 3/5. */
/* Every function has a direct ARM BL-reference; signatures/types remain provisional. */
/* 32-bit register-state translation. Standalone compiler equality is separately marked. */
/* NO PC port, original C++ class recovery, or official DS build integration. */
#include <stdint.h>

/* original module: 26, addr: 0x020FA8E0, 28 bytes, BL refs: 71 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020FA8E0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint8_t*)(uintptr_t)(r0 + (468u))); r1 = ((r0 << 28)); r1 = ((r1 >> 31)); Z = (r1==0); N = (r1>>31); if (!Z) { r0 = ((r0 << 31)); } if (Z) { r0 = ((r0 << 30)); } r0 = ((r0 >> 31)); return r0; }

/* original module: 26, addr: 0x020FB538, 28 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020FB538(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (16u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = *((uint32_t*)(uintptr_t)(r1 + (16u))); } if (!Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (28u))); } if (!Z) { r0 = (r1 - (r0)); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 26, addr: 0x020FBBD0, 28 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020FBBD0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09a4u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0xfu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0xfu)); V = (((r0 ^ (0xfu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 26, addr: 0x020FF520, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_020FF520(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0xa000u); r3 = (0x1u); { uint64_t z = (uint64_t)r1 - (uint64_t)(0xa000u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0xa000u)); V = (((r1 ^ (0xa000u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!Z && N == V)) { r3 = (0x0u); } r2 = ((0x0u) - r2); { uint64_t z = (uint64_t)r1 - (uint64_t)(r2); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r2)); V = (((r1 ^ (r2)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N == V)) { r1 = (0x1u); } if ((N != V)) { r1 = (0x0u); } *((uint8_t*)(uintptr_t)(r0 + (13u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r0 + (14u))) = (uint8_t)r1; return r0; }

/* original module: 26, addr: 0x02102A44, 12 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_02102A44(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x0213610cu; r0 = (r1 + ((r0 << 6))); return r0; }

/* original module: 26, addr: 0x02102A54, 16 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_02102A54(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x0213628cu; r1 = (0x60u); r0 = (r1 * r0 + r2); return r0; }

/* original module: 26, addr: 0x02108340, 16 bytes, BL refs: 9 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_02108340(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x02133350u; r1 = (0x2cu); r0 = (r1 * r0 + r2); return r0; }

/* original module: 26, addr: 0x02108354, 16 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_02108354(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x021333d4u; r1 = (0xcu); r0 = (r1 * r0 + r2); return r0; }

/* original module: 26, addr: 0x02108368, 12 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_02108368(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x02133434u; r0 = (r1 + ((r0 << 3))); return r0; }

/* original module: 26, addr: 0x02108378, 12 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_02108378(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x02133464u; r0 = (r1 + ((r0 << 3))); return r0; }

/* original module: 26, addr: 0x0210B448, 40 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_0210B448(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r2 = *((uint32_t*)(uintptr_t)(r1 + (4u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (8u))); *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (208u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (212u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (216u))) = (uint32_t)r1; return r0; }

/* original module: 26, addr: 0x0210C158, 20 bytes, BL refs: 8 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_0210C158(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 - (0x10u)); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x2u)); V = (((r0 ^ (0x2u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!C || Z)) { r0 = (0x1u); } if ((C && !Z)) { r0 = (0x0u); } return r0; }

/* original module: 26, addr: 0x0210D2EC, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_0210D2EC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x54525243u; { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = 0x5452424cu; } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { r0 = 0x424f474eu; } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 26, addr: 0x02110E34, 36 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_02110E34(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r2 = (0x0u); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (148u))) = (uint32_t)r2; } { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } r1 = *((uint32_t*)(uintptr_t)(r0 + (88u))); if (!Z) { r1 = (r1 | (0x2u)); } if (Z) { r1 = (r1 & ~(0x2u)); } *((uint32_t*)(uintptr_t)(r0 + (88u))) = (uint32_t)r1; return r0; }

/* original module: 26, addr: 0x02110E88, 20 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_02110E88(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (88u))); { uint32_t z = r0 & (0x2u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 26, addr: 0x02117570, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_02117570(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09bcu; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); return r0; }

/* original module: 26, addr: 0x0211E0D8, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_0211E0D8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } r1 = *((uint32_t*)(uintptr_t)(r0 + (4u))); if (!Z) { r1 = (r1 ^ (0x1u)); } if (Z) { r1 = (r1 ^ (0x2u)); } *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; return r0; }

/* original module: 26, addr: 0x0211E7EC, 20 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_0211E7EC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 110u))); r0 = 0xcccccccdu; r1 = (r0 + ((r2 << (r0&31u)))); r0 = ((r0 >> 3)); return r0; }

/* original module: 26, addr: 0x021204C8, 20 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_021204C8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e0ce0u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (56u))); r0 = (r0 + (0x1cu)); return r0; }

/* original module: 26, addr: 0x021204E0, 20 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_021204E0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09bcu; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (12u))); r0 = (r0 + (0x34u)); return r0; }

/* original module: 26, addr: 0x021315C8, 20 bytes, BL refs: 70 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_021315C8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e0ce0u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (56u))); r0 = (r0 + (0x1cu)); return r0; }

/* original module: 26, addr: 0x02131714, 20 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_02131714(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e0ce0u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (56u))); r0 = (r0 + (0x34u)); return r0; }

/* original module: 26, addr: 0x0213179C, 24 bytes, BL refs: 9 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov026_0213179C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0ce0u; r1 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (56u))); r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r1 + 86u))); *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; return r0; }

/* original module: 29, addr: 0x021443A8, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov029_021443A8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = 0xfffff333u; r3 = (0x0u); r2 = ((0x0u) - r12); r1 = (r12 + (0x4000u)); *((uint32_t*)(uintptr_t)(r0 + (196u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (200u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (204u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (208u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (212u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (216u))) = (uint32_t)r2; return r0; }

/* original module: 29, addr: 0x02147090, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov029_02147090(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09bcu; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); return r0; }

/* original module: 29, addr: 0x0214A478, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov029_0214A478(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (856u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = *((uint8_t*)(uintptr_t)(r0 + (881u))); } if (Z) { r1 = (r1 + (0x1u)); } if (Z) { *((uint8_t*)(uintptr_t)(r0 + (881u))) = (uint8_t)r1; } if (!Z) { r0 = *((uint8_t*)(uintptr_t)(r1 + (881u))); } if (!Z) { r0 = (r0 + (0x1u)); } if (!Z) { *((uint8_t*)(uintptr_t)(r1 + (881u))) = (uint8_t)r0; } return r0; }

/* original module: 3, addr: 0x020B8004, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov003_020B8004(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x100u)); r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 20u))); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 22u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r1)); V = (((r2 ^ (r1)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 20u))); } if (!C) { r1 = (r1 + (0x1u)); } if (C) { r1 = (0x0u); } *((uint16_t*)(uintptr_t)(r0 + 20u)) = (uint16_t)r1; return r0; }

/* original module: 30, addr: 0x021428A8, 48 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov030_021428A8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } r3 = 0x00007007u; if (!Z) { r1 = 0xffc08fffu; } if (!Z) { r2 = (r3 & (r1)); } if (Z) { r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 32u))); } if (Z) { r1 = (r3 - (0x4000u)); } if (Z) { r2 = (r2 & (0xffu)); } if (Z) { r2 = (r1 | ((r2 << 16))); } r1 = (0x31u); *((uint32_t*)(uintptr_t)(r0 + (164u))) = (uint32_t)r2; *((uint8_t*)(uintptr_t)(r0 + (163u))) = (uint8_t)r1; return r0; }

/* original module: 30, addr: 0x021473A0, 16 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov030_021473A0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09bcu; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); return r0; }

/* original module: 30, addr: 0x0214BEA4, 48 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov030_0214BEA4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (160u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { *((uint32_t*)(uintptr_t)(r2 + (0u))) = (uint32_t)r1; } r3 = *((uint32_t*)(uintptr_t)(r0 + (160u))); r2 = *((uint8_t*)(uintptr_t)(r0 + (302u))); r3 = (r3 + (0x4u)); *((uint32_t*)(uintptr_t)(r0 + (160u))) = (uint32_t)r3; *((uint8_t*)(uintptr_t)(r1 + (1496u))) = (uint8_t)r2; r1 = *((uint8_t*)(uintptr_t)(r0 + (302u))); r1 = (r1 + (0x1u)); *((uint8_t*)(uintptr_t)(r0 + (302u))) = (uint8_t)r1; return r0; }

/* original module: 30, addr: 0x0214C2CC, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov030_0214C2CC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x1u); r1 = (0x0u); *((uint8_t*)(uintptr_t)(r0 + (304u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (305u))) = (uint8_t)r1; return r0; }

/* original module: 30, addr: 0x0214C43C, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov030_0214C43C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0d24u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 30, addr: 0x0214DDB0, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov030_0214DDB0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0d28u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 31, addr: 0x020D8840, 24 bytes, BL refs: 10 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020D8840(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (468u))); r2 = (r3 + (0x1u)); *((uint32_t*)(uintptr_t)(r0 + (468u))) = (uint32_t)r2; r0 = (r0 + ((r3 << 2))); *((uint32_t*)(uintptr_t)(r0 + (448u))) = (uint32_t)r1; return r0; }

/* original module: 31, addr: 0x020D9044, 48 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020D9044(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x6bc04a00u; r12 = (0x0u); r1 = (r0 + (0x18u)); r3 = (0x3000u); *((uint32_t*)(uintptr_t)(r0 + (36u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (40u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (52u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (32u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (64u))) = (uint32_t)r0; *((uint32_t*)(uintptr_t)(r0 + (68u))) = (uint32_t)r1; return r0; }

/* original module: 31, addr: 0x020DA70C, 36 bytes, BL refs: 8 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020DA70C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x0u); r2 = (~(0x0u)); *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (20u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 24u)) = (uint16_t)r1; *((uint8_t*)(uintptr_t)(r0 + (26u))) = (uint8_t)r1; return r0; }

/* original module: 31, addr: 0x020DB6D4, 32 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_ov031_020DB6D4(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r1 = (0x0u); *((volatile uint32_t*)(uintptr_t)(object + (4u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (8u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (12u))) = (uint32_t)r1; *((volatile uint16_t*)(uintptr_t)(object + 16u)) = (uint16_t)r1; *((volatile uint8_t*)(uintptr_t)(object + (18u))) = (uint8_t)r1; *((volatile uint8_t*)(uintptr_t)(object + (19u))) = (uint8_t)r1;;
}

/* original module: 31, addr: 0x020DD5E8, 32 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020DD5E8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (56u))); r1 = (0x0u); *((uint32_t*)(uintptr_t)(r2 + (0u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r2 + (4u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r2 + (8u))) = (uint32_t)r1; r0 = *((uint32_t*)(uintptr_t)(r0 + (44u))); *((uint16_t*)(uintptr_t)(r0 + 152u)) = (uint16_t)r1; return r0; }

/* original module: 31, addr: 0x020E0A8C, 32 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_ov031_020E0A8C(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r1 = (0x0u); *((volatile uint32_t*)(uintptr_t)(object + (0u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (4u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (8u))) = (uint32_t)r1; *((volatile uint16_t*)(uintptr_t)(object + 12u)) = (uint16_t)r1; *((volatile uint8_t*)(uintptr_t)(object + (14u))) = (uint8_t)r1; *((volatile uint8_t*)(uintptr_t)(object + (15u))) = (uint8_t)r1;;
}

/* original module: 31, addr: 0x020E10C8, 48 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020E10C8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x0u); r3 = (0x1000u); r2 = (0x800u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r2; *((uint8_t*)(uintptr_t)(r0 + (8u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (9u))) = (uint8_t)r1; *((uint16_t*)(uintptr_t)(r0 + 10u)) = (uint16_t)r1; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 16u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 18u)) = (uint16_t)r1; return r0; }

/* original module: 31, addr: 0x020E1E78, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020E1E78(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (344u))); r0 = 0x000004ccu; { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N == V)) { r0 = (0x1u); } if ((N != V)) { r0 = (0x0u); } return r0; }

/* original module: 31, addr: 0x020E4AB4, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020E4AB4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x0000ffffu; r2 = (0x0u); *((uint16_t*)(uintptr_t)(r0 + 76u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 82u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 80u)) = (uint16_t)r2; return r0; }

/* original module: 31, addr: 0x020EE9EC, 40 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020EE9EC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r0 - (uint64_t)(0x6u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x6u)); V = (((r0 ^ (0x6u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1u)); V = (((r0 ^ (0x1u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x2u)); V = (((r0 ^ (0x2u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0xfu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0xfu)); V = (((r0 ^ (0xfu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x10u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x10u)); V = (((r0 ^ (0x10u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x7u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x7u)); V = (((r0 ^ (0x7u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x0u); } if (!Z) { r0 = (0x1u); } return r0; }

/* original module: 31, addr: 0x020F1534, 20 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020F1534(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e0ce0u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (28u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (12u))); return r0; }

/* original module: 31, addr: 0x020F23B0, 28 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020F23B0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x100u)); r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 116u))); r1 = ((0x0u) - r1); r1 = (((r1 << 4)) - r1); r1 = (((uint32_t)((int32_t)r1 >> 4))); *((uint16_t*)(uintptr_t)(r0 + 116u)) = (uint16_t)r1; return r0; }

/* original module: 31, addr: 0x020F75C4, 60 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020F75C4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r1 = *((uint32_t*)(uintptr_t)(r0 + (12u))); r3 = (r2 - (0x800u)); r2 = (r1 - (0x800u)); r1 = 0x027e0cd8u; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; r2 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = (0x0u); r2 = *((uint32_t*)(uintptr_t)(r2 + (12u))); *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; *((uint8_t*)(uintptr_t)(r2 + (298u))) = (uint8_t)r1; r0 = (0x1u); *((uint8_t*)(uintptr_t)(r2 + (301u))) = (uint8_t)r0; return r0; }

/* original module: 31, addr: 0x020FB2B4, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020FB2B4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x0u); r1 = 0x0000ffffu; r2 = (r3 - (0x1u)); *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r0 + 14u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 12u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 18u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 16u)) = (uint16_t)r3; return r0; }

/* original module: 31, addr: 0x020FD03C, 32 bytes, BL refs: 9 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_020FD03C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 28u))); } if (Z) { r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 28u))); } if (!Z) { r1 = (r1 | (0x2u)); } if (Z) { r1 = 0x0000fffdu; } if (Z) { r1 = (r2 & (r1)); } *((uint16_t*)(uintptr_t)(r0 + 28u)) = (uint16_t)r1; return r0; }

/* original module: 31, addr: 0x02103994, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_02103994(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 22u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x8u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x8u)); V = (((r0 ^ (0x8u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 31, addr: 0x0210EB24, 56 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_0210EB24(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x04001000u; r0 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r0 = (r0 & ~(0xe000u)); r0 = (r0 | (0x8000u)); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 74u))); r0 = (r0 & ~(0x3f00u)); r0 = (r0 | (0x3c00u)); *((uint16_t*)(uintptr_t)(r1 + 74u)) = (uint16_t)r0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 74u))); r0 = (r0 & ~(0x3fu)); r0 = (r0 | (0x38u)); *((uint16_t*)(uintptr_t)(r1 + 74u)) = (uint16_t)r0; return r0; }

/* original module: 31, addr: 0x0210EB60, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov031_0210EB60(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x04001000u; r0 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r0 = (r0 & ~(0xe000u)); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 74u))); r0 = (r0 & ~(0x3fu)); r0 = (r0 | (0x30u)); *((uint16_t*)(uintptr_t)(r1 + 74u)) = (uint16_t)r0; return r0; }

/* original module: 32, addr: 0x0211B2BC, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov032_0211B2BC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 76u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0xau); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0xau)); V = (((r0 ^ (0xau)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 32, addr: 0x0211CD50, 56 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_ov032_0211CD50(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r1 = (0x0u); *((volatile uint8_t*)(uintptr_t)(object + (0u))) = (uint8_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (4u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (8u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (28u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (32u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (36u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (44u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (12u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (16u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (20u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (24u))) = (uint32_t)r1; *((volatile uint16_t*)(uintptr_t)(object + 40u)) = (uint16_t)r1;;
}

/* original module: 32, addr: 0x0211D94C, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov032_0211D94C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 40u))); r1 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r2 = (r2 | (0x2u)); *((uint16_t*)(uintptr_t)(r0 + 40u)) = (uint16_t)r2; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 40u))); } if (Z) { r1 = (r1 | (0x1u)); } if (Z) { *((uint16_t*)(uintptr_t)(r0 + 40u)) = (uint16_t)r1; } return r0; }

/* original module: 33, addr: 0x0211C260, 52 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov033_0211C260(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x38u); r3 = (r2 * r3); r3 = (r3 + (0x0u)); r2 = (r0 + (0x1u)); r0 = (r3 + ((r2 << 2))); r0 = (r0 + ((r1 << 2))); r0 = (r0 + ((r1 << 2))); r0 = (r0 + ((r1 << 2))); r0 = (r0 + ((r1 << 3))); r0 = (r0 + ((r2 << 1))); r0 = (r0 + ((r2 << 1))); r0 = (r0 + ((r1 << 1))); return r0; }

/* original module: 34, addr: 0x0211C85C, 32 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov034_0211C85C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09a4u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x21u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x21u)); V = (((r0 ^ (0x21u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x4eu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x4eu)); V = (((r0 ^ (0x4eu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 34, addr: 0x021217B4, 20 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov034_021217B4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 42u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 37, addr: 0x0211B510, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov037_0211B510(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x02122970u; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 28u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x3u)); V = (((r2 ^ (0x3u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N != V)) { r1 = (0x78u); } if ((N != V)) { r0 = (r2 * r1 + r0); } if ((N != V)) { r1 = (0x1u); } if ((N != V)) { *((uint8_t*)(uintptr_t)(r0 + (330u))) = (uint8_t)r1; } return r0; }

/* original module: 37, addr: 0x0211E45C, 36 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov037_0211E45C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 76u))); r0 = (r0 + (0xeeu)); r0 = (r0 + (0xff00u)); r0 = ((r0 << 16)); r0 = ((r0 >> 16)); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x3u)); V = (((r0 ^ (0x3u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!C || Z)) { r0 = (0x1u); } if ((C && !Z)) { r0 = (0x0u); } return r0; }

/* original module: 37, addr: 0x0211E480, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov037_0211E480(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 108u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x3u)); V = (((r0 ^ (0x3u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 37, addr: 0x0211E49C, 20 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov037_0211E49C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (804u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 37, addr: 0x0211E824, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov037_0211E824(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (r0 + (0x300u)); r12 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 40u))); r3 = (0x4u); *((uint8_t*)(uintptr_t)(r0 + (904u))) = (uint8_t)r1; r1 = (r12 | (0x5u)); *((uint16_t*)(uintptr_t)(r2 + 40u)) = (uint16_t)r1; *((uint8_t*)(uintptr_t)(r0 + (74u))) = (uint8_t)r3; return r0; }

/* original module: 37, addr: 0x021201A8, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov037_021201A8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x300u)); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 2u))); { uint32_t z = r0 & (0x2u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 37, addr: 0x02120204, 44 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov037_02120204(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (r0 + (0x300u)); } if (Z) { r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 2u))); } if (Z) { r1 = (r1 | (0x20u)); } if (Z) { *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r1; } if (!Z) { r1 = (r0 + (0x300u)); } if (!Z) { r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 2u))); } if (!Z) { r0 = 0x0000ffdfu; } if (!Z) { r0 = (r2 & (r0)); } if (!Z) { *((uint16_t*)(uintptr_t)(r1 + 2u)) = (uint16_t)r0; } return r0; }

/* original module: 37, addr: 0x02120530, 36 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov037_02120530(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 76u))); r0 = (r0 + (0xf1u)); r0 = (r0 + (0xff00u)); r0 = ((r0 << 16)); r0 = ((r0 >> 16)); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x3u)); V = (((r0 ^ (0x3u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!C || Z)) { r0 = (0x1u); } if ((C && !Z)) { r0 = (0x0u); } return r0; }

/* original module: 37, addr: 0x021205C4, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov037_021205C4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 108u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x3u)); V = (((r0 ^ (0x3u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 37, addr: 0x021205E0, 20 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov037_021205E0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (764u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 37, addr: 0x02120D94, 12 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov037_02120D94(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0xecu)); r0 = (r0 + ((r1 << 4))); return r0; }

/* original module: 38, addr: 0x0211EAC0, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov038_0211EAC0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x0000ffffu; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (160u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 166u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 164u)) = (uint16_t)r2; return r0; }

/* original module: 4, addr: 0x020B7A98, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov004_020B7A98(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x1000u)); r1 = *((uint32_t*)(uintptr_t)(r0 + (388u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N == V)) { r0 = *((uint32_t*)(uintptr_t)(r0 + (384u))); } if ((N == V)) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if ((N != V)) { r0 = (~(0x0u)); } if ((N == V)) { r0 = (r1 + ((r0 << 3))); } return r0; }

/* original module: 40, addr: 0x0212A794, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov040_0212A794(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (1932u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = 0x0000023du; } if (!Z) { *((uint32_t*)(uintptr_t)(r1 + (88u))) = (uint32_t)r0; } return r0; }

/* original module: 41, addr: 0x02128940, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov041_02128940(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0xa4u); r2 = (0x0u); r1 = (r0 + (0x100u)); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r1 + 26u)) = (uint16_t)r2; *((uint8_t*)(uintptr_t)(r0 + (280u))) = (uint8_t)r2; return r0; }

/* original module: 41, addr: 0x0212A890, 44 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov041_0212A890(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 76u))); r2 = (0x0u); r3 = 0x00000666u; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x2u)); V = (((r1 ^ (0x2u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } r1 = 0x00000666u; if (Z) { r3 = (r3 - ((r3 << 1))); } *((uint32_t*)(uintptr_t)(r0 + (388u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (392u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (396u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (400u))) = (uint32_t)r1; return r0; }

/* original module: 43, addr: 0x02123AB0, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov043_02123AB0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020aed4cu; r1 = (r0 + (0x200u)); r3 = *((uint32_t*)(uintptr_t)(r2 + (0u))); r2 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r1 + 172u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r1 + 166u)) = (uint16_t)r2; return r0; }

/* original module: 43, addr: 0x02126358, 24 bytes, BL refs: 8 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov043_02126358(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 108u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x2u)); V = (((r0 ^ (0x2u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x3u)); V = (((r0 ^ (0x3u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 43, addr: 0x02126C78, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov043_02126C78(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020aed4cu; r12 = (0x0u); r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = (r0 + (0x200u)); r2 = (0x1u); *((uint32_t*)(uintptr_t)(r0 + (60u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r1 + 228u)) = (uint16_t)r12; *((uint8_t*)(uintptr_t)(r0 + (742u))) = (uint8_t)r12; *((uint8_t*)(uintptr_t)(r0 + (743u))) = (uint8_t)r2; return r0; }

/* original module: 44, addr: 0x02125558, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov044_02125558(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (44u))); r0 = 0xc22e4507u; r1 = *((uint32_t*)(uintptr_t)(r1 + (40u))); r2 = ((r1 << 12)); r1 = (r0 + ((r2 << (r0&31u)))); r0 = ((r0 >> 10)); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1000u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1000u)); V = (((r0 ^ (0x1000u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!Z && N == V)) { r0 = (0x1000u); } return r0; }

/* original module: 46, addr: 0x02124DC8, 20 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov046_02124DC8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 108u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = 0x0212a1f0u; } if (!Z) { r0 = 0x0212a130u; } return r0; }

/* original module: 46, addr: 0x0212645C, 52 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov046_0212645C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = (r0 + ((r2 << 2))); r3 = (0x0u); r1 = (0x1u); r2 = (~((r1 << (r2&31u)))); *((uint32_t*)(uintptr_t)(r12 + (816u))) = (uint32_t)r3; r1 = (r0 + (0x300u)); r3 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 150u))); r0 = ((r2 << 16)); r2 = (0x96u); r0 = (r3 & ((r0 >> 16))); *((uint16_t*)(uintptr_t)(r1 + 150u)) = (uint16_t)r0; *((uint32_t*)(uintptr_t)(r12 + (828u))) = (uint32_t)r2; return r0; }

/* original module: 46, addr: 0x02126490, 20 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov046_02126490(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 108u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = 0x0212a350u; } if (!Z) { r0 = 0x0212a398u; } return r0; }

/* original module: 46, addr: 0x0212785C, 52 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov046_0212785C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = (r0 + ((r2 << 2))); r3 = (0x0u); r1 = (0x1u); r2 = (~((r1 << (r2&31u)))); *((uint32_t*)(uintptr_t)(r12 + (928u))) = (uint32_t)r3; r1 = (r0 + (0x300u)); r3 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 184u))); r0 = ((r2 << 16)); r2 = (0x96u); r0 = (r3 & ((r0 >> 16))); *((uint16_t*)(uintptr_t)(r1 + 184u)) = (uint16_t)r0; *((uint32_t*)(uintptr_t)(r12 + (936u))) = (uint32_t)r2; return r0; }

/* original module: 46, addr: 0x02129738, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov046_02129738(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x00000666u; r2 = (0x1000u); *((uint32_t*)(uintptr_t)(r0 + (48u))) = (uint32_t)r0; *((uint32_t*)(uintptr_t)(r0 + (52u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (56u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (60u))) = (uint32_t)r1; return r0; }

/* original module: 47, addr: 0x02131BC8, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov047_02131BC8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x0u); r1 = (r0 + (0x300u)); r2 = *((uint32_t*)(uintptr_t)(r0 + (56u))); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r1 + 122u)) = (uint16_t)r3; r1 = (0x1u); *((uint16_t*)(uintptr_t)(r2 + 8u)) = (uint16_t)r1; r1 = (0x6cu); *((uint16_t*)(uintptr_t)(r0 + 68u)) = (uint16_t)r1; return r0; }

/* original module: 48, addr: 0x02130BE4, 32 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov048_02130BE4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r0 = 0x02137ba0u; r2 = *((uint32_t*)(uintptr_t)(r1 + (4u))); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r3; r1 = *((uint32_t*)(uintptr_t)(r1 + (8u))); *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; return r0; }

/* original module: 49, addr: 0x02134524, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov049_02134524(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0d40u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 50, addr: 0x02133244, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov050_02133244(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020aed4cu; r2 = (0x0u); r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = (r0 + (0x200u)); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r1 + 76u)) = (uint16_t)r2; *((uint8_t*)(uintptr_t)(r0 + (586u))) = (uint8_t)r2; return r0; }

/* original module: 50, addr: 0x02134AC8, 40 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov050_02134AC8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (600u))); r1 = *((uint32_t*)(uintptr_t)(r2 + (4u))); *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; r1 = *((uint32_t*)(uintptr_t)(r2 + (8u))); *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; r2 = *((uint32_t*)(uintptr_t)(r2 + (12u))); r1 = (r1 + (0x1800u)); *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; return r0; }

/* original module: 50, addr: 0x02134AF0, 16 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov050_02134AF0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (600u))); r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r1 + 40u))); *((uint16_t*)(uintptr_t)(r0 + 40u)) = (uint16_t)r1; return r0; }

/* original module: 51, addr: 0x02135908, 20 bytes, BL refs: 17 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov051_02135908(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 108u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1u)); V = (((r0 ^ (0x1u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = 0x0000119au; } if (!Z) { r0 = (0xc00u); } return r0; }

/* original module: 52, addr: 0x02130A58, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov052_02130A58(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020aed4cu; r1 = (r0 + (0x200u)); r3 = *((uint32_t*)(uintptr_t)(r2 + (0u))); r2 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r1 + 118u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r1 + 114u)) = (uint16_t)r2; return r0; }

/* original module: 52, addr: 0x021336B8, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov052_021336B8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020aed4cu; r12 = (0x0u); r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = (r0 + (0x200u)); r2 = (0x1u); *((uint32_t*)(uintptr_t)(r0 + (60u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r1 + 228u)) = (uint16_t)r12; *((uint8_t*)(uintptr_t)(r0 + (742u))) = (uint8_t)r12; *((uint8_t*)(uintptr_t)(r0 + (743u))) = (uint8_t)r2; return r0; }

/* original module: 53, addr: 0x0213B104, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov053_0213B104(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 76u))); r0 = (0x1u); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x3u)); V = (((r1 ^ (0x3u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x4u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x4u)); V = (((r1 ^ (0x4u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 54, addr: 0x02139748, 48 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov054_02139748(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = ((r1 << 16)); r3 = (r0 + (0x200u)); r12 = (0x0u); r2 = (((uint32_t)((int32_t)r2 >> 16))); *((uint32_t*)(uintptr_t)(r0 + (504u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r3 + 100u)) = (uint16_t)r12; *((uint16_t*)(uintptr_t)(r3 + 102u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r3 + 104u)) = (uint16_t)r12; *((uint16_t*)(uintptr_t)(r3 + 106u)) = (uint16_t)r12; *((uint16_t*)(uintptr_t)(r3 + 108u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r3 + 110u)) = (uint16_t)r12; return r0; }

/* original module: 55, addr: 0x0213ABAC, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov055_0213ABAC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (32u))); r2 = (0x0u); r1 = (r1 + (0x124u)); r1 = (r1 + (0x800u)); *((uint32_t*)(uintptr_t)(r0 + (28u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (36u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (32u))) = (uint32_t)r1; return r0; }

/* original module: 58, addr: 0x02142830, 60 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov058_02142830(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (216u))); r2 = (r0 + (0x98u)); r3 = (r3 - (r2)); r2 = (((uint32_t)((int32_t)r3 >> 1))); r2 = (r3 + ((r2 >> 30))); r3 = (((uint32_t)((int32_t)r2 >> 2))); r2 = (r1 + (0x200u)); *((uint16_t*)(uintptr_t)(r2 + 236u)) = (uint16_t)r3; r2 = *((uint32_t*)(uintptr_t)(r0 + (216u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { *((uint32_t*)(uintptr_t)(r2 + (0u))) = (uint32_t)r1; } r1 = *((uint32_t*)(uintptr_t)(r0 + (216u))); r1 = (r1 + (0x4u)); *((uint32_t*)(uintptr_t)(r0 + (216u))) = (uint32_t)r1; return r0; }

/* original module: 58, addr: 0x021428E4, 40 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov058_021428E4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r12 = (0x0u); r2 = *((uint32_t*)(uintptr_t)(r1 + (4u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (8u))); *((uint8_t*)(uintptr_t)(r0 + (0u))) = (uint8_t)r12; *((uint8_t*)(uintptr_t)(r0 + (1u))) = (uint8_t)r12; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; return r0; }

/* original module: 58, addr: 0x02142A64, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov058_02142A64(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0d44u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 58, addr: 0x02148830, 20 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov058_02148830(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 110u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1u)); V = (((r0 ^ (0x1u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 58, addr: 0x0214A9F0, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov058_0214A9F0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x021570d0u; r1 = (0x0u); *((uint8_t*)(uintptr_t)(r0 + (0u))) = (uint8_t)r1; return r0; }

/* original module: 58, addr: 0x0214AC98, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov058_0214AC98(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0d48u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }
