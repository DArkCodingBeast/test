#include "ObjetMobile.h"

//contstruct
ObjetMobile::ObjetMobile(Vecteur para) 
        : parameters(para), derivee_temporelle(para.get_dim()) {}


void ObjetMobile::affiche(std::ostream& sortie) const {
        sortie << "Paramètres : ";
        const std::vector<double>& para_temp = parameters.get_vect();
        const std::vector<double>& deri_temp_temp = derivee_temporelle.get_vect();
        for (auto const& para : para_temp)
        {
            sortie << para << " ";}
        sortie << "\nDérivées Temporelles : ";
        for (auto const& deri : deri_temp_temp)
        {
            sortie << deri << " ";}
    }

//acceder les trucs qui truc
//pour les ref
Vecteur& ObjetMobile::getParam() {return parameters;} 
Vecteur& ObjetMobile::getDerive() {return derivee_temporelle;}
//pour des copies
Vecteur ObjetMobile::getParam() const {return parameters;}
Vecteur ObjetMobile::getDerive() const {return derivee_temporelle;}

std::ostream& operator<<(std::ostream& sortie, const ObjetMobile& obj){
    obj.affiche(sortie);
    sortie << std::endl;
    return sortie;}
