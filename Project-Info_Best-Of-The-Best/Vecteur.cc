#include "Vecteur.h"

Vecteur::Vecteur(std::vector<double> vect) : vect(vect) {}

void Vecteur::augmente(double val) //increase dimension avec valeur
    { 
        vect.push_back(val);
        dim = vect.size();  
    }

void Vecteur::set_coord(unsigned int coord, double value) //change value
    {
        if (coord > vect.size()) // If the vector has less dimensions than the coordinate 
        {
            std::cerr << "Le vecteur n'a pas tant de dimension" << std::endl;
        }
        else
        {
            vect[coord-1] = value;
        }
    }
void Vecteur::affiche() const //afficher les elements
    {
        for (auto& element : vect)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
bool Vecteur::compare(Vecteur& autre){ //regard si on a les memes vecteurs

    double eps(1e-10);
    
    if (autre.dim == dim)
        {for( unsigned int i(0); i < dim; ++i)
            {if (abs(vect[i]-autre.vect[i]) <= eps) return true;}}
 
    return false; 
}
Vecteur Vecteur::addition(Vecteur autre){ //additionnes les elements d'un vecteur
    Vecteur c;

    if (autre.dim == dim){
    for (size_t i(0); i <= dim; ++i){
        c.vect.push_back(autre.vect[i] + vect[i]);
    }
    return c;}

    //si les dimensions ne sont pas les memes:
    std::cerr << "les dimensions des vecteurs ne sont pas les memes, returning vecteur à additioner" << std::endl;
    return autre; //choix random, mais il faut return qqch
}
Vecteur Vecteur::soustraction(Vecteur& autre){ //soustrait les elements d'un vecteur
    Vecteur c;

    if (autre.dim == dim){
    for (size_t i(0); i < dim; ++i){
        c.vect.push_back(vect[i] - autre.vect[i]);
    }
    return c;}

    //si les dimensions ne sont pas les memes:
    std::cerr << "les dimensions des vecteurs ne sont pas les memes, returning vecteur à soustraire" << std::endl;
    return autre; //choix random, mais il faut return qqch
}
Vecteur Vecteur::oppose(){ // change le signe de chaque coord
    Vecteur b;
        for (auto& numb : vect){
            b.vect.push_back(-numb);
        }
    return b;
}
Vecteur Vecteur::mult(double lamba){ //multiplie chaque coord par lambda
    Vecteur b;
        for (auto& numb : vect){
            b.vect.push_back(lamba*numb);
        }
    return b;
}
double Vecteur::prod_scal(Vecteur& autre){ // produit scalaire
    double scalaire(0);

    if (autre.dim == dim){
        for (size_t i(0); i <= dim; ++i){
            scalaire += vect[i]*autre.vect[i];
        }}
    
    //si les dimensions ne sont pas les memes:
    std::cerr << "les dimensions des vecteurs ne sont pas les memes, returning 0" << std::endl;
    return scalaire; 
}
Vecteur Vecteur::prod_vect(Vecteur& autre){
    Vecteur c;

    if ((dim == 3) and (dim = autre.dim))
    {
        c.vect.push_back(vect[1]*autre.vect[2] - autre.vect[1]*vect[2]); //rappelle que indice commence à 0 donc coordoné 3 a un indice de 2
        c.vect.push_back(-vect[0]*autre.vect[2] + autre.vect[0]*vect[2]);
        c.vect.push_back(vect[0]*autre.vect[1] - autre.vect[0]*vect[1]);
        return c;
    }

    std::cerr << "Les dimensions des vecteurs sont different ou pas égale à 3" << std::endl;
    return autre;
}
double Vecteur::norme(){
    double norme;
    for(auto& elem : vect){
        norme += elem*elem;
    }
    return sqrt(norme);
}
double Vecteur::norme2(){
    double norme;
    for(auto& elem : vect){
        norme += elem*elem;
    }
    return norme; //je choisi de refaire la fonction au lieu de prendre la foction norme au carré en supposant que les doubles sont bizarre 
}
Vecteur Vecteur::unitaire(){
    Vecteur c;
    double norm = norme();

    for (auto& elem : vect){
        c.vect.push_back(elem/norm);
    }
    return c;
}
