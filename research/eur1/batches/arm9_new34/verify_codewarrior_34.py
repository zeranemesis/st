#!/usr/bin/env python3
"""Standalone CodeWarrior ARM dsi/1.2p1 test for 34 EUR1 functions.

Does not integrate anything in the real Spirit Tracks C++ build. Requires Windows
and the CodeWarrior/sjiswrap binaries already installed in the user's repo.
The 66 other directly-called targets in the manifest are not compiled here.
"""
from __future__ import annotations
import argparse
import collections
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
import tempfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]
COMPILER = ROOT / 'tools/mwccarm/dsi/1.2p1/mwccarm.exe'
WRAPPER = ROOT / 'tools/sjiswrap.exe'
DEFAULT_OUT = ROOT / 'build/eur1/codewarrior_new34.json'
FLAGS = ['-O4,p', '-enum', 'int', '-char', 'signed', '-str', 'noreuse',
         '-proc', 'arm946e', '-gccext,on', '-fp', 'soft', '-inline', 'noauto',
         '-lang', 'c', '-Cpp_exceptions', 'off', '-RTTI', 'off',
         '-interworking', '-w', 'off', '-sym', 'on', '-gccinc', '-nolink',
         '-msgstyle', 'gcc', '-ipa', 'file']


def extract_symbols(data: bytes, wanted: set[str]) -> dict[str, dict]:
    if data[:6] != b'\x7fELF\x01\x01' or len(data) < 52:
        raise ValueError('Expected ARM32 little-endian CodeWarrior ELF')
    h = struct.unpack_from('<16sHHIIIIIHHHHHH', data)
    if h[1] != 1 or h[2] != 40:
        raise ValueError('Not a relocatable ARM object')
    off, width, n = h[6], h[11], h[12]
    if width != 40 or off + n * width > len(data):
        raise ValueError('Invalid ELF section header table')
    sec = [struct.unpack_from('<10I', data, off + i * 40) for i in range(n)]

    def getsection(i: int) -> bytes:
        if not 0 <= i < n or sec[i][1] == 8:
            raise ValueError('ELF section invalid')
        a, b = sec[i][4], sec[i][5]
        if a + b > len(data):
            raise ValueError('ELF section out of bounds')
        return data[a:a + b]

    rel = collections.defaultdict(list)
    for q in sec:
        if q[1] not in (4, 9):
            continue
        es = q[9] or (12 if q[1] == 4 else 8)
        if es < 8 or q[5] % es or q[4] + q[5] > len(data):
            raise ValueError('Corrupt relocation section')
        for i in range(q[4], q[4] + q[5], es):
            rel[q[7]].append(struct.unpack_from('<I', data, i)[0])

    found = {}
    for q in sec:
        if q[1] != 2:
            continue
        st = getsection(q[6])
        es = q[9] or 16
        if es < 16 or q[5] % es:
            raise ValueError('Invalid symbol table stride')
        for i in range(q[4], q[4] + q[5], es):
            nameoff, value, size, info, other, shndx = struct.unpack_from('<IIIBBH', data, i)
            if nameoff >= len(st):
                continue
            end = st.find(b'\0', nameoff)
            if end < 0:
                raise ValueError('Symbol name unterminated')
            name = st[nameoff:end].decode('ascii', 'replace')
            if name not in wanted:
                continue
            if name in found:
                found[name] = {'error': 'duplicate_symbol'}
                continue
            if not 0 < shndx < n:
                found[name] = {'error': 'undefined_symbol'}
                continue
            data_segment = getsection(shndx)
            start = value - sec[shndx][3]
            if size <= 0 or start < 0 or start + size > len(data_segment):
                found[name] = {'error': 'invalid_size_or_offset'}
                continue
            code = data_segment[start:start + size]
            count_rel = sum(start <= x < start + size for x in rel.get(shndx, []))
            found[name] = {'size': size, 'sha256': hashlib.sha256(code).hexdigest(),
                           'relocations': count_rel}
    return found


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler', type=Path, default=COMPILER)
    parser.add_argument('--wrapper', type=Path, default=WRAPPER)
    parser.add_argument('--out', type=Path, default=DEFAULT_OUT)
    a = parser.parse_args()
    if os.name != 'nt':
        raise RuntimeError('Windows required for the original proprietary compiler')
    if not a.compiler.is_file() or not a.wrapper.is_file():
        raise FileNotFoundError('CodeWarrior ARM compiler or sjiswrap missing')
    manifest = json.loads((HERE / 'manifest_100_targets.json').read_text())
    checked = [f for f in manifest['functions'] if f['status'] == 'clang_armv5te_byte_identical']
    if len(checked) != 34:
        raise ValueError('Expected exactly 34 compiled C functions')
    with tempfile.TemporaryDirectory(prefix='st_new34_cw_') as d:
        out = Path(d)
        cmd = [str(a.wrapper), str(a.compiler), *FLAGS, '-c',
               str(HERE / 'recovered_exact_34.c'), '-o', str(out)]
        p = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True,
                           errors='replace', timeout=180)
        if p.returncode:
            raise RuntimeError('CodeWarrior failed:\n' + (p.stdout + '\n' + p.stderr)[-7000:])
        objects = list(out.glob('*.o'))
        if len(objects) != 1:
            raise RuntimeError(f'Expected one CodeWarrior object, got {len(objects)}')
        found = extract_symbols(objects[0].read_bytes(), {f['symbol'] for f in checked})
    rows = []
    for f in checked:
        x = found.get(f['symbol'])
        if not x:
            status = 'not_emitted'
        elif 'error' in x:
            status = x['error']
        elif x['relocations']:
            status = 'relocations_unresolved'
        elif x['size'] != f['size_bytes']:
            status = 'different_size'
        elif x['sha256'] == f['original_span_sha256']:
            status = 'exact_codewarrior_standalone'
        else:
            status = 'different_instructions'
        rows.append({'module': f['module'], 'address': f['address'],
                     'status': status, 'expected_size': f['size_bytes'],
                     'actual': x})
    counts = dict(collections.Counter(r['status'] for r in rows))
    report = {'game': manifest['game'], 'revision': manifest['revision'],
              'compiler': str(a.compiler), 'flags': FLAGS, 'checked': 34,
              'status_counts': counts, 'results': rows,
              'limitations': 'Standalone code equality, not original C++ source or official DS objdiff match.'}
    a.out.parent.mkdir(parents=True, exist_ok=True)
    a.out.write_text(json.dumps(report, indent=2) + '\n')
    print('CodeWarrior exact:', counts.get('exact_codewarrior_standalone', 0), '/34')
    print('Statuses:', counts)
    print('Report:', a.out)
    print('IMPORTANT: original C++ build integration has NOT been measured')
    return 0


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as exc:
        print('FAIL:', exc, file=sys.stderr)
        raise SystemExit(1)
