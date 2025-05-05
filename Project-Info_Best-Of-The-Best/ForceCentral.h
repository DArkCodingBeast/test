#include "ObjetPhysique.h"
#include "Vecteur.h"
#include "constantes.h"
#include "ObjetPhysique.h"
#include "PointMateriel.h"
#include "ChampForces.h"
#include <iostream>
#pragma once



class ForceCentral : public ChampForces
{
protected:
   ObjetPhysique const& obj;
   Vecteur quadratique_inverse(ObjetPhysique const&);


public:
   ForceCentral(PointMateriel& );
};



class ChampNewtonien : public ForceCentral
{
public :

   ChampNewtonien(PointMateriel &);
   virtual Vecteur force(ObjetPhysique const&, double) ;
   virtual void affiche(std::ostream&) const ;

};
