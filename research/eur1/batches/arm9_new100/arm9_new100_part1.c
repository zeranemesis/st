/* Spirit Tracks EUR Rev 1, new BL-referenced 100-function research batch, part 1/2. */
/* Matching status is measured per original ARM code span; CodeWarrior is NOT tested. */
/* Some C ABI signatures and register-oriented translations are PROVISIONAL. */
#include <stdint.h>

/* st_ov000_02057EE0, module 0, original 0x02057EE0, 20 bytes, register_C_provisional */
uint32_t st_ov000_02057EE0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (r0 + (0x14u)); } if (Z) { r0 = (0x0u); } return r0; }

/* st_ov000_0205D0FC, module 0, original 0x0205D0FC, 28 bytes, register_C_provisional */
uint32_t st_ov000_0205D0FC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x5053424bu; { uint64_t z = (uint64_t)r0 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (r1)); V = (((r0 ^ (r1)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = 0x50535742u; } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (r1)); V = (((r0 ^ (r1)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* st_ov000_0205D368, module 0, original 0x0205D368, 28 bytes, register_C_provisional */
uint32_t st_ov000_0205D368(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x47525353u; { uint64_t z = (uint64_t)r0 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (r1)); V = (((r0 ^ (r1)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = 0x53575354u; } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(r1); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (r1)); V = (((r0 ^ (r1)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* st_ov000_02062E5C, module 0, original 0x02062E5C, 24 bytes, register_C_provisional */
uint32_t st_ov000_02062E5C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r1 + (12u))); r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 14u))); *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r2 + 16u))); *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r1; return r0; }

/* st_ov000_0206C6C4, module 0, original 0x0206C6C4, 24 bytes, register_C_provisional */
uint32_t st_ov000_0206C6C4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r2 = (0x1u); *((uint16_t*)(uintptr_t)(r1 + 14u)) = (uint16_t)r2; r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); *((uint16_t*)(uintptr_t)(r0 + 14u)) = (uint16_t)r2; return r0; }

/* st_ov000_0208116C, module 0, original 0x0208116C, 24 bytes, register_C_provisional */
uint32_t st_ov000_0208116C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r2 = *((uint32_t*)(uintptr_t)(r0 + (76u))); } r0 = *((uint32_t*)(uintptr_t)(r0 + (28u))); if (!Z) { *((uint32_t*)(uintptr_t)(r1 + (0u))) = (uint32_t)r2; } *((uint32_t*)(uintptr_t)(r1 + (4u))) = (uint32_t)r0; return r0; }

/* st_ov000_02081688, module 0, original 0x02081688, 24 bytes, register_C_provisional */
uint32_t st_ov000_02081688(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (12u))); r0 = (0x1u); r2 = *((uint32_t*)(uintptr_t)(r2 + (32u))); { uint32_t z = r2 & ((r0 << (r1&31u))); Z = (z==0); N = (z>>31); } if (Z) { r0 = (0x0u); } return r0; }

/* st_ov000_02081850, module 0, original 0x02081850, 24 bytes, register_C_provisional */
uint32_t st_ov000_02081850(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (12u))); r0 = (0x1u); r2 = *((uint32_t*)(uintptr_t)(r2 + (76u))); { uint32_t z = r2 & ((r0 << (r1&31u))); Z = (z==0); N = (z>>31); } if (Z) { r0 = (0x0u); } return r0; }

/* st_ov000_02081890, module 0, original 0x02081890, 24 bytes, register_C_provisional */
uint32_t st_ov000_02081890(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = *((uint32_t*)(uintptr_t)(r0 + (12u))); r0 = (0x1u); r2 = *((uint32_t*)(uintptr_t)(r2 + (28u))); { uint32_t z = r2 & ((r0 << (r1&31u))); Z = (z==0); N = (z>>31); } if (Z) { r0 = (0x0u); } return r0; }

