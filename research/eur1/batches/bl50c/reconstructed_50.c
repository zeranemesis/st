/* Spirit Tracks EUR1: 50 original ARM BL target C research reconstructions. */
/* Standalone research: NOT built into Nintendo DS; CodeWarrior matching unverified. */
#include <stdint.h>
#include <stddef.h>

/* [001] arm9 0x02002EB8 size=32 sha256=b1b0b1369ccbbdd6e5ec8d21cc208c70836ab939c65fa7c33c7b118039d02143 BL=1 */
uint32_t st_arm9_02002EB8(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r2 = *(volatile uint32_t*)(uintptr_t)(r0+0); L1: ; uint32_t _v1 = r2 - 0x0u; Z = (_v1==0); N = ((_v1>>31)&1); C = (r2 >= 0x0u); V = (((r2 ^ 0x0u) & (r2 ^ _v1) & 0x80000000u)!=0); L2: if (!Z) { r2 = *(volatile uint32_t*)(uintptr_t)(r0+0); } L3: if (!Z) { r3 = 0x1u; } L4: if (!Z) { *(volatile uint16_t*)(uintptr_t)(r2+52) = (uint16_t)r3; } L5: if (!Z) { r0 = *(volatile uint32_t*)(uintptr_t)(r0+0); } L6: if (!Z) { *(volatile uint16_t*)(uintptr_t)(r0+56) = (uint16_t)r1; } L7: return r0; }

/* [002] arm9 0x0200371C size=36 sha256=6ee69c1cbebe30e14cd9d0514a659af7d270739e42c84c083d28912e71dfafe0 BL=1 */
uint32_t st_arm9_0200371C(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r1 = 0x02045cccu; L1: r2 = *(volatile uint32_t*)(uintptr_t)(r1+0); L2: ; uint32_t _v2=r0&r2; Z=(_v2==0); N=((_v2>>31)&1); L3: if (!Z) { r0 = 0x0u; } L4: if (Z) { r0 = (r2 | r0); } L5: if (Z) { *(volatile uint32_t*)(uintptr_t)(r1+0) = (uint32_t)r0; } L6: if (Z) { r0 = 0x1u; } L7: return r0; }

/* [003] arm9 0x020092CC size=32 sha256=0d5de6620ef028cf8c82fe77eee6a0589003b63886eb2e22fa93ebb5360254fa BL=1 */
void st_arm9_020092CC(uint32_t p){register uint32_t i asm("r3")=0;register uint32_t value asm("r2")=-1u;do{register uint32_t dst asm("r1")=p+(i<<2);asm volatile("":"+r"(dst));i++;*(volatile uint32_t*)(dst+8)=value;asm volatile("":"+r"(i));}while((int32_t)i<3);}

/* [004] arm9 0x020131EC size=40 sha256=b87afbc2a8dc0c5c634abd71f4b04414c1dc05a487207e491000036c94019195 BL=1 */
uint32_t st_arm9_020131EC(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r1 = 0x04000004u; L1: r0 = (uint32_t)*(volatile uint16_t*)(uintptr_t)(r1+0); L2: ; uint32_t _v2=r0&0x1u; Z=(_v2==0); N=((_v2>>31)&1); L3: if (!Z) goto L1; L4: r1 = 0x04000004u; L5: r0 = (uint32_t)*(volatile uint16_t*)(uintptr_t)(r1+0); L6: ; uint32_t _v6=r0&0x1u; Z=(_v6==0); N=((_v6>>31)&1); L7: if (Z) goto L5; L8: return r0; }

/* [005] arm9 0x02014704 size=40 sha256=2e487c5d94baa2b1a4ef03f56fa8f0e82aba4fcf3848b617bdc7b3d616f7e6c8 BL=2 */
uint32_t st_arm9_02014704(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: ; uint32_t _v0 = r0 - 0x0u; Z = (_v0==0); N = ((_v0>>31)&1); C = (r0 >= 0x0u); V = (((r0 ^ 0x0u) & (r0 ^ _v0) & 0x80000000u)!=0); L1: r3 = 0x0u; L2: if (Z) goto L7; L3: r2 = *(volatile uint32_t*)(uintptr_t)(r0+0); L4: r1 = 0x554e5348u; L5: ; uint32_t _v5 = r2 - r1; Z = (_v5==0); N = ((_v5>>31)&1); C = (r2 >= r1); V = (((r2 ^ r1) & (r2 ^ _v5) & 0x80000000u)!=0); L6: if (Z) { r3 = *(volatile uint32_t*)(uintptr_t)(r0+36); } L7: r0 = r3; L8: return r0; }

