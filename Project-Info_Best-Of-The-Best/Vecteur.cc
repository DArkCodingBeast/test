#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Vecteur {

private:

vector<double> vect;
size_t dim = vect.size();

public:
Vecteur(vector<double> vect = {0}) : vect(vect) {}

void augmente(double val) //increase dimension
    { 
       for(unsigned int i(1); i <= val; ++i) 
       {
        vect.push_back(0);
       }
    }

void set_coord(unsigned int coord, double value) //change value
    {
        if (coord > vect.size()) // If the vector has less dimensions than the coordinate 
        {
            cerr << "Le vecteur n'a pas tant de dimension" << endl;
        }
        else
        {
            vect[coord-1] = value;
        }
    }
void const affiche() //afficher les elements
    {
        for (auto& element : vect)
        {
            cout << element << " ";
        }
        cout << endl;
    }
bool compare(Vecteur& autre){ //regard si on a les memes vecteurs

    double eps(1e-10);
    
    if (autre.dim == dim)
        {for( unsigned int i(0); i <= dim; ++i)
            {if (abs(vect[i]-autre.vect[i]) <= eps) return true;}}
 
    return false; 
}
Vecteur addition(Vecteur autre){ //additionnes les elements d'un vecteur
    Vecteur c;

    if (autre.dim == dim){
    for (size_t i(0); i <= dim; ++i){
        c.vect.push_back(autre.vect[i] + vect[i]);
    }
    return c;}

    //si les dimensions ne sont pas les memes:
    cerr << "les dimensions des vecteurs ne sont pas les memes, returning vecteur à additioner" << endl;
    return autre; //choix random, mais il faut return qqch
}
Vecteur soustraction(Vecteur& autre){ //soustrait les elements d'un vecteur
    Vecteur c;

    if (autre.dim == dim){
    for (size_t i(0); i <= dim; ++i){
        c.vect.push_back(vect[i] - autre.vect[i]);
    }
    return c;}

    //si les dimensions ne sont pas les memes:
    cerr << "les dimensions des vecteurs ne sont pas les memes, returning vecteur à soustraire" << endl;
    return autre; //choix random, mais il faut return qqch
}
Vecteur oppose(){ // change le signe de chaque coord
    Vecteur b;
        for (auto& numb : vect){
            b.vect.push_back(-numb);
        }
    return b;
}
Vecteur mult(double lamba){ //multiplie chaque coord par lambda
    Vecteur b;
        for (auto& numb : vect){
            b.vect.push_back(lamba*numb);
        }
    return b;
}
double prod_scal(Vecteur& autre){ // produit scalaire
    double scalaire;

    if (autre.dim == dim){
        for (size_t i(0); i <= dim; ++i){
            scalaire += vect[i]*autre.vect[i];
        }}
    
    //si les dimensions ne sont pas les memes:
    cerr << "les dimensions des vecteurs ne sont pas les memes, returning 0" << endl;
    return 0.0; 
}
Vecteur prod_vect(Vecteur& autre){
    Vecteur c;

    if ((dim = 3) and (dim = autre.dim))
    {
        c.vect.push_back(vect[1]*autre.vect[2] - autre.vect[1]*vect[2]); //rappelle que indice commence à 0 donc coordoné 3 a un indice de 2
        c.vect.push_back(-vect[0]*autre.vect[2] + autre.vect[0]*vect[2]);
        c.vect.push_back(vect[0]*autre.vect[1] - autre.vect[1]*vect[0]);
        return c;
    }

    cerr << "Les dimensions des vecteurs sont different ou pas égale à 3" << endl;
    return autre;
}
double norme(){
    double norme;
    for(auto& elem : vect){
        norme += elem*elem;
    }
    return sqrt(norme);
}
double norme2(){
    double norme;
    for(auto& elem : vect){
        norme += elem*elem;
    }
    return norme; //je choisi de refaire la fonction au lieu de prendre la foction norme au carré en supposant que les doubles sont bizarre 
}
Vecteur unitaire(){
    Vecteur c;
    double norm = norme();

    for (auto& elem : vect){
        c.vect.push_back(elem/norm);
    }
    return c;
}
};

int main(){

Vecteur vect1;
Vecteur vect2;
Vecteur vect3;
/* Cette partie
* (1) pourrait être écrite autrement, par exemple avec des
* manipulateurs (set_coord()) ;
* (2) sera revue dans 2 semaines (constructeurs, surcharge des opérateurs).
*/
// v1 = (1.0, 2.0, -0.1)
vect1.augmente(1.0); vect1.augmente(0.0); vect1.augmente(-0.1);
vect1.set_coord(1, 2.0); // pour tester set_coord()
// v2 = (2.6, 3.5, 4.1)
vect2.augmente(2.6); vect2.augmente(3.5); vect2.augmente(4.1);
vect3 = vect1;
cout << "Vecteur 1 : ";
vect1.affiche();
cout << endl;
cout << "Vecteur 2 : ";
vect2.affiche();
cout << endl;
cout << "Le vecteur 1 est ";
if (vect1.compare(vect2)) {
cout << "égal au";
} else {
cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (not vect1.compare(vect3)) {
cout << "différent du";
} else {
cout << "égal au";
}
cout << " vecteur 3." << endl;

    return 0;
}



