#ifndef RATON_H
#define RATON_H
#include "Animal.h"

class Raton : public Animal {

//Metodos
public:
    Raton();
    Raton(int Fila, int Columna, int Sexo);
    virtual ~Raton();

    void Mover();
    int Comer(Celda &otra, Celda*** terreno);
    //void PrintRaton();
};

#endif // RATON_H