/* [006] arm9 0x0202694C size=48 sha256=ffb73a59195e6ba86c5f199853481582b46d9782d5de854355b59769f7e51ae5 BL=1 */
uint32_t st_arm9_0202694C(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r2 = *(volatile uint32_t*)(uintptr_t)(r0+0); L1: ; uint32_t _v1 = r2 - 0x0u; Z = (_v1==0); N = ((_v1>>31)&1); C = (r2 >= 0x0u); V = (((r2 ^ 0x0u) & (r2 ^ _v1) & 0x80000000u)!=0); L2: if (Z) goto L10; L3: r1 = *(volatile uint32_t*)(uintptr_t)(r2+16); L4: *(volatile uint32_t*)(uintptr_t)(r0+0) = (uint32_t)r1; L5: ; uint32_t _v5 = r1 - 0x0u; Z = (_v5==0); N = ((_v5>>31)&1); C = (r1 >= 0x0u); V = (((r1 ^ 0x0u) & (r1 ^ _v5) & 0x80000000u)!=0); L6: if (!Z) { r0 = 0x0u; } L7: if (!Z) { *(volatile uint32_t*)(uintptr_t)(r1+20) = (uint32_t)r0; } L8: if (Z) { r1 = 0x0u; } L9: if (Z) { *(volatile uint32_t*)(uintptr_t)(r0+4) = (uint32_t)r1; } L10: r0 = r2; L11: return r0; }

/* [007] arm9 0x0202815C size=12 sha256=f7e146ee9e88c39b1758c3dd337d6e4d5cf4bb336b965a5f72911e6bd4a17587 BL=10 */
uint32_t st_arm9_0202815C(uint32_t x) { uint32_t y; do { int borrow = __builtin_usub_overflow(x, 4u, &y); x = y; asm volatile("" : "+r"(x)); if (borrow) break; } while (1); return x; }

/* [008] arm9 0x0202CE2C size=32 sha256=5a95aefaf18266d88163739e9e7fe9dca2933f479554b8fd4deda35aee415085 BL=2 */
uint32_t st_arm9_0202CE2C(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: ; uint32_t _v0 = r2 - 0x0u; Z = (_v0==0); N = ((_v0>>31)&1); C = (r2 >= 0x0u); V = (((r2 ^ 0x0u) & (r2 ^ _v0) & 0x80000000u)!=0); L1: if (Z) { r1 = 0x0u; } L2: if (Z) goto L5; L3: ; uint32_t _v3 = r1 - 0x0u; Z = (_v3==0); N = ((_v3>>31)&1); C = (r1 >= 0x0u); V = (((r1 ^ 0x0u) & (r1 ^ _v3) & 0x80000000u)!=0); L4: if (Z) { r2 = 0x0u; } L5: *(volatile uint32_t*)(uintptr_t)(r0+84) = (uint32_t)r1; L6: *(volatile uint32_t*)(uintptr_t)(r0+88) = (uint32_t)r2; L7: return r0; }

/* [009] arm9 0x0202EDF4 size=24 sha256=643423ffb43acb7dce18b8b8cc48f9e1cc8db4c9dbc5ab6b2145c2a514920d1b BL=1 */
void st_arm9_0202EDF4(uint32_t mask){volatile uint16_t*ptr=(volatile uint16_t*)0x020505d0u;asm volatile("" : "+r"(ptr));while((ptr[29]&mask)!=0){} }

/* [010] overlay_000 0x0205FDD0 size=40 sha256=d5e529c05ee5f81c265b4222e03d69151f82e173795ebe10f7b0285c0aa4994f BL=1 */
uint32_t st_ov000_0205FDD0(uint32_t addr){register uint32_t z asm("r2")=0; register uint32_t vt asm("r1")=0x020b1cc8u;asm volatile("" : "+r"(z));asm volatile("" : "+r"(vt));*(volatile uint32_t*)(addr+8)=z;*(volatile uint16_t*)(addr+14)=z;*(volatile uint16_t*)(addr+16)=z;asm volatile("" ::: "memory");((uint32_t*)(addr))[0]=vt;((uint32_t*)(addr))[1]=z;asm volatile("" ::: "memory");*(volatile uint32_t*)(addr+28)=z;asm volatile("" ::: "memory");*(volatile uint16_t*)(addr+32)=z;return addr;}

