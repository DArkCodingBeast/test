#pragma once
#include "Dessinable.h"
#include "ObjetMobile.h"
#include "Vecteur.h"
#include "Contrainte.h"
#include "ChampForces.h"
#include <memory> // Pour std::shared_ptr


class ObjetPhysique : public ObjetMobile, public Dessinable{
public:
    ObjetPhysique(ObjetPhysique const&);
    ObjetPhysique(Vecteur, Vecteur, std::shared_ptr<Contrainte>, std::shared_ptr<ChampForces>, double, double, unsigned int);
    ObjetPhysique(Vecteur, std::shared_ptr<Contrainte>, std::shared_ptr<ChampForces>, double, double, unsigned int);
    ObjetPhysique(Vecteur, Vecteur, double, double, unsigned int);
    
    void dessine_sur(&SupportADessin) override {}
    std::shared_ptr<Contrainte> get_cont() const;
    std::shared_ptr<ChampForces> get_champ() const;
    unsigned int get_dim() const;
    double get_masse() const;
    double get_charge() const;
    Vecteur force(double t) const;
    Vecteur position() const;
    Vecteur vitesse() const;
    void affiche(std::ostream&) const;

protected:
    std::shared_ptr<Contrainte> cont;
    std::shared_ptr<ChampForces> champ;
    unsigned int dim;
    double masse;
    double charge;
};
    
