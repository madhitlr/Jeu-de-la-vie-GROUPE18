#include "C:\Users\DELL VOSTRO\source\repos\Jeu-de-la-vie-GROUPE18\COMPOSANTS\Cellule.h"

Cellule::Cellule(bool etat) : vivante(etat) {}
Cellule::~Cellule() {}

bool Cellule::estVivante() const { return vivante; }
void Cellule::definirEtat(bool etat) { vivante = etat; }

int Cellule::indiceTorique(int indice, int taille) {
    return (indice + taille) % taille;
}

CelluleStandard::CelluleStandard(bool etat) : Cellule(etat) {}
std::shared_ptr<Cellule> CelluleStandard::clone() const {
    return std::make_shared<CelluleStandard>(*this);
}