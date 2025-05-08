#include "PointMateriel.h"

PointMateriel::PointMateriel(Vecteur parameters, Vecteur derive, std::shared_ptr<ChampForces> champ, std::shared_ptr<Contrainte> cont, double masse, double charge, unsigned int dim): 
	ObjetPhysique(parameters, derive, cont, champ, masse, charge, dim) {}
PointMateriel::PointMateriel(Vecteur parameters, std::shared_ptr<ChampForces> champ, std::shared_ptr<Contrainte> cont, double masse, double charge , unsigned int dim): 
	ObjetPhysique(parameters, cont , champ, masse, charge, dim) {}
PointMateriel::PointMateriel(Vecteur parameters, Vecteur derive, double masse, double charge, unsigned int dim): 
	ObjetPhysique(parameters, derive, masse, charge, dim) {}
	
PointMateriel::PointMateriel(PointMateriel const& autre): ObjetPhysique (autre){}	


void PointMateriel::dessine_sur(SupportADessin&) {}
Vecteur PointMateriel::evolution(double temps){
	return cont->applique_force(*this, champ->force(*this,temps), temps);
}
void PointMateriel::affiche(std::ostream& sortie) const {
	ObjetPhysique::affiche(sortie);
}
std::ostream& operator<<(std::ostream& sortie, const PointMateriel& p){
	p.affiche(sortie);
	return sortie;	
}