/* [011] overlay_000 0x0205FDF8 size=40 sha256=d5e529c05ee5f81c265b4222e03d69151f82e173795ebe10f7b0285c0aa4994f BL=1 */
uint32_t st_ov000_0205FDF8(uint32_t addr){register uint32_t z asm("r2")=0; register uint32_t vt asm("r1")=0x020b1cc8u;asm volatile("" : "+r"(z));asm volatile("" : "+r"(vt));*(volatile uint32_t*)(addr+8)=z;*(volatile uint16_t*)(addr+14)=z;*(volatile uint16_t*)(addr+16)=z;asm volatile("" ::: "memory");((uint32_t*)(addr))[0]=vt;((uint32_t*)(addr))[1]=z;asm volatile("" ::: "memory");*(volatile uint32_t*)(addr+28)=z;asm volatile("" ::: "memory");*(volatile uint16_t*)(addr+32)=z;return addr;}

/* [012] overlay_000 0x0206F6AC size=44 sha256=7f69271f9212b1b1f01a5ce0ce5057be31630488ec26c682a36c0c32564f8dd0 BL=1 */
void st_ov000_0206F6AC(uint32_t p) {
    register uint32_t i asm("r3")=0;
    register uint32_t v asm("r2")=~0u;
    asm volatile("" : "+r"(i), "+r"(v));
    do {
        register uint32_t addr asm("r1")=p+(i<<2);
        asm volatile("" : "+r"(addr));
        *(volatile uint16_t*)(addr+4)=v;
        asm volatile("" : "+r"(i) : "r"(addr) : "memory");
        i++;
        asm volatile("" : "+r"(addr) : "r"(i) : "memory");
        *(volatile uint16_t*)(addr+6)=v;
        asm volatile("" : "+r"(i));
    } while ((int32_t)i<3);
    register uint32_t zero asm("r1")=0;
    asm volatile("" : "+r"(zero));
    *(volatile uint32_t*)(p+20)=zero;
}


/* [013] overlay_000 0x020A6C60 size=12 sha256=e914998634460875fd1a377db48d15e7c81028e5ca10010ddd1d06599caca06c BL=2 */
uint32_t st_ov000_020A6C60(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r3 = (r2 - r1); L1: *(uint32_t*)(uintptr_t)(r0+0u) = r1; *(uint32_t*)(uintptr_t)(r0+4u) = r2; *(uint32_t*)(uintptr_t)(r0+8u) = r3; L2: return r0; }

/* [014] overlay_003 0x020B7E2C size=44 sha256=ce664e3f5404d07c7eb3cf9c86ae7b549818c6133219d78bcdc4732686da71ba BL=3 */
uint32_t st_ov003_020B7E2C(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r1 = *(volatile uint32_t*)(uintptr_t)(r0+272); L1: r2 = *(volatile uint32_t*)(uintptr_t)(r0+256); L2: r1 = (r1 - 0x1u); L3: ; uint32_t _v3 = r1 - r2; Z = (_v3==0); N = ((_v3>>31)&1); C = (r1 >= r2); V = (((r1 ^ r2) & (r1 ^ _v3) & 0x80000000u)!=0); L4: if (!Z&&(N==V)) { r1 = r2; } L5: if (!Z&&(N==V)) goto L8; L6: ; uint32_t _v6 = r1 - 0x0u; Z = (_v6==0); N = ((_v6>>31)&1); C = (r1 >= 0x0u); V = (((r1 ^ 0x0u) & (r1 ^ _v6) & 0x80000000u)!=0); L7: if (N!=V) { r1 = 0x0u; } L8: r0 = (r0 + (r1 << 1u)); L9: r0 = (uint32_t)*(volatile uint16_t*)(uintptr_t)(r0+224); L10: return r0; }

/* [015] overlay_007 0x020B7014 size=60 sha256=9f5e7c2ea09f8c6aece1fdd1c41fd52a38cf50c6ccb40857133a4d0fee747700 BL=1 */
uint32_t st_ov007_020B7014(void){register uint32_t p asm("r0")=0x020b8520u;asm volatile("":"+r"(p));register uint32_t m asm("r3")=*(volatile uint32_t*)p;if(!(m&1u)){register uint32_t v asm("r2")=0x020b84bcu;register uint32_t n asm("r1")=~0u;asm volatile("":"+r"(v),"+r"(n));*(volatile uint32_t*)(p+40)=v;*(volatile uint32_t*)(p+44)=n;*(volatile uint32_t*)p=m|1u;}p=0x020b8548u;asm volatile("":"+r"(p));return p;}

/* [016] overlay_017 0x020BD6F8 size=40 sha256=a8c501a2c24066b3c8a8cc5d374472854508cbaf2eb86e266f5c5a2e69cebe0c BL=2 */
uint32_t st_ov017_020BD6F8(uint32_t p){register uint32_t r1 asm("r1")=*(volatile uint16_t*)(p+64);register uint32_t r2 asm("r2")=0;asm volatile("":"+r"(r1),"+r"(r2));if(r1==0){p=*(volatile uint32_t*)(p+160);p=*(volatile uint32_t*)(p+104);if(p!=50)r2=1;}asm volatile("":"+r"(r2):"r"(p));return r2;}

