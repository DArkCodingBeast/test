#include "ObjetPhysique.h"
#pragma once

class ObjetPhysique;

class Aller_De_lavant : public Contrainte
{private: 
double vit;
    double temps

public:
    Aller_De_lavant(double, double = 0 );
    Vecteur position(ObjetPhysique const& ) override;
    Vecteur vitesse(ObjetPhysique const& ) override;
    void affiche(std::ostream&) const;
};
