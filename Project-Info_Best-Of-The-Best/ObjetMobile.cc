#include <iostream>
#include <vector>
#include "Vecteur.h"


class ObjetMobile {

public:

    //contstruct
    ObjetMobile(std::vector <double> para) 
        : parameters(para), derivee_temporelle(para.size()) {}

    //Methode
    virtual void evolution(double t) = 0;

    void affiche(std::ostream& sortie) const {
        sortie << "Paramètres : ";
        std::vector<double> para_temp = parameters.get_vect();
        std::vector<double> deri_temp_temp = derivee_temporelle.get_vect();
        for (auto const& para : para_temp)
        {
            sortie << para << " ";}
        sortie << "\nDérivées Temporelles : ";
        for (auto const& deri : deri_temp_temp)
        {
            sortie << deri << " ";}
      }

      //acceder les trucs qui truc
      Vecteur getParam() {return parameters;}
      Vecteur getDerive() {return derivee_temporelle;}

protected:

    Vecteur parameters; // This would be the (E) vector
    Vecteur derivee_temporelle; //I guess (E')??

};

std::ostream& operator<<(std::ostream& sortie, const ObjetMobile& obj){
    obj.affiche(sortie);
    sortie << std::endl;
    return sortie;}


class Integrateur {
public:
    virtual void integre(ObjetMobile& obj, double t, double dt) = 0;
};

class IntegrateurEulerCromer : public Integrateur {
public:
    virtual void integre(ObjetMobile& obj, double t, double dt) override{
        obj.evolution(t);

        Vecteur param_integr = obj.getParam();
        Vecteur deriv_integr = obj.getDerive();


        
    }

};
