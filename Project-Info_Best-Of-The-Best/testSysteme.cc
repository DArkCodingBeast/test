/*#include "Systeme.h"
#include "PointMateriel.h"
#include "ForceCentral.h"
#include "Contrainte.h"
#include "SupportTextDessin.h"
#include "Cont_spherique.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    // Create a text viewer for output
    TextViewer viewer(cout);

    // Create a system
    Systeme systeme;

    // Create constraints
    auto contrainteLibre = make_shared<Libre>();

    // Create force fields
    Vecteur gravitation(0.0, 0.0, -9.81);
    auto champGravitation = make_shared<GravitationConstante>(gravitation);

    // Create objects
    Vecteur position1({M_PI_4, M_PI_4});
    Vecteur vitesse1({0.0, 0.0});
    auto objet1 = make_unique<PointMateriel>(position1, vitesse1, champGravitation, contrainteLibre, 1.0);

    Vecteur position2(5.0, 0.0, 15.0);
    Vecteur vitesse2(0.0, 0.0, 0.0);
    auto objet2 = make_unique<PointMateriel>(position2, vitesse2, champGravitation, contrainteLibre, 2.0);

    // Add objects to the system
    systeme.ajouter_objet(move(objet1));
    systeme.ajouter_objet(move(objet2));

    // Add constraints and force fields to the system
    systeme.ajouter_contrainte(contrainteLibre);
    systeme.ajouter_champ(champGravitation);
    cout << systeme << endl;
    //tesitng switching stuff
    auto contrainte_s = make_shared<Cont_spherique>(1.0);
    systeme.ajouter_contrainte(contrainte_s);
    systeme.donner_contrainte(0,1);
    cout << systeme << endl;
    // Simulate the system
    double dt = 1e-3;
    for (int i = 0; i < 1000; ++i) {
        systeme.evolue(dt);
        systeme.dessine_sur(viewer);
        if (i%100 == 0){
        cout << "temps = " << systeme.getTemps() << endl << *systeme.getObjets()[0] << endl;}
    }
    cout << "Simulation complete." << endl;

    return 0;
}*/

#include "Systeme.h"
#include "PointMateriel.h"
#include "ForceCentral.h"
#include "Contrainte.h"
#include "SupportTextDessin.h"
#include "Cont_spherique.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {

    Systeme systeme;
    
    Vecteur gravitation(0.0, 0.0, -9.81);
    auto champGravitation = make_shared<GravitationConstante>(gravitation);

    auto contrainte_s = make_shared<Cont_spherique>(2.2);
    Vecteur position1({M_PI / 6, 0});
    Vecteur vitesse1({0.0, 1});
    auto objet1 = make_unique<PointMateriel>(position1, vitesse1, champGravitation, contrainte_s, 0.1);

    systeme.ajouter_objet(move(objet1));

    cout << systeme << endl;

    double dt = 0.01;
    for (int i = 0; i < 10; ++i) {
        systeme.evolue(dt);
        cout << "temps = " << systeme.getTemps() << endl << *systeme.getObjets()[0] << endl;
    }
    cout << "Simulation complete." << endl;

    return 0;
}

