#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\PC-PHONE\Desktop\miaw/COMPOSANTS/Grille.cpp"
#include "C:\Users\PC-PHONE\Desktop\miaw/COMPOSANTS/Cellule.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyProjectTests
{
    TEST_CLASS(GrilleTests)
    {
    public:

        TEST_METHOD(TestInitialisationGrille)
        {

            int largeur = 10;
            int hauteur = 10;
            Grille grille(largeur, hauteur);

            Assert::AreEqual(largeur, grille.getLargeur());
            Assert::AreEqual(hauteur, grille.getHauteur());

            for (int y = 0; y < hauteur; ++y) {
                for (int x = 0; x < largeur; ++x) {
                    Assert::IsFalse(grille.estVivante(x, y));
                }
            }
        }
        TEST_METHOD(TestIterationGrille)
        {
            // Arrange
            Grille grille(3, 3);

            // Initialisation du motif vertical
            std::vector<std::vector<std::shared_ptr<Cellule>>> config(3, std::vector<std::shared_ptr<Cellule>>(3));
            for (int y = 0; y < 3; ++y) {
                for (int x = 0; x < 3; ++x) {
                    config[y][x] = std::make_shared<CelluleStandard>(false);
                }
            }

            config[0][1]->definirEtat(true);
            config[1][1]->definirEtat(true);
            config[2][1]->definirEtat(true);
            grille.changerGrille(config);

            grille.actualiserEtat();


            for (int y = 0; y < 3; ++y) {
                for (int x = 0; x < 3; ++x) {
                    Assert::IsTrue(grille.estVivante(x, y));
                }
            }
        }
        TEST_METHOD(TestMotifStableBloc)
        {
            Grille grille(3, 3);

            // Configuration du bloc 2x2 :
            // (x,y)
            // 0,0 0,1 0,2
            // 1,0 1,1 1,2
            // 2,0 2,1 2,2
            std::vector<std::vector<std::shared_ptr<Cellule>>> config(3, std::vector<std::shared_ptr<Cellule>>(3));
            for (int y = 0; y < 3; ++y) {
                for (int x = 0; x < 3; ++x) {
                    config[y][x] = std::make_shared<CelluleStandard>(false);
                }
            }

            // On rend vivantes les cellules au centre (1,1), (2,1), (1,2), (2,2)
            config[1][1]->definirEtat(true);
            config[1][2]->definirEtat(true);
            config[2][1]->definirEtat(true);
            config[2][2]->definirEtat(true);

            grille.changerGrille(config);


            grille.actualiserEtat(); // Après cette itération, le bloc doit rester identique

            // Vérifions que le bloc est toujours là
            Assert::IsFalse(grille.estVivante(0, 0));
            Assert::IsFalse(grille.estVivante(0, 1));
            Assert::IsFalse(grille.estVivante(0, 2));

            Assert::IsFalse(grille.estVivante(1, 0));
            Assert::IsTrue(grille.estVivante(1, 1));
            Assert::IsTrue(grille.estVivante(1, 2));

            Assert::IsFalse(grille.estVivante(2, 0));
            Assert::IsTrue(grille.estVivante(2, 1));
            Assert::IsTrue(grille.estVivante(2, 2));
        }
    };
}