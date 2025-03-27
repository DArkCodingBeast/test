#include <iostream>
#include <vector>
#include <array>
#include "PointMateriel.h"

class ObjetMobile {

    public:

    //contstruct
    ObjetMobile(std::vector <double> parameters) 
        : parameters(parameters), derivee_temporelle(parameters.size(), 0.0) {}

    //Methode
    virtual void evolution(double t) = 0;

    std::ostream& affiche() const {
        std::ostream& sortie;
        sortie << "nique ta race";
        return sortie;
      }


    protected:

    std::vector <double> parameters;
    std::vector <double> derivee_temporelle;

};

std::ostream& operator<<(std::ostream& sortie, const ObjetMobile& obj){
    sortie << affiche();

    return sortie;}