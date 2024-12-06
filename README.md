# Projet : Le Jeu de la Vie

## 📚 Table des matières

1. [Introduction](#introduction)
2. [Règles du Jeu de la Vie](#règles-du-jeu-de-la-vie)
3. [Architecture du projet](#architecture-du-projet)
4. [Diagramme UML](#diagramme-uml)
5. [Fonctionnalités](#fonctionnalités)
6. [Extensions Implémentées](#extensions-implémentées)
7. [Prérequis Techniques](#prérequis-techniques)
8. [Installation et Exécution](#installation-et-exécution)
9. [Utilisation](#utilisation)
10. [Objectifs Pédagogiques](#objectifs-pédagogiques)
11. [Conclusion](#conclusion)

## 1. Introduction

Le **Jeu de la Vie de Conway** est un automate cellulaire qui illustre des principes mathématiques et informatiques fascinants. Ce projet implémente cette simulation en utilisant les concepts de la **programmation orientée objet (POO)** en C++.

Deux modes d'exécution sont disponibles :

- Un mode graphique réalisé avec **SFML** pour une visualisation interactive.
- Un mode console permettant une gestion plus légère et scriptable.

Ce projet a pour but d'intégrer des principes logiciels robustes, une structure modulaire, et d'explorer des extensions avancées du concept original.

## 2. Règles du Jeu de la Vie

Le **Jeu de la Vie** repose sur les règles suivantes :

1. **Naissance** : Une cellule morte devient vivante si elle est entourée de **trois cellules vivantes**.
2. **Survie** : Une cellule vivante reste vivante si elle est entourée de **deux ou trois cellules vivantes**.
3. **Mort** : Dans tous les autres cas, une cellule meurt (par sous-population ou surpopulation).

La simulation se déroule sur une grille bidimensionnelle, où chaque cellule évolue en fonction de son état actuel et de celui de ses voisins immédiats.

### Importance des règles

Ces règles simples produisent des motifs complexes, permettant de simuler des comportements biologiques, des automates et même des systèmes chaotiques.

## 3. Architecture du projet

L'architecture du projet est divisée en trois couches principales, permettant une organisation modulaire et flexible :

### Couche Composants

- **Responsabilité** : Gère les éléments fondamentaux du jeu, notamment la cellule et la grille.
- **Classes principales** :
  - `Cellule` : Représente une cellule vivante ou morte, avec des méthodes pour gérer son état.
  - `Grille` : Modélise une matrice de cellules, applique les règles du jeu, et gère la logique de transition des états.

### Couche Service

- **Responsabilité** : Coordonne la logique centrale de l'application.
- **Fonctions clés** :
  - Chargement et sauvegarde des configurations initiales et intermédiaires.
  - Gestion des itérations de simulation.
- **Classes principales** :
  - `GestionnaireDeFichiers` : Permet de lire et écrire les configurations et les états de la grille.
  - `JeuDeLaVie` : Coordonne l'évolution du jeu en utilisant la grille et les services associés.

### Couche IHM

- **Responsabilité** : Interagit avec l'utilisateur via des interfaces graphiques ou en console.
- **Modes** :
  - **Graphique** : Utilise **SFML** pour afficher la grille et permettre des interactions en temps réel.
  - **Console** : Affiche les états successifs sous forme textuelle et sauvegarde les résultats dans des fichiers.
- **Classes principales** :
  - `AfficheurConsole` : Gère l'affichage des états dans le terminal.
  - `AfficheurGraphique` : Implémente une visualisation interactive avec SFML.

## 4. Diagramme UML

Voici une représentation UML des classes et de leurs relations :

*(Ajoutez ici une image ou une description détaillée du diagramme UML)*

## 5. Fonctionnalités

### Simulation classique du Jeu de la Vie

La simulation suit les règles de Conway. Chaque itération met à jour l'état de toutes les cellules en parallèle, en calculant les transitions en fonction des voisins immédiats. Les cellules mortes ou vivantes évoluent en fonction des trois règles fondamentales, permettant d'observer des motifs dynamiques comme :

- **Oscillateurs** : Motifs qui reviennent à leur état initial après un nombre fixe d'itérations.
- **Vaisseaux** : Motifs mobiles qui se déplacent dans la grille.
- **Motifs statiques** : Configurations qui restent inchangées au fil des itérations.

### Mode interactif

#### Mode Graphique
- **Description** :
  - Visualisation en temps réel de l'évolution de la grille.
  - Interactions utilisateur via la souris pour ajouter, retirer ou modifier des cellules pendant la simulation.
  - Contrôle de la vitesse d'exécution avec des commandes interactives.
- **Implémentation** :
  - Utilisation de la bibliothèque **SFML** pour dessiner la grille et gérer les événements utilisateur.
  - Chaque cellule est représentée par un rectangle coloré (vert pour vivante, noir pour morte).

#### Mode Console
- **Description** :
  - Simulation basée sur des fichiers texte décrivant l'état initial de la grille.
  - Affichage des états successifs dans le terminal sous forme de matrice.
  - Résultats sauvegardés automatiquement dans des fichiers distincts pour chaque itération.
- **Implémentation** :
  - Lecture et écriture des configurations dans des fichiers structurés.
  - Affichage textuel optimisé pour des grilles de taille variable.

### Sauvegarde et chargement

#### Sauvegarde automatique
- **Description** :
  - Chaque état de la grille est sauvegardé à la fin d'une itération, permettant une reprise ou une analyse ultérieure.
  - Les fichiers sont nommés de manière incrémentale pour suivre l'évolution de la simulation.
- **Implémentation** :
  - Utilisation de la classe `GestionnaireDeFichiers` pour écrire les configurations dans un répertoire dédié.

#### Chargement de configurations personnalisées
- **Description** :
  - L'utilisateur peut définir un fichier texte contenant une grille personnalisée avec des cellules initiales vivantes ou mortes.
  - Cette fonctionnalité permet de tester des scénarios spécifiques ou d'explorer des motifs prédéfinis.
- **Implémentation** :
  - Lecture des fichiers ligne par ligne pour construire une grille valide.
  - Gestion des erreurs de format pour garantir une configuration cohérente.

## 6. Extensions Implémentées

### Grille Torique
L'extension de la grille torique ajoute une fonctionnalité clé au projet en supprimant les limites traditionnelles de la grille rectangulaire.

#### Description
Dans une grille classique, les cellules situées aux bords n'ont pas de voisins de l'autre côté. Cependant, dans une grille torique :
- **Les bords gauche et droit de la grille sont connectés** : Une cellule située à l'extrémité gauche considère les cellules de l'extrémité droite comme ses voisines.
- **Les bords supérieur et inférieur sont également connectés** : Une cellule en haut de la grille peut interagir avec les cellules situées tout en bas.

Ce mécanisme permet d'observer des comportements nouveaux et dynamiques :
1. **Propagation infinie des motifs** : Les motifs qui atteignent un bord continuent de l'autre côté de la grille.
2. **Équilibre naturel des motifs** : Les motifs ne sont pas arrêtés par des "murs invisibles", ce qui donne lieu à des interactions plus naturelles.

#### Avantages
- **Amélioration des simulations** : Permet de modéliser des environnements sans frontières, tels que les systèmes planétaires ou biologiques.
- **Complexité accrue** : Enrichit les possibilités de configurations et de motifs observables.

#### Implémentation Technique
- L'algorithme calcule les voisins de chaque cellule en utilisant des **opérations modulo** sur les coordonnées de la grille :
  ```cpp
  int voisinX = (x + décalageX + largeur) % largeur;
  int voisinY = (y + décalageY + hauteur) % hauteur;
  ```
- Cela assure que les indices "tournent" au-delà des limites de la grille.

## 7. Prérequis Techniques

- **C++17 ou plus récent** : Pour utiliser les fonctionnalités modernes du langage.
- **SFML** (version 2.5.1 ou ultérieure) : Pour gérer l'interface graphique.
- Un compilateur compatible comme **GCC**, **Clang**, ou **MSVC**.

## 8. Installation et Exécution

### Étapes d'installation

1. Clonez le dépôt :
   ```bash
   git clone https://github.com/votre-nom-utilisateur/jeu-de-la-vie.git
   ```
2. Accédez au dossier :
   ```bash
   cd jeu-de-la-vie
   ```
3. Compilez le projet :
   ```bash
   g++ -std=c++17 -I include -o jeu main.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```

### Configuration initiale

Préparez un fichier décrivant l'état initial de la grille, par exemple :

```
5 5
0 0 0 0 0
0 1 1 1 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
```

Exécutez ensuite le programme en fournissant ce fichier comme argument.

## 9. Utilisation

### Mode console

- Lancez la simulation avec :
  ```bash
  ./jeu --console config.txt
  ```
- Les états successifs sont sauvegardés dans des fichiers de sortie.

### Mode graphique

- Lancez la simulation graphique avec :
  ```bash
  ./jeu --gui config.txt
  ```
- Utilisez la souris ou le clavier pour interagir avec la grille.

## 10. Objectifs Pédagogiques

Ce projet vise à :

1. Illustrer les principes de la programmation orientée objet.
2. Montrer comment structurer un projet avec une architecture modulaire.
3. Utiliser des bibliothèques externes comme **SFML** pour enrichir une application.
4. Apprendre à gérer des états complexes et des itérations successives.

## 11. Conclusion

Le projet "Jeu de la Vie" démontre comment des règles simples peuvent conduire à des comportements complexes et imprévisibles. L'architecture modulaire permet d'ajouter des extensions futures, comme :

- La parallélisation des calculs.
- L'ajout de motifs préprogrammés (oscillateurs, vaisseaux).
- Une interface utilisateur plus avancée.

Ce travail constitue une base solide pour explorer des concepts avancés en programmation et simulation.



