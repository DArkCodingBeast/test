#include "Vecteur.h"
#include "ChampForces.h"
#include "Contrainte.h"
#include "ObjetPhysique.h"
#pragma once


class PointMateriel : public ObjetPhysique {	
    public:
        PointMateriel(PointMateriel const&);
        PointMateriel(Vecteur, double, double, unsigned int ,GravitationConstante&, Contrainte&);
        Vecteur evolution(double);
        void affiche(std::ostream&) const;
    };