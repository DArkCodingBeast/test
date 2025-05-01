#include "Vecteur.h"
#pragma once

//prototypes
class ObjetPhysique;

class ChampForces{
    public :
        virtual Vecteur force(ObjetPhysique const&, double) = 0;
        virtual void affiche(std::ostream&) const = 0;
    };

std::ostream& operator<<(std::ostream&, ChampForces const& );
    
class GravitationConstante : public ChampForces{
    private :
        Vecteur gravitation;
    
    public :
        GravitationConstante(Vecteur const&);
        Vecteur force(ObjetPhysique const&, double) override;
        virtual void affiche(std::ostream& sortie) const override;
    };