# Spirit Tracks EUR Rev 1 — 34 nouvelles fonctions C exactes, 66 cibles suivantes

## Résultat réellement vérifié (23 octobre 2026)

Ce lot apporte **34 nouvelles fonctions C** compilées **octet pour octet** avec Clang ARMv5TE `-O2`, représentant **536 octets** d'instructions ARM9 originales. Les 34 adresses ont été croisées avec les **symboles `kind:function(arm)` du dépôt** (13 ARM9 principal, 21 overlays) et possèdent au moins une référence d'appel direct `BL` dans leur module. Aucune adresse ne figure dans les cinq lots précédents (100 + 500 + 500 + 1000 + 500). La ROM d'origine, validée par SHA-1, reste exclusivement locale.

**66 autres adresses** possèdent elles aussi des références directes `BL` mais sont simplement **cataloguées comme cibles à décompiler**. Elles n'ont **pas encore de corps C restauré** et ne doivent pas être comptées comme des fonctions décompilées, validées ou matching.

| Mesure | Résultat |
| --- | ---: |
| Nouvelles adresses cibles | 100 |
| Fonctions C réellement reconstruites et Clang-exactes | **34** |
| Octets ARM9 reconstitués exactement | **536** |
| Fonctions C avec symbole `kind:function(arm)` dans le dépôt | **34** |
| Adresses `BL` en attente de vraie décompilation | **66** |
| Correspondances avec CodeWarrior original | **non testées** |
| Fonctions intégrées au vrai build du jeu DS | **0** |

Le C présent est une **reconstruction minimale compatible avec les instructions**, pas nécessairement la signature ou classe C++ originale. En particulier, les `volatile` reproduisent l'ordre de certaines écritures en mémoire ; leur présence n'établit pas qu'ils figuraient dans le code source Nintendo.

## Fichiers

- `recovered_exact_34.c` — les **34 définitions C complètes**, aucune ROM ni assembleur propriétaire intégré.
- `manifest_100_targets.json` — les 34 fonctions testées et les 66 autres points d'appel, avec adresses, tailles, décomptes d'appels et empreintes SHA-256 des octets originaux.
- `verify_exact_34.py` — compile les 34 fonctions avec Clang et compare octet pour octet avec les images `arm9.bin` / `overlay_NNN.bin` extraites de **ta propre ROM**, en vérifiant leurs empreintes.
- `verify_codewarrior_34.py` — analyse les 34 mêmes fonctions avec le **véritable CodeWarrior ARM dsi/1.2p1** installé sous Windows. Le résultat est toujours à mesurer.

## Refaire la comparaison locale avec Clang

Depuis la racine du dépôt, après avoir extrait ta ROM avec l'outil déjà présent dans `research/eur1/scripts/analyze_nds.py` :

```powershell
python research/eur1/batches/arm9_new34/verify_exact_34.py --working-code "C:\chemin\audit\working_code" --overlays-csv "C:\chemin\audit\reports\overlays.csv"
```

Résultat mesuré lors de la création : `Clang ARMv5TE standalone match: 34/34 C functions, 536 original bytes identical`.

## Vérification CodeWarrior Windows (prochaine action)

```powershell
cd C:\st
git pull --ff-only origin main
python research/eur1/batches/arm9_new34/verify_codewarrior_34.py
```

Rapport créé dans `build/eur1/codewarrior_new34.json`. **Ne pas annoncer 34 matchs CodeWarrior tant que le script n'est pas exécuté.** Le matching isolé ne compte pas dans les statistiques officielles `objdiff` tant que chaque fonction n'est pas intégrée dans son unité C++ d'origine.

Aucun port PC n'a été commencé.
