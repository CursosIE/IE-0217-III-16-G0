#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class Celda;

class Animal {

//Atributos
public:
    bool alreadyReproduced; //Bandera para saber si un animal ya se repdodujo en un dia
    int Energia; //Energia del aimal.
    int Fila, Columna; //Posicion del animal. Identificador
    int Sexo; //Sexo del animal.
    string tipoAnimal; //se define en las clases hijo, dependiendo de que tipo de animal sea

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
