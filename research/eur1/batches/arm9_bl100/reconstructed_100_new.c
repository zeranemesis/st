/* Spirit Tracks Europe Rev 1. BL referenced standalone research functions. */
/* C/C++ class ownership and original CodeWarrior game matching still unknown. */
/* #001: ARM9 0x02001f30, BL xrefs 3, clang_exact */
void st_arm9_02001F30(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((volatile unsigned int*)(unsigned long)(a0 + 4u)) = (unsigned int)(0u);*((volatile unsigned int*)(unsigned long)(a0 + 0u)) = (unsigned int)(0u);*((volatile unsigned int*)(unsigned long)(a0 + 12u)) = (unsigned int)(0u);*((volatile unsigned int*)(unsigned long)(a0 + 8u)) = (unsigned int)(0u);}
/* #002: ARM9 0x020273c8, BL xrefs 3, clang_exact */
void st_arm9_020273C8(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((volatile unsigned int*)(unsigned long)(a0 + 4u)) = (unsigned int)(0u);*((volatile unsigned int*)(unsigned long)(a0 + 0u)) = (unsigned int)(0u);*((volatile unsigned int*)(unsigned long)(a0 + 8u)) = (unsigned int)(0u);*((volatile unsigned int*)(unsigned long)(a0 + 12u)) = (unsigned int)(0u);}
/* #003: ARM9 0x020075e0, BL xrefs 2, clang_exact */
unsigned int st_arm9_020075E0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((*((unsigned int*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 4u))) + 0u))));}
/* #004: ARM9 0x020092ec, BL xrefs 1, clang_exact */
unsigned int st_arm9_020092EC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned int*)(unsigned long)((a0 + (a1 << 2u)) + 8u)) = (unsigned int)(a2);return (unsigned int)((a0 + (a1 << 2u)));}
/* #005: ARM9 0x0201667c, BL xrefs 2, clang_exact */
void st_arm9_0201667C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned int*)(unsigned long)(a0 + 0u)) = (unsigned int)(a0);*((unsigned int*)(unsigned long)(a0 + 4u)) = (unsigned int)(a0);}
/* #006: ARM9 0x0201be20, BL xrefs 1, clang_exact */
void st_arm9_0201BE20(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned char*)(unsigned long)(a0 + 4u)) = (unsigned char)(1u);}
/* #007: overlay 000 0x0209c938, BL xrefs 2, clang_exact */
unsigned int st_ov000_0209C938(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((*((signed char*)(unsigned long)(a0 + 14u))));}
/* #008: overlay 024 0x020d4674, BL xrefs 1, clang_exact */
void st_ov024_020D4674(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned int*)(unsigned long)(a0 + 44u)) = (unsigned int)((~0u));*((unsigned int*)(unsigned long)(a0 + 48u)) = (unsigned int)((~0u));}
/* #009: overlay 026 0x0211e804, BL xrefs 1, clang_exact */
unsigned int st_ov026_0211E804(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((*((volatile unsigned short*)(unsigned long)(a0 + 114u))) & 255u));}
/* #010: ARM9 0x02007350, BL xrefs 2, clang_exact */
unsigned int st_arm9_02007350(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((*((unsigned int*)(unsigned long)(a0 + 0u))) + ((*((unsigned short*)(unsigned long)(a0 + 8u))) << 4u)));}
/* #011: ARM9 0x02007360, BL xrefs 1, clang_exact */
unsigned int st_arm9_02007360(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((*((unsigned int*)(unsigned long)(a0 + 0u))) + ((*((unsigned short*)(unsigned long)(a0 + 10u))) << 4u)));}
/* #012: overlay 024 0x020c52e8, BL xrefs 1, clang_exact */
unsigned int st_ov024_020C52E8(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned int*)(unsigned long)(67108864u + 0u)) = (unsigned int)((((*((unsigned int*)(unsigned long)(67108864u + 0u))) & ~7936u) | 4352u));return (unsigned int)((((*((unsigned int*)(unsigned long)(67108864u + 0u))) & ~7936u) | 4352u));}
/* #013: ARM9 0x0200b5d0, BL xrefs 1, clang_exact */
void st_arm9_0200B5D0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if((a1 != 0u)){*((unsigned int*)(unsigned long)(a0 + 8u)) = (unsigned int)(a1);}if((a2 != 0u)){*((unsigned int*)(unsigned long)(a0 + 24u)) = (unsigned int)(a2);}}
/* #014: overlay 000 0x02083484, BL xrefs 1, clang_exact */
void st_ov000_02083484(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((a1 + 2u) != 0u)){*((unsigned char*)(unsigned long)(a0 + 110u)) = (unsigned char)(a1);}}
/* #015: ARM9 0x02019514, BL xrefs 2, clang_exact */
unsigned int st_arm9_02019514(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 3564u))) == 0u)) ? 0u : ((((*((unsigned int*)(unsigned long)(a0 + 3564u))) != 0u)) ? (*((unsigned char*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 3564u))) + 336u))) : (*((unsigned int*)(unsigned long)(a0 + 3564u))))));}
/* #016: ARM9 0x02020df8, BL xrefs 1, clang_exact */
void st_arm9_02020DF8(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if((((*((unsigned short*)(unsigned long)(a1 + 32u))) & 1u) != 0u)){*((unsigned char*)(unsigned long)(a0 + 948u)) = (unsigned char)((((((*((unsigned short*)(unsigned long)(a1 + 32u))) & 1u) != 0u)) ? 1u : (*((unsigned short*)(unsigned long)(a1 + 32u)))));}}
/* #017: ARM9 0x0201eaa0, BL xrefs 3, provisional_semantic_C */
unsigned int st_arm9_0201EAA0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((unsigned int)((int)((*((unsigned int*)(unsigned long)(a0 + 16u))) + 2048u) >> 12u)) & 255u));}
/* #018: overlay 000 0x020984e0, BL xrefs 1, provisional_semantic_C */
void st_ov000_020984E0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned int*)(unsigned long)(a0 + 144u)) = (unsigned int)(a1);*((unsigned int*)(unsigned long)(a0 + 52u)) = (unsigned int)((a1 + 4u));*((unsigned int*)(unsigned long)(a0 + 48u)) = (unsigned int)((a1 + 4u));*((unsigned short*)(unsigned long)(a0 + 78u)) = (unsigned short)((*((signed short*)(unsigned long)(a1 + 28u))));}
/* #019: ARM9 0x02001fa4, BL xrefs 3, provisional_semantic_C */
void st_arm9_02001FA4(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((int)((*((unsigned int*)(unsigned long)(a0 + 8u)))) < (int)((*((unsigned int*)(unsigned long)(a0 + 12u)))))){*((unsigned int*)(unsigned long)(a0 + 8u)) = (unsigned int)(((((int)((*((unsigned int*)(unsigned long)(a0 + 8u)))) < (int)((*((unsigned int*)(unsigned long)(a0 + 12u)))))) ? ((*((unsigned int*)(unsigned long)(a0 + 8u))) + 1u) : (*((unsigned int*)(unsigned long)(a0 + 12u)))));}}
/* #020: ARM9 0x02001fbc, BL xrefs 3, provisional_semantic_C */
unsigned int st_arm9_02001FBC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((int)((*((unsigned int*)(unsigned long)(a0 + 8u)))) < (int)((*((unsigned int*)(unsigned long)(a0 + 12u)))))) ? 0u : ((((int)((*((unsigned int*)(unsigned long)(a0 + 8u)))) >= (int)((*((unsigned int*)(unsigned long)(a0 + 12u)))))) ? 1u : (*((unsigned int*)(unsigned long)(a0 + 12u))))));}
/* #021: overlay 024 0x020c790c, BL xrefs 1, provisional_semantic_C */
void st_ov024_020C790C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned int*)(unsigned long)(a0 + 32u)) = (unsigned int)((~0u));*((unsigned short*)(unsigned long)(a0 + 40u)) = (unsigned short)(0u);}
/* #022: overlay 000 0x02062e5c, BL xrefs 1, provisional_semantic_C */
void st_ov000_02062E5C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned short*)(unsigned long)(a0 + 0u)) = (unsigned short)((*((signed short*)(unsigned long)((*((unsigned int*)(unsigned long)(a1 + 12u))) + 14u))));*((unsigned short*)(unsigned long)(a0 + 2u)) = (unsigned short)((*((signed short*)(unsigned long)((*((unsigned int*)(unsigned long)(a1 + 12u))) + 16u))));}
/* #023: overlay 074 0x02155b30, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov074_02155B30(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned short*)(unsigned long)((a0 + 256u) + 248u)) = (unsigned short)(0u);return (unsigned int)((a0 + 256u));}
/* #024: overlay 031 0x020f23a0, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov031_020F23A0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((*((unsigned short*)(unsigned long)(a0 + 108u))) << 4u) + 1024u));}
/* #025: overlay 030 0x0214be94, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov030_0214BE94(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((a0 + 272u) + ((*((unsigned char*)(unsigned long)(a1 + 0u))) << 2u)));}
/* #026: overlay 089 0x0216bfb0, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov089_0216BFB0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((*((unsigned int*)(unsigned long)(a0 + 20u))) + (*((unsigned int*)(unsigned long)(a0 + 24u)))));}
/* #027: ARM9 0x02013e18, BL xrefs 3, provisional_semantic_C */
unsigned int st_arm9_02013E18(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((*((unsigned int*)(unsigned long)(a0 + 196u))) == 0u)){*((unsigned int*)(unsigned long)(a0 + 196u)) = (unsigned int)(a1);}if(((*((unsigned int*)(unsigned long)(a0 + 196u))) == 0u)){*((unsigned int*)(unsigned long)(a0 + 200u)) = (unsigned int)(a2);}return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 196u))) != 0u)) ? 0u : ((((*((unsigned int*)(unsigned long)(a0 + 196u))) == 0u)) ? 1u : a0)));}
/* #028: ARM9 0x020070c4, BL xrefs 2, provisional_semantic_C */
unsigned int st_arm9_020070C4(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned short*)(unsigned long)(a0 + 12u))) != (*((unsigned int*)(unsigned long)(a0 + 4u))))) ? 0u : ((((*((unsigned short*)(unsigned long)(a0 + 12u))) == (*((unsigned int*)(unsigned long)(a0 + 4u))))) ? 1u : (*((unsigned int*)(unsigned long)(a0 + 4u))))));}
/* #029: overlay 093 0x0217415c, BL xrefs 1, provisional_semantic_C */
void st_ov093_0217415C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned short*)(unsigned long)(a0 + 0u)) = (unsigned short)((*((signed short*)(unsigned long)(a1 + 0u))));}
/* #030: overlay 037 0x021205b8, BL xrefs 1, provisional_semantic_C */
void st_ov037_021205B8(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned short*)(unsigned long)(a0 + 40u)) = (unsigned short)((*((signed short*)(unsigned long)(a1 + 0u))));}
/* #031: overlay 029 0x02147568, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov029_02147568(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned short*)(unsigned long)((a0 + 1024u) + 234u)) = (unsigned short)(a1);return (unsigned int)((a0 + 1024u));}
/* #032: overlay 023 0x020eece0, BL xrefs 1, provisional_semantic_C */
void st_ov023_020EECE0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned char*)(unsigned long)(a0 + 200u)) = (unsigned char)(1u);if(((*((unsigned int*)(unsigned long)(a0 + 196u))) == 4u)){*((unsigned char*)(unsigned long)(a0 + 42u)) = (unsigned char)(1u);}}
/* #033: ARM9 0x02002d88, BL xrefs 2, provisional_semantic_C */
unsigned int st_arm9_02002D88(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)){*((unsigned char*)(unsigned long)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)) ? (*((unsigned int*)(unsigned long)(a0 + 0u))) : a0) + 64u)) = (unsigned char)(a1);}return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)) ? (*((unsigned int*)(unsigned long)(a0 + 0u))) : a0));}
/* #034: overlay 090 0x0216f364, BL xrefs 1, provisional_semantic_C */
void st_ov090_0216F364(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned int*)(unsigned long)(a0 + 148u)) = (unsigned int)(a1);*((unsigned char*)(unsigned long)(a0 + 248u)) = (unsigned char)(((((((unsigned int)((int)a1 >> 12u)) & 255u) > 31u)) ? 31u : (((unsigned int)((int)a1 >> 12u)) & 255u)));}
/* #035: overlay 031 0x020fb318, BL xrefs 1, provisional_semantic_C */
void st_ov031_020FB318(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((*((unsigned int*)(unsigned long)(a0 + 180u))) != 0u)){*((unsigned int*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 180u))) + 0u)) = (unsigned int)(a1);}*((unsigned int*)(unsigned long)(a0 + 180u)) = (unsigned int)(((*((unsigned int*)(unsigned long)(a0 + 180u))) + 4u));}
/* #036: overlay 020 0x020d26b0, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov020_020D26B0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((((a1 <= a0)) ? a0 : a1) << 16u) >> 16u));}
/* #037: overlay 024 0x020c4dd4, BL xrefs 2, provisional_semantic_C */
unsigned int st_ov024_020C4DD4(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) == 0u)) ? 0u : ((((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)) ? 1u : (*((unsigned int*)(unsigned long)(a0 + 0u))))));}
/* #038: overlay 089 0x0216dc1c, BL xrefs 1, provisional_semantic_C */
void st_ov089_0216DC1C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((*((unsigned int*)(unsigned long)((a0 + 24576u) + 2372u))) != 0u)){*((unsigned int*)(unsigned long)(a0 + 1084u)) = (unsigned int)((*((unsigned int*)(unsigned long)((a0 + 24576u) + 2372u))));}}
/* #039: ARM9 0x0201be08, BL xrefs 2, provisional_semantic_C */
unsigned int st_arm9_0201BE08(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((*((unsigned int*)(unsigned long)(a0 + 0u))) == 0u)){*((unsigned int*)(unsigned long)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)) ? 0u : a0) + 0u)) = (unsigned int)(a1);}return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) == 0u)) ? 1u : ((((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)) ? 0u : a0)));}
/* #040: overlay 000 0x0208116c, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov000_0208116C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if((a2 != 0u)){*((unsigned int*)(unsigned long)(a1 + 0u)) = (unsigned int)((((a2 != 0u)) ? (*((unsigned int*)(unsigned long)(a0 + 76u))) : a2));}*((unsigned int*)(unsigned long)(a1 + 4u)) = (unsigned int)((*((unsigned int*)(unsigned long)(a0 + 28u))));return (unsigned int)((*((unsigned int*)(unsigned long)(a0 + 28u))));}
/* #041: ARM9 0x02019340, BL xrefs 1, provisional_semantic_C */
unsigned int st_arm9_02019340(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((a1 != 0u)) ? 0u : 1u));}
/* #042: overlay 000 0x02060b50, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov000_02060B50(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 104u))) == 1u)) ? 1u : 0u));}
/* #043: overlay 000 0x020a9ce4, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov000_020A9CE4(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((int)((*((signed short*)(unsigned long)((a0 + (a1 << 1u)) + 60u)))) < (int)(0u))) ? 0u : (*((signed short*)(unsigned long)((a0 + (a1 << 1u)) + 60u)))));}
/* #044: overlay 000 0x020a4384, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov000_020A4384(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((signed short*)(unsigned long)((a0 + 256u) + 68u))) != (*((signed short*)(unsigned long)((a0 + 256u) + 70u))))) ? 0u : ((((*((signed short*)(unsigned long)((a0 + 256u) + 68u))) == (*((signed short*)(unsigned long)((a0 + 256u) + 70u))))) ? 1u : (*((signed short*)(unsigned long)((a0 + 256u) + 70u))))));}
/* #045: overlay 016 0x020b7974, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov016_020B7974(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned short*)(unsigned long)((a0 + 256u) + 136u))) < (*((unsigned short*)(unsigned long)((a0 + 256u) + 138u))))) ? 0u : ((((*((unsigned short*)(unsigned long)((a0 + 256u) + 136u))) >= (*((unsigned short*)(unsigned long)((a0 + 256u) + 138u))))) ? 1u : (*((unsigned short*)(unsigned long)((a0 + 256u) + 138u))))));}
/* #046: overlay 000 0x02065e88, BL xrefs 1, provisional_semantic_C */
void st_ov000_02065E88(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((*((unsigned short*)(unsigned long)(a0 + 16u))) >= 160u)){*((unsigned short*)(unsigned long)(a0 + 14u)) = (unsigned short)(((((*((unsigned short*)(unsigned long)(a0 + 16u))) >= 160u)) ? (~0u) : (*((unsigned short*)(unsigned long)(a0 + 16u)))));}}
/* #047: ARM9 0x02018c78, BL xrefs 1, provisional_semantic_C */
void st_arm9_02018C78(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned short*)(unsigned long)(a0 + 4u)) = (unsigned short)(((((*((unsigned int*)(unsigned long)(a0 + 8u))) == 1u)) ? ((unsigned int)((int)((((*((unsigned int*)(unsigned long)(a0 + 8u))) == 1u)) ? (a1 + 1u) : a1) >> 1u)) : ((((*((unsigned int*)(unsigned long)(a0 + 8u))) == 1u)) ? (a1 + 1u) : a1)));}
/* #048: overlay 063 0x0215c988, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov063_0215C988(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned char*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 4u))) + 196u)) = (unsigned char)(((((*((unsigned char*)(unsigned long)(a0 + 150u))) != 0u)) ? 0u : ((((*((unsigned char*)(unsigned long)(a0 + 150u))) == 0u)) ? 1u : (*((unsigned char*)(unsigned long)(a0 + 150u))))));return (unsigned int)((*((unsigned int*)(unsigned long)(a0 + 4u))));}
/* #049: ARM9 0x0203bc54, BL xrefs 2, provisional_semantic_C */
unsigned int st_arm9_0203BC54(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((((*((unsigned int*)(unsigned long)(a0 + 8u))) == 0u)) ? 0u : ((((*((unsigned int*)(unsigned long)(a0 + 8u))) != 0u)) ? (((((*((unsigned int*)(unsigned long)(a0 + 8u))) != 0u)) ? (*((unsigned char*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 8u))) + 0u))) : (*((unsigned int*)(unsigned long)(a0 + 8u)))) & 31u) : ((((*((unsigned int*)(unsigned long)(a0 + 8u))) != 0u)) ? (*((unsigned char*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 8u))) + 0u))) : (*((unsigned int*)(unsigned long)(a0 + 8u)))))) & 255u));}
/* #050: overlay 036 0x0211d8b8, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov036_0211D8B8(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(0u);}
/* #051: overlay 024 0x020d5460, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov024_020D5460(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((a0 - 4u) > 3u)) ? 0u : ((((a0 - 4u) <= 3u)) ? 1u : (a0 - 4u))));}
/* #052: overlay 094 0x0217485c, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov094_0217485C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 64u))) != 3u)) ? 0u : 1u));}
/* #053: overlay 077 0x02158bbc, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov077_02158BBC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((signed short*)(unsigned long)(a0 + 76u))) != 4u)) ? 0u : 1u));}
/* #054: overlay 071 0x021561e4, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov071_021561E4(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((signed short*)(unsigned long)(a0 + 76u))) != 16u)) ? 1u : 0u));}
/* #055: ARM9 0x0200503c, BL xrefs 1, provisional_semantic_C */
void st_arm9_0200503C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)){*((unsigned int*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 0u))) + 332u)) = (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)) ? 0u : a1));}if(((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)){*((unsigned int*)(unsigned long)(a0 + 0u)) = (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)) ? 0u : a1));}}
/* #056: overlay 031 0x020d9834, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov031_020D9834(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 4u))) + 104u))) != 41u)) ? 0u : 1u));}
/* #057: overlay 024 0x020cea70, BL xrefs 1, provisional_semantic_C */
void st_ov024_020CEA70(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){*((unsigned char*)(unsigned long)(a0 + 261u)) = (unsigned char)(a1);if((a2 != 0u)){*((unsigned int*)(unsigned long)(a0 + 256u)) = (unsigned int)((((a2 != 0u)) ? 75u : a1));}if((a2 == 0u)){*((unsigned char*)(unsigned long)(a0 + 260u)) = (unsigned char)((((a2 == 0u)) ? 1u : (((a2 != 0u)) ? 75u : a1)));}}
/* #058: overlay 064 0x02158bb8, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov064_02158BB8(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 24u))) != 2u)) ? 0u : ((((*((unsigned int*)(unsigned long)(a0 + 24u))) == 2u)) ? 1u : (*((unsigned int*)(unsigned long)(a0 + 24u))))));}
/* #059: overlay 064 0x02158ba4, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov064_02158BA4(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 24u))) != 1u)) ? 0u : ((((*((unsigned int*)(unsigned long)(a0 + 24u))) == 1u)) ? 1u : (*((unsigned int*)(unsigned long)(a0 + 24u))))));}
/* #060: overlay 028 0x02142d7c, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov028_02142D7C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((signed short*)(unsigned long)(a0 + 76u))) != 0u)) ? 0u : ((((*((signed short*)(unsigned long)(a0 + 76u))) == 0u)) ? 1u : (*((signed short*)(unsigned long)(a0 + 76u))))));}
/* #061: overlay 026 0x02121df4, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov026_02121DF4(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((signed short*)(unsigned long)(a0 + 76u))) != 0u)) ? 0u : ((((*((signed short*)(unsigned long)(a0 + 76u))) == 0u)) ? 1u : (*((signed short*)(unsigned long)(a0 + 76u))))));}
/* #062: overlay 077 0x02156a64, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov077_02156A64(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((signed short*)(unsigned long)(a0 + 76u))) != 10u)) ? 0u : ((((*((signed short*)(unsigned long)(a0 + 76u))) == 10u)) ? 1u : (*((signed short*)(unsigned long)(a0 + 76u))))));}
/* #063: overlay 093 0x02175560, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov093_02175560(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 116u))) == 0u)) ? 0u : ((((*((unsigned int*)(unsigned long)(a0 + 116u))) != 0u)) ? 1u : (*((unsigned int*)(unsigned long)(a0 + 116u))))));}
/* #064: overlay 064 0x02159230, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov064_02159230(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned char*)(unsigned long)(a0 + 27u))) != 0u)) ? 0u : ((((*((unsigned char*)(unsigned long)(a0 + 27u))) == 0u)) ? 1u : (*((unsigned char*)(unsigned long)(a0 + 27u))))));}
/* #065: overlay 024 0x020c516c, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov024_020C516C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned char*)(unsigned long)(a0 + 27u))) != 0u)) ? 0u : ((((*((unsigned char*)(unsigned long)(a0 + 27u))) == 0u)) ? 1u : (*((unsigned char*)(unsigned long)(a0 + 27u))))));}
/* #066: overlay 016 0x020b81a0, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov016_020B81A0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned char*)(unsigned long)(a0 + 27u))) != 0u)) ? 0u : ((((*((unsigned char*)(unsigned long)(a0 + 27u))) == 0u)) ? 1u : (*((unsigned char*)(unsigned long)(a0 + 27u))))));}
/* #067: overlay 016 0x020b7b68, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov016_020B7B68(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned char*)(unsigned long)(a0 + 27u))) != 0u)) ? 0u : ((((*((unsigned char*)(unsigned long)(a0 + 27u))) == 0u)) ? 1u : (*((unsigned char*)(unsigned long)(a0 + 27u))))));}
/* #068: ARM9 0x020070dc, BL xrefs 1, provisional_semantic_C */
unsigned int st_arm9_020070DC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned short*)(unsigned long)(a0 + 12u))) != 0u)) ? 0u : ((((*((unsigned short*)(unsigned long)(a0 + 12u))) == 0u)) ? 1u : (*((unsigned short*)(unsigned long)(a0 + 12u))))));}
/* #069: overlay 058 0x0214f0d8, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov058_0214F0D8(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned short*)(unsigned long)(a0 + 34u))) == 0u)) ? 0u : ((((*((unsigned short*)(unsigned long)(a0 + 34u))) != 0u)) ? 1u : (*((unsigned short*)(unsigned long)(a0 + 34u))))));}
/* #070: overlay 026 0x020f2a2c, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov026_020F2A2C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned short*)(unsigned long)(a0 + 68u))) == 0u)) ? 0u : ((((*((unsigned short*)(unsigned long)(a0 + 68u))) != 0u)) ? 1u : (*((unsigned short*)(unsigned long)(a0 + 68u))))));}
/* #071: overlay 024 0x020cb8ec, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov024_020CB8EC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned char*)(unsigned long)(a0 + 110u))) != 0u)) ? 0u : ((((*((unsigned char*)(unsigned long)(a0 + 110u))) == 0u)) ? 1u : (*((unsigned char*)(unsigned long)(a0 + 110u))))));}
/* #072: ARM9 0x020338d4, BL xrefs 1, provisional_semantic_C */
unsigned int st_arm9_020338D4(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((int)(a0) < (int)(0u))) ? (0u - a0) : a0));}
/* #073: overlay 000 0x02067be0, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov000_02067BE0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((a1 != 0u)) ? (*((unsigned int*)(unsigned long)((((a1 == 0u)) ? (*((unsigned int*)(unsigned long)(a0 + 20u))) : a0) + 24u))) : (((a1 == 0u)) ? (*((unsigned int*)(unsigned long)(a0 + 20u))) : a0)));}
/* #074: overlay 037 0x021201ec, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov037_021201EC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((((*((unsigned short*)(unsigned long)((a0 + 768u) + 2u))) & 4u) == 0u)) ? 0u : (((((*((unsigned short*)(unsigned long)((a0 + 768u) + 2u))) & 4u) != 0u)) ? 1u : (*((unsigned short*)(unsigned long)((a0 + 768u) + 2u))))));}
/* #075: overlay 000 0x02057ee0, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov000_02057EE0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 4u))) == 0u)) ? 0u : ((((*((unsigned int*)(unsigned long)(a0 + 4u))) != 0u)) ? ((*((unsigned int*)(unsigned long)(a0 + 4u))) + 20u) : (*((unsigned int*)(unsigned long)(a0 + 4u))))));}
/* #076: ARM9 0x0202d674, BL xrefs 2, provisional_semantic_C */
unsigned int st_arm9_0202D674(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((((*((unsigned int*)(unsigned long)(a0 + 28u))) >> 24u) & 1u) == 0u)) ? (*((unsigned int*)(unsigned long)(((((((*((unsigned int*)(unsigned long)(a0 + 28u))) >> 24u) & 1u) != 0u)) ? (((((((*((unsigned int*)(unsigned long)(a0 + 28u))) >> 24u) & 1u) != 0u)) ? ((*((unsigned int*)(unsigned long)(a0 + 28u))) << 8u) : a0) >> 8u) : ((((((*((unsigned int*)(unsigned long)(a0 + 28u))) >> 24u) & 1u) != 0u)) ? ((*((unsigned int*)(unsigned long)(a0 + 28u))) << 8u) : a0)) + 8u))) : ((((((*((unsigned int*)(unsigned long)(a0 + 28u))) >> 24u) & 1u) != 0u)) ? (((((((*((unsigned int*)(unsigned long)(a0 + 28u))) >> 24u) & 1u) != 0u)) ? ((*((unsigned int*)(unsigned long)(a0 + 28u))) << 8u) : a0) >> 8u) : ((((((*((unsigned int*)(unsigned long)(a0 + 28u))) >> 24u) & 1u) != 0u)) ? ((*((unsigned int*)(unsigned long)(a0 + 28u))) << 8u) : a0))));}
/* #077: overlay 031 0x020d9d0c, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov031_020D9D0C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((signed short*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 0u))) + 18u))) == 0u)) ? 0u : ((((*((signed short*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 0u))) + 18u))) != 0u)) ? 1u : (*((signed short*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 0u))) + 18u))))));}
/* #078: overlay 031 0x020d9878, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov031_020D9878(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 4u))) + 104u))) != 71u)) ? 0u : ((((*((unsigned int*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 4u))) + 104u))) == 71u)) ? 1u : (*((unsigned int*)(unsigned long)((*((unsigned int*)(unsigned long)(a0 + 4u))) + 104u))))));}
/* #079: overlay 088 0x02169b7c, BL xrefs 1, provisional_semantic_C */
void st_ov088_02169B7C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if((a1 == 1u)){*((unsigned int*)(unsigned long)(a0 + 148u)) = (unsigned int)((((a1 == 1u)) ? 0u : a2));}if((a1 == 1u)){*((unsigned char*)(unsigned long)(a0 + 160u)) = (unsigned char)((((a1 == 1u)) ? 1u : a1));}}
/* #080: overlay 080 0x0215c320, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov080_0215C320(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((a0 != 9u)) ? 1u : (((a0 == 9u)) ? 0u : a0)));}
/* #081: overlay 023 0x020ef6ac, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov023_020EF6AC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((a1 != 2u)) ? 0u : (((a1 == 2u)) ? 1u : a0)));}
/* #082: ARM9 0x02009ec4, BL xrefs 1, provisional_semantic_C */
void st_arm9_02009EC4(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((*((unsigned int*)(unsigned long)(a0 + 0u))) == 1u)){*((unsigned short*)(unsigned long)(a0 + 16u)) = (unsigned short)(a1);}if(((*((unsigned int*)(unsigned long)(a0 + 0u))) == 1u)){*((unsigned short*)(unsigned long)(a0 + 18u)) = (unsigned short)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) == 1u)) ? (((((*((unsigned int*)(unsigned long)(a0 + 0u))) == 1u)) ? (*((unsigned short*)(unsigned long)(a0 + 18u))) : (*((unsigned int*)(unsigned long)(a0 + 0u)))) | 4u) : a1));}}
/* #083: overlay 042 0x0212b264, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov042_0212B264(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((signed short*)(unsigned long)(a0 + 76u))) != 4u)) ? 0u : ((((*((signed short*)(unsigned long)(a0 + 76u))) == 4u)) ? 1u : (*((signed short*)(unsigned long)(a0 + 76u))))));}
/* #084: overlay 036 0x0211d8a0, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov036_0211D8A0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 228u))) != 87u)) ? 1u : ((((*((unsigned int*)(unsigned long)(a0 + 228u))) == 87u)) ? 0u : (*((unsigned int*)(unsigned long)(a0 + 228u))))));}
/* #085: overlay 031 0x0210a938, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov031_0210A938(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 188u))) != 1u)) ? 120u : ((((*((unsigned int*)(unsigned long)(a0 + 188u))) == 1u)) ? (*((unsigned short*)(unsigned long)(a0 + 172u))) : a0)));}
/* #086: ARM9 0x0200b69c, BL xrefs 1, provisional_semantic_C */
unsigned int st_arm9_0200B69C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((a0 == 0u)) ? 0u : (((a0 != 0u)) ? ((((a0 != 0u)) ? (*((unsigned short*)(unsigned long)(a0 + 48u))) : a0) << 3u) : (((a0 != 0u)) ? (*((unsigned short*)(unsigned long)(a0 + 48u))) : a0))));}
/* #087: ARM9 0x0200b5bc, BL xrefs 1, provisional_semantic_C */
unsigned int st_arm9_0200B5BC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((a0 == 0u)) ? 0u : (((a0 != 0u)) ? ((((a0 != 0u)) ? (*((unsigned short*)(unsigned long)(a0 + 28u))) : a0) << 3u) : (((a0 != 0u)) ? (*((unsigned short*)(unsigned long)(a0 + 28u))) : a0))));}
/* #088: ARM9 0x0200b5a8, BL xrefs 1, provisional_semantic_C */
unsigned int st_arm9_0200B5A8(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((a0 == 0u)) ? 0u : (((a0 != 0u)) ? ((((a0 != 0u)) ? (*((unsigned short*)(unsigned long)(a0 + 12u))) : a0) << 3u) : (((a0 != 0u)) ? (*((unsigned short*)(unsigned long)(a0 + 12u))) : a0))));}
/* #089: ARM9 0x02002c8c, BL xrefs 1, provisional_semantic_C */
void st_arm9_02002C8C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)){*((unsigned int*)(unsigned long)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)) ? (*((unsigned int*)(unsigned long)(a0 + 0u))) : (*((unsigned int*)(unsigned long)(a0 + 0u)))) + 0u)) = (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)) ? 0u : a2));}if(((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)){*((unsigned int*)(unsigned long)(a0 + 0u)) = (unsigned int)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) != 0u)) ? 0u : a2));}}
/* #090: overlay 084 0x0215c050, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov084_0215C050(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)(((((a1 != 0u)) ? (*((unsigned int*)(unsigned long)((((a1 != 0u)) ? (a0 + ((((a1 != 0u)) ? (a1 - 1u) : a1) << 2u)) : a0) + 1000u))) : (((a1 != 0u)) ? (a0 + ((((a1 != 0u)) ? (a1 - 1u) : a1) << 2u)) : a0)) + 4u));}
/* #091: overlay 089 0x021670bc, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov089_021670BC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((a0 == 0u)) ? 0u : (((a0 != 0u)) ? (*((unsigned int*)(unsigned long)((((a0 != 0u)) ? (*((unsigned int*)(unsigned long)(a0 + 0u))) : a0) + 0u))) : (((a0 != 0u)) ? (*((unsigned int*)(unsigned long)(a0 + 0u))) : a0))));}
/* #092: ARM9 0x02009ea4, BL xrefs 1, provisional_semantic_C */
void st_arm9_02009EA4(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((*((unsigned int*)(unsigned long)(a0 + 0u))) == 1u)){*((unsigned short*)(unsigned long)(a0 + 12u)) = (unsigned short)(a1);}if(((*((unsigned int*)(unsigned long)(a0 + 0u))) == 1u)){*((unsigned short*)(unsigned long)(a0 + 14u)) = (unsigned short)(a2);}if(((*((unsigned int*)(unsigned long)(a0 + 0u))) == 1u)){*((unsigned short*)(unsigned long)(a0 + 18u)) = (unsigned short)(((((*((unsigned int*)(unsigned long)(a0 + 0u))) == 1u)) ? (((((*((unsigned int*)(unsigned long)(a0 + 0u))) == 1u)) ? (*((unsigned short*)(unsigned long)(a0 + 18u))) : (*((unsigned int*)(unsigned long)(a0 + 0u)))) | 8u) : a1));}}
/* #093: overlay 088 0x02169b0c, BL xrefs 1, provisional_semantic_C */
void st_ov088_02169B0C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if((a1 == 25u)){*((unsigned int*)(unsigned long)(a0 + 140u)) = (unsigned int)((((a1 == 25u)) ? ((((a1 == 25u)) ? ((((a1 == 25u)) ? (*((unsigned int*)(unsigned long)(a2 + 0u))) : a1) << 16u) : (((a1 == 25u)) ? (*((unsigned int*)(unsigned long)(a2 + 0u))) : a1)) >> 16u) : (((a1 == 25u)) ? ((((a1 == 25u)) ? (*((unsigned int*)(unsigned long)(a2 + 0u))) : a1) << 16u) : (((a1 == 25u)) ? (*((unsigned int*)(unsigned long)(a2 + 0u))) : a1))));}}
/* #094: overlay 026 0x020eae28, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov026_020EAE28(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((a0 == 0u)) ? 1u : a0));}
/* #095: overlay 093 0x02171f1c, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov093_02171F1C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((a1 != 39u)) ? 0u : (((a1 == 39u)) ? 1u : a0)));}
/* #096: overlay 026 0x020eafbc, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov026_020EAFBC(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((a1 == 0u)) ? (*((signed char*)(unsigned long)(a0 + 13u))) : a0));}
/* #097: overlay 092 0x02166428, BL xrefs 1, provisional_semantic_C */
void st_ov092_02166428(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){if(((*((unsigned char*)(unsigned long)(a0 + 92u))) == 0u)){*((unsigned short*)(unsigned long)(a0 + 86u)) = (unsigned short)(((((*((unsigned char*)(unsigned long)(a0 + 92u))) == 0u)) ? (((((*((unsigned char*)(unsigned long)(a0 + 92u))) == 0u)) ? (*((signed short*)(unsigned long)(a0 + 86u))) : (*((unsigned char*)(unsigned long)(a0 + 92u)))) + ((unsigned int)((int)((((*((unsigned char*)(unsigned long)(a0 + 92u))) == 0u)) ? (a1 << 16u) : a1) >> 16u))) : ((((*((unsigned char*)(unsigned long)(a0 + 92u))) == 0u)) ? (a1 << 16u) : a1)));}}
/* #098: overlay 036 0x0211d398, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov036_0211D398(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((((((*((unsigned int*)(unsigned long)(a0 + 228u))) == 1u)) ? (*((unsigned char*)(unsigned long)(a0 + 723u))) : a0) != 0u)) ? 0u : (((((((*((unsigned int*)(unsigned long)(a0 + 228u))) == 1u)) ? (*((unsigned char*)(unsigned long)(a0 + 723u))) : a0) == 0u)) ? 1u : ((((*((unsigned int*)(unsigned long)(a0 + 228u))) == 1u)) ? (*((unsigned char*)(unsigned long)(a0 + 723u))) : a0))));}
/* #099: overlay 036 0x0211d3d0, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov036_0211D3D0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((((((*((unsigned int*)(unsigned long)(a0 + 228u))) == 86u)) ? (*((unsigned char*)(unsigned long)(a0 + 723u))) : a0) != 0u)) ? 0u : (((((((*((unsigned int*)(unsigned long)(a0 + 228u))) == 86u)) ? (*((unsigned char*)(unsigned long)(a0 + 723u))) : a0) == 0u)) ? 1u : ((((*((unsigned int*)(unsigned long)(a0 + 228u))) == 86u)) ? (*((unsigned char*)(unsigned long)(a0 + 723u))) : a0))));}
/* #100: overlay 036 0x0211d3b4, BL xrefs 1, provisional_semantic_C */
unsigned int st_ov036_0211D3B4(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3){return (unsigned int)((((((((*((unsigned int*)(unsigned long)(a0 + 228u))) == 87u)) ? (*((unsigned char*)(unsigned long)(a0 + 723u))) : a0) != 0u)) ? 0u : (((((((*((unsigned int*)(unsigned long)(a0 + 228u))) == 87u)) ? (*((unsigned char*)(unsigned long)(a0 + 723u))) : a0) == 0u)) ? 1u : ((((*((unsigned int*)(unsigned long)(a0 + 228u))) == 87u)) ? (*((unsigned char*)(unsigned long)(a0 + 723u))) : a0))));}