/* st_ov000_0208E758, module 0, original 0x0208E758, 24 bytes, register_C_provisional */
uint32_t st_ov000_0208E758(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x0u); r2 = (~(0x0u)); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r2; *((uint16_t*)(uintptr_t)(r0 + 4u)) = (uint16_t)r1; *((uint16_t*)(uintptr_t)(r0 + 6u)) = (uint16_t)r1; return r0; }

/* st_ov000_0209C938, module 0, original 0x0209C938, 8 bytes, register_C_Clang_exact */
uint32_t st_ov000_0209C938(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((int8_t*)(uintptr_t)(r0 + 14u))); return r0; }

/* st_ov000_0209DACC, module 0, original 0x0209DACC, 72 bytes, register_C_provisional */
uint32_t st_ov000_0209DACC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = (r1 + (0x9u)); r12 = (0x1u); { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r3 = ((r12 << (r3&31u))); } if (!Z) { r12 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 28u))); } if (!Z) { r3 = ((r3 << 16)); } r1 = (r0 + (r1)); if (!Z) { r3 = (r12 | ((r3 >> 16))); } if (Z) { r3 = (~((r12 << (r3&31u)))); } if (Z) { r12 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 28u))); } if (Z) { r3 = ((r3 << 16)); } if (Z) { r3 = (r12 & ((r3 >> 16))); } *((uint16_t*)(uintptr_t)(r0 + 28u)) = (uint16_t)r3; { uint64_t z = (uint64_t)r2 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r2 >= (0x0u)); V = (((r2 ^ (0x0u)) & (r2 ^ (uint32_t)z) & 0x80000000u) != 0); } *((uint8_t*)(uintptr_t)(r1 + (70u))) = (uint8_t)r2; if (!Z) { r0 = (0x2u); } if (!Z) { *((uint8_t*)(uintptr_t)(r1 + (24u))) = (uint8_t)r0; } return r0; }

/* st_ov105_02188650, module 105, original 0x02188650, 24 bytes, register_C_provisional */
uint32_t st_ov105_02188650(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x0218a3a8u; r2 = (0x0u); r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r1 + 0u))); *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; return r0; }

/* st_ov105_0218866C, module 105, original 0x0218866C, 24 bytes, register_C_provisional */
uint32_t st_ov105_0218866C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x0218a3a8u; r2 = (0x0u); r1 = (uint32_t)(*((int16_t*)(uintptr_t)(r1 + 0u))); *((uint16_t*)(uintptr_t)(r0 + 2u)) = (uint16_t)r2; *((uint16_t*)(uintptr_t)(r0 + 0u)) = (uint16_t)r1; return r0; }

/* st_ov105_02188BB4, module 105, original 0x02188BB4, 24 bytes, register_C_provisional */
uint32_t st_ov105_02188BB4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = (0x0u); r2 = (0x1u); *((uint8_t*)(uintptr_t)(r0 + (66u))) = (uint8_t)r2; *((uint8_t*)(uintptr_t)(r0 + (67u))) = (uint8_t)r1; *((uint32_t*)(uintptr_t)(r0 + (68u))) = (uint32_t)r1; return r0; }

/* st_ov016_020B78F4, module 16, original 0x020B78F4, 16 bytes, typed_C_Clang_exact */
void st_ov016_020B78F4(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[388u] = 0u; ((volatile unsigned char*)p0)[138u] = 0u; }

/* st_ov016_020B7904, module 16, original 0x020B7904, 16 bytes, typed_C_Clang_exact */
void st_ov016_020B7904(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[389u] = 1u; ((volatile unsigned char*)p0)[258u] = 1u; }

/* st_ov016_020B7914, module 16, original 0x020B7914, 16 bytes, typed_C_Clang_exact */
void st_ov016_020B7914(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[389u] = 0u; ((volatile unsigned char*)p0)[258u] = 0u; }

/* st_ov016_020B7924, module 16, original 0x020B7924, 16 bytes, typed_C_Clang_exact */
void st_ov016_020B7924(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[390u] = 1u; ((volatile unsigned char*)p0)[378u] = 1u; }

/* st_ov016_020B7934, module 16, original 0x020B7934, 16 bytes, typed_C_Clang_exact */
void st_ov016_020B7934(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[390u] = 0u; ((volatile unsigned char*)p0)[378u] = 0u; }

