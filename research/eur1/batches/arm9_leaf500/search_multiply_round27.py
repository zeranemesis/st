#!/usr/bin/env python3
"""Round27: arithmetic expression shape and multiply-accumulate ARM matching.

Test semantically equivalent C changes around rX=(rA*rB+rC) and rX=rA*rB,
including combined/split multiply-add with an empty compiler-only barrier
on the intermediate product, operand order, plus optional volatile memory
accesses and tentative ABI return/no-return. No original ROM bytes needed.

Strict matches require the full original function SHA256 and byte count.
Literal-prefix matches require an exact original ARM instruction SHA256
and one extra 4-byte Clang literal referenced by a decoded PC-relative LDR.
"""
from __future__ import annotations
import hashlib, json, re, subprocess, tempfile, argparse
from pathlib import Path
from verify_fifth500 import FLAGS, elf32_sections
from audit_literal_pools_round20 import arm_pc_literal_references
from search_barriers_round23 import symbol

HERE=Path(__file__).resolve().parent
PATTERN=re.compile(r"^uint32_t (st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$",re.M)
CLEAN="unsigned Z=0,N=0,C=0,V=0;"
TERMINAL=re.compile(r"\s*return r0;\s*}\s*$")
MUL=re.compile(r"\b(r(?:0|1|2|3|12))\s*=\s*\((r(?:0|1|2|3|12))\s*\*\s*(r(?:0|1|2|3|12))\s*(?:\+\s*(r(?:0|1|2|3|12)))?\);")
VOL=re.compile(r"\*\(\((u?int(?:8|16|32)_t)\s*\*\)")

