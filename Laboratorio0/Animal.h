#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

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
    Animal(int Fila, int Columna, int Sexo);
    virtual ~Animal();

    virtual void Mover() = 0;
    virtual void Comer() = 0;
    void Reproducir();
    bool Morir();
    void Print();
};

#endif // ANIMAL_H
