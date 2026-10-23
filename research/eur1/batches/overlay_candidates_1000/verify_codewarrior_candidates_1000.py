#!/usr/bin/env python3
"""Verify the 1,000 EUR1 research code spans using CodeWarrior ARM dsi/1.2p1.

Run this tool on Windows with the Spirit Tracks repository's CodeWarrior
compiler and sjiswrap. It generates throwaway C translation units in batches,
extracts compiled ELF32 ARM symbols and compares their *exact bytes* with
original EUR1 code-span SHA-256 fingerprints from the existing manifest.

A CodeWarrior standalone byte match is not a validated independent original
function nor an integrated DS game build match. 677 candidate entrypoints still
lack strong original-function boundary evidence. No ROM/assets are read here.
"""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]  # research/eur1/batches/overlay_candidates_1000 -> repo
SOURCE = HERE / 'candidate_reconstructions_1000.c'
MANIFEST = HERE / 'manifest_candidates_1000.json'
DEFAULT_COMPILER = ROOT / 'tools/mwccarm/dsi/1.2p1/mwccarm.exe'
DEFAULT_WRAPPER = ROOT / 'tools/sjiswrap.exe'
DEFAULT_REPORT = ROOT / 'build/eur1/codewarrior_candidates_1000.json'

# Match the working original project verifier's standalone CodeWarrior C flags.
CFLAGS = [
    '-O4,p', '-enum', 'int', '-char', 'signed', '-str', 'noreuse',
    '-proc', 'arm946e', '-gccext,on', '-fp', 'soft',
    '-inline', 'noauto', '-lang', 'c', '-Cpp_exceptions', 'off',
    '-RTTI', 'off', '-interworking', '-w', 'off', '-sym', 'on',
    '-gccinc', '-nolink', '-msgstyle', 'gcc', '-ipa', 'file',
]

FUNC_RE = re.compile(r'\b(st_ov\d{3}_[0-9A-F]{8})\(')
EXPECTED_EVIDENCE = {
    'upstream_symbol', 'local_function_pointer',
    'post_return_candidate', 'unconfirmed_possible_epilogue',
}


def load_inputs() -> tuple[list[dict], dict[str, str]]:
    doc = json.loads(MANIFEST.read_text(encoding='utf-8'))
    functions = doc['functions']
    if len(functions) != 1000:
        raise ValueError(f'Expected 1000 manifest entries; got {len(functions)}')
    names = [f"st_ov{f['overlay']:03}_{int(f['address'], 16):08X}" for f in functions]
    if len(names) != len(set(names)):
        raise ValueError('Duplicate (overlay, address) in 1000-target manifest')
    if set(f['evidence'] for f in functions) - EXPECTED_EVIDENCE:
        raise ValueError('Unknown function-boundary evidence classification')

    # The published research C body is one line per function. This guard
    # deliberately fails if the source structure changes rather than silently
    # compiling an incomplete or ambiguous function.
    code_lines: dict[str, str] = {}
    for line in SOURCE.read_text(encoding='utf-8').splitlines():
        match = FUNC_RE.search(line)
        if not match:
            continue
        name = match.group(1)
        if name in code_lines or line.count('{') != 1 or line.count('}') != 1:
            raise ValueError(f'Ambiguous/non-single-line function: {name}')
        code_lines[name] = line
    if set(code_lines) != set(names):
        missing = sorted(set(names) - set(code_lines))[:8]
        extra = sorted(set(code_lines) - set(names))[:8]
        raise ValueError(f'Source/manifest mismatch: missing={missing}, extra={extra}')
    return functions, code_lines


def _read_cstr(buf: bytes, offset: int) -> str:
    if offset < 0 or offset >= len(buf):
        raise ValueError('String table name offset out of range')
    end = buf.find(b'\0', offset)
    if end < 0:
        raise ValueError('Unterminated ELF string')
    return buf[offset:end].decode('ascii', errors='replace')


