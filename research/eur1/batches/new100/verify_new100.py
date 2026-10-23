#!/usr/bin/env python3
"""Compare 100 experimental EUR Rev 1 ARM9 C functions to extracted ROM spans.

A standalone Clang match is NOT CodeWarrior matching or proof of original
C++ semantics. Requires user's own locally extracted and decrypted overlays.
"""
import argparse
import hashlib
import importlib.util
import json
import subprocess
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]
SOURCE = HERE / 'new100.c'
MANIFEST = HERE / 'manifest_new100.json'
REFERENCE_PARSER = ROOT / 'research/eur1/batches/overlay_candidates_1000/verify_candidates_1000.py'
FLAGS = ['--target=armv5te-none-eabi','-march=armv5te','-marm','-O2','-ffreestanding','-ffunction-sections','-w']


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--working-code', type=Path, required=True)
    ap.add_argument('--clang', default='clang')
    args = ap.parse_args()
    spec = importlib.util.spec_from_file_location('st_elf32_sections', REFERENCE_PARSER)
    if spec is None or spec.loader is None: raise RuntimeError('Missing existing ELF parser: ' + str(REFERENCE_PARSER))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    doc = json.loads(MANIFEST.read_text(encoding='utf-8'))
    functions = doc['functions']
    assert len(functions)==100
    with tempfile.TemporaryDirectory(prefix='st_new100_') as t:
        obj = Path(t) / 'result.o'
        cp = subprocess.run([args.clang, *FLAGS, '-c', str(SOURCE), '-o', str(obj)],capture_output=True,text=True)
        if cp.returncode: raise RuntimeError(cp.stderr)
        sections = module.elf32_sections(obj.read_bytes())
    exact, sizes, bytes_total = 0, 0, 0
    images = {}
    for f in functions:
        mod = f['module']
        if mod not in images:
            p = args.working_code / ('arm9.bin' if mod=='arm9' else f'overlay_{mod:03d}.bin')
            image = p.read_bytes()
            assert hashlib.sha1(image).hexdigest() == doc['module_sha1'][str(mod)], 'Module digest mismatch: '+str(mod)
            images[mod] = image
        a = int(f['address'],16)
        base = int(doc['module_base'][str(mod)],16)
        n=f['size_bytes']
        original=images[mod][a-base:a-base+n]
        if len(original)!=n or hashlib.sha256(original).hexdigest()!=f['original_span_sha256']:
            raise RuntimeError('Original span mismatch: '+f['symbol'])
        generated=sections.get('.text.'+f['symbol'])
        if generated is None: raise RuntimeError('Missing generated function: '+f['symbol'])
        equal=generated==original
        expected=(f['clang_status']=='byte_exact')
        if equal != expected:raise RuntimeError('Research baseline changed: '+f['symbol'])
        exact+=equal
        sizes+=len(generated)==n
        bytes_total+=n
    print(f'PASS 100/100 compiled, {exact}/100 Clang exact, {sizes}/100 matching sizes, {bytes_total} original ARM bytes')
    print('WARNING: this is standalone Clang matching, not CodeWarrior or Nintendo DS build matching.')

if __name__=='__main__':main()
