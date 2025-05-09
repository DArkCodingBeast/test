#include <vector>
#include <iostream>
#include <cmath>
#pragma once

class Vecteur {

    protected:
        std::vector<double> vect;
    
    public:
        Vecteur(std::vector<double> vect = {});
        Vecteur(std::size_t);
        Vecteur(double, double, double);

        std::vector<double> get_vect() const;
        std::size_t get_dim() const;
        void augmente(double); //increase dimension
        void set_coord(std::size_t, double); //change value
        void affiche(std::ostream&) const; //afficher les elements
        bool compare(const Vecteur&) const; //regard si on a les memes vecteurs
        Vecteur addition(Vecteur) const; //additionnes les elements d'un vecteur
        Vecteur soustraction(Vecteur) const; //soustrait les elements d'un vecteur
        Vecteur oppose(); // change le signe de chaque coord
        Vecteur mult(double) const; //multiplie chaque coord par lambda
        double prod_scal(const Vecteur&) const; // produit scalaire
        Vecteur prod_vect(const Vecteur&) const;
        double norme() const; //norme :3
        double norme2()const ; //norme au carreeeeeeeeeeeee
        Vecteur unitaire() const; //le vecteur unitaire associated to this vector mm yes yes
    };

std::ostream& operator<<(std::ostream&, const Vecteur&);
bool operator==(Vecteur, const Vecteur&);
bool operator!=(Vecteur, const Vecteur&);
double operator*(Vecteur, const Vecteur&);
void operator+=(Vecteur&, const Vecteur&);
Vecteur operator+(Vecteur, const Vecteur&);
void operator-=(Vecteur&, const Vecteur&);
Vecteur operator-(Vecteur, const Vecteur&);