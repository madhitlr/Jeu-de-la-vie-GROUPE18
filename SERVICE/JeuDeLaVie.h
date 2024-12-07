#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\COMPOSANTS\Grille.h"
#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\IHM\Afficheur.h"
#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\IHM\AfficheurGraphique.h"

class JeuDeLaVie {
private:
    Grille grille;
    int maxIterations;

public:
    JeuDeLaVie(int largeur, int hauteur, int maxIterations);
    void chargerFichierConfiguration(const std::string& cheminFichier);
    void lancerSimulation(Afficheur& afficheur);
    void lancerSimulationGraphique(AfficheurGraphique& afficheur);
    void setGrille(const std::vector<std::vector<std::shared_ptr<Cellule>>>& nouvelleGrille);
    int calculerScore() const;
};

#endif 