/* The Legend of Zelda: Spirit Tracks EUR Rev 1 */
/* 34 Clang-verified ARM9 C snippets; research-only, not integrated into official game C++ build. */
/* Do not mistake 66 other targets in the manifest for compiled C functions. */

/* Fixed ARM9 original compiler ABI and source semantics still require examination. */

/* Verified 01/34 | overlay 7 | 0x020B7B8C | 24 bytes | 1 direct BL refs */
void st_ov007_020B7B8C(void *p) { *(volatile unsigned char*)((char*)p+231)=1u; *(volatile unsigned char*)((char*)p+230)=1u; *(volatile unsigned char*)((char*)p+451)=1u; *(volatile unsigned char*)((char*)p+450)=1u; }

/* Verified 02/34 | overlay 7 | 0x020B7BA4 | 24 bytes | 1 direct BL refs */
void st_ov007_020B7BA4(void *p) { *(volatile unsigned char*)((char*)p+231)=0u; *(volatile unsigned char*)((char*)p+230)=0u; *(volatile unsigned char*)((char*)p+451)=0u; *(volatile unsigned char*)((char*)p+450)=0u; }

/* Verified 03/34 | overlay 16 | 0x020B7904 | 16 bytes | 1 direct BL refs */
void st_ov016_020B7904(void *p) { *(volatile unsigned char*)((char*)p+389)=1u; *(volatile unsigned char*)((char*)p+258)=1u; }

/* Verified 04/34 | overlay 16 | 0x020B7924 | 16 bytes | 1 direct BL refs */
void st_ov016_020B7924(void *p) { *(volatile unsigned char*)((char*)p+390)=1u; *(volatile unsigned char*)((char*)p+378)=1u; }

/* Verified 05/34 | overlay 16 | 0x020B7914 | 16 bytes | 1 direct BL refs */
void st_ov016_020B7914(void *p) { *(volatile unsigned char*)((char*)p+389)=0u; *(volatile unsigned char*)((char*)p+258)=0u; }

/* Verified 06/34 | overlay 16 | 0x020B7934 | 16 bytes | 1 direct BL refs */
void st_ov016_020B7934(void *p) { *(volatile unsigned char*)((char*)p+390)=0u; *(volatile unsigned char*)((char*)p+378)=0u; }

/* Verified 07/34 | overlay 16 | 0x020B7D18 | 16 bytes | 1 direct BL refs */
void st_ov016_020B7D18(void *p) { *(volatile unsigned char*)((char*)p+28)=1u; *(volatile unsigned char*)((char*)p+262)=1u; }

/* Verified 08/34 | overlay 16 | 0x020B78F4 | 16 bytes | 1 direct BL refs */
void st_ov016_020B78F4(void *p) { *(volatile unsigned char*)((char*)p+388)=0u; *(volatile unsigned char*)((char*)p+138)=0u; }

/* Verified 09/34 | overlay 16 | 0x020B7D4C | 16 bytes | 1 direct BL refs */
void st_ov016_020B7D4C(void *p) { *(volatile unsigned char*)((char*)p+28)=0u; *(volatile unsigned char*)((char*)p+262)=0u; }

/* Verified 10/34 | overlay 20 | 0x020C720C | 28 bytes | 1 direct BL refs */
void st_ov020_020C720C(void *p) { *(volatile unsigned*)((char*)p+4)=0u; *(volatile unsigned*)((char*)p+8)=0u; *(volatile unsigned*)((char*)p+20)=0u; *(volatile unsigned*)((char*)p+28)=0u; *(volatile unsigned*)((char*)p+32)=0u; }

/* Verified 11/34 | overlay 21 | 0x020ECC88 | 16 bytes | 1 direct BL refs */
void st_ov021_020ECC88(void *p) { *(volatile unsigned char*)((char*)p+0)=0u; *(volatile unsigned char*)((char*)p+1)=0u; }

/* Verified 12/34 | overlay 23 | 0x020EECF8 | 16 bytes | 1 direct BL refs */
void st_ov023_020EECF8(void *p) { *(volatile unsigned char*)((char*)p+42)=0u; *(volatile unsigned char*)((char*)p+200)=0u; }

/* Verified 13/34 | overlay 24 | 0x020C78B4 | 12 bytes | 1 direct BL refs */
void st_ov024_020C78B4(void *p, unsigned v, unsigned v2, unsigned v3) { *(volatile unsigned*)((char*)p+32)=v; *(volatile unsigned short*)((char*)p+40)=v2; }

/* Verified 14/34 | overlay 24 | 0x020CB2B0 | 12 bytes | 3 direct BL refs */
void st_ov024_020CB2B0(void *p, unsigned v, unsigned v2, unsigned v3) { *(volatile unsigned*)((char*)p+8)=v; *(volatile unsigned*)((char*)p+12)=v2; }

/* Verified 15/34 | overlay 24 | 0x020D21AC | 12 bytes | 1 direct BL refs */
unsigned st_ov024_020D21AC(void *p,unsigned v,unsigned v2) { return *(volatile unsigned char*)((char*)p+15+v); }

