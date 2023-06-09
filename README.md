# Age of Manif
###### développeurs : Tachez Anis et Sierra Théodore
###### Dernière mise à jour : 7 juin 2023
###### Bibliothèque : SFML
### But du jeu : 
Bienvenue dans notre jeu vidéo ! Le concept du jeu est simple : il s'agit d'un affrontement stratégique en tour par tour entre deux joueurs. L'un d'entre vous incarnera le peuple, tandis que l'autre endossera le rôle du gouvernement. Votre objectif principal sera de prendre le contrôle du territoire français, qui se trouve actuellement plongé dans un climat tendu. Préparez-vous à des combats palpitants où la stratégie sera votre meilleur atout !
### Lancer le jeu :
Dans votre terminal : 
``` bash
git clone https://github.com/anistac/AgeOfManif
cd AgeOfManif/src
cmake .
make
./ex
```

### Comment jouer :
#### Début du jeu :
De manière alternée vous allez chacun pouvoir effectuer différentes actions afin que l'opinion de la population francaise penche en votre faveur. Dans un premier temps vous avez accès à la carte de France, depouis laquelle vous pouvez accéder aux 12 régions existantes à l'aide des différents boutons sur le côté gauche de votre écran : 
![menu](https://i.imgur.com/JaeeEc7.png)
 Maintenant vous arrivé sur la map de la région choisi : 
 ![jeu](https://i.imgur.com/dxhlmN9.png)
 Vous aurez à votre disposition la possibilité de créer des batiments qui génèreront soit des troupes soit des ressources essentiels dans votre quête.
 Si l'opinion atteint les 0% le gouvernement gagne, les 100% le peuple gagne !
#### Commandes :
##### Peuple :
-  Manifester : sélectionner un batiment adverse puis cliqué sur le 'bouton ation' en bas en droite dans le menu "Actions"
Argent : +5000  Opinion : -10%
-  Construire une ZAD : sélectionner une case vide le la map et actionné le bouton action correspondant
Argent : - 5000 Opinion : +5% Troupes : +3 manifestant
- Construire un barbecue : sélectionner une case vide le la map et actionné le bouton action correspondant
Argent : -500 Opinion : +10% Troupes : +1 manifestant radical
- Aller travailler : Sélectionner un de vos manifestants et une usine
Argent : 3000 Opinion : -1%

##### Gouvernement :
- Dissoudre une manifestation : sélectionner votre batiment bloqué par une manifestattion puis cliqué une le bouton correspondant pour le débloquer
Argent : - 10000 Opinion : -5% Troupes : -1 manifestant
- Construire un poste de police : sélectionner une case vide le la map et actionné le bouton action correspondant
Argent : - 2000 Opinion : 3% Troupes : +1 policier
- Construire une Mairie : sélectionner une case vide le la map et actionné le bouton action correspondant
Argent : - 500 Opinion : -10% Troupes : +1 polititien
- Céder au peuple : sélectionner votre Mairie bloqué par un manifestant radical puis cliqué une le bouton correspondant pour le débloquer
Argent : -10000


##### Commun :
- Construire une usine : sélectionner un hexagone vide
Argent : + 10000
- Détruire un batiment : sélectionner un batiment vous appartenant et détruiser le
Argent : + 1000 Opinion : -2%
- Déplacer une troupe : cliquer sur une de vos troupes puis sur la case vers laquelle vous voulez la déplacer en actionnant le bouton correspondant
Argent : - 100
#### Comment gagner :
Rappel : L'unique critère determinant qui mène ou gagne est 'l'opinion' de la population, si l'opinion est à 100% le peuple gagne, mais s'il atteint 0% le gourvernement l'emporte.

#### Conception du code : 
![UML Global](https://i.imgur.com/eG0ID2n.png)
Le code à été concu de manière très modulaire, le jeu se compose d'une map, d'une grille, d'entités. Les entités peuvent être de 3 types : Batiments, Troupes ou hexagones, et ont une positions (coordonnée axiale) sur la grille. Ceci nous permet que les entités peuvent intéragir deux à deux à l'aide de commande. Les commandes possibles apparaissent en fonction des entités choisies sur la grille, et font varier des différentes ressources du jeu (argent et opinion) ainsi que de pouvoir créer d'autres entités.

#### Points primordiaux pour notre code :
- Structure modulaire : Le programme est conçu de manière modulaire, avec des classes et des méthodes bien définies, ce qui facilite la compréhension et la maintenance du code. Chaque classe a une responsabilité spécifique et peut être développée et testée indépendamment.
-  Extensibilité : Le programme est conçu de manière à être extensible, un ppint très important pour nous dans la mesure où le projet peut être bien plus conséquent pour atteindre la qualité et la quantité classique des jeux similaires de nos jours. De nouvelles fonctionnalités peuvent être ajoutées facilement sans avoir à modifier de manière significative le code existant, comme principalement des commandes et des entités. Cela permet de répondre aux besoins futurs et de faire évoluer le programme sans compromettre sa stabilité.
- Le code suit (au maximum) les conventions de nommage claires, utilise une indentation cohérente et suit les bonnes pratiques de programmation. Cela facilite la lisibilité du code et la collaboration avec d'autres développeurs.

#### Plus en détail :
- Interactable : est une classe abstraite qui englobe toutes les entités avec lesquels le joueurs peut intéragir, que se soit Troupes Batiment ou les Hexagones (Hex).
- Grille : est une classe qui contient la liste des hexagones dans une unordered_map. C'est un stockage clé-valeurs, où la clé est une position avec coordonné axiale et la valeur est un pointeur vers un hexagone. De cette manière on est capable de récupérer facilement un hexagone en fonction des ses coordonnées axiales. On a aussi mis en place des méthodes permettants de passer de coordonnée de la souris en coordonnée axiale, il est donc très facile de récupérer les hexagones, et donc les entités, avec lesquel le joueur interagit. La théorie implémentée dans les classes Hex et Grid est décrit sur [ce site](https://www.redblobgames.com/grids/hexagons/).
- Commande : Dans notre jeu il existe plusieurs types d'actions en fonction du camp, des troupes et des batiments. On a donc du mettre en place une solution pour lister toutes les commandes en fonction des entitées sur lesquels elles s'appliquent : il s'agit du registre de commande. Le registre de commande stock l'intégralité des commandes possibles en fonctions de ses initiateurs dans une unorder_multimap. Il s'agit encore d'un sockage de type clé-valeurs, où la clé est une paire de type d'interactable et où la valeur est un pointeur vers la commande. On peut ainsi grace à cette classe statique retrouver facilement les commandes réalisables par le ou les entités selectionnées (hexagone compris).


##### Améliorations : 
Le jeu n'est pas totalement terminé : 
- Le game play n'a été poli
- ajout de régions supplémentaires
- L'implémentation d'autres commandes est pimoradiales afin d'éviter d'avoir un jeu trop répétitif, ainsi qu'avoir un jeu plus ample en terme de stratégie pour arriver à la victoire.
- Régler le problème de redimensionnement de notre jeu lorsqu'on change la taille de la fenêtre. 
- Nous voulions créer une fenêtre avec un système de missions à faire dans chaque région afin de donner un guide aux joueurs.
- Ajouter un système de brouillard pour obliger le joueur à explorer la carte.
Le jeu peut néanmoins être amélioré facilement grace à sa grande modularité.


#### Organisation au sein du groupe :
Nous avons commencé à dévelloper des partis séparées (Menu et grille) avant ensuite de les combiner. Nous avons ensuite fait toutes nos scéances de travaille ensemble se qui facilitais grandement notre communication. Pour travailler en duo (deux ordinateurs différents) nous avons utiliser Git, notre dépot est hébergé sur Github mais nous utilisions GitKraken pour simplifier nos démarches (qui est un client graphique multiplateforme puissant et intuitif qui simplifie l'utilisation de Git). Suivi du dévellopement des prémisse des différentes classes, puis la fin du dévellopement nous l'avons effectuer sur un seul ordi afin de dévelloper le jeu sans s'embrouiller : 
![gitkraken](https://i.imgur.com/WF0DULX.png)
