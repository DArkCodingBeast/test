#include "Systeme.h"

Systeme::Systeme() : objets(), contraintes(), champs(), integrateur(std::make_unique<IntegrateurEulerCromer>(0.01)), temps(0.0) {}
Systeme::Systeme(std::vector<std::unique_ptr<ObjetPhysique>>&& objets, std::vector<std::shared_ptr<Contrainte>>&& contraintes, std::vector<std::shared_ptr<ChampForces>>&& champs, 
    std::unique_ptr<Integrateur>&& integrateur, double temps = 0.0) : objets(std::move(objets)), contraintes(std::move(contraintes)), champs(std::move(champs)), integrateur(std::move(integrateur)), temps(temps) {}

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
void Systeme::donner_contrainte(std::size_t i_obj, std::size_t j_con) {
    objets[i_obj]->set_cont(contraintes[j_con]);
}
void Systeme::ajouter_champ(std::shared_ptr<ChampForces> champ) {
    champs.push_back(std::move(champ));
}
void Systeme::donner_champ(std::size_t i_obj, std::size_t j_cha) {
    objets[i_obj]->set_champ(champs[j_cha]);
}
void Systeme::dessine_sur(SupportADessin& support) const {
    for (const auto& objet : objets) {
        objet->dessine_sur(support);
    }
}
void Systeme::change_int(std::unique_ptr<Integrateur>&& n_int){
    integrateur = nullptr;
    integrateur = std::move(n_int);
}
void Systeme::evolue(double dt) {
    for (const auto& objet : objets) {
    integrateur->integre_1objet(*objet, temps, dt); 
    }
    temps += dt;
}
std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme) {
    sortie << "Systeme : à t = " << systeme.getTemps() << std::endl;
    for (std::size_t i(0); i < systeme.getObjets().size(); ++i){
        sortie << "Objet no " << i + 1 << " :" << std::endl;
        if (systeme.getObjets()[i]) {
        systeme.getObjets()[i]->affiche(sortie);
        sortie << std::endl;
        } else {
            sortie << "Objet null." << std::endl;
        }
    }
    return sortie;
}