/* Verified 16/34 | overlay 26 | 0x02122EF8 | 20 bytes | 1 direct BL refs */
void st_ov026_02122EF8(void *p) { unsigned n= *(volatile unsigned*)((char*)p+380)+67u; *(volatile unsigned*)((char*)p+380)=n; *(volatile unsigned*)((char*)p+276)=n; }

/* Verified 17/34 | overlay 32 | 0x0211D168 | 24 bytes | 1 direct BL refs */
void st_ov032_0211D168(void *p) { *(volatile unsigned*)((char*)p+20)=0u; *(volatile unsigned*)((char*)p+24)=0u; *(volatile unsigned*)((char*)p+12)=0u; *(volatile unsigned*)((char*)p+16)=0u; }

/* Verified 18/34 | overlay 58 | 0x021428D4 | 16 bytes | 1 direct BL refs */
void st_ov058_021428D4(void *p) { *(volatile unsigned char*)((char*)p+0)=0u; *(volatile unsigned char*)((char*)p+1)=0u; }

/* Verified 19/34 | overlay 71 | 0x0215B608 | 16 bytes | 1 direct BL refs */
void st_ov071_0215B608(void *p) { *(volatile unsigned char*)((char*)p+0)=0u; *(volatile unsigned char*)((char*)p+1)=0u; }

/* Verified 20/34 | overlay 80 | 0x0215E920 | 16 bytes | 1 direct BL refs */
void st_ov080_0215E920(void *p) { *(volatile unsigned short*)((char*)p+0)=0u; *(volatile unsigned*)((char*)p+4)=0u; }

/* Verified 21/34 | overlay 84 | 0x0215C21C | 16 bytes | 1 direct BL refs */
void st_ov084_0215C21C(void *p) { *(volatile unsigned char*)((char*)p+0)=0u; *(volatile unsigned char*)((char*)p+1)=0u; }

/* Verified 22/34 | ARM9 main | 0x0202B56C | 8 bytes | 1 direct BL refs */
unsigned st_arm9_0202B56C(void *p) { return *(volatile unsigned*)((char*)p+56); }

/* Verified 23/34 | ARM9 main | 0x020077E0 | 24 bytes | 1 direct BL refs */
void st_arm9_020077E0(void *p) { *(volatile unsigned*)((char*)p+0)=0u; *(volatile unsigned*)((char*)p+4)=0u; *(volatile unsigned*)((char*)p+8)=0u; *(volatile unsigned short*)((char*)p+12)=0u; }

/* Verified 24/34 | ARM9 main | 0x0200B6B0 | 8 bytes | 1 direct BL refs */
void st_arm9_0200B6B0(void *p, unsigned v, unsigned v2, unsigned v3) { *(volatile unsigned*)((char*)p+44) = v; }

/* Verified 25/34 | ARM9 main | 0x02013B10 | 20 bytes | 1 direct BL refs */
void st_arm9_02013B10(void *p) { *(volatile unsigned short*)((char*)p+0)=0u; *(volatile unsigned short*)((char*)p+2)=0u; *(volatile unsigned short*)((char*)p+4)=0u; }

/* Verified 26/34 | ARM9 main | 0x02013B88 | 16 bytes | 1 direct BL refs */
void st_arm9_02013B88(void *p) { *(volatile unsigned short*)((char*)p+2)=0u; *(volatile unsigned short*)((char*)p+4)=0u; }

/* Verified 27/34 | ARM9 main | 0x02016798 | 16 bytes | 1 direct BL refs */
void st_arm9_02016798(void *p) { *(volatile unsigned short*)((char*)p+0)=0u; *(volatile unsigned short*)((char*)p+14)=0u; }

/* Verified 28/34 | ARM9 main | 0x020177CC | 24 bytes | 1 direct BL refs */
void st_arm9_020177CC(void *p) { *(volatile unsigned char*)((char*)p+4)=0u; *(volatile unsigned*)((char*)p+8)=0u; *(volatile unsigned*)((char*)p+12)=0u; *(volatile unsigned*)((char*)p+16)=0u; }

/* Verified 29/34 | ARM9 main | 0x0201EC30 | 8 bytes | 4 direct BL refs */
unsigned st_arm9_0201EC30(void *p) { return *(volatile unsigned*)((char*)p+16); }

/* Verified 30/34 | ARM9 main | 0x02021E00 | 8 bytes | 4 direct BL refs */
unsigned st_arm9_02021E00(void *p) { return *(volatile unsigned*)((char*)p+8); }

/* Verified 31/34 | ARM9 main | 0x020271B0 | 8 bytes | 1 direct BL refs */
unsigned st_arm9_020271B0(void) { return 0u; }

/* Verified 32/34 | ARM9 main | 0x02026730 | 8 bytes | 1 direct BL refs */
unsigned st_arm9_02026730(void *p) { return *(volatile unsigned short*)((char*)p+4); }

/* Verified 33/34 | ARM9 main | 0x0203B938 | 8 bytes | 1 direct BL refs */
unsigned st_arm9_0203B938(void) { return 0u; }

/* Verified 34/34 | ARM9 main | 0x02013A34 | 16 bytes | 1 direct BL refs */
void st_arm9_02013A34(void *p) { *(volatile unsigned short*)((char*)p+0)=0u; *(volatile unsigned short*)((char*)p+2)=0u; }