/* [017] overlay_022 0x020ED140 size=48 sha256=36d33628ea479ea63880bfabb94066b70f8ab151ed211baa9e614efac44c0b6e BL=1 */
void st_ov022_020ED140(uint32_t p) {
    register uint32_t addr asm("r1")=p+0xaf000u;
    register uint32_t i asm("r3")=0;
    asm volatile("" : "+r"(addr), "+r"(i));
    *(volatile uint32_t*)(addr+40)=i;
    *(volatile uint32_t*)(addr+44)=i;
    asm volatile("" ::: "r2", "memory");
    register uint32_t v asm("r2")=~0u;
    asm volatile("" : "+r"(v));
    do {
        register uint32_t d asm("r1")=p+(i<<2);
        asm volatile("" : "+r"(d));
        d+=0xaf000u;
        asm volatile("" : "+r"(d));
        asm volatile("" : "+r"(i) : "r"(d) : "memory");
        i++;
        asm volatile("" : "+r"(i));
        *(volatile uint32_t*)(d+4)=v;
        asm volatile("" : "+r"(i));
    } while (i<3);
}


/* [018] overlay_026 0x020EA81C size=36 sha256=d5793257b43c178719ee5f713439753e76a3c19ae90f3cdf4176dae8b02b52df BL=1 */
void st_ov026_020EA81C(uint32_t p){register uint32_t i asm("r3")=0;asm volatile("":"+r"(i));register uint32_t value asm("r2")=i;do{register uint32_t dst asm("r1")=p+(i<<2);asm volatile("":"+r"(dst));i++;*(volatile uint32_t*)(dst+32)=value;asm volatile("":"+r"(i));}while((int32_t)i<8);*(volatile uint32_t*)(p+20)=value;}

/* [019] overlay_026 0x020F169C size=32 sha256=1cc311f5f96d045709f220016a511571b1974f77d9319d3a0c2e2fb2cf533fbf BL=2 */
void st_ov026_020F169C(uint32_t p){register uint32_t i asm("r3")=0;register uint32_t value asm("r2")=4194304u;do{register uint32_t dst asm("r1")=p+(i<<2);asm volatile("":"+r"(dst));i++;*(volatile uint32_t*)(dst+12)=value;asm volatile("":"+r"(i));}while((int32_t)i<5);}

/* [020] overlay_026 0x020F7A3C size=8 sha256=ae5cd4653b8d552cc544515329f444c0365b59788fe1c12c58171d8a19fac68d BL=2 */
uint32_t st_ov026_020F7A3C(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: *(uint32_t*)(uintptr_t)(r0+0u) = r1; *(uint32_t*)(uintptr_t)(r0+4u) = r2; *(uint32_t*)(uintptr_t)(r0+8u) = r3; L1: return r0; }

/* [021] overlay_026 0x020FC9C0 size=48 sha256=204f39e4a2249fe471617c37744dafd67de0b35aab9914424f19e24d740389f9 BL=2 */
uint32_t st_ov026_020FC9C0(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: ; uint32_t _v0 = r1 - 0x4u; Z = (_v0==0); N = ((_v0>>31)&1); C = (r1 >= 0x4u); V = (((r1 ^ 0x4u) & (r1 ^ _v0) & 0x80000000u)!=0); L1: if (N!=V) { uint32_t _v1 = r1 - r2; Z = (_v1==0); N = ((_v1>>31)&1); C = (r1 >= r2); V = (((r1 ^ r2) & (r1 ^ _v1) & 0x80000000u)!=0); } L2: if (N==V) { r1 = 0x0u; } L3: if (N==V) goto L10; L4: ; uint32_t _v4 = r1 - 0x3u; Z = (_v4==0); N = ((_v4>>31)&1); C = (r1 >= 0x3u); V = (((r1 ^ 0x3u) & (r1 ^ _v4) & 0x80000000u)!=0); L5: if (Z) { r1 = 0x1u; } L6: if (Z) goto L10; L7: ; uint32_t _v7 = r1 - 0x2u; Z = (_v7==0); N = ((_v7>>31)&1); C = (r1 >= 0x2u); V = (((r1 ^ 0x2u) & (r1 ^ _v7) & 0x80000000u)!=0); L8: if (Z) { r1 = 0x2u; } L9: if (!Z) { r1 = 0x3u; } L10: *(volatile uint32_t*)(uintptr_t)(r0+0) = (uint32_t)r1; L11: return r0; }

