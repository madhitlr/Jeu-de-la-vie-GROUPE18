#ifndef GRILLE_H
#define GRILLE_H

#include "Cellule.h"
#include <vector>
#include <memory>
#include <string>

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
};

#endif
