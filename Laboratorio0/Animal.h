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

    virtual int Mover(int columns, int rows, Celda*** terreno) = 0;
    virtual int Comer(int columns, int rows, Celda*** terreno) = 0;
    virtual void Reproducir(int columns, int rows, Celda*** terreno) = 0;
    bool Morir();
    inline bool operator--() {return Morir();} //sobrecarga del operador -- con Morir()
    void Print();

};

#endif // ANIMAL_H
