#ifndef GESTIONNAIREDEFICHIER_H
#define GESTIONNAIREDEFICHIER_H

#include <string>
#include <vector>
#include <filesystem>

class GestionnaireDeFichier {
public:
    void creerDossierIterations();
    void sauvegarderIteration(const std::string& nomFichier, const std::vector<std::vector<bool>>& grille);
};

#endif
