#include "IHM/AfficheurConsole.h"
#include "COMPOSANTS/Grille.h"
#include <iostream>
#include <fstream>

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
