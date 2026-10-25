/* Spirit Tracks EUR Rev 1 (BKIP): research C leaf functions, part 1/5. */
/* Every function has a direct ARM BL-reference; signatures/types remain provisional. */
/* 32-bit register-state translation. Standalone compiler equality is separately marked. */
/* NO PC port, original C++ class recovery, or official DS build integration. */
#include <stdint.h>

/* original module: 0, addr: 0x02054548, 64 bytes, BL refs: 8 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02054548(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r2 = (0x0u); { uint64_t z = (uint64_t)r3 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r3 >= (0x0u)); V = (((r3 ^ (0x0u)) & (r3 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; } if (Z) { *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; } if (Z) { *((uint32_t*)(uintptr_t)(r1 + (4u))) = (uint32_t)r2; } if (!Z) { *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r3; } if (!Z) { *((uint32_t*)(uintptr_t)(r1 + (4u))) = (uint32_t)r2; } if (!Z) { r2 = *((uint32_t*)(uintptr_t)(r0 + (0u))); } if (!Z) { *((uint32_t*)(uintptr_t)(r2 + (4u))) = (uint32_t)r1; } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; } r1 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r1 = (r1 + (0x1u)); *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x02057D6C, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02057D6C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (60u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x58u); } if (!Z) { r0 = (r1 * r0 + r2); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x02058FC4, 52 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02058FC4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = *((uint32_t*)(uintptr_t)(r2 + (0u))); r3 = *((uint32_t*)(uintptr_t)(r2 + (4u))); r2 = *((uint32_t*)(uintptr_t)(r2 + (8u))); *((uint32_t*)(uintptr_t)(r1 + (4u))) = (uint32_t)r12; *((uint32_t*)(uintptr_t)(r1 + (8u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r1 + (12u))) = (uint32_t)r2; r2 = *((uint32_t*)(uintptr_t)(r0 + (128u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { *((uint32_t*)(uintptr_t)(r2 + (0u))) = (uint32_t)r1; } r1 = *((uint32_t*)(uintptr_t)(r0 + (128u))); r1 = (r1 + (0x4u)); *((uint32_t*)(uintptr_t)(r0 + (128u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x020590E4, 32 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020590E4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020b1ba8u; r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x0205AED0, 32 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0205AED0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (r0 - (0x80000u)); r0 = (((uint32_t)((int32_t)r2 >> 6))); r0 = (r2 + ((r0 >> 25))); r0 = (((uint32_t)((int32_t)r0 >> 7))); r0 = (((uint32_t)((int32_t)r0 >> (r1&31u)))); r0 = ((r0 << 16)); r0 = (((uint32_t)((int32_t)r0 >> 16))); return r0; }

/* original module: 0, addr: 0x0205B090, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0205B090(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 - (0x80u)); r1 = ((r0 << 12)); r0 = (((uint32_t)((int32_t)r1 >> 6))); r0 = (r1 + ((r0 >> 25))); r0 = ((r0 << 9)); r0 = (((uint32_t)((int32_t)r0 >> 16))); return r0; }

/* original module: 0, addr: 0x0205B5A8, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0205B5A8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x04000448u; r2 = (0x1u); *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; return r0; }

/* original module: 0, addr: 0x0205C5A0, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0205C5A0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = (r0 + (0x8u)); r3 = *((uint8_t*)(uintptr_t)(r12 + (r1))); r0 = (r0 + (r1)); *((uint8_t*)(uintptr_t)(r0 + (10u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r12 + (r1))) = (uint8_t)r2; return r0; }

/* original module: 0, addr: 0x0205C6A4, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0205C6A4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x020b62f0u; r2 = ((r0 >> 5)); r1 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r3 = (r0 & (0x1fu)); r0 = (r1 + ((r2 << 2))); r1 = *((uint32_t*)(uintptr_t)(r0 + (16u))); r0 = (0x1u); { uint32_t z = r1 & ((r0 << (r3&31u))); Z = (z==0); N = (z>>31); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x0205CAB4, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0205CAB4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e09a4u; r0 = (0x1u); r2 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = *((uint32_t*)(uintptr_t)(r2 + (96u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x1u)); V = (((r1 ^ (0x1u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = *((uint32_t*)(uintptr_t)(r2 + (0u))); } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x42u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x42u)); V = (((r1 ^ (0x42u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x0205D500, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0205D500(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (~(0x0u)); { uint64_t z = (uint64_t)r2 - (uint64_t)(r3); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r3)); V = (((r2 ^ (r3)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r2 = (0x100u); } if (Z) { *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r1; } if (Z) { *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r2; } if (!Z) { r1 = ((0x100u) - r3); } if (!Z) { *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; } if (!Z) { *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r2; } return r0; }

/* original module: 0, addr: 0x0205FD08, 52 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0205FD08(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r2 = 0x00000fffu; r12 = *((uint32_t*)(uintptr_t)(r3 + (4u))); r1 = ((r1 << 28)); r3 = (uint32_t)(*((uint16_t*)(uintptr_t)(r12 + 4u))); r2 = (r3 & (r2)); *((uint16_t*)(uintptr_t)(r12 + 4u)) = (uint16_t)r2; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r2 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 4u))); r0 = (r0 | ((r1 >> 16))); *((uint16_t*)(uintptr_t)(r2 + 4u)) = (uint16_t)r0; return r0; }

/* original module: 0, addr: 0x02060738, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02060738(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((int8_t*)(uintptr_t)(r0 + 99u))); r1 = (uint32_t)(*((int8_t*)(uintptr_t)(r0 + 101u))); r2 = (r2 + (0x1u)); *((uint8_t*)(uintptr_t)(r0 + (99u))) = (uint8_t)r2; r2 = (uint32_t)(*((int8_t*)(uintptr_t)(r0 + 99u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r1)); V = (((r2 ^ (r1)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!Z && N == V)) { r1 = (uint32_t)(*((int8_t*)(uintptr_t)(r0 + 100u))); } if ((!Z && N == V)) { *((uint8_t*)(uintptr_t)(r0 + (99u))) = (uint8_t)r1; } return r0; }

/* original module: 0, addr: 0x02060804, 40 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02060804(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x0u); r2 = (r3 - (0x1u)); r1 = (0x1u); *((uint32_t*)(uintptr_t)(r0 + (88u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (96u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (104u))) = (uint32_t)r3; *((uint16_t*)(uintptr_t)(r0 + 108u)) = (uint16_t)r2; *((uint8_t*)(uintptr_t)(r0 + (110u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (111u))) = (uint8_t)r3; return r0; }

/* original module: 0, addr: 0x02060EC4, 28 bytes, BL refs: 8 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02060EC4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x020aa470u; r2 = (r3 + ((r1 << 3))); r3 = *((uint32_t*)(uintptr_t)(r3 + ((r1 << 3)))); r1 = *((uint32_t*)(uintptr_t)(r2 + (4u))); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x02061D88, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02061D88(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (32u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (40u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = (uint32_t)(*((int8_t*)(uintptr_t)(r1 + 1u))); r0 = (r1 + (r0)); r0 = ((r0 << 16)); r0 = (((uint32_t)((int32_t)r0 >> 16))); return r0; }

/* original module: 0, addr: 0x02061DB8, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02061DB8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (32u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (8u))); r1 = *((uint8_t*)(uintptr_t)(r0 + (1u))); r0 = (uint32_t)(*((int8_t*)(uintptr_t)(r0 + 4u))); r0 = (r1 - (r0)); r0 = ((r0 << 16)); r0 = (((uint32_t)((int32_t)r0 >> 16))); return r0; }

/* original module: 0, addr: 0x02062E44, 24 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02062E44(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r1 + (12u))); r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 10u))); *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 12u))); *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r1; return r0; }

/* original module: 0, addr: 0x02063FE4, 24 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02063FE4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x1u); r1 = *((uint32_t*)(uintptr_t)(r0 + (4u))); *((uint8_t*)(uintptr_t)(r0 + (8u))) = (uint8_t)r2; r0 = (0x0u); *((uint8_t*)(uintptr_t)(r1 + (42u))) = (uint8_t)r0; return r0; }

/* original module: 0, addr: 0x02065460, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02065460(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (88u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (92u))); } if (Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x0206547C, 48 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0206547C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = *((uint8_t*)(uintptr_t)(r0 + (113u))); r1 = *((uint32_t*)(uintptr_t)(r0 + (80u))); r3 = *((uint32_t*)(uintptr_t)(r0 + (88u))); r2 = (r1 * r12); { uint64_t z = (uint64_t)r3 - (uint64_t)(r2); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r3 >= (r2)); V = (((r3 ^ (r2)) & (r3 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N == V)) { r1 = *((uint32_t*)(uintptr_t)(r0 + (84u))); } if ((N == V)) { r2 = *((uint32_t*)(uintptr_t)(r0 + (92u))); } if ((N == V)) { r0 = (r1 * r12); } if ((N == V)) { { uint64_t z = (uint64_t)r2 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r0)); V = (((r2 ^ (r0)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } } if ((N == V)) { r0 = (0x1u); } if ((N != V)) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x0206590C, 36 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0206590C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = (0x0u); r3 = (0x2u); *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r12; *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r12; *((uint32_t*)(uintptr_t)(r0 + (148u))) = (uint32_t)r12; *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r1; *((uint32_t*)(uintptr_t)(r0 + (140u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (144u))) = (uint32_t)r3; return r0; }

/* original module: 0, addr: 0x0206678C, 36 bytes, BL refs: 13 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0206678C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 0u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x1au); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x1au)); V = (((r1 ^ (0x1au)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = *((uint32_t*)(uintptr_t)(r0 + (0u))); } if (!Z) { r1 = (r1 + (0x2u)); } if (Z) { r1 = *((uint8_t*)(uintptr_t)(r2 + (2u))); } if (Z) { r1 = (r2 + (r1)); } *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x020667B0, 32 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020667B0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = 0x020b20b8u; r2 = 0x0000ffffu; r3 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r12; *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r2; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x020667D8, 24 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020667D8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x0000ffffu; r3 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r2; return r0; }

/* original module: 0, addr: 0x020669B4, 24 bytes, BL refs: 10 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020669B4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 6u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0xffu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0xffu)); V = (((r0 ^ (0xffu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!C || Z)) { *((uint8_t*)(uintptr_t)(r1 + (0u))) = (uint8_t)r0; } if ((!C || Z)) { r0 = (0x1u); } if ((C && !Z)) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x02067BB4, 16 bytes, BL refs: 12 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02067BB4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (12u))); } if (!Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (16u))); } return r0; }

/* original module: 0, addr: 0x02068504, 20 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02068504(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + ((r0 << 1))); r0 = (r0 + (0x4u)); r0 = ((r0 << 16)); r0 = ((r0 >> 16)); return r0; }

/* original module: 0, addr: 0x020691B4, 36 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020691B4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r2 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 38u))); r0 = *((uint32_t*)(uintptr_t)(r1 + (8u))); r0 = ((r0 << 3)); r0 = (r0 + (0x6u)); { uint64_t z = (uint64_t)r2 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (r0)); V = (((r2 ^ (r0)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!Z && N == V)) { r0 = (0x1u); } if ((Z || N != V)) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x0206981C, 40 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0206981C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (64u))); r1 = (0x1u); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 0u))); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { r1 = (0x0u); } r0 = (0x1u); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x0206AC84, 20 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0206AC84(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (0x14u); r2 = (r1 * r0); r0 = 0x020aa5a8u; r0 = *((uint8_t*)(uintptr_t)(r0 + (r2))); return r0; }

/* original module: 0, addr: 0x0206AC9C, 20 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0206AC9C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (0x14u); r2 = (r1 * r0); r0 = 0x020aa5aau; r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + r2))); return r0; }

/* original module: 0, addr: 0x0206ACB4, 24 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0206ACB4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (0x14u); r2 = (r1 * r0); r0 = 0x020aa5a9u; r0 = *((uint8_t*)(uintptr_t)(r0 + (r2))); r0 = (r0 + (0x80u)); return r0; }

/* original module: 0, addr: 0x0206ACD0, 20 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0206ACD0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x020aa5acu; r0 = (0x14u); r0 = (r1 * r0 + r3); r0 = *((uint8_t*)(uintptr_t)(r2 + (r0))); return r0; }

/* original module: 0, addr: 0x0206AEB4, 32 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0206AEB4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (48u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x100u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x100u)); V = (((r0 ^ (0x100u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r2 = (r1 * r0); } if (!Z) { r0 = (((uint32_t)((int32_t)r2 >> 7))); } if (!Z) { r0 = (r2 + ((r0 >> 24))); } if (!Z) { r1 = (((uint32_t)((int32_t)r0 >> 8))); } r0 = (r1); return r0; }

/* original module: 0, addr: 0x0206AF94, 52 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0206AF94(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x0u); r2 = (0x7fu); r1 = (0x28u); *((uint8_t*)(uintptr_t)(r0 + (16u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r0 + (17u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r0 + (18u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r0 + (19u))) = (uint8_t)r3; *((uint32_t*)(uintptr_t)(r0 + (20u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (24u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (28u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (32u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (36u))) = (uint32_t)r3; return r0; }

/* original module: 0, addr: 0x0206D32C, 12 bytes, BL refs: 6 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0206D32C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x000003ffu; r0 = (r0 & (r1)); return r0; }

/* original module: 0, addr: 0x02070138, 28 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02070138(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x0u); r2 = (r3 - (0x1u)); { uint64_t z = (uint64_t)r1 - (uint64_t)(r2); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r2)); V = (((r1 ^ (r2)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = (0xb4u); } *((uint8_t*)(uintptr_t)(r0 + (5u))) = (uint8_t)r3; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x02070C98, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02070C98(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02049a2cu; r1 = *((uint32_t*)(uintptr_t)(r0 + (8u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = 0x02070d69u; } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; } return r0; }

/* original module: 0, addr: 0x020712B4, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020712B4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint8_t*)(uintptr_t)(r0 + (12u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = *((uint8_t*)(uintptr_t)(r0 + (48u))); } if (Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = *((uint8_t*)(uintptr_t)(r0 + (92u))); } if (Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x02072D08, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02072D08(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (r0 + ((r1 << 2))); r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 0u))); r3 = *((uint32_t*)(uintptr_t)(r1 + (4u))); r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 2u))); *((uint16_t*)(uintptr_t)(r3 + 6u)) = (uint16_t)r0; r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 4u))); *((uint16_t*)(uintptr_t)(r3 + 8u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r3 + 10u)) = (uint16_t)r0; return r0; }

/* original module: 0, addr: 0x020731C8, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020731C8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r3 = 0x020b22d0u; r1 = (r2 - (0x1u)); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r0 + 8u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 10u)) = (uint16_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (20u))) = (uint32_t)r2; return r0; }

/* original module: 0, addr: 0x020771D0, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020771D0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + ((r1 << 2))); r1 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (12u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x020774B4, 12 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020774B4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x0204a110u; r0 = *((uint32_t*)(uintptr_t)(r0 + (3572u))); return r0; }

/* original module: 0, addr: 0x020786CC, 12 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
uint32_t st_ov000_020786CC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (560u))); r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 6u))); return r0; }

/* original module: 0, addr: 0x02078EA0, 16 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02078EA0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x18u); r0 = (r1 * r2 + r0); r0 = *((uint32_t*)(uintptr_t)(r0 + (24u))); return r0; }

/* original module: 0, addr: 0x0207901C, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
void st_ov000_0207901C(volatile unsigned char *obj) {
    *(volatile unsigned short *)(obj + 16u) = 0u;
    *(volatile unsigned short *)(obj + 18u) = 0u;
    *(volatile unsigned int *)(obj + 20u) = 0u;
}

/* original module: 0, addr: 0x02079304, 28 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02079304(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020b259cu; r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 8u)) = (uint16_t)r1; return r0; }

/* original module: 0, addr: 0x0207995C, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0207995C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r3 = (0x148u); r1 = (0x1u); *((uint16_t*)(uintptr_t)(r0 + 48u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 42u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 44u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 46u)) = (uint16_t)r2; *((uint8_t*)(uintptr_t)(r0 + (80u))) = (uint8_t)r1; return r0; }

/* original module: 0, addr: 0x0207C04C, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0207C04C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x2u); r1 = (0x0u); r12 = 0x020b2894u; r2 = (r3 - (0x3u)); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r12; *((uint8_t*)(uintptr_t)(r0 + (4u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r0 + (5u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (6u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (7u))) = (uint8_t)r1; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x0207E7A4, 40 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT, round 15. */
void st_ov000_0207E7A4(volatile uint8_t *object, uint32_t r1, uint32_t r2, uint32_t r3) {
    uint32_t r12 = 0;
    r1 = (0x0u); *((volatile uint16_t*)(uintptr_t)(object + 0u)) = (uint16_t)r1; *((volatile uint16_t*)(uintptr_t)(object + 2u)) = (uint16_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (4u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (8u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (12u))) = (uint32_t)r1; *((volatile uint32_t*)(uintptr_t)(object + (16u))) = (uint32_t)r1; *((volatile uint16_t*)(uintptr_t)(object + 20u)) = (uint16_t)r1; *((volatile uint16_t*)(uintptr_t)(object + 22u)) = (uint16_t)r1;;
}

/* original module: 0, addr: 0x0208009C, 20 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0208009C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0c90u; r1 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r0 = (r1 + ((r0 << 12))); r0 = (r0 + (0x800u)); return r0; }

/* original module: 0, addr: 0x020800B4, 20 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020800B4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x027e0c90u; r1 = *((uint32_t*)(uintptr_t)(r1 + (8u))); r0 = (r1 + ((r0 << 12))); r0 = (r0 + (0x800u)); return r0; }

/* original module: 0, addr: 0x02080194, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02080194(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (304u))); r2 = *((uint8_t*)(uintptr_t)(r1 + (0u))); r1 = *((uint8_t*)(uintptr_t)(r1 + (1u))); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r3 + 8u))); r3 = (r3 + (0xcu)); r0 = (r1 * r0 + r2); r0 = (r3 + ((r0 << 2))); return r0; }

/* original module: 0, addr: 0x02081660, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02081660(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (12u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r2 = *((uint32_t*)(uintptr_t)(r3 + (32u))); } r0 = (0x1u); if (!Z) { r0 = (r2 | ((r0 << (r1&31u)))); } if (Z) { r0 = (~((r0 << (r1&31u)))); } if (Z) { r1 = *((uint32_t*)(uintptr_t)(r3 + (32u))); } if (Z) { r0 = (r1 & (r0)); } *((uint32_t*)(uintptr_t)(r3 + (32u))) = (uint32_t)r0; return r0; }

/* original module: 0, addr: 0x020816A0, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020816A0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r3 = *((uint32_t*)(uintptr_t)(r0 + (172u))); } r2 = (0x1u); if (!Z) { r1 = (r3 | ((r2 << (r1&31u)))); } if (Z) { r1 = (~((r2 << (r1&31u)))); } if (Z) { r2 = *((uint32_t*)(uintptr_t)(r0 + (172u))); } if (Z) { r1 = (r2 & (r1)); } *((uint32_t*)(uintptr_t)(r0 + (172u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x020816D8, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020816D8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r3 = *((uint32_t*)(uintptr_t)(r0 + (176u))); } r2 = (0x1u); if (!Z) { r1 = (r3 | ((r2 << (r1&31u)))); } if (Z) { r1 = (~((r2 << (r1&31u)))); } if (Z) { r2 = *((uint32_t*)(uintptr_t)(r0 + (176u))); } if (Z) { r1 = (r2 & (r1)); } *((uint32_t*)(uintptr_t)(r0 + (176u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x02081804, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02081804(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (12u))); r0 = ((r1 >> 5)); r0 = (r2 + ((r0 << 2))); r2 = *((uint32_t*)(uintptr_t)(r0 + (68u))); r1 = (r1 & (0x1fu)); r0 = (0x1u); { uint32_t z = r2 & ((r0 << (r1&31u))); Z = (z==0); N = (z>>31); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x02081828, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02081828(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (12u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r2 = *((uint32_t*)(uintptr_t)(r3 + (76u))); } r0 = (0x1u); if (!Z) { r0 = (r2 | ((r0 << (r1&31u)))); } if (Z) { r0 = (~((r0 << (r1&31u)))); } if (Z) { r1 = *((uint32_t*)(uintptr_t)(r3 + (76u))); } if (Z) { r0 = (r1 & (r0)); } *((uint32_t*)(uintptr_t)(r3 + (76u))) = (uint32_t)r0; return r0; }

/* original module: 0, addr: 0x02081868, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02081868(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (12u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r2 = *((uint32_t*)(uintptr_t)(r3 + (28u))); } r0 = (0x1u); if (!Z) { r0 = (r2 | ((r0 << (r1&31u)))); } if (Z) { r0 = (~((r0 << (r1&31u)))); } if (Z) { r1 = *((uint32_t*)(uintptr_t)(r3 + (28u))); } if (Z) { r0 = (r1 & (r0)); } *((uint32_t*)(uintptr_t)(r3 + (28u))) = (uint32_t)r0; return r0; }

/* original module: 0, addr: 0x02081D90, 32 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02081D90(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r0 = (0xau); r2 = *((uint8_t*)(uintptr_t)(r3 + (16u))); r1 = *((uint8_t*)(uintptr_t)(r3 + (17u))); r0 = (r2 * r0 + r3); r0 = (r0 + (r1)); r0 = *((uint8_t*)(uintptr_t)(r0 + (64u))); return r0; }

/* original module: 0, addr: 0x0208385C, 52 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0208385C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = (~(0x1u)); r1 = (0x0u); r3 = (r12 + (0x1u)); r2 = (0x1000u); *((uint16_t*)(uintptr_t)(r0 + 12u)) = (uint16_t)r12; *((uint16_t*)(uintptr_t)(r0 + 14u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 16u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 18u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 20u)) = (uint16_t)r1; *((uint8_t*)(uintptr_t)(r0 + (22u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (23u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (24u))) = (uint8_t)r1; return r0; }

/* original module: 0, addr: 0x02084728, 56 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02084728(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r1 = (r2 - (0x8000u)); r3 = (0x1000u); *((uint16_t*)(uintptr_t)(r0 + 154u)) = (uint16_t)r3; *((uint32_t*)(uintptr_t)(r0 + (156u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (160u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (164u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (168u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (172u))) = (uint32_t)r2; *((uint8_t*)(uintptr_t)(r0 + (178u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (179u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (141u))) = (uint8_t)r2; *((uint16_t*)(uintptr_t)(r0 + 142u)) = (uint16_t)r2; return r0; }

/* original module: 0, addr: 0x020849F4, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020849F4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 220u))); { uint32_t z = r1 & (0x4u); Z = (z==0); N = (z>>31); } if (!Z) { r1 = (0x0u); } if (Z) { r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 152u))); } r0 = (0xa4u); r0 = (r1 * r0); r0 = (r0 + (0x800u)); r0 = (((uint32_t)((int32_t)r0 >> 12))); return r0; }

/* original module: 0, addr: 0x02085B4C, 44 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02085B4C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r1 = (r2 - (0x1u)); *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 8u)) = (uint16_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (20u))) = (uint32_t)r2; return r0; }

/* original module: 0, addr: 0x02085D68, 32 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02085D68(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 2u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N != V)) { r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 0u))); } if ((N != V)) { r2 = (0x0u); } if ((N != V)) { *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r2; } if ((N != V)) { r1 = (r1 | (0x10u)); } if ((N != V)) { *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; } return r0; }

/* original module: 0, addr: 0x020872E4, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020872E4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = (0x4u); r3 = (0x1u); r2 = (0x8u); r1 = (0x0u); *((uint16_t*)(uintptr_t)(r0 + 12u)) = (uint16_t)r12; *((uint8_t*)(uintptr_t)(r0 + (16u))) = (uint8_t)r3; *((uint8_t*)(uintptr_t)(r0 + (17u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (18u))) = (uint8_t)r1; return r0; }

/* original module: 0, addr: 0x02087DE0, 20 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
void st_ov000_02087DE0(volatile unsigned char *obj, unsigned int value) {
    *(volatile unsigned int *)(obj + 0u) = 0u;
    *(volatile unsigned short *)(obj + 4u) = (unsigned short)value;
    *(volatile unsigned short *)(obj + 6u) = 0u;
}

/* original module: 0, addr: 0x02088E20, 32 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02088E20(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N == V)) { r3 = 0x020ab530u; } if ((N != V)) { r0 = (0x0u); } if ((N == V)) { r2 = (0x9cu); } if ((N == V)) { r2 = (r0 * r2 + r3); } if ((N == V)) { r0 = *((uint32_t*)(uintptr_t)(r2 + (84u))); } if ((N == V)) { r0 = (r0 + ((r1 << 5))); } return r0; }

/* original module: 0, addr: 0x02088EEC, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02088EEC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (8u))); r2 = (0x0u); r1 = (r1 + (0x100u)); *((uint16_t*)(uintptr_t)(r1 + 36u)) = (uint16_t)r2; return r0; }

/* original module: 0, addr: 0x02089FC0, 36 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02089FC0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 16u))); r2 = (0x0u); r3 = (~(0x0u)); *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 8u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 10u)) = (uint16_t)r2; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r0 + 18u)) = (uint16_t)r1; return r0; }

/* original module: 0, addr: 0x02089FE4, 24 bytes, BL refs: 12 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02089FE4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r12 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 6u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(r12); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r12)); V = (((r1 ^ (r12)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N == V)) { *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r1; } if ((N == V)) { *((uint16_t*)(uintptr_t)(r0 + 10u)) = (uint16_t)r2; } if ((N == V)) { *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r3; } return r0; }

/* original module: 0, addr: 0x0208A7F0, 40 bytes, BL refs: 26 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0208A7F0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r1 + (8u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (12u))); r2 = (r1 - (r3)); r1 = (((uint32_t)((int32_t)r2 >> 1))); r1 = (r2 + ((r1 >> 30))); r1 = (((uint32_t)((int32_t)r1 >> 2))); Z = (r1==0); N = (r1>>31); if (!Z) { r1 = *((uint32_t*)(uintptr_t)(r3 + (0u))); } if (Z) { r1 = (0x0u); } *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x0208AED0, 16 bytes, BL refs: 8 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0208AED0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020ace0cu; r1 = (0x6u); r0 = (r1 * r0 + r2); return r0; }

/* original module: 0, addr: 0x0208BAAC, 32 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0208BAAC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (36u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x0u); } if (Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (64u))); } if (Z) { r0 = (r0 + ((r1 << 2))); } if (Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (812u))); } if (Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (72u))); } return r0; }

/* original module: 0, addr: 0x0208DC40, 24 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0208DC40(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (112u))); r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 90u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x5eu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x5eu)); V = (((r0 ^ (0x5eu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x0208E770, 44 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_0208E770(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(r3); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r3)); V = (((r1 ^ (r3)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r3 = (0x0u); } if (!Z) { *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r3; } r12 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 4u))); r3 = (0xfu); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; r1 = (r12 + (r2)); *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r3; return r0; }

/* original module: 0, addr: 0x02091F5C, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02091F5C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (104u))); r0 = (0x18u); r3 = (r2 * r0); r0 = 0x020ad080u; r0 = *((uint32_t*)(uintptr_t)(r0 + (r3))); { uint64_t z = (uint64_t)r1 - (uint64_t)(r0); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (r0)); V = (((r1 ^ (r0)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x020930BC, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020930BC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (104u))); r1 = 0x020ad080u; r0 = (0x18u); r0 = (r2 * r0 + r1); r0 = *((uint32_t*)(uintptr_t)(r0 + (20u))); { uint32_t z = r0 & (0x1u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x020930E4, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020930E4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (104u))); r1 = 0x020ad080u; r0 = (0x18u); r0 = (r2 * r0 + r1); r0 = *((uint32_t*)(uintptr_t)(r0 + (20u))); { uint32_t z = r0 & (0x100000u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x02093FAC, 28 bytes, BL refs: 7 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02093FAC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (24u))); r0 = (0x0u); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = *((uint8_t*)(uintptr_t)(r1 + (4u))); } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { r0 = (0x1u); } return r0; }

/* original module: 0, addr: 0x02096B48, 40 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02096B48(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x0u); r2 = (~(0x0u)); *((uint16_t*)(uintptr_t)(r0 + 64u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 78u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 76u)) = (uint16_t)r1; *((uint32_t*)(uintptr_t)(r0 + (84u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (80u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (88u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 92u)) = (uint16_t)r2; return r0; }

/* original module: 0, addr: 0x02096BFC, 36 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02096BFC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x0u); r2 = (r3 - (0x1u)); r1 = (0xffu); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r3; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; *((uint8_t*)(uintptr_t)(r0 + (12u))) = (uint8_t)r1; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r3; return r0; }

/* original module: 0, addr: 0x02096C7C, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02096C7C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r1 = (r2 - (0x1u)); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r2; return r0; }

/* original module: 0, addr: 0x02097C40, 40 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_02097C40(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r1 = (0x12u); *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (20u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (24u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r0 + 30u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 28u)) = (uint16_t)r1; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; return r0; }

/* original module: 0, addr: 0x0209F16C, 12 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: BYTE-EXACT */
uint32_t st_ov000_0209F16C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 48u))); return r0; }

