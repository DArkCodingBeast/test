#include "Vecteur.h"
#pragma once


class ObjetMobile {

public:

    //contstruct
    ObjetMobile(std::vector <double>);
    //Methode
    virtual void evolution(double) = 0;
    void affiche(std::ostream&) const;

    //acceder les trucs qui truc
    //pour les ref
    Vecteur& getParam();
    Vecteur& getDerive();
    //pour des copies(?)
    const Vecteur& getParam() const;
    const Vecteur& getDerive() const;

protected:

    Vecteur parameters; // This would be the (E) vector
    Vecteur derivee_temporelle; //I guess (E')??

};

std::ostream& operator<<(std::ostream&, const ObjetMobile&);

class Integrateur {
public:
    virtual void integre(ObjetMobile&, double, double) = 0;
};

class IntegrateurEulerCromer : public Integrateur {
public:
    virtual void integre(ObjetMobile&, double, double) override;
};
