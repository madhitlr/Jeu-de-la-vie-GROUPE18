# 🌸 Projet : Le Jeu de la Vie 🌸

## 📚 Table des matières

1. [✨ Introduction](#introduction)
2. [📜 Règles du Jeu de la Vie](#règles-du-jeu-de-la-vie)
3. [🏗️ Architecture du projet](#architecture-du-projet)
4. [📊 Diagramme UML](#diagramme-uml)
5. [🎮 Fonctionnalités](#fonctionnalités)
6. [🔧 Extensions Implémentées](#extensions-implémentées)
7. [📋 Prérequis Techniques](#prérequis-techniques)
8. [💻 Installation et Exécution](#installation-et-exécution)
9. [🕹️ Utilisation](#utilisation)
10. [🧪 Tests Unitaires](#tests-unitaires)
11. [🎓 Objectifs Pédagogiques](#objectifs-pédagogiques)
12. [🌟 Conclusion](#conclusion)

---

## 1. ✨ Introduction

Le **Jeu de la Vie de Conway** est un automate cellulaire fascinant qui illustre comment des règles simples peuvent produire des comportements complexes. Créé en 1970, il s'agit d'un modèle en grille où chaque cellule, vivante ou morte, évolue selon des règles précises basées sur ses voisins. Ce jeu est devenu un outil pédagogique et scientifique majeur pour explorer des concepts liés à la biologie, aux mathématiques et à l'informatique.

Dans ce projet, nous avons recréé cette simulation en utilisant les principes de la **programmation orientée objet (POO)** en C++. Avec une architecture modulaire et robuste, nous avons intégré deux modes d'exécution :

- 🖼️ **Mode graphique** : Offrant une visualisation interactive avec la bibliothèque **SFML**.
- 🖥️ **Mode console** : Fournissant une approche légère et textuelle pour simuler les états successifs.

Ce projet va au-delà de la simple reproduction du concept en explorant des extensions avancées comme la grille torique et l'ajout de motifs prédéfinis. En combinant rigueur technique et créativité, cette simulation est une invitation à découvrir les merveilles des systèmes dynamiques.

---

## 2. 📜 Règles du Jeu de la Vie

Le **Jeu de la Vie** repose sur les règles suivantes :

1. 🌱 **Naissance** : Une cellule morte devient vivante si elle est entourée de **trois cellules vivantes**.
2. 💪 **Survie** : Une cellule vivante reste vivante si elle est entourée de **deux ou trois cellules vivantes**.
3. ☠️ **Mort** : Dans tous les autres cas, une cellule meurt (par sous-population ou surpopulation).

La simulation se déroule sur une grille bidimensionnelle, où chaque cellule évolue en fonction de son état actuel et de celui de ses voisins immédiats.

### 🌌 Importance des règles

Ces règles simples produisent des motifs complexes, permettant de simuler des comportements biologiques, des automates et même des systèmes chaotiques.

---

## 3. 🏗️ Architecture du projet

L'architecture du projet est divisée en trois couches principales, permettant une organisation modulaire et flexible :

### 🧩 Couche Composants

- **Responsabilité** : Gère les éléments fondamentaux du jeu, notamment la cellule et la grille.
- **Classes principales** :
  - `Cellule` : Représente une cellule vivante ou morte, avec des méthodes pour gérer son état.
  - `Grille` : Modélise une matrice de cellules, applique les règles du jeu, et gère la logique de transition des états.

### ⚙️ Couche Service

- **Responsabilité** : Coordonne la logique centrale de l'application.
- **Fonctions clés** :
  - Chargement et sauvegarde des configurations initiales et intermédiaires.
  - Gestion des itérations de simulation.
- **Classes principales** :
  - `GestionnaireDeFichiers` : Permet de lire et écrire les configurations et les états de la grille.
  - `JeuDeLaVie` : Coordonne l'évolution du jeu en utilisant la grille et les services associés.

### 🎨 Couche IHM

- **Responsabilité** : Interagit avec l'utilisateur via des interfaces graphiques ou en console.
- **Modes** :
  - **Graphique** : Utilise **SFML** pour afficher la grille et permettre des interactions en temps réel.
  - **Console** : Affiche les états successifs sous forme textuelle et sauvegarde les résultats dans des fichiers.
- **Classes principales** :
  - `AfficheurConsole` : Gère l'affichage des états dans le terminal.
  - `AfficheurGraphique` : Implémente une visualisation interactive avec SFML.

---

## 4. 📊 Évolution du Diagramme de Classe du Projet
![image](https://github.com/user-attachments/assets/ab7979ff-d390-49da-83ae-9326ce62ed80)

Dans l’ancien diagramme, la gestion des cellules toriques était assurée par une classe dérivée spécifique, `CelluleTorique`. Cependant, cette approche rendait la structure plus complexe et introduisait des redondances inutiles. Dans le nouveau diagramme, le comportement torique a été intégré directement dans la classe de base `Cellule`. Ainsi, toutes les cellules adoptent un comportement torique par défaut. Cette simplification permet de réduire les responsabilités redondantes et de faciliter la gestion de la logique du jeu.

La structure des couches a également été repensée pour offrir une architecture plus claire et modulaire.

---

## 🎬 Aperçu du Jeu de la Vie

Voici un exemple visuel montrant une simulation dynamique du **Jeu de la Vie** :

<div align="center">
  <img src="https://media.giphy.com/media/d7SnByEMkrdeoVQ2lT/giphy.gif" alt="Aperçu du Jeu de la Vie" />
</div>


## 5. 🎮 Fonctionnalités

- 🌀 Simulation classique du Jeu de la Vie avec application des règles de Conway.
- 🌟 Mode graphique interactif avec la bibliothèque SFML.
- 🖥️ Mode console permettant une gestion légère des simulations.
- 💾 Sauvegarde et chargement des grilles à partir de fichiers texte.

---

## 6. 🔧 Extensions Implémentées

**🏗️ Placement de constructions pré-programmées sur la grille**

L’utilisateur peut sélectionner et insérer des motifs prédéfinis directement dans la grille pour démarrer la simulation avec des configurations intéressantes. Ces motifs incluent des oscillateurs, des vaisseaux et des structures statiques. Cette fonctionnalité est idéale pour explorer des scénarios complexes sans configurer manuellement chaque cellule, ce qui rend l’expérimentation plus rapide et plus accessible.

🎹 Intégration de nouveaux motifs via le clavier

Pendant l’exécution de la simulation, l’utilisateur peut interagir avec la grille en ajoutant de nouveaux motifs à l’aide des touches du clavier. Cela enrichit l’expérience interactive et permet de tester l’impact de nouveaux éléments en temps réel.

### 🔄 Grille Torique

La gestion torique connecte les bords de la grille pour permettre des motifs continus qui traversent les limites, offrant une expérience de simulation fluide et naturelle.

---

## 7. 📋 Prérequis Techniques

- 🖥️ **C++17 ou plus récent** : Pour utiliser les fonctionnalités modernes du langage.
- 🎨 **SFML** (version 2.5.1 ou ultérieure) : Pour gérer l'interface graphique.

---

## 8. 💻 Installation et Exécution

1. 📥 Clonez le dépôt :
   ```bash
   git clone https://github.com/votre-nom-utilisateur/jeu-de-la-vie.git
   ```
2. ⚙️ Compilez le projet :
   ```bash
   g++ -std=c++17 -I include -o jeu main.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```
3. ▶️ Exécutez le programme :
   ```bash
   ./jeu
   ```

---

## 9. 🕹️ Utilisation

Pour exécuter le programme, nous utilisons le **débogueur Windows local** intégré à l’environnement de développement. Une fois le programme lancé, un menu interactif s’affiche, offrant les options suivantes :

1. **Mode Console** :
   - Permet une simulation légère affichée directement dans la console.
   - L’utilisateur peut charger une configuration initiale ou suivre les itérations successives en texte.

2. **Mode Graphique** :
   - Offre une visualisation en temps réel des évolutions sur la grille.
   - Les utilisateurs peuvent interagir avec la simulation en ajoutant, supprimant ou modifiant des cellules directement via la souris ou le clavier.

### Instructions :
- Lancez le débogueur Windows local pour démarrer le programme.
- Choisissez le mode souhaité dans le menu interactif.
- Suivez les instructions affichées à l’écran pour configurer la simulation et interagir avec la grille.

---

## 10. 🧪 Tests Unitaires
![Capture d'écran 2024-12-07 224714](https://github.com/user-attachments/assets/be9175c4-ad2f-4962-89de-5fa2fbd962c6)

Nous avons implémenté des tests unitaires pour garantir la fiabilité et la robustesse des fonctionnalités principales du projet. Ces tests ont été réalisés avec **Microsoft Visual Studio C++ Unit Testing Framework**. Voici un résumé des tests effectués :

1. **Test d'initialisation de la grille** : Vérification que la grille est correctement créée avec les dimensions spécifiées et que toutes les cellules sont initialisées comme mortes.
2. **Test des itérations** : Simulation d'une grille de 3x3 avec un motif initial et vérification que les cellules évoluent correctement selon les règles du jeu.
3. **Test d'un motif stable (bloc)** : Vérification que le motif 2x2 reste inchangé après plusieurs itérations, confirmant son caractère stable.

Tous les tests ont été exécutés avec succès, confirmant que les fonctionnalités principales fonctionnent comme prévu.

---

## 11. 🎓 Objectifs Pédagogiques

Ce projet vise à :

- 🛠️ Illustrer les principes de la programmation orientée objet.
- 🏗️ Montrer comment structurer un projet avec une architecture modulaire.
- 🎨 Utiliser des bibliothèques externes comme **SFML** pour enrichir une application.
- 🔄 Apprendre à gérer des états complexes et des itérations successives.

---

## 12. 🌟 Conclusion

Le projet "Jeu de la Vie" démontre comment des règles simples peuvent conduire à des comportements complexes et imprévisibles. L'architecture modulaire permet d'ajouter des extensions futures, comme :

- ⚡ La parallélisation des calculs.
- 🖼️ Une interface utilisateur plus avancée.

Ce travail constitue une base solide pour explorer des concepts avancés en programmation et simulation.

🌸 Merci pour votre lecture et bonne exploration du "Jeu de la Vie" ! 🌸

