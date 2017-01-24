#ifndef CELDA_H
#define CELDA_H

#include <iostream>

using namespace std;

class Celda {
public:
    int ocupante; // dependiendo del numero entero que tenga va a ser cierto animal, 0 es vacio
    int zacate; // el zacate equivale a energia para ovejas y ratones

public:
    Celda();
    Celda(int cantidadZacate, int tipoOcupante);
    virtual ~Celda();

    void print();
};

#endif // CELDA_H
