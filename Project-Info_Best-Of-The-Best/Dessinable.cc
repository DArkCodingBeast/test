#include "PointMateriel.h"

class SupportADessin;

class Systeme {};

class Dessinable {
public:
    virtual ~Dessin() = default;
    virtual dessine_sur(SupportADessin& support) = 0;
};

class SupportADessin {
public:
virtual ~SupportADessin() = default;
SupportADessin(SupportADessin const&)            = delete;
SupportADessin& operator=(SupportADessin const&) = delete;

virtual void dessine(PointMateriel const&) = 0;
virtual void dessine(Systeme const&) = 0;
virtual void dessine(Solide const&) = 0; 
};

class TextViewer : public SupportADessin {
    public:
    TextViewer(std::ostream& sortie)
        : sortie(sortie)
      {}
    virtual ~TextViewer() = default;
    
    TextViewer(TextViewer const&)            = delete;
    TextViewer& operator=(TextViewer const&) = delete;
     
    virtual void dessine(PointMateriel const& point) override {
        sortie << point << std::endl;
    }
    
    virtual void dessine(Systeme const& systeme) override {
        sortie << systeme << std::endl;
    }
     
    private:
    std::ostream& sortie;
    };

/*
virtual void dessine_sur(SupportADessin& support) override
{ support.dessine(*this); }
 */