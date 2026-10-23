#!/usr/bin/env python3
"""Recompile 100 ARM9 C candidates and compare to YOUR local Spirit Tracks EUR1 code.

Standalone Clang -O2 code-section matching, NOT an original CodeWarrior or
normal Nintendo DS C++ game build comparison. No ROM or game assets included.
"""
from __future__ import annotations
import argparse,collections,hashlib,json,struct,subprocess,sys,tempfile
from pathlib import Path

HERE=Path(__file__).resolve().parent
CFILE=HERE/'reconstructed_100_new.c'
MANIFEST=HERE/'manifest_100_new.json'
FLAGS=['--target=armv5te-none-eabi','-march=armv5te','-marm','-O2','-ffreestanding','-fomit-frame-pointer','-ffunction-sections','-w']


def elf_text(blob:bytes):
    if blob[:6]!=b'\x7fELF\x01\x01':raise ValueError('Expected 32-bit little-endian ARM ELF')
    h=struct.unpack_from('<16sHHIIIIIHHHHHH',blob,0)
    if h[1]!=1 or h[2]!=40 or h[11]!=40:raise ValueError('Not an ELF32 ARM relocatable object')
    pos=h[6];cnt=h[12];stridx=h[13]
    if pos+cnt*40>len(blob) or stridx>=cnt:raise ValueError('Broken section table')
    sh=[struct.unpack_from('<10I',blob,pos+40*i) for i in range(cnt)]
    strings=blob[sh[stridx][4]:sh[stridx][4]+sh[stridx][5]]
    names=[]
    for q in sh:
        st=q[0]
        if st>=len(strings):raise ValueError('Out-of-range section name')
        end=strings.find(b'\x00',st)
        if end<0:raise ValueError('Unterminated section name')
        names.append(strings[st:end].decode('ascii','replace'))
    sections={}
    for i,(q,name) in enumerate(zip(sh,names)):
        if q[1]==1 and name.startswith('.text.st_'):
            off,n=q[4],q[5]
            if off+n>len(blob):raise ValueError('Section beyond file')
            sections[name[6:]]=blob[off:off+n]
    # Relocation records against code sections invalidate raw-byte matching.
    for q in sh:
        if q[1] in (4,9) and q[5] and q[7]<cnt and names[q[7]].startswith('.text.st_'):
            raise ValueError(f'Unapplied relocation inside {names[q[7]]}')
    return sections


def verify(code_dir:Path,clang:str):
    doc=json.loads(MANIFEST.read_text(encoding='utf-8'))
    records=doc['functions']
    if len(records)!=100 or len({(x['overlay'],x['address']) for x in records})!=100:
        raise ValueError('Manifest must have 100 unique (module, address) pairs')
    # Authenticate the *local user-owned* executable images before using them.
    cache={}
    modules={x['overlay'] for x in records}
    for module in modules:
        if module<0:
            path=code_dir/'arm9.bin';digest=doc['arm9_sha1']
        else:
            path=code_dir/f'overlay_{module:03}.bin';digest=doc['overlay_sha1'][str(module)]
        data=path.read_bytes()
        if hashlib.sha1(data).hexdigest()!=digest:
            raise ValueError(f'Wrong EUR1 code image at {path}')
        cache[module]=data
    with tempfile.TemporaryDirectory(prefix='st_100new_') as t:
        out=Path(t)/'test.o'
        proc=subprocess.run([clang,*FLAGS,'-c',str(CFILE),'-o',str(out)],capture_output=True,text=True)
        if proc.returncode:raise RuntimeError('Clang ARM compile failed:\n'+proc.stderr[-6000:])
        sections=elf_text(out.read_bytes())
    if len(sections)!=100:raise ValueError(f'Found {len(sections)} code sections, expected 100')
    exact=0;original_bytes=0;results=[]
    for r in records:
        m=r['overlay'];addr=int(r['address'],16)
        sym=f'st_arm9_{addr:08X}' if m<0 else f'st_ov{m:03}_{addr:08X}'
        base=int(doc['arm9_base'],16) if m<0 else int(doc['overlay_ram_base'][str(m)],16)
        start=addr-base;end=start+r['size_bytes']
        orig=cache[m][start:end] if start>=0 else b''
        if len(orig)!=r['size_bytes'] or hashlib.sha256(orig).hexdigest()!=r['original_span_sha256']:
            raise ValueError(f'Original EUR1 reference mismatch: {sym}')
        new=sections.get(sym)
        if new is None:raise ValueError(f'Missing {sym}')
        match=orig==new
        if match!=r['clang_armv5te_exact']:
            raise ValueError(f'Status drift {sym}: expected={r["clang_armv5te_exact"]}, got={match}')
        exact+=match;original_bytes+=len(orig)
        results.append({'symbol':sym,'address':r['address'],'original_bytes':len(orig),'generated_bytes':len(new),'exact':match})
    expect=doc['summary']
    if exact!=expect['clang_byte_exact'] or original_bytes!=expect['original_code_bytes']:
        raise ValueError(f'Unexpected count/byte totals exact={exact}; bytes={original_bytes}')
    return {'total':100,'clang_exact':exact,'clang_nonmatching':100-exact,'original_code_bytes':original_bytes,'results':results}


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--working-code',required=True,type=Path,help='Directory with ARM9.bin and decoded overlay_XXX.bin from your EUR1 ROM')
    p.add_argument('--clang',default='clang')
    p.add_argument('--out',type=Path,default=HERE/'local_verify_results.json')
    a=p.parse_args()
    try: result=verify(a.working_code,a.clang)
    except (OSError,ValueError,RuntimeError) as e:
        print('FAIL:',e,file=sys.stderr);return 1
    a.out.parent.mkdir(parents=True,exist_ok=True)
    a.out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(f'PASS 100/100 originals authenticated; {result["clang_exact"]}/100 Clang ARM exact; {result["original_code_bytes"]} original instruction bytes')
    print('50 provisional nonmatching C bodies remain research, NOT Nintendo CodeWarrior matching')
    print('Report:',a.out)
    return 0

if __name__=='__main__':raise SystemExit(main())
