# Spirit Tracks EUR Rev 1 — matching round 6, October 24 2026

## Result verified on original EUR1 (BKIP) owner-supplied ROM

Clang 17 standalone ARMv5TE compilation of the **complete 50-function C unit** against
the SHA-1-authenticated ARM9/overlay executable images (each original span SHA-256 checked)
now yields **30 exact functions / 50** and **848 exact machine-code bytes / 1,528 studied**.
The prior result was 28/50 and 748 bytes; this is **+2 functions / +100 bytes**.

### Two new Clang byte-identical C reconstructions

| Executable module | Address | Size | Improvement |
|---|---|---:|---|
| overlay_007 | `0x020B7014` | 60 | Preserved three independent literal addresses and object-initialization register ordering |
| overlay_017 | `0x020BD6F8` | 40 | Preserved the result accumulator in r2 until the unique return path |

Both were compiled and compared in the whole 50-function translation unit.
Published source Git blob SHA: `8f97e16ccc2291efed74cabc65b07f19ffd69c8f`,
identical to the locally validated source.

## Remaining 20 functions (NOT matching)

The following C functions still fail the original-instruction byte comparison.
Descriptions are **code generation mismatch categories**, not claims of semantic verification.

| Module | Address | Original size | Current obstacle |
|---|---|---:|---|
| arm9 | `0x0200371C` | 36 | booléen / ordre d'initialisation et d'écriture |
| arm9 | `0x020131EC` | 40 | attente matérielle / placement du littéral d'adresse |
| arm9 | `0x02014704` | 40 | validation de signature / allocation des registres |
| arm9 | `0x0202694C` | 48 | liste chaînée / séparation des branches et pointeurs |
| arm9 | `0x0202CE2C` | 32 | validation d'arguments / instructions conditionnelles |
| overlay_003 | `0x020B7E2C` | 44 | borne signée / sélection conditionnelle |
| overlay_026 | `0x020FC9C0` | 48 | réduction d'état / comparaison signée |
| overlay_026 | `0x0211E0F0` | 32 | test de masque / TST contre AND et extraction |
| overlay_030 | `0x0214D724` | 32 | test de masque / TST contre AND |
| overlay_030 | `0x0214D744` | 32 | test de masque / TST contre AND |
| overlay_038 | `0x0211988C` | 52 | parcours de liste / fusion de branchements |
| overlay_070 | `0x0214B2A0` | 36 | comparaisons en cascade / CLZ ajouté |
| overlay_090 | `0x02170E18` | 48 | comparaison signed <= 1 / sortie unique |
| overlay_092 | `0x0217A7E4` | 32 | stockage STM / initialisation zéro anticipée |
| overlay_000 | `0x02072FF0` | 20 | adressage STRH indexé / ADD+STRH |
| overlay_000 | `0x020816C4` | 20 | TST registre décalé / ANDS+MOVEQ |
| overlay_000 | `0x020816FC` | 20 | TST registre décalé / ANDS+MOVEQ |
| overlay_000 | `0x0207749C` | 24 | chargements conditionnels / optimisation des deux branches |
| arm9 | `0x02028C4C` | 20 | STMLT auto-incrémenté / boucle vectorisée autrement |
| arm9 | `0x02028C60` | 24 | LDMLT/STMLT auto-incrémentés / deux instructions séparées |

### Work actually tested and rejected this pass

- Tested bit-mask-return variants for overlay 026, overlay 030 and overlay 000.
  The original uses condition flags and `MOVcc`; Clang continues to choose
  shifted extraction (`ANDS`) or adds/changes instructions. **No new matches.**
- Tested indexed halfword store `overlay_000:0x02072FF0`.
  Clang emits `ADD` followed by `STRH` instead of one register-indexed `STRH`.
- Tested field pair/conditional-counter update `overlay_092:0x0217A7E4`.
  Clang can reproduce the original ARM `STM` but not yet the exact surrounding
  `LDREQ/ADDEQ/MOVNE` sequence; **not counted as matching**.
- Tested list traversal, signed clamp and mode-switch variants.
  Conditional flow is altered by Clang at `-O2`, so these remain provisional.
- No ARM executable machine instructions from the proprietary ROM are hard-coded
  into the research C source to force superficial byte equality.

### Reproduce

```powershell
python research/eur1/batches/bl50c/verify_50.py --working-code C:\path\to\working_code --overlays-csv C:\path\to\overlays.csv
```

Expected:
`PASS: 30 Clang-exact and 20 nonmatching functions; 50 source bodies`.

**Scope:** these matches are isolated **Clang ARMv5TE**, not original Nintendo
CodeWarrior `dsi/1.2p1`, `objdiff`, official decomp completion, DS rebuild, or
PC-port gameplay validation. Empty GNU compiler barriers/register constraints
control Clang code generation and are not portable original Nintendo C++ sources.