/* st_ov016_020B7D18, module 16, original 0x020B7D18, 16 bytes, typed_C_Clang_exact */
void st_ov016_020B7D18(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[28u] = 1u; ((volatile unsigned char*)p0)[262u] = 1u; }

/* st_ov016_020B7D4C, module 16, original 0x020B7D4C, 16 bytes, typed_C_Clang_exact */
void st_ov016_020B7D4C(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[28u] = 0u; ((volatile unsigned char*)p0)[262u] = 0u; }

/* st_ov020_020C720C, module 20, original 0x020C720C, 28 bytes, typed_C_Clang_exact */
void st_ov020_020C720C(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned int*)p0)[1u] = 0u; ((volatile unsigned int*)p0)[2u] = 0u; ((volatile unsigned int*)p0)[5u] = 0u; ((volatile unsigned int*)p0)[7u] = 0u; ((volatile unsigned int*)p0)[8u] = 0u; }

/* st_ov020_020D686C, module 20, original 0x020D686C, 24 bytes, register_C_provisional */
uint32_t st_ov020_020D686C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r0 = ((r0 << 31)); r0 = ((r0 >> 31)); Z = (r0==0); N = (r0>>31); if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* st_ov021_020ECC88, module 21, original 0x020ECC88, 16 bytes, typed_C_Clang_exact */
void st_ov021_020ECC88(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[0u] = 0u; ((volatile unsigned char*)p0)[1u] = 0u; }

/* st_ov021_020FB64C, module 21, original 0x020FB64C, 24 bytes, register_C_provisional */
uint32_t st_ov021_020FB64C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x02109905u; r1 = *((uint8_t*)(uintptr_t)(r2 + (r0))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0xffu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0xffu)); V = (((r1 ^ (0xffu)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r1 = (r1 + (0x1u)); } if (!C) { *((uint8_t*)(uintptr_t)(r2 + (r0))) = (uint8_t)r1; } return r0; }

/* st_ov021_020FB668, module 21, original 0x020FB668, 24 bytes, register_C_provisional */
uint32_t st_ov021_020FB668(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x02109901u; r1 = *((uint8_t*)(uintptr_t)(r2 + (r0))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0xffu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0xffu)); V = (((r1 ^ (0xffu)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r1 = (r1 + (0x1u)); } if (!C) { *((uint8_t*)(uintptr_t)(r2 + (r0))) = (uint8_t)r1; } return r0; }

/* st_ov021_020FB868, module 21, original 0x020FB868, 24 bytes, register_C_provisional */
uint32_t st_ov021_020FB868(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x0210990du; r0 = *((uint8_t*)(uintptr_t)(r2 + (r1))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x63u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x63u)); V = (((r0 ^ (0x63u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r0 = (r0 + (0x1u)); } if (!C) { *((uint8_t*)(uintptr_t)(r2 + (r1))) = (uint8_t)r0; } return r0; }

/* st_ov021_020FB884, module 21, original 0x020FB884, 24 bytes, register_C_provisional */
uint32_t st_ov021_020FB884(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x02109909u; r0 = *((uint8_t*)(uintptr_t)(r2 + (r1))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x63u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x63u)); V = (((r0 ^ (0x63u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r0 = (r0 + (0x1u)); } if (!C) { *((uint8_t*)(uintptr_t)(r2 + (r1))) = (uint8_t)r0; } return r0; }

/* st_ov021_020FB8A0, module 21, original 0x020FB8A0, 24 bytes, register_C_provisional */
uint32_t st_ov021_020FB8A0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x02109911u; r0 = *((uint8_t*)(uintptr_t)(r2 + (r1))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0xffu); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0xffu)); V = (((r0 ^ (0xffu)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r0 = (r0 + (0x1u)); } if (!C) { *((uint8_t*)(uintptr_t)(r2 + (r1))) = (uint8_t)r0; } return r0; }

/* st_ov021_020FB8BC, module 21, original 0x020FB8BC, 24 bytes, register_C_provisional */
uint32_t st_ov021_020FB8BC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02109900u; r1 = *((uint8_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x63u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x63u)); V = (((r1 ^ (0x63u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!C) { r1 = (r1 + (0x1u)); } if (!C) { *((uint8_t*)(uintptr_t)(r0 + (0u))) = (uint8_t)r1; } return r0; }

/* st_ov021_021065F4, module 21, original 0x021065F4, 24 bytes, register_C_provisional */
uint32_t st_ov021_021065F4(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x0210907cu; r2 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (4u))); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (48u))) = (uint32_t)r1; return r0; }

/* st_ov021_021068EC, module 21, original 0x021068EC, 24 bytes, register_C_provisional */
uint32_t st_ov021_021068EC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x0210909cu; r2 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (4u))); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (48u))) = (uint32_t)r1; return r0; }