def parse_arm_elf_symbols(data: bytes, wanted: set[str]) -> dict[str, dict]:
    """Return ELF32 LE function symbol code, size and relocation count.

    CodeWarrior emits relocatable ARM ELF32. Original verifier extracts code
    with ELF symbol sizes; this parser avoids requiring third-party Python
    modules just to read symbol and relocation tables.
    """
    if len(data) < 52 or data[:6] != b'\x7fELF\x01\x01':
        raise ValueError('Expected little-endian 32-bit ELF CodeWarrior object')
    (_ident, etype, machine, _ver, _entry, _phoff, shoff, _flags,
     _ehsize, _phentsize, _phnum, shentsize, shnum, _shstrndx) = struct.unpack_from(
        '<16sHHIIIIIHHHHHH', data, 0)
    if etype != 1 or machine != 40 or shentsize != 40:
        raise ValueError('Expected unlinked ARM ELF32 with standard section headers')
    if shoff < 52 or shoff + shnum * shentsize > len(data):
        raise ValueError('ELF section table out of file range')
    sh = [struct.unpack_from('<IIIIIIIIII', data, shoff + i * shentsize)
          for i in range(shnum)]

    def sec_data(idx: int) -> bytes:
        if idx >= len(sh):
            raise ValueError('ELF section index out of range')
        row = sh[idx]
        if row[1] == 8:  # SHT_NOBITS
            raise ValueError('Cannot read SHT_NOBITS section')
        off, size = row[4], row[5]
        if off + size > len(data):
            raise ValueError('ELF section extends past end of file')
        return data[off:off + size]

    relocations: dict[int, list[int]] = defaultdict(list)
    for sec in sh:
        if sec[1] not in (4, 9):  # SHT_RELA, SHT_REL
            continue
        target = sec[7]  # sh_info = target section index
        ent = sec[9] or (12 if sec[1] == 4 else 8)
        if ent < (12 if sec[1] == 4 else 8):
            raise ValueError('Truncated relocation entry size')
        off, size = sec[4], sec[5]
        if off + size > len(data) or size % ent != 0:
            raise ValueError('Corrupt ELF relocation table')
        for p in range(off, off + size, ent):
            relocations[target].append(struct.unpack_from('<I', data, p)[0])

    found: dict[str, dict] = {}
    for sec in sh:
        if sec[1] != 2:  # SHT_SYMTAB
            continue
        strtab = sec_data(sec[6])  # sh_link
        off, size = sec[4], sec[5]
        ent = sec[9] or 16
        if ent < 16 or size % ent or off + size > len(data):
            raise ValueError('Corrupt ELF symbol table')
        for p in range(off, off + size, ent):
            st_name, value, count, _info, _other, shndx = struct.unpack_from(
                '<IIIBBH', data, p)
            if st_name >= len(strtab):
                raise ValueError('ELF symbol name out of bounds')
            name = _read_cstr(strtab, st_name)
            if name not in wanted:
                continue
            if name in found:
                found[name] = {'error': 'duplicate_symbol'}
                continue
            if shndx == 0 or shndx >= len(sh):
                found[name] = {'error': 'undefined_or_special_symbol'}
                continue
            section = sh[shndx]
            start = value - section[3]  # ELF relocatable symbol offset
            try:
                blob = sec_data(shndx)
            except ValueError:
                found[name] = {'error': 'invalid_symbol_section'}
                continue
            if count == 0 or start < 0 or start + count > len(blob):
                found[name] = {'error': 'invalid_size_or_range'}
                continue
            rels = sum(start <= offset < start + count
                       for offset in relocations.get(shndx, []))
            result = {
                'size': count,
                'sha256': hashlib.sha256(blob[start:start + count]).hexdigest(),
                'relocations': rels,
            }
            found[name] = result
    return found


def compile_batch(lines: list[str], compiler: Path, wrapper: Path, tmp: Path,
                  number: int) -> tuple[dict[str, dict], str | None]:
    cfile = tmp / f'cw_batch_{number:03}.c'
    objdir = tmp / f'out_{number:03}'
    objdir.mkdir(exist_ok=True)
    # All functions use C built-in types; don't include modern stdint.h or
    # stddef.h, which the historical CodeWarrior headers might not provide.
    cfile.write_text('/* Standalone CodeWarrior matching probe. */\n' +
                     '\n'.join(lines) + '\n', encoding='ascii')
    wanted = set()
    for line in lines:
        match = FUNC_RE.search(line)
        if match:
            wanted.add(match.group(1))
    cmd = [str(wrapper), str(compiler), *CFLAGS,
           '-c', str(cfile), '-o', str(objdir)]
    try:
        p = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True,
                           errors='replace', timeout=180)
        if p.returncode:
            return {}, (p.stdout + '\n' + p.stderr).strip()[-4000:]
        objects = list(objdir.glob('*.o'))
        if len(objects) != 1:
            return {}, f'CodeWarrior produced {len(objects)} objects, expected 1'
        return parse_arm_elf_symbols(objects[0].read_bytes(), wanted), None
    except (ValueError, OSError, subprocess.SubprocessError) as exc:
        return {}, str(exc)


