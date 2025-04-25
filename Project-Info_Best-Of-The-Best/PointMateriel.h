#include "ObjetPhysique.h"
#pragma once

class PointMateriel;
class GravitationConstante : public ChampForces{
private :
    Vecteur gravitation;

public :
    GravitationConstante(Vecteur const&);
    Vecteur force(ObjetPhysique const&, double) override;
};


class PointMateriel : public ObjetPhysique{	
public:
    PointMateriel(PointMateriel const&);
    PointMateriel(Vecteur , double , double , double ,GravitationConstante & , Contrainte & );
    Vecteur evolution(double);};