/* st_ov021_02106948, module 21, original 0x02106948, 24 bytes, register_C_provisional */
uint32_t st_ov021_02106948(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = 0x021090a4u; r2 = *((uint32_t*)(uintptr_t)(r1 + (0u))); r1 = *((uint32_t*)(uintptr_t)(r1 + (4u))); *((uint32_t*)(uintptr_t)(r0 + (44u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (48u))) = (uint32_t)r1; return r0; }

/* st_ov023_020EECE0, module 23, original 0x020EECE0, 24 bytes, register_C_provisional */
uint32_t st_ov023_020EECE0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (196u))); r2 = (0x1u); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x4u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x4u)); V = (((r1 ^ (0x4u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } *((uint8_t*)(uintptr_t)(r0 + (200u))) = (uint8_t)r2; if (Z) { *((uint8_t*)(uintptr_t)(r0 + (42u))) = (uint8_t)r2; } return r0; }

/* st_ov023_020EECF8, module 23, original 0x020EECF8, 16 bytes, typed_C_Clang_exact */
void st_ov023_020EECF8(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[42u] = 0u; ((volatile unsigned char*)p0)[200u] = 0u; }

/* st_ov026_0211DCEC, module 26, original 0x0211DCEC, 24 bytes, register_C_provisional */
uint32_t st_ov026_0211DCEC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = 0x02137fe4u; r1 = (~(0x0u)); *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r2; *((uint32_t*)(uintptr_t)(r0 + (8u))) = (uint32_t)r1; *((uint32_t*)(uintptr_t)(r0 + (4u))) = (uint32_t)r1; return r0; }

/* st_ov029_02144348, module 29, original 0x02144348, 24 bytes, register_C_provisional */
uint32_t st_ov029_02144348(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x0000ffffu; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (176u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 182u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 180u)) = (uint16_t)r2; return r0; }

/* st_ov031_020D9878, module 31, original 0x020D9878, 24 bytes, register_C_provisional */
uint32_t st_ov031_020D9878(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (4u))); r0 = *((uint32_t*)(uintptr_t)(r0 + (104u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x47u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x47u)); V = (((r0 ^ (0x47u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* st_ov031_020D9D0C, module 31, original 0x020D9D0C, 24 bytes, register_C_provisional */
uint32_t st_ov031_020D9D0C(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (0u))); r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 18u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* st_ov031_020F5CAC, module 31, original 0x020F5CAC, 24 bytes, register_C_provisional */
uint32_t st_ov031_020F5CAC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r2 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 56u))); *((uint32_t*)(uintptr_t)(r0 + ((r2 << 2)))) = (uint32_t)r1; r1 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 56u))); r1 = (r1 + (0x1u)); *((uint16_t*)(uintptr_t)(r0 + 56u)) = (uint16_t)r1; return r0; }

