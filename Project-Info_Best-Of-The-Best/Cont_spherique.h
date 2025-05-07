#include "ObjetPhysique.h"
#pragma once

class ObjetPhysique;

class Cont_spherique : public Contrainte
{private :
	double rayon;
	
public:
	Cont_spherique(double );
    Vecteur applique_force(ObjetPhysique const&, Vecteur , double ) override;
    Vecteur position(ObjetPhysique const& ) override;
    Vecteur vitesse(ObjetPhysique const& ) override;
    void affiche(std::ostream&) const;
};


