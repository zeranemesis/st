#!/usr/bin/env python3
"""Hash-check readable ARMv5TE candidate bodies against published EUR1 SHA256 spans.

No ROM needed: original span hashes come from the user-verified manifest_50.json.
This is standalone Clang comparison, NOT CodeWarrior or Nintendo DS objdiff.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import tempfile

from verify_50 import function_sections

HERE = Path(__file__).resolve().parent
FLAGS = ('--target=armv5te-none-eabi', '-march=armv5te', '-marm', '-O2',
         '-ffreestanding', '-fomit-frame-pointer', '-ffunction-sections',
         '-Wno-unused-parameter', '-c')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--clang', default='clang', help='Clang with ARMv5TE backend')
    parser.add_argument('--out', type=Path,
                        default=Path('build/eur1/semantic_candidates_round9.json'))
    args = parser.parse_args()
    manifest = json.loads((HERE / 'manifest_50.json').read_text(encoding='utf-8'))
    pending = {f['symbol']: f for f in manifest['functions'] if not f['clang_byte_exact']}
    with tempfile.TemporaryDirectory(prefix='st_round9_') as tmp:
        obj = Path(tmp) / 'round9.o'
        subprocess.run([args.clang, *FLAGS,
                        str(HERE / 'semantic_candidates_round9.c'), '-o', str(obj)],
                       check=True)
        generated = function_sections(obj.read_bytes())
    if len(generated) != 18 or not set(generated).issubset(pending):
        raise ValueError('Expected 18 separate candidates from the 20 nonmatching originals')
    rows = []
    for symbol, code in sorted(generated.items()):
        ref = pending[symbol]
        rows.append({'symbol': symbol, 'module': ref['module'],
                     'address': ref['address'], 'original_size': ref['size'],
                     'candidate_size': len(code),
                     'clang_byte_exact': (len(code) == ref['size'] and
                                          hashlib.sha256(code).hexdigest() == ref['original_sha256'])})
    exact = sum(row['clang_byte_exact'] for row in rows)
    report = {'comparison': 'Clang ARMv5TE -O2 standalone source vs original manifest SHA256',
              'candidate_count': len(rows), 'new_candidate_matches': exact,
              'note': 'No ROM required; no DS build or Nintendo CodeWarrior claim',
              'candidates': rows}
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(f'PASS: 18 compiled candidates, {exact}/18 Clang SHA256-exact; '
          f'{18 - exact} still nonmatching')
    print(f'Detailed report: {args.out}')


if __name__ == '__main__':
    main()