/* original module: 0, addr: 0x020A2B0C, 12 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A2B0C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x100u)); *((uint16_t*)(uintptr_t)(r0 + 112u)) = (uint16_t)r1; return r0; }

/* original module: 0, addr: 0x020A3950, 20 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A3950(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (12u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x0u); } if (!Z) { r0 = (0x10u); } return r0; }

/* original module: 0, addr: 0x020A44D0, 20 bytes, BL refs: 5 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A44D0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (312u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!Z && N == V)) { r0 = (0x1u); } if ((Z || N != V)) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x020A4B40, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A4B40(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 30u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x60u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x60u)); V = (((r0 ^ (0x60u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((N != V)) { r0 = (0x1u); } if ((N == V)) { r0 = (0x0u); } return r0; }

/* original module: 0, addr: 0x020A5568, 20 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A5568(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (36u))); r2 = (0x0u); r0 = (r0 + ((r1 << 4))); *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r2; return r0; }

/* original module: 0, addr: 0x020A557C, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A557C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (36u))); r0 = 0x020a779cu; r3 = (r3 + ((r1 << 4))); *((uint32_t*)(uintptr_t)(r3 + (8u))) = (uint32_t)r0; r0 = (0x0u); r1 = *((uint32_t*)(uintptr_t)(r2 + (0u))); *((uint32_t*)(uintptr_t)(r3 + (4u))) = (uint32_t)r0; *((uint32_t*)(uintptr_t)(r3 + (12u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x020A55A4, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A55A4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (36u))); r0 = 0x020a77b0u; r3 = (r3 + ((r1 << 4))); *((uint32_t*)(uintptr_t)(r3 + (8u))) = (uint32_t)r0; r0 = (0x0u); r1 = *((uint32_t*)(uintptr_t)(r2 + (0u))); *((uint32_t*)(uintptr_t)(r3 + (4u))) = (uint32_t)r0; *((uint32_t*)(uintptr_t)(r3 + (12u))) = (uint32_t)r1; return r0; }

/* original module: 0, addr: 0x020A5688, 32 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A5688(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } r0 = 0x027e09bcu; r1 = (0x1u); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); if (Z) { r1 = (0x0u); } r0 = (r0 + ((r1 << 2))); r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); return r0; }

/* original module: 0, addr: 0x020A56AC, 32 bytes, BL refs: 4 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A56AC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } r0 = 0x027e09bcu; r1 = (0x1u); r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); if (Z) { r1 = (0x0u); } r0 = (r0 + ((r1 << 2))); r0 = *((uint32_t*)(uintptr_t)(r0 + (12u))); return r0; }

/* original module: 0, addr: 0x020A61D0, 28 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: SHA256 BYTE-EXACT (round 16). */
uint32_t st_ov000_020A61D0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) {
uint32_t r12 = 0;
 r2 = *((volatile uint32_t*)(uintptr_t)(r0 + (2048u))); uint32_t cmp_lhs = r2, cmp_rhs = 0x0u; unsigned Z = (cmp_lhs == cmp_rhs); unsigned C = (cmp_lhs >= cmp_rhs); unsigned GE = ((int32_t)cmp_lhs >= (int32_t)cmp_rhs); if (!Z) { *((volatile uint32_t*)(uintptr_t)(r2 + (0u))) = (uint32_t)r1; } r1 = *((volatile uint32_t*)(uintptr_t)(r0 + (2048u))); r1 = (r1 + (0x4u)); *((volatile uint32_t*)(uintptr_t)(r0 + (2048u))) = (uint32_t)r1;
return r0;
}

