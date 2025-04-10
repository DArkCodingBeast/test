#include "PointMateriel.h"
#include <memory>

class SupportADessin;

class Dessinable {
    public:
        virtual ~Dessinable() = default;
        virtual void dessine_sur(SupportADessin& support) = 0;
};

std::ostream& operator<<(std::ostream& sortie, Dessinable const& dess){
    sortie << "Dessinable object";
    return sortie;
}

class Systeme {
protected:
std::vector<std::unique_ptr<Dessinable>> objets;
std::vector<std::unique_ptr<Contrainte>> contraintes;
std::vector<std::unique_ptr<ChampForces>> champs;
IntegrateurEulerCromer integrateur;
double temps;

public:
Systeme() : objets({}), contraintes({}), champs({}), integrateur(0.01), temps(0.0) {}
Systeme(std::vector<std::unique_ptr<Dessinable>>&& objets, std::vector<std::unique_ptr<Contrainte>>&& contraintes, std::vector<std::unique_ptr<ChampForces>>&& champs, 
    IntegrateurEulerCromer integrateur, double temps = 0.0) : objets(std::move(objets)), contraintes(std::move(contraintes)), champs(std::move(champs)), integrateur(integrateur), temps(temps) {}

const std::vector<std::unique_ptr<Dessinable>>& getObjets() const {return objets;}
const std::vector<std::unique_ptr<Contrainte>>& getContraintes() const {return contraintes;}
const std::vector<std::unique_ptr<ChampForces>>& getChamp() const {return champs;}
double getTemps() const {return temps;}

void ajouter_objet(std::unique_ptr<Dessinable> objet) {
    objets.push_back(std::move(objet));
}

void ajouter_contrainte(std::unique_ptr<Contrainte> contrainte) {
    contraintes.push_back(std::move(contrainte));
}

void ajouter_champ(std::unique_ptr<ChampForces> champ) {
    champs.push_back(std::move(champ));
}

void dessine_sur(SupportADessin& support) const {
    for (const auto& objet : objets) {
        objet->dessine_sur(support);
    }
}
}; // skibidi

std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme) {
    sortie << "Systeme : à t = " << systeme.getTemps() << std::endl;
    for (size_t i = 0; i < systeme.getObjets().size(); ++i){
        sortie << "Objet no " << i + 1 << " :" << std::endl;
        if (systeme.getObjets()[i]) {
        sortie << *(systeme.getObjets()[i]) << std::endl << std::endl;
        } else {
            sortie << "Objet null." << std::endl;
        }
    }
    return sortie;
}

class SupportADessin {
    public:
    SupportADessin() = default;
    virtual ~SupportADessin() = default;
    SupportADessin(SupportADessin const&)            = delete;
    SupportADessin& operator=(SupportADessin const&) = delete;
    
    virtual void dessine(PointMateriel const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    };

class TextViewer : public SupportADessin {
    public:
    TextViewer(std::ostream& sortie)
        : sortie(sortie)
      {}
    virtual ~TextViewer() = default;
    
    TextViewer(TextViewer const&)            = delete;
    TextViewer& operator=(TextViewer const&) = delete;
     
    virtual void dessine(PointMateriel const& point) override {
        sortie << point << std::endl;
    }
    
    virtual void dessine(Systeme const& systeme) override {
        sortie << systeme << std::endl;
    }
     
    protected:
    std::ostream& sortie;
    };
