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

    void affiche(std::ostream& sortie) const {
        for (auto const& para : parameters)
        {
            sortie << para << " ";}
      }


    protected:

    std::vector <double> parameters;
    std::vector <double> derivee_temporelle;

};

std::ostream& operator<<(std::ostream& sortie, const ObjetMobile& obj){
    obj.affiche(sortie);
    sortie << std::endl;
    return sortie;}