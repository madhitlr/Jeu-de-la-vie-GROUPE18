#ifndef GRILLE_H
#define GRILLE_H

#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\COMPOSANTS\Cellule.h"
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
    void changerGrille(const std::vector<std::vector<std::shared_ptr<Cellule>>>& nouvelle);


    int getLargeur() const;
    int getHauteur() const;
    bool estVivante(int x, int y) const;
    void afficherConsole() const;

private:
    std::vector<std::shared_ptr<Cellule>> getVoisins(int x, int y, const std::vector<std::vector<std::shared_ptr<Cellule>>>& grille) const;
};

#endif // GRILLE_H