/* [022] overlay_026 0x02106B34 size=44 sha256=f5f7d3e085dc1d107b844c2cbe02ddf3458cd5c90659d89040a309e2956a3c67 BL=1 */
void st_ov026_02106B34(uint32_t p, uint32_t val) {
    register uint32_t zero asm("r3")=0;
    asm volatile("" : "+r"(zero));
    ((uint32_t*)p)[0]=val;
    ((uint32_t*)p)[1]=zero;
    asm volatile("" ::: "r2", "memory");
    register uint32_t v asm("r2")=7;
    asm volatile("" : "+r"(v));
    *(volatile uint32_t*)(p+8)=zero;
    *(volatile uint32_t*)(p+12)=zero;
    *(volatile uint32_t*)(p+16)=v;
    *(volatile uint8_t*)(p+20)=zero;
    *(volatile uint8_t*)(p+21)=zero;
    *(volatile uint16_t*)(p+22)=zero;
    *(volatile uint8_t*)(p+24)=zero;
}


/* [023] overlay_026 0x0211E0F0 size=32 sha256=1dccfffe735dd14b38f666627fd46c540910aac5bd517b09d4ab82230e21de76 BL=1 */
uint32_t st_ov026_0211E0F0(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r0 = 0x027e09b8u; L1: r0 = *(volatile uint32_t*)(uintptr_t)(r0+0); L2: r0 = *(volatile uint32_t*)(uintptr_t)(r0+20); L3: ; uint32_t _v3=r0&0x20u; Z=(_v3==0); N=((_v3>>31)&1); L4: if (!Z) { r0 = 0x1u; } L5: if (Z) { r0 = 0x0u; } L6: return r0; }

/* [024] overlay_026 0x0211F1CC size=36 sha256=760384a0f7c21cc345243c74226ef2e53bd45a40e3010e95dbf176f92864579f BL=2 */
void st_ov026_0211F1CC(uint32_t p,uint32_t flag){register uint32_t i asm("r3")=0;do{register uint32_t dst asm("r2")=p+(i<<2);asm volatile("":"+r"(dst));dst=*(volatile uint32_t*)(dst+876);asm volatile("":"+r"(i) : "r"(dst):"memory");i++;if(dst)*(volatile uint8_t*)(dst+592)=flag;asm volatile("":"+r"(i));}while((int32_t)i<3);asm volatile("" ::: "memory");}

/* [025] overlay_026 0x02121258 size=24 sha256=2ab9ced2a5e55386274ffb834a85c62ffd84d10169c2c422a0353cc5f49de906 BL=1 */
void st_ov026_02121258(uint32_t*p){register uint32_t a asm("r2")=0x52425254u,b asm("r1")=0x02138350u;asm volatile("" : "+r"(a),"+r"(b));p[0]=b;p[1]=a;}

/* [026] overlay_026 0x021212A0 size=24 sha256=ea57f504076d6a9fddd90292907edec26e016788e10268579e90243e69316696 BL=1 */
void st_ov026_021212A0(uint32_t*p){register uint32_t a asm("r2")=0x52425254u,b asm("r1")=0x0213835Cu;asm volatile("" : "+r"(a),"+r"(b));p[0]=b;p[1]=a;}

/* [027] overlay_030 0x0214D724 size=32 sha256=479808b8496e36109e4c88523c7017812d912e0450d814fbe09cd41a624adfd6 BL=1 */
uint32_t st_ov030_0214D724(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r0 = 0x027e09b8u; L1: r0 = *(volatile uint32_t*)(uintptr_t)(r0+0); L2: r0 = *(volatile uint32_t*)(uintptr_t)(r0+52); L3: ; uint32_t _v3=r0&0x40000u; Z=(_v3==0); N=((_v3>>31)&1); L4: if (!Z) { r0 = 0x1u; } L5: if (Z) { r0 = 0x0u; } L6: return r0; }

/* [028] overlay_030 0x0214D744 size=32 sha256=ba160f34db1a93d900aaeb59a3702363180778ff3f20e83f3c5462dfefae2deb BL=1 */
uint32_t st_ov030_0214D744(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r0 = 0x027e09b8u; L1: r0 = *(volatile uint32_t*)(uintptr_t)(r0+0); L2: r0 = *(volatile uint32_t*)(uintptr_t)(r0+20); L3: ; uint32_t _v3=r0&0x800u; Z=(_v3==0); N=((_v3>>31)&1); L4: if (!Z) { r0 = 0x1u; } L5: if (Z) { r0 = 0x0u; } L6: return r0; }

/* [029] overlay_031 0x020E0398 size=12 sha256=535c93f237a12b181253c514cde0e14b31722760549b652944cd83a115838ec7 BL=1 */
uint32_t st_ov031_020E0398(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r2 = 0x0u; L1: *(uint32_t*)(uintptr_t)(r0+0u) = r1; *(uint32_t*)(uintptr_t)(r0+4u) = r2; L2: return r0; }

