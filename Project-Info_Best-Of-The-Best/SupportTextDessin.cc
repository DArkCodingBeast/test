#include "SupportTextDessin.h"
#include "Systeme.h"

TextViewer::TextViewer(std::ostream& sortie)
    : sortie(sortie)
    {}
     
void TextViewer::dessine(ObjetPhysique const& point){
    sortie << point << std::endl;
}
    
void TextViewer::dessine(Systeme const& systeme) {
    sortie << systeme << std::endl;
}