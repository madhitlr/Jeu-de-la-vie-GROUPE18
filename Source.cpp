#include <SFML/Audio.hpp>
#include <iostream>

int main() {
    sf::Music musique;

    // Chemin du fichier audio (modifiez le chemin si nécessaire)
    std::string cheminFichier = "C:\\Users\\PC-PHONE\\Desktop\\miaw\\audio\\meow.mp3";


    // Charger la musique
    if (!musique.openFromFile(cheminFichier)) {
        std::cerr << "Erreur : Impossible de charger la musique depuis " << cheminFichier << std::endl;
        return 1; // Sortir avec une erreur
    }

    // Jouer la musique
    musique.play();
    std::cout << "Lecture de la musique... Appuyez sur une touche pour quitter." << std::endl;

    // Garder le programme actif tant que la musique joue
    while (musique.getStatus() == sf::SoundSource::Playing) {
        sf::sleep(sf::milliseconds(100));
    }

    return 0; // Succès
}
