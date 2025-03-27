#include <PointMateriel.h>


GravitationConstante::GravitationConstante(std::array<double, 3> const& grav) : gravitation(grav) {}
GravitationConstante::std::array<double,3> force(PointMateriel const& p1, double temps) {
    return {gravitation[0] * p1.Get_masse(),
            gravitation[1] * p1.Get_masse(),
            gravitation[2] * p1.Get_masse()};
}


PointMateriel::PointMateriel(PointMateriel const& autre): vect_etat(autre.vect_etat), vect_derivee(autre.vect_derivee), masse(autre.masse), ChampForce(autre.ChampForce) {}
PointMateriel::const std::array<double,3> Get_Position() const {return vect_etat;}	
PointMateriel::const std::array<double,3> Get_Derivative_Pos() const {return vect_derivee;}		
PointMateriel::const double Get_masse() const {return masse;}
PointMateriel::const std::array<double,3> Get_Champ() const {return ChampForce;}
PointMateriel::void set_vect_etat(std::array<double,3> autre) {vect_etat = autre;}
PointMateriel::std::array<double,3> evolution(double temps) {return {ChampForce[0]/masse,ChampForce[1]/masse,ChampForce[2]/masse};}


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
