#include "ObjetMobile.h"
#include <string>
#pragma once

class Contrainte{
public:
    virtual Vecteur applique_force(ObjetPhysique const&, Vecteur , double ) = 0;
    virtual Vecteur position(ObjetPhysique const& ) = 0;
    virtual Vecteur vitesse(ObjetPhysique const& ) = 0;
};

class Libre : public Contrainte{
    public:
    
        Vecteur applique_force(ObjetPhysique const& ,Vecteur , double );
        Vecteur position(ObjetPhysique const& ) {return obj.getParam();}
        Vecteur vitesse(ObjetPhysique const& ) {return obj.getDerive();}
    };

class ChampForces{
public :
    virtual Vecteur force(ObjetPhysique const&, double t) = 0;
};


class ObjetPhysique : public ObjetMobile{

private :
    Contrainte& cont;
    ChampForces& champ;
    unsigned int dim;
    double masse;
    double charge;


public:

    ObjetPhysique (ObjetPhysique const& ): cont(autre.get_cont()), champ(autre.get_champ()), dim(autre.get_dim()), masse(autre.get_masse()), charge(autre.get_charge()){}
    ObjetPhysique (Contrainte& , ChampForces& , unsigned int ): cont(cont), champ(champ), dim(dim){}
    Contrainte const& get_cont() {return cont;}
    ChampForces const& get_champ() {return champ;}
    const unsigned int get_dim() {return dim;}
    const double get_masse() {return masse;}
    const double get_charge() {return charge;}
    Vecteur force(double t = 0) const  {return champ.force(*this,t);}              // A finir ces trois fonction puis adapter les classes de semaine avant comme sous classes de celle ci
    Vecteur position() const  {return cont.position(*this);
    Vecteur vitesse() {return cont.vitesse(*this);}
};


std::ostream& operator<<(std::ostream& sortie, ChampForces const& autre)
{ return sortie;}


std::ostream& operator<<(std::ostream& sortie, Contrainte const& autre)
{ return sortie;}


std::ostream& operator<<(std::ostream& sortie, ObjetPhysique & autre)
{sortie << autre.get_cont() << autre.get_champ() << autre.get_dim() << autre.get_charge() << autre.get_masse() << std::endl;
 return sortie;}
















