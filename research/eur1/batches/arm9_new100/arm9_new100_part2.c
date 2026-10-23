/* Spirit Tracks EUR Rev 1, new BL-referenced 100-function research batch, part 2/2. */
/* Matching status is measured per original ARM code span; CodeWarrior is NOT tested. */
/* Some C ABI signatures and register-oriented translations are PROVISIONAL. */
#include <stdint.h>

/* st_ov063_0215A6F8, module 63, original 0x0215A6F8, 24 bytes, register_C_provisional */
uint32_t st_ov063_0215A6F8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (616u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = 0x00000385u; } if (Z) { r0 = 0x020aed50u; } if (Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); } return r0; }

/* st_ov063_02160E7C, module 63, original 0x02160E7C, 24 bytes, register_C_provisional */
uint32_t st_ov063_02160E7C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x0000ffffu; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (160u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 166u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 164u)) = (uint16_t)r2; return r0; }

/* st_ov068_0215E384, module 68, original 0x0215E384, 24 bytes, register_C_provisional */
uint32_t st_ov068_0215E384(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 6u))); r1 = 0x0000fffbu; r2 = (r2 | (0x2u)); r1 = (r2 & (r1)); *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r1; return r0; }

/* st_ov069_0215AB1C, module 69, original 0x0215AB1C, 24 bytes, register_C_provisional */
uint32_t st_ov069_0215AB1C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x0000ffffu; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (160u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 166u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 164u)) = (uint16_t)r2; return r0; }

/* st_ov007_020B7B8C, module 7, original 0x020B7B8C, 24 bytes, typed_C_Clang_exact */
void st_ov007_020B7B8C(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[231u] = 1u; ((volatile unsigned char*)p0)[230u] = 1u; ((volatile unsigned char*)p0)[451u] = 1u; ((volatile unsigned char*)p0)[450u] = 1u; }

/* st_ov007_020B7BA4, module 7, original 0x020B7BA4, 24 bytes, typed_C_Clang_exact */
void st_ov007_020B7BA4(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[231u] = 0u; ((volatile unsigned char*)p0)[230u] = 0u; ((volatile unsigned char*)p0)[451u] = 0u; ((volatile unsigned char*)p0)[450u] = 0u; }

/* st_ov071_021561E4, module 71, original 0x021561E4, 24 bytes, register_C_provisional */
uint32_t st_ov071_021561E4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 76u))); r0 = (0x0u); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x6u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x6u)); V = (((r1 ^ (0x6u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x10u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x10u)); V = (((r1 ^ (0x10u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { r0 = (0x1u); } return r0; }

/* st_ov071_0215B608, module 71, original 0x0215B608, 16 bytes, typed_C_Clang_exact */
void st_ov071_0215B608(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[0u] = 0u; ((volatile unsigned char*)p0)[1u] = 0u; }

/* st_ov077_02158BBC, module 77, original 0x02158BBC, 24 bytes, register_C_provisional */
uint32_t st_ov077_02158BBC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 76u))); r0 = (0x1u); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x3u)); V = (((r1 ^ (0x3u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x4u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x4u)); V = (((r1 ^ (0x4u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { r0 = (0x0u); } return r0; }

/* st_ov084_0215C050, module 84, original 0x0215C050, 24 bytes, register_C_provisional */
uint32_t st_ov084_0215C050(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = (r1 - (0x1u)); } if (!Z) { r0 = (r0 + ((r1 << 2))); } if (!Z) { r0 = *((uint32_t*)(uintptr_t)(r0 + (1000u))); } r0 = (r0 + (0x4u)); return r0; }

/* st_ov084_0215C21C, module 84, original 0x0215C21C, 16 bytes, typed_C_Clang_exact */
void st_ov084_0215C21C(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[0u] = 0u; ((volatile unsigned char*)p0)[1u] = 0u; }

/* st_ov088_02169B0C, module 88, original 0x02169B0C, 24 bytes, register_C_provisional */
uint32_t st_ov088_02169B0C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x19u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x19u)); V = (((r1 ^ (0x19u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = *((uint32_t*)(uintptr_t)(r2 + (0u))); } if (Z) { r1 = ((r1 << 16)); } if (Z) { r1 = ((r1 >> 16)); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (140u))) = (uint32_t)r1; } return r0; }

/* st_ov088_02169B7C, module 88, original 0x02169B7C, 24 bytes, register_C_provisional */
uint32_t st_ov088_02169B7C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x1u)); V = (((r1 ^ (0x1u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r2 = (0x0u); } if (Z) { r1 = (0x1u); } if (Z) { *((uint32_t*)(uintptr_t)(r0 + (148u))) = (uint32_t)r2; } if (Z) { *((uint8_t*)(uintptr_t)(r0 + (160u))) = (uint8_t)r1; } return r0; }

/* st_ov091_0216FA78, module 91, original 0x0216FA78, 24 bytes, register_C_provisional */
uint32_t st_ov091_0216FA78(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x0u); r1 = (r0 + (0x900u)); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r1 + 116u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r1 + 118u)) = (uint16_t)r2; return r0; }

