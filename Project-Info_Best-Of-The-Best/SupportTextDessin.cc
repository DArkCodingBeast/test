#include "SupportTextDessin.h"
#include "Systeme.h"

TextViewer::TextViewer(std::fstream& sortie)
    : sortie(sortie)
    {}
     
void TextViewer::dessine(const ObjetPhysique& point){
    sortie << point << std::endl;
}
    
void TextViewer::dessine(Systeme const& systeme) {
    sortie << systeme << std::endl;
}
