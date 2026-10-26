#!/usr/bin/env python3
"""Host semantic regression checks for round30 readable Spirit Tracks EUR1 C.

The real fifth500 source shards are compiled and linked as ordinary host C,
then eight address-stride helpers, a 10-bit mask, signed comparison,
conditional constant selection and fixed-point arithmetic are executed on
boundary inputs. Nintendo DS fixed-address memory dereferences are NOT
executed on the host.
This checks arithmetic C behavior, NOT original game execution and NOT a
Clang ARM instruction SHA256 match. The latter is a distinct CI audit.
"""
from __future__ import annotations

import argparse
from pathlib import Path
import subprocess
import tempfile

HERE = Path(__file__).resolve().parent
VALUES = (0, 1, 2, 7, 255, 0x10000, 0x7FFFFFFF, 0xFFFFFFFF)

# Existing original function address, game-address base, struct stride.
OPERATIONS = (
    ("st_ov000_0208AED0", 0x020ACE0C, 6),
    ("st_ov000_020A7880", 0x020AF7D4, 28),
    ("st_ov020_020C70BC", 0x020DF5E4, 28),
    ("st_ov021_020EA8A8", 0x02106C9C, 24),
    ("st_ov026_02102A54", 0x0213628C, 96),
    ("st_ov026_02108340", 0x02133350, 44),
    ("st_ov026_02108354", 0x021333D4, 12),
    ("st_ov071_02150D80", 0x02163B90, 24),
)


def main() -> None:
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--cc",default="clang")
    args=ap.parse_args()
    names=[x[0] for x in OPERATIONS]+["st_ov000_0206D32C", "st_ov026_020EB284", "st_ov026_020F903C", "st_ov093_021753BC"]
    lines=[
        "#include <stdint.h>",
        "#include <stdio.h>",
        "#include <stdlib.h>",
        *[f"extern uint32_t {n}(uint32_t, uint32_t, uint32_t, uint32_t);" for n in names],
        "int main(void) {",
        "uint32_t values[] = {"+",".join(hex(x)+"u" for x in VALUES)+"};",
        "unsigned checks=0;",
    ]
    for name,base,stride in OPERATIONS:
        lines.extend([
            f'for (unsigned i=0;i<sizeof(values)/sizeof(values[0]);i++) {{',
            f'  uint32_t got={name}(values[i],0xA5A5u,0xDEADu,0xBEEFu);',
            f'  uint32_t expected=0x{base:08X}u+{stride}u*values[i];',
            f'  if(got!=expected){{fprintf(stderr,"{name} index %u: %08x != %08x\\n",i,got,expected);return 1;}}',
            '  checks++;',
            '}',
        ])
    lines.extend([
        'for (unsigned i=0;i<sizeof(values)/sizeof(values[0]);i++) {',
        '  uint32_t expected=values[i]&0x3FFu;',
        '  uint32_t got=st_ov000_0206D32C(values[i],0xA5u,0xFFu,0x99u);',
        '  if(got!=expected){fprintf(stderr,"mask error %u\\n",i);return 1;}',
        '  checks++;',
        '}',
        'for (unsigned i=0;i<sizeof(values)/sizeof(values[0]);i++) {',
        '  uint32_t value=values[i];',
        '  uint32_t got=st_ov026_020F903C(value,0,0,0);',
        '  uint32_t expected=value==0u ? 3u : 1u;',
        '  if(got!=expected){fprintf(stderr,"conditional immediate error %u\\n",i);return 1;}',
        '  checks++;',
        '}',
        'for (unsigned i=0;i<sizeof(values)/sizeof(values[0]);i++) {',
        '  for (unsigned j=0;j<sizeof(values)/sizeof(values[0]);j++) {',
        '    uint32_t a=values[i],b=values[j];',
        '    uint32_t expected=(int32_t)a>(int32_t)b ? a-b : b-a;',
        '    uint32_t got=st_ov026_020EB284(a,b,0,0);',
        '    if(got!=expected){fprintf(stderr,"signed difference error %u %u\\n",i,j);return 1;}',
        '    checks++;',
        '  }',
        '}',
        'for (unsigned i=0;i<sizeof(values)/sizeof(values[0]);i++) {',
        '  for (unsigned j=0;j<sizeof(values)/sizeof(values[0]);j++) {',
        '    uint32_t fixed=values[i]*values[j]+0x800u;',
        '    uint32_t expected=(uint32_t)((int32_t)fixed>>12);',
        '    uint32_t got=st_ov093_021753BC(values[i],values[j],0,0);',
        '    if(got!=expected){fprintf(stderr,"fixed point error %u %u\\n",i,j);return 1;}',
        '    checks++;',
        '  }',
        '}',
        'printf("PASS: %u host test cases across 12 genuine research C functions (8 strides, mask, compare, selector, fixed-point)\\n",checks);',
        'return 0;',
        '}',
    ])
    if len(OPERATIONS)!=8 or len(names)!=12:
        raise ValueError("Round30 host validation set was accidentally modified")
    with tempfile.TemporaryDirectory(prefix="st_round30_host_") as tmp:
        harness=Path(tmp)/"harness.c"
        binary=Path(tmp)/"round30_host"
        harness.write_text("\n".join(lines)+"\n",encoding="utf-8")
        cmd=[args.cc,"-std=gnu11","-O2","-w",
             *[str(HERE/f"arm9_leaf_500_part{i}.c") for i in range(1,6)],
             str(harness),"-o",str(binary)]
        built=subprocess.run(cmd,capture_output=True,text=True,timeout=150)
        if built.returncode:
            raise RuntimeError("Host Clang compile/link failed: "+built.stderr[-4000:])
        run=subprocess.run([str(binary)],capture_output=True,text=True,timeout=20)
        if run.returncode:
            raise RuntimeError("Host semantic check failed: "+run.stderr[-4000:])
        print(run.stdout.strip())
    print("Four DS-address memory access routines are intentionally not executed on the host.")
    print("This host test does not establish original DS gameplay semantics.")


if __name__=="__main__":
    main()
