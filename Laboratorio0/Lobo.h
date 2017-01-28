#ifndef LOBO_H
#define LOBO_H
#include "Animal.h"

class Lobo : public Animal {

//Metodos
public:
    Lobo();
    Lobo(int Fila, int Columna, int Sexo);
    virtual ~Lobo();

    void Mover();
    int Comer(int columns, int rows, Celda*** terreno);
    //void PrintLobo();
};

#endif // LOBO_H
