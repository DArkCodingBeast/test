#include "Vecteur.h"
#pragma once


class ObjetMobile {

public:

    //contstruct
    ObjetMobile(Vecteur para = {0,0,0});
    //Methode
    virtual Vecteur evolution(double) = 0;
    void affiche(std::ostream&) const;

    //acceder les trucs qui truc
    //pour les ref
    Vecteur& getParam();
    Vecteur& getDerive();
    //pour des copies(?)
    Vecteur getParam() const;
    Vecteur getDerive() const;

protected:

    Vecteur parameters; // This would be the (E) vector
    Vecteur derivee_temporelle; //I guess (E')??

};

std::ostream& operator<<(std::ostream&, const ObjetMobile&);


