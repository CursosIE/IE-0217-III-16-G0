#ifndef CELDA_H
#define CELDA_H

#include <iostream>

using namespace std;

class Celda {
public:
    string ocupante; // el tipo de animal
    int zacate; // el zacate equivale a energia para ovejas y ratones

public:
    Celda();
    Celda(int cantidadZacate, string tipoOcupante);
    virtual ~Celda();

    void print();
};

#endif // CELDA_H
