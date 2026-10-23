#!/usr/bin/env python3
"""Audit the sixth 100-function Spirit Tracks EUR1 research C batch.

This verifies original span provenance and actual standalone Clang code equality.
It does not certify semantic equivalence or original Nintendo CodeWarrior matching.
"""
from __future__ import annotations
import argparse, hashlib, json, shutil, struct, subprocess, tempfile
from collections import Counter
from pathlib import Path

HERE=Path(__file__).resolve().parent
MANIFEST=HERE/'manifest_new100.json'
FLAGS=['--target=armv5te-none-eabi','-march=armv5te','-marm','-O2','-w','-ffreestanding','-fomit-frame-pointer','-ffunction-sections']

def elf32_sections(blob:bytes)->dict[str,bytes]:
    if len(blob)<52 or blob[:6]!=b'\x7fELF\x01\x01':
        raise ValueError('Expected little-endian ELF32')
    fields=struct.unpack_from('<16sHHIIIIIHHHHHH',blob,0)
    _,typ,machine,_,_,_,off,_,_,_,_,shsize,n,shstr=fields
    if typ!=1 or machine!=40 or shsize!=40 or shstr>=n or off+n*40>len(blob):
        raise ValueError('Not a relocatable ARM ELF')
    items=[struct.unpack_from('<IIIIIIIIII',blob,off+i*40) for i in range(n)]
    st=items[shstr];names=blob[st[4]:st[4]+st[5]]
    result={}
    for item in items:
        a,t,_,_,fpos,ln,_,_,_,_=item
        if a>=len(names):continue
        z=names.find(b'\0',a)
        if z<0:continue
        name=names[a:z].decode('utf-8','replace')
        if fpos+ln>len(blob):raise ValueError(f'Bad section {name}')
        if t in (4,9) and name.startswith(('.rel.text.st_', '.rela.text.st_')) and ln:
            raise ValueError(f'Unexpected function relocation: {name}')
        if t==1 and name.startswith('.text.st_'):
            if name in result:raise ValueError(f'Duplicate code symbol {name}')
            result[name]=blob[fpos:fpos+ln]
    return result

def run(working_code:Path,clang:str)->Counter:
    m=json.loads(MANIFEST.read_text(encoding='utf-8'))
    fns=m['functions']
    if len(fns)!=100 or len({(x['module'],x['address']) for x in fns})!=100:
        raise ValueError('Expected exactly 100 distinct module/address functions')
    bins={}
    for mod,digest in m['original_module_sha1'].items():
        file=working_code/('arm9.bin' if mod=='arm9' else f'overlay_{int(mod):03d}.bin')
        if not file.is_file():raise FileNotFoundError(f'Missing original decompressed code {file}')
        content=file.read_bytes()
        if hashlib.sha1(content).hexdigest()!=digest:
            raise ValueError(f'SHA1 mismatch in {file}')
        bins[mod]=content
    with tempfile.TemporaryDirectory(prefix='st-sixth-100-') as tmp:
        sections={}
        for i in range(1,3):
            src=HERE/f'arm9_new100_part{i}.c'
            obj=Path(tmp)/f'part{i}.o'
            p=subprocess.run([clang,*FLAGS,'-c',str(src),'-o',str(obj)],capture_output=True,text=True)
            if p.returncode:raise RuntimeError(f'Compile {src.name} failed: {p.stderr[-5000:]}')
            cur=elf32_sections(obj.read_bytes())
            if cur.keys()&sections.keys():raise ValueError('Duplicate C symbols between source shards')
            sections.update(cur)
    counts=Counter()
    for x in fns:
        mod=x['module'];addr=int(x['address'],16);base=int(m['module_ram_base'][str(mod)],16)
        n=x['size_bytes'];original=bins[str(mod)][addr-base:addr-base+n]
        if addr<base or len(original)!=n or hashlib.sha256(original).hexdigest()!=x['original_span_sha256']:
            raise ValueError(f'Original bytes invalid at {mod} {x["address"]}')
        symbol=f'.text.st_{"arm9" if mod=="arm9" else f"ov{int(mod):03d}"}_{addr:08X}'
        actual=sections.get(symbol)
        if actual is None:raise ValueError(f'Missing compiled function {symbol}')
        exact=actual==original
        expected=x['clang_standalone_status']
        actual_state='exact_original_machine_bytes' if exact else ('different_size' if len(actual)!=n else 'different_instructions')
        if actual_state!=expected:raise ValueError(f'Recorded matching state changed: {symbol}: {expected} vs {actual_state}')
        counts['byte_exact' if exact else 'c_compiles_not_byte_exact']+=1
    if len(sections)!=100:raise ValueError(f'Expected 100 emitted functions, got {len(sections)}')
    return counts

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--working-code',required=True,type=Path)
    p.add_argument('--clang',default=shutil.which('clang'))
    a=p.parse_args()
    if not a.clang:p.error('clang not installed or not on PATH')
    try:
        results=run(a.working_code,a.clang)
        print('PASS: 100/100 C bodies compile; 100/100 original SHA256 spans match')
        print('Exact Clang ARMv5TE instruction matches:',results['byte_exact'],'/100')
        print('Compiles but emitted instructions differ:',results['c_compiles_not_byte_exact'],'/100')
        print('CAUTION:',results['c_compiles_not_byte_exact'],'nonmatching functions still require semantic/CFG review; no CodeWarrior or DS integration is claimed')
    except (OSError,ValueError,RuntimeError) as e:
        p.exit(1,'FAIL: '+str(e)+'\n')
