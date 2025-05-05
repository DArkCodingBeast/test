#include "Integrateur.h"

//contrusctor 
Integrateur::Integrateur(double dt) : dt(dt) {}

IntegrateurEulerCromer::IntegrateurEulerCromer() : Integrateur(0.01) {}
IntegrateurEulerCromer::IntegrateurEulerCromer(double dt) : Integrateur(dt) {}
//Integrateur
void IntegrateurEulerCromer::integre_1objet(ObjetMobile& obj, double t, double dt){
        Vecteur acceleration = obj.evolution(t);

        Vecteur& param_integr = obj.getParam();
        Vecteur& deriv_integr = obj.getDerive();

        deriv_integr = deriv_integr + acceleration.mult(dt);
        param_integr = param_integr + deriv_integr.mult(dt);

    }

void IntegrateurEulerCromer::integre_2objet(ObjetMobile& obj, ObjetMobile& autre, double t, double dt) {
		Vecteur acceleration_1 = obj.evolution(t);
		Vecteur acceleration_2 = autre.evolution(t);
		
		Vecteur& param_1 = obj.getParam();
        Vecteur& deriv_1 = obj.getDerive();
        Vecteur& param_2 = autre.getParam();
        Vecteur& deriv_2 = autre.getDerive();
  
		deriv_1 = deriv_1 + acceleration_1.mult(dt);
        param_1 = param_1 + deriv_1.mult(dt);
		deriv_2 = deriv_2 + acceleration_2.mult(dt);
        param_2 = param_2 + deriv_2.mult(dt);


}   
