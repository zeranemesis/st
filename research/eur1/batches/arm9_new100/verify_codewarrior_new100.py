#!/usr/bin/env python3
"""Check sixth batch 100 BL-backed ARM9 C reconstructions with CodeWarrior.

Runs on Windows using locally installed dsi/1.2p1 and sjiswrap. Functions
are compiled in standalone temporary C units; neither the DS build nor ROM
is modified. SHA-256 is compared to original ROM-derived manifest hashes.
This only tests compiler byte matching, *not* correctness of C semantics,
original C++ translation-unit ownership, or a native PC port.

--backend clang is solely a portable parser and report smoke test; results
from that mode must NEVER be presented as original CodeWarrior matching.
"""
from __future__ import annotations
import argparse
from collections import Counter,defaultdict
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import tempfile

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[3]
MANIFEST=HERE/'manifest_new100.json'
DEFAULT_REPORT=ROOT/'build/eur1/codewarrior_new100.json'
COMPILER=ROOT/'tools/mwccarm/dsi/1.2p1/mwccarm.exe'
WRAPPER=ROOT/'tools/sjiswrap.exe'
CW_FLAGS=[
 '-O4,p','-enum','int','-char','signed','-str','noreuse',
 '-proc','arm946e','-gccext,on','-fp','soft','-inline','noauto',
 '-lang','c','-Cpp_exceptions','off','-RTTI','off','-interworking',
 '-w','off','-sym','on','-gccinc','-nolink','-msgstyle','gcc','-ipa','file',
]
CLANG_FLAGS=['--target=armv5te-none-eabi','-march=armv5te','-marm',
 '-O2','-w','-ffreestanding','-fomit-frame-pointer','-ffunction-sections']
# Standalone sources use stdint.h. CodeWarrior dsi/1.2p1 predates C99 stdint.h.
LOCAL_TYPES='''typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned long long uint64_t;
typedef signed long long int64_t;
typedef unsigned int uintptr_t;
'''
# Byte/symbol parser is already maintained in the previous batch verifier.
sys.path.insert(0,str(HERE.parent/'overlay_candidates_1000'))
from verify_codewarrior_candidates_1000 import parse_arm_elf_symbols  # noqa: E402

FUNCTION_RE=re.compile(r'\b(st_(?:arm9|ov\d{3})_[0-9A-F]{8})\s*\([^;{}]*\)\s*\{')

def load_sources():
 """Extract full, balanced-brace function bodies from the five C shards."""
 blocks={}
 for number in range(1,3):
  path=HERE/f'arm9_new100_part{number}.c'
  code=path.read_text(encoding='utf-8')
  for m in FUNCTION_RE.finditer(code):
   name=m.group(1); start=code.rfind("\n",0,m.start())+1;pos=m.end()-1;depth=0
   for k in range(pos,len(code)):
    if code[k]=='{':depth+=1
    elif code[k]=='}':
     depth-=1
     if depth==0:
      block=code[start:k+1]
      if name in blocks:raise ValueError('Duplicate function: '+name)
      blocks[name]=block
      break
   else:raise ValueError('Unterminated function: '+name)
 return blocks

def name_of(item):
 mod=item['module']
 suffix='arm9' if mod=='arm9' else f'ov{int(mod):03d}'
 return f'st_{suffix}_{int(item["address"],16):08X}'

def compile_batch(rows,blocks,tmp,index,backend,compiler,wrapper):
 """Return (symbol records, error). Compile errors are isolated by recursion."""
 src=tmp/f'cw_new100_{index}.c';out=tmp/f'out_{index}'
 out.mkdir(exist_ok=True)
 names=[name_of(r) for r in rows]
 code=LOCAL_TYPES+'\n'+'\n\n'.join(blocks[n] for n in names)+'\n'
 src.write_text(code,encoding='ascii')
 if backend=='codewarrior':
  cmd=[str(wrapper),str(compiler),*CW_FLAGS,'-c',str(src),'-o',str(out)]
 else:
  target=out/'candidate.o'
  cmd=[str(compiler),*CLANG_FLAGS,'-c',str(src),'-o',str(target)]
 try:
  p=subprocess.run(cmd,cwd=ROOT,capture_output=True,text=True,errors='replace',timeout=180)
  if p.returncode:
   return {},(p.stdout+'\n'+p.stderr)[-2400:].strip()
  objects=list(out.glob('*.o'))
  if len(objects)!=1:return {},f'Expected one ELF object; got {len(objects)}'
  return parse_arm_elf_symbols(objects[0].read_bytes(),set(names)),None
 except (OSError,subprocess.SubprocessError,ValueError) as exc:
  return {},str(exc)

