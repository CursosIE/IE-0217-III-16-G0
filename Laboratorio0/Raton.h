#ifndef RATON_H
#define RATON_H

#include "Animal.h"
#include "Celda.h"
#include "Controlador.h"

class Raton : public Animal {

//Metodos
public:
    Raton();
    Raton(int Fila, int Columna, int Sexo);
    virtual ~Raton();

    int operator!(); //metodo mover
    int operator++(); //funcion de comer
    void operator~(); //metodo reproducir
    //void PrintRaton();
};

#endif // RATON_H
