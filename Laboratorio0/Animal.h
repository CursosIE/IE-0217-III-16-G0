#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class Celda;

class Animal {

//Atricbutos
public:
    int Sexo; //Sexo del animal.
    int Energia; //Energia del aimal.
    int Fila, Columna; //Posicion del animal.
    string tipoAnimal; //se define en las clases hijo, dependiendo de que tipo de animal sea

//Funciones
public:
    Animal();
    virtual ~Animal();

    virtual int Mover(int columns, int rows, Celda*** terreno) = 0;
    virtual int Comer(int columns, int rows, Celda*** terreno) = 0;
    virtual void Reproducir(int columns, int rows, Celda*** terreno) = 0;
    bool Morir();
    void Print();
};

#endif // ANIMAL_H
