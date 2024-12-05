#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include "C:\Users\PC-PHONE\Desktop\miaw\COMPOSANTS/Grille.h"

class Afficheur {
public:
    virtual void afficher(const Grille& grille, int iteration) = 0;
    virtual ~Afficheur() {}
};

#endif // AFFICHEUR_H
