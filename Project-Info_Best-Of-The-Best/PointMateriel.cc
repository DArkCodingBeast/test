#include <iostream>
#include <fstream>
#include <vector>
#include <array>

class PointMateriel;


class GravitationConstante
{
private :

std::array<double,3> gravitation;



public :

GravitationConstante(std::array<double, 3> const& grav)
: gravitation(grav) {}


std::array<double,3> force(PointMateriel const& p1, double temps);




};


class PointMateriel
{
	
private:

std::array<double,3> vect_etat;
std::array<double,3> vect_derivee;
double masse;
std::array<double,3> ChampForce;

public:

PointMateriel(PointMateriel const& autre)
: vect_etat(autre.vect_etat), vect_derivee(autre.vect_derivee), masse(autre.masse), ChampForce(autre.ChampForce) {}


const std::array<double,3> Get_Position() const
{return vect_etat;}
	
const std::array<double,3> Get_Derivative_Pos() const
{return vect_derivee;}	
	
const double Get_masse() const
{return masse;}

const std::array<double,3> Get_Champ() const
{return ChampForce;}


void set_vect_etat(std::array<double,3> autre)
{vect_etat = autre;}

std::array<double,3> evolution(double temps)
{return {ChampForce[0]/masse,ChampForce[1]/masse,ChampForce[2]/masse};}




};



std::array<double,3> GravitationConstante::force(PointMateriel const& p1, double temps) {
    return {gravitation[0] * p1.Get_masse(),
            gravitation[1] * p1.Get_masse(),
            gravitation[2] * p1.Get_masse()};
}











std::ostream& operator<<(std::ostream& sortie,std::array<double,3> const& autre)
{sortie << "[";
    for (size_t i = 0; i < autre.size(); ++i) {
        sortie << autre[i];
        if (i != autre.size() - 1) {
            sortie << ", ";
        }
    }
    sortie << "]";
    return sortie;}



std::ostream& operator<<(std::ostream& sortie,PointMateriel const& autre)

{sortie << "le position du point matériel est : " << autre.Get_Position() << std::endl << " ,sa vitesse est : " << autre.Get_Derivative_Pos() <<
 std::endl << " ,sa masse est : " << autre.Get_masse() << std::endl << " Et le champ de force associé est : " << autre.Get_Champ() << std::endl;
 return sortie;}






int main()
{return 0;}
