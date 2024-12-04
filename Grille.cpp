#include "COMPOSANTS/Grille.h"
#include <fstream>
#include <iostream>

Grille::Grille(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
    cellules.resize(hauteur, std::vector<std::shared_ptr<Cellule>>(largeur));
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            cellules[i][j] = std::make_shared<CelluleStandard>(false);
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
    cellules.resize(hauteur, std::vector<std::shared_ptr<Cellule>>(largeur));
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            int etat;
            fichier >> etat;
            cellules[i][j] = std::make_shared<CelluleStandard>(etat == 1);
        }
    }
}

void Grille::actualiserEtat() {
    auto ancienneGrille = cellules;

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            int vivantes = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = Cellule::indiceTorique(j + dx, largeur);
                    int ny = Cellule::indiceTorique(i + dy, hauteur);
                    if (ancienneGrille[ny][nx]->estVivante()) {
                        ++vivantes;
                    }
                }
            }
            cellules[i][j]->definirEtat((ancienneGrille[i][j]->estVivante() && (vivantes == 2 || vivantes == 3)) || (!ancienneGrille[i][j]->estVivante() && vivantes == 3));
        }
    }
}

int Grille::getLargeur() const { return largeur; }
int Grille::getHauteur() const { return hauteur; }
bool Grille::estVivante(int x, int y) const { return cellules[y][x]->estVivante(); }
void Grille::afficherConsole() const {
    for (const auto& ligne : cellules) {
        for (const auto& cellule : ligne) {
            std::cout << (cellule->estVivante() ? "1 " : "0 ");
        }
        std::cout << "\n";
    }
}
