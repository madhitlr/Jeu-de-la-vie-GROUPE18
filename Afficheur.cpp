#include "IHM/Afficheur.h"
#include <iostream>

void AfficheurConsole::afficher(const Grille& grille, int iteration) {
    std::cout << "Itération " << iteration + 1 << " :\n";
    grille.afficherConsole();
    std::cout << "\n";

    auto grilleBool = convertirGrilleEnBool(grille);
    std::string nomFichier = "iterations/iteration_" + std::to_string(iteration + 1) + ".txt";
    gestionnaireFichier.sauvegarderIteration(nomFichier, grilleBool);
}

std::vector<std::vector<bool>> AfficheurConsole::convertirGrilleEnBool(const Grille& grille) {
    std::vector<std::vector<bool>> resultat(grille.getHauteur(), std::vector<bool>(grille.getLargeur()));
    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            resultat[y][x] = grille.estVivante(x, y);
        }
    }
    return resultat;
}

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
            cellule.setFillColor(grille.estVivante(x, y) ? sf::Color::Green : sf::Color::Black);
            cellule.setPosition(x * tailleCellule, y * tailleCellule);
            window.draw(cellule);
        }
    }

    window.display();
}
