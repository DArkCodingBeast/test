#include "ObjetMobile.h"
#include "Systeme_Dessin.h"
#include <string>
#pragma once


class ObjetPhysique;

class Contrainte
{public:
    virtual Vecteur applique_force(ObjetPhysique const&, Vecteur , double ) = 0;
    virtual Vecteur position(ObjetPhysique const& ) = 0;
    virtual Vecteur vitesse(ObjetPhysique const& ) = 0;
};

class Libre : public Contrainte{
    public:
    
        Vecteur applique_force(ObjetPhysique const& ,Vecteur , double ) override;
        Vecteur position(ObjetPhysique const& ) override;
        Vecteur vitesse(ObjetPhysique const& ) override;
    };

class ChampForces{
public :
    virtual Vecteur force(ObjetPhysique const&, double) = 0;
};


class ObjetPhysique : public ObjetMobile, public Dessinable {
private :
    Contrainte& cont;
    ChampForces& champ;
    unsigned int dim;
    double masse;
    double charge;

public:

    ObjetPhysique (ObjetPhysique const&);
    ObjetPhysique (Vecteur, Contrainte& , ChampForces& , unsigned int, double, double);
    Contrainte & get_cont() const;
    ChampForces & get_champ() const;
    unsigned int get_dim() const ;
    double get_masse() const ;
    double get_charge() const;
    Vecteur force(double t = 0) const ;            
    Vecteur position() const ;
    Vecteur vitesse() ;
};


std::ostream& operator<<(std::ostream& , ChampForces const& );
std::ostream& operator<<(std::ostream& , Contrainte const& );
std::ostream& operator<<(std::ostream& , ObjetPhysique& );
















