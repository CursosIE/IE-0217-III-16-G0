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

    int Mover(int columns, int rows, Celda*** terreno);
    int Comer(int columns, int rows, Celda*** terreno);
    void operator~(); //metodo reproducir
    //void PrintOveja();
};

#endif // OVEJA_H
