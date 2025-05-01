#include "Vecteur.h"
#pragma once

//prototypes
class GravitationConstante;
class Contrainte;
class ObjetPhysique;

class PointMateriel : public ObjetPhysique {	
    public:
        PointMateriel(PointMateriel const&);
        PointMateriel(Vecteur, double, double, unsigned int ,GravitationConstante&, Contrainte&);
        Vecteur evolution(double);
        void affiche(std::ostream&) const;
    };