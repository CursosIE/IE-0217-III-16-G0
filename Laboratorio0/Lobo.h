#ifndef LOBO_H
#define LOBO_H

#include <cstdlib>

#include "Animal.h"
#include "Celda.h"
#include "Controlador.h"

class Lobo : public Animal {

//Metodos
public:
    Lobo();
    Lobo(int Fila, int Columna, int Sexo);
    virtual ~Lobo();

    int Mover(int columns, int rows, Celda*** terreno);
    int Comer(int columns, int rows, Celda*** terreno);
    void operator~(); //metodo reproducir
    //void PrintLobo();
};

#endif // LOBO_H