/* original module: 0, addr: 0x020A62B8, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A62B8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (2048u))); r3 = (r2 - (r0)); r2 = (((uint32_t)((int32_t)r3 >> 1))); r2 = (r3 + ((r2 >> 30))); { uint64_t z = (uint64_t)r1 - (uint64_t)(((uint32_t)((int32_t)r2 >> 2))); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (((uint32_t)((int32_t)r2 >> 2)))); V = (((r1 ^ (((uint32_t)((int32_t)r2 >> 2)))) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (C) { r0 = (0x0u); } if (!C) { r0 = *((uint32_t*)(uintptr_t)(r0 + ((r1 << 2)))); } return r0; }

/* original module: 0, addr: 0x020A6B70, 36 bytes, BL refs: 2 */
/* Clang ARMv5TE standalone: COMPLETE SHA256 BYTE-EXACT (round 14). */
uint32_t st_ov000_020A6B70(volatile uint8_t *object) {
    *(volatile uint32_t *)(object + 0) = 0u;
    *(volatile uint32_t *)(object + 4) = 0u;
    *(volatile uint32_t *)(object + 8) = 0u;
    *(volatile uint8_t *)(object + 12) = 0u;
    *(volatile uint8_t *)(object + 13) = 0u;
    *(volatile uint32_t *)(object + 24) = 0u;
    *(volatile uint32_t *)(object + 28) = 0u;
    return (uint32_t)(uintptr_t)object;
}

/* original module: 0, addr: 0x020A7764, 32 bytes, BL refs: 1 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A7764(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r2 = (~(0x0u)); r12 = (r2 - (r3)); { uint64_t z = (uint64_t)r12 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r12 >= (r1)); V = (((r12 ^ (r1)) & (r12 ^ (uint32_t)z) & 0x80000000u) != 0); } if ((!C || Z)) { *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r2; } if ((C && !Z)) { r1 = (r3 + (r1)); } if ((C && !Z)) { *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; } return r0; }

/* original module: 0, addr: 0x020A7880, 16 bytes, BL refs: 3 */
/* Clang ARMv5TE standalone: SEMANTIC C ONLY - NOT BYTE-EXACT */
uint32_t st_ov000_020A7880(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x020af7d4u; r1 = (0x1cu); r0 = (r1 * r0 + r2); return r0; }
