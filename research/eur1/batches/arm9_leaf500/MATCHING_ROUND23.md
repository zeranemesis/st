# Spirit Tracks EUR Rev1 — passe 23 : +48 nouvelles correspondances ARM

**Date : 25 octobre 2026.** Branche de recherche `decomp/eur1-100-new-bl-reconstructions-20261023b`, PR #15 en brouillon.

## Résultat vérifié sur les véritables fichiers C

La nouvelle recherche `search_barriers_round23.py` a compilé **5 552 variantes C** correspondant à **195 fonctions précédemment nonmatching** du cinquième lot EUR1.

Elle a trouvé **48 nouvelles adresses originales** dont l'empreinte SHA-256 correspond à tout le code ARM d'origine. Répartition :

- **23 correspondances strictes** : la section ELF Clang produite correspond en taille et en octets à l'intégralité de la référence originale.
- **25 correspondances supplémentaires d'instructions ARM** : tous les octets d'instructions originales correspondent, mais la section ELF Clang comporte une constante PC-relative de 4 octets, explicitement référencée par un `LDR` ARM.

Ces 48 sources ne sont pas de simples propositions laissées dans une recherche : les 48 anciennes traductions synthétiques ont été **remplacées dans les cinq vrais fichiers `arm9_leaf_500_part*.c`**, puis l'outil de recompilation indépendant et les tests GitHub Actions ont validé à nouveau toutes les entrées.

### Bilan

| Mesure sur ce lot de 500 | Avant | Après |
| --- | ---: | ---: |
| Sections Clang strictement byte-exact | 54 | **77** |
| Flux ARM exacts avec une constante Clang en plus | 45 | **70** |
| **Flux d'instructions ARM originaux byte-exact (total)** | **99** | **147** |
| Sans correspondance d'instructions ARM | 401 | **353** |
| Sections Clang complètes encore nonmatching | 446 | **423** |

Les **77 sections strictes** et les **70 correspondances de flux avec literal pool** restent deux catégories distinctes. Aucun de ces décomptes ne représente le pourcentage de décompilation de l'intégralité du jeu DS.

### Liste intégrale des 48 nouvelles fonctions

| Module | Adresse originale EUR1 | Instructions d'origine | Nature du matching | Variante C |
| --- | --- | ---: | --- | --- |
| ARM9 | `0x02003740` | 24 B | Instructions + 4 B literal | `one1_rr0_m1` |
| ARM9 | `0x0201E8D4` | 36 B | Section Clang intégrale | `all_volatile_m1` |
| ARM9 | `0x0201EAA0` | 20 B | Section Clang intégrale | `one2_rr0_m0` |
| ARM9 | `0x02020268` | 44 B | Instructions + 4 B literal | `last_volatile_m1` |
| overlay 000 | `0x020590E4` | 32 B | Instructions + 4 B literal | `last_volatile_m1` |
| overlay 000 | `0x02061D88` | 32 B | Section Clang intégrale | `one3_rr1_m0` |
| overlay 000 | `0x02061DB8` | 36 B | Section Clang intégrale | `one3_rr1_m0` |
| overlay 000 | `0x02068504` | 20 B | Section Clang intégrale | `pair1_m0` |
| overlay 000 | `0x020774B4` | 12 B | Instructions + 4 B literal | `one0_rr0_m0` |
| overlay 000 | `0x02079304` | 28 B | Instructions + 4 B literal | `last_volatile_m1` |
| overlay 000 | `0x020800B4` | 20 B | Instructions + 4 B literal | `one0_rr1_m0` |
| overlay 000 | `0x02088EEC` | 20 B | Section Clang intégrale | `one2_rr1_m0` |
| overlay 000 | `0x02089FC0` | 36 B | Section Clang intégrale | `all_volatile_m1` |
| overlay 000 | `0x02096B48` | 40 B | Section Clang intégrale | `all_volatile_m1` |
| overlay 018 | `0x020C4B98` | 40 B | Instructions + 4 B literal | `last_volatile_m1` |
| overlay 020 | `0x020C5DD0` | 12 B | Instructions + 4 B literal | `one0_rr0_m0` |
| overlay 020 | `0x020CC648` | 28 B | Instructions + 4 B literal | `one1_rr0_m1` |
| overlay 020 | `0x020CC9BC` | 48 B | Instructions + 4 B literal | `all_but_last_m0` |
| overlay 020 | `0x020CEB40` | 20 B | Instructions + 4 B literal | `one0_rr2_m1` |
| overlay 020 | `0x020CECD4` | 12 B | Instructions + 4 B literal | `one0_rr0_m0` |
| overlay 020 | `0x020D64B8` | 16 B | Instructions + 4 B literal | `one0_rr0_m0` |
| overlay 020 | `0x020D64CC` | 16 B | Instructions + 4 B literal | `one0_rr0_m0` |
| overlay 021 | `0x020FB684` | 28 B | Instructions + 4 B literal | `pair0_m1` |
| overlay 022 | `0x020EAFE4` | 16 B | Instructions + 4 B literal | `one0_rr1_m0` |
| overlay 022 | `0x020EDC28` | 36 B | Section Clang intégrale | `all_volatile_m1` |
| overlay 022 | `0x020EE020` | 20 B | Section Clang intégrale | `all_volatile_m1` |
| overlay 023 | `0x020EE1D0` | 24 B | Section Clang intégrale | `all_m1` |
| overlay 023 | `0x020F131C` | 12 B | Instructions + 4 B literal | `one0_rr0_m0` |
| overlay 025 | `0x020C596C` | 56 B | Section Clang intégrale | `all_volatile_m0` |
| overlay 025 | `0x020C59A4` | 36 B | Section Clang intégrale | `all_but_last_m0` |
| overlay 026 | `0x020EEB10` | 20 B | Section Clang intégrale | `one0_rr1_m1` |
| overlay 026 | `0x020EEB38` | 20 B | Section Clang intégrale | `one1_rr1_m1` |
| overlay 026 | `0x020F5030` | 32 B | Instructions + 4 B literal | `all_volatile_m1` |
| overlay 026 | `0x020F653C` | 12 B | Instructions + 4 B literal | `one0_rr1_m0` |
| overlay 026 | `0x0213179C` | 24 B | Instructions + 4 B literal | `one3_rr1_m1` |
| overlay 031 | `0x020DA70C` | 36 B | Section Clang intégrale | `all_volatile_m1` |
| overlay 031 | `0x020F23B0` | 28 B | Section Clang intégrale | `all_m1` |
| overlay 037 | `0x02120D94` | 12 B | Section Clang intégrale | `one0_rr0_m0` |
| overlay 050 | `0x02134AF0` | 16 B | Section Clang intégrale | `one1_rr1_m1` |
| overlay 055 | `0x0213ABAC` | 32 B | Section Clang intégrale | `last_volatile_m1` |
| overlay 070 | `0x02141A24` | 20 B | Instructions + 4 B literal | `one0_rr2_m1` |
| overlay 071 | `0x0215F974` | 20 B | Instructions + 4 B literal | `one0_rr2_m1` |
| overlay 075 | `0x021538F4` | 12 B | Section Clang intégrale | `one0_rr0_m0` |
| overlay 075 | `0x0215AEF8` | 24 B | Section Clang intégrale | `one1_rr3_m0` |
| overlay 083 | `0x02154124` | 24 B | Section Clang intégrale | `all_volatile_m1` |
| overlay 092 | `0x02177DD8` | 16 B | Instructions + 4 B literal | `one0_rr1_m0` |
| overlay 092 | `0x02178618` | 16 B | Instructions + 4 B literal | `one0_rr1_m0` |
| overlay 111 | `0x02184DEC` | 12 B | Instructions + 4 B literal | `one0_rr1_m0` |

