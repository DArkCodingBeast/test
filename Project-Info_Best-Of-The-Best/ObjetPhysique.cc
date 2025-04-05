#include "ObjetPhysique.h"


Vecteur Libre:: applique_force(ObjetPhysique const& obj,Vecteur force, double temps)    {if (obj.get_masse() == 0) {return {force};}      return {force.mult(1 / obj.get_masse())};}

Vecteur Contrainte:: position(ObjetPhysique const& obj)     {return obj.getParam();}
Vecteur Contrainte:: vitesse(ObjetPhysique const& obj)  {return obj.getDerive();}
  
ObjetPhysique::ObjetPhysique (ObjetPhysique const& autre):  ObjetMobile(autre.getParam()),cont(autre.get_cont()), champ(autre.get_champ()), dim(autre.get_dim()), masse(autre.get_masse()), charge(autre.get_charge()){}
ObjetPhysique::ObjetPhysique (Vecteur paramaters, Contrainte& cont, ChampForces& champ, unsigned int dim, double masse, double charge):     ObjetMobile(paramaters),cont(cont), champ(champ), dim(dim),masse(masse), charge(charge) {}

Contrainte& ObjetPhysique::get_cont() const    {return cont;}
ChampForces& ObjetPhysique::get_champ() const  {return champ;}
unsigned int ObjetPhysique::get_dim() const     {return dim;}
double ObjetPhysique::get_masse() const     {return masse;}
double ObjetPhysique::get_charge() const     {return charge;}
Vecteur ObjetPhysique:: force(double t = 0) const   {return champ.force(*this,t);}             
Vecteur ObjetPhysique:: position() const     {return cont.position(*this);}
Vecteur ObjetPhysique:: vitesse()    {return cont.vitesse(*this);}


std::ostream& operator<<(std::ostream& sortie, ChampForces const& autre)     { return sortie;}
std::ostream& operator<<(std::ostream& sortie, Contrainte const& autre)     { return sortie;}
std::ostream& operator<<(std::ostream& sortie, ObjetPhysique & autre)
{sortie <<"Le vecteur d'etat est : " << autre.getParam() << std::endl << "Le vecteur vitesse est : " << autre.get_cont() << autre.get_champ() << std::endl << " La dimension est : " << autre.get_dim() << std::endl << " La charge electrique est : "<< autre.get_charge() << std::endl << "La masse est : "<< autre.get_masse() << std::endl;  return sortie;}

 














