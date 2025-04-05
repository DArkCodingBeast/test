#include "PointMateriel.h"

int main(){

    PointMateriel steve({0,0,1}, {0, 1, 2}, 0.127, {0, 0, -9.81});
    IntegrateurEulerCromer cummer(0.1);

    return 0;
}