# Filler - Le 101 (école 42)
Filler est un jeu algorithmique qui consiste à remplir une grille d’une taille connue
à l’avance avec des pièces de taille et de formes aléatoires, sans que les pièces ne se superposent
de plus d’une seule case et sans qu’elles ne depassent de la grille. Si l’une de
ces conditions n’est pas remplie, la partie s’arrête.

Chaque pièce posée avec succès rapporte un certain nombre de points, et a un seul
joueur, le but du jeu pourrait être d’obtenir le meilleur score possible. Cepedant, c’est
avec deux joueurs que le filler prend tout son intérêt. Chaque joueur a pour but de poser
un maximum de pièces tout en tentant d’empêcher son adversaire de le faire. A la fin de
la partie, celui avec le plus de point remporte le match...

## Règles

• Le plateau est défini par X colonnes et Y lignes. Il fera donc X x Y cases.

• A chaque tour, le programme du joueur actif se voit fournir l’état actuel du plateau
et une pièce à placer.

• La VM représente les pièces posées par un des programmes joueurs avec des charactères
’X’ et celles posées par l’autre avec des charactères ’O’.

• Une pièce est définie par x colonnes et y lignes. Dans chaque pièce, une forme
d’une ou plusieurs cases est représentée avec le charactère ’*’.

• Pour pouvoir poser une pièce, il faut qu’une case de la forme recouvre une case,
et une seule case, d’une forme précédemment posée.

• La forme doit rentrer intégralement dans le plateau.

• Le plateau contient une première forme pour chaque programme joueur pour initier
la partie.

• La partie s’arrête à la première erreur : dès qu’une pièce ne peut plus être posée
ou a été mal posée.

## Fonctions autorisées
◦ write
◦ malloc
◦ free
◦ read
◦ perror
◦ strerror

## Exemple
<p align="center">
<img src="https://github.com/mdubus/filler/blob/master/img/mdubus-filler-ecole-42.gif"/>
</p>

## Stratégie adoptée

Un algorithme en deux temps a été mis en place :

◦ Une première phase de rush vers le point le plus proche de l'adversaire,<br/>

◦ Une seconde phase d'encerclement une fois arrivé au contact afin d'empêcher un maximum l'adversaire de jouer.<br/>

Le calcul du coup optimal se fait par l'attribution d'une note à chaque coup possible en fonction de plusieurs critères comme la distance des murs et le nombre de cases prises collées à l'adversaire.

## Utilisation

#### Télécharger et compiler Filler
```
git clone https://github.com/Alhuin/Filler.git ~/Filler
cd ~/Filler
make
```
#### Exécution
```
./filler_vm -f [map] -p1 [player1] -p2 [player2]
```

## Licence
Ce projet a été produit sous licence MIT - voir le fichier LICENSE.md pour plus d'informations.

