#ifndef OVEJA_H
#define OVEJA_H
#include "Animal.h"

class Oveja : public Animal {

//Metodos
public:
    Oveja();
    Oveja(int Fila, int Columna, int Sexo);
    virtual ~Oveja();

    void Mover();
    void Comer();
    //void PrintOveja();
};

#endif // OVEJA_H
