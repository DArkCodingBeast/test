#pragma once
#include "Dessinable.h"
#include "ObjetMobile.h"
#include "Contrainte.h"
#include "ChampForces.h"
#include <memory> // Pour std::shared_ptr

//prototype
class SupportADessin;

class ObjetPhysique : public ObjetMobile, public Dessinable{
public:
    ObjetPhysique(ObjetPhysique const&);
    ObjetPhysique(Vecteur, Vecteur, std::shared_ptr<Contrainte>, std::shared_ptr<ChampForces>, double, double, unsigned int);
    ObjetPhysique(Vecteur, std::shared_ptr<Contrainte>, std::shared_ptr<ChampForces>, double, double, unsigned int);
    ObjetPhysique(Vecteur, Vecteur, double, double, unsigned int);
    
    void dessine_sur(SupportADessin& miaw ) override { /*not sure what to do with this*/}
    std::shared_ptr<Contrainte> get_cont() const;
    std::shared_ptr<ChampForces> get_champ() const;
    unsigned int get_dim() const;
    double get_masse() const;
    double get_charge() const;
    Vecteur force(double t) const;
    Vecteur position() const;
    Vecteur vitesse() const;
    void affiche(std::ostream&) const;
    virtual Vecteur evolution(double) override {/*not sure what to do with this*/ return Vecteur(0,0,0);};
    void set_cont(std::shared_ptr<Contrainte>);
    void set_champ(std::shared_ptr<ChampForces>);

protected:
    std::shared_ptr<Contrainte> cont;
    std::shared_ptr<ChampForces> champ;
    unsigned int dim;
    double masse;
    double charge;
};
std::ostream& operator<<(std::ostream&, const ObjetPhysique&);
