#ifndef ZORRO_H
#define ZORRO_H

#include "Animal.h"
#include "Celda.h"
#include "Controlador.h"


class Zorro : public Animal {

//Metodos
public:
    Zorro();
    Zorro(int Fila, int Columna, int Sexo);
    virtual ~Zorro();

    int operator!(); //metodo mover
    int operator++(); //funcion de comer
    void operator~(); //metodo reproducir
    //void PrintZorro();
};

#endif // ZORRO_H
