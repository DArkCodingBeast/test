#include "Vecteur.h"
#include "ObjetMobile.h"
#include "ObjetPhysique.h"
#include "PointMateriel.h"
#include <cmath>
using namespace std;



class ForceCentral : public ChampForces
{
private:
   ObjetPhysique& obj;

   // This is the object that will be used to calculate the force
   Vecteur quadratique_inverse(ObjetPhysique& autre)
   {Vecteur diff(getParam()-autre.getParam());
      if (norme(diff) < 1e-5) {return{(0,0,0)};}
     else return diff.mult(1/(norme(diff)*norme2(diff))); }

public:
   ForceCentral(ObjetPhysique& obj) : obj(obj) {}
};


class ChampNewtonien : public ForceCentral
{
public :
   virtual Vecteur force(ObjetPhysique const&, double) override {}




};

