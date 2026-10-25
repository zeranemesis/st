#!/usr/bin/env python3
"""Clang ARMv5TE matching attempts on high-BL-reference, same-size EUR1 functions.

Candidate bodies are explicit, auditable C reverse-engineering reconstructions
from previous ARM register-state transcriptions. Every candidate is compared
against the COMPLETE original SHA256 code fingerprint at the function address.
The generated C versions have provisional semantics and signatures; only an
actual SHA match can be promoted. Nintendo CodeWarrior is not used.
"""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import tempfile
from verify_fifth500 import FLAGS, elf32_sections

HERE = Path(__file__).resolve().parent

# Body strings represent r0=object/address, r1/r2/r3=remaining original
# ARM input registers. The type helper macros are substituted as variants.
RECOVERED = {
"st_ov026_020FA8E0": [
"uint32_t flags = RD8(r0,468); return (flags & 8u) ? (flags & 1u) : ((flags >> 1) & 1u);",
"uint32_t flags = RD8(r0,468); return (flags >> ((flags & 8u) ? 0u : 1u)) & 1u;",
"uint32_t flags = RD8(r0,468); return (flags & 8u) != 0u ? ((flags & 1u)!=0u) : ((flags & 2u)!=0u);",
],
"st_arm9_0201E8D4": [
"uint32_t a = RD32(r1,20), b = RD32(r1,16); WR16(r0,0,(int32_t)(b+0x800u)>>12); WR16(r0,2,(int32_t)(a+0x800u)>>12); return r0;",
"WR16(r0,0,((int32_t)(RD32(r1,16)+0x800u)>>12)); WR16(r0,2,((int32_t)(RD32(r1,20)+0x800u)>>12)); return r0;",
],
"st_ov000_0208A7F0": [
"uint32_t begin=RD32(r1,8), end=RD32(r1,12); WR32(r0,0, ((int32_t)(end-begin)/4 != 0) ? RD32(begin,0):0u); return r0;",
"uint32_t begin=RD32(r1,8), end=RD32(r1,12); WR32(r0,0, begin!=end ? RD32(begin,0):0u); return r0;",
],
"st_ov000_0206678C": [
"uint32_t p=RD32(r0,0); uint32_t tag=RD16(p,0); WR32(r0,0,tag==26u ? p+RD8(p,2):p+2u); return r0;",
"uint32_t p=RD32(r0,0); WR32(r0,0,(RD16(p,0)==26u) ? p+RD8(p,2):p+2u); return r0;",
],
"st_ov020_020C9430": [
"uint32_t entry=r0+72u*r1; return RD8(entry,68)!=0u?entry:0u;",
"uint32_t entry=r0+72u*r1; if(RD8(entry,68)==0u) return 0u; return entry;",
],
"st_ov092_0217A278": [
"return (RD32(r0,36)+2u)&3u;",
"uint32_t index=RD32(r0,36); return (index+2u)%4u;",
],
"st_ov000_020669B4": [
"uint32_t v=RD16(r0,6); if(v<=255u) { WR8(r1,0,v); return 1u; } return 0u;",
"uint32_t v=RD16(r0,6); uint32_t ok=(v<=255u); if(ok) WR8(r1,0,v); return ok;",
],
"st_ov031_020D8840": [
"uint32_t count=RD32(r0,468); WR32(r0,468,count+1u); WR32(r0+count*4u,448,r1); return r0+count*4u;",
"uint32_t count=RD32(r0,468); WR32(r0,468,count+1u); uint32_t entry=r0+448u+count*4u; WR32(entry,0,r1); return r0+count*4u;",
],
"st_ov071_021530DC": [
"int32_t delta=(int16_t)(r1-(int16_t)RD16(r0,40)); uint32_t magnitude=delta<0?(uint32_t)-delta:(uint32_t)delta; return magnitude<0x4000u;",
"int32_t delta=(int16_t)(r1-(int16_t)RD16(r0,40)); return (delta<0?-delta:delta)<0x4000;",
],
"st_arm9_0202CF08": [
"WR32(r0,0,0); WR32(r0,4,0); WR32(r0,28,0); WR32(r0,24,0); WR32(r0,8,0); WR32(r0,16,14); WR32(r0,12,0); return r0;",
"WR32(r0,0,0); WR32(r0,4,0); WR32(r0,28,0); WR32(r0,24,0); WR32(r0,8,0); WR32(r0,16,14); WR32(r0,12,0); return r0;",
],
"st_ov026_0210C158": [
"return (r0-16u)<=2u;",
"return r0>=16u && r0<=18u;",
"return r0==16u || r0==17u || r0==18u;",
],
"st_ov043_02126358": [
"uint32_t v=RD16(r0,108); return (v==2u || v==3u);",
"uint32_t v=RD16(r0,108); return (v-2u)<=1u;",
],
"st_ov093_0216E420": [
"uint32_t p=RD32(r0,192); return p!=0u ? RD32(RD32(p,0),0):0u;",
"uint32_t p=RD32(r0,192); if(!p) return 0u; p=RD32(p,0); return RD32(p,0);",
],
}


