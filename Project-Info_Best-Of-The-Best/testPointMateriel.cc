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








int main(){
   // un vecteur en 3D :
Vecteur vect1(1.0, 2.0, -0.1);
// un autre vecteur en 3D
Vecteur vect2(2.6, 3.5, 4.1);
Vecteur vect3(vect1); // copie de V1
Vecteur vect4(4); // le vecteur nul en 4D
cout << "Vecteur 1 : " << vect1 << endl;
cout << "Vecteur 2 : " << vect2 << endl;
cout << "Vecteur 3 : " << vect3 << endl;
cout << "Vecteur 4 : " << vect4 << endl;
cout << "Le vecteur 1 est ";
if (vect1 == vect2) {
cout << "égal au";
} else {
cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (vect1 != vect3) {
cout << "différent du";
} else {
cout << "égal au";
}
cout << " vecteur 3." << endl;

return 0;}