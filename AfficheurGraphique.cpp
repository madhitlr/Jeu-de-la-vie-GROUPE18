#include "IHM/AfficheurGraphique.h"


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
    sf::RectangleShape Cellule(sf::Vector2f(tailleCellule - 1, tailleCellule - 1));

    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            if (grille.estVivante(x, y)) {
                Cellule.setFillColor(sf::Color::Magenta);
            }
            else {
                Cellule.setFillColor(sf::Color::Black);
            }
            Cellule.setPosition(x * tailleCellule, y * tailleCellule);
            window.draw(Cellule);
        }
    }
    window.display();
}
