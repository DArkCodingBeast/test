#include "Integrateur.h"

//contrusctor 
Integrateur::Integrateur(double dt) : dt(dt) {}

IntegrateurEulerCromer::IntegrateurEulerCromer() : Integrateur(0.01) {}
IntegrateurEulerCromer::IntegrateurEulerCromer(double dt) : Integrateur(dt) {}
//Integrateur
void IntegrateurEulerCromer::integre(ObjetMobile& obj, double t, double dt){
        Vecteur acceleration = obj.evolution(t);
        std::cout << acceleration << std::endl;
        Vecteur& param_integr = obj.getParam();
        std::cout << param_integr << std::endl;
        Vecteur& deriv_integr = obj.getDerive();
        std::cout << deriv_integr << std::endl;
        deriv_integr = deriv_integr + acceleration.mult(dt);
        std::cout << deriv_integr << std::endl;
        param_integr = param_integr + deriv_integr.mult(dt);
        std::cout << param_integr << std::endl;

    }

