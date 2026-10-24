#!/usr/bin/env python3
"""Verify coverage and ARM hashes of all 20 existing nonmatching bl50c functions.

A Clang SHA256 match is standalone ARMv5TE code equality ONLY, not Nintendo
CodeWarrior matching, source semantics, game rebuild, or PC port progress.
No ROM bytes are required or included.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import tempfile

from verify_50 import function_sections

HERE = Path(__file__).resolve().parent
FLAGS = (
    '--target=armv5te-none-eabi', '-march=armv5te', '-marm', '-O2',
    '-ffreestanding', '-fomit-frame-pointer', '-ffunction-sections',
    '-Wno-unused-parameter', '-c',
)
SOURCES = {
    'semantic_candidates_round9.c': 18,
    'semantic_candidates_round10.c': 2,
}


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--clang', default='clang')
    parser.add_argument('--out', type=Path,
                        default=Path('build/eur1/semantic_candidates_round10.json'))
    args = parser.parse_args()

    manifest = json.loads((HERE / 'manifest_50.json').read_text(encoding='utf-8'))
    functions = manifest['functions']
    if len(functions) != 50 or len({f['symbol'] for f in functions}) != 50:
        raise ValueError('Expected 50 distinct documented functions')
    pending = {f['symbol']: f for f in functions if not f['clang_byte_exact']}
    if len(pending) != 20:
        raise ValueError('The baseline changed; review reference exact statuses first')
    generated = {}
    with tempfile.TemporaryDirectory(prefix='st_round10_') as tmp:
        for source, expected_count in SOURCES.items():
            obj = Path(tmp) / (source + '.o')
            subprocess.run([args.clang, *FLAGS, str(HERE / source), '-o', str(obj)],
                           capture_output=True, text=True, check=True)
            code = function_sections(obj.read_bytes())
            if len(code) != expected_count:
                raise ValueError(f'{source}: expected {expected_count} function sections; got {len(code)}')
            duplicate = generated.keys() & code.keys()
            if duplicate:
                raise ValueError(f'Symbols defined by both batches: {sorted(duplicate)}')
            generated.update({symbol: (source, machine_code)
                              for symbol, machine_code in code.items()})
    if generated.keys() != pending.keys():
        raise ValueError('Candidates and previously unmatched symbols differ: '
                         + str(sorted(generated.keys() ^ pending.keys())))

    rows = []
    for symbol, (source, compiled) in sorted(generated.items()):
        reference = pending[symbol]
        matched = (len(compiled) == reference['size'] and
                   hashlib.sha256(compiled).hexdigest() == reference['original_sha256'])
        rows.append({
            'source': source, 'symbol': symbol, 'module': reference['module'],
            'address': reference['address'], 'original_size': reference['size'],
            'candidate_size': len(compiled), 'clang_byte_exact': matched,
            'status': 'exact' if matched else 'size_differs' if len(compiled) != reference['size']
            else 'same_size_hash_differs',
        })
    exact = sum(row['clang_byte_exact'] for row in rows)
    report = {
        'kind': 'standalone Clang ARMv5TE -O2 C candidates vs original span SHA256',
        'baseline': {'exact': 30, 'total': 50, 'matched_original_bytes': 848},
        'candidates_covered': len(rows),
        'new_sha256_exact_candidates': exact,
        'nonmatching_candidates': len(rows) - exact,
        'limitations': 'NOT CodeWarrior, game objdiff, or ROM rebuild; no ROM data required',
        'functions': rows,
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(f'PASS: {len(rows)}/20 existing unmatched functions have candidate C; '
          f'{exact}/20 candidates are Clang SHA256-exact')
    print(f'Report: {args.out}')


if __name__ == '__main__':
    main()
