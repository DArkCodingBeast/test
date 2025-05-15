#include <vector>
#include "ChampForces.h"
#pragma once

class ObjetPhysique;

class ChampComp : public ChampForces{
private :
	std::vector<ChampForces> compo_champ;
	
	
public:
	ChampComp(ChampComp const &);
	ChampComp(ChampForces const &);
	ChampComp();
	Vecteur force(ObjetPhysique const &, double);



	};
