#include "Dessinable.h"
#include "ObjetMobile.h"
#pragma once

//prototypes
class Contrainte;
class ChampForces;

class ObjetPhysique : public ObjetMobile, public Dessinable {
    protected :
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
        Vecteur vitesse() const ;
        void affiche(std::ostream& sortie) const;
        void affiche(std::ostream& sortie,double temps) const;
    };

    std::ostream& operator<<(std::ostream&, ObjetPhysique const& );
    