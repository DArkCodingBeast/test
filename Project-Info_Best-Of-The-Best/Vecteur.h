#include <vector>
#pragma once

class Vecteur {

    private:
        std::vector<double> vect;
        size_t dim = vect.size();
    
    public:
        Vecteur(std::vector<double> vect = {0});
    
        void augmente(double); //increase dimension
        void set_coord(unsigned int, double); //change value
        void affiche() const; //afficher les elements
        bool compare(Vecteur&); //regard si on a les memes vecteurs
        Vecteur addition(Vecteur); //additionnes les elements d'un vecteur
        Vecteur soustraction(Vecteur&); //soustrait les elements d'un vecteur
        Vecteur oppose(); // change le signe de chaque coord
        Vecteur mult(double); //multiplie chaque coord par lambda
        double prod_scal(Vecteur&); // produit scalaire
        Vecteur prod_vect(Vecteur&);
        double norme();
        double norme2();
        Vecteur unitaire();
    };
