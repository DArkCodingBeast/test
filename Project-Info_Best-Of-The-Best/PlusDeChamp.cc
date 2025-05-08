#include "PlusDeChamp.h"


FrotFluide::FrotFluide(double coef): coef(coef) {}

Vecteur FrotFluide::force(ObjetPhysique const& obj, double t)  { return obj.getDerive().mult(-coef); }
   
void FrotFluide::affiche(std::ostream& sortie) const  {sortie << "L'objet est contraint par des frottement fluide de coéfficient λ : " << coef << std::endl; }
	
	
	

ElectConst::ElectConst(Vecteur champ1, Vecteur champ2) : champ_elec(champ1) , champ_mag(champ2) {}

Vecteur ElectConst::force(ObjetPhysique const& obj, double t)  {return ( champ_elec + champ_mag.prod_vect(obj.getDerive()) ).mult(obj.get_charge() ); }

void ElectConst::affiche(std::ostream& sortie) const {sortie << " L'objet est contraint par un champ electrique constant de vecteur : "
	<< champ_elec << " et par un champ magnetique de vecteur : " << champ_mag << std::endl;}
	

Suspension_route_sin::Suspension_route_sin(double raid, double a, double peri) : raideur(raid), amplitude(a), periode(peri) {}

Vecteur Suspension_route_sin::force(ObjetPhysique const& obj, double t) {return raideur * (amplitude * sin( ( 2 * M_PI * obj.getParam().get_vect()[0] ) / periode ) - obj.getParam().get_vect()[1]); }

void Suspension_route_sin::affiche(std::ostream& sortie) const { sortie << "L'objet est contraint a se deplacer sur une route sinusoidale de periode : " 
	<< periode << " , d'amplitude : " << amplitude << ", avec un ressort comme supension de raideur : " << raideur << std::endl;}







