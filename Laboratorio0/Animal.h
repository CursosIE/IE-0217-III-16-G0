#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class Celda;

class Animal {

//Atributos
public:
    ///Bandera para saber si a un animal ya se le aplicaron todos los metodos.
    bool allFunctions;
    ///Bandera para saber si un animal ya se movio en un dia.
    bool alreadyMoved;
    ///Bandera para saber si un animal ya se repdodujo en un dia.
    bool alreadyReproduced;
    ///Energia del aimal.
    int Energia;
    ///Posicion del animal.
    int Fila, Columna;
    ///Sexo del animal.
    int Sexo;
    ///Se define en las clases hijo, dependiendo de que tipo de animal que sea.
    string tipoAnimal;

//Metodos
public:
    Animal();
    virtual ~Animal();

    virtual int operator!() = 0; //metodo mover
    virtual int operator++() = 0; //metodo de comer
    virtual void operator~() = 0; //metodo de reproducir
    bool operator--(); // metodo de morir
    void Print();

};

#endif // ANIMAL_H
