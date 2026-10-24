# Spirit Tracks — Matching round 8 (EUR Rev 1, 24 octobre 2026)

**Résultat : aucune nouvelle fonction byte-exacte.** 30/50 fonctions Clang ARMv5TE, 848/1 528 octets identiques, 20 fonctions restantes.

**Ce tour :** 1 443 variantes C supplémentaires compilées et comparées dans quatre campagnes ; aucune correspondance intégrale supplémentaire. Les résultats des campagnes sont conservés dans l’archive de travail locale, non sur GitHub. Les 569 essais de la passe précédente sont distincts. Toutes les images de code proviennent exclusivement de la ROM EUR Rev 1 fournie par le propriétaire.

## Diagnostic automatisé de la source actuelle

`diagnose_unmatched.py` recompile les 50 fonctions, authentifie chaque module original par SHA-1 et chaque fonction par SHA-256, puis mesure les écarts par mots ARM de 4 octets ; aucune instruction originale n’est incluse dans le rapport JSON par défaut.

| Module | Adresse | Taille originale | Taille compilée | Mots alignés identiques |
|---|---|---:|---:|---:|
| arm9 | `0x020131EC` | 40 | 36 | 4/9 |
| overlay_000 | `0x02072FF0` | 20 | 20 | 3/5 |
| arm9 | `0x02014704` | 40 | 40 | 2/10 |
| overlay_070 | `0x0214B2A0` | 36 | 48 | 2/9 |
| overlay_000 | `0x020816C4` | 20 | 24 | 1/5 |
| overlay_000 | `0x020816FC` | 20 | 24 | 1/5 |
| arm9 | `0x0202CE2C` | 32 | 28 | 1/7 |
| overlay_092 | `0x0217A7E4` | 32 | 44 | 1/8 |
| arm9 | `0x02028C60` | 24 | 40 | 1/6 |
| overlay_000 | `0x0207749C` | 24 | 28 | 0/6 |
| overlay_026 | `0x0211E0F0` | 32 | 28 | 0/7 |
| overlay_030 | `0x0214D724` | 32 | 28 | 0/7 |
| overlay_030 | `0x0214D744` | 32 | 28 | 0/7 |
| arm9 | `0x0200371C` | 36 | 40 | 0/9 |
| arm9 | `0x0202694C` | 48 | 44 | 0/11 |
| overlay_090 | `0x02170E18` | 48 | 52 | 0/12 |
| overlay_038 | `0x0211988C` | 52 | 48 | 0/12 |
| arm9 | `0x02028C4C` | 20 | 36 | 0/5 |
| overlay_003 | `0x020B7E2C` | 44 | 84 | 0/11 |
| overlay_026 | `0x020FC9C0` | 48 | 100 | 0/12 |

**Attention :** « mots alignés identiques » n’est pas un taux de matching de fonctions et ne prouve ni équivalence sémantique, ni validité des frontières de fonction. Les différences peuvent être provoquées par la disposition des littéraux, des branches et des allocations de registres.

## Obstacles principaux
- ARM9 `0x020131EC` : Clang crée la constante d’adresse du registre matériel avec MOV/ORR, là où le binaire utilise un literal pool LDR ; la sémantique de polling ne doit pas être altérée.
- overlay 000 `0x02072FF0` : Clang fusionne calcul d’adresse et écriture halfword ; il faut préserver LSL suivi de STRH indexé, sans recopier de l’assembleur ARM brut.
- ARM9 `0x02014704` : une des meilleures variantes historiques reproduisait 9/10 instructions mais déplaçait le CMP avant/après l’initialisation ; pas un match complet.
- overlay 000 `0x020816C4` / `0x020816FC` : TST/MOVEQ contre ANDS/MOVNE et allocations de registres.
- ARM9 `0x02028C4C` / `0x02028C60` : instructions ARM de copie/remplissage utilisant des LDM/STM à incrément post-fixé ; code Clang autonome différent.

## Travail possible avec CodeWarrior
- Retrouver les signatures C++ d’origine et leurs flags de compilation dans `config/eur1` et `src/`.
- Compiler avec le vrai `mwccarm dsi/1.2p1` de la configuration du projet puis vérifier avec `objdiff` et le build DS.
- Ne marquer `clang_byte_exact` ou un statut de matching CodeWarrior qu’après comparaison binaire complète du corps de fonction.

**Les 20 fonctions n’ont pas été transformées en matchs.** La base de la PR conserve 30/50, et le vérificateur reste inchangé. Aucun binaire de ROM, bytecode original ou ressource propriétaire n’a été publié.