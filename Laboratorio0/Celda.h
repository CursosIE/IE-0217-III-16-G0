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
public:
    Animal* animal;
    int columna;
    int fila;
    string ocupante; // el tipo de animal
    int zacate; // el zacate equivale a energia para ovejas y ratones

public:
    Celda();
    Celda(int cantidadZacate, string tipoOcupante, int columna, int fila);
    virtual ~Celda();

    void print();
};

#endif // CELDA_H
