#include "ObjetPhysique.h"
#include "ChampForces.h"
#include <iostream>
#include <cmath>
#pragma once



class FrotFluide : public ChampForces
{
private:
   double coef;


public:
   FrotFluide(double coef);
   Vecteur force(ObjetPhysique const&, double)  ;
   void affiche(std::ostream&) const ;
};



class ElectConst : public ChampForces
{
 private:
	Vecteur champ_elec;
	Vecteur champ_mag;
	
	
 public:
   ElectConst(Vecteur, Vecteur);
   Vecteur force(ObjetPhysique const&, double)  ;
   void affiche(std::ostream&) const ;
	
};
	
	
class Suspension_route_sin : public ChampForces
{private :
	double raideur;
	double amplitude;
	double periode;
	 
 public :
   Suspension_route_sin(double, double, double);
   Vecteur force(ObjetPhysique const&, double) ;
   void affiche(std::ostream&) const ;
	
};
	
	
	
	
	
	
	
	

