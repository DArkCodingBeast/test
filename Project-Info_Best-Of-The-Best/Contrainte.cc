#include "Contrainte.h"
#include "ObjetPhysique.h"


Vecteur Libre:: applique_force(ObjetPhysique const& obj,Vecteur force, double temps){
    if (obj.get_masse() == 0) 
        {return force;}      
    return force.mult(1 / obj.get_masse());
}

Vecteur Libre::position(ObjetPhysique const& obj){
    return obj.getParam();
}
Vecteur Libre::vitesse(ObjetPhysique const& obj){
    return obj.getDerive();
}
void Libre::affiche(std::ostream& sortie) const{
    sortie << "Aucune contrainte n'est appliqué sur l'objet." << std::endl;
}
std::ostream& operator<<(std::ostream& sortie, Contrainte const& autre){
    autre.affiche(sortie);
    return sortie;
}