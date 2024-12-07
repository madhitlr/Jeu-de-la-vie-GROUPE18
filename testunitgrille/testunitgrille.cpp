#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\testunitgrille/pch.h"
#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\COMPOSANTS\Grille.h"
#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\COMPOSANTS\Cellule.h"
#include <vector>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsGrille
{
    TEST_CLASS(TestGrilleIteration)
    {
    public:
        // Test pour v�rifier la validit� de la grille apr�s une it�ration
        TEST_METHOD(TestGrilleApresUneIteration)
        {
            // �tape 1 : Initialisez une grille 3x3 avec un motif
            Grille grille(3, 3);
            grille.initialiserDepuisFichier("C:\\Users\\DELL VOSTRO\\source\\repos\\Jeu-de-la-vie-GROUPE18\\etat_initial.txt");

            // �tape 2 : Stockez l'�tat initial des cellules
            std::vector<std::vector<bool>> etatInitial(3, std::vector<bool>(3, false));
            for (int y = 0; y < grille.getHauteur(); ++y) {
                for (int x = 0; x < grille.getLargeur(); ++x) {
                    etatInitial[y][x] = grille.estVivante(x, y);
                }
            };
            // �tape 3 : Passez � l'�tat suivant
            grille.actualiserEtat();

            // �tape 4 : V�rifiez les r�gles du Jeu de la Vie
            for (int y = 0; y < grille.getHauteur(); ++y) {
                for (int x = 0; x < grille.getLargeur(); ++x) {
                    bool etatActuel = grille.estVivante(x, y);
                    int voisinsVivants = 0;

                    // Comptez les voisins vivants
                    for (int dy = -1; dy <= 1; ++dy) {
                        for (int dx = -1; dx <= 1; ++dx) {
                            if (dx == 0 && dy == 0) continue; // Ignorez la cellule elle-m�me
                            int nx = Cellule::indiceTorique(x + dx, grille.getLargeur());
                            int ny = Cellule::indiceTorique(y + dy, grille.getHauteur());
                            if (etatInitial[ny][nx]) voisinsVivants++;
                        }
                    }

                    // V�rifiez les r�gles :
                    if (etatInitial[y][x]) {
                        Assert::IsTrue(etatActuel == (voisinsVivants == 2 || voisinsVivants == 3),
                            L"Erreur : Une cellule vivante ne respecte pas les r�gles de survie.");
                    }
                    else {
                        Assert::IsTrue(etatActuel == (voisinsVivants == 3),
                            L"Erreur : Une cellule morte ne respecte pas les r�gles de naissance.");
                    }
                }
            }
        }
    };
}