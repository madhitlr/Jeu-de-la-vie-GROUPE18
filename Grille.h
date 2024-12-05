#ifndef GRILLE_H
#define GRILLE_H

#include "COMPOSANTS/Cellule.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class Grille {
private:
    int largeur, hauteur;
    std::vector<std::vector<std::shared_ptr<Cellule>>> cellules;

public:
    Grille(int largeur, int hauteur);
    void initialiserDepuisFichier(const std::string& cheminFichier);
    void actualiserEtat();

    int getLargeur() const;
    int getHauteur() const;
    bool estVivante(int x, int y) const;
    void afficherConsole() const;

private:
    std::vector<std::shared_ptr<Cellule>> getVoisins(int x, int y, const std::vector<std::vector<std::shared_ptr<Cellule>>>& grille) const;
};

#endif // GRILLE_H