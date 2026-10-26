#!/usr/bin/env python3
"""Round28: simplify a final ARM CMP/TST dual-guard constant selection to C.

Read-only variant search. Only handles a safely recognized final two-guard
selection with complementary ARM flag predicates and constants. Preserves
all preceding memory operations; varies return style, qualifiers and
zero-byte compiler barriers while checking complete original SHA256 spans.
"""
from __future__ import annotations
import argparse, hashlib, json, re, subprocess, tempfile
from pathlib import Path
from verify_fifth500 import FLAGS, elf32_sections
from audit_literal_pools_round20 import arm_pc_literal_references
from search_barriers_round23 import symbol

HERE=Path(__file__).resolve().parent
PATTERN=re.compile(r"^uint32_t (st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$",re.M)
SEP="unsigned Z=0,N=0,C=0,V=0;"
CMP=re.compile(r"\{\s*uint64_t z = \(uint64_t\)(r\d+) - \(uint64_t\)\((r\d+|0x[0-9a-f]+u)\);[^{}]*\}\s*$")
BIT=re.compile(r"\{\s*uint32_t z = (.*?); Z = \(z==0\); N = \(z>>31\); \}\s*$")
TAIL=re.compile(r"\s*if \((?P<a>[^{}]*?)\)\s*\{\s*r0\s*=\s*\((?P<v1>0x[0-9a-f]+u)\);\s*\}\s*if \((?P<b>[^{}]*?)\)\s*\{\s*r0\s*=\s*\((?P<v2>0x[0-9a-f]+u)\);\s*\}\s*return r0;\s*}\s*$")
VOL=re.compile(r"\*\(\((u?int(?:8|16|32)_t)\s*\*\)")
REGISTER=re.compile(r"\b(r[0123])\s*=\s*[^;{}]+;")

def normalize(t):
    t=re.sub(r"\s+","",t)
    while t.startswith("(") and t.endswith(")"):
        t=t[1:-1]
    return t

OPPOSITES={
    "Z":"!Z","!Z":"Z",
    "C":"!C","!C":"C",
    "N==V":"N!=V","N!=V":"N==V",
    "!C||Z":"C&&!Z","C&&!Z":"!C||Z",
    "!Z&&N==V":"Z||N!=V","Z||N!=V":"!Z&&N==V",
}
def cond(expr,lhs,rhs,is_bit):
    if is_bit:
        if expr=="Z":return f"(({lhs}) == 0u)"
        if expr=="!Z":return f"(({lhs}) != 0u)"
        return None
    forms={
        "Z":f"({lhs} == {rhs})",
        "!Z":f"({lhs} != {rhs})",
        "C":f"({lhs} >= {rhs})",
        "!C":f"({lhs} < {rhs})",
        "N==V":f"((int32_t){lhs} >= (int32_t){rhs})",
        "N!=V":f"((int32_t){lhs} < (int32_t){rhs})",
        "!C||Z":f"({lhs} <= {rhs})",
        "C&&!Z":f"({lhs} > {rhs})",
        "!Z&&N==V":f"((int32_t){lhs} > (int32_t){rhs})",
        "Z||N!=V":f"((int32_t){lhs} <= (int32_t){rhs})",
    }
    return forms.get(expr)

