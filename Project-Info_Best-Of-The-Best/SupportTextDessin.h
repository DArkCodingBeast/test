#include <ostream>
#include "ObjetPhysique.h"
#pragma once

//prototype
class Systeme;

class SupportADessin {
    public:
    SupportADessin() = default;
    virtual ~SupportADessin() = default;
    SupportADessin(SupportADessin const&)            = delete;
    SupportADessin& operator=(SupportADessin const&) = delete;
    
    virtual void dessine(ObjetPhysique const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    };

class TextViewer : public SupportADessin {
    public:
    TextViewer(std::ostream&);
    virtual ~TextViewer() = default;
    
    TextViewer(TextViewer const&)            = delete;
    TextViewer& operator=(TextViewer const&) = delete;
     
    virtual void dessine(ObjetPhysique const&) override;
    
    virtual void dessine(Systeme const&) override;
     
    protected:
    std::ostream& sortie;
    };