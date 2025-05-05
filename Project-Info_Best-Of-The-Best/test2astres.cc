#include "PointMateriel.h"
#include "ForceCentral.h"
#include "Contrainte.h"
#include "Integrateur.h"
#include <memory>
#include <iostream>
#include <cassert>
using namespace std;

int main(){
	Libre contrainte;
	Vecteur position_Terre(10,0,0);
	Vecteur vitesse_Terre(0,100,0);
	Vecteur position_Lune(-10,0,0);
	Vecteur vitesse_Lune(0,-100,0);
	PointMateriel terre(position_Terre, vitesse_Terre, nullptr, make_shared<Libre> (contrainte), 5.972e24);
	PointMateriel Lune(position_Lune, vitesse_Lune, nullptr, make_shared<Libre>(contrainte) , 5.972e24);
	ChampNewtonien grav_1(terre);
	ChampNewtonien grav_2(Lune);
	terre.set_champ(make_shared<ChampNewtonien>(grav_1));
	Lune.set_champ(make_shared<ChampNewtonien>(grav_2));
	IntegrateurEulerCromer integ;
	double t(0);
	double dt(1e-3);
	//cout << p.evolution(t);
	cout<< "temps:" << t << endl << "terre :" << endl << terre << endl << "Lune :" << endl << Lune << endl;
	for(size_t i(0); i< 1400; ++i){
		integ.integre_2objet(terre,Lune,t,dt);
		t += dt;
		if((i%100)==99){
		cout<< "temps:" << t << endl << terre << endl << Lune << endl;
	}
}
	
	
	cout << "Tout fonctionne" << endl;
	return 0;
	
}
