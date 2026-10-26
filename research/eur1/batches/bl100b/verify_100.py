#!/usr/bin/env python3
"""Verify EUR1 Spirit Tracks 100 research functions against LOCAL extracted ARM9 images.

Checks standalone Clang ARMv5TE byte equality only, not Nintendo CodeWarrior,
ROM rebuild or game execution. No ROM or machine-code dump is distributed.
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
ROM_SHA1 = 'dcb221a89acb894503a461c2c7d4cfdad9a06b68'
RX = re.compile(r'/\*\s*(\d{3})\s+(arm9|\d+)\s+(0x[\dA-Fa-f]+)\s+(\d+)\s+([EP])\s*\*/\s*ST_FN\((st_[A-Za-z0-9_]+),')

def parse_elf(data):
    h = struct.unpack_from('<16sHHIIIIIHHHHHH', data)
    if h[0][:6] != b'\x7fELF\x01\x01' or h[1:3] != (1,40):
        raise ValueError('Expected little-endian ARM ELF32 object')
    off, width, count, names_index = h[6], h[11], h[12], h[13]
    if width != 40 or off+40*count > len(data) or names_index >= count:
        raise ValueError('Malformed ELF section table')
    rows = [struct.unpack_from('<10I', data, off+i*40) for i in range(count)]
    names = data[rows[names_index][4]:rows[names_index][4]+rows[names_index][5]]
    out = {}
    for r in rows:
        e = names.find(b'\0', r[0])
        if e < 0:
            continue
        name = names[r[0]:e].decode('ascii','replace')
        if r[1] in (4,9) and name.startswith(('.rel.text.st_','.rela.text.st_')) and r[5]:
            raise ValueError('Unresolved relocation '+name)
        if r[1] == 1 and name.startswith('.text.st_'):
            if r[4]+r[5] > len(data):
                raise ValueError('Invalid function section')
            out[name[6:]] = data[r[4]:r[4]+r[5]]
    return out

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--working-code',required=True,type=Path)
    p.add_argument('--overlays-csv',required=True,type=Path)
    p.add_argument('--clang',default='clang')
    p.add_argument('--out',default='build/eur1/bl100b_verify.json',type=Path)
    a = p.parse_args()
    text = (HERE/'reconstructed_100.c').read_text(encoding='utf-8')
    found = RX.findall(text)
    if len(found) != 100 or len({(x[1],x[2]) for x in found}) != 100:
        raise ValueError('Expected 100 distinct (module,address) C definitions')
    if sum(x[4]=='E' for x in found)!=74:
        raise ValueError('Expected 74 E and 26 P classifications')
    with tempfile.TemporaryDirectory() as temp:
        obj = Path(temp)/'batch.o'
        subprocess.run([a.clang,'--target=armv5te-none-eabi','-march=armv5te',
                        '-marm','-O2','-ffreestanding','-fomit-frame-pointer',
                        '-ffunction-sections','-c',str(HERE/'reconstructed_100.c'),
                        '-o',str(obj)],check=True)
        compiled = parse_elf(obj.read_bytes())
    bases={'arm9':0x02000000}
    hashes={'arm9':ARM9_SHA1}
    for row in csv.DictReader(a.overlays_csv.open(encoding='utf-8')):
        k=str(int(row['id']))
        bases[k]=int(row['ram'],16)
        hashes[k]=row['hash_sha1']
    images={}
    results=[]
    for index,mod,address,size,expected,symbol in found:
        if mod not in images:
            name='arm9.bin' if mod=='arm9' else f'overlay_{int(mod):03d}.bin'
            image=(a.working_code/name).read_bytes()
            if hashlib.sha1(image).hexdigest()!=hashes[mod]:
                raise ValueError('Wrong EUR1 image: '+name)
            images[mod]=image
        off=int(address,16)-bases[mod]
        original=images[mod][off:off+int(size)]
        generated=compiled.get(symbol)
        if off<0 or len(original)!=int(size) or generated is None:
            raise ValueError('Missing function: '+mod+' '+address)
        exact=(original==generated)
        if exact!=(expected=='E'):
            raise ValueError('Clang regression at '+mod+' '+address)
        results.append({'index':int(index),'module':mod,'address':address,
                        'symbol':symbol,'original_size':len(original),
                        'generated_size':len(generated),'original_sha256':hashlib.sha256(original).hexdigest(),
                        'clang_exact':exact})
    counts=collections.Counter('exact' if x['clang_exact'] else 'provisional' for x in results)
    report={'game':'Spirit Tracks','revision':'EUR Rev 1','rom_sha1':ROM_SHA1,
            'count':len(results),'status':dict(counts),'functions':results,
            'limitations':'Clang standalone only; CodeWarrior, DS objdiff, and gameplay untested.'}
    a.out.parent.mkdir(parents=True,exist_ok=True)
    a.out.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(f"PASS {counts['exact']}/100 Clang byte-identical, {counts['provisional']} provisional")
    print('Report:',a.out)

if __name__=='__main__':
    main()
