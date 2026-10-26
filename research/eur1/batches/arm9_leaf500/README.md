# Spirit Tracks (Europe Rev 1) — fifth research batch, 500 further ARM9 leaf functions

This fifth batch adds **500 new C function bodies at direct ARM BL call targets**, excluding all addresses in the previous research sets (100 + 500 + 500 + 1,000 code spans). The reconstructions use **low-level register-state C** for instruction-level traceability, not original Nintendo class names or types. Some are complete straight-line leaf functions; exact ownership/CFG in the game remains subject to audit.

## Verified results

- **500 distinct BL-referenced original ARM9 addresses**, each with at least one direct branch-and-link call recorded in the same module in the decompilation scan
- **500/500 C bodies compile with Clang ARMv5TE `-O2`**
- **500/500 original addresses and instruction-byte spans validated with SHA-256** against a user-owned dumped Nintendo DS EUR1 Rev 1 ROM (ROM SHA-1 `dcb221a89acb894503a461c2c7d4cfdad9a06b68`)
- **82/500 exact complete Clang ARM ELF function sections** (including 2 new round-25 source rewrites), plus 70 additional exact original ARM instruction spans with a one-word Clang literal pool; **418/500 Clang function sections compile but differ in full bytes**
- **474/500 reconstructed code spans at least 16 bytes**, compared to prior batches of mostly 4–12-byte returns
- **74 distinct ARM9 code modules** (ARM9 main and overlays); **15,092 original instruction bytes** represented
- **0 CodeWarrior checks and 0 integrated original DS source units** from this batch

**Important:** Compilability and algorithmic transcription do not guarantee behavior is correct. The **418 nonmatching C bodies are experimental, low-level translations** and have not been independently checked for runtime semantic equivalence. Do **not** count all 500 as matching/completed game functions. Their C++ owners, true signatures and full control-flow boundaries still need review. This is not a PC port.

## Contents

- `arm9_leaf_500_part1.c` ... `arm9_leaf_500_part5.c` — 100 C bodies each, names encode ARM9 module and original entry address
- `manifest_fifth500.json` — function provenance, direct-BL reference counts, SHA-256 originals, Clang byte-equality status and pending CodeWarrior status
- `verify_fifth500.py` — recompilation and original-ROM byte-provenance checks (fails on changed matching status)
- `local_validation.json` — reproducible local summary without distributing original ROM bytes

The file is **not** part of the production DS build. The original ROM, decompressed ARM9 modules and proprietary CodeWarrior compiler must not be committed to this repository.

## Reproduce byte checks

From the repository root on Windows/Linux/macOS, with Clang ARMv5TE available and your local ROM already extracted/decompressed:

```powershell
python research/eur1/batches/arm9_leaf500/verify_fifth500.py --working-code C:\path\to\your\working_code
```

The `working_code` directory must contain your local `arm9.bin` and the `overlay_NNN.bin` files referenced in the manifest. The verifier checks the original SHA-1 of each module, compares each original function-span SHA-256, compiles each of the five C files, and compares the generated ELF function sections against the original code bytes. **It does not claim CodeWarrior matching for this batch.**

## Subsequent decompilation steps

1. Validate the **418 nonmatching C bodies** with an independent ARM instruction interpreter or emulator and refine their C types/expressions with the original CodeWarrior compiler, starting with functions having the most same-overlay BL references.
2. Trace function boundaries/callers and recover true argument signatures and C++ structures.
3. Move confirmed functions to their correct original source files and use `ninja arm9_eur1 report_eur1 check_eur1`, `ninja changes_eur1`, and `objdiff` to establish actual decompilation progress.

This is research to make later native PC porting feasible; no native PC port was started.


## Original CodeWarrior verification tool (added 2026-10-23)

The new [`verify_codewarrior_fifth500.py`](verify_codewarrior_fifth500.py)
recompiles the 500 research C bodies using your Windows-installed
**CodeWarrior ARM dsi/1.2p1**, and compares ELF symbol bytes to the
original-code SHA256 fingerprints already stored in the manifest. It splits
failed batches automatically so one compiler error does not hide the other
functions' results. It leaves the Nintendo DS build and ROM untouched.

Run from `C:\st` in PowerShell:

```powershell
git pull --ff-only origin main
python research/eur1/batches/arm9_leaf500/verify_codewarrior_fifth500.py
```

Result: `C:\st\build\eur1\codewarrior_fifth500.json`.

