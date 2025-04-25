#include "ObjetMobile.h"
#pragma once

class Integrateur {
    public:
        Integrateur(double);
        virtual void integre(ObjetMobile&, double, double) = 0;
    
    protected:
        double dt;
    };
    
    class IntegrateurEulerCromer : public Integrateur {
    public:
        IntegrateurEulerCromer();
        IntegrateurEulerCromer(double);
        virtual void integre(ObjetMobile&, double, double) override;
    };