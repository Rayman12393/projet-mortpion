# projet-morpion

Bienvenue dans ce petit projet de jeu de **Morpion (Tic-Tac-Toe)** codé en **langage C**, avec une interface en mode texte grâce à la bibliothèque **ncurses**.  
Ce jeu permet à un ou deux joueurs de s’affronter dans un duel stratégique de X et de O — directement dans le terminal !

---

##  Présentation

Ce projet a été réalisé dans le but de mettre en pratique :

- La programmation en C
- L’utilisation de la bibliothèque **ncurses** pour créer des interfaces en terminal
- La gestion d’un petit moteur de jeu (plateau, tour de jeu, victoire, IA basique)

C’est une version simple mais fonctionnelle du Morpion, avec deux modes de jeu :

-  **Joueur vs Joueur** : deux humains jouent chacun leur tour.
-  **Joueur vs IA** : vous jouez contre une intelligence artificielle qui joue de manière aléatoire.

---

##  Règles du jeu

- Le plateau est une grille de **3x3 cases**.
- Le joueur **X** commence toujours la partie.
- Les joueurs jouent en appuyant sur une touche de `1` à `9`, qui correspond à une position sur le plateau :


- Le premier à aligner **trois symboles identiques** (horizontalement, verticalement ou en diagonale) remporte la partie.
- Si toutes les cases sont remplies sans vainqueur, c’est un **match nul**.
- Vous pouvez **quitter la partie** à tout moment en appuyant sur `q`.

---

##  Installation et compilation

###  Prérequis

- Un compilateur C (`gcc`)
- La bibliothèque `ncurses`

###  Installation de ncurses

```bash
sudo apt update
sudo apt install libncurses5-dev libncursesw5-dev
