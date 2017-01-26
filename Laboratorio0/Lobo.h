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
    void Comer();
    //void PrintLobo();
};

#endif // LOBO_H
