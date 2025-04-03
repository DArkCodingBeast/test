#include "ObjetMobile.h"



class Contrainte{
public:

    virtual Vecteur applique_force(ObjetPhysique const& obj,Vecteur force, double temps) = 0;
    virtual Vecteur position(ObjetPhysique const& obj) = 0;
    virtual Vecteur vitesse(ObjetPhysique const& obj) = 0;

};



class Libre : public Contrainte{
    public:
    
        Vecteur applique_force(ObjetPhysique const& obj,Vecteur force, double temps)
        {if (obj.Get_masse() == 0) {return {force};}
        return {force.mult(1 / obj.get_masse())}}
    
        Vecteur position(ObjetPhysique const& obj) {return obj.vect_etat;}
        Vecteur vitesse(ObjetPhysique const& obj) {return fct_derivee(obj.vect_etat);}
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

    ObjetPhysique (ObjetPhysique const& autre): cont(autre.get_cont()), champ(autre.get_champ()), dim(autre.get_dim()){}

    ObjetPhysique (Contrainte& cont, ChampForce& champ, unsigned int dim): cont(cont), champ(champ), dim(dim){}

    Contrainte& get_cont() {return cont;}

    ChampForce& get_champ() {return champ;}

    unsigned int get_dim() {return dim;}

    double get_masse() {return masse;}

    double get_charge() {return charge;}

    Vecteur force(double t = 0) const
    {return  force(   ,double t);}              // A finir ces trois fonction puis adapter les classes de semaine avant comme sous classes de celle ci
    
    Vecteur position() const
    {return  champ.Get_Champ().force();}

    Vecteur vitesse() const
    {return  champ.Get_Champ().force();}
}:


std::ostream& operator<<(std::ostream& sortie, ObjetPhysique const& autre)
{sortie << autre.get_cont() << autre.get_champ() << autre.get_dim() << autre.get_charge() << autre.get_masse() << std::endl;
 return sortie;}
















