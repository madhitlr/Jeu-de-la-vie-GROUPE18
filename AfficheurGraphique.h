#ifndef AFFICHEURGRAPHIQUE_H
#define AFFICHEURGRAPHIQUE_H

#include "IHM/Afficheur.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class AfficheurGraphique : public Afficheur {
private:
    sf::RenderWindow window;
    int tailleCellule;
    sf::Font font; // Police pour afficher du texte
    sf::Text playText, resetText, quitText; // Boutons
    sf::RectangleShape playButton, resetButton, quitButton;

public:
    AfficheurGraphique(int tailleCellule, int largeur, int hauteur);
    sf::RenderWindow& getWindow();
    void afficher(const Grille& grille, int iteration) override;
    bool handleEvents(Grille& grille, bool& running); // Gère les événements utilisateur
};

#endif // AFFICHEURGRAPHIQUE_H
