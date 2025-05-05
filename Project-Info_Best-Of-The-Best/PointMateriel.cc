#include "PointMateriel.h"
#include "ChampForces.h"
#include "Contrainte.h"
#include "ObjetPhysique.h"

PointMateriel::PointMateriel(Vecteur parameters, Vecteur derive, std::shared_ptr<ChampForces> champ, std::shared_ptr<Contrainte> cont, double masse, double charge, unsigned int dim): 
	ObjetPhysique(parameters, derive, cont, champ, dim, masse, charge) {}
PointMateriel::PointMateriel(Vecteur parameters, std::shared_ptr<ChampForces> champ, std::shared_ptr<Contrainte> cont, double masse, double charge , unsigned int dim): 
	ObjetPhysique(parameters, cont , champ, dim, masse, charge) {}
PointMateriel::PointMateriel(Vecteur parameters, Vecteur derive, double masse, double charge, unsigned int dim): 
	ObjetPhysique(parameters, derive, dim, masse, charge) {}
	
PointMateriel::PointMateriel(PointMateriel const& autre): ObjetPhysique (autre){}	






void PointMateriel::dessine_sur(SupportADessin&) {}
Vecteur PointMateriel::evolution(double temps) {return cont->applique_force(*this,champ->force(*this,temps),temps);}
void PointMateriel::affiche(std::ostream& sortie) const {ObjetPhysique::affiche(sortie);}
std::ostream& operator<<(std::ostream& sortie, const PointMateriel& p){
	p.affiche(sortie);
	return sortie;	
}