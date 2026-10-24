# Spirit Tracks EUR Rev 1 — passe 12 : CodeWarrior et première intégration UI

Date : 24 octobre 2026. Branche de travail de la PR #15 ; `main` inchangée.

## 1. CodeWarrior vérifiable sur Windows

Ajout de `verify_codewarrior_round11.py` dans le dossier
`research/eur1/batches/arm9_leaf500/`.

Il extrait les **dix fonctions C déjà étudiées** de
`semantic_refactors_round11.c`, les compile séparément pour identifier
les erreurs fonction par fonction, lit les symboles et relocations ARM ELF32,
puis compare les tailles et les SHA-256 aux références de la ROM EUR1
présentes dans le manifeste historique.

- `--backend clang` : **smoke test uniquement**. Sur GitHub Actions :
  10/10 fonctions examinées ; 5 tailles différentes, 5 mêmes tailles
  mais instructions différentes, **0 nouveau matching**.
- `--backend codewarrior` (mode par défaut) : nécessite **Windows**, le
  compilateur original `tools/mwccarm/dsi/1.2p1/mwccarm.exe` et
  `tools/sjiswrap.exe` sur l'ordinateur du propriétaire. **Aucun résultat
  original CodeWarrior n'est revendiqué dans cette passe.**
- Le rapport n'inclut pas les octets de la ROM. Un match isolé ne prouve
  pas une intégration `objdiff` au binaire DS.

À lancer dans le dépôt sur Windows, après avoir récupéré la branche PR #15 :

```powershell
python research/eur1/batches/arm9_leaf500/verify_codewarrior_round11.py --backend codewarrior --out build/eur1/codewarrior_round11.json
```

Pour le diagnostic Clang seul :

```powershell
python research/eur1/batches/arm9_leaf500/verify_codewarrior_round11.py --backend clang
```

## 2. Fonction C++ réelle ajoutée : 0x0206590C

La fonction `UnkStruct_020d8698_24_5C_Base::func_ov000_0206590c`
était déjà déclarée dans `include/Unknown/UICounterManager.hpp`,
appelée par le constructeur et placée par le delink EUR1 dans
`src/000_Second/code_020657fc.cpp`. Elle a désormais une définition
dans **ce véritable fichier C++ du jeu**, reprenant les six écritures
décrites dans la traduction du cinquième lot :

1. `mUnk_00.x = 0`
2. `mUnk_00.y = 0`
3. `mUnk_94 = 0`
4. `mUnk_04 = param1`
5. `mUnk_8C = param2`
6. `mUnk_90 = 2`

Le script `research/eur1/tests/test_ui_counter_6590c_integration.py`
extrait la **définition réelle** (pas une copie de la fonction), teste
la signature du header, compile la fonction comme C++ ARMv5TE avec un
shim réduit des champs de classe, vérifie les offsets 0x04, 0x80, 0x8C,
0x90, 0x94 et lance trois vecteurs de tests sur hôte avec ASan/UBSan.

Commande portable :

```sh
python3 research/eur1/tests/test_ui_counter_6590c_integration.py
```

**Limite critique :** ces tests utilisent une déclaration de classe
minimale dédiée au test, **pas la compilation CodeWarrior de l'unité
C++ complète**. La source C++ ajoutée n'est donc pas qualifiée
`matching` : ni `objdiff` EUR1, ni rebuild ROM jouable, ni test
émulateur n'ont été validés pour cette nouvelle définition.

## 3. Suivi honnête

- Cinquième lot de 500 : **33/500 correspondances Clang historiques**,
  inchangées ; ses dix versions C alternatives demeurent nonmatching.
- Lot `bl50c` : **30/50 correspondances Clang historiques**, inchangées.
- **1 corps de méthode C++ du jeu ajouté** dans le dossier `src/`,
  actuellement nonmatching/non testé CodeWarrior. Cela ne vaut pas un
  pourcentage de décompilation supplémentaire mesuré.
- La CI de recherche vérifie désormais à chaque modification pertinente
  le nouvel outil et la méthode C++ du jeu.
- Le build GitHub traditionnel dépend de l'accès à l'image privée/indisponible
  `ghcr.io/zeldaret/ph-build:st`. Les tests isolés verts ne remplacent
  pas ce build.

Prochain objectif : compiler l'unité `code_020657fc.cpp` dans le vrai build
CodeWarrior local, examiner le diff de `0x0206590C`, ajuster le source
seulement sur preuve binaire, puis démarrer l'intégration de fonctions
adjacentes de l'unité source.
