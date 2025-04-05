#include <vector>
#include <iostream>
#include <cmath>
#pragma once
    
class Vecteur {

    protected:
        std::vector<double> vect;
        size_t dim = vect.size();
    
    public:
        Vecteur(std::vector<double> vect = {0});
        Vecteur(size_t);
        Vecteur(double, double, double);

        std::vector<double> get_vect() const;
        size_t get_dim() const;
        void augmente(double); //increase dimension
        void set_coord(unsigned int, double); //change value
        void affiche() const; //afficher les elements
        bool compare(const Vecteur&); //regard si on a les memes vecteurs
        Vecteur addition(const Vecteur&); //additionnes les elements d'un vecteur
        Vecteur soustraction(const Vecteur&); //soustrait les elements d'un vecteur
        Vecteur oppose(); // change le signe de chaque coord
        Vecteur mult(double); //multiplie chaque coord par lambda
        double prod_scal(const Vecteur&); // produit scalaire
        Vecteur prod_vect(const Vecteur&);
        double norme();
        double norme2();
        Vecteur unitaire();
    };

std::ostream& operator<<(std::ostream&, const Vecteur&);
bool operator==(Vecteur, const Vecteur&);
bool operator!=(Vecteur, const Vecteur&);
double operator*(Vecteur, const Vecteur&);
void operator+=(Vecteur&, const Vecteur&);
Vecteur operator+(Vecteur, const Vecteur&);
void operator-=(Vecteur&, const Vecteur&);
Vecteur operator-(Vecteur, const Vecteur&);