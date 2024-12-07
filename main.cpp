#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include "SERVICE/JeuDeLaVie.h"
#include "IHM/AfficheurConsole.h"
#include "IHM/AfficheurGraphique.h"
#include "SERVICE/GestionnaireDeFichier.h"
#include <iostream>
#include <SFML/Audio.hpp>

static std::vector<int> scores;

void chargerScores() {
    std::ifstream in("scores.txt");
    if (!in) return;
    int sc;
    while (in >> sc) {
        scores.push_back(sc);
    }
}

void sauvegarderScores() {
    std::ofstream out("scores.txt");
    for (int sc : scores) {
        out << sc << "\n";
    }
}

void afficherScores() {
    if (scores.empty()) {
        std::cout << "Aucun score enregistre.\n";
        return;
    }
    std::cout << "----- SCORES -----\n";
    for (auto sc : scores) {
        std::cout << sc << "\n";
    }
}

void afficherMenuPrincipal() {
    std::cout << "=============================\n";
    std::cout << "     JEU DE LA VIE (MENU)    \n";
    std::cout << "=============================\n";
    std::cout << "1. Play\n";
    std::cout << "2. Test unitaire\n";
    std::cout << "3. Score\n";
    std::cout << "0. Quitter\n";
    std::cout << "Choix: ";
}

void afficherMenuPlay() {
    std::cout << "----- PLAY -----\n";
    std::cout << "1. Mode Console\n";
    std::cout << "2. Mode Graphique\n";
    std::cout << "0. Retour\n";
    std::cout << "Choix: ";
}

void afficherMenuGraphique() {
    std::cout << "----- MODE GRAPHIQUE -----\n";
    std::cout << "1. Charger depuis un fichier\n";
    std::cout << "2. Grille interactive (WASD pour bouger, e pour toggler, q pour quitter)\n";
    std::cout << "0. Retour\n";
    std::cout << "Choix: ";
}

// Fonction pour �diter la grille de mani�re interactive avec WASD
std::vector<std::vector<std::shared_ptr<Cellule>>> editerGrilleInteractif(int largeur, int hauteur) {
    std::vector<std::vector<std::shared_ptr<Cellule>>> grille(hauteur, std::vector<std::shared_ptr<Cellule>>(largeur));
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            grille[y][x] = std::make_shared<CelluleStandard>(false);
        }
    }

    int cx = 0, cy = 0; // position du curseur
    char input;
    while (true) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        std::cout << "Utilisez W,A,S,D pour bouger le curseur\nE pour toggler la cellule\nQ pour lancer la simulation\n\n";

        for (int y = 0; y < hauteur; ++y) {
            for (int x = 0; x < largeur; ++x) {
                if (y == cy && x == cx) {
                    std::cout << (grille[y][x]->estVivante() ? "[X]" : "[ ]");
                }
                else {
                    std::cout << (grille[y][x]->estVivante() ? " X " : " . ");
                }
            }
            std::cout << "\n";
        }

        std::cin >> input;
        if (input == 'q' || input == 'Q') {
            break;
        }
        else if (input == 'w' || input == 'W') {
            if (cy > 0) cy--;
        }
        else if (input == 's' || input == 'S') {
            if (cy < hauteur - 1) cy++;
        }
        else if (input == 'a' || input == 'A') {
            if (cx > 0) cx--;
        }
        else if (input == 'd' || input == 'D') {
            if (cx < largeur - 1) cx++;
        }
        else if (input == 'e' || input == 'E') {
            bool etat = grille[cy][cx]->estVivante();
            grille[cy][cx]->definirEtat(!etat);
        }
    }

    return grille;
}

int main() {
    chargerScores();
   
    sf::Music musique;
    if (!musique.openFromFile("C:\\Users\\PC-PHONE\\Desktop\\miaw\\audio\\meow.ogg")) {
        std::cerr << "Erreur lors du chargement de la musique.\n";
    } 
    else {
        musique.setLoop(true);
        musique.setVolume(50.f); // Ajuster le volume si besoin 
        musique.play();
    }

    while (true) {
        afficherMenuPrincipal();
        int choix;
        std::cin >> choix;

        if (choix == 0) {
            break;
        }
        else if (choix == 1) {
            afficherMenuPlay();
            int choixPlay;
            std::cin >> choixPlay;

            if (choixPlay == 1) {
                // Mode Console
                int largeur = 20, hauteur = 20, maxIterations;
                std::string cheminFichier;
                std::cout << "Entrez le chemin du fichier: ";
                std::cin >> cheminFichier;

                std::cout << "Entrez le nombre d'iterations: ";
                std::cin >> maxIterations;

                GestionnaireDeFichier gf;
                gf.creerDossierIterations();

                JeuDeLaVie jeu(largeur, hauteur, maxIterations);
                jeu.chargerFichierConfiguration(cheminFichier);

                AfficheurConsole afficheurConsole;
                jeu.lancerSimulation(afficheurConsole);

                int score = jeu.calculerScore();
                scores.push_back(score);
                sauvegarderScores();

            }
            else if (choixPlay == 2) {
                // Mode Graphique
                afficherMenuGraphique();
                int choixGraph;
                std::cin >> choixGraph;

                int largeur = 20, hauteur = 20, maxIterations;
                std::cout << "Entrez le nombre d'iterations: ";
                std::cin >> maxIterations;

                GestionnaireDeFichier gf;
                gf.creerDossierIterations();

                JeuDeLaVie jeu(largeur, hauteur, maxIterations);

                if (choixGraph == 1) {
                    // Charger depuis un fichier
                    std::string cheminFichier;
                    std::cout << "Entrez le chemin du fichier: ";
                    std::cin >> cheminFichier;
                    jeu.chargerFichierConfiguration(cheminFichier);
                }
                else if (choixGraph == 2) {
                    // Grille interactive WASD
                    auto nouvelleGrille = editerGrilleInteractif(largeur, hauteur);
                    jeu.setGrille(nouvelleGrille);
                }
                else {
                    continue; // retour
                }

                AfficheurGraphique afficheurGraphique(25, largeur, hauteur);
                jeu.lancerSimulationGraphique(afficheurGraphique);

                int score = jeu.calculerScore();
                scores.push_back(score);
                sauvegarderScores();
            }

        }
        else if (choix == 2) {

            std::cout << "Tests unitaires en cours de developpement...\n";

        }
        else if (choix == 3) {
            // Afficher les scores
            afficherScores();
        }
    }

    return 0;
}
