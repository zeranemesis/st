/* Spirit Tracks EUR Rev 1 (BKIP): research C leaf functions, part 4/5. */
/* Every function has a direct ARM BL-reference; signatures/types remain provisional. */
/* 32-bit register-state translation. Standalone compiler equality is separately marked. */
/* NO PC port, original C++ class recovery, or official DS build integration. */
#include <stdint.h>

/* original module: 58, addr: 0x0214CBD8, 20 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov058_0214CBD8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 108u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1u)); V = (((r0 ^ (0x1u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 58, addr: 0x0214D7B4, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov058_0214D7B4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0d4cu; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 59, addr: 0x0215CAA4, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov059_0215CAA4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (r0 + (0x300u)); r12 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 26u))); r1 = 0x0000ffefu; r3 = (0x0u); r1 = (r12 & (r1)); *((uint16_t*)(uintptr_t)(r2 + 26u)) = (uint16_t)r1; *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r2 + 12u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r2 + 10u)) = (uint16_t)r3; return r0; }

/* original module: 59, addr: 0x02160840, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov059_02160840(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 176u))); r3 = *((uint32_t*)(uintptr_t)(r0 + (88u))); r1 = 0x0000fffbu; r3 = (r3 | (0x2u)); r2 = (r2 & (r1)); r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (88u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r0 + 176u)) = (uint16_t)r2; *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r1; return r0; }

/* original module: 59, addr: 0x02161B00, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov059_02161B00(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x100u)); r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 36u))); r0 = (0x1u); { uint32_t z = r2 & ((r0 << (r1&31u))); Z = (z==0); N = (z>>31); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 60, addr: 0x0215901C, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov060_0215901C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 108u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x3u)); V = (((r0 ^ (0x3u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x4u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x4u)); V = (((r0 ^ (0x4u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 60, addr: 0x02159034, 44 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov060_02159034(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 114u))); r1 = 0x027e09b8u; r0 = (0x1u); r2 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = ((r3 >> 5)); r1 = (r2 + ((r1 << 2))); r1 = *((uint32_t*)(uintptr_t)(r1 + (20u))); r2 = (r3 & (0x1fu)); { uint32_t z = r1 & ((r0 << (r2&31u))); Z = (z==0); N = (z>>31); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 60, addr: 0x02160A88, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov060_02160A88(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + ((r1 << 2))); r0 = *((uint32_t*)(uintptr_t)(r0 + (76u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 62, addr: 0x0215B494, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov062_0215B494(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0d60u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 63, addr: 0x02158544, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov063_02158544(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 76u))); r0 = (r0 + (0x200u)); r2 = (0x0u); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x6u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x6u)); V = (((r1 ^ (0x6u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = (0x14u); } *((uint16_t*)(uintptr_t)(r0 + 116u)) = (uint16_t)r2; if (Z) { *((uint16_t*)(uintptr_t)(r0 + 58u)) = (uint16_t)r1; } if (Z) { *((uint16_t*)(uintptr_t)(r0 + 56u)) = (uint16_t)r2; } return r0; }

/* original module: 63, addr: 0x02158C2C, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov063_02158C2C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x0u); r2 = *((uint32_t*)(uintptr_t)(r0 + (56u))); *((uint32_t*)(uintptr_t)(r0 + (616u))) = (uint32_t)r1; r3 = (0x1u); r1 = 0x02162ff0u; *((uint16_t*)(uintptr_t)(r2 + 8u)) = (uint16_t)r3; *((uint32_t*)(uintptr_t)(r0 + (52u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (48u))) = (uint32_t)r1; return r0; }

/* original module: 63, addr: 0x0215A6C0, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov063_0215A6C0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (592u))); r2 = *((uint32_t*)(uintptr_t)(r0 + (596u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (600u))); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r1 + (4u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r1 + (8u))) = (uint32_t)r0; return r0; }

/* original module: 64, addr: 0x02158AD0, 48 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov064_02158AD0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x0u); r2 = (0x2u); r1 = 0x0215aee0u; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (48u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r3; *((uint8_t*)(uintptr_t)(r0 + (52u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r0 + (53u))) = (uint8_t)r3; *((uint32_t*)(uintptr_t)(r0 + (24u))) = (uint32_t)r2; return r0; }

/* original module: 66, addr: 0x02158590, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov066_02158590(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020b62f0u; r2 = *((uint8_t*)(uintptr_t)(r0 + (932u))); r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r0 = (r0 + (0x300u)); *((uint8_t*)(uintptr_t)(r3 + (2984u))) = (uint8_t)r2; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 166u))); r0 = (r3 + (0xb00u)); *((uint16_t*)(uintptr_t)(r0 + 164u)) = (uint16_t)r1; return r0; }

/* original module: 66, addr: 0x02158FD4, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov066_02158FD4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x0u); *((uint8_t*)(uintptr_t)(r0 + (64u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (65u))) = (uint8_t)r1; *((uint32_t*)(uintptr_t)(r0 + (60u))) = (uint32_t)r1; return r0; }

/* original module: 68, addr: 0x0215A6E8, 28 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov068_0215A6E8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e0d64u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 76u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x2u)); V = (((r0 ^ (0x2u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 68, addr: 0x0215AE6C, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov068_0215AE6C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 + (0x200u)); r3 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 64u))); r2 = (0x0u); r0 = 0x0000fffeu; r3 = (r3 | (0x4u)); r0 = (r3 & (r0)); *((uint16_t*)(uintptr_t)(r1 + 64u)) = (uint16_t)r0; *((uint16_t*)(uintptr_t)(r1 + 46u)) = (uint16_t)r2; return r0; }

/* original module: 68, addr: 0x0215CAD0, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov068_0215CAD0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 218u))); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 216u))); r2 = (0x0u); r1 = (r3 - (r1)); r1 = ((r1 << 16)); r1 = ((r1 >> 16)); r3 = (r1 + (0xfu)); *((uint16_t*)(uintptr_t)(r0 + 218u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 216u)) = (uint16_t)r2; r0 = (r1); return r0; }

/* original module: 69, addr: 0x02159380, 20 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov069_02159380(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 110u))); r0 = 0xcccccccdu; r1 = (r0 + ((r2 << (r0&31u)))); r0 = ((r0 >> 3)); return r0; }

/* original module: 69, addr: 0x0215A02C, 56 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov069_0215A02C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r3 = 0x0215b32cu; r1 = (r2 - (0x1u)); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r3; *((uint8_t*)(uintptr_t)(r0 + (4u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (5u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (6u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (7u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (8u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (9u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (27u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (10u))) = (uint8_t)r2; *((uint32_t*)(uintptr_t)(r0 + (28u))) = (uint32_t)r1; return r0; }

/* original module: 7, addr: 0x020B66A4, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov007_020B66A4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020b8520u; r1 = *((uint32_t*)(uintptr_t)(r0 + (8u))); { uint32_t z = r1 & (0x1u); Z = (z==0); N = (z>>31); } if (Z) { r2 = 0x020b8474u; } if (Z) { r1 = (r1 | (0x1u)); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (28u))) = (uint32_t)r2; } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; } r0 = 0x020b853cu; return r0; }

/* original module: 7, addr: 0x020B673C, 36 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov007_020B673C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020b8520u; r1 = *((uint32_t*)(uintptr_t)(r0 + (12u))); { uint32_t z = r1 & (0x1u); Z = (z==0); N = (z>>31); } if (Z) { r2 = 0x020b842cu; } if (Z) { r1 = (r1 | (0x1u)); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (32u))) = (uint32_t)r2; } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; } r0 = 0x020b8540u; return r0; }

/* original module: 7, addr: 0x020B6BD4, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov007_020B6BD4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020b8520u; r1 = *((uint32_t*)(uintptr_t)(r0 + (20u))); { uint32_t z = r1 & (0x1u); Z = (z==0); N = (z>>31); } if (Z) { r2 = 0x020b8408u; } if (Z) { r1 = (r1 | (0x1u)); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r2; } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (20u))) = (uint32_t)r1; } r0 = 0x020b8530u; return r0; }

/* original module: 7, addr: 0x020B7358, 36 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov007_020B7358(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x020b8520u; r1 = *((uint32_t*)(uintptr_t)(r0 + (4u))); { uint32_t z = r1 & (0x1u); Z = (z==0); N = (z>>31); } if (Z) { r2 = 0x020b8498u; } if (Z) { r1 = (r1 | (0x1u)); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (36u))) = (uint32_t)r2; } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; } r0 = 0x020b8544u; return r0; }

/* original module: 70, addr: 0x02141A24, 20 bytes, BL refs: 10 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov070_02141A24(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020aed4cu; *((uint16_t*)(uintptr_t)(r0 + 76u)) = (uint16_t)r1; r1 = *((uint32_t*)(uintptr_t)(r2 + (0u))); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r1; return r0; }

/* original module: 70, addr: 0x02148870, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov070_02148870(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 110u))); r0 = 0x0214df58u; r0 = *((uint32_t*)(uintptr_t)(r0 + ((r1 << 2)))); return r0; }

/* original module: 70, addr: 0x0214B20C, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov070_0214B20C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09a4u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1eu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1eu)); V = (((r0 ^ (0x1eu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x53u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x53u)); V = (((r0 ^ (0x53u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x4bu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x4bu)); V = (((r0 ^ (0x4bu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 70, addr: 0x0214B234, 32 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov070_0214B234(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09a4u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1fu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1fu)); V = (((r0 ^ (0x1fu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x4cu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x4cu)); V = (((r0 ^ (0x4cu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 70, addr: 0x0214B258, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov070_0214B258(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09a4u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x21u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x21u)); V = (((r0 ^ (0x21u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x4eu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x4eu)); V = (((r0 ^ (0x4eu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 70, addr: 0x0214B27C, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov070_0214B27C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09a4u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x22u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x22u)); V = (((r0 ^ (0x22u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x4fu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x4fu)); V = (((r0 ^ (0x4fu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 71, addr: 0x02150D80, 16 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov071_02150D80(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x02163b90u; r1 = (0x18u); r0 = (r1 * r0 + r2); return r0; }

/* original module: 71, addr: 0x02152350, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov071_02152350(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 76u))); r0 = (r0 + (0x3f4u)); r0 = (r0 + (0xfc00u)); r0 = ((r0 << 16)); r0 = ((r0 >> 16)); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x2u)); V = (((r0 ^ (0x2u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!C || Z)) { r0 = (0x1u); } if ((C && !Z)) { r0 = (0x0u); } return r0; }

/* original module: 71, addr: 0x021530DC, 36 bytes, BL refs: 10 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov071_021530DC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 40u))); r0 = (r1 - (r0)); r0 = ((r0 << 16)); r0 = (((uint32_t)((int32_t)r0 >> 16))); Z = (r0==0); N = (r0>>31); if (N) { r0 = ((0x0u) - r0); } { uint64_t z = (uint64_t)r0 - (uint64_t)(0x4000u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x4000u)); V = (((r0 ^ (0x4000u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!Z && N == V)) { r0 = (0x1u); } if ((Z || N != V)) { r0 = (0x0u); } return r0; }

/* original module: 71, addr: 0x0215B618, 40 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov071_0215B618(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r12 = (0x0u); r2 = *((uint32_t*)(uintptr_t)(r1 + (4u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (8u))); *((uint8_t*)(uintptr_t)(r0 + (0u))) = (uint8_t)r12; *((uint8_t*)(uintptr_t)(r0 + (1u))) = (uint8_t)r12; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; return r0; }

/* original module: 71, addr: 0x0215F160, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov071_0215F160(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 224u))); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 226u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r0 = (0x1u); } if (C) { r0 = (0x0u); } return r0; }

/* original module: 71, addr: 0x0215F21C, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov071_0215F21C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (268u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { *((uint32_t*)(uintptr_t)(r2 + (0u))) = (uint32_t)r1; } r1 = *((uint32_t*)(uintptr_t)(r0 + (268u))); r1 = (r1 + (0x4u)); *((uint32_t*)(uintptr_t)(r0 + (268u))) = (uint32_t)r1; return r0; }

/* original module: 71, addr: 0x0215F974, 20 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov071_0215F974(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020aed4cu; *((uint16_t*)(uintptr_t)(r0 + 76u)) = (uint16_t)r1; r1 = *((uint32_t*)(uintptr_t)(r2 + (0u))); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r1; return r0; }

/* original module: 71, addr: 0x02163AE0, 32 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov071_02163AE0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e0ce0u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (44u))); r0 = *((uint8_t*)(uintptr_t)(r0 + (22u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x3u)); V = (((r0 ^ (0x3u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (C) { r0 = (0x1u); } if (!C) { r0 = (0x0u); } return r0; }

/* original module: 73, addr: 0x02151C40, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov073_02151C40(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020aed4cu; r1 = (r0 + (0x200u)); r12 = *((uint32_t*)(uintptr_t)(r2 + (0u))); r3 = (0x0u); r2 = (r0 + (0x400u)); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r12; *((uint16_t*)(uintptr_t)(r1 + 204u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r2 + 52u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r2 + 66u)) = (uint16_t)r3; return r0; }

/* original module: 73, addr: 0x0215F7EC, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov073_0215F7EC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09bcu; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); return r0; }

/* original module: 73, addr: 0x02160D68, 44 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov073_02160D68(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 40u))); r0 = (r0 - (0x8000u)); r0 = ((r0 << 16)); r0 = ((((uint32_t)((int32_t)r0 >> 16))) - r1); r0 = ((r0 << 16)); r0 = (((uint32_t)((int32_t)r0 >> 16))); Z = (r0==0); N = (r0>>31); if (N) { r0 = ((0x0u) - r0); } { uint64_t z = (uint64_t)r0 - (uint64_t)(0x4000u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x4000u)); V = (((r0 ^ (0x4000u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N != V)) { r0 = (0x1u); } if ((N == V)) { r0 = (0x0u); } return r0; }

/* original module: 73, addr: 0x02162398, 28 bytes, BL refs: 11 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov073_02162398(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 72u))); r0 = 0x000003e7u; r0 = (r0 - (r1)); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x18u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x18u)); V = (((r0 ^ (0x18u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N == V)) { r0 = (0x1u); } if ((N != V)) { r0 = (0x0u); } return r0; }

/* original module: 74, addr: 0x02152DF4, 20 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov074_02152DF4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = (0x1fu); } if (Z) { r1 = (0x0u); } *((uint8_t*)(uintptr_t)(r0 + (252u))) = (uint8_t)r1; return r0; }

/* original module: 74, addr: 0x02153654, 48 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov074_02153654(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (r0 + (0x400u)); r12 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 144u))); r1 = 0x0000fffbu; r3 = (0x0u); r1 = (r12 & (r1)); *((uint16_t*)(uintptr_t)(r2 + 144u)) = (uint16_t)r1; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 144u))); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r2 + 32u)) = (uint16_t)r3; r0 = (r1 | (0x8u)); *((uint16_t*)(uintptr_t)(r2 + 144u)) = (uint16_t)r0; return r0; }

/* original module: 74, addr: 0x0215E64C, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov074_0215E64C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e0d7cu; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (88u))); { uint32_t z = r0 & (0x2u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 75, addr: 0x021538F4, 12 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov075_021538F4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x700u)); r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 214u))); return r0; }

/* original module: 75, addr: 0x02155674, 16 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov075_02155674(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09bcu; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (16u))); return r0; }

/* original module: 75, addr: 0x0215AEF8, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov075_0215AEF8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x19cu)); r3 = (r0 + (0x800u)); r0 = *((uint32_t*)(uintptr_t)(r3 + ((r1 << 2)))); r0 = (r0 + (r2)); *((uint32_t*)(uintptr_t)(r3 + ((r1 << 2)))) = (uint32_t)r0; return r0; }

/* original module: 75, addr: 0x0215B08C, 32 bytes, BL refs: 9 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov075_0215B08C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x3u)); V = (((r1 ^ (0x3u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (2312u))) = (uint32_t)r1; } r2 = (0x0u); r1 = (r0 + (0x900u)); r3 = (0x2u); *((uint16_t*)(uintptr_t)(r1 + 94u)) = (uint16_t)r3; *((uint8_t*)(uintptr_t)(r0 + (2468u))) = (uint8_t)r2; return r0; }

/* original module: 75, addr: 0x0215D858, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov075_0215D858(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 8u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 10u)) = (uint16_t)r1; *((uint8_t*)(uintptr_t)(r0 + (12u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (13u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (14u))) = (uint8_t)r1; *((uint16_t*)(uintptr_t)(r0 + 16u)) = (uint16_t)r1; return r0; }

/* original module: 76, addr: 0x021510F4, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov076_021510F4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020aed4cu; r2 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 76u))); r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = (r0 + (0x200u)); r12 = (0x0u); *((uint16_t*)(uintptr_t)(r1 + 88u)) = (uint16_t)r12; { uint64_t z = (uint64_t)r2 - (uint64_t)(0x9u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x9u)); V = (((r2 ^ (0x9u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = (0x1000u); } *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r3; if (Z) { *((uint32_t*)(uintptr_t)(r0 + (716u))) = (uint32_t)r1; } return r0; }

/* original module: 77, addr: 0x021582C0, 44 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov077_021582C0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; *((uint16_t*)(uintptr_t)(r0 + 76u)) = (uint16_t)r1; r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 76u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x2u)); V = (((r1 ^ (0x2u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x3u)); V = (((r1 ^ (0x3u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r1 = *((uint32_t*)(uintptr_t)(r0 + (88u))); } if (Z) { r1 = (r1 & ~(0x2000u)); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (88u))) = (uint32_t)r1; } if (!Z) { r1 = *((uint32_t*)(uintptr_t)(r0 + (88u))); } if (!Z) { r1 = (r1 | (0x2000u)); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (88u))) = (uint32_t)r1; } return r0; }

/* original module: 78, addr: 0x0215C430, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov078_0215C430(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 72u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x18u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x18u)); V = (((r0 ^ (0x18u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((Z || N != V)) { r0 = (0x1u); } if ((!Z && N == V)) { r0 = (0x0u); } return r0; }

/* original module: 78, addr: 0x0215C4FC, 36 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov078_0215C4FC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x0215de00u; r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 40u))); r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r1 + 0u))); r0 = (r1 - (r0)); r0 = ((r0 << 16)); r0 = (((uint32_t)((int32_t)r0 >> 16))); Z = (r0==0); N = (r0>>31); if (N) { r0 = (0x1u); } if (!N) { r0 = (0x0u); } return r0; }

/* original module: 80, addr: 0x02150E64, 36 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov080_02150E64(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); { uint64_t z = (uint64_t)r1 - (uint64_t)(0xc8u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0xc8u)); V = (((r1 ^ (0xc8u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((C && !Z)) { r1 = (0xc8u); } *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r2; if ((C && !Z)) { *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; } if ((C && !Z)) { r0 = (r2); } if ((!C || Z)) { *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; } if ((!C || Z)) { r0 = (0x1u); } return r0; }

/* original module: 80, addr: 0x02150E88, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov080_02150E88(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 0u))); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 2u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r1)); V = (((r2 ^ (r1)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((C && !Z)) { r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 2u))); } if ((C && !Z)) { r1 = (r1 + (0x1u)); } if ((C && !Z)) { *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r1; } if ((C && !Z)) { r0 = (0x0u); } if ((!C || Z)) { r0 = (0x1u); } return r0; }

/* original module: 80, addr: 0x02150EAC, 44 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov080_02150EAC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 0u))); r1 = (r1 + (r2)); r1 = ((r1 << 16)); r1 = ((r1 >> 16)); { uint64_t z = (uint64_t)r1 - (uint64_t)(0xc8u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0xc8u)); V = (((r1 ^ (0xc8u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((C && !Z)) { r1 = (0xc8u); } if ((C && !Z)) { *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; } if ((C && !Z)) { r0 = (0x0u); } if ((!C || Z)) { *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; } if ((!C || Z)) { r0 = (0x1u); } return r0; }

/* original module: 80, addr: 0x0215A1B8, 64 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov080_0215A1B8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x1000u); *((uint16_t*)(uintptr_t)(r1 + 0u)) = (uint16_t)r2; r2 = (r0 + (0x800u)); r12 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 148u))); r3 = (0x0u); *((uint16_t*)(uintptr_t)(r1 + 2u)) = (uint16_t)r12; r12 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 144u))); *((uint16_t*)(uintptr_t)(r1 + 4u)) = (uint16_t)r12; r2 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 146u))); *((uint16_t*)(uintptr_t)(r1 + 6u)) = (uint16_t)r2; r0 = *((uint32_t*)(uintptr_t)(r0 + (2104u))); *((uint32_t*)(uintptr_t)(r1 + (8u))) = (uint32_t)r0; *((uint32_t*)(uintptr_t)(r1 + (12u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r1 + (16u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r1 + (20u))) = (uint32_t)r3; return r0; }

/* original module: 80, addr: 0x0215A790, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov080_0215A790(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (92u))); r2 = *((uint32_t*)(uintptr_t)(r0 + (96u))); r1 = *((uint32_t*)(uintptr_t)(r0 + (100u))); *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; return r0; }

/* original module: 80, addr: 0x0215A7AC, 48 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov080_0215A7AC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = *((uint32_t*)(uintptr_t)(r0 + (1780u))); r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r2 = *((uint32_t*)(uintptr_t)(r1 + (4u))); *((uint32_t*)(uintptr_t)(r12 + (2212u))) = (uint32_t)r3; r1 = *((uint32_t*)(uintptr_t)(r1 + (8u))); *((uint32_t*)(uintptr_t)(r12 + (2216u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r12 + (2220u))) = (uint32_t)r1; r0 = *((uint32_t*)(uintptr_t)(r0 + (1784u))); *((uint32_t*)(uintptr_t)(r0 + (2212u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (2216u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (2220u))) = (uint32_t)r1; return r0; }

/* original module: 80, addr: 0x0215B6B4, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov080_0215B6B4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r1 = (r0 + (0x700u)); *((uint16_t*)(uintptr_t)(r1 + 44u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r1 + 46u)) = (uint16_t)r2; *((uint32_t*)(uintptr_t)(r0 + (1840u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (1844u))) = (uint32_t)r2; return r0; }

/* original module: 81, addr: 0x021514F0, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov081_021514F0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 + (0x200u)); r3 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 32u))); r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 34u))); { uint64_t z = (uint64_t)r3 - (uint64_t)(r2); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r3 >= (r2)); V = (((r3 ^ (r2)) & (r3 ^ (uint32_t)z) & 0x80000000u) != 0); } if (C) { r1 = (0x1u); } if (C) { *((uint8_t*)(uintptr_t)(r0 + (553u))) = (uint8_t)r1; } if (!C) { r0 = (0x0u); } if (!C) { *((uint16_t*)(uintptr_t)(r1 + 34u)) = (uint16_t)r0; } if (!C) { *((uint16_t*)(uintptr_t)(r1 + 32u)) = (uint16_t)r0; } return r0; }

/* original module: 83, addr: 0x021540EC, 52 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov083_021540EC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (r0 + (0x1700u)); r3 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 196u))); r2 = 0x0215d2f8u; r0 = (r0 + (0x1000u)); r12 = *((uint32_t*)(uintptr_t)(r2 + ((r3 << 2)))); r2 = (0x1e000u); r3 = (0x1u); *((uint32_t*)(uintptr_t)(r0 + (1920u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (1916u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r0 + (1912u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (1864u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (1868u))) = (uint32_t)r2; return r0; }

/* original module: 83, addr: 0x02154124, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov083_02154124(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x1000u)); r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (1920u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (1916u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (1912u))) = (uint32_t)r1; return r0; }

/* original module: 83, addr: 0x0215495C, 16 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
unsigned int st_ov083_0215495C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { *((unsigned int*)((unsigned char*)((a0 + 4096u)) + (1964))) = (4096u); return (a0 + 4096u); }

/* original module: 83, addr: 0x02154CC4, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov083_02154CC4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 + (0x1000u)); r3 = (0x1000u); r0 = (r0 + (0x1700u)); r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (1972u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r0 + 192u)) = (uint16_t)r2; return r0; }

/* original module: 83, addr: 0x02155310, 40 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov083_02155310(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 + (0x1700u)); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 206u))); { uint32_t z = r0 & (0x100u); Z = (z==0); N = (z>>31); } if (!Z) { r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 206u))); } if (!Z) { r0 = 0x0000feffu; } if (!Z) { r0 = (r2 & (r0)); } if (Z) { r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 206u))); } if (Z) { r0 = (r0 | (0x100u)); } *((uint16_t*)(uintptr_t)(r1 + 206u)) = (uint16_t)r0; return r0; }

/* original module: 83, addr: 0x0215533C, 44 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov083_0215533C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (r0 + (0x1700u)); *((uint16_t*)(uintptr_t)(r2 + 202u)) = (uint16_t)r1; r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 202u))); r12 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 206u))); r0 = 0x0000fdffu; r3 = (0x0u); r0 = (r12 & (r0)); *((uint16_t*)(uintptr_t)(r2 + 206u)) = (uint16_t)r0; *((uint16_t*)(uintptr_t)(r2 + 198u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r2 + 200u)) = (uint16_t)r1; return r0; }

/* original module: 84, addr: 0x02151EA4, 44 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov084_02151EA4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x1u); r1 = ((r2 << (r1&31u))); r3 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 36u))); r1 = ((r1 << 16)); r2 = ((0x20000u) - r2); r3 = (r3 | ((r1 >> 16))); r1 = (0x0u); *((uint16_t*)(uintptr_t)(r0 + 36u)) = (uint16_t)r3; *((uint32_t*)(uintptr_t)(r0 + (24u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (20u))) = (uint32_t)r2; return r0; }

/* original module: 84, addr: 0x02151ED0, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov084_02151ED0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r1 = (r2 - (0x8000u)); *((uint8_t*)(uintptr_t)(r0 + (41u))) = (uint8_t)r2; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r0 + 28u)) = (uint16_t)r1; return r0; }

/* original module: 84, addr: 0x02151EE8, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov084_02151EE8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r1 = (r2 - (0x8000u)); *((uint8_t*)(uintptr_t)(r0 + (42u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (39u))) = (uint8_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r0 + 30u)) = (uint16_t)r1; return r0; }

/* original module: 84, addr: 0x02155A84, 20 bytes, BL refs: 16 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov084_02155A84(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 72u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x8u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x8u)); V = (((r0 ^ (0x8u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((Z || N != V)) { r0 = (0x1u); } if ((!Z && N == V)) { r0 = (0x0u); } return r0; }

/* original module: 84, addr: 0x02155D20, 28 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov084_02155D20(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e09a4u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x4eu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x4eu)); V = (((r0 ^ (0x4eu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 84, addr: 0x02159DAC, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov084_02159DAC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0d80u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 84, addr: 0x0215C22C, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov084_0215C22C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r12 = (0x0u); r2 = *((uint32_t*)(uintptr_t)(r1 + (4u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (8u))); *((uint8_t*)(uintptr_t)(r0 + (0u))) = (uint8_t)r12; *((uint8_t*)(uintptr_t)(r0 + (1u))) = (uint8_t)r12; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; return r0; }

/* original module: 84, addr: 0x0215E618, 20 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_ov084_0215E618(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if ((((*((unsigned char*)((unsigned char*)(a0) + (444))))) != (0u))) { *((unsigned char*)((unsigned char*)(a0) + (444))) = (((((*((unsigned char*)((unsigned char*)(a0) + (444))))) != (0u)) ? (0u) : ((*((unsigned char*)((unsigned char*)(a0) + (444))))))); } }

/* original module: 85, addr: 0x021530A8, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov085_021530A8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (148u))); r0 = (r0 - (0x1u)); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x1u)); V = (((r0 ^ (0x1u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!C || Z)) { r0 = (0x1u); } if ((C && !Z)) { r0 = (0x0u); } return r0; }

/* original module: 86, addr: 0x0215EA7C, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov086_0215EA7C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x0000ffffu; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (160u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 166u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 164u)) = (uint16_t)r2; return r0; }

/* original module: 88, addr: 0x02167D9C, 16 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_ov088_02167D9C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if (((a1) == (25u))) { *((unsigned int*)((unsigned char*)(a0) + (188))) = ((((a1) == (25u)) ? (*((unsigned int*)((unsigned char*)(a2) + (0)))) : a1)); } }

/* original module: 88, addr: 0x02167DB0, 16 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_ov088_02167DB0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if (((a1) == (25u))) { *((unsigned int*)((unsigned char*)(a0) + (192))) = ((((a1) == (25u)) ? (*((unsigned int*)((unsigned char*)(a2) + (0)))) : a1)); } }

/* original module: 88, addr: 0x02168670, 16 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_ov088_02168670(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if (((a1) == (25u))) { *((unsigned int*)((unsigned char*)(a0) + (188))) = ((((a1) == (25u)) ? (*((unsigned int*)((unsigned char*)(a2) + (0)))) : a1)); } }

/* original module: 88, addr: 0x02168684, 16 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_ov088_02168684(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if (((a1) == (25u))) { *((unsigned int*)((unsigned char*)(a0) + (192))) = ((((a1) == (25u)) ? (*((unsigned int*)((unsigned char*)(a2) + (0)))) : a1)); } }

/* original module: 88, addr: 0x02168B7C, 16 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_ov088_02168B7C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if (((a1) == (25u))) { *((unsigned int*)((unsigned char*)(a0) + (100))) = ((((a1) == (25u)) ? (*((unsigned int*)((unsigned char*)(a2) + (0)))) : a1)); } }

/* original module: 88, addr: 0x02168DDC, 16 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_ov088_02168DDC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if (((a1) == (1u))) { *((unsigned int*)((unsigned char*)(a0) + (76))) = ((((a1) == (1u)) ? (0u) : (a1))); } }

/* original module: 88, addr: 0x02168DEC, 24 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_ov088_02168DEC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if (((a1) == (2u))) { *((unsigned int*)((unsigned char*)(a0) + (76))) = ((((a1) == (2u)) ? (((int)((((a1) == (2u)) ? (((((a1) == (2u)) ? (*((unsigned int*)((unsigned char*)(a2) + (0)))) : a1) + 2048u)) : ((((a1) == (2u)) ? (*((unsigned int*)((unsigned char*)(a2) + (0)))) : a1)))) >> 12)) : ((((a1) == (2u)) ? (((((a1) == (2u)) ? (*((unsigned int*)((unsigned char*)(a2) + (0)))) : a1) + 2048u)) : ((((a1) == (2u)) ? (*((unsigned int*)((unsigned char*)(a2) + (0)))) : a1)))))); } }

/* original module: 88, addr: 0x02169250, 16 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
void st_ov088_02169250(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { if (((a1) == (25u))) { *((unsigned int*)((unsigned char*)(a0) + (112))) = ((((a1) == (25u)) ? (*((unsigned int*)((unsigned char*)(a2) + (0)))) : a1)); } }

/* original module: 88, addr: 0x0216C414, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov088_0216C414(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (1376u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x2u)); V = (((r0 ^ (0x2u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 88, addr: 0x0216F18C, 16 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov088_0216F18C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x027e0ce0u; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (28u))); return r0; }

/* original module: 88, addr: 0x02170684, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov088_02170684(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (88u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x2u)); V = (((r0 ^ (0x2u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 88, addr: 0x02172798, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov088_02172798(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x02177398u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 88, addr: 0x02172A08, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov088_02172A08(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x0u); *((uint8_t*)(uintptr_t)(r0 + (43u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (42u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (409u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (977u))) = (uint8_t)r1; return r0; }

/* original module: 88, addr: 0x021742D0, 28 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov088_021742D0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (8u))); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 16u))); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 36u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 89, addr: 0x0216635C, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov089_0216635C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x0u); *((uint16_t*)(uintptr_t)(r0 + 84u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 126u)) = (uint16_t)r1; return r0; }

/* original module: 89, addr: 0x021666B8, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov089_021666B8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (r1 & (0x7u)); r3 = (0x1u); *((uint32_t*)(uintptr_t)(r0 + (20u))) = (uint32_t)r1; r12 = ((r1 >> 3)); r1 = ((r3 << (r2&31u))); *((uint32_t*)(uintptr_t)(r0 + (24u))) = (uint32_t)r12; *((uint8_t*)(uintptr_t)(r0 + (16u))) = (uint8_t)r1; return r0; }

/* original module: 89, addr: 0x02166950, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov089_02166950(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (r0 + (0x8u)); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r3; r3 = *((uint32_t*)(uintptr_t)(r0 + (136u))); r1 = (0x0u); *((uint32_t*)(uintptr_t)(r2 + (0u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (136u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (140u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (144u))) = (uint32_t)r1; r1 = (0x1u); *((uint8_t*)(uintptr_t)(r0 + (152u))) = (uint8_t)r1; return r0; }

/* original module: 89, addr: 0x02167224, 28 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov089_02167224(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 36u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(r2); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r2)); V = (((r1 ^ (r2)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((C && !Z)) { r0 = (~(0x0u)); } if ((!C || Z)) { r2 = *((uint32_t*)(uintptr_t)(r0 + (40u))); } if ((!C || Z)) { r0 = ((r1 << 1)); } if ((!C || Z)) { r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + r0))); } return r0; }

/* original module: 89, addr: 0x021680C8, 20 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov089_021680C8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02177d60u; r1 = (0x0u); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); *((uint32_t*)(uintptr_t)(r0 + (600u))) = (uint32_t)r1; return r0; }

/* original module: 89, addr: 0x021697A4, 40 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov089_021697A4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (~(0x63u)); *((uint32_t*)(uintptr_t)(r0 + (92u))) = (uint32_t)r1; r2 = (0x1f4u); r1 = 0x00001388u; *((uint32_t*)(uintptr_t)(r0 + (100u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (96u))) = (uint32_t)r1; r1 = *((uint32_t*)(uintptr_t)(r0 + (128u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (4u))); *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r1; return r0; }

/* original module: 9, addr: 0x020B6910, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov009_020B6910(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x021190e4u; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 90, addr: 0x02165AD4, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov090_02165AD4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02177100u; r0 = *((uint32_t*)(uintptr_t)(r0 + (48u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; } r0 = 0x02177100u; r1 = *((uint32_t*)(uintptr_t)(r0 + (48u))); r1 = (r1 + (0x4u)); *((uint32_t*)(uintptr_t)(r0 + (48u))) = (uint32_t)r1; return r0; }
