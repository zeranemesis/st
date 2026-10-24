#!/usr/bin/env python3
"""Measure the remaining Clang ARMv5TE byte mismatches against your own EUR Rev 1 ROM.

Do not commit local output files if you enable --local-asm: they may contain
instructions disassembled from your ROM. This is NOT Nintendo CodeWarrior matching.
"""
from __future__ import annotations
import argparse
import csv
import hashlib
import json
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

# Imported from sibling verified-tooling (always present in the same research batch).
from verify_50 import function_sections

FLAGS = ('--target=armv5te-none-eabi', '-march=armv5te', '-marm', '-O2',
         '-ffreestanding', '-fomit-frame-pointer', '-ffunction-sections', '-w')
ARM9_SHA1 = '650ea160271b2297bfdea0ff3b97e9fa335d7f73'


def as_elf32_arm(data: bytes, base: int) -> bytes:
    """Wrap local ARM code as a temporary section so objdump can disassemble it."""
    strings = b'\x00.text\x00.shstrtab\x00'
    off = 0x100
    strings_off = off + len(data)
    shoff = (strings_off + len(strings) + 3) & ~3
    buf = bytearray(shoff + 120)
    buf[off:off + len(data)] = data
    buf[strings_off:strings_off + len(strings)] = strings
    ident = b'\x7fELF' + bytes([1, 1, 1, 0]) + bytes(8)
    struct.pack_into('<16sHHIIIIIHHHHHH', buf, 0, ident, 2, 40, 1,
                     base, 0, shoff, 0x5000200, 52, 0, 0, 40, 3, 2)
    struct.pack_into('<10I', buf, shoff + 40, 1, 1, 6, base, off, len(data),
                     0, 0, 4, 0)
    struct.pack_into('<10I', buf, shoff + 80, 7, 3, 0, 0, strings_off,
                     len(strings), 0, 0, 1, 0)
    return bytes(buf)


