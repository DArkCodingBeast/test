#include "Integrateur.h"
#include "SupportTextDessin.h"
#pragma once

class Systeme {
    private:
    std::vector<std::unique_ptr<ObjetPhysique>> objets;
    std::vector<std::shared_ptr<Contrainte>> contraintes;
    std::vector<std::shared_ptr<ChampForces>> champs;
    std::unique_ptr<Integrateur> integrateur;
    double temps;
    
    public:
    Systeme();
    Systeme(std::vector<std::unique_ptr<ObjetPhysique>>&&, std::vector<std::shared_ptr<Contrainte>>&&, std::vector<std::shared_ptr<ChampForces>>&&, 
        std::unique_ptr<Integrateur>&&, double);
    
    const std::vector<std::unique_ptr<ObjetPhysique>>& getObjets() const;
    const std::vector<std::shared_ptr<Contrainte>>& getContraintes() const;
    const std::vector<std::shared_ptr<ChampForces>>& getChamp() const;
    double getTemps() const;
    
    void ajouter_objet(std::unique_ptr<ObjetPhysique>); // ajouter objet a systeme
    void ajouter_contrainte(std::shared_ptr<Contrainte>); // comme ajouter_objet
    void donner_contrainte(std::size_t, std::size_t); // donner a un objet une contrainte
    void ajouter_champ(std::shared_ptr<ChampForces>); // come ajouter_objet
    void donner_champ(std::size_t, std::size_t); // comme donner_contrainte
    void dessine_sur(SupportADessin&) const;
    void change_int(std::unique_ptr<Integrateur>&&);
    void evolue(double);
};
    
    std::ostream& operator<<(std::ostream&, Systeme const&);