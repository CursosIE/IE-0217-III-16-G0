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

    int Mover(int columns, int rows, Celda*** terreno);
    int Comer(int columns, int rows, Celda*** terreno);
    void operator~(); //metodo reproducir
    //void PrintRaton();
};

#endif // RATON_H
