# Spirit Tracks EUR Rev1 — Passe 13, 25 octobre 2026

## Objectif : travailler sur le code C++ du jeu sans inventer de nouveaux matches

Cette passe ajoute deux outils complémentaires et des contrôles automatisés au
dépôt `zeranemesis/st`, PR #15 (branche de recherche ; `main` intacte).

### 1. Vérificateur CodeWarrior pour la *méthode intégrée*

`research/eur1/tests/verify_ui_counter_6590c_codewarrior.py` isole et
compile la définition **réelle** de
`UnkStruct_020d8698_24_5C_Base::func_ov000_0206590c`, extraite de
`src/000_Second/code_020657fc.cpp`.

Il compare le SHA-256 et la taille du code ARM produit avec le manifeste
EUR Rev1 préalablement vérifié par la ROM du propriétaire. Les relocations
non résolues bloquent le statut « exact », de même que les sections ambiguës.

Résultat GitHub Actions en `--backend clang` :
**32 octets générés, 36 octets originaux, nonmatching Clang C++ isolé**.
Le test de comportement de la méthode du dépôt valide également
la compilation ARMv5TE et trois vecteurs hôte ASan/UBSan.

Le vérificateur peut faire la même comparaison avec le véritable compilateur
historique **Nintendo CodeWarrior dsi/1.2p1** sur Windows, en réutilisant les
options C++ de `tools/configure.py` adaptées à l'overlay 0.

```powershell
# Après avoir récupéré la branche de la PR #15 :
cd C:\st
python research/eur1/tests/verify_ui_counter_6590c_codewarrior.py --backend codewarrior --out build/eur1/codewarrior_ui_counter_6590c.json
```

Le compilateur `tools/mwccarm/dsi/1.2p1/mwccarm.exe` et
`tools/sjiswrap.exe` doivent être installés localement. **Ce mode n'a pas
été exécuté ici** : le dépôt distant ne contient pas l'exécutable propriétaire.

Le mode test disponible sur GitHub :

```sh
python3 research/eur1/tests/verify_ui_counter_6590c_codewarrior.py --backend clang
```

**Limite :** le test compile la méthode extraite avec une déclaration de
classe minimale et non l'unité complète du jeu dans son contexte de
compilation, de liaison et de placement. Même un résultat CodeWarrior exact
isolé ne prouverait donc pas que la ROM a été reconstruite correctement.

### 2. Attribution des fonctions de l'overlay 0

`research/eur1/batches/arm9_leaf500/audit_overlay000_ownership.py`
recoupe les 500 cibles historiques avec les **symboles EUR Rev1** et les
**plages textuelles explicitement définies dans les delinks**.

Résultat GitHub Actions :

| Mesure | Total |
| --- | ---: |
| Fonctions du cinquième lot situées dans l'overlay 0 | **103** |
| Symboles de fonctions C++ manglés à ces adresses | **21** |
| Fonctions situées dans un fichier source explicitement délimité | **8** |
| Fonctions disposant des deux types d'indices | **7** |

Ce rapport ne prétend pas que les 7 corps sont absents, non décompilés,
matching ou déjà intégrés. Des adresses peuvent désigner des wrappers,
des alias ou des constructeurs. Il aide seulement à identifier **où**
examiner les C++ déjà présents avant d'en écrire un autre.

La méthode `0x0206590C` est attribuée de manière vérifiée à
`src/000_Second/code_020657fc.cpp`.
La fonction `0x020669B4` se trouve **déjà** dans
`src/000_Second/UnkSystem1_Base.cpp` et n'a pas été ajoutée une seconde fois.

Pour reconstruire le rapport :

```sh
python3 research/eur1/batches/arm9_leaf500/audit_overlay000_ownership.py --out build/eur1/overlay000_fifthbatch_ownership.json
```

### 3. Test automatisé et limites

Le workflow `.github/workflows/research-eur1-round11.yml` effectue
la compilation/test C++ de la méthode intégrée, son hachage isolé Clang,
les tests des dix candidats C précédents, et l'audit des propriétaires
source. Le workflow de recherche est **PASS** :
https://github.com/zeranemesis/st/actions/runs/40173635636

Les workflows généraux `Build` et `CI` échouaient déjà sur le commit de
`main` antérieur à ces passes. Le build standard dépend d'une image Docker
qui a précédemment retourné un refus d'accès ; l'échec du formatage
`clang-format` est également observé dans le workflow global.
**Cette passe ne prétend ni avoir corrigé ces blocages, ni avoir construit
une ROM jouable.**

- Lot historique `arm9_leaf500` : **33/500 Clang exacts**, inchangé.
- Lot `bl50c` : **30/50 Clang exacts**, inchangé.
- Matching CodeWarrior d'origine de la méthode C++ intégrée : **inconnu**.
- `objdiff` jeu complet et port PC natif : **non testés**.

Prochaine action sur machine propriétaire : exécuter le vérificateur C++
CodeWarrior puis, lorsque le build ROM EUR1 est rétabli, mesurer l'objet
officiel par `objdiff` avant d'attribuer un statut matching.
