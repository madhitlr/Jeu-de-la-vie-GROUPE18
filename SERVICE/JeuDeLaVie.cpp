#include "JeuDeLaVie.h"

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
    float delay = 0.6f;

 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        afficheur.afficher(grille, iteration);

        if (clock.getElapsedTime().asSeconds() >= delay) {
            // Compter les cellules vivantes
            int vivantes = 0;
            for (int y = 0; y < grille.getHauteur(); ++y) {
                for (int x = 0; x < grille.getLargeur(); ++x) {
                    if (grille.estVivante(x, y)) {
                        vivantes++;
                    }
                }
            }

            // Vérifier si toutes les cellules sont mortes
            if (vivantes == 0) {
                std::cout << "\nSimulation terminee : toutes les cellules sont mortes.\n";
                return; // Quitter la simulation
            }

            // Vérifier la stabilité de la grille


            // Sauvegarder l'état actuel pour la comparaison


            // Actualiser la grille et redémarrer le chronomètre
            grille.actualiserEtat();
            clock.restart();
            iteration++;

            // Vérifier le nombre maximum d'itérations
            if (iteration >= maxIterations) {
                std::cout << "\nSimulation terminee : maximum d'itérations atteint.\n";
                return; // Quitter la simulation
            }
        }
    }
}

void JeuDeLaVie::setGrille(const std::vector<std::vector<std::shared_ptr<Cellule>>>& nouvelleGrille) {
    grille.changerGrille(nouvelleGrille);
}

int JeuDeLaVie::calculerScore() const {
    int vivantes = 0;
    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            if (grille.estVivante(x, y)) vivantes++;
        }
    }
    return vivantes;
}