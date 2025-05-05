#include "ObjetMobile.h"
#pragma once

class Integrateur {
    public:
        Integrateur(double);
        virtual void integre_1objet(ObjetMobile&, double, double) = 0;
		virtual void integre_2objet(ObjetMobile&, ObjetMobile&, double, double) = 0;
    protected:
        double dt;
    };
    
class IntegrateurEulerCromer : public Integrateur {
    public:
        IntegrateurEulerCromer();
        IntegrateurEulerCromer(double);
        virtual void integre_1objet(ObjetMobile&, double, double) override;
        virtual void integre_2objet(ObjetMobile&, ObjetMobile&, double, double);
    };