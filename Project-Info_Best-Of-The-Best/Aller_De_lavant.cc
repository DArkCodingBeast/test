#include "Aller_De_lavant.h"


class ObjetPhysique;

Aller_De_lavant::Aller_De_lavant(double vitesse, double temps) : vit(vitesse), temps(temps) {}
    
Vecteur Aller_De_lavant::position(ObjetPhysique const& obj) {return Vecteur(vit*temps , obj.getParam().get_vect()[1] , obj.getParam().get_vect()[2]);}
Vecteur Aller_De_lavant::vitesse(ObjetPhysique const& obj) {return Vecteur(vit , obj.getDerive().get_vect()[1] , obj.getDerive().get_vect()[2]);}
void Aller_De_lavant::affiche(std::ostream& sortie) const {sortie << " l'objet est deplacé sur l'axe des x, avec une vitesse de " << vit << "m/s pendant " << temps << "seconde "<< std::endl;}
void Aller_De_lavant::set(double t) {temps = t;}