def source_variants(line,name):
    if SEP not in line:return []
    body=line.split(SEP,1)[1]
    tail=TAIL.search(body)
    if tail is None:return []
    c1,c2=normalize(tail["a"]),normalize(tail["b"])
    if OPPOSITES.get(c1)!=c2:return []
    before=body[:tail.start()].rstrip()
    cmp=CMP.search(before)
    bit=BIT.search(before)
    if cmp:
        lhs,rhs=cmp[1],cmp[2]
        prefix=before[:cmp.start()].strip()
        expression=cond(c1,lhs,rhs,False)
    elif bit:
        lhs=bit[1];rhs=""
        prefix=before[:bit.start()].strip()
        expression=cond(c1,lhs,rhs,True)
    else:return []
    if expression is None or "if (" in prefix or "{" in prefix or "}" in prefix:return []
    v1,v2=tail["v1"],tail["v2"]
    styles=[
        f"return ({expression}) ? {v1} : {v2};",
        f"r0 = ({expression}) ? {v1} : {v2}; return r0;",
        f"if ({expression}) r0 = {v1}; else r0 = {v2}; return r0;",
        f"return ({expression}) ? {v1} : {v2};",
        f"uint32_t out = ({expression}); return out ? {v1} : {v2};",
        f"uint32_t out = ({expression}); __asm__ __volatile__(\"\" : \"+r\"(out)); return out ? {v1} : {v2};",
    ]
    if v1=="0x1u" and v2=="0x0u":
        styles.extend([f"return ({expression});",f"return !!({expression});",f"return ((uint32_t)({expression}) & 1u);"])
    if v1=="0x0u" and v2=="0x1u":
        styles.extend([f"return !({expression});",f"return 1u - (uint32_t)({expression});"])
    output=[]
    regs=[m[1] for m in REGISTER.finditer(prefix)]
    barrier_reg=regs[-1] if regs else None
    for style_idx,style in enumerate(styles):
        for volatile in (False,True):
            bodyprefix=VOL.sub(r"*((volatile \1*)",prefix) if volatile else prefix
            for barrier in (False,True):
                if barrier and barrier_reg is None:continue
                extra=f' __asm__ __volatile__("" : "+r"({barrier_reg})); ' if barrier else ""
                s=f"uint32_t {name}(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) {{\nuint32_t r12=0;\n{bodyprefix}\n{extra}\n{style}\n}}\n"
                output.append((style_idx,volatile,barrier,s))
    return output

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--clang",default="clang")
    p.add_argument("--out",type=Path,default=Path("build/eur1/round28_conditionals.json"))
    args=p.parse_args()
    m=json.loads((HERE/"manifest_fifth500.json").read_text(encoding="utf-8"))
    pending={symbol(x):x for x in m["functions"] if x["clang_standalone_status"]!="exact_original_machine_bytes"
             and not x.get("clang_instruction_prefix_status")}
    records={};srcs=[];targets=set()
    for shard in range(1,6):
        text=(HERE/f"arm9_leaf_500_part{shard}.c").read_text(encoding="utf-8")
        for f in PATTERN.finditer(text):
            name=f[1]
            if name not in pending:continue
            for i,(style,volatile,barrier,code) in enumerate(source_variants(f[0],name)):
                sym=name+"_r28_v"+str(i)
                code=code.replace(name+"(",sym+"(",1)
                records[sym]=(pending[name],style,volatile,barrier,code)
                srcs.append(code)
                targets.add(name)
    if len(records)<100 or len(targets)<5:raise ValueError(f"Not enough recognized conditional results: {len(records)} from {len(targets)}")
    sections={}
    with tempfile.TemporaryDirectory(prefix="st_round28_") as tmp:
        for start in range(0,len(srcs),1100):
            end=min(len(srcs),start+1100)
            src=Path(tmp)/f"c{start}.c";obj=Path(tmp)/f"c{start}.o"
            src.write_text("#include <stdint.h>\n"+"\n".join(srcs[start:end]),encoding="utf-8")
            result=subprocess.run([args.clang,*FLAGS,"-c",str(src),"-o",str(obj)],
                                  capture_output=True,text=True,timeout=150)
            if result.returncode:raise RuntimeError("Clang failed: "+result.stderr[-4500:])
            binary=elf32_sections(obj.read_bytes())
            if sections.keys() & binary.keys():raise ValueError("Duplicate symbols")
            sections.update(binary)
    if len(sections)!=len(records):raise ValueError("Incomplete object sections")
    matches={};levels={"strict":0,"literal":0}
    for sym,(rec,style,vol,bar,source) in records.items():
        data=sections[".text."+sym];n=rec["size_bytes"];expected=rec["original_span_sha256"]
        if len(data)==n and hashlib.sha256(data).hexdigest()==expected:level="strict"
        elif len(data)==n+4 and hashlib.sha256(data[:n]).hexdigest()==expected and any(
                r["literal_target_offset"]==n for r in arm_pc_literal_references(data,n)):level="literal"
        else:continue
        levels[level]+=1
        original=sym.rsplit("_r28_v",1)[0]
        match={"name":original,"module":rec["module"],"address":rec["address"],
               "original_size":n,"level":level,"style":style,"volatile":vol,"barrier":bar,
               "source":source.replace(sym+"(",original+"(",1),"original_sha256":expected}
        if original not in matches or (level=="strict" and matches[original]["level"]!="strict"):matches[original]=match
    rows=sorted(matches.values(),key=lambda x:x["name"])
    report={"compiled_variants":len(records),"original_functions_scanned":len(targets),
            "baseline_opcode_exact":m["summary"]["standalone_clang_exact_original_instruction_spans_total"],
            "matching_variants":levels,"new_unique_matches":len(rows),
            "strict_new":sum(x["level"]=="strict" for x in rows),
            "literal_new":sum(x["level"]=="literal" for x in rows),"matches":rows}
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(report,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {len(records)} conditional ARM C variants from {len(targets)} original functions")
    print(f"NEW_EXACT: {len(rows)} (strict={report['strict_new']}, literal={report['literal_new']})")
    for x in rows:print(f"NEW_MATCH: {x['name']} {x['level']} {x['original_size']}B cond_style={x['style']}")
if __name__=="__main__":main()
