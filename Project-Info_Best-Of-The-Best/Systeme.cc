#include "Systeme.h"

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
void donner_contrainte(std::size_t i_obj, std::size_t j_con) {
    // gotta do this one

}
void Systeme::ajouter_champ(std::shared_ptr<ChampForces> champ) {
    champs.push_back(std::move(champ));
}
void donner_champ(std::size_t i_obj, std::size_t j_cha) {
    // gotta do this one

}
void Systeme::dessine_sur(SupportADessin& support) const {
    for (const auto& objet : objets) {
        objet->dessine_sur(support);
    }
} 

void Systeme::evolue(double dt) {
    for (const auto& objet : objets) {
    integrateur.integre_1objet(*objet, temps, dt); 
    }
    temps += dt;
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