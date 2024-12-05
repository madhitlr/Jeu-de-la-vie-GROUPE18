#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include "C:\Users\PC-PHONE\Desktop\miaw\COMPOSANTS/Grille.h"
#include "C:\Users\PC-PHONE\Desktop\miaw\IHM/Afficheur.h"
#include "C:\Users\PC-PHONE\Desktop\miaw\IHM/AfficheurGraphique.h"

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
