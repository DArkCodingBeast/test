#include "Integrateur.h"
#include <memory>
#include <string>
#pragma once

class ObjetPhysique;
class SupportADessin;

class Dessinable {
    public:
        virtual ~Dessinable() = default;
        virtual void dessine_sur(SupportADessin&) = 0;
};
    
std::ostream& operator<<(std::ostream&, Dessinable const&);

class Contrainte
{public:
    virtual Vecteur applique_force(ObjetPhysique const&, Vecteur , double ) = 0;
    virtual Vecteur position(ObjetPhysique const& ) = 0;
    virtual Vecteur vitesse(ObjetPhysique const& ) = 0;
};

class Libre : public Contrainte{
    public:
    
        Vecteur applique_force(ObjetPhysique const& ,Vecteur , double ) override;
        Vecteur position(ObjetPhysique const& ) override;
        Vecteur vitesse(ObjetPhysique const& ) override;
    };

class ChampForces{
public :
    virtual Vecteur force(ObjetPhysique const&, double) = 0;
};


class ObjetPhysique : public ObjetMobile, public Dessinable {
private :
    Contrainte& cont;
    ChampForces& champ;
    unsigned int dim;
    double masse;
    double charge;

public:
    virtual void dessine_sur(SupportADessin&) override;

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
};


class PointMateriel : public ObjetPhysique{	
public:
    PointMateriel(PointMateriel const&);
    PointMateriel(Vecteur , double , double , unsigned int ,GravitationConstante & , Contrainte & );
    Vecteur evolution(double);};

    class SupportADessin;
    
class Systeme {
    private:
    std::vector<std::unique_ptr<ObjetPhysique>> objets;
    std::vector<std::shared_ptr<Contrainte>> contraintes;
    std::vector<std::shared_ptr<ChampForces>> champs;
    Integrateur& integrateur;
    double temps;
    
    public:
    Systeme();
    Systeme(std::vector<std::unique_ptr<ObjetPhysique>>&&, std::vector<std::shared_ptr<Contrainte>>&&, std::vector<std::shared_ptr<ChampForces>>&&, 
        Integrateur&, double);
    
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
        
    virtual void dessine(ObjetPhysique const&) = 0;
    virtual void dessine(Systeme const&) = 0;
};
    
class TextViewer : public SupportADessin {
        public:
        TextViewer(std::ostream&);
        virtual ~TextViewer() = default;
        
        TextViewer(TextViewer const&)            = delete;
        TextViewer& operator=(TextViewer const&) = delete;
         
        virtual void dessine(ObjetPhysique const&) override;
        
        virtual void dessine(Systeme const&) override;
         
        private:
        std::ostream& sortie;
        };