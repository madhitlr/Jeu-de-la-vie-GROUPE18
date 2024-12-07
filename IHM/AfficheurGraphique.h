#ifndef AFFICHEURGRAPHIQUE_H
#define AFFICHEURGRAPHIQUE_H

#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\IHM\Afficheur.h"
#include <SFML/Graphics.hpp>

class AfficheurGraphique : public Afficheur {
private:
    sf::RenderWindow window;
    int tailleCellule;

public:
    AfficheurGraphique(int tailleCellule, int largeur, int hauteur);
    sf::RenderWindow& getWindow();
    void afficher(const Grille& grille, int iteration) override;
};

#endif // AFFICHEURGRAPHIQUE_H
