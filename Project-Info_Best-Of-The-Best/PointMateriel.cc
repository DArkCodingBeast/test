#include "PointMateriel.h"


GravitationConstante::GravitationConstante(Vecteur const& grav) : gravitation(grav) {}
Vecteur GravitationConstante::force(ObjetPhysique const& p1, double temps) {
    return gravitation.mult(p1.get_masse());
}

PointMateriel:: PointMateriel(Vecteur parameters, double masse, double charge, double dim,GravitationConstante & champ, Contrainte & cont): ObjetPhysique(parameters, cont , champ, dim, masse, charge) {}
PointMateriel:: PointMateriel(PointMateriel const& autre): ObjetPhysique (autre){}	
Vecteur PointMateriel:: evolution(double temps) {return "valeur de l equation d evolution" ;}
