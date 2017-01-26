#ifndef CELDA_H
#define CELDA_H

#include <iostream>
#include "Animal.h"
#include "Lobo.h"
#include "Oveja.h"
#include "Zorro.h"
#include "Raton.h"

using namespace std;

class Celda {
public:
    string ocupante; // el tipo de animal
    int zacate; // el zacate equivale a energia para ovejas y ratones
    Animal* animal;

public:
    Celda();
    Celda(int cantidadZacate, string tipoOcupante, int fila, int columna);
    virtual ~Celda();

    void print();
};

#endif // CELDA_H
