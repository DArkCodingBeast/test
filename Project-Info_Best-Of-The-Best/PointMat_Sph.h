#include "PointMateriel.h"

class PointMat_Sphere : public PointMateriel{

public:
    PointMat_Sphere(PointMat_Sphere const&);
    PointMat_Sphere(Vecteur, Vecteur, std::shared_ptr<ChampForces> /*champ*/, std::shared_ptr<Contrainte> /*cont*/, double, double = 0, unsigned int = 3);
    PointMat_Sphere(Vecteur, std::shared_ptr<ChampForces> /*champ*/, std::shared_ptr<Contrainte> /*cont*/, double, double = 0, unsigned int = 3);
    PointMat_Sphere(Vecteur, Vecteur, double, double = 0, unsigned int = 3);
};
