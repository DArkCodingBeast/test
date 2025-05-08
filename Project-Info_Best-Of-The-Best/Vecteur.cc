#include "Vecteur.h"

// constructeurs
Vecteur::Vecteur(std::vector<double> vect) : vect(vect) {}
Vecteur::Vecteur(std::size_t dim) : vect(std::vector<double>(dim, 0.0)) {}
Vecteur::Vecteur(double x, double y, double z) : vect(std::vector<double>{x, y, z}) {}

//operateurs
std::ostream& operator<<(std::ostream& sortie, const Vecteur& vecteur)
    {
        vecteur.affiche(sortie);
        return sortie;
}
bool operator==(Vecteur VICTOR, const Vecteur& autre)
    {
        return VICTOR.compare(autre);
}
bool operator!=(Vecteur VICTOR, const Vecteur& autre)
    {
        return  !(VICTOR.compare(autre));
}
double operator*(Vecteur one, const Vecteur& other)
    {
        return one.prod_scal(other);
}
void operator+=(Vecteur& one, const Vecteur& other)
    {
        one = one.addition(other);
}
Vecteur operator+(Vecteur one, const Vecteur& other)
    {
        one += other;
        return one;
}
void operator-=(Vecteur& one, const Vecteur& other)
    {
        one = one.soustraction(other);
}
Vecteur operator-(Vecteur one, const Vecteur& other)
    {
        one -= other;
        return one;
}

//methodes
std::vector<double> Vecteur::get_vect() const
    {
        return vect;
}
std::size_t Vecteur::get_dim() const
    {
        return vect.size();
}

void Vecteur::augmente(double val) //increase dimension avec valeur
    { 
        vect.push_back(val);

}
void Vecteur::set_coord(std::size_t coord, double value) //change value
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
void Vecteur::affiche(std::ostream& sortie) const //afficher les elements
    {
        for (auto& element : vect)
        {
            sortie << element << " ";
        }
        sortie << std::endl;
}
bool Vecteur::compare(const Vecteur& autre) const { //regard si on a les memes vecteurs

    double eps(1e-10);
    
    if (autre.get_dim() != get_dim()) return false;
    for(std::size_t i(0); i < get_dim(); ++i){
            if (abs(vect[i]-autre.vect[i]) > eps) return false; //as soon as one thing no match
        }     
    return true; //if all match
}
Vecteur Vecteur::addition(Vecteur autre) const { //additionnes les elements d'un vecteur
    if (autre.get_dim() != get_dim()){
        if (get_dim() > autre.get_dim()){
            for (std::size_t miaw(autre.get_dim()); miaw <= get_dim(); ++miaw){
                autre.augmente(0);
            }
            for (std::size_t i(0); i < get_dim(); ++i){
                autre.vect[i] += vect[i];
        }
        } else if (get_dim() < autre.get_dim()){
            Vecteur wow(*this);
            for (std::size_t miaw(get_dim()); miaw <= autre.get_dim(); ++miaw){
                wow.augmente(0);
            }
            for (std::size_t i(0); i < get_dim(); ++i){
                autre.vect[i] += wow.vect[i];
            }
        }
    } else {
        for (std::size_t i(0); i < get_dim(); ++i){
        autre.vect[i] += vect[i];
        } 
    }
    return autre;
}
Vecteur Vecteur::soustraction(Vecteur autre) const{ //soustrait les elements d'un vecteur
    if (autre.get_dim() != get_dim()){
        if (get_dim() > autre.get_dim()){
            for (std::size_t miaw(autre.get_dim()); miaw <= get_dim(); ++miaw){
                autre.augmente(0);
            }
            for (std::size_t i(0); i < get_dim(); ++i){
                autre.vect[i] -= vect[i];
        }
        } else if (get_dim() < autre.get_dim()){
            Vecteur wow(*this);
            for (std::size_t miaw(get_dim()); miaw <= autre.get_dim(); ++miaw){
                wow.augmente(0);
            }
            for (std::size_t i(0); i < get_dim(); ++i){
                autre.vect[i] -= wow.vect[i];
            }
        }
    } else {
        for (std::size_t i(0); i < get_dim(); ++i){
        autre.vect[i] -= vect[i];
        } 
    }
    return autre;
}
Vecteur Vecteur::oppose(){ // change le signe de chaque coord
    Vecteur b;
        for (auto& numb : vect){
            b.augmente(-numb);
        }
    return b;
}
Vecteur Vecteur::mult(double lamba) const{ //multiplie chaque coord par lambda
    Vecteur b;
        for (auto& numb : vect){
            b.augmente(lamba*numb);
        }
    return b;
}
double Vecteur::prod_scal(const Vecteur& autre) const{ // produit scalaire
    double scalaire(0);

    if (autre.get_dim() == get_dim()){
        for (std::size_t i(0); i < get_dim(); ++i){
            scalaire += vect[i]*autre.vect[i];
        }} else { 
            //si les dimensions ne sont pas les memes:
            std::cerr << "les dimensions des vecteurs ne sont pas les memes, returning 0" << std::endl;
            return 0;}
    return scalaire; 
}
Vecteur Vecteur::prod_vect(const Vecteur& autre) const{
    Vecteur c;

    if ((get_dim() == 3) and (get_dim() == autre.get_dim()))
    {
        c.augmente(vect[1]*autre.vect[2] - autre.vect[1]*vect[2]); //rappelle que indice commence à 0 donc coordoné 3 a un indice de 2
        c.augmente(-vect[0]*autre.vect[2] + autre.vect[0]*vect[2]);
        c.augmente(vect[0]*autre.vect[1] - autre.vect[0]*vect[1]);
        return c;
    }

    std::cerr << "Les dimensions des vecteurs sont different ou pas égale à 3" << std::endl;
    return autre;
}
double Vecteur::norme() const{
    double norme(0);
    for(auto& elem : vect){
        norme += elem*elem;
    }
    return sqrt(norme);
}
double Vecteur::norme2() const{
    double norme(0);
    for(auto& elem : vect){
        norme += elem*elem;
    }
    return norme; 
//je choisi de refaire la fonction au lieu de prendre la foction norme au carré en supposant que les doubles sont bizarre :)
}
Vecteur Vecteur::unitaire() const{
    Vecteur c;
    double norm = norme();
    if (norm == 0) {return *this;} //on ne peux pas normaliser un vecteur nul
    for (auto& elem : vect){
        c.augmente(elem/norm);
    }
    return c;
}
