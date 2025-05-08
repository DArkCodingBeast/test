.RECIPEPREFIX = >
CC = $(CXX)
CXXFLAGS = -std=c++14 -pedantic -Wall


#fichier a executable lors du /make:
all: testVecteur testChutePommes testSysteme # test2astres	


# compilation des executable/cibles:
testVecteur: testVecteur.o Vecteur.o
>$(CC) $(CXXFLAGS) testVecteur.o Vecteur.o -o testVecteur

testChutePommes: testChutePommes.o Vecteur.o PointMateriel.o ForceCentral.o Contrainte.o Integrateur.o ObjetPhysique.o ObjetMobile.o ChampForces.o Systeme.o
>$(CC) $(CXXFLAGS) testChutePommes.o Vecteur.o PointMateriel.o ForceCentral.o Contrainte.o Integrateur.o ObjetPhysique.o ObjetMobile.o ChampForces.o Systeme.o -o testChutePommes

testSysteme: testSysteme.o Systeme.o PointMateriel.o ForceCentral.o Contrainte.o Integrateur.o ObjetPhysique.o ObjetMobile.o ChampForces.o SupportTextDessin.o Vecteur.o
>$(CC) $(CXXFLAGS) testSysteme.o Systeme.o PointMateriel.o ForceCentral.o Contrainte.o Integrateur.o ObjetPhysique.o ObjetMobile.o ChampForces.o SupportTextDessin.o Vecteur.o -o testSysteme

# test2astres: test2astres.o Vecteur.o PointMateriel.o ForceCentral.o Contrainte.o Integrateur.o ObjetPhysique.o ObjetMobile.o ChampForces.o
# >$(CC) $(CXXFLAGS) test2astres.o Vecteur.o PointMateriel.o ForceCentral.o Contrainte.o Integrateur.o ObjetPhysique.o ObjetMobile.o ChampForces.o -o test2astres

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

Systeme.o: Systeme.cc Systeme.h
>$(CC) $(CXXFLAGS) -c Systeme.cc -o Systeme.o

Dessinable.o: Dessinable.cc Dessinable.h
>$(CC) $(CXXFLAGS) -c Dessinable.cc -o Dessinable.o

Cont_spherique.o: Cont_spherique.cc Cont_spherique.h
>$(CC) $(CXXFLAGS) -c Cont_spherique.cc -o Cont_spherique.o

SupportTextDessin.o: SupportTextDessin.cc SupportTextDessin.h
>$(CC) $(CXXFLAGS) -c SupportTextDessin.cc -o SupportTextDessin.o

clean:
>rm -f *.o testChutePommes testVecteur testSysteme