/* st_ov031_0210A938, module 31, original 0x0210A938, 24 bytes, register_C_provisional */
uint32_t st_ov031_0210A938(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r1 = *((uint32_t*)(uintptr_t)(r0 + (188u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x0u)); V = (((r1 ^ (0x0u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r1 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x1u)); V = (((r1 ^ (0x1u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 172u))); } if (!Z) { r0 = (0x78u); } return r0; }

/* st_ov032_0211D168, module 32, original 0x0211D168, 24 bytes, typed_C_Clang_exact */
void st_ov032_0211D168(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned int*)p0)[5u] = 0u; ((volatile unsigned int*)p0)[6u] = 0u; ((volatile unsigned int*)p0)[3u] = 0u; ((volatile unsigned int*)p0)[4u] = 0u; }

/* st_ov033_0211BFCC, module 33, original 0x0211BFCC, 24 bytes, register_C_provisional */
uint32_t st_ov033_0211BFCC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = 0x02122888u; r1 = *((uint32_t*)(uintptr_t)(r0 + (0u))); { uint64_t z = (uint64_t)r1 - (uint64_t)(0x1u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r1 >= (0x1u)); V = (((r1 ^ (0x1u)) & (r1 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r1 = (0x1u); } if (!Z) { *((uint32_t*)(uintptr_t)(r0 + (0u))) = (uint32_t)r1; } return r0; }

/* st_ov036_0211D8A0, module 36, original 0x0211D8A0, 24 bytes, register_C_provisional */
uint32_t st_ov036_0211D8A0(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (228u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x56u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x56u)); V = (((r0 ^ (0x56u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x57u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x57u)); V = (((r0 ^ (0x57u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x0u); } if (!Z) { r0 = (0x1u); } return r0; }

/* st_ov037_021201EC, module 37, original 0x021201EC, 24 bytes, register_C_provisional */
uint32_t st_ov037_021201EC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (r0 + (0x300u)); r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 2u))); { uint32_t z = r0 & (0x4u); Z = (z==0); N = (z>>31); } if (!Z) { r0 = (0x1u); } if (Z) { r0 = (0x0u); } return r0; }

/* st_ov042_0212B264, module 42, original 0x0212B264, 24 bytes, register_C_provisional */
uint32_t st_ov042_0212B264(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = (uint32_t)(*((int16_t*)(uintptr_t)(r0 + 76u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x3u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x3u)); V = (((r0 ^ (0x3u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { { uint64_t z = (uint64_t)r0 - (uint64_t)(0x4u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x4u)); V = (((r0 ^ (0x4u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } } if (Z) { r0 = (0x1u); } if (!Z) { r0 = (0x0u); } return r0; }

/* st_ov058_021428D4, module 58, original 0x021428D4, 16 bytes, typed_C_Clang_exact */
void st_ov058_021428D4(volatile unsigned char *p0,unsigned v1,unsigned v2,unsigned v3){ ((volatile unsigned char*)p0)[0u] = 0u; ((volatile unsigned char*)p0)[1u] = 0u; }

/* st_ov058_02151540, module 58, original 0x02151540, 24 bytes, register_C_provisional */
uint32_t st_ov058_02151540(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r3 = 0x0000ffffu; r2 = (0x0u); *((uint32_t*)(uintptr_t)(r0 + (64u))) = (uint32_t)r1; *((uint16_t*)(uintptr_t)(r0 + 70u)) = (uint16_t)r3; *((uint16_t*)(uintptr_t)(r0 + 68u)) = (uint16_t)r2; return r0; }

/* st_ov063_0215A6DC, module 63, original 0x0215A6DC, 24 bytes, register_C_provisional */
uint32_t st_ov063_0215A6DC(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) { uint32_t r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0, r11=0, r12=0; unsigned Z=0,N=0,C=0,V=0; r0 = *((uint32_t*)(uintptr_t)(r0 + (616u))); { uint64_t z = (uint64_t)r0 - (uint64_t)(0x0u); Z = ((uint32_t)z == 0); N = ((uint32_t)z >> 31); C = (r0 >= (0x0u)); V = (((r0 ^ (0x0u)) & (r0 ^ (uint32_t)z) & 0x80000000u) != 0); } if (!Z) { r0 = (0xau); } if (Z) { r0 = 0x020aed48u; } if (Z) { r0 = (uint32_t)(*((uint16_t*)(uintptr_t)(r0 + 0u))); } return r0; }
