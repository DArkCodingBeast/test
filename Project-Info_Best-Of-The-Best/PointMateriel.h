#include "Vecteur.h"
#include "ChampForces.h"
#include "Contrainte.h"
#include "SupportTextDessin.h"
#pragma once



class PointMateriel : public ObjetPhysique {	
    public:
        PointMateriel(PointMateriel const&);
        PointMateriel (Vecteur, Vecteur, std::shared_ptr<ChampForces> champ, std::shared_ptr<Contrainte> cont, double, double = 0, unsigned int = 3);
        PointMateriel(Vecteur, std::shared_ptr<ChampForces> champ, std::shared_ptr<Contrainte> cont, double, double = 0, unsigned int = 3);
        PointMateriel(Vecteur, Vecteur, double, double = 0, unsigned int = 3);
        
        virtual void dessine_sur(SupportADessin&) override;
        virtual Vecteur evolution(double) override;
        void affiche(std::ostream&) const;
    };

std::ostream& operator<<(std::ostream&, const PointMateriel&);