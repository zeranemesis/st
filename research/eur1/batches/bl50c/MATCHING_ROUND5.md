# Matching round 5 — Spirit Tracks EUR Rev 1 (24 October 2026)

This research batch was compared locally against the owner's SHA-1-authenticated EUR Rev 1 (BKIP) executable overlays. The **whole 50-function C source was compiled together with Clang 17 ARMv5TE -O2** and compared byte-for-byte to the original code spans. Each original span was verified by its SHA-256.

| Metric | Before | After |
| --- | ---: | ---: |
| Matching standalone Clang functions | 24/50 | **28/50** |
| Identical original code bytes | 584 | **748** |
| Examined original code bytes | 1,528 | **1,528** |
| Nonmatching C reconstructions | 26 | **22** |
| CodeWarrior original Nintendo/objdiff matches confirmed | 0 | **0** |

## Four newly exact reconstructions
| Module | Address | Original bytes | Reconstruction |
| --- | --- | ---: | --- |
| overlay_000 | `0x0206F6AC` | 44 | Loop initializing six halfword fields; ARM register and memory-order constraints |
| overlay_022 | `0x020ED140` | 48 | Three-iteration initializer with an ARM immediate and exact loop ordering |
| overlay_026 | `0x02106B34` | 44 | Structure initializer using a compiler-generated `STM` plus word/byte/halfword stores |
| overlay_082 | `0x021567B8` | 28 | Object-field copy with compiler-generated `LDM` for two adjacent source words |

**Git blob SHA for the exact C file tested locally and committed:** `b28ae51e705256ccec071df0dd45afb6eec1460d`.

## Still nonmatching (22)
| Module | Address | Original span (bytes) |
| --- | --- | ---: |
| arm9 | `0x0200371C` | 36 |
| arm9 | `0x020131EC` | 40 |
| arm9 | `0x02014704` | 40 |
| arm9 | `0x0202694C` | 48 |
| arm9 | `0x0202CE2C` | 32 |
| overlay_003 | `0x020B7E2C` | 44 |
| overlay_007 | `0x020B7014` | 60 |
| overlay_017 | `0x020BD6F8` | 40 |
| overlay_026 | `0x020FC9C0` | 48 |
| overlay_026 | `0x0211E0F0` | 32 |
| overlay_030 | `0x0214D724` | 32 |
| overlay_030 | `0x0214D744` | 32 |
| overlay_038 | `0x0211988C` | 52 |
| overlay_070 | `0x0214B2A0` | 36 |
| overlay_090 | `0x02170E18` | 48 |
| overlay_092 | `0x0217A7E4` | 32 |
| overlay_000 | `0x02072FF0` | 20 |
| overlay_000 | `0x020816C4` | 20 |
| overlay_000 | `0x020816FC` | 20 |
| overlay_000 | `0x0207749C` | 24 |
| arm9 | `0x02028C4C` | 20 |
| arm9 | `0x02028C60` | 24 |

## Reproduce

```powershell
python research/eur1/batches/bl50c/verify_50.py --working-code C:\path\to\working_code --overlays-csv C:\path\to\overlays.csv
```

Expected: `PASS: 28 Clang-exact and 22 nonmatching functions; 50 source bodies`.

**Limitations:** isolated **Clang** ARMv5TE byte matches, **not** original Nintendo CodeWarrior `dsi/1.2p1`, DS `objdiff`, a rebuilt Nintendo DS ROM, or a native PC port. Some source bodies use empty GNU inline-assembly barriers, fixed register constraints and register clobbers which generate no machine instruction themselves. Source semantics, original function names, ABI, caller constraints and C++ owners are not fully verified. No game ROM, extracted executable or original copyrighted assets are committed. Do not change matching manifest status without reproducing a byte-identical whole-source build.