def compile_src(body: str, name: str, version: int) -> str:
    qualifier = "volatile " if version % 2 else ""
    macro = (
        f"#define RD32(p,n) (*(const {qualifier}uint32_t *)(uintptr_t)((p)+(n)))\n"
        f"#define RD16(p,n) (*(const {qualifier}uint16_t *)(uintptr_t)((p)+(n)))\n"
        f"#define RD8(p,n) (*(const {qualifier}uint8_t *)(uintptr_t)((p)+(n)))\n"
        f"#define WR32(p,n,x) (*( {qualifier}uint32_t *)(uintptr_t)((p)+(n))=(uint32_t)(x))\n"
        f"#define WR16(p,n,x) (*( {qualifier}uint16_t *)(uintptr_t)((p)+(n))=(uint16_t)(x))\n"
        f"#define WR8(p,n,x) (*( {qualifier}uint8_t *)(uintptr_t)((p)+(n))=(uint8_t)(x))\n"
    )
    # Macros are isolated by compilation per qualifier, so macros in generated
    # sections do not collide (Clang compiles one source per qualifier).
    return macro


def main() -> None:
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--clang", default="clang")
    p.add_argument("--out",type=Path,default=Path("build/eur1/round19_high_bl.json"))
    args=p.parse_args()
    manifest=json.loads((HERE/"manifest_fifth500.json").read_text(encoding="utf-8"))
    by_addr={(str(f["module"]), int(f["address"],16)):f for f in manifest["functions"]}
    records={}
    for name,bodylist in RECOVERED.items():
        section, addr=name.rsplit("_",1)
        raw_module=section.split("_",1)[1]
        module="arm9" if raw_module=="arm9" else str(int(raw_module.removeprefix("ov")))
        ref=by_addr.get((module,int(addr,16)))
        if ref is None or ref["clang_standalone_status"]=="exact_original_machine_bytes":
            raise ValueError(f"Candidate already matched or missing: {name}")
        records[name]=ref
    exact={}
    tested=0
    with tempfile.TemporaryDirectory(prefix="st_round19_high_bl_") as tmp:
        for qualifier in range(2):
            header=compile_src("", "",qualifier)
            variants=[]
            expected={}
            for name,bodies in RECOVERED.items():
                for i,body in enumerate(bodies):
                    key=f"{name}_v{qualifier*10+i}"
                    expected[key]=(records[name],body,qualifier*10+i)
                    variants.append(
                        f"uint32_t {key}(uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3)"
                        "{\n"+body+"\n}\n"
                    )
            source=Path(tmp)/f"q{qualifier}.c"
            obj=Path(tmp)/f"q{qualifier}.o"
            source.write_text("#include <stdint.h>\n"+header+"\n".join(variants),encoding="utf-8")
            proc=subprocess.run([args.clang,*FLAGS,"-c",str(source),"-o",str(obj)],
                                text=True,capture_output=True,timeout=120)
            if proc.returncode:
                raise RuntimeError("Clang ARM compile failed: "+proc.stderr[-4500:])
            compiled=elf32_sections(obj.read_bytes())
            if len(compiled)!=len(expected):
                raise ValueError(f"Missing compiled section {len(compiled)} / {len(expected)}")
            for key,(ref,body,v) in expected.items():
                code=compiled[".text."+key]
                tested+=1
                if (len(code)!=ref["size_bytes"] or
                    hashlib.sha256(code).hexdigest()!=ref["original_span_sha256"]):
                    continue
                name=key.rsplit("_v",1)[0]
                if name not in exact or v<exact[name]["variant"]:
                    exact[name]={
                        "name":name,"module":ref["module"],"address":ref["address"],
                        "size":ref["size_bytes"],"variant":v,
                        "body":body,"qualifier":"volatile" if qualifier else "regular",
                        "sha256":ref["original_span_sha256"]
                    }
    matches=sorted(exact.values(),key=lambda x:x["name"])
    output={
        "scope":"13 prioritized same-size, high-BL functions with human-auditable C",
        "original_functions":len(RECOVERED),
        "compiled_variants":tested,
        "new_exact_matches":len(matches),
        "matches":matches,
        "limitations":"Clang ARM standalone fingerprint only; no CodeWarrior or DS rebuild",
    }
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(output,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {tested} manually reconstructed C variants, {len(RECOVERED)} original candidates")
    print("EXACT_NEW:",len(matches))
    for row in matches:
        print("EXACT:",row["name"],row["size"],"bytes")
    print("Report:",args.out)


if __name__=="__main__":
    main()
