#ifndef ZORRO_H
#define ZORRO_H
#include "Animal.h"

class Zorro : public Animal {

//Metodos
public:
    Zorro();
    Zorro(int Fila, int Columna, int Sexo);
    virtual ~Zorro();

    void Mover();
    int Comer(int columns, int rows, Celda*** terreno);
    //void PrintZorro();
};

#endif // ZORRO_H
