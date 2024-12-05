#include "SERVICE/JeuDeLaVie.h"

JeuDeLaVie::JeuDeLaVie(int largeur, int hauteur, int maxIterations)
    : grille(largeur, hauteur), maxIterations(maxIterations) {
}

void JeuDeLaVie::chargerFichierConfiguration(const std::string& cheminFichier) {
    grille.initialiserDepuisFichier(cheminFichier);
}

void JeuDeLaVie::lancerSimulation(Afficheur& afficheur) {
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        afficheur.afficher(grille, iteration);
        grille.actualiserEtat();
    }
}

void JeuDeLaVie::lancerSimulationGraphique(AfficheurGraphique& afficheur) {
    sf::RenderWindow& window = afficheur.getWindow();
    int iteration = 0;

    sf::Clock clock;
    float delay = 0.2f; // délai en secondes entre les itérations

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        afficheur.afficher(grille, iteration);

        if (clock.getElapsedTime().asSeconds() >= delay) {
            grille.actualiserEtat();
            clock.restart();
            iteration++;

            if (iteration >= maxIterations) {
                window.close();
            }
        }
    }
}
