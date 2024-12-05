#include "AfficheurGraphique.h"

AfficheurGraphique::AfficheurGraphique(int tailleCellule, int largeur, int hauteur)
    : tailleCellule(tailleCellule),
    window(sf::VideoMode(largeur* tailleCellule, hauteur* tailleCellule), "Jeu de la Vie") {
    window.setFramerateLimit(60);
}

sf::RenderWindow& AfficheurGraphique::getWindow() {
    return window;
}

void AfficheurGraphique::afficher(const Grille& grille, int iteration) {
    window.clear();
    sf::RectangleShape cellule(sf::Vector2f(tailleCellule - 1, tailleCellule - 1));

    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            if (grille.estVivante(x, y)) {
                cellule.setFillColor(sf::Color::Green);
            }
            else {
                cellule.setFillColor(sf::Color::Black);
            }
            cellule.setPosition(x * tailleCellule, y * tailleCellule);
            window.draw(cellule);
        }
    }
    window.display();
}
