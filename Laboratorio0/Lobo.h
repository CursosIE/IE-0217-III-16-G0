#ifndef LOBO_H
#define LOBO_H

#include <cstdlib>

#include "Animal.h"
#include "Celda.h"
#include "Controlador.h"

class Lobo : public Animal {

//Metodos
public:
    Lobo();
    Lobo(int Fila, int Columna, int Sexo);
    virtual ~Lobo();

    int operator!(); //metodo mover
    int operator++(); //metodo de comer
    void operator~(); //metodo reproducir
    //void PrintLobo();
};

#endif // LOBO_H