def candidates(body: str, name: str):
    if not TERMINAL.search(body) or "if (" in body or "{" in body or "}" in body[:-1]:
        return []
    source=TERMINAL.sub("",body).strip()
    patterns=list(MUL.finditer(source))
    if not patterns: return []
    # Branch-proven memory semantics are left unchanged except qualifiers.
    original=patterns[0]
    dst,a,b,add=original.groups()
    exprs=[]
    orig=original[0]
    if add:
        exprs += [
            ("swapped",f"{dst} = ({b} * {a} + {add});"),
            ("addfirst",f"{dst} = ({add} + {a} * {b});"),
            ("parenthesized",f"{dst} = (({a} * {b}) + {add});"),
            ("split",f"{dst} = ({a} * {b}); {dst} += {add};"),
            ("split_swap",f"{dst} = ({b} * {a}); {dst} += {add};"),
            ("split_barrier",f"{dst} = ({a} * {b}); __asm__ __volatile__(\"\" : \"+r\"({dst})); {dst} += {add};"),
            ("split_barrier_swap",f"{dst} = ({b} * {a}); __asm__ __volatile__(\"\" : \"+r\"({dst})); {dst} += {add};"),
            ("forced_operand",f'__asm__ __volatile__("" : "+r"({a})); {dst} = ({a} * {b} + {add});'),
            ("forced_second",f'__asm__ __volatile__("" : "+r"({b})); {dst} = ({a} * {b} + {add});'),
            ("forced_addend",f'__asm__ __volatile__("" : "+r"({add})); {dst} = ({a} * {b} + {add});'),
        ]
    else:
        exprs += [
            ("swapped",f"{dst} = ({b} * {a});"),
            ("forced_a",f'__asm__ __volatile__("" : "+r"({a})); {dst} = ({a} * {b});'),
            ("forced_b",f'__asm__ __volatile__("" : "+r"({b})); {dst} = ({a} * {b});'),
            ("forced_product",f'{dst} = ({a} * {b}); __asm__ __volatile__("" : "+r"({dst}));'),
        ]
    # Literal-stride arithmetic decomposition (e.g. 20*i=16*i+4*i)
    aliases={}
    for reg,hexval in re.findall(r"\b(r(?:0|1|2|3|12))\s*=\s*\((0x[0-9a-f]+u)\);",source):
        aliases[reg]=int(hexval[:-1],16)
    for mult,multreg in [(a,b),(b,a)]:
        if mult not in aliases:continue
        k=aliases[mult]
        decomps={
            6:f"(({multreg} << 2) + ({multreg} << 1))",
            10:f"(({multreg} << 3) + ({multreg} << 1))",
            12:f"(({multreg} << 3) + ({multreg} << 2))",
            20:f"(({multreg} << 4) + ({multreg} << 2))",
            24:f"(({multreg} << 4) + ({multreg} << 3))",
            28:f"(({multreg} << 5) - ({multreg} << 2))",
            36:f"(({multreg} << 5) + ({multreg} << 2))",
            44:f"(({multreg} << 5) + ({multreg} << 3) + ({multreg} << 2))",
            56:f"(({multreg} << 6) - ({multreg} << 3))",
            60:f"(({multreg} << 6) - ({multreg} << 2))",
            96:f"(({multreg} << 6) + ({multreg} << 5))",
        }
        if k in decomps:
            result=decomps[k]
            rhs=f"{result} + {add}" if add else result
            exprs.append(("shift_decomposed",f"{dst} = ({rhs});"))
    seen=set();out=[]
    for kind,replacement in exprs:
        if replacement==orig:continue
        substituted=source[:original.start()]+replacement+source[original.end():]
        for vol in (False,True):
            c=VOL.sub(r"*((volatile \1*)",substituted) if vol else substituted
            for returned in (True,False):
                typename="uint32_t" if returned else "void"
                tail="\nreturn r0;" if returned else ""
                code=f"{typename} {name}(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) {{\nuint32_t r12=0;\n"+c+tail+"\n}\n"
                if code in seen: continue
                seen.add(code);out.append((kind,vol,returned,code))
    return out

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--clang",default="clang")
    parser.add_argument("--out",type=Path,default=Path("build/eur1/round27_multiply_expression.json"))
    args=parser.parse_args()
    m=json.loads((HERE/"manifest_fifth500.json").read_text(encoding="utf-8"))
    outstanding={symbol(x):x for x in m["functions"]
                 if x["clang_standalone_status"]!="exact_original_machine_bytes"
                 and not x.get("clang_instruction_prefix_status")}
    srcs=[];registry={};scanned=set()
    for part in range(1,6):
        code=(HERE/f"arm9_leaf_500_part{part}.c").read_text(encoding="utf-8")
        for match in PATTERN.finditer(code):
            name=match[1]
            if name not in outstanding or CLEAN not in match[0]:continue
            body=match[0].split(CLEAN,1)[1]
            for index,(kind,vol,returned,source) in enumerate(candidates(body,name)):
                emitted=f"{name}_round27_v{index}"
                src=source.replace(name+"(",emitted+"(",1)
                registry[emitted]=(outstanding[name],kind,vol,returned,src)
                srcs.append(src);scanned.add(name)
    if len(srcs)<100 or len(scanned)<10:
        raise ValueError(f"Too few multiplication candidates: {len(srcs)}/{len(scanned)}")
    compiled={}
    with tempfile.TemporaryDirectory(prefix="st_eur1_mul27_") as tmp:
        for start in range(0,len(srcs),1300):
            end=min(start+1300,len(srcs))
            src=Path(tmp)/f"c{start}.c";obj=Path(tmp)/f"c{start}.o"
            src.write_text("#include <stdint.h>\n"+"\n".join(srcs[start:end]),encoding="utf-8")
            result=subprocess.run([args.clang,*FLAGS,"-c",str(src),"-o",str(obj)],
                                  capture_output=True,text=True,timeout=150)
            if result.returncode:
                raise RuntimeError(f"Clang error at batch {start}-{end}: "+result.stderr[-4500:])
            sections=elf32_sections(obj.read_bytes())
            if compiled.keys()&sections.keys():raise ValueError("Duplicate ARM sections")
            compiled.update(sections)
    if len(compiled)!=len(registry):
        raise ValueError(f"Expected {len(registry)} function sections, got {len(compiled)}")
    found={};levels={"strict":0,"literal":0}
    for name,(ref,kind,vol,returned,source) in registry.items():
        data=compiled[".text."+name];size=ref["size_bytes"];sha=ref["original_span_sha256"]
        if len(data)==size and hashlib.sha256(data).hexdigest()==sha:level="strict"
        elif len(data)==size+4 and hashlib.sha256(data[:size]).hexdigest()==sha and any(
           x["literal_target_offset"]==size for x in arm_pc_literal_references(data,size)):level="literal"
        else:continue
        levels[level]+=1
        orig=name.rsplit("_round27_v",1)[0]
        item={"name":orig,"address":ref["address"],"module":ref["module"],"size":size,
              "level":level,"variant":kind,"volatile":vol,"return_r0":returned,
              "source":source.replace(name+"(",orig+"(",1),"original_sha256":sha}
        if orig not in found or (level=="strict" and found[orig]["level"]!="strict"):found[orig]=item
    rows=sorted(found.values(),key=lambda x:x["name"])
    report={"compiled_variants":len(registry),"functions_scanned":len(scanned),
            "baseline_total":m["summary"]["standalone_clang_exact_original_instruction_spans_total"],
            "matching_variants":levels,"new_matches":len(rows),
            "strict_new":sum(x["level"]=="strict" for x in rows),
            "literal_new":sum(x["level"]=="literal" for x in rows),"matches":rows}
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(report,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {len(srcs)} ARM Clang arithmetic C variants from {len(scanned)} unmatched original functions")
    print(f"NEW_EXACT: {len(rows)} (strict={report['strict_new']}, literal={report['literal_new']})")
    for x in rows:print(f"NEW_MATCH: {x['name']} {x['level']} {x['size']}B form={x['variant']} volatile={x['volatile']} return={x['return_r0']}")

if __name__=="__main__":main()
