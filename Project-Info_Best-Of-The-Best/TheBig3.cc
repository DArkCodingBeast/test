#include "TheBig3.h"

Vecteur Libre:: applique_force(ObjetPhysique const& obj,Vecteur force, double temps){
    if (obj.get_masse() == 0) 
        {return force;}      
    return force.mult(1 / obj.get_masse());
}

Vecteur Libre::position(ObjetPhysique const& obj)     {return obj.getParam();}
Vecteur Libre::vitesse(ObjetPhysique const& obj)  {return obj.getDerive();}
void Libre::affiche(std::ostream& sortie) const {sortie << "Aucune contrainte n'est appliqué sur l'objet." << std::endl;}

ObjetPhysique::ObjetPhysique (ObjetPhysique const& autre):  ObjetMobile(autre.getParam()),cont(autre.get_cont()), champ(autre.get_champ()), 
    dim(autre.get_dim()), masse(autre.get_masse()), charge(autre.get_charge()){}
ObjetPhysique::ObjetPhysique (Vecteur paramaters, Contrainte& cont, ChampForces& champ, unsigned int dim, double masse, double charge):     
    ObjetMobile(paramaters), cont(cont), champ(champ), dim(dim), masse(masse), charge(charge) {}

Contrainte& ObjetPhysique::get_cont() const    {return cont;}
ChampForces& ObjetPhysique::get_champ() const  {return champ;}
unsigned int ObjetPhysique::get_dim() const     {return dim;}
double ObjetPhysique::get_masse() const     {return masse;}
double ObjetPhysique::get_charge() const     {return charge;}
Vecteur ObjetPhysique:: force(double t) const   {return champ.force(*this,t);}             
Vecteur ObjetPhysique:: position() const     {return cont.position(*this);}
Vecteur ObjetPhysique:: vitesse() const   {return cont.vitesse(*this);}
void ObjetPhysique::affiche(std::ostream& sortie) const
{sortie << "Le vecteur d'etat est : " << getParam() << std::endl
<< "Le vecteur vitesse est : " << get_cont() << get_champ() << std::endl 
<< "La masse est : "<< get_masse() << std::endl 
<< "La dimension est : " << get_dim() << std::endl 
<< "La charge electrique est : "<< get_charge() << std::endl; }




std::ostream& operator<<(std::ostream& sortie, ChampForces const& autre) {
    autre.affiche(sortie);
    return sortie;}
std::ostream& operator<<(std::ostream& sortie, Contrainte const& autre) {
    autre.affiche(sortie);
    return sortie;}
std::ostream& operator<<(std::ostream& sortie, ObjetPhysique & autre){
autre.affiche(sortie);   
return sortie;}

GravitationConstante::GravitationConstante(Vecteur const& grav) : gravitation(grav) {}
void GravitationConstante::affiche(std::ostream& sortie) const {sortie << "un champ de force : " << gravitation << std::endl; }
Vecteur GravitationConstante::force(ObjetPhysique const& p1, double temps) {
    return gravitation.mult(p1.get_masse());
}

PointMateriel:: PointMateriel(Vecteur parameters, double masse, double charge, unsigned int dim, GravitationConstante & champ, Contrainte & cont): ObjetPhysique(parameters, cont , champ, dim, masse, charge) {}
PointMateriel:: PointMateriel(PointMateriel const& autre): ObjetPhysique (autre){}	
Vecteur PointMateriel:: evolution(double temps) {return cont.applique_force(*this,champ.force(*this,temps),temps);}
void PointMateriel::affiche(std::ostream& sortie) const override {ObjetPhysique::affiche(sortie);}

class SupportADessin;

std::ostream& operator<<(std::ostream& sortie, Dessinable const& dess){
    sortie << "Dessinable object";
    return sortie;
}


Systeme::Systeme() : objets(), contraintes(), champs(), integrateur(0.01), temps(0.0) {}
Systeme::Systeme(std::vector<std::unique_ptr<ObjetPhysique>>&& objets, std::vector<std::shared_ptr<Contrainte>>&& contraintes, std::vector<std::shared_ptr<ChampForces>>&& champs, 
    IntegrateurEulerCromer integrateur, double temps = 0.0) : objets(std::move(objets)), contraintes(std::move(contraintes)), champs(std::move(champs)), integrateur(integrateur), temps(temps) {}

const std::vector<std::unique_ptr<ObjetPhysique>>& Systeme::getObjets() const {return objets;}
const std::vector<std::shared_ptr<Contrainte>>& Systeme::getContraintes() const {return contraintes;}
const std::vector<std::shared_ptr<ChampForces>>& Systeme::getChamp() const {return champs;}
double Systeme::getTemps() const {return temps;}

void Systeme::ajouter_objet(std::unique_ptr<ObjetPhysique> objet) {
    objets.push_back(std::move(objet));
}

void Systeme::ajouter_contrainte(std::shared_ptr<Contrainte> contrainte) {
    contraintes.push_back(std::move(contrainte));
}

void Systeme::ajouter_champ(std::shared_ptr<ChampForces> champ) {
    champs.push_back(std::move(champ));
}

void Systeme::dessine_sur(SupportADessin& support) const {
    for (const auto& objet : objets) {
        objet->dessine_sur(support);
    }
} 

void Systeme::evolue(double dt) {
    for (const auto& objet : objets) {
    integrateur.integre(*objet, temps, dt); // probleme here
    }
    temps += dt; // problem here
}
std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme) {
    sortie << "Systeme : à t = " << systeme.getTemps() << std::endl;
    for (std::size_t i(0); i < systeme.getObjets().size(); ++i){
        sortie << "Objet no " << i + 1 << " :" << std::endl;
        if (systeme.getObjets()[i]) {
        sortie << *(systeme.getObjets()[i]) << std::endl << std::endl;
        } else {
            sortie << "Objet null." << std::endl;
        }
    }
    return sortie;
}

TextViewer::TextViewer(std::ostream& sortie)
    : sortie(sortie)
    {}
     
void TextViewer::dessine(PointMateriel const& point){
    sortie << point << std::endl;
}
    
void TextViewer::dessine(Systeme const& systeme) {
    sortie << systeme << std::endl;
}