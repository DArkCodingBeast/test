#include "PointMateriel.h"
#include <memory>

class SupportADessin;
class Dessinable;

class Systeme {
protected:
std::vector<std::unique_ptr<Dessinable>> objets;
std::vector<std::unique_ptr<Contrainte>> contraintes;
std::vector<std::unique_ptr<ChampForces>> champs;
IntegrateurEulerCromer integrateur;
double temps;

public:
Systeme() : temps(0.0) {}

std::vector<std::unique_ptr<Dessinable>> getObjets() const {return objets;}
std::vector<std::unique_ptr<Contrainte>> getContraintes() const {return contraintes;}
std::vector<std::unique_ptr<ChampForces>> getChamp() const {return champs;}
double getTemps() {return temps;}

void ajouter_objet(std::unique_ptr<Dessinable> objet) {
    objets.push_back(objet);
}

void ajouter_contrainte(std::unique_ptr<Contrainte> contrainte) {
    contraintes.push_back(contrainte);
}

void ajouter_champ(std::unique_ptr<ChampForces> champ) {
    champs.push_back(champ);
}

void dessine_sur(SupportADessin& support) const {
    for (const auto& objet : objets) {
        objet->dessine_sur(support);
    }
}
};


std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme) {
    sortie << "Systeme : à t = " << systeme.getTemps() << std::endl;
    for (size_t i = 0; i < systeme.getObjets().size(); ++i){
        sortie << "Objet no " << i + 1 << " :" << std::endl;
        sortie << *(systeme.getObjets()[i]) << std::endl << std::endl;
    }
    return sortie;
}

class Dessinable {
public:
    virtual ~Dessinable() = default;
    virtual dessine_sur(SupportADessin& support) = 0;
};

class SupportADessin {
public:
virtual ~SupportADessin() = default;
SupportADessin(SupportADessin const&)            = delete;
SupportADessin& operator=(SupportADessin const&) = delete;

virtual void dessine(PointMateriel const&) = 0;
virtual void dessine(Systeme const&) = 0;
virtual void dessine(Solide const&) = 0; 
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

/*
virtual void dessine_sur(SupportADessin& support) override
{ support.dessine(*this); }
 */