#include "ObjetPhysique.h"
#pragma once

class ObjetPhysique;

class Aller_De_lavant : public Contrainte
{
public:
	Cont_spherique(double );
    Vecteur position(ObjetPhysique const& ) override;
    Vecteur vitesse(ObjetPhysique const& ) override;
    void affiche(std::ostream&) const;
};
