#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\COMPOSANTS\Grille.h"
#include <fstream>
#include <iostream>

Grille::Grille(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
    cellules.resize(hauteur, std::vector<std::shared_ptr<Cellule>>(largeur));
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            cellules[y][x] = std::make_shared<CelluleStandard>(false);
        }
    }
}

void Grille::initialiserDepuisFichier(const std::string& cheminFichier) {
    std::ifstream fichier(cheminFichier);
    if (!fichier) {
        std::cerr << "Erreur lors de l'ouverture du fichier.\n";
        return;
    }

    fichier >> hauteur >> largeur;
    cellules.clear();
    cellules.resize(hauteur, std::vector<std::shared_ptr<Cellule>>(largeur));

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            int etat;
            fichier >> etat;
            cellules[y][x] = std::make_shared<CelluleStandard>(etat == 1);
        }
    }
}

void Grille::actualiserEtat() {
    // Créer une copie profonde de la grille actuelle
    std::vector<std::vector<std::shared_ptr<Cellule>>> ancienneGrille(hauteur, std::vector<std::shared_ptr<Cellule>>(largeur));

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            ancienneGrille[y][x] = cellules[y][x]->clone();
        }
    }

    // Mise à jour de l'état des cellules
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            int vivantes = 0;

            // Compter les voisins vivants dans l'ancienne grille
            for (const auto& voisin : getVoisins(x, y, ancienneGrille)) {
                if (voisin->estVivante()) {
                    ++vivantes;
                }
            }

            // Appliquer les règles de Conway
            if (ancienneGrille[y][x]->estVivante()) {
                cellules[y][x]->definirEtat(vivantes == 2 || vivantes == 3);
            }
            else {
                cellules[y][x]->definirEtat(vivantes == 3);
            }
        }
    }
}

int Grille::getLargeur() const { return largeur; }
int Grille::getHauteur() const { return hauteur; }
bool Grille::estVivante(int x, int y) const { return cellules[y][x]->estVivante(); }

void Grille::afficherConsole() const {
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            std::cout << (cellules[y][x]->estVivante() ? "1 " : "0 ");
        }
        std::cout << "\n";
    }
}

std::vector<std::shared_ptr<Cellule>> Grille::getVoisins(int x, int y, const std::vector<std::vector<std::shared_ptr<Cellule>>>& grille) const {
    std::vector<std::shared_ptr<Cellule>> voisins;

    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;

            int nx = Cellule::indiceTorique(x + dx, largeur);
            int ny = Cellule::indiceTorique(y + dy, hauteur);

            voisins.push_back(grille[ny][nx]);
        }
    }

    return voisins;
}


void Grille::changerGrille(const std::vector<std::vector<std::shared_ptr<Cellule>>>& nouvelle) {
    cellules = nouvelle;
}
