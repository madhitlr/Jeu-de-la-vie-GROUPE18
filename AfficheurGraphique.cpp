#include "IHM/AfficheurGraphique.h"
#include <sstream>

AfficheurGraphique::AfficheurGraphique(int tailleCellule, int largeur, int hauteur)
    : tailleCellule(tailleCellule),
    window(sf::VideoMode(largeur* tailleCellule, hauteur* tailleCellule + 50), "Jeu de la Vie"),
    font() {
    window.setFramerateLimit(60);

    // Charger une police
    if (!font.loadFromFile("C:\\Users\\PC-PHONE\\Desktop\\miaw\\Arimo,Roboto\\Arimo\\Arimo-Italic-VariableFont_wght.ttf")) {}
}

sf::RenderWindow& AfficheurGraphique::getWindow() {
    return window;
}

void AfficheurGraphique::afficher(const Grille& grille, int iteration) {
    int vivantes = 0, mortes = 0;

    // Gérer les événements SFML (fermeture de la fenêtre)
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return;
        }
    }

    // Effacer la fenêtre
    window.clear(sf::Color::White);

    // Dessiner les cellules
    sf::RectangleShape cellule(sf::Vector2f(tailleCellule - 1, tailleCellule - 1));
    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            if (grille.estVivante(x, y)) {
                cellule.setFillColor(sf::Color::Magenta);
                vivantes++;
            }
            else {
                cellule.setFillColor(sf::Color::Black);
                mortes++;
            }
            cellule.setPosition(x * tailleCellule, y * tailleCellule);
            window.draw(cellule);
        }
    }


    sf::Vertex line[2];
    for (int i = 0; i <= grille.getLargeur(); ++i) {
        line[0] = sf::Vertex(sf::Vector2f(i * tailleCellule, 0), sf::Color::Black);
        line[1] = sf::Vertex(sf::Vector2f(i * tailleCellule, grille.getHauteur() * tailleCellule), sf::Color::White);
        window.draw(line, 2, sf::Lines);
    }
    for (int i = 0; i <= grille.getHauteur(); ++i) {
        line[0] = sf::Vertex(sf::Vector2f(0, i * tailleCellule), sf::Color::Black);
        line[1] = sf::Vertex(sf::Vector2f(grille.getLargeur() * tailleCellule, i * tailleCellule), sf::Color::White);
        window.draw(line, 2, sf::Lines);
    }

    // Afficher le texte (itération, vivantes, mortes)
    sf::Text texte;
    texte.setFont(font);
    texte.setCharacterSize(20);
    texte.setFillColor(sf::Color::Black);

    std::ostringstream infos;
    infos << "Iteration: " << iteration << "  Vivantes: " << vivantes << "  Mortes: " << mortes;

    texte.setString(infos.str());
    texte.setPosition(10, grille.getHauteur() * tailleCellule + 5); // Texte en bas
    window.draw(texte);

    // Afficher tout
    window.display();
}