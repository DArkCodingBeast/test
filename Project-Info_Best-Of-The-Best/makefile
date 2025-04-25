.RECIPEPREFIX = >
CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall

all: testVecteur

testVecteur: testVecteur.o Vecteur.o
>$(CC) $(CXXFLAGS) testVecteur.o Vecteur.o -o testVecteur
testVecteur.o: testVecteur.cc Vecteur.h
>$(CC) $(CXXFLAGS) -c testVecteur.cc -o testVecteur.o
Vecteur.o: Vecteur.cc Vecteur.h
>$(CC) $(CXXFLAGS) -c Vecteur.cc -o Vecteur.o


clean:
>del /Q *.o testVecteur.exe




