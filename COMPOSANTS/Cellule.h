#ifndef CELLULE_H
#define CELLULE_H

#include <memory>

class Cellule {
protected:
    bool vivante;

public:
    Cellule(bool etat);
    virtual ~Cellule();

    bool estVivante() const;
    void definirEtat(bool etat);

    virtual std::shared_ptr<Cellule> clone() const = 0;

    static int indiceTorique(int indice, int taille);
};

class CelluleStandard : public Cellule {
public:
    CelluleStandard(bool etat);
    std::shared_ptr<Cellule> clone() const override;
};

#endif // CELLULE_H
