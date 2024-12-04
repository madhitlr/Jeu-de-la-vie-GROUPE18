#ifndef JEUDALAVIE_H
#define JEUDALAVIE_H

#include "COMPOSANTS/Grille.h"
#include "IHM/Afficheur.h"

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

#endif
