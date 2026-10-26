#!/usr/bin/env python3
"""Recover short EUR1 ARM instruction sequences from owner-ROM SHA256 fingerprints.

The input is the fifth500 original-code manifest containing whole-function
SHA256 hashes and the published C research translations (not ROM bytes).
For previously opcode-unmatched 12/16-byte functions, enumerate a small,
explicit ARMv5TE instruction grammar appropriate to leaf functions:
  (1) literal LDR + register AND + BX LR;
  (2) literal LDR + pointer LDR + BX LR;
  (3) literal LDR + MOV immediate + MLA + BX LR.

Only full SHA256 equality of all original ARM instruction bytes is a hit.
The output is a read-only decoding hypothesis about ORIGINAL INSTRUCTIONS,
not a Clang-C byte match, new game address, or playable decompilation.
No CodeWarrior, game binaries, direct asm implementation, or ROM upload.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
from collections import Counter

HERE=Path(__file__).resolve().parent
FILE=HERE/"manifest_fifth500.json"
FUNCTION=re.compile(r"^uint32_t (st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$",re.M)
BX_LR=0xE12FFF1E

def name_of(x):
    module="arm9" if x["module"]=="arm9" else f"ov{int(x['module']):03d}"
    return f"st_{module}_{int(x['address'],16):08X}"

def words_hash(words):
    return hashlib.sha256(struct.pack("<"+"I"*len(words),*words)).hexdigest()

def immediate_encodings(value):
    result=[]
    for rot in range(16):
        for bits in range(256):
            n=2*rot
            actual=bits if not n else ((bits>>n)|(bits<<(32-n)))&0xffffffff
            if actual==value:
                result.append((rot<<8)|bits)
    return result

def find_candidates_by_hash(records):
    wanted={r["original_span_sha256"] for r in records}
    found={}
    tested=Counter()

    def try_seq(family,words,features):
        digest=words_hash(words)
        tested[family]+=1
        if digest in wanted and digest not in found:
            found[digest]={
                "template":family,
                "instruction_word_hex_le_arm":[f"0x{w:08X}" for w in words],
                "instruction_bytes_hex":struct.pack("<"+"I"*len(words),*words).hex(),
                "instruction_stream_sha256":digest,
                "decoded_operand_roles":features,
                "caution":"Verified original instruction bytes from SHA256; NOT equivalent to Clang section/source-code matching",
            }

    # 12 bytes: literal LDR then load indirect or AND immediate-register,
    # followed by BX LR. Registers r0-r3 are common for short leaf ABI.
    for litreg in range(4):
        for displ in (0,4,8,12,16):
            lit=0xE59F0000|(litreg<<12)|displ
            for out in range(4):
                for base in range(4):
                    for indirect_off in (0,4,8):
                        ld=0xE5900000|(base<<16)|(out<<12)|indirect_off
                        try_seq("literal_ldrw_leaf",[lit,ld,BX_LR],
                                {"literal_register":litreg,"pc_literal_offset":displ,
                                 "load_base":base,"load_result":out,"load_offset":indirect_off})
                    for inputreg in range(4):
                        op=0xE0000000|(base<<16)|(out<<12)|inputreg
                        try_seq("literal_and_register_leaf",[lit,op,BX_LR],
                                {"literal_register":litreg,"pc_literal_offset":displ,
                                 "and_dest":out,"and_input":base,"and_operand":inputreg})

    # 16 bytes: LDR literal + MOV 8-bit rotated immediate + MLA
    # (multiply-add register) + BX LR. Values grounded in straight-line
    # published research source C's positive stride immediates.
    strides={6,12,16,20,24,28,32,44,60,96}
    for stride in strides:
        for enc in immediate_encodings(stride):
            for literal_reg in range(4):
                for off in (0,4,8,12,16):
                    literal=0xE59F0000|(literal_reg<<12)|off
                    for stride_reg in range(4):
                        mov=0xE3A00000|(stride_reg<<12)|enc
                        for out in range(4):
                            for first in range(4):
                                for second in range(4):
                                    for accum in range(4):
                                        # instruction encoding MLA Rd,Rm,Rs,Rn
                                        mla=0xE0200090|(out<<16)|(accum<<12)|(second<<8)|first
                                        try_seq("literal_mov_mla_leaf",[literal,mov,mla,BX_LR],
                                                {"stride":stride,"literal_register":literal_reg,
                                                 "pc_literal_offset":off,"stride_register":stride_reg,
                                                 "result_register":out,"multiply_regs":[first,second],
                                                 "accumulate_register":accum})
    # Four-instruction conditional leaf families. All branches are ARM
    # condition-coded instructions, NOT guessed source CFG boundaries.
    for cmpreg in range(4):
        cmp_zero=0xE3500000|(cmpreg<<16)
        for base in range(4):
            for dest in range(4):
                load_eq=0x05900000|(base<<16)|(dest<<12)|12
                load_ne=0x15900000|(base<<16)|(dest<<12)|16
                try_seq("conditional_field_select_leaf",
                        [cmp_zero,load_eq,load_ne,BX_LR],
                        {"compared_register":cmpreg,"base_register":base,
                         "output_register":dest,"field_offsets":[12,16]})
                for a,b in ((3,1),(1,3)):
                    mov_eq=0x03A00000|(dest<<12)|a
                    mov_ne=0x13A00000|(dest<<12)|b
                    try_seq("conditional_immediate_select_leaf",
                            [cmp_zero,mov_eq,mov_ne,BX_LR],
                            {"compared_register":cmpreg,"output_register":dest,
                             "equal_value":a,"non_equal_value":b})

    # CMP followed by signed-GT and signed-LE conditional SUB.
    for first in range(4):
        for second in range(4):
            compare=0xE1500000|(first<<16)|second
            for dst in range(4):
                subgt=0xC0400000|(first<<16)|(dst<<12)|second
                suble=0xD0400000|(second<<16)|(dst<<12)|first
                try_seq("signed_compare_absolute_difference_leaf",
                        [compare,subgt,suble,BX_LR],
                        {"compare":[first,second],"subtract_output":dst})

    # MOV #24 + MLA (pointer array index) + load word at offset 24.
    for stride_reg in range(4):
        mov=0xE3A00018|(stride_reg<<12)
        for dest in range(4):
            load=0xE5900018|(dest<<16)|(dest<<12)
            for x in range(4):
                for y in range(4):
                    for accumulate in range(4):
                        mla=0xE0200090|(dest<<16)|(accumulate<<12)|(y<<8)|x
                        try_seq("mov_mla_load_word_leaf",
                                [mov,mla,load,BX_LR],
                                {"stride":24,"stride_register":stride_reg,
                                 "multiply":[x,y],"accumulate":accumulate,
                                 "result_register":dest,"dereference_offset":24})

    # MUL, ADD #0x800, MOV ASR #12, BX LR (scaled fixed-point).
    for output in range(4):
        for factor0 in range(4):
            for factor1 in range(4):
                mul=0xE0000090|(output<<16)|(factor1<<8)|factor0
                for add_dst in range(4):
                    add=0xE2800000|(output<<16)|(add_dst<<12)|0xB02
                    for shift_dst in range(4):
                        asr=0xE1A00000|(shift_dst<<12)|(12<<7)|(2<<5)|add_dst
                        try_seq("mul_add_0x800_asr12_leaf",
                                [mul,add,asr,BX_LR],
                                {"multiply":[factor0,factor1],"mul_result":output,
                                 "add_result":add_dst,"shift_output":shift_dst})

    # LDRH [object+#110], literal base pointer, indexed LDR [base, index<<2].
    for object_reg in range(4):
        for idx_reg in range(4):
            off=110
            ldrh=0xE1D000B0|(object_reg<<16)|(idx_reg<<12)|((off>>4)<<8)|(off&15)
            for ptr_reg in range(4):
                literal=0xE59F0004|(ptr_reg<<12)
                for load_dst in range(4):
                    indexed=0xE7900000|(ptr_reg<<16)|(load_dst<<12)|(2<<7)|idx_reg
                    try_seq("ldrh_global_table_lookup_leaf",
                            [ldrh,literal,indexed,BX_LR],
                            {"object_register":object_reg,"index_register":idx_reg,
                             "literal_pointer_register":ptr_reg,
                             "destination_register":load_dst,"object_field_offset":110})

    return found,tested

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--out",type=Path,default=Path("build/eur1/recovered_short_arm_round30.json"))
    args=p.parse_args()
    manifest=json.loads(FILE.read_text(encoding="utf-8"))
    pending=[r for r in manifest["functions"]
             if r["size_bytes"] in (12,16)
             and r["clang_standalone_status"]!="exact_original_machine_bytes"
             and not r.get("clang_instruction_prefix_status")]
    if len(pending)<10:raise ValueError("Expected >=10 short unmatched functions")
    found,tested=find_candidates_by_hash(pending)

    # Verify every original candidate twice against the original-record hash
    # AND its original instruction span length. A digest collision cannot
    # pretend to be another code length.
    recovered=[]
    for r in pending:
        info=found.get(r["original_span_sha256"])
        if info is None or len(info["instruction_bytes_hex"])!=r["size_bytes"]*2:
            continue
        code=bytes.fromhex(info["instruction_bytes_hex"])
        if hashlib.sha256(code).hexdigest()!=r["original_span_sha256"]:
            raise ValueError("SHA mismatch of recovered original instruction stream")
        recovered.append({
            "symbol":name_of(r),"module":r["module"],"address":r["address"],
            "bytes":r["size_bytes"],"direct_BL_references":r["direct_BL_references"],
            "sha256":r["original_span_sha256"],
            **info,
        })
    recovered.sort(key=lambda x:x["symbol"])
    summary=manifest["summary"]
    report={
        "scope":"Existing fifth500 short functions ONLY; ROM-free constrained ARM instruction-hash search",
        "strict_Clang_full_section_matches_unchanged":summary["standalone_clang_exact"],
        "exact_opcode_spans_already_matched_by_Clang_unchanged":summary["standalone_clang_exact_original_instruction_spans_total"],
        "original_short_unmatched_examined":len(pending),
        "candidate_arm_sequences_hashed_by_family":dict(tested),
        "original_short_instruction_sequences_recovered":len(recovered),
        "not_promoted_to_Clang_matching":True,
        "original_streams":recovered,
    }
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_text(json.dumps(report,indent=2)+"\n",encoding="utf-8")
    print(f"PASS: {sum(tested.values())} SHA256-checked short ARM sequence hypotheses")
    print(f"EXACT_ORIGINAL_INSTRUCTIONS_RECOVERED: {len(recovered)} / {len(pending)} short original functions")
    for r in recovered:
        print(f"ORIGINAL_OPCODE: {r['symbol']} {r['bytes']}/{r['bytes']} original ARM bytes "
              f"{r['template']}, SHA256 verified (NOT new C match)")
    print(f"CURRENT_CLANG_MATCHES_UNCHANGED: {summary['standalone_clang_exact_original_instruction_spans_total']}/500")
    print("Report:",args.out)

if __name__=="__main__":
    main()
