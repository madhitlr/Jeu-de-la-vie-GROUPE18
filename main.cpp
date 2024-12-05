#include "SERVICE/JeuDeLaVie.h"
#include "IHM/AfficheurConsole.h"
#include "IHM/AfficheurGraphique.h"
#include "SERVICE/GestionnaireDeFichier.h"
#include <iostream>

int main() {
    int largeur = 20, hauteur = 20, maxIterations;
    std::string cheminFichier = "C:\\Users\\PC-PHONE\\Desktop\\miaw\\etat_initial.txt";

    std::cout << "Entrez le nombre d'itérations : ";
    std::cin >> maxIterations;

    GestionnaireDeFichier gestionnaireFichier;
    gestionnaireFichier.creerDossierIterations();

    JeuDeLaVie jeu(largeur, hauteur, maxIterations);
    jeu.chargerFichierConfiguration(cheminFichier);

    std::cout << "Choisissez un mode :\n1. Mode Console\n2. Mode Graphique\n> ";
    int choix;
    std::cin >> choix;

    if (choix == 1) {
        AfficheurConsole afficheurConsole;
        jeu.lancerSimulation(afficheurConsole);
    }
    else if (choix == 2) {
        AfficheurGraphique afficheurGraphique(25, largeur, hauteur);
        jeu.lancerSimulationGraphique(afficheurGraphique);
    }
    else {
        std::cerr << "Choix invalide.\n";
    }

    return 0;
}
