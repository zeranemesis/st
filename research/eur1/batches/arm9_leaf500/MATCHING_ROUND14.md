# Spirit Tracks EUR1 — passe 14 (25 octobre 2026)

## Résultat réellement vérifié : 26 fonctions C reconstruites, +1 matching Clang

Cette passe ne dépend pas de CodeWarrior. Elle reprend **26 fonctions ARM
de l'overlay 000 qui avaient déjà une transcription C à registres**, pour
leur donner une version C lisible et testable. Ce ne sont **pas 26 nouvelles
adresses découvertes** ni 26 nouvelles fonctions intégrées au C++ du jeu.

### Fichiers publiés

- `semantic_candidates_round14.c` : 26 reconstructions C autonomes
  utilisant des paramètres nommés, des accès mémoire explicites et des
  expressions lisibles ; l'ordre d'écriture original est préservé.
- `test_semantic_round14.c` : **26 groupes de tests**, avec variantes,
  sentinelles, valeurs limites, masques ARM, pointeurs et états signés.
  Compilation et exécution Clang hôte avec ASan/UBSan : **PASS**.
- `verify_semantic_round14.py` : compile les **26 fonctions ARMv5TE -O2**
  et compare la totalité des octets compilés à leur empreinte SHA-256 du
  manifeste EUR Rev1 : **1/26 strictement identique**, 25 autres candidats.
- `verify_fifth500_romfree.py` : recompile **les cinq vrais fichiers C
  historiques**, compare l'intégralité des 500 sections ARM à leurs SHA-256
  d'origine, vérifie que le manifeste reflète exactement les résultats.
  Résultat : **34/500 exacts**, contre 33/500 avant cette passe.
- `.github/workflows/research-eur1-round14.yml` : tous ces contrôles
  automatisés sur GitHub Actions.

### Cibles travaillées

| Famille | Adresses de fonctions originales (overlay 000) | Nb |
| --- | --- | ---: |
| Calculs, masques et adresses de tables | `0205AED0`, `02068504`, `0206AEB4`, `0206D32C`, `0208AED0`, `020A7880` | 6 |
| Structures, réinitialisations et sentinelles | `0205D500`, `0206AF94`, `02070138`, `02079304`, `0207995C`, `02089FC0`, `02096C7C`, `020A6B70` | 8 |
| Tests de champs et comparaisons | `020712B4`, `020771D0`, `02078EA0`, `02089FE4`, `020A3950`, `020A44D0`, `020A4B40` | 7 |
| Gestion de bits, compteur et stockage | `020816A0`, `020816D8`, `0208E770`, `020A2B0C`, `020A7764` | 5 |
| **Total** | | **26** |

Les champs ont des noms *proposés*, issus de la traduction précédente ;
les tests hôte vérifient les comportements choisis, pas une équivalence
complète du jeu original.

### Fonction promue, match à 100 % des octets ARM

- **Overlay 000 / `0x020A6B70`**, 36 octets, deux appels BL directs.
- Réinitialise des champs 32 bits aux offsets `0`, `4`, `8`, `24`,
  `28`, ainsi que deux champs 8 bits à `12` et `13`.
- La nouvelle version lisible a produit **exactement les 36 octets ARM
  originaux** en Clang ARMv5TE `-O2`, SHA-256 complet identique au
  manifeste original provenant de la ROM EUR1.
- L'ancienne définition à registres du fichier historique
  `arm9_leaf_500_part1.c` est **remplacée par cette version C typée**.
  Le manifeste `manifest_fifth500.json` a été mis à jour : statut
  `exact_original_machine_bytes`, **34 exacts / 466 nonmatching**.
- Toute la compilation des 500 fonctions a été réauditée indépendamment
  pour vérifier que les 499 autres symboles et les statuts connus restent
  cohérents. Aucun octet du jeu original n'est publié.

### Reproduire les tests sans CodeWarrior ni ROM

Depuis la racine du dépôt, sur Linux avec Clang et Python :

```sh
python3 research/eur1/batches/arm9_leaf500/verify_semantic_round14.py
python3 research/eur1/batches/arm9_leaf500/verify_fifth500_romfree.py
clang -std=c11 -O1 -g -Wall -Wextra -Werror -fsanitize=address,undefined -fno-omit-frame-pointer \
  research/eur1/batches/arm9_leaf500/test_semantic_round14.c -o /tmp/st-round14
/tmp/st-round14
```

GitHub Actions vert :
https://github.com/zeranemesis/st/actions/runs/40174646619

**Limites importantes :** pas de compilation Nintendo CodeWarrior, pas
d'`objdiff` officiel de la ROM DS, pas de validation d'un port PC natif.
Les **25 autres variantes C** sont actuellement nonmatching avec
Clang. Aucun fichier `src/` officiel du jeu n'a été modifié dans
cette passe ; l'intégration C++ complète reste une étape séparée.
