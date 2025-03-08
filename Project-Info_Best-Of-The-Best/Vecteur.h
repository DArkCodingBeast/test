#include <iostream>
#include <vector>
#include <cmath>
#pragma once

class Vecteur {

private:

std::vector<double> vect;
size_t dim = vect.size();

public:
Vecteur(std::vector<double> vect = {0}) : vect(vect) {}

void augmente(double val); //increase dimension
void set_coord(unsigned int coord, double value); //change value
void const affiche(); //afficher les elements
bool compare(Vecteur& autre); //regard si on a les memes vecteurs
Vecteur addition(Vecteur autre); //additionnes les elements d'un vecteur
Vecteur soustraction(Vecteur& autre); //soustrait les elements d'un vecteur
Vecteur oppose(); // change le signe de chaque coord
Vecteur mult(double lamba); //multiplie chaque coord par lambda
double prod_scal(Vecteur& autre); // produit scalaire
Vecteur prod_vect(Vecteur& autre);
double norme();
double norme2();
Vecteur unitaire();
};