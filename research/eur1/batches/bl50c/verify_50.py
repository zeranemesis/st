#!/usr/bin/env python3
"""Verify fifty EUR1 Spirit Tracks ARM9 C research functions against owner's local decoded ROM.

Standalone Clang ARMv5TE byte equality only; not Nintendo CodeWarrior/objdiff.
Never uploads or distributes original ROM/overlay contents.
"""
import argparse
import collections
import csv
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import tempfile

HERE = Path(__file__).resolve().parent
ARM9_SHA1 = '650ea160271b2297bfdea0ff3b97e9fa335d7f73'

def function_sections(blob):
    hdr = struct.unpack_from('<16sHHIIIIIHHHHHH', blob)
    if hdr[0][:6] != b'\x7fELF\x01\x01' or hdr[1:3] != (1, 40):
        raise ValueError('Expected ARM ELF32 little-endian object')
    pos, width, count, string_index = hdr[6], hdr[11], hdr[12], hdr[13]
    if width != 40 or pos + width * count > len(blob) or string_index >= count:
        raise ValueError('Invalid ELF32 section headers')
    rows = [struct.unpack_from('<10I', blob, pos + i*40) for i in range(count)]
    strrow = rows[string_index]
    names = blob[strrow[4]:strrow[4]+strrow[5]]
    secs = {}
    for r in rows:
        if r[0] >= len(names):
            continue
        end = names.find(b'\x00', r[0])
        if end < 0:
            continue
        name = names[r[0]:end].decode('ascii','replace')
        if r[1] == 1 and name.startswith('.text.st_'):
            if r[4]+r[5] > len(blob):
                raise ValueError('Truncated ELF section '+name)
            if name[6:] in secs:
                raise ValueError('Duplicate section '+name)
            secs[name[6:]] = blob[r[4]:r[4]+r[5]]
        if r[1] in (4,9) and name.startswith(('.rel.text.st_', '.rela.text.st_')) and r[5]:
            raise ValueError('Unresolved relocation '+name)
    return secs

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--working-code', type=Path, required=True)
    p.add_argument('--overlays-csv', type=Path, required=True)
    p.add_argument('--clang', default='clang')
    p.add_argument('--out', type=Path, default=Path('build/eur1/verify_bl50c.json'))
    a = p.parse_args()
    manifest = json.loads((HERE/'manifest_50.json').read_text(encoding='utf-8'))
    functions = manifest['functions']
    src = (HERE/'reconstructed_50.c').read_text(encoding='utf-8')
    names = re.findall(r'\b(?:uint32_t|void|volatile uint32_t\s*\*)\s*(st_[A-Za-z0-9_]+)\s*\(', src)
    expected = {f['symbol'] for f in functions}
    if len(functions)!=50 or len(expected)!=50 or len(names)!=50 or set(names)!=expected:
        raise ValueError('Expected exactly 50 distinct C definitions and manifest rows')
    with tempfile.TemporaryDirectory(prefix='st_eur1_50_') as tmp:
        obj = Path(tmp)/'recovered.o'
        subprocess.run([a.clang,'--target=armv5te-none-eabi','-march=armv5te',
                        '-marm','-O2','-ffreestanding','-fomit-frame-pointer',
                        '-ffunction-sections','-Wno-unused-variable',
                        '-Wno-unused-label','-Wno-unused-parameter','-c',
                        str(HERE/'reconstructed_50.c'),'-o',str(obj)],check=True)
        compiled = function_sections(obj.read_bytes())
    if set(compiled) != expected:
        raise ValueError('Unexpected emitted function sections')
    base = {'arm9':0x02000000}
    sha = {'arm9':ARM9_SHA1}
    for row in csv.DictReader(a.overlays_csv.open(encoding='utf-8')):
        key=f'overlay_{int(row["id"]):03d}'
        base[key]=int(row['ram'],16)
        sha[key]=row['hash_sha1']
    files={}
    result=[]
    for f in functions:
        mod=f['module']
        if mod not in files:
            source = a.working_code/(mod+'.bin')
            files[mod]=source.read_bytes()
            if hashlib.sha1(files[mod]).hexdigest()!=sha[mod]:
                raise ValueError('Wrong version or corrupt ROM extraction: '+str(source))
        addr=int(f['address'],16)
        if mod=='arm9' and addr>=0x0203d51c:
            raise ValueError('ARM9 address is not executable: '+f['address'])
        offset=addr-base[mod]
        orig=files[mod][offset:offset+f['size']] if offset>=0 else b''
        if len(orig)!=f['size'] or hashlib.sha256(orig).hexdigest()!=f['original_sha256']:
            raise ValueError('Original executable span differs: '+mod+':'+f['address'])
        obj=compiled[f['symbol']]
        match=(orig==obj)
        if match!=f['clang_byte_exact']:
            raise ValueError('Clang matching changed: '+f['symbol'])
        result.append({'module':mod,'address':f['address'],'symbol':f['symbol'],
                       'original_size':len(orig),'compiled_size':len(obj),'clang_exact':match})
    exact=sum(r['clang_exact'] for r in result)
    if exact!=28 or sum(r['original_size'] for r in result)!=1528 or sum(r['original_size'] for r in result if r['clang_exact'])!=748:
        raise ValueError('Aggregate validation mismatch')
    report={'summary':{'clang_exact':exact,'provisional':50-exact},
            'functions':result,'limitations':'Standalone Clang, not CodeWarrior or DS source integration'}
    a.out.parent.mkdir(parents=True,exist_ok=True)
    a.out.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(f'PASS: {exact} Clang-exact and {50-exact} nonmatching functions; 50 source bodies')
    print('Untested: CodeWarrior, DS objdiff, full DS game build and in-game behavior')
    print('Report:',a.out)

if __name__=='__main__':
    main()
