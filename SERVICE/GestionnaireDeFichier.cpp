#include "GestionnaireDeFichier.h"
#include <filesystem>
#include <fstream>
#include <iostream>

void GestionnaireDeFichier::creerDossierIterations() {
    std::string dossier = "iterations";
    if (!std::filesystem::exists(dossier)) {
        std::filesystem::create_directory(dossier);
        std::cout << "Dossier 'iterations' créé.\n";
    }
}

void GestionnaireDeFichier::sauvegarderIteration(const std::string& nomFichier, const std::vector<std::vector<bool>>& grille) {
    std::ofstream fichier(nomFichier);
    if (fichier.is_open()) {
        for (const auto& ligne : grille) {
            for (bool cellule : ligne) {
                fichier << (cellule ? "1 " : "0 ");
            }
            fichier << "\n";
        }
        fichier.close();
    }
    else {
        std::cerr << "Erreur : Impossible de créer le fichier " << nomFichier << ".\n";
    }
}
