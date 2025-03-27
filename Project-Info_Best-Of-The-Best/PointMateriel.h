#include <iostream>
#include <fstream>
#include <vector>
#include <array>



class GravitationConstante{
private :

    std::array<double,3> gravitation;

public :
    GravitationConstante(std::array<double, 3> const& grav);
    std::array<double,3> force(PointMateriel const& p1, double temps);
};




class PointMateriel{	
private:

    std::array<double,3> vect_etat;
    std::array<double,3> vect_derivee;
    double masse;
    std::array<double,3> ChampForce;

public:

PointMateriel(PointMateriel const& autre);
    const std::array<double,3> Get_Position() const;
    const std::array<double,3> Get_Derivative_Pos() const;
    const double Get_masse() const;
    const std::array<double,3> Get_Champ() const;
    void set_vect_etat(std::array<double,3> autre);
    std::array<double,3> evolution(double temps);
};

std::ostream& operator<<(std::ostream& sortie,std::array<double,3> const& autre);
std::ostream& operator<<(std::ostream& sortie,PointMateriel const& autre);



