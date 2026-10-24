/* EUR1 Spirit Tracks - 100 BL-backed ARM9 C reconstructions. */
/* 74 isolated Clang ARMv5TE exact; 26 provisional. CodeWarrior untested. */
#include <stdint.h>
#define W(a) (*(volatile uint32_t*)(uintptr_t)(a))
#define H(a) (*(volatile uint16_t*)(uintptr_t)(a))
#define B(a) (*(volatile uint8_t*)(uintptr_t)(a))
#define S(a) (*(volatile int16_t*)(uintptr_t)(a))
#define C(a) (*(volatile int8_t*)(uintptr_t)(a))
#define ST_FN(name,body) uint32_t name(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) body

/* 001 0 0x0209743C 12 E */
ST_FN(st_ov000_0209743C,{ r0 = 0x020b5c44u; return r0; })
/* 002 0 0x0209C700 12 E */
ST_FN(st_ov000_0209C700,{ r0 = 0x020b615cu; return r0; })
/* 003 arm9 0x02014FE8 12 E */
ST_FN(st_arm9_02014FE8,{ r0 = 0x02043efcu; return r0; })
/* 004 arm9 0x02031BF4 12 E */
ST_FN(st_arm9_02031BF4,{ r0 = 0x020318a8u; return r0; })
/* 005 0 0x02061A70 12 E */
ST_FN(st_ov000_02061A70,{ r0 = 0x0204aedcu; return r0; })
/* 006 0 0x0207A208 12 E */
ST_FN(st_ov000_0207A208,{ r0 = 0x027e0c90u; return r0; })
/* 007 0 0x02097430 12 E */
ST_FN(st_ov000_02097430,{ r0 = 0x020b5418u; return r0; })
/* 008 0 0x0209C6F4 12 E */
ST_FN(st_ov000_0209C6F4,{ r0 = 0x020b5d84u; return r0; })
/* 009 20 0x020C6F54 12 E */
ST_FN(st_ov020_020C6F54,{ r0 = 0x020df5b2u; return r0; })
/* 010 20 0x020C70F8 12 E */
ST_FN(st_ov020_020C70F8,{ r0 = 0x020df654u; return r0; })
/* 011 20 0x020C713C 12 E */
ST_FN(st_ov020_020C713C,{ r0 = 0x020df720u; return r0; })
/* 012 arm9 0x02028538 16 E */
ST_FN(st_arm9_02028538,{ r1 = 0x04000247u; B(r1+0) = (uint8_t)r0; return r0; })
/* 013 arm9 0x02030C5C 16 E */
ST_FN(st_arm9_02030C5C,{ r0 = 0x02050688u; r0 = W(r0+0); return r0; })
/* 014 arm9 0x02030C84 16 E */
ST_FN(st_arm9_02030C84,{ r1 = 0x02050688u; W(r1+0) = (uint32_t)r0; return r0; })
/* 015 0 0x02058F74 16 E */
ST_FN(st_ov000_02058F74,{ r1 = 0x027e0954u; W(r1+0) = (uint32_t)r0; return r0; })
/* 016 0 0x020590D4 16 E */
ST_FN(st_ov000_020590D4,{ r1 = 0x027e0958u; W(r1+0) = (uint32_t)r0; return r0; })
/* 017 0 0x020665CC 16 E */
ST_FN(st_ov000_020665CC,{ r1 = 0x020b4fb0u; W(r1+0) = (uint32_t)r0; return r0; })
/* 018 0 0x02071FBC 16 E */
ST_FN(st_ov000_02071FBC,{ r1 = 0x027e09a8u; W(r1+0) = (uint32_t)r0; return r0; })
/* 019 0 0x02072D4C 16 E */
ST_FN(st_ov000_02072D4C,{ r1 = 0x027e09b0u; W(r1+0) = (uint32_t)r0; return r0; })
/* 020 0 0x02084378 16 E */
ST_FN(st_ov000_02084378,{ r1 = 0x020ab384u; r0 = r1 + (r0 << 3u); return r0; })
/* 021 0 0x020AA254 16 E */
ST_FN(st_ov000_020AA254,{ r1 = 0x020b6558u; W(r1+0) = (uint32_t)r0; return r0; })
/* 022 9 0x020B6900 16 E */
ST_FN(st_ov009_020B6900,{ r1 = 0x021190e4u; W(r1+0) = (uint32_t)r0; return r0; })
/* 023 15 0x020B73D8 16 E */
ST_FN(st_ov015_020B73D8,{ r1 = 0x02157fb8u; W(r1+0) = (uint32_t)r0; return r0; })
/* 024 18 0x020C5B50 16 E */
ST_FN(st_ov018_020C5B50,{ r1 = 0x027e099cu; W(r1+0) = (uint32_t)r0; return r0; })
/* 025 19 0x020CE860 16 E */
ST_FN(st_ov019_020CE860,{ r1 = 0x020d2508u; W(r1+0) = (uint32_t)r0; return r0; })
/* 026 20 0x020C4880 16 E */
ST_FN(st_ov020_020C4880,{ r1 = 0x020db080u; W(r1+0) = (uint32_t)r0; return r0; })
/* 027 20 0x020C6E18 16 E */
ST_FN(st_ov020_020C6E18,{ r0 = 0x020de9a0u; r0 = W(r0+0); return r0; })
/* 028 20 0x020C6F60 16 E */
ST_FN(st_ov020_020C6F60,{ r1 = 0x020dbb8cu; H(r1+0) = (uint16_t)r0; return r0; })
/* 029 20 0x020C6F70 16 E */
ST_FN(st_ov020_020C6F70,{ r0 = 0x020dbb8cu; r0 = (uint32_t)H(r0+0); return r0; })
/* 030 21 0x020FB530 16 E */
ST_FN(st_ov021_020FB530,{ r1 = 0x027e0cf4u; W(r1+0) = (uint32_t)r0; return r0; })
/* 031 26 0x020E6CC4 16 E */
ST_FN(st_ov026_020E6CC4,{ r1 = 0x02138e30u; W(r1+0) = (uint32_t)r0; return r0; })
/* 032 26 0x020F16BC 16 E */
ST_FN(st_ov026_020F16BC,{ r1 = 0x027e0d10u; W(r1+0) = (uint32_t)r0; return r0; })
/* 033 26 0x020F4CA8 16 E */
ST_FN(st_ov026_020F4CA8,{ r1 = 0x0213f698u; W(r1+0) = (uint32_t)r0; return r0; })
/* 034 26 0x020F54A8 16 E */
ST_FN(st_ov026_020F54A8,{ r1 = 0x027e0d14u; W(r1+0) = (uint32_t)r0; return r0; })
/* 035 26 0x02104FFC 16 E */
ST_FN(st_ov026_02104FFC,{ r1 = 0x027e0d18u; W(r1+0) = (uint32_t)r0; return r0; })
/* 036 26 0x02105540 16 E */
ST_FN(st_ov026_02105540,{ r1 = 0x027e0d1cu; W(r1+0) = (uint32_t)r0; return r0; })
/* 037 26 0x0212FC34 16 E */
ST_FN(st_ov026_0212FC34,{ r1 = 0x027e0d20u; W(r1+0) = (uint32_t)r0; return r0; })
/* 038 30 0x0214C42C 16 E */
ST_FN(st_ov030_0214C42C,{ r1 = 0x027e0d24u; W(r1+0) = (uint32_t)r0; return r0; })
/* 039 30 0x0214DDA0 16 E */
ST_FN(st_ov030_0214DDA0,{ r1 = 0x027e0d28u; W(r1+0) = (uint32_t)r0; return r0; })
/* 040 49 0x02134514 16 E */
ST_FN(st_ov049_02134514,{ r1 = 0x027e0d40u; W(r1+0) = (uint32_t)r0; return r0; })
/* 041 56 0x0213D5D8 16 E */
ST_FN(st_ov056_0213D5D8,{ r1 = 0x0213f0d8u; W(r1+0) = (uint32_t)r0; return r0; })
/* 042 58 0x02142A54 16 E */
ST_FN(st_ov058_02142A54,{ r1 = 0x027e0d44u; W(r1+0) = (uint32_t)r0; return r0; })
/* 043 58 0x0214AC88 16 E */
ST_FN(st_ov058_0214AC88,{ r1 = 0x027e0d48u; W(r1+0) = (uint32_t)r0; return r0; })
/* 044 58 0x0214D7A4 16 E */
ST_FN(st_ov058_0214D7A4,{ r1 = 0x027e0d4cu; W(r1+0) = (uint32_t)r0; return r0; })
/* 045 62 0x0215B484 16 E */
ST_FN(st_ov062_0215B484,{ r1 = 0x027e0d60u; W(r1+0) = (uint32_t)r0; return r0; })
/* 046 70 0x02144104 16 E */
ST_FN(st_ov070_02144104,{ r1 = 0x0214ddfcu; r0 = r1 + (r0 << 3u); return r0; })
/* 047 71 0x0215F36C 16 E */
ST_FN(st_ov071_0215F36C,{ r1 = 0x027e0d70u; W(r1+0) = (uint32_t)r0; return r0; })
/* 048 84 0x02159D9C 16 E */
ST_FN(st_ov084_02159D9C,{ r1 = 0x027e0d80u; W(r1+0) = (uint32_t)r0; return r0; })
/* 049 88 0x0216F704 16 E */
ST_FN(st_ov088_0216F704,{ r1 = 0x020b6540u; W(r1+0) = (uint32_t)r0; return r0; })
/* 050 88 0x02172788 16 E */
ST_FN(st_ov088_02172788,{ r1 = 0x02177398u; W(r1+0) = (uint32_t)r0; return r0; })
/* 051 91 0x02167B14 16 E */
ST_FN(st_ov091_02167B14,{ r1 = 0x02178210u; W(r1+0) = (uint32_t)r0; return r0; })
/* 052 91 0x0216F1A4 16 E */
ST_FN(st_ov091_0216F1A4,{ r1 = 0x02178ec0u; W(r1+0) = (uint32_t)r0; return r0; })
/* 053 92 0x0216F5EC 16 E */
ST_FN(st_ov092_0216F5EC,{ r1 = 0x027e0d88u; W(r1+0) = (uint32_t)r0; return r0; })
/* 054 107 0x02184E88 16 E */
ST_FN(st_ov107_02184E88,{ r0 = 0x021868a0u; W(r0+96) = (uint32_t)r0; return r0; })
/* 055 arm9 0x020313A0 20 E */
ST_FN(st_arm9_020313A0,{ r0 = 0x02050700u; r0 = W(r0+0); r0 = W(r0+28); return r0; })
/* 056 21 0x020FB540 20 E */
ST_FN(st_ov021_020FB540,{ r1 = 0x027e0cf4u; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 057 21 0x020FE148 20 E */
ST_FN(st_ov021_020FE148,{ r1 = 0x027e095cu; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 058 23 0x020EA374 20 E */
ST_FN(st_ov023_020EA374,{ r1 = 0x027e095cu; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 059 26 0x020E6C84 20 E */
ST_FN(st_ov026_020E6C84,{ r1 = 0x02178210u; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 060 26 0x020F16CC 20 E */
ST_FN(st_ov026_020F16CC,{ r1 = 0x027e0d10u; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 061 26 0x020F4CB8 20 E */
ST_FN(st_ov026_020F4CB8,{ r1 = 0x0213f698u; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 062 26 0x020F54B8 20 E */
ST_FN(st_ov026_020F54B8,{ r1 = 0x027e0d14u; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 063 26 0x0210500C 20 E */
ST_FN(st_ov026_0210500C,{ r1 = 0x027e0d18u; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 064 26 0x02105550 20 E */
ST_FN(st_ov026_02105550,{ r1 = 0x027e0d1cu; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 065 26 0x0212FC44 20 E */
ST_FN(st_ov026_0212FC44,{ r1 = 0x027e0d20u; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 066 36 0x0211CA7C 20 E */
ST_FN(st_ov036_0211CA7C,{ r0 = 0x027e09bcu; r0 = W(r0+0); r0 = W(r0+4); return r0; })
/* 067 56 0x0213D5E8 20 E */
ST_FN(st_ov056_0213D5E8,{ r1 = 0x0213f0d8u; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 068 71 0x0215F37C 20 E */
ST_FN(st_ov071_0215F37C,{ r1 = 0x027e0d70u; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 069 73 0x02161B2C 20 E */
ST_FN(st_ov073_02161B2C,{ r0 = 0x027e09bcu; r0 = W(r0+0); r0 = W(r0+16); return r0; })
/* 070 88 0x0216F714 20 E */
ST_FN(st_ov088_0216F714,{ r1 = 0x020b6540u; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 071 90 0x021684F8 20 E */
ST_FN(st_ov090_021684F8,{ r0 = 0x027e09bcu; r0 = W(r0+0); r0 = W(r0+4); return r0; })
/* 072 93 0x02166498 20 E */
ST_FN(st_ov093_02166498,{ r1 = 0x027e0d8cu; r2 = 0x0u; W(r1+0) = (uint32_t)r2; return r0; })
/* 073 93 0x0216E310 20 E */
ST_FN(st_ov093_0216E310,{ r0 = 0x027e09bcu; r0 = W(r0+0); r0 = W(r0+16); return r0; })
/* 074 94 0x0216DE88 20 E */
ST_FN(st_ov094_0216DE88,{ r0 = 0x027e09bcu; r0 = W(r0+0); r0 = W(r0+4); return r0; })
/* 075 28 0x02142F84 12 P */
ST_FN(st_ov028_02142F84,{ r0 = 0x00000f33u; return r0; })
/* 076 0 0x020976C4 12 P */
ST_FN(st_ov000_020976C4,{ r0 = 0x0000020bu; return r0; })
/* 077 71 0x02159A40 12 P */
ST_FN(st_ov071_02159A40,{ r0 = 0x0000019au; return r0; })
/* 078 71 0x02159A4C 12 P */
ST_FN(st_ov071_02159A4C,{ r0 = 0x00001ccdu; return r0; })
/* 079 89 0x021680E0 12 P */
ST_FN(st_ov089_021680E0,{ r0 = 0x00032044u; return r0; })
/* 080 arm9 0x0200F37C 16 P */
ST_FN(st_arm9_0200F37C,{ r1 = (uint32_t)H(r0+12); r1 = W(r0 + r1); r0 = r0 + r1; return r0; })
/* 081 arm9 0x02015338 16 P */
ST_FN(st_arm9_02015338,{ r0 = 0x0204999cu; r0 = W(r0+116); return r0; })
/* 082 arm9 0x02027D50 16 P */
ST_FN(st_arm9_02027D50,{ r0 = 0x04000100u; r0 = (uint32_t)H(r0+0); return r0; })
/* 083 20 0x020C5D68 16 P */
ST_FN(st_ov020_020C5D68,{ r1 = 0x020dbf60u; W(r1+8) = (uint32_t)r0; return r0; })
/* 084 20 0x020C5DE0 16 P */
ST_FN(st_ov020_020C5DE0,{ r0 = 0x020dbec0u; r0 = W(r0+40); return r0; })
/* 085 20 0x020C64D0 16 P */
ST_FN(st_ov020_020C64D0,{ r1 = 0x020dbec0u; W(r1+28) = (uint32_t)r0; return r0; })
/* 086 20 0x020C67BC 16 P */
ST_FN(st_ov020_020C67BC,{ r0 = 0x020dbec0u; r0 = (uint32_t)H(r0+8); return r0; })
/* 087 20 0x020D34C0 16 P */
ST_FN(st_ov020_020D34C0,{ r1 = 0x020e9868u; W(r1+12) = (uint32_t)r0; return r0; })
/* 088 20 0x020D6374 16 P */
ST_FN(st_ov020_020D6374,{ r1 = 0x020e99e0u; H(r1+38) = (uint16_t)r0; return r0; })
/* 089 75 0x0215BE80 16 P */
ST_FN(st_ov075_0215BE80,{ r1 = 0x00a10065u; W(r0+2300) = (uint32_t)r1; return r0; })
/* 090 92 0x02177DC8 16 P */
ST_FN(st_ov092_02177DC8,{ r1 = 0x0217e098u; W(r1+4) = (uint32_t)r0; return r0; })
/* 091 92 0x02178608 16 P */
ST_FN(st_ov092_02178608,{ r1 = 0x0217e0e8u; W(r1+4) = (uint32_t)r0; return r0; })
/* 092 26 0x02106BB4 20 P */
ST_FN(st_ov026_02106BB4,{ r1 = W(r0+4); r0 = 0x021331e8u; r0 = B(r0 + r1); return r0; })
/* 093 58 0x02151B88 20 P */
ST_FN(st_ov058_02151B88,{ r2 = 0x02155eb8u; W(r0+4) = (uint32_t)r1; W(r0+0) = (uint32_t)r2; return r0; })
/* 094 58 0x02152C50 20 P */
ST_FN(st_ov058_02152C50,{ r2 = 0x02155f58u; W(r0+4) = (uint32_t)r1; W(r0+0) = (uint32_t)r2; return r0; })
/* 095 63 0x0215FF94 20 P */
ST_FN(st_ov063_0215FF94,{ r2 = 0x02163a70u; W(r0+4) = (uint32_t)r1; W(r0+0) = (uint32_t)r2; return r0; })
/* 096 63 0x0216165C 20 P */
ST_FN(st_ov063_0216165C,{ r2 = 0x02163c58u; W(r0+4) = (uint32_t)r1; W(r0+0) = (uint32_t)r2; return r0; })
/* 097 65 0x02158AC0 20 P */
ST_FN(st_ov065_02158AC0,{ r2 = 0x0215aa2cu; W(r0+4) = (uint32_t)r1; W(r0+0) = (uint32_t)r2; return r0; })
/* 098 20 0x020D6540 32 P */
ST_FN(st_ov020_020D6540,{ r0 = 0x020e99e0u; r0 = W(r0+8); r0 = B(r0+1293); if (r0 == 0x1u) { r0 = 0x1u; } if (r0 != 0x1u) { r0 = 0x0u; } return r0; })
/* 099 arm9 0x020092C4 8 P */
ST_FN(st_arm9_020092C4,{ W(r0 + (r1 << 2u)) = (uint32_t)r2; return r0; })
/* 100 22 0x020EB048 16 P */
ST_FN(st_ov022_020EB048,{ r1 = 0x020e87b2u; r0 = B(r1 + (r0 << 5u)); return r0; })
