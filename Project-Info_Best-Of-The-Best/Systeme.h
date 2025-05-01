#include "Vecteur.h"
#pragma once

//Prototypes
class IntegrateurEulerCromer;
class ObjetPhysique;
class Contrainte;
class ChampForces;
class SupportADessin;

class Systeme {
    private:
    std::vector<std::unique_ptr<ObjetPhysique>> objets;
    std::vector<std::shared_ptr<Contrainte>> contraintes;
    std::vector<std::shared_ptr<ChampForces>> champs;
    IntegrateurEulerCromer integrateur;
    double temps;
    
    public:
    Systeme();
    Systeme(std::vector<std::unique_ptr<ObjetPhysique>>&&, std::vector<std::shared_ptr<Contrainte>>&&, std::vector<std::shared_ptr<ChampForces>>&&, 
        IntegrateurEulerCromer, double);
    
    const std::vector<std::unique_ptr<ObjetPhysique>>& getObjets() const;
    const std::vector<std::shared_ptr<Contrainte>>& getContraintes() const;
    const std::vector<std::shared_ptr<ChampForces>>& getChamp() const;
    double getTemps() const;
    
    void ajouter_objet(std::unique_ptr<ObjetPhysique>);
    void ajouter_contrainte(std::shared_ptr<Contrainte>);
    void ajouter_champ(std::shared_ptr<ChampForces>);
    void dessine_sur(SupportADessin&) const;
    void evolue(double);
};
    
    std::ostream& operator<<(std::ostream&, Systeme const&);