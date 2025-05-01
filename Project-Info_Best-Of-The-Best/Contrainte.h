#include "Vecteur.h"
#pragma once

class ObjetPhysique;

class Contrainte
{public:
    virtual Vecteur applique_force(ObjetPhysique const&, Vecteur , double ) = 0;
    virtual Vecteur position(ObjetPhysique const& ) = 0;
    virtual Vecteur vitesse(ObjetPhysique const& ) = 0;
    virtual void affiche(std::ostream&) const = 0;
};

class Libre : public Contrainte{
    public:
    
        Vecteur applique_force(ObjetPhysique const& ,Vecteur , double ) override;
        Vecteur position(ObjetPhysique const& ) override;
        Vecteur vitesse(ObjetPhysique const& ) override;
        void affiche(std::ostream&) const override;
    };

    std::ostream& operator<<(std::ostream&, Contrainte const& );