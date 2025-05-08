#include "Cont_spherique.h"
#include "ObjetPhysique.h"
#include "Contrainte.h"
#include "ChampForces.h"
#include "Dessinable.h"
#include "ObjetMobile.h"
#include "constantes.h"
#include <cmath>

Cont_spherique::Cont_spherique(double rayon) : rayon(rayon) {}
void Cont_spherique::affiche(std::ostream& sortie) const{
    sortie << "Contrainte sphérique de rayon " << rayon << std::endl;}
    
    
    
Vecteur Cont_spherique::position(ObjetPhysique const& obj)
	{ 
	  double theta = obj.getParam().get_vect()[0]; 
      double phi = obj.getParam().get_vect()[1];   

      double x = rayon * sin(theta) * cos(phi);
      double y = rayon * sin(theta) * sin(phi);
      double z = rayon * cos(theta);
	  
	  return Vecteur(x,y,z);}
		
		
		
Vecteur Cont_spherique::vitesse(ObjetPhysique const& obj)
	{
	  double teta = obj.getParam().get_vect()[0]; 
      double phi = obj.getParam().get_vect()[1]; 
      double vteta = obj.getDerive().get_vect()[0];  
      double vphi = obj.getDerive().get_vect()[1]; 

	  Vecteur uteta (cos(teta) * cos(phi), cos(teta) * sin(phi), sin(teta)); // <--- a verif le signe du sin(teta))
      Vecteur uphi (-1*sin(phi), cos(phi), 0.0);
      
	  return Vecteur(uteta.mult(rayon * vteta ) + uphi.mult(rayon * sin(teta) * vphi)); }
      
      


Vecteur Cont_spherique::applique_force(ObjetPhysique const& obj, Vecteur force ,double t) 
{ double teta = position(obj).get_vect()[0];
  double phi = position(obj).get_vect()[1];
  double vteta = vitesse(obj).get_vect()[0];
  double vphi = vitesse(obj).get_vect()[1];
  std::cout << "hehe" << std::endl;
  Vecteur uteta (cos(teta) * cos(phi), cos(teta) * sin(phi), sin(teta)); // <-- verif signe sin(teta)
  Vecteur uphi (-1*sin(phi), cos(phi), 0.0);																			
  std::cout << "hoho" << std::endl;
  double acc_teta = (force * uteta) / (obj.get_masse() * rayon) + sin(teta) * cos(teta) * vphi * vphi;
  std::cout << "haha" << std::endl;		 //le produit scalaire par dessu et en dessous pas content
  double acc_phi = (force * uphi) / (obj.get_masse() * rayon * sin(teta)) - ( 2 * vteta * vphi ) / tan(teta);
  std::cout << "hihi" << std::endl;
  return Vecteur({acc_teta,acc_phi});}


std::ostream& operator<<(std::ostream& sortie, Cont_spherique const& autre){
    autre.affiche(sortie);
    return sortie;}
	
	

	
    
    
 


