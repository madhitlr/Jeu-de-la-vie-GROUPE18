#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include "COMPOSANTS/Grille.h"
#include "SERVICE/GestionnaireDeFichier.h"
#include <SFML/Graphics.hpp>

class Afficheur {
public:
    virtual void afficher(const Grille& grille, int iteration) = 0;
    virtual ~Afficheur() {}
};

class AfficheurConsole : public Afficheur {
private:
    GestionnaireDeFichier gestionnaireFichier;

public:
    void afficher(const Grille& grille, int iteration) override;

    std::vector<std::vector<bool>> convertirGrilleEnBool(const Grille& grille);
};

class AfficheurGraphique : public Afficheur {
private:
    sf::RenderWindow window;
    int tailleCellule;

public:
    AfficheurGraphique(int tailleCellule, int largeur, int hauteur);
    sf::RenderWindow& getWindow();
    void afficher(const Grille& grille, int iteration) override;
};

#endif
