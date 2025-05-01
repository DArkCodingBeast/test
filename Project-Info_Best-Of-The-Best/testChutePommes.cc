#include "PointMateriel.h"
#include "ForceCentral.h"
#include "Contrainte.h"
#include "Integrateur.h"
#include <iostream>
#include <cassert>
using namespace std;

int main(){
	ContrainteLibre contrainte;
	Vecteur position_p({0,0,10});
	Vecteur vitesse_p(0,0,0);
	Vecteur position_t(0,0,-6371000);
	Vecteur vitesse_t(0,0,0);
	PointMateriel terre(position_t, vitesse_t, 5.972e24);
	Gravitation_ponctuelle grav(terre);
	PointMateriel p(position_p, vitesse_p, shared_ptr<ChampForces>(&grav), shared_ptr<Contrainte>(&contrainte) , 0.1);
	IntegrateurEulerCromer integ;
	double t(0);
	double dt(1e-3);
	//cout << p.evolution(t);
	cout<< "temps:" << t << endl << p << endl;
	for(size_t i(0); i< 1400; i++){
		integ.Integre(p,t,dt);
		t += dt;
		if((i%100)==99){
		cout<< "temps:" << t << endl << p << endl;
	}
}
	
	
	cout << "Tout fonctionne" << endl;
	return 0;
	
}