/* [030] overlay_032 0x0211FCDC size=24 sha256=0fab83426c9fae21a96dbf442c1ac009b17a94682cbbfc651f2729585cfdccec BL=1 */
void st_ov032_0211FCDC(uint32_t*p){register uint32_t a asm("r2")=0x534B4449u,b asm("r1")=0x021226BCu;asm volatile("" : "+r"(a),"+r"(b));p[0]=b;p[1]=a;}

/* [031] overlay_038 0x0211988C size=52 sha256=287c5537495bb792dcb5f759ce0473a0e6260b6e5d4d1c6963b69f00bcab2b33 BL=2 */
uint32_t st_ov038_0211988C(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r1 = 0x021215c4u; L1: goto L3; L2: r1 = (r2 + 0x294u); L3: r2 = *(volatile uint32_t*)(uintptr_t)(r1+0); L4: ; uint32_t _v4 = r2 - r0; Z = (_v4==0); N = ((_v4>>31)&1); C = (r2 >= r0); V = (((r2 ^ r0) & (r2 ^ _v4) & 0x80000000u)!=0); L5: if (Z) goto L8; L6: ; uint32_t _v6 = r2 - 0x0u; Z = (_v6==0); N = ((_v6>>31)&1); C = (r2 >= 0x0u); V = (((r2 ^ 0x0u) & (r2 ^ _v6) & 0x80000000u)!=0); L7: if (!Z) goto L2; L8: ; uint32_t _v8 = r2 - r0; Z = (_v8==0); N = ((_v8>>31)&1); C = (r2 >= r0); V = (((r2 ^ r0) & (r2 ^ _v8) & 0x80000000u)!=0); L9: if (Z) { r0 = *(volatile uint32_t*)(uintptr_t)(r0+660); } L10: if (Z) { *(volatile uint32_t*)(uintptr_t)(r1+0) = (uint32_t)r0; } L11: return r0; }

/* [032] overlay_040 0x0212C6D0 size=28 sha256=2f8b7fdf335a8fd15c9291000d0233fe1b65346fbe1111bbb52795878dfa54f3 BL=1 */
void st_ov040_0212C6D0(volatile uint8_t *p,uint16_t kind){register uint32_t a asm("r3")=0x544c4b54u,b asm("r2")=0x0212ea08u;asm volatile("" : "+r"(a),"+r"(b));((uint32_t*)p)[0]=b;((uint32_t*)p)[1]=a;asm volatile("" : : "r"(kind): "memory");*(volatile uint16_t*)(p+8)=kind;}

/* [033] overlay_062 0x02159738 size=36 sha256=5d90cf023ee8291dece43e3d50fc2ea145676e928833c0971cb9275437b86255 BL=1 */
void st_ov062_02159738(uint8_t *p){volatile int16_t*src=(volatile int16_t*)0x0215f888u;int32_t a=src[0];asm volatile("" : "+r"(a));*(volatile uint16_t*)(p+220)=a;int32_t b=src[1];int32_t c=src[2];asm volatile("" : "+r"(b),"+r"(c));*(volatile uint16_t*)(p+222)=c;*(volatile uint16_t*)(p+224)=b;}

/* [034] overlay_069 0x02159F14 size=24 sha256=47c0c07fec0710bca2b5fbca6e3b958c7e74eb91e0dfb404fea08e2350d00b77 BL=1 */
void st_ov069_02159F14(uint32_t*p){register uint32_t a asm("r2")=0x52423146u,b asm("r1")=0x0215B090u;asm volatile("" : "+r"(a),"+r"(b));p[0]=b;p[1]=a;}

/* [035] overlay_069 0x0215A954 size=24 sha256=0abfe6c6e5392099ce9c4b0b63f78638365ab920a0facb2e17cc47ebbde8096f BL=1 */
void st_ov069_0215A954(uint32_t*p){register uint32_t a asm("r2")=0x52425250u,b asm("r1")=0x0215B350u;asm volatile("" : "+r"(a),"+r"(b));p[0]=b;p[1]=a;}

