#include "PointMateriel.h"
#include "Integrateur.h"
#include "Cont_spherique"
using namespace std;

int main(){
	Cont_spherique contrainte;
	Vecteur position_p(0,0,10);
	Vecteur vitesse_p(0,0,0);
	Vecteur position_t(0,0,-6748345);
	Vecteur vitesse_t(0,0,0);
	PointMateriel terre(position_t, vitesse_t, 5.972e24);
	ChampNewtonien grav(terre);
	PointMateriel p(position_p, vitesse_p, make_shared<ChampNewtonien>(grav), make_shared<Libre>(contrainte) , 0.1);
	IntegrateurEulerCromer integ;
	double t(0);
	double dt(1e-3);
cout << p << endl;
contrainte.applique_force(p);
cout << p << endl;
return 0;}


