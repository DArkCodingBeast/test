#include "Dessinable.h"
#include "SupportTextDessin.h"

std::ostream& operator<<(std::ostream& sortie, Dessinable const& dess){
    sortie << "Dessinable object";
    return sortie;
}
