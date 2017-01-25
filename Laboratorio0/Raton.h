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
    void Comer();
    void PrintRaton();
};

#endif // RATON_H