La passe couvre **1196 octets de code ARM original** sur 48 fonctions nouvelles. Il ne s'agit pas de nouvelles adresses découvertes : toutes figuraient dans le manifeste de recherche.

### Méthode

La piste efficace consiste à conserver la sémantique exprimée par la traduction à registres ARM, tout en plaçant une **barrière de compilation vide** après certaines opérations intermédiaires :

```c
__asm__ __volatile__("" : "+r"(r0));
```

La barrière n'insère **aucun octet ARM** ; elle empêche parfois Clang `-O2` de fusionner deux opérations et l'oblige à retrouver l'ordre d'instructions observé dans le binaire. Les variantes de recherche utilisent aussi, quand nécessaire, des pointeurs mémoire `volatile`.

**Limites importantes :** `__asm__` est une extension compilateur, **pas du C ISO pur**. Certaines signatures ont `void` pour retrouver exactement l'ABI telle qu'elle apparaît dans la fonction ; les véritables signatures C++ originales restent à identifier. Ces correspondances ne certifient pas la sémantique des fonctions dans toutes les conditions d'exécution.

### Validation indépendante

- [Recherche Clang et empreintes SHA-256, 48 nouveaux matches — PASS](https://github.com/zeranemesis/st/actions/runs/40211364613).
- [Vérificateur complet des 500 fonctions, 77 strictes, 26 groupes de régression — PASS](https://github.com/zeranemesis/st/actions/runs/40211661108).
- [Audit des 500 fonctions, 70 pools de 4 octets contrôlés — PASS](https://github.com/zeranemesis/st/actions/runs/40211673225).
- [Recherche et contrôle des 423 autres sections nonmatching — PASS](https://github.com/zeranemesis/st/actions/runs/40211665641).

Sur les **423 sections nonmatching** restantes, le classement du compilateur contient **105 cas de taille identique mais d'instructions différentes** et **318 cas de taille différente**. Le groupe des 70 flux exacts avec literal pool reste inclus dans ces 423 sections.

### Reproduction sans ROM ni compilateur Nintendo

Depuis le dépôt, avec Python 3 et Clang ARMv5TE sur le PATH :

```sh
python3 research/eur1/batches/arm9_leaf500/verify_fifth500_romfree.py
python3 research/eur1/batches/arm9_leaf500/audit_literal_pools_round20.py
python3 research/eur1/batches/arm9_leaf500/search_barriers_round23.py
```

Le dernier script est une recherche **lecture seule**. Après la promotion des 48 fonctions, elles sont exclues de ses candidats nonmatching : il ne doit plus redéclarer les mêmes 48 comme nouvelles.

Ce travail ne teste toujours **ni le vrai compilateur Nintendo CodeWarrior**, ni `objdiff` sur l'unité de traduction C++ originale, ni la compilation du jeu DS, ni un port PC jouable.
