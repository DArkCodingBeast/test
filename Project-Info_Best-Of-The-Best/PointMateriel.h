#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#pragma once


class GravitationConstante{
private :

    std::array<double,3> gravitation;

public :
    GravitationConstante(std::array<double, 3> const&);
    std::array<double,3> force(PointMateriel const&, double );
};




class PointMateriel{	
private:

    std::array<double,3> vect_etat;
    std::array<double,3> vect_derivee;
    double masse;
    std::array<double,3> ChampForce;

public:

PointMateriel(PointMateriel const&);
    const std::array<double,3> Get_Position() const;
    const std::array<double,3> Get_Derivative_Pos() const;
    const double Get_masse() const;
    const std::array<double,3> Get_Champ() const;
    void set_vect_etat(std::array<double,3>);
    std::array<double,3> evolution(double);
};


std::ostream& operator<<(std::ostream& ,std::array<double,3> const&);
std::ostream& operator<<(std::ostream& ,PointMateriel const&);



