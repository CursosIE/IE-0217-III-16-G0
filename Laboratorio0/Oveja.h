#ifndef OVEJA_H
#define OVEJA_H

#include "Animal.h"
#include "Celda.h"
#include "Controlador.h"

class Oveja : public Animal {

//Metodos
public:
    Oveja();
    Oveja(int Fila, int Columna, int Sexo);
    virtual ~Oveja();

    int operator!(); //metodo mover
    int operator++(); //funcion de comer
    void operator~(); //metodo reproducir
    //void PrintOveja();
};

#endif // OVEJA_H
