#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\COMPOSANTS/Grille.h"

class Afficheur {
public:
    virtual void afficher(const Grille& grille, int iteration) = 0;
    virtual ~Afficheur() {}
};

#endif // AFFICHEUR_H