def check_one(f: dict, symbol: dict | None, error: str | None) -> dict:
    name = f"st_ov{f['overlay']:03}_{int(f['address'], 16):08X}"
    row = {
        'overlay': f['overlay'], 'address': f['address'], 'symbol': name,
        'evidence': f['evidence'],
        'function_boundary_unconfirmed': bool(f.get('separate_function_boundary_unconfirmed')),
        'expected_size': f['size_bytes'],
        'expected_sha256': f['original_span_sha256'],
    }
    if error:
        row.update(status='compiler_error',error=error)
    elif symbol is None:
        row['status'] = 'not_emitted_or_not_symbolized'
    elif 'error' in symbol:
        row['status'] = symbol['error']
    else:
        row['generated_size'] = symbol['size']
        row['generated_sha256'] = symbol['sha256']
        row['relocations'] = symbol['relocations']
        if symbol['relocations']:
            row['status'] = 'unverifiable_relocations'
        elif symbol['size'] != f['size_bytes']:
            row['status'] = 'different_size'
        elif symbol['sha256'] == f['original_span_sha256']:
            row['status'] = 'exact_codewarrior_standalone'
        else:
            row['status'] = 'different_instructions'
    return row


def main() -> int:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--compiler', type=Path, default=DEFAULT_COMPILER)
    p.add_argument('--wrapper', type=Path, default=DEFAULT_WRAPPER)
    p.add_argument('--out', type=Path, default=DEFAULT_REPORT)
    p.add_argument('--batch-size', type=int, default=100,
                   help='Functions compiled together per CodeWarrior object (default: 100)')
    a = p.parse_args()
    if os.name != 'nt':
        raise RuntimeError('Windows with the installed CodeWarrior .exe is required')
    if not 1 <= a.batch_size <= 250:
        raise ValueError('--batch-size must be from 1 to 250')
    compiler, wrapper = a.compiler.resolve(), a.wrapper.resolve()
    if not compiler.is_file() or not wrapper.is_file():
        raise FileNotFoundError(f'Missing CodeWarrior compiler or sjiswrap: {compiler}, {wrapper}')
    functions, ccode = load_inputs()
    results = []
    with tempfile.TemporaryDirectory(prefix='st_codewarrior_1000_') as d:
        tmp = Path(d)
        for off in range(0, len(functions), a.batch_size):
            batch = functions[off:off + a.batch_size]
            lines = [ccode[f"st_ov{f['overlay']:03}_{int(f['address'], 16):08X}"]
                     for f in batch]
            idx = (off // a.batch_size) + 1
            found, error = compile_batch(lines, compiler, wrapper, tmp, idx)
            for f in batch:
                name = f"st_ov{f['overlay']:03}_{int(f['address'], 16):08X}"
                results.append(check_one(f, found.get(name), error))
            done = len(results)
            exact = sum(x['status'] == 'exact_codewarrior_standalone' for x in results)
            print(f'Batch {idx:02}: tested {done:4}/1000; CodeWarrior exact so far {exact}', flush=True)
            if error:
                print(f'  WARNING batch {idx}: {error[-450:]}', file=sys.stderr, flush=True)

    totals = Counter(x['status'] for x in results)
    by_evidence: dict[str, Counter] = defaultdict(Counter)
    for x in results:
        by_evidence[x['evidence']][x['status']] += 1
    report = {
        'game': 'The Legend of Zelda: Spirit Tracks',
        'revision': 'EUR Rev 1',
        'source': str(SOURCE.relative_to(ROOT)),
        'manifest': str(MANIFEST.relative_to(ROOT)),
        'compiler': str(compiler),
        'flags': CFLAGS,
        'method': 'Standalone CodeWarrior C translation units, symbol bytes vs SHA256 original ROM spans',
        'limitations': 'CodeWarrior-exact code span does not prove independent function entrypoint or correct C++ signature, nor DS game integration. 677 starts lack strong boundary evidence.',
        'total_candidates': len(results),
        'counts': dict(sorted(totals.items())),
        'counts_by_evidence': {k: dict(sorted(v.items())) for k, v in sorted(by_evidence.items())},
        'functions': results,
    }
    a.out.parent.mkdir(parents=True, exist_ok=True)
    a.out.write_text(json.dumps(report, indent=2, ensure_ascii=True) + '\n', encoding='utf-8')
    print('\nCodeWarrior standalone exact:', totals['exact_codewarrior_standalone'], '/1000')
    print('Statuses:', dict(sorted(totals.items())))
    print('Results grouped by boundary evidence:')
    for evidence, statuses in sorted(by_evidence.items()):
        print(f'  {evidence}: {statuses["exact_codewarrior_standalone"]}/{sum(statuses.values())} exact')
    print('Report:', a.out.resolve())
    print('IMPORTANT: 677 code-span starts remain unconfirmed independent functions.')
    print('No normal DS build units or upstream objdiff results were changed.')
    return 0 if len(results) == 1000 else 1


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (OSError, RuntimeError, ValueError, subprocess.SubprocessError) as exc:
        print('FAIL:', exc, file=sys.stderr)
        raise SystemExit(1)
