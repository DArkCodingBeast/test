#include <iostream>
#include <vector>
#include <array>


class GravitationConstante
{

private :

std::array<double,3> gravitation;



public :

std::array<double,3> force(PointMateriel& p1, double temps)
{return gravitation*p1.masse;}
























};










class PointMateriel
{
	
private:

std::array<double,3> vect_etat;
std::array<double,3> vect_derivee;
double masse;
GravitationConstante& ChampForce;

public:

PointMateriel(PointMateriel const& autre)
: vect_etat(autre.vect_etat), vect_derivee(autre.vect_derivee), masse(autre.masse), ChampForce(autre.ChampForce) {} 


PointMateriel(std::array<double,3> const vect_etat, std::array<double,3> const vect_derivee, double masse = 0,GravitationConstante& ChampForce)
: vect_etat(autre.vect_etat), vect_derivee(autre.vect_derivee), masse(autre.masse), ChampForce(autre.ChampForce) {} 








std::array<double,3> Get_Position()
{return vect_etat;}
	
std::array<double,3> Get_Derivative_Pos()
{return vect_derivee;}	
	
double Get_masse()
{return masse;}


void set_vect_etat(std::array<double,3> autre)
{vect_etat = autre;}


void set_vect_derivee(std::array<double,3> autre)
{vect_derivee = autre;}


std::array<double,3> position()
{return vect_etat;}
	
std::array<double,3> vitesse()
{return vect_derivee;}	
	
double evolution(double temps)
{return GetNorme(ChampForce)/masse;}




	
	};





class vect