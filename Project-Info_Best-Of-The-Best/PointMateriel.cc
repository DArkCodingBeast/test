#include "PointMateriel.h"
#include "ObjetPhysique.h"

PointMateriel::PointMateriel(Vecteur parameters, double masse, double charge, unsigned int dim, GravitationConstante & champ, Contrainte & cont): ObjetPhysique(parameters, cont , champ, dim, masse, charge) {}
PointMateriel::PointMateriel(PointMateriel const& autre): ObjetPhysique (autre){}	
Vecteur PointMateriel::evolution(double temps) {return cont.applique_force(*this,champ.force(*this,temps),temps);}
void PointMateriel::affiche(std::ostream& sortie) const {ObjetPhysique::affiche(sortie);}