#include "ChampForces.h"






ChampComp::ChampComp(ChampComp const & tab) : compo_champ(tab) {}
ChampComp::ChampComp(ChampForces const & champ1) : compo_champ.push_back(champ1) {}
ChampComp::ChampComp() : compo_champ({}) {}
ChampComp::Vecteur force(ObjetPhysique const & obj, double t);
