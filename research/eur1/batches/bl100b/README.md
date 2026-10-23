# Spirit Tracks (EUR Rev 1) - 100 additional BL-backed ARM9 C reconstructions

This batch was reconstructed from the owner's previously supplied **Spirit Tracks EUR Rev 1 (BKIP)** ROM (SHA-1 `dcb221a89acb894503a461c2c7d4cfdad9a06b68`). The original ROM, overlays, executable instructions and assets are **not** included.

## Results measured in this session

| Check | Result |
| --- | ---: |
| Distinct source functions written in `reconstructed_100.c` | **100** |
| Direct same-module ARM `BL` callsites found | **106** |
| ARM9 executable modules represented (main + overlays) | **33** |
| Original function spans checked | **1,648 bytes** |
| Full-source standalone Clang ARMv5TE byte-exact | **74 / 100** |
| Original bytes matching under Clang | **1,220 bytes** |
| C functions compiling, but not matching | **26 / 100** |
| Standalone CodeWarrior `dsi/1.2p1` matching | **Not tested** |
| Integrated game C++ / `objdiff` matches | **0 new measured** |
| Rebuilt game ROM or in-game validation | **Not tested** |

The 100 are unique `(module,address)` combinations and exclude already published standalone C bodies from earlier research batches (including the 34 exact functions in `arm9_new34`, and the immediately preceding `arm9_bl100` batch). One entry at `ov028:0x02142F84` was already a **queued address without C** in `arm9_new34`; its C body has now been provisionally reconstructed. A queued address is not equivalent to a previously decompiled function.

### What "74 exact" means

Each exact function was compiled as actual C code with Clang 17 targeting ARMv5TE, `-marm -O2 -ffreestanding -ffunction-sections -fomit-frame-pointer`. The ELF function section was compared **byte by byte** with the corresponding address/length of the locally extracted, SHA-1-verified ARM9 game image. These are **isolated Clang matches**, not claims about Nintendo's original C++ compiler or semantic ownership. Calls and original function boundaries have not been independently established beyond the observed direct `BL` references and short ARM return instruction.

The other 26 functions are labeled `P` for **provisional**. Their C code compiles but does not reproduce original ARM instructions. Its runtime semantics must not be considered authoritative without additional analysis.

All functions use provisional 32-bit register-oriented signatures; the exact original parameter types, classes, calling conventions, and game-source translation units remain unknown. Do not directly include these research units in the shipping DS/PC builds.

## Files

- `reconstructed_100.c`: all 100 complete short C routine bodies, labeled `E` (Clang exact) or `P` (provisional).
- `verify_100.py`: compile, load original function spans from *your own* locally extracted EUR1 images, verify module hashes and compare all 100 instruction sequences.
- `verify_result.json` is produced **locally**, not required to build the game or committed as executable data.

## Re-run verification on Windows

After extracting the EUR Rev 1 ROM using the repository's existing `research/eur1/scripts/analyze_nds.py`:

```powershell
cd C:\st
git fetch origin
git checkout decomp/eur1-100-new-bl-reconstructions-20261023b
python research/eur1/batches/bl100b/verify_100.py --working-code research/eur1/working_code --overlays-csv research/eur1/reports/overlays.csv
```

Use the appropriate local path if your `working_code` directory was generated elsewhere. The script requires Clang with an ARMv5TE target.

**Expected result:** `PASS 74/100 Clang byte-identical, 26 provisional`. The comparison was reproduced against the local original EUR1 images during creation.

### Next steps

1. Test each C implementation against the actual CodeWarrior `dsi/1.2p1` compiler on Windows.
2. Recover correct original C++ owners, exact function boundaries, ABI and symbol declarations.
3. Integrate only verified functions into their real `src/` object file and check with `ninja ... check_eur1` / `objdiff`.
4. Test a rebuilt ROM in a DS emulator before any native PC port.

**No change to the official decompilation percentage or PC-port playability can be claimed from this standalone research batch.**