/* [036] overlay_070 0x0214B2A0 size=36 sha256=669b717b06246971c4a370b7dede02b89037c830498f214ddd5d97c769bf9c08 BL=1 */
uint32_t st_ov070_0214B2A0(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r0 = 0x027e09a4u; L1: r0 = *(volatile uint32_t*)(uintptr_t)(r0+0); L2: r0 = *(volatile uint32_t*)(uintptr_t)(r0+0); L3: ; uint32_t _v3 = r0 - 0x20u; Z = (_v3==0); N = ((_v3>>31)&1); C = (r0 >= 0x20u); V = (((r0 ^ 0x20u) & (r0 ^ _v3) & 0x80000000u)!=0); L4: if (!Z) { uint32_t _v4 = r0 - 0x4du; Z = (_v4==0); N = ((_v4>>31)&1); C = (r0 >= 0x4du); V = (((r0 ^ 0x4du) & (r0 ^ _v4) & 0x80000000u)!=0); } L5: if (Z) { r0 = 0x1u; } L6: if (!Z) { r0 = 0x0u; } L7: return r0; }

/* [037] overlay_082 0x021567B8 size=28 sha256=0847310c83c7acf0e7c38c0e841ed540b77f8593525082699177169bda33a2a4 BL=1 */
void st_ov082_021567B8(uint32_t obj, uint32_t src) {
    register uint32_t dst asm("r3")=*(volatile uint32_t*)(obj+608);
    asm volatile("" : "+r"(dst));
    register uint32_t a asm("r0") = ((uint32_t*)src)[0];
    register uint32_t b asm("r2") = ((uint32_t*)src)[1];
    asm volatile("" : "+r"(a),"+r"(b));
    *(volatile uint32_t*)(dst+148)=a;
    a=*(volatile uint32_t*)(src+8);
    asm volatile("" : "+r"(a));
    *(volatile uint32_t*)(dst+152)=b;
    *(volatile uint32_t*)(dst+156)=a;
}


/* [038] overlay_090 0x02170E18 size=48 sha256=fd25e5cc27ae7a349f0637a13f6234b76480d2b5983213b51684b7eb21a89cea BL=3 */
uint32_t st_ov090_02170E18(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r1 = (uint32_t)*(volatile uint16_t*)(uintptr_t)(r0+108); L1: r2 = 0x1u; L2: ; uint32_t _v2 = r1 - 0x1u; Z = (_v2==0); N = ((_v2>>31)&1); C = (r1 >= 0x1u); V = (((r1 ^ 0x1u) & (r1 ^ _v2) & 0x80000000u)!=0); L3: if (Z) goto L10; L4: ; uint32_t _v4 = r1 - 0x2u; Z = (_v4==0); N = ((_v4>>31)&1); C = (r1 >= 0x2u); V = (((r1 ^ 0x2u) & (r1 ^ _v4) & 0x80000000u)!=0); L5: if (!Z) goto L9; L6: r0 = (uint32_t)*(volatile int16_t*)(uintptr_t)(r0+72); L7: ; uint32_t _v7 = r0 - 0x1u; Z = (_v7==0); N = ((_v7>>31)&1); C = (r0 >= 0x1u); V = (((r0 ^ 0x1u) & (r0 ^ _v7) & 0x80000000u)!=0); L8: if (Z||(N!=V)) goto L10; L9: r2 = 0x0u; L10: r0 = r2; L11: return r0; }

/* [039] overlay_092 0x0217A7E4 size=32 sha256=50ad54732b8ffcdaad632d6dcf6c95495f444b04f8e8fc92518f2ce11122c8ea BL=1 */
uint32_t st_ov092_0217A7E4(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) { unsigned Z=0,N=0,C=0,V=0; L0: r2 = *(volatile uint32_t*)(uintptr_t)(r0+0); L1: *(volatile uint32_t*)(uintptr_t)(r0+0u) = r1; *(volatile uint32_t*)(uintptr_t)(r0+4u) = r2; L2: ; uint32_t _v2 = r1 - r2; Z = (_v2==0); N = ((_v2>>31)&1); C = (r1 >= r2); V = (((r1 ^ r2) & (r1 ^ _v2) & 0x80000000u)!=0); L3: if (Z) { r1 = *(volatile uint32_t*)(uintptr_t)(r0+8); } L4: if (Z) { r1 = (r1 + 0x1u); } L5: if (!Z) { r1 = 0x0u; } L6: *(volatile uint32_t*)(uintptr_t)(r0+8) = (uint32_t)r1; L7: return r0; }

/* [040] overlay_093 0x021686D4 size=36 sha256=6c5a5d70b8a040dd49aba492d8fc5921fbc623c45771933bc4392d2fd5b6f2cb BL=1 */
void st_ov093_021686D4(uint32_t p){register uint32_t ptr asm("r1")=0x0217890cu;register uint32_t sz asm("r2")=8;asm volatile("" : "+r"(ptr),"+r"(sz));int32_t a=*(volatile int16_t*)(ptr+8);asm volatile("" : "+r"(a));*(volatile uint16_t*)(p)=a;int32_t b=*(volatile int16_t*)(ptr+10);asm volatile("" : "+r"(b));*(volatile uint16_t*)(p+2)=b;*(volatile uint32_t*)(p+4)=sz;}


