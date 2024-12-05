#ifndef AFFICHEURCONSOLE_H
#define AFFICHEURCONSOLE_H

#include "IHM/Afficheur.h"
#include "SERVICE/GestionnaireDeFichier.h"

class AfficheurConsole : public Afficheur {
private:
    GestionnaireDeFichier gestionnaireFichier;

public:
    void afficher(const Grille& grille, int iteration) override;

private:
    std::vector<std::vector<bool>> convertirGrilleEnBool(const Grille& grille);
};

#endif // AFFICHEURCONSOLE_H
