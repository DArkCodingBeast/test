#include "ForceCentral.h"



ForceCentral::ForceCentral(PointMateriel & objet): obj(objet) {}  

Vecteur ForceCentral::quadratique_inverse(ObjetPhysique const& autre) 
	{Vecteur diff(obj.getParam()-autre.getParam());
     if (diff.norme() < 1e-5) 
		{return Vecteur(0,0,0);}
     else 
		return diff.mult(1/(diff.norme()*diff.norme2())); }




ChampNewtonien::ChampNewtonien(PointMateriel & point) : ForceCentral(point) {}

Vecteur ChampNewtonien::force(ObjetPhysique const& autre, double t) {return quadratique_inverse(autre)*autre.get_masse()*obj.get_masse()*constantes::G;}
void ChampNewtonien::affiche(std::ostream& sortie) const {sortie << "le champ newtonien associé aux point mat.";};