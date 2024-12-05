#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include "Grille.h"
#include "Afficheur.h"
#include "AfficheurGraphique.h"

class JeuDeLaVie {
private:
    Grille grille;
    int maxIterations;

public:
    JeuDeLaVie(int largeur, int hauteur, int maxIterations);
    void chargerFichierConfiguration(const std::string& cheminFichier);
    void lancerSimulation(Afficheur& afficheur);
    void lancerSimulationGraphique(AfficheurGraphique& afficheur);
};

#endif // JEUDELAVIE_H
