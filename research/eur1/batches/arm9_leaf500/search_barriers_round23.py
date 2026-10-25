#!/usr/bin/env python3
"""Search compiler-only barrier placement for exact Spirit Tracks EUR1 ARM code.

Every candidate keeps the original low-level C operation order and emits a
small number of empty GCC-style asm compiler barriers on intermediate
register values. These have zero runtime ARM bytes, but can prevent LLVM
from deleting/combining original independent ARM operations.

Check either the complete original SHA256 section, or its entire ARM
instruction prefix with one verified pc-relative literal word. NO ROM,
Nintendo CodeWarrior or game build. This search makes no manifest edits.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import tempfile

from verify_fifth500 import FLAGS, elf32_sections
from audit_literal_pools_round20 import arm_pc_literal_references

HERE = Path(__file__).resolve().parent
FUNCTION = re.compile(r"^uint32_t (st_(?:arm9|ov\d{3})_[0-9A-F]{8})\([^\n]+$", re.M)
BEGIN = "unsigned Z=0,N=0,C=0,V=0;"
ENDING = re.compile(r"\s*return r0;\s*}\s*$")
REG_WRITE = re.compile(r"^(r(?:0|1|2|3|12))\s*=\s*(.*);$")
HEADER = "#include <stdint.h>\n"
BAR = '__asm__ __volatile__("" : "+r"({reg}));'

def symbol(x: dict) -> str:
    m = "arm9" if x["module"] == "arm9" else f"ov{int(x['module']):03d}"
    return f"st_{m}_{int(x['address'], 16):08X}"


def src_variants(body: str, name: str):
    if not ENDING.search(body):
        return []
    code = ENDING.sub("", body).strip()
    if any(w in code for w in ["if (", "uint64_t z", "uint32_t z", "goto", "switch", "for (", "while ("]):
        return []
    if "{" in code or "}" in code:
        return []
    statements = [x.strip() + ";" for x in code.split(";") if x.strip()]
    assignments = [(i, m.group(1)) for i, t in enumerate(statements)
                   if (m := REG_WRITE.fullmatch(t)) is not None]
    if not assignments:
        return []

    def build(select: set[int], mode: int):
        lines = []
        for i, statement in enumerate(statements):
            lines.append(statement)
            if i in select:
                target = next((reg for j, reg in assignments if j == i), None)
                if target is None:
                    continue
                lines.append(BAR.format(reg=target))
        return_flag = mode % 2 == 0
        signature = "uint32_t" if return_flag else "void"
        suffix = "\nreturn r0;" if return_flag else ""
        return f"{signature} {name}(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3) {{\nuint32_t r12=0;\n" + "\n".join(lines) + suffix + "\n}\n"

    variants = []
    # Try barriers at each of the first six original explicit assignments.
    for ix, (at, reg) in enumerate(assignments[:8]):
        for mode in range(2):
            variants.append((f"one{ix}_r{reg}_m{mode}", build({at}, mode)))
    # Try after two consecutive register-state assignments.
    for ix in range(min(len(assignments) - 1, 7)):
        for mode in range(2):
            variants.append((f"pair{ix}_m{mode}",
                             build({assignments[ix][0], assignments[ix+1][0]}, mode)))
    # Preserve all intermediate register data dependencies or the last ones.
    for typ, chosen in [
        ("all", {i for i, _ in assignments}),
        ("first", {assignments[0][0]}),
        ("last", {assignments[-1][0]}),
        ("last_two", {i for i, _ in assignments[-2:]}),
        ("all_but_last", {i for i, _ in assignments[:-1]}),
    ]:
        if chosen:
            for mode in range(2):
                variants.append((f"{typ}_m{mode}", build(chosen, mode)))
    # Extra variants keep original type but enforce volatile memory effects.
    for typ, chosen in [
        ("all_volatile", {i for i, _ in assignments}),
        ("last_volatile", {assignments[-1][0]}),
    ]:
        if chosen:
            for mode in range(2):
                code = build(chosen, mode)
                code = re.sub(r"\*\(\((u?int(?:8|16|32)_t)\s*\*\)",
                              r"*((volatile \1*)", code)
                variants.append((f"{typ}_m{mode}", code))
    return variants


def main() -> None:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--clang", default="clang")
    p.add_argument("--out", type=Path, default=Path("build/eur1/round23_barriers.json"))
    args = p.parse_args()
    m = json.loads((HERE / "manifest_fifth500.json").read_text(encoding="utf-8"))
    pending = {symbol(r):r for r in m["functions"]
               if r["clang_standalone_status"] != "exact_original_machine_bytes"
               and not r.get("clang_instruction_prefix_status")}
    all_code = []
    records = {}
    selected = set()
    for shard in range(1, 6):
        code = (HERE / f"arm9_leaf_500_part{shard}.c").read_text(encoding="utf-8")
        for match in FUNCTION.finditer(code):
            name = match[1]
            if name not in pending or BEGIN not in match[0]:
                continue
            body = match[0].split(BEGIN, 1)[1]
            emitted = src_variants(body, name)
            for j, (label, src) in enumerate(emitted):
                variant_symbol = f"{name}_barrier_v{j}"
                src = src.replace(f"{name}(", f"{variant_symbol}(", 1)
                records[variant_symbol] = (pending[name], label, src)
                all_code.append(src)
                selected.add(name)
    if len(selected) < 100 or len(records) < 1000:
        raise ValueError(f"Unexpectedly few generated candidates: {len(selected)} / {len(records)}")
    with tempfile.TemporaryDirectory(prefix="st_barrier_") as tmp:
        src = Path(tmp) / "candidate.c"
        obj = Path(tmp) / "candidate.o"
        src.write_text(HEADER + "\n".join(all_code), encoding="utf-8")
        proc = subprocess.run([args.clang, *FLAGS, "-c", str(src), "-o", str(obj)],
                              capture_output=True, text=True, timeout=180)
        if proc.returncode:
            raise RuntimeError("Clang compilation failed: " + proc.stderr[-5500:])
        sections = elf32_sections(obj.read_bytes())
    if len(sections) != len(records):
        raise ValueError(f"Missing function sections: {len(sections)} vs {len(records)}")

    exact = {}
    totals = {"strict":0, "prefix":0}
    for name, (record, label, source) in records.items():
        generated = sections[".text." + name]
        n = record["size_bytes"]
        if len(generated) == n and hashlib.sha256(generated).hexdigest() == record["original_span_sha256"]:
            level = "strict"
        elif (len(generated) == n + 4
              and hashlib.sha256(generated[:n]).hexdigest() == record["original_span_sha256"]
              and any(ref["literal_target_offset"] == n
                      for ref in arm_pc_literal_references(generated,n))):
            level = "prefix"
        else:
            continue
        totals[level] += 1
        original = name.rsplit("_barrier_v",1)[0]
        proposal = {
            "name":original, "module":record["module"], "address":record["address"],
            "original_size":n, "clang_size":len(generated),
            "level":level, "strategy":label,
            "source":source.replace(name + "(", original + "(", 1),
            "original_instruction_sha256":record["original_span_sha256"],
        }
        if (original not in exact or (level=="strict" and exact[original]["level"]!="strict")
            or len(source)<len(exact[original]["source"])):
            exact[original] = proposal
    ordered = sorted(exact.values(), key=lambda x: x["name"])
    report={
        "kind":"Empty compiler barrier insertion for readable low-level C ARMv5TE",
        "compiled_source_variants":len(records),
        "original_unmatched_tested":len(selected),
        "matching_variants":totals,
        "new_unique_matches":len(ordered),
        "strict_new":sum(x["level"]=="strict" for x in ordered),
        "opcode_prefix_new":sum(x["level"]=="prefix" for x in ordered),
        "matches":ordered,
        "baseline_strict":54,
        "baseline_additional_opcode_literal":45,
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(report, indent=2)+"\n", encoding="utf-8")
    print(f"PASS: {len(records)} ARM candidates across {len(selected)} previously nonmatching functions")
    print(f"NEW_EXACT: {len(ordered)} (strict={report['strict_new']}, opcode with literal={report['opcode_prefix_new']})")
    for r in ordered:
        print(f"NEW_MATCH: {r['name']} level={r['level']} {r['original_size']} ARM bytes {r['strategy']}")
    print("Report:",args.out)


if __name__ == "__main__":
    main()
