#ifndef CELDA_H
#define CELDA_H

#include <iostream>

#include "Lobo.h"
#include "Oveja.h"
#include "Zorro.h"
#include "Raton.h"

using namespace std;

class Animal;

class Celda {

//Atributos
public:
    ///Animal que se encuetra en la celda.
    Animal* animal;
    ///Posicion de la celda.
    int columna, fila;
    ///Tipo de animal que ocupa la celda.
    string ocupante;
    ///Cantidad de zacate presente en la celda.
    int zacate;

//Metodos
public:
    Celda();
    Celda(int cantidadZacate, string tipoOcupante, int columna, int fila);
    virtual ~Celda();

    void print();
};

#endif // CELDA_H
