#include <iostream>
#include <vector>
#include <array>
#include "PointMateriel.h"

class ObjetMateriel {

    public:

    virtual void evolution(double t) = 0;



    protected:

    std::vector <double> parmaterers;
    std::vector <double, dim()> dérivée_temporelle_des_paramètres;
    size_t dim() {return parameters.size();}

};