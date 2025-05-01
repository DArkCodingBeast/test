#include "ObjetPhysique.h"
#include "constantes.h"
#pragma once



class ForceCentral : public ChampForces
{
protected:
   ObjetPhysique const& obj;
   Vecteur quadratique_inverse(ObjetPhysique const&);
   // This is the object that will be used to calculate the force

public:
   ForceCentral(ObjetPhysique const& );
};



class ChampNewtonien : public ForceCentral
{
public :
   virtual Vecteur force(ObjetPhysique const&, double);
   virtual void affiche(ObjetPhysique const&, double);

};
