#include "ChampForces.h"
#include "ObjetPhysique.h"

GravitationConstante::GravitationConstante(Vecteur const& grav) : gravitation(grav) {}
void GravitationConstante::affiche(std::ostream& sortie) const{
    sortie << "un champ de force : " << gravitation << std::endl;
}
Vecteur GravitationConstante::force(ObjetPhysique const& p1, double temps) {
    return gravitation.mult(p1.get_masse());
}

std::ostream& operator<<(std::ostream& sortie, ChampForces const& autre) {
    autre.affiche(sortie);
    return sortie;}