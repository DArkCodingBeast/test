#include <iostream>
#include <fstream>
#include <vector>
#pragma once

class PointMateriel;

class GravitationConstante{
private :

    Vecteur gravitation;

public :
    GravitationConstante(Vecteur const&);
    Vecteur force(PointMateriel const&, double );
};




class PointMateriel{	
private:

    Vecteur vect_etat;
    Vecteur vect_derivee;
    double masse;
    Vecteur ChampForce;

public:

PointMateriel(PointMateriel const&);
    const Vecteur Get_Position() const;
    const Vecteur Get_Derivative_Pos() const;
    const double Get_masse() const;
    const Vecteur Get_Champ() const;
    void set_vect_etat(Vecteur);
    Vecteur evolution(double);
};

std::ostream& operator<<(std::ostream& ,PointMateriel const&);