/* Named leaf routines, semantically reconstructed from original ARM instructions.
   Clang instruction equivalence is measured below, not assumed. */
/* [041] arm9 0x02028390 size=8 sha256=060682c80d3a37098de575f51eabcbe853bedcd07c00051f839c558df4b37d67 */
uint32_t st_arm9_02028390(uint32_t x) { __builtin_assume(x != 0); return __builtin_clz(x); }
/* [042] overlay_000 0x0205B1CC size=12 sha256=7e15c0fa7a7662f1b51ea6aa1aaca160ab766bf5401298ca840d3cc6b28f5c36 */
void st_ov000_0205B1CC(uint32_t *dst, uint32_t first, uint32_t second) {
    dst[0] = first;
    dst[1] = first;
    dst[2] = second;
}
/* [043] overlay_023 0x020EF9A4 size=12 sha256=a95fb179d42f835b33c255b0a333526fb0a2c8d5db2caefba50dad3d81e633c3 */
void st_ov023_020EF9A4(uint32_t *dst,uint32_t a,uint32_t b,uint32_t c){dst[1]=a;dst[2]=b;asm volatile("" ::: "memory");dst[3]=c;}
/* [044] overlay_032 0x0211DA50 size=16 sha256=16f093abc76889994f68f477d47f7a59ae121a35ba597d643c9e0be2927270da */
void st_ov032_0211DA50(uint32_t *dst) {
    register uint32_t a asm("r2") = *(volatile uint32_t *)(dst + 1);
    register uint32_t b asm("r1") = *(volatile uint32_t *)(dst + 2);
    asm volatile("" : "+r"(a), "+r"(b));
    dst[1] = b;
    dst[2] = a;
}
/* [045] overlay_000 0x02072FF0 size=20 sha256=2380258467c76cb9787820ab2c0374d89847e531dda76a3ad5e85c7eff45c6ee */
uint32_t st_ov000_02072FF0(volatile uint8_t *base, uint32_t index, uint32_t value) {
    *(volatile uint16_t *)(base + index * 2u) = (uint16_t)value;
    base[16] = 1u;
    return (uint32_t)(uintptr_t)base;
}
/* [046] overlay_000 0x020816C4 size=20 sha256=4981b1105a00122cc830957cdfbf6926c8043cc2821a2da0485355d408ff54f0 */
uint32_t st_ov000_020816C4(volatile uint8_t *obj, uint32_t bit) {
    uint32_t mask = *(volatile uint32_t *)(obj + 172);
    return (bit < 32u && (mask & (1u << bit)) != 0u) ? 1u : 0u;
}
/* [047] overlay_000 0x020816FC size=20 sha256=02f6c1bbe381fbcdee32486833c1e8361de06d669007eab20d58f202fe1d6e0f */
uint32_t st_ov000_020816FC(volatile uint8_t *obj, uint32_t bit) {
    uint32_t mask = *(volatile uint32_t *)(obj + 176);
    return (bit < 32u && (mask & (1u << bit)) != 0u) ? 1u : 0u;
}
/* [048] overlay_000 0x0207749C size=24 sha256=153176730b5a275bd359d0b337e1f09336eba7650390b1ad1087666142355fe2 */
uint32_t st_ov000_0207749C(const volatile uint8_t *obj, uint32_t index, uint32_t alternate) {
    if (index == UINT32_MAX) {
        return *(const volatile uint32_t *)(obj + alternate * 4u + 12u);
    }
    return *(const volatile uint32_t *)(obj + index * 4u + 20u);
}
/* [049] arm9 0x02028C4C size=20 sha256=3cfd563af82d5813c8180f4b189a1e34d77a9c562334d174657e0d116c7d988e */
uint32_t st_arm9_02028C4C(uint32_t value, volatile uint32_t *dest, uint32_t bytes) {
    uintptr_t end = (uintptr_t)dest + bytes;
    while ((intptr_t)(uintptr_t)dest < (intptr_t)end) {
        *dest++ = value;
    }
    return value;
}
/* [050] arm9 0x02028C60 size=24 sha256=11b33393cb66eec6392d208c96cdea91fc66ad9d1ea9b3ad8d32a727d66489b8 */
volatile uint32_t *st_arm9_02028C60(volatile uint32_t *source, volatile uint32_t *dest, uint32_t bytes) {
    uintptr_t end = (uintptr_t)dest + bytes;
    while ((intptr_t)(uintptr_t)dest < (intptr_t)end) {
        *dest++ = *source++;
    }
    return source;
}
