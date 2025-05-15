#include "PointMat_Sph.h"

PointMat_Sphere::PointMat_Sphere(Vecteur parameters, Vecteur derive, std::shared_ptr<ChampForces> champ, std::shared_ptr<Contrainte> cont, double masse, double charge, unsigned int dim): 
	PointMateriel(parameters, derive, champ, cont, masse, charge, dim) {}
PointMat_Sphere::PointMat_Sphere(Vecteur parameters, std::shared_ptr<ChampForces> champ, std::shared_ptr<Contrainte> cont, double masse, double charge , unsigned int dim): 
	PointMateriel(parameters, champ, cont , masse, charge, dim) {}
PointMat_Sphere::PointMat_Sphere(Vecteur parameters, Vecteur derive, double masse, double charge, unsigned int dim): 
	PointMateriel(parameters, derive, masse, charge, dim) {}
PointMat_Sphere::PointMat_Sphere(PointMat_Sphere const& autre): PointMateriel(autre) {}
