#include "ForceCentral.h"




Vecteur ForceCentral::quadratique_inverse(ObjetPhysique const& autre) 
	{Vecteur diff(obj.getParam()-autre.getParam());
     if (diff.norme() < 1e-5) 
		{return Vecteur(0,0,0);}
     else 
		return diff.mult(1/(diff.norme()*diff.norme2())); }

ForceCentral::ForceCentral(ObjetPhysique const& objet): obj(objet) {}  



Vecteur ChampNewtonien::force(ObjetPhysique const& autre, double t) {return quadratique_inverse(autre)*autre.get_masse()*obj.get_masse()*constantes::G;}


void ChampNewtonien::affiche(ObjetPhysique const& autre, double t) {};