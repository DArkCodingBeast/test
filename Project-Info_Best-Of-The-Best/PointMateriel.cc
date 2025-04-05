#include "PointMateriel.h"


GravitationConstante::GravitationConstante(Vecteur const& grav) : gravitation(grav) {}
Vecteur GravitationConstante::force(PointMateriel const& p1, double temps) {
    return {gravitation.mult(p1.Get_masse())};
}

PointMateriel:: PointMateriel(Vecteur vect_etat,Vecteur vect_derivee,double masse,Vecteur ChampForce): vect_etat(vect_etat), vect_derivee(vect_derivee), masse(masse), ChampForce(ChampForce) {}
PointMateriel:: PointMateriel(PointMateriel const& autre): vect_etat(autre.vect_etat), vect_derivee(autre.vect_derivee), masse(autre.masse), ChampForce(autre.ChampForce) {}
const Vecteur PointMateriel:: Get_Position() const {return vect_etat;}	
const Vecteur PointMateriel:: Get_Derivative_Pos() const {return vect_derivee;}		
const double PointMateriel:: Get_masse() const {return masse;}
const Vecteur PointMateriel:: Get_Champ() const {return ChampForce;}
void PointMateriel:: set_vect_etat(Vecteur autre) {vect_etat = autre;}
Vecteur PointMateriel:: evolution(double temps) {return {ChampForce.mult(1/masse)};}


std::ostream& operator<<(std::ostream& sortie,PointMateriel const& autre)
{sortie << "le position du point matériel est : " << autre.Get_Position() << std::endl << " ,sa vitesse est : " << autre.Get_Derivative_Pos() <<
 std::endl << " ,sa masse est : " << autre.Get_masse() << std::endl << " Et le champ de force associé est : " << autre.Get_Champ() << std::endl;
 return sortie;}
