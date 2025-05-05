#include "ObjetPhysique.h"
#include "Contrainte.h"
#include "ChampForces.h"
#include "Dessinable.h"
#include "ObjetMobile.h"
#include "constantes.h"

ObjetPhysique::ObjetPhysique (ObjetPhysique const& autre):  ObjetMobile(autre.getParam(),autre.getDerive()),cont(autre.get_cont()), champ(autre.get_champ()), 
    dim(autre.get_dim()), masse(autre.get_masse()), charge(autre.get_charge()){}
    
ObjetPhysique::ObjetPhysique (Vecteur paramaters, Vecteur derive,  std::shared_ptr<Contrainte> cont, std::shared_ptr<ChampForces> champ, double masse, double charge, unsigned int dim):     
    ObjetMobile(paramaters,derive), cont(cont), champ(champ), dim(dim), masse(masse), charge(charge) {}
    
ObjetPhysique::ObjetPhysique (Vecteur paramaters, std::shared_ptr<Contrainte> cont, std::shared_ptr<ChampForces> champ, double masse, double charge, unsigned int dim):     
    ObjetMobile(paramaters), cont(cont), champ(champ), dim(dim), masse(masse), charge(charge) {}
    
ObjetPhysique::ObjetPhysique (Vecteur paramaters, Vecteur derive, double masse, double charge, unsigned int dim):     
    ObjetMobile(paramaters,derive), cont(std::make_shared<Libre>()), champ(std::make_shared<GravitationConstante>(Vecteur(0,0,0))), dim(dim), masse(masse), charge(charge) {}





std::shared_ptr<Contrainte> ObjetPhysique::get_cont() const    {return cont;}
std::shared_ptr<ChampForces> ObjetPhysique::get_champ() const  {return champ;}
unsigned int ObjetPhysique::get_dim() const     {return dim;}
double ObjetPhysique::get_masse() const     {return masse;}
double ObjetPhysique::get_charge() const     {return charge;}
Vecteur ObjetPhysique:: force(double t) const   {return champ->force(*this,t);}             
Vecteur ObjetPhysique:: position() const     {return cont->position(*this);}
Vecteur ObjetPhysique:: vitesse() const   {return cont->vitesse(*this);}
void ObjetPhysique::affiche(std::ostream& sortie) const{
    sortie << "Le vecteur d'etat est : " << getParam() << std::endl
           << "Le vecteur vitesse est : " << getDerive() << std::endl 
           << "La masse est : "<< get_masse() << std::endl 
           << "La dimension est : " << get_dim() << std::endl 
           << "La charge electrique est : "<< get_charge() << std::endl; }

std::ostream& operator<<(std::ostream& sortie, ObjetPhysique const& autre){
    autre.affiche(sortie);   
    return sortie;}