For reproducibility, `--backend clang` runs only a Clang regression smoke
check. That mode has already been tested against all 500 C functions and
returned **26 exact, 145 different-instruction, and 329 different-size** results;
it is **not** an original CodeWarrior comparison. No CodeWarrior match count
has been observed for this fifth batch yet.

[Matching priorities and audit](CODEWARRIOR_NEXT_STEPS.md) includes a list
of ten high-call-count same-size mismatches. The separate
[`semantic_refactors_3.c`](semantic_refactors_3.c) contains three
human-readable C interpretations of ARM disassembly, **not verified matching
implementations or integrated game functions**.

## Seven newly matching typed C rewrites (2026-10-23)

The previous register-simulation bodies at seven existing addresses were replaced by readable C functions with typed, ordered memory writes. All seven produce **exact original instructions under Clang ARMv5TE**, revalidated against the owner's EUR Rev 1 ROM. See [the seven-function audit](MATCHING_REWRITES_7.md). The current round-25 baseline is **82 exact / 418 nonmatching**; the round-24 baseline was **80 exact / 420 nonmatching**; the round-23 baseline was **77 exact / 423 nonmatching**; the round-20 baseline was **54 exact / 446 nonmatching**, following two more source rewrites; the earlier round-16 baseline was **52 exact / 448 nonmatching**; the previous round-15 baseline was **48 exact / 452 nonmatching**. At the end of round 14 it was **34 exact / 466 nonmatching**. The earlier snapshot was **33 exact / 138 instruction-different / 329 size-different** before the new exact 0x020A6B70 replacement. The true CodeWarrior dsi/1.2p1 results, ABI/C++ ownership and official DS game build matching are **not established** by this Clang experiment.

## 25 October 2026 — 26-function readable-C round

[Round 14](MATCHING_ROUND14.md) adds **26 alternative C bodies for existing overlay-000 targets**, 26 sanitizer-backed host regression groups and a ROM-free full-batch SHA-256 audit. One function, **0x020A6B70**, is now byte-exact with standalone Clang ARMv5TE and was promoted into the original fifth-batch C shard. This changes the measured Clang baseline from **33/500 to 34/500**, with **466** nonmatching bodies. No CodeWarrior matching or full Nintendo DS rebuild is claimed.

## 25 October 2026 — round 15, fourteen additional exact C matches

[Round 15 matching report](MATCHING_ROUND15.md) documents **14 original ARM functions newly byte-matched under standalone Clang ARMv5TE**, found by comparing 848 typed source variants across 106 previously nonmatching addresses to full-length original SHA-256 hashes. All 14 readable C bodies have replaced the corresponding register-state source entries, including three ARM9 main executable functions. The entire **500-function set was recompiled and independently rehashed: 48/500 exact, 452/500 still nonmatching**. These are not yet original Nintendo compiler matches or integrated original game C++ source objects.

## 25 October 2026 — round 16 / 17 matching follow-up

[Matching round 16](MATCHING_ROUND16.md) adds **four SHA-256 byte-exact standalone Clang ARMv5TE** source rewrites (main ARM9, overlays 000, 019 and 071). The owner-ROM-reference based full-500 C rebuild confirms **52/500 byte-exact** (up from 48) and **448/500 still nonmatching**. Conditional, grouped-conditional, straight-line and ARM TST exploratory searches reported no further new matches after promotion. No original compiler or DS game/PC port integration is claimed.

## 25 October 2026 — rounds 18/19: targeted experiments and instruction-level diagnostics

[Matching investigation round 18](MATCHING_ROUND18.md) tests **3,952** additional standalone Clang ARMv5TE C variants across short functions, object mutations and 13 high-BL-reference typed-C reconstructions. **No new exact matches** were obtained: the verified baseline stays **52/500 exact, 448/500 nonmatching**. The newly added `rank_mismatches_round18.py` recompiles all 500 actual C shards and classifies mismatches into **122 identical-size/different-instruction** and **326 different-size** cases. It supports optional *local-only* authenticated EUR1 original ARM instruction-word comparisons, without using CodeWarrior or uploading the ROM.

## 25 October 2026 — round 20: two new actual Clang ARM byte-exact sources

[Matching round 20](MATCHING_ROUND20.md) promotes **overlay 000 `0x020A2B0C` (12/12 ARM bytes, pure C)** and **overlay 092 `0x0217A278` (16/16 bytes, C with a *compiler-only empty inline-assembly barrier*)** into the existing actual research C shards. Independent full-500 Clang ARMv5TE -O2 SHA-256 verification on GitHub Actions confirms **54 exact / 446 nonmatching**. The remaining nonmatching entries divide into **121 same-size/different-instruction** and **325 different-size**. Neither Nintendo CodeWarrior, official DS C++ objdiff, nor game functionality has been established.