def check_one(item,record,error):
 row={k:item[k] for k in ('module','address','size_bytes','original_span_sha256','direct_BL_references','clang_standalone_status')}
 row['symbol']=name_of(item)
 if error:
  row['status']='compile_error';row['error']=error
 elif record is None:row['status']='missing_symbol'
 elif 'error' in record:row['status']=record['error']
 else:
  row['generated_size']=record['size'];row['generated_sha256']=record['sha256']
  row['relocations']=record['relocations']
  if record['relocations']:row['status']='unresolved_relocations'
  elif record['size']!=item['size_bytes']:row['status']='different_size'
  elif record['sha256']==item['original_span_sha256']:
   row['status']='exact_codewarrior_standalone' # renamed below when running smoke backend
  else:row['status']='different_instructions'
 return row

def main():
 ap=argparse.ArgumentParser(description=__doc__)
 ap.add_argument('--backend',choices=('codewarrior','clang'),default='codewarrior')
 ap.add_argument('--compiler',type=Path)
 ap.add_argument('--wrapper',type=Path,default=WRAPPER)
 ap.add_argument('--out',type=Path)
 ap.add_argument('--batch-size',type=int,default=25)
 ap.add_argument('--no-bisect',action='store_true',help='Do not split failed compilation batches')
 args=ap.parse_args()
 if not 1<=args.batch_size<=100:ap.error('--batch-size must be between 1 and 100')
 if args.backend=='codewarrior' and os.name!='nt':ap.error('CodeWarrior mode needs Windows')
 compiler=(args.compiler or (COMPILER if args.backend=='codewarrior' else Path('clang')))
 wrapper=args.wrapper
 if args.backend=='codewarrior' and (not compiler.is_file() or not wrapper.is_file()):
  ap.error(f'Missing CodeWarrior or sjiswrap at {compiler} / {wrapper}')
 manifest=json.loads(MANIFEST.read_text(encoding='utf-8'))
 functions=manifest['functions'];blocks=load_sources()
 if len(functions)!=100 or len(set(name_of(x) for x in functions))!=100:
  raise ValueError('Expected 100 unique function entries')
 if set(blocks)!=set(name_of(x) for x in functions):
  raise ValueError('Source and manifest symbols do not agree')
 outfile=args.out or (DEFAULT_REPORT if args.backend=='codewarrior' else ROOT/'build/eur1/clang_new100_smoke.json')
 results=[];idx=0
 with tempfile.TemporaryDirectory(prefix='st_codewarrior_new100_') as td:
  tmp=Path(td)
  def process(rows):
   nonlocal idx
   idx+=1
   found,error=compile_batch(rows,blocks,tmp,idx,args.backend,compiler,wrapper)
   if error and len(rows)>1 and not args.no_bisect:
    cut=len(rows)//2
    process(rows[:cut]);process(rows[cut:])
    return
   for f in rows:results.append(check_one(f,found.get(name_of(f)),error))
  for offset in range(0,100,args.batch_size):
   process(functions[offset:offset+args.batch_size])
   print(f'Checked {len(results)}/100 original code spans',flush=True)
 counts=Counter(r['status'] for r in results)
 if args.backend=='clang':
  for r in results:
   if r['status']=='exact_codewarrior_standalone':r['status']='exact_clang_smoke'
  counts=Counter(r['status'] for r in results)
 exact_key='exact_codewarrior_standalone' if args.backend=='codewarrior' else 'exact_clang_smoke'
 results.sort(key=lambda r:(str(r['module']),int(r['address'],16)))
 report={'game':'The Legend of Zelda: Spirit Tracks','revision':'EUR Rev 1',
  'backend':args.backend,'standalone_only':True,
  'compiler':str(compiler),'flags':CW_FLAGS if args.backend=='codewarrior' else CLANG_FLAGS,
  'functions_checked':len(results),'counts':dict(sorted(counts.items())),
  'warning':'Standalone matching does not verify C semantics, function C++ ownership or original game build integration; Remaining nonmatching C reconstructions require careful semantic and CFG review.',
  'functions':results}
 outfile.parent.mkdir(parents=True,exist_ok=True)
 outfile.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
 print(f'\n{args.backend} standalone byte-exact matches: {counts[exact_key]}/100')
 print('Other statuses:',dict(sorted(counts.items())))
 print('Report:',outfile.resolve())
 return 0 if len(results)==100 else 1

if __name__=='__main__':
 try:raise SystemExit(main())
 except (OSError,RuntimeError,ValueError,subprocess.SubprocessError) as exc:
  print('FAIL:',exc,file=sys.stderr);raise SystemExit(1)
