#include "Integrateur.h"

//contrusctor 
Integrateur::Integrateur(double dt) : dt(dt) {}

IntegrateurEulerCromer::IntegrateurEulerCromer() : Integrateur(0.01) {}
IntegrateurEulerCromer::IntegrateurEulerCromer(double dt) : Integrateur(dt) {}
//Integrateur
void IntegrateurEulerCromer::integre(ObjetMobile& obj, double t, double dt){
        Vecteur acceleration = obj.evolution(t);

        Vecteur& param_integr = obj.getParam();
        Vecteur& deriv_integr = obj.getDerive();

        deriv_integr = deriv_integr + acceleration.mult(dt);
        param_integr = param_integr + deriv_integr.mult(dt);

    }

