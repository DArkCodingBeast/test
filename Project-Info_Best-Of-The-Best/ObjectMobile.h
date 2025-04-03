#include <iostream>
#include <vector>
#include "Vecteur.h"


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
    Vecteur getParam() const;
    Vecteur getDerive() const;

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
    virtual void integre(ObjetMobile& obj, double t, double dt) override;
};