def instruction_lines(output: str) -> list[str]:
    result = []
    for line in output.splitlines():
        match = re.match(r'^\s*[0-9a-f]+:\s+[0-9a-f]{8}\s+(.+)$', line)
        if match:
            result.append(match.group(1).split(' @ ')[0].strip())
    return result


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--working-code', required=True, type=Path)
    parser.add_argument('--overlays-csv', required=True, type=Path)
    parser.add_argument('--clang', default='clang')
    parser.add_argument('--objdump', default='llvm-objdump')
    parser.add_argument('--out', type=Path, default=Path('build/eur1/remaining_diagnostics.json'))
    parser.add_argument('--local-asm', type=Path, help='Optional local-only .txt disassembly of the ORIGINAL ROM and generated code (never commit)')
    args = parser.parse_args()

    root = Path(__file__).resolve().parent
    doc = json.loads((root / 'manifest_50.json').read_text(encoding='utf-8'))
    functions = doc['functions']
    if len(functions) != 50 or len({f['symbol'] for f in functions}) != 50:
        raise ValueError('Expected precisely fifty unique functions')
    bases = {'arm9': 0x02000000}
    hashes = {'arm9': ARM9_SHA1}
    with args.overlays_csv.open(encoding='utf-8', newline='') as handle:
        for row in csv.DictReader(handle):
            module = f'overlay_{int(row["id"]):03d}'
            bases[module] = int(row['ram'], 16)
            hashes[module] = row['hash_sha1']

    originals = {}
    cache = {}
    for f in functions:
        module = f['module']
        if module not in cache:
            contents = (args.working_code / (module + '.bin')).read_bytes()
            if hashlib.sha1(contents).hexdigest() != hashes[module]:
                raise ValueError('Unexpected EUR1 module SHA-1: ' + module)
            cache[module] = contents
        pos = int(f['address'], 16) - bases[module]
        data = cache[module][pos:pos + f['size']] if pos >= 0 else b''
        if len(data) != f['size'] or hashlib.sha256(data).hexdigest() != f['original_sha256']:
            raise ValueError('Original executable function bytes changed: ' + f['symbol'])
        originals[f['symbol']] = data

    with tempfile.TemporaryDirectory(prefix='st_matching20_') as tmp:
        directory = Path(tmp)
        compiled_path = directory / 'all.o'
        process = subprocess.run([args.clang, *FLAGS, '-c', str(root / 'reconstructed_50.c'),
                                  '-o', str(compiled_path)], capture_output=True, text=True)
        if process.returncode:
            raise RuntimeError('Clang ARM target failed: ' + process.stderr[-3000:])
        generated = function_sections(compiled_path.read_bytes())
        if {f['symbol'] for f in functions} != set(generated):
            raise ValueError('The compiled function set differs from the manifest')
        rows = []
        local = []
        for f in functions:
            name = f['symbol']
            origin = originals[name]
            new = generated[name]
            same = (origin == new)
            if same != f['clang_byte_exact']:
                raise ValueError('Baseline matching status differs from manifest for ' + name)
            first = next((i for i in range(0, min(len(origin), len(new)), 4)
                          if origin[i:i + 4] != new[i:i + 4]), None)
            matches = sum(origin[i:i + 4] == new[i:i + 4]
                          for i in range(0, min(len(origin), len(new)), 4))
            prefix = 0
            while prefix + 4 <= min(len(origin), len(new)) and origin[prefix:prefix + 4] == new[prefix:prefix + 4]:
                prefix += 4
            rows.append({'symbol': name, 'module': f['module'], 'address': f['address'],
                         'expected_matching': same, 'original_size': len(origin),
                         'compiled_size': len(new), 'equal_word_positions': matches,
                         'compared_word_positions': min(len(origin), len(new)) // 4,
                         'matching_prefix_bytes': prefix,
                         'first_difference_offset': first})
            if args.local_asm and not same:
                raw = directory / (name + '.elf')
                raw.write_bytes(as_elf32_arm(origin, int(f['address'], 16)))
                origdump = subprocess.run([args.objdump, '-d', str(raw)], capture_output=True, text=True, check=True)
                newdump = subprocess.run([args.objdump, '-d', f'--disassemble-symbols={name}', str(compiled_path)], capture_output=True, text=True, check=True)
                a, b = instruction_lines(origdump.stdout), instruction_lines(newdump.stdout)
                local += [f'### {name}  {f["address"]} (original at left)', '']
                for i in range(max(len(a), len(b))):
                    local.append(f'{i * 4:04x}: {a[i] if i < len(a) else "":<54} | {b[i] if i < len(b) else ""}')
                local.append('')
        matches = sum(row['expected_matching'] for row in rows)
        exact_bytes = sum(row['original_size'] for row in rows if row['expected_matching'])
        if matches != doc['summary']['exact'] or exact_bytes != doc['summary']['exact_bytes']:
            raise ValueError('Unexpected matching regression')
        pending = sorted((row for row in rows if not row['expected_matching']),
                         key=lambda row: (-row['equal_word_positions'], abs(row['compiled_size'] - row['original_size']), row['original_size']))
        report = {'compiler': 'Clang ARMv5TE -O2', 'scope': 'Standalone matching; NOT CodeWarrior/objdiff',
                  'summary': {'functions': len(rows), 'exact': matches, 'nonmatching': len(pending),
                              'matching_bytes': exact_bytes, 'total_original_bytes': sum(row['original_size'] for row in rows)},
                  'priority_order': pending, 'all_functions': rows,
                  'privacy': 'No original ARM ROM code words, machine-code dumps, or assets included in this JSON'}
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
        if args.local_asm:
            args.local_asm.parent.mkdir(parents=True, exist_ok=True)
            args.local_asm.write_text('\n'.join(local) + '\n', encoding='utf-8')
    print(f"PASS: {matches}/{len(rows)} byte-exact; {exact_bytes} original bytes; {len(pending)} remaining")
    print('Nearest functions: ' + ', '.join(f"{r['symbol']} ({r['equal_word_positions']}/{r['compared_word_positions']} aligned words)" for r in pending[:5]))
    print('JSON: ' + str(args.out))
    return 0


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (ValueError, RuntimeError, OSError, subprocess.CalledProcessError) as exc:
        print('FAIL: ' + str(exc), file=sys.stderr)
        raise SystemExit(1)
