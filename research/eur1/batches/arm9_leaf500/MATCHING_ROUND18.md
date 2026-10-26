# Spirit Tracks (EUR Rev1) — round 18/19 matching investigation

**25 October 2026.** Branch `decomp/eur1-100-new-bl-reconstructions-20261023b`, draft PR #15.

## Result: 52/500 Clang-exact unchanged, new evidence and ROM-local diagnostics

This round did **not** produce an additional byte-exact match. Unlike
standalone C compilation or plausible semantics, exact matching requires
the **whole Clang ARMv5TE -O2 function instruction byte stream** to agree
with the owner-ROM-derived reference SHA-256. The scripts do not change the
fifth-batch source files or manifest unless a true match is discovered and
promoted.

### Reproducible candidate searches performed

| Search | Distinct original functions | ARM C variants compiled | New exact matches |
| --- | ---: | ---: | ---: |
| `search_short_round18.py`: static globals, table-address calculations, short return expressions | 40 | 360 | **0** |
| `search_stores_round18.py`: nested pointers, reassignments and volatile C memory access | 221 | 3,536 | **0** |
| `search_high_bl_round19.py`: manually readable C for heavily called, equal-size functions | 13 | 56 | **0** |
| **New experiments in this round** | **Overlapping target sets** | **3,952** | **0** |

The CI workflow also continued to run the established comparison/bitwise
searches, all of which remained negative after the previous successful
round-16 promotion.

### Full-batch compiled mismatch audit

New source: `rank_mismatches_round18.py`.

Runs Clang on the **five actual existing C shards** (all 500 function
bodies) and validates every match status against the original EUR1
SHA-256 manifest. Runs without a Nintendo compiler or a ROM.

CI-confirmed baseline:

| Classification | Count |
| --- | ---: |
| Byte-exact standalone Clang ARMv5TE -O2 | **52** |
| Same generated size, different machine instructions | **122** |
| Different generated size | **326** |
| Total fifth-batch functions | **500** |

The ranking initially prioritizes the **122 equal-size functions** by
direct BL-call reference count and size delta. This is a heuristic, not
evidence of a source or semantic match.

Most referenced same-size candidates (from the verified CI report):

| Module | Address | ARM code size | Original BL references |
| --- | --- | ---: | ---: |
| Overlay 026 | `0x020FA8E0` | 28 | 71 |
| Main ARM9 | `0x0201E8D4` | 36 | 50 |
| Overlay 000 | `0x0208A7F0` | 40 | 26 |
| Overlay 000 | `0x0206678C` | 36 | 13 |
| Overlay 020 | `0x020C9430` | 24 | 12 |
| Overlay 092 | `0x0217A278` | 16 | 11 |
| Overlay 000 | `0x020669B4` | 24 | 10 |
| Overlay 031 | `0x020D8840` | 24 | 10 |
| Overlay 071 | `0x021530DC` | 36 | 10 |
| Main ARM9 | `0x0202CF08` | 40 | 9 |

The high-reference candidate source descriptions and C formulations are
included in `search_high_bl_round19.py`, but **none** are labeled as
matched or integrated in the actual game C++ sources.

## How to unblock ARM instruction-level matching without CodeWarrior

The owner already has an extracted EUR1 project on Windows. If the
decompressed original executable data is available locally (files
`arm9.bin`, `overlay_000.bin`, etc.), provide its *directory* to the
ranker. The tool checks the whole-file SHA-1 and function SHA-256 hashes
against the manifest before comparing original and Clang **ARM instruction
words at four-byte offsets**.

```powershell
cd C:\st

# ROM-free ranking, ready to use immediately:
python research/eur1/batches/arm9_leaf500/rank_mismatches_round18.py --limit 30

# Stronger check if your own verified decompressed EUR1 code files exist:
python research/eur1/batches/arm9_leaf500/rank_mismatches_round18.py --working-code "C:\path\to\working_code" --limit 30 --out build/eur1/mismatch_local_round18.json
```

The custom path above is an **example** and must be replaced by the
existing local directory containing those authentic code module files.
The optional local JSON then includes, for each mismatch:

- Exact machine instruction words which already match.
- The offsets and 32-bit ARM words for the first ten differences.
- A high-priority ranking based on actual instruction-word agreement,
  instead of just size and call count.

The original ROM or original machine bytes are **never uploaded to GitHub
by the script**. The optional local report may contain a handful of
original ARM instruction words: keep it local and do not commit it.

### Validation

GitHub Actions **PASS** — both all-pass Clang searching and complete
500-function mismatch audit:
https://github.com/zeranemesis/st/actions/runs/40189629010

## Interpretation

All 500 fifth-batch standalone C transcriptions still compile with
Clang ARMv5TE, and all previously validated 52 matches are preserved.
This is still **not** matching with original Nintendo CodeWarrior,
official DS objdiff, a game build, or a native PC port.

Further blind source-variant searches have poor yields. The most useful
next matching work is to use the **authenticated original ARM
instruction words** to identify precise register allocation, load/store
order, conditional-code and literal-pool differences for the 122 same-size
candidates. These original bytes exist only on the owner's local machine.
