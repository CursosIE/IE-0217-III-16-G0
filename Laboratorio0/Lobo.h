#ifndef LOBO_H
#define LOBO_H
#include "Animal.h"

class Lobo : public Animal {

//Metodos
public:
    Lobo();
    Lobo(int Fila, int Columna, int Sexo);
    virtual ~Lobo();

    int Mover(int columns, int rows, Celda*** terreno);
    int Comer(int columns, int rows, Celda*** terreno);
    void Reproducir(int columns, int rows, Celda*** terreno);
    //void PrintLobo();
};

#endif // LOBO_H