## 25 October 2026 — round 21: literal-pool-aware exact ARM instruction audit

[Literal-pool audit round 21](MATCHING_LITERAL_POOLS_ROUND21.md) independently confirms **43 additional exact original ARM instruction streams** which were previously classified as nonmatching because Clang appended **one four-byte PC-relative literal pool word** to each emitted function section. For all 43, the full original *instruction* SHA-256 agrees with the leading Clang code bytes and a decoded ARM PC-relative `LDR` demonstrably references the appended constant. The two counters are intentionally separate: **54/500 strictly exact full Clang sections**, **43 additional original instruction spans with verified Clang literal-pool trailer**, giving **97/500 exact original ARM instruction byte spans**. The remaining **446 strict nonmatching full sections** remain nonmatching until full original pool/linker placement is established. No CodeWarrior or Nintendo DS object match is claimed.

## 25 October 2026 — round 22: two more source-backed opcode-span matches

[Round 22 matching report](MATCHING_ROUND22.md) describes **6,074 C variants across 366 previously unmatched original ARM functions**, with **two new exact original opcode spans**: overlay 020 `0x020D3780` (32/32 ARM bytes) and overlay 021 `0x02106B1C` (24/24). Their readable C implementations replace the prior register-state translations in the original fifth-batch source shard and are independently verified with a PC-relative reference to the one extra 4-byte Clang literal. The two independent counts are now **54/500 strictly full-section exact** plus **45 referenced-literal original instruction-span matches**, totaling **99/500 original instruction spans byte-exact**. **446** function sections remain nonmatching in the full-section metric; **401** functions still lack a matching original ARM instruction span. No proprietary original compiler or full DS rebuild has been used.

## 25 October 2026 — round 23: 48 source-backed ARM matches

[Matching round 23](MATCHING_ROUND23.md) promotes **48 previously nonmatching functions** after compiling **5,552** C source variants with empty, instruction-free compiler barriers (and, where necessary, volatile memory accesses). All five existing research C shards were updated. Independent GitHub Actions SHA-256 audits of the **500 actually published ARM functions** verify **23 new whole-section exact matches** plus **25 new original instruction-span exact matches with a separate PC-relative 4-byte literal**. Totals: **77/500 full Clang sections strictly byte-exact**, **70 additional opcode-exact referenced-literal cases**, **147/500 exact original ARM instruction streams**, **353 with unmatched original ARM instruction streams**. This is experimental standalone Clang matching, not Nintendo CodeWarrior, original game C++ integration, or a playable port.

## 26 October 2026 — round 24: conditional compiler-barrier C matching

[Matching round 24](MATCHING_ROUND24.md) finds **three additional original ARM functions with fully byte-exact Clang ELF sections**, from **43,460** source variants over **353 previously opcode-nonmatching functions**. The original functions at overlay 000 `0x02058FC4` (52 bytes), overlay 090 `0x021687BC` (24 bytes) and overlay 092 `0x02168B54` (20 bytes) now have matching actual C research bodies. GitHub Actions independently recompiles all 500 originals: **80 strict Clang sections**, **70 more exact original ARM instruction spans with a referenced four-byte Clang literal**, giving **150/500 exact original ARM opcode spans** and **350/500 opcode-nonmatching**. This experiment uses Clang extensions, not the original Nintendo compiler or a game rebuild.

## 26 October 2026 — round 25: nonadjacent empty compiler-barrier combinations

[Matching round 25](MATCHING_ROUND25.md) tests **13,924 Clang ARM variants** across 128 previously opcode-nonmatching unbranched C research functions. Two genuine **full-section SHA256-exact** ARM candidates were promoted from the original compiler output evidence to the actual `arm9_leaf_500_part1.c` and `part4.c`: overlay 000 `0x02072D08` (36 bytes), overlay 080 `0x0215A7AC` (48 bytes). GitHub Actions independently confirms **82/500 strict whole-function Clang ARM sections**, plus **70 separately exact ARM opcode spans with one referenced Clang literal**, totaling **152/500 original ARM instruction streams byte-exact**, with **348 opcode-unmatched** and **418 nonmatching whole Clang sections**. These Clang-specific register-optimization matches do not establish original CodeWarrior compilation, DS game reconstruction or a native PC port.
