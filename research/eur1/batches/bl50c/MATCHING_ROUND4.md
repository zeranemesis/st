# Matching round 4 — four verified ARMv5TE source reconstructions

**Game:** The Legend of Zelda: Spirit Tracks — EUR Rev 1 (BKIP). All original ARM code comes from the owner's locally extracted ROM and is not published here.

## Verified local results

| Metric | Previous | Current | Delta |
|---|---:|---:|---:|
| Clang ARMv5TE byte-identical bodies | 20 / 50 | **24 / 50** | **+4** |
| Matched original ARM bytes | 448 | **584** | **+136** |
| Original ARM code bytes inspected | 1,528 | **1,528** | — |
| Still nonmatching | 30 | **26** | −4 |
| Nintendo CodeWarrior/DS objdiff exact | 0 confirmed | **0 confirmed** | — |

### Four new byte-identical routines

- **ARM9 `0x020092CC`** (32 bytes): three-word initialization loop, `0xFFFFFFFF`, C loop with explicit signed bound and fixed register allocation.
- **Overlay 026 `0x020EA81C`** (36 bytes): eight-word zero initialization plus final field reset, loop retained with an empty compiler barrier.
- **Overlay 026 `0x020F169C`** (32 bytes): five-word initialization to `0x00400000`, fixed register allocation to prevent compiler unrolling.
- **Overlay 026 `0x0211F1CC`** (36 bytes): three-pointer traversal with conditional byte write. An empty GNU asm input constraint enforces pointer load before incrementing the loop counter.

The complete 50-function C file was compiled with **Clang 17 ARMv5TE `-O2`** and all emitted per-function ELF text sections compared with SHA-1 authenticated original executable modules and SHA-256 authenticated function spans. The complete run reported **PASS: 24 Clang-exact and 26 nonmatching**.

### Important limits and reproducibility

These four reconstructions are **C that produces original ARM instruction bytes under Clang**, not a verified match with the original Nintendo CodeWarrior `dsi/1.2p1`. Empty GNU `asm volatile("")` directives constrain register allocation/ordering but emit no original ARM opcodes; they are not portable to Nintendo CodeWarrior without further work. Function signatures, source class ownership and input preconditions must still be recovered.

Verified source Git blob: `29ec6ec3eef3b391e423343f26eb267a1e78288e`.

```powershell
python research/eur1/batches/bl50c/verify_50.py --working-code C:\YOUR_PATH\working_code --overlays-csv C:\YOUR_PATH\overlays.csv
```

No original Nintendo ROM/overlay bytes or game assets are present, no `src/` production files are modified, and the native PC port is not claimed playable.
