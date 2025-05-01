#include "PointMateriel.h"
#include "ForceCentral.h"
#include "Contrainte.h"
#include "Integrateur.h"
#include <iostream>
#include <cassert>
using namespace std;

int main(){
	Libre contrainte;
	Vecteur position_p({0,0,10});
	Vecteur vitesse_p(0,0,0);
	Vecteur position_t(0,0,-6371000);
	Vecteur vitesse_t(0,0,0);
	PointMateriel terre(position_t, vitesse_t, 5.972e24);
	ChampNewtonien grav(terre);
	PointMateriel p(position_p, vitesse_p, grav, contrainte , 0.1);
	IntegrateurEulerCromer integ;
	double t(0);
	double dt(1e-3);
	//cout << p.evolution(t);
	cout<< "temps:" << t << endl << p << endl;
	for(size_t i(0); i< 1400; i++){
		integ.integre(p,t,dt);
		t += dt;
		if((i%100)==99){
		cout<< "temps:" << t << endl << p << endl;
	}
}
	
	
	cout << "Tout fonctionne" << endl;
	return 0;
	
}
