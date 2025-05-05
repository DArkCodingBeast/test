.RECIPEPREFIX = >
CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall


#fichier a executable lors du /make:
all: testVecteur testChutePommes	


# compilation des executable/cibles:
testVecteur: testVecteur.o Vecteur.o
>$(CC) $(CXXFLAGS) testVecteur.o Vecteur.o -o testVecteur

testintegrateur: ChutePommes.o Vecteur.o PointMateriel.o ForceCentral.o Contrainte.o Integrateur.o ObjetPhysique.o ObjetMobile.o
>$(CC) $(CXXFLAGS) ChutePommes.o Vecteur.o PointMateriel.o ForceCentral.o Contrainte.o Integrateur.o -o testChutePommes




# Compilation de tout les fichier:
Vecteur.o: Vecteur.cc Vecteur.h
>$(CC) $(CXXFLAGS) -c Vecteur.cc -o Vecteur.o

PointMateriel.o: PointMateriel.cc PointMateriel.h
>$(CC) $(CXXFLAGS) -c PointMateriel.cc -o PointMateriel.o

ObjetPhysique.o: ObjetPhysique.cc ObjetPhysique.h
>$(CC) $(CXXFLAGS) -c ObjetPhysique.cc -o ObjetPhysique.o

ObjetMobile.o: ObjetMobile.cc ObjetMobile.h
>$(CC) $(CXXFLAGS) -c ObjetMobile.cc -o ObjetMobile.o

ChampForces.o: ChampForces.cc ChampForces.h
>$(CC) $(CXXFLAGS) -c ChampForces.cc -o ChampForces.o	

ForceCentral.o: ForceCentral.cc ForceCentral.h
>$(CC) $(CXXFLAGS) -c ForceCentral.cc -o ForceCentral.o

Contrainte.o: Contrainte.cc Contrainte.h
>$(CC) $(CXXFLAGS) -c Contrainte.cc -o Contrainte.o

Integrateur.o: Integrateur.cc Integrateur.h
>$(CC) $(CXXFLAGS) -c Integrateur.cc -o Integrateur.o

testVecteur.o: testVecteur.cc Vecteur.h
>$(CC) $(CXXFLAGS) -c testVecteur.cc -o testVecteur.o

testChutePommes: testChutePommes.o Vecteur.o PointMateriel.o ForceCentral.o Contrainte.o Integrateur.o ObjetPhysique.o ObjetMobile.o ChampForces.o
>$(CC) $(CXXFLAGS) testChutePommes.o Vecteur.o PointMateriel.o ForceCentral.o Contrainte.o Integrateur.o ObjetPhysique.o ObjetMobile.o ChampForces.o -o testChutePommes



clean:
>rm -f *.o testChutePommes testVecteur




