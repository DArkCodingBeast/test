#include "PointMateriel.h"


GravitationConstante::GravitationConstante(Vecteur const& grav) : gravitation(grav) {}
virtual void GravitationConstante::affiche(ostream& sortie) const override {sortie << "un champ de force : " << gravitation <<< endl; }
Vecteur GravitationConstante::force(ObjetPhysique const& p1, double temps) {
    return gravitation.mult(p1.get_masse());
}

PointMateriel:: PointMateriel(Vecteur parameters, double masse, double charge, unsigned int dim, GravitationConstante & champ, Contrainte & cont): ObjetPhysique(parameters, cont , champ, dim, masse, charge) {}
PointMateriel:: PointMateriel(PointMateriel const& autre): ObjetPhysique (autre){}	
Vecteur PointMateriel:: evolution(double temps) {return cont.applique_force(*this,champ.force(*this,temps),temps);}
void PointMateriel::affiche(ostream& sortie) const {ObjetPhysique::affiche(sortie);}
