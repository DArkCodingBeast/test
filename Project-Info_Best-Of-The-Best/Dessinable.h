#pragma once
#include <ostream>

//prototypes
class SupportADessin;

class Dessinable {
    public:
        virtual ~Dessinable() = default;
        virtual void dessine_sur(SupportADessin&) = 0;
};

std::ostream& operator<<(std::ostream&, Dessinable const&);