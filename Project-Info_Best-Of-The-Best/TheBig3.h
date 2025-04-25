#include <string>
#include <memory>
#include "Integrateur.h"
#pragma once

class ObjetPhysique;
class SupportADessin;

class Dessinable {
    public:
        virtual ~Dessinable() = default;
        virtual void dessine_sur(SupportADessin&) = 0;
};

class Contrainte
{public:
    virtual Vecteur applique_force(ObjetPhysique const&, Vecteur , double ) = 0;
    virtual Vecteur position(ObjetPhysique const& ) = 0;
    virtual Vecteur vitesse(ObjetPhysique const& ) = 0;
    virtual void affiche(std::ostream&) const = 0;
};

class Libre : public Contrainte{
    public:
    
        Vecteur applique_force(ObjetPhysique const& ,Vecteur , double ) override;
        Vecteur position(ObjetPhysique const& ) override;
        Vecteur vitesse(ObjetPhysique const& ) override;
        void affiche(std::ostream&) const override;
    };

class ChampForces{
public :
    virtual Vecteur force(ObjetPhysique const&, double) = 0;
    virtual void affiche(std::ostream&) const = 0;
};


class ObjetPhysique : public ObjetMobile, public Dessinable {
private :
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


std::ostream& operator<<(std::ostream& , ChampForces const& );
std::ostream& operator<<(std::ostream& , Contrainte const& );
std::ostream& operator<<(std::ostream& , ObjetPhysique& );

class PointMateriel;
class GravitationConstante : public ChampForces{
private :
    Vecteur gravitation;

public :
    GravitationConstante(Vecteur const&);
    Vecteur force(ObjetPhysique const&, double) override;
    virtual void affiche(std::ostream& sortie) const override;
};

class PointMateriel : public ObjetPhysique{	
public:
    PointMateriel(PointMateriel const&);
    PointMateriel(Vecteur, double, double, unsigned int ,GravitationConstante&, Contrainte&);
    Vecteur evolution(double);};
    void affiche(std::ostream&) const override;

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
    void evolue(double);
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