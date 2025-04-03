#include<ObjetMobile.h>



class Contrainte{
public:

    std::array<double,3> applique_force(ObjetPhysique const& obj,std::array<double,3> force, double temps)
    {return }

    virtual <double,3> position(ObjetPhysique const& obj)
    {return }

    virtual array<double,3> vitesse(ObjetPhysique const& obj)
    {}

};



class Libre : public Contrainte{
    public:
    
        std::array<double,3> applique_force(ObjetPhysique const& obj,std::array<double,3> force, double temps)
        {if (obj.Get_masse() == 0) {return {force[0],force[1],force[2]};}
        return {force[0] / obj.Get_masse(),force[1] / obj.Get_masse(),force[2] / obj.Get_masse()}}
    
        std::array<double,3> position(ObjetPhysique const& obj)
        {return obj.vect_etat;}
    
        std::array<double,3> vitesse(ObjetPhysique const& obj)
        {return fct_derivee(obj.vect_etat);}
    
    };
    



class ChampForces{

public :

    std::array<double, 3> force(ObjetPhysique const&, double t)
    {}



};




class ObjetPhysique : public ObjetMobile{

private :
    Contrainte& cont;
    ChampForce& champ;
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

    std::array<double,3> vecteur_force(double t = 0) const
    {return  champ.Get_Champ().force();}
    
    std::array<double,3> vecteur_position() const
    {return  champ.Get_Champ().force();}

    std::array<double,3> vecteur_vitesse() const
    {return  champ.Get_Champ().force();}
}:


std::ostream& operator<<(std::ostream& sortie, ObjetPhysique const& autre)
{sortie << autre.get_cont() << autre.get_champ() << autre.get_dim() << autre.get_charge() << autre.get_masse() << std::endl;
 return sortie;}
















