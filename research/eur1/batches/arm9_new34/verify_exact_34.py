#!/usr/bin/env python3
"""Recompile 34 isolated C ARM9 functions and compare against user's LOCAL Spirit Tracks EUR1 extracted code.

The accompanying 66 targets are an address/BL-reference backlog, NOT additional C decompilations.
No Nintendo ROM or binary data is distributed by this verifier.
"""
from __future__ import annotations

import argparse
import collections
import csv
import hashlib
import json
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent
CFLAGS = ['--target=armv5te-none-eabi', '-march=armv5te', '-marm', '-O2',
          '-ffreestanding', '-fomit-frame-pointer', '-ffunction-sections']


def arm_elf_function_sections(data: bytes) -> dict[str, bytes]:
    if data[:6] != b'\x7fELF\x01\x01' or len(data) < 52:
        raise ValueError('Expected little-endian ELF32 ARM object')
    hdr = struct.unpack_from('<16sHHIIIIIHHHHHH', data)
    if hdr[1] != 1 or hdr[2] != 40:
        raise ValueError('Not a relocatable ARM ELF object')
    shoff, entries, count, names_index = hdr[6], hdr[11], hdr[12], hdr[13]
    if entries != 40 or shoff + entries * count > len(data) or names_index >= count:
        raise ValueError('Bad ELF section table')
    rows = [struct.unpack_from('<10I', data, shoff + i * 40) for i in range(count)]
    strings = rows[names_index]
    names = data[strings[4]:strings[4] + strings[5]]
    sections = {}
    for row in rows:
        pos = row[0]
        if pos >= len(names):
            continue
        end = names.find(b'\0', pos)
        if end < 0:
            continue
        name = names[pos:end].decode('ascii', 'replace')
        if row[1] in (4, 9) and (name.startswith('.rel.text.st_') or name.startswith('.rela.text.st_')) and row[5] > 0:
            raise ValueError('Unresolved relocation in candidate: ' + name)
        if row[1] == 1 and name.startswith('.text.st_'):
            if row[4] + row[5] > len(data):
                raise ValueError('ELF section exceeds object')
            key = name[6:]
            if key in sections:
                raise ValueError('Duplicate function section: ' + key)
            sections[key] = data[row[4]:row[4] + row[5]]
    return sections


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--working-code', required=True, type=Path,
                        help='Folder with arm9.bin and overlay_NNN.bin extracted from your own EUR1 ROM')
    parser.add_argument('--overlays-csv', type=Path, required=True,
                        help='reports/overlays.csv from existing research/eur1/scripts/analyze_nds.py')
    parser.add_argument('--clang', default='clang')
    parser.add_argument('--out', type=Path, default=Path('build/eur1/verify_34_new.json'))
    args = parser.parse_args()

    manifest = json.loads((ROOT / 'manifest_100_targets.json').read_text())
    functions = manifest['functions']
    verified = [x for x in functions if x['status'] == 'clang_armv5te_byte_identical']
    backlog = [x for x in functions if x['status'] == 'BL_target_queued_no_C_reconstruction']
    if len(functions) != 100 or len(verified) != 34 or len(backlog) != 66:
        raise ValueError('Manifest must have exactly 34 matched C functions and 66 backlog addresses')
    base = {'arm9': 0x02000000}
    for row in csv.DictReader(args.overlays_csv.open(encoding='utf-8')):
        base[int(row['id'])] = int(row['ram'], 16)

    with tempfile.TemporaryDirectory(prefix='st_eur1_34_') as d:
        obj = Path(d) / 'batch34.o'
        p = subprocess.run([args.clang, *CFLAGS, '-c',
                            str(ROOT / 'recovered_exact_34.c'), '-o', str(obj)],
                           capture_output=True, text=True)
        if p.returncode:
            raise RuntimeError('Clang ARM compile failed: ' + p.stderr[-4000:])
        compiled = arm_elf_function_sections(obj.read_bytes())

    if len(compiled) != 34:
        raise ValueError(f'Compiled {len(compiled)} functions instead of exactly 34')
    images = {}
    results = []
    for entry in verified:
        module = entry['module']
        if module not in images:
            path = args.working_code / ('arm9.bin' if module == 'arm9' else f'overlay_{module:03}.bin')
            images[module] = path.read_bytes()
        addr = int(entry['address'], 16)
        offset = addr - base[module]
        if offset < 0:
            raise ValueError('Original address below module base')
        original = images[module][offset:offset + entry['size_bytes']]
        generated = compiled.get(entry['symbol'])
        match = len(original) == entry['size_bytes'] and original == generated
        actual_sha = hashlib.sha256(original).hexdigest()
        if actual_sha != entry['original_span_sha256']:
            raise ValueError('Wrong original ROM revision or overlay data at ' + entry['address'])
        results.append({'module': module, 'address': entry['address'], 'status': 'exact' if match else 'different',
                        'original_bytes': len(original), 'emitted_bytes': len(generated) if generated is not None else None,
                        'sha256': actual_sha})
    good = sum(x['status'] == 'exact' for x in results)
    report = {'game': manifest['game'], 'revision': manifest['revision'],
              'checked_standalone_clang': len(results), 'exact': good,
              'bytes_exact': sum(x['original_bytes'] for x in results if x['status'] == 'exact'),
              'queued_unreconstructed': len(backlog), 'results': results,
              'limitations': '34 byte-matched standalone C snippets, NOT DS C++ objdiff units; 66 additional addresses are only candidates.'}
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(report, indent=2) + '\n')
    print(f'Clang ARMv5TE standalone match: {good}/34 C functions, {report["bytes_exact"]} original bytes identical')
    print('Separate research backlog: 66 direct-BL target addresses; C not yet reconstructed')
    print('Report:', args.out)
    return 0 if good == 34 else 1


if __name__ == '__main__':
    try:
        sys.exit(main())
    except (OSError, RuntimeError, ValueError, subprocess.SubprocessError) as exc:
        print('FAIL:', exc, file=sys.stderr)
        sys.exit(1)
