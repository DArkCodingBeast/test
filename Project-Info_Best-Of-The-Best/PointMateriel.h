#include "ObjetPhysique.h"
#pragma once

class PointMateriel;

class GravitationConstante : public ChampForces{
private :

    Vecteur gravitation;

public :
    GravitationConstante(Vecteur const&);
    Vecteur force(PointMateriel const&, double);
};


class PointMateriel : ObjetPhysique{	

public:

PointMateriel(PointMateriel const&);
PointMateriel(Vecteur vect_etat,Vecteur vect_derivee,double masse,Vecteur ChampForce);
    const Vecteur Get_Position() const;
    const Vecteur Get_Derivative_Pos() const;
    const double Get_masse() const;
    const Vecteur Get_Champ() const;
    void set_vect_etat(Vecteur);
    Vecteur evolution(double);
};

std::ostream& operator<<(std::ostream& ,PointMateriel const&);



