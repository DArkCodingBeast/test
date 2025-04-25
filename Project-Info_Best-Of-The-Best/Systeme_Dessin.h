#include "PointMateriel.h"
#include <memory>
#pragma one

class SupportADessin;

class Dessinable {
    public:
        virtual ~Dessinable() = default;
        virtual void dessine_sur(SupportADessin& support) = 0;
};

std::ostream& operator<<(std::ostream&, Dessinable const&);

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
void evolue(double) const;
};

std::ostream& operator<<(std::ostream&, Systeme const&);

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
    TextViewer(std::ostream&);
    virtual ~TextViewer() = default;
    
    TextViewer(TextViewer const&)            = delete;
    TextViewer& operator=(TextViewer const&) = delete;
     
    virtual void dessine(PointMateriel const&) override;
    
    virtual void dessine(Systeme const&) override;
     
    protected:
    std::ostream& sortie;
    };