/* st_ov092_021708B0, module 92, original 0x021708B0, 68 bytes, register_C_provisional */
uint32_t st_ov092_021708B0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r2 = (0x0u); } if (Z) { r2 = (0x4u); } r2 = (r1 + (r2)); r1 = (r0 + (0x200u)); r0 = (0x1u); { uint64_t z = (uint64_t)r3 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r3 >= (0x0u)); V = (((r3 ^ (0x0u)) & (r3 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = ((r0 << (r2&31u))); } if (!Z) { r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 124u))); } if (!Z) { r0 = ((r0 << 16)); } if (!Z) { r0 = (r2 | ((r0 >> 16))); } if (Z) { r0 = (~((r0 << (r2&31u)))); } if (Z) { r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r1 + 124u))); } if (Z) { r0 = ((r0 << 16)); } if (Z) { r0 = (r2 & ((r0 >> 16))); } *((uint16_t*)(uintptr_t)(r1 + 124u)) = (uint16_t)r0; return r0; }

/* st_ov093_02171F1C, module 93, original 0x02171F1C, 24 bytes, register_C_provisional */
uint32_t st_ov093_02171F1C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r1 - (uint64_t)(0x25u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x25u)); V = (((r1 ^ (0x25u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x26u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x26u)); V = (((r1 ^ (0x26u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x27u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x27u)); V = (((r1 ^ (0x27u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* st_ov094_0217485C, module 94, original 0x0217485C, 24 bytes, register_C_provisional */
uint32_t st_ov094_0217485C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (64u))); r0 = (0x1u); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x2u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x2u)); V = (((r1 ^ (0x2u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x3u)); V = (((r1 ^ (0x3u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (!Z) { r0 = (0x0u); } return r0; }

/* st_ov094_0217533C, module 94, original 0x0217533C, 24 bytes, register_C_provisional */
uint32_t st_ov094_0217533C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x0000ffffu; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (160u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 166u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 164u)) = (uint16_t)r2; return r0; }

/* st_arm9_02000B60, module arm9, original 0x02000B60, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_02000B60(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_02001804, module arm9, original 0x02001804, 24 bytes, register_C_provisional */
uint32_t st_arm9_02001804(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x02044dd0u; r2 = (0x0u); r0 = 0x02044e18u; *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r2; return r0; }

/* st_arm9_020037C0, module arm9, original 0x020037C0, 24 bytes, register_C_provisional */
uint32_t st_arm9_020037C0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02045cccu; r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; return r0; }

/* st_arm9_0200503C, module arm9, original 0x0200503C, 24 bytes, register_C_provisional */
uint32_t st_arm9_0200503C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = (0x0u); } if (!Z) { *((uint32_t*)(uintptr_t)(r2 + (332u))) = (uint32_t)r1; } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; } return r0; }

/* st_arm9_02006C50, module arm9, original 0x02006C50, 24 bytes, register_C_provisional */
uint32_t st_arm9_02006C50(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02046c4cu; r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; r1 = *((uint32_t*)(uintptr_t)(r0 + (8u))); *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; return r0; }

/* st_arm9_020077E0, module arm9, original 0x020077E0, 24 bytes, register_C_provisional */
uint32_t st_arm9_020077E0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 12u)) = (uint16_t)r1; return r0; }

/* st_arm9_02007E74, module arm9, original 0x02007E74, 24 bytes, register_C_provisional */
uint32_t st_arm9_02007E74(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = *((uint8_t*)(uintptr_t)(r0 + (1u))); r2 = 0x0203de2cu; r1 = *((uint8_t*)(uintptr_t)(r0 + (0u))); r0 = (r2 + ((r3 << 4))); r0 = *((uint32_t*)(uintptr_t)(r0 + ((r1 << 2)))); return r0; }

/* st_arm9_0200B6B0, module arm9, original 0x0200B6B0, 8 bytes, register_C_Clang_exact */
uint32_t st_arm9_0200B6B0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r1; return r0; }

/* st_arm9_02014218, module arm9, original 0x02014218, 24 bytes, register_C_provisional */
uint32_t st_arm9_02014218(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 0u))); r3 = (0x0u); *((uint16_t*)(uintptr_t)(r0 + 32u)) = (uint16_t)r3; r1 = (r2 + (r1)); *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; return r0; }

/* st_arm9_020167A8, module arm9, original 0x020167A8, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_020167A8(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_020177CC, module arm9, original 0x020177CC, 24 bytes, typed_C_Clang_exact */
void st_arm9_020177CC(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[4u] = 0u; ((volatile unsigned int*)p0)[2u] = 0u; ((volatile unsigned int*)p0)[3u] = 0u; ((volatile unsigned int*)p0)[4u] = 0u; }

/* st_arm9_02018C78, module arm9, original 0x02018C78, 24 bytes, register_C_provisional */
uint32_t st_arm9_02018C78(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (8u))); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x1u)); V = (((r2 ^ (0x1u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r1 = (r1 + (0x1u)); } if (Z) { r1 = (((uint32_t)((int32_t)r1 >> 1))); } *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r1; return r0; }

/* st_arm9_0201BBCC, module arm9, original 0x0201BBCC, 24 bytes, register_C_provisional */
uint32_t st_arm9_0201BBCC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (0x0u); *((uint8_t*)(uintptr_t)(r0 + (13u))) = (uint8_t)r1; *((uint8_t*)(uintptr_t)(r0 + (14u))) = (uint8_t)r3; *((uint16_t*)(uintptr_t)(r0 + 16u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 32u)) = (uint16_t)r3; return r0; }

/* st_arm9_0201CD68, module arm9, original 0x0201CD68, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_0201CD68(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_0201EC30, module arm9, original 0x0201EC30, 8 bytes, register_C_Clang_exact */
uint32_t st_arm9_0201EC30(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (16u))); return r0; }

/* st_arm9_02020404, module arm9, original 0x02020404, 24 bytes, register_C_provisional */
uint32_t st_arm9_02020404(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (0x1u); r1 = *((uint32_t*)(uintptr_t)(r0 + (8u))); *((uint8_t*)(uintptr_t)(r0 + (24u))) = (uint8_t)r2; r0 = (0x4u); *((uint16_t*)(uintptr_t)(r1 + 22u)) = (uint16_t)r0; return r0; }

/* st_arm9_02021E00, module arm9, original 0x02021E00, 8 bytes, register_C_Clang_exact */
uint32_t st_arm9_02021E00(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (8u))); return r0; }

/* st_arm9_0202288C, module arm9, original 0x0202288C, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_0202288C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_02022890, module arm9, original 0x02022890, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_02022890(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_02022894, module arm9, original 0x02022894, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_02022894(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_02026730, module arm9, original 0x02026730, 8 bytes, register_C_Clang_exact */
uint32_t st_arm9_02026730(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 4u))); return r0; }

/* st_arm9_020271B0, module arm9, original 0x020271B0, 8 bytes, register_C_Clang_exact */
uint32_t st_arm9_020271B0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (0x0u); return r0; }

/* st_arm9_0202B56C, module arm9, original 0x0202B56C, 8 bytes, register_C_Clang_exact */
uint32_t st_arm9_0202B56C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (56u))); return r0; }

/* st_arm9_02032124, module arm9, original 0x02032124, 68 bytes, register_C_provisional */
uint32_t st_arm9_02032124(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x04000204u; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 0u))); r1 = (r1 & (0xcu)); r1 = (((uint32_t)((int32_t)r1 >> 2))); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 0u))); r1 = (r1 & (0x10u)); r1 = (((uint32_t)((int32_t)r1 >> 4))); *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 0u))); r0 = (r0 & ~(0xcu)); r0 = (r0 | (0xcu)); *((uint16_t*)(uintptr_t)(r2 + 0u)) = (uint16_t)r0; r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r2 + 0u))); r0 = (r0 & ~(0x10u)); *((uint16_t*)(uintptr_t)(r2 + 0u)) = (uint16_t)r0; return r0; }

/* st_arm9_020338EC, module arm9, original 0x020338EC, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_020338EC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_02033E50, module arm9, original 0x02033E50, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_02033E50(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_0203B920, module arm9, original 0x0203B920, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_0203B920(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_0203B930, module arm9, original 0x0203B930, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_0203B930(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_0203B934, module arm9, original 0x0203B934, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_0203B934(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_0203B938, module arm9, original 0x0203B938, 8 bytes, register_C_Clang_exact */
uint32_t st_arm9_0203B938(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (0x0u); return r0; }

/* st_arm9_0203D26C, module arm9, original 0x0203D26C, 4 bytes, register_C_Clang_exact */
uint32_t st_arm9_0203D26C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; return r0; }

/* st_arm9_0203D410, module arm9, original 0x0203D410, 24 bytes, register_C_provisional */
uint32_t st_arm9_0203D410(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x0203d5fcu; r1 = 0x0203d824u; *((uint32_t*)(uintptr_t)(r0 + (12u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (16u))) = (uint32_t)r1; r0 = (0x1u); return r0; }
