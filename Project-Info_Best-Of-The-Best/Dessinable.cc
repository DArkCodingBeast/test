#include "PointMateriel.h"

class SupportADessin;

class Systeme {};

class Dessinable {
public:
    virtual ~Dessin() = default;
    virtual dessine_sur(SupportADessin& support) = 0;
};

class SupportADessin
{
public:
virtual ~SupportADessin() = default;

virtual void dessine(PointMateriel const&) = 0;
virtual void dessine(Systeme const&) = 0;
virtual void dessine(Solide const&) = 0; 
};