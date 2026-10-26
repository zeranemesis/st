#!/usr/bin/env python3
"""Audit ten reinterpreted overlay-0 C functions against original ROM span hashes.

The hashes are from the existing owner-verified fifth-500 manifest. The
original ROM is neither read nor distributed by this ROM-free comparison.
Only standalone Clang ARMv5TE code generation is being measured.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import tempfile

from verify_fifth500 import FLAGS, elf32_sections

HERE = Path(__file__).resolve().parent
SOURCE = HERE / 'semantic_refactors_round11.c'
TARGETS = (
    '0x02057D6C', '0x020590E4', '0x0205B090', '0x0205C5A0',
    '0x02060738', '0x02060804', '0x02062E44', '0x02065460',
    '0x0206547C', '0x0206590C',
)

def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--clang', default='clang')
    parser.add_argument('--out', type=Path,
                        default=Path('build/eur1/semantic_refactors_round11.json'))
    args = parser.parse_args()
    manifest = json.loads((HERE / 'manifest_fifth500.json').read_text(encoding='utf-8'))
    indexed = {(str(row['module']), row['address'].upper()): row
               for row in manifest['functions']}
    if len(indexed) != 500:
        raise ValueError('Original 500-function manifest is not unique')
    with tempfile.TemporaryDirectory(prefix='st-semantic11-') as tmp:
        obj = Path(tmp) / 'round11.o'
        result = subprocess.run(
            [args.clang, *FLAGS, '-c', str(SOURCE), '-o', str(obj)],
            capture_output=True, text=True)
        if result.returncode:
            raise ValueError('ARM Clang compile failed: ' + result.stderr[-3000:])
        sections = elf32_sections(obj.read_bytes())
    expected = {f'.text.st_ov000_{int(address, 16):08X}' for address in TARGETS}
    if set(sections) != expected:
        raise ValueError('Emitted C symbols differ: ' + str(sorted(set(sections) ^ expected)))
    rows = []
    for address in TARGETS:
        entry = indexed.get(('0', address.upper()))
        if entry is None or entry['clang_standalone_status'] == 'exact_original_machine_bytes':
            raise ValueError(f'Target not a known provisional function: {address}')
        symbol = f'.text.st_ov000_{int(address, 16):08X}'
        code = sections[symbol]
        exact = (len(code) == entry['size_bytes'] and
                 hashlib.sha256(code).hexdigest() == entry['original_span_sha256'])
        rows.append({
            'address': address, 'module': 'overlay_000',
            'original_size': entry['size_bytes'], 'generated_size': len(code),
            'standalone_clang_sha256_exact': exact,
            'status': 'byte_exact' if exact else
                      'size_mismatch' if len(code) != entry['size_bytes'] else
                      'same_size_code_differs',
        })
    exact_count = sum(row['standalone_clang_sha256_exact'] for row in rows)
    report = {
        'compiler': 'standalone Clang ARMv5TE -O2', 'source': SOURCE.name,
        'functions': len(rows), 'new_exact': exact_count, 'rows': rows,
        'limitation': 'Not original Nintendo CodeWarrior matching, game rebuild, or runtime equivalence',
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(f'PASS: {len(rows)} tested source functions, {exact_count} Clang SHA256-exact, '
          f'{len(rows) - exact_count} provisional')
    print('Results:', args.out)

if __name__ == '__main__':
    main()
