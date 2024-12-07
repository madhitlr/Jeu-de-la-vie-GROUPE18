#include "pch.h"
#include <gtest/gtest.h>
#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\COMPOSANTS\Grille.h"
#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\COMPOSANTS\Cellule.h"

class GrilleTest : public ::testing::Test {
protected:
    // Méthode pour initialiser une grille avec un motif "Glider"
    void initialiserGrilleAvecGlider(Grille& grille) {
        grille.definirEtat(1, 2, true);
        grille.definirEtat(2, 3, true);
        grille.definirEtat(3, 1, true);
        grille.definirEtat(3, 2, true);
        grille.definirEtat(3, 3, true);
    }
};

// Test pour vérifier le nombre de cellules vivantes
TEST_F(GrilleTest, TestCellulesVivantes) {
    Grille grille(6, 6);
    initialiserGrilleAvecGlider(grille);

    int cellulesVivantes = 0;
    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            if (grille.estVivante(x, y)) {
                cellulesVivantes++;
            }
        }
    }

    EXPECT_EQ(cellulesVivantes, 5); // Vérifie qu'il y a 5 cellules vivantes
}

// Test pour vérifier les voisins en mode torique
TEST_F(GrilleTest, TestVoisinsToroique) {
    Grille grille(5, 5);

    // Activer les coins de la grille
    grille.definirEtat(0, 0, true); // Coin supérieur gauche
    grille.definirEtat(4, 4, true); // Coin inférieur droit

    int voisinsVivantsHautGauche = 0;
    int voisinsVivantsBasDroit = 0;

    // Compter les voisins vivants pour le coin supérieur gauche (0,0)
    auto voisinsHautGauche = grille.getVoisins(0, 0, grille);
    for (const auto& voisin : voisinsHautGauche) {
        if (voisin->estVivante()) {
            voisinsVivantsHautGauche++;
        }
    }

    // Compter les voisins vivants pour le coin inférieur droit (4,4)
    auto voisinsBasDroit = grille.getVoisins(4, 4, grille);
    for (const auto& voisin : voisinsBasDroit) {
        if (voisin->estVivante()) {
            voisinsVivantsBasDroit++;
        }
    }

    EXPECT_EQ(voisinsVivantsHautGauche, 1); // Vérifie qu'il y a 1 voisin vivant pour (0,0)
    EXPECT_EQ(voisinsVivantsBasDroit, 1);   // Vérifie qu'il y a 1 voisin vivant pour (4,4)
}

// Test pour vérifier la génération suivante d'un glider
TEST_F(GrilleTest, TestGenerationSuivanteGlider) {
    Grille grille(6, 6);
    initialiserGrilleAvecGlider(grille);

    Grille grilleAttendue(6, 6);
    grilleAttendue.definirEtat(2, 1, true);
    grilleAttendue.definirEtat(3, 2, true);
    grilleAttendue.definirEtat(3, 3, true);
    grilleAttendue.definirEtat(2, 3, true);
    grilleAttendue.definirEtat(4, 2, true);

    grille.actualiserEtat();

    // Vérifie chaque cellule entre la grille actuelle et la grille attendue
    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            EXPECT_EQ(grille.estVivante(x, y), grilleAttendue.estVivante(x, y));
        }
    }
}

// Main pour exécuter les tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}