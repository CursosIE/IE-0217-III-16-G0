#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <fstream>
#include <iostream>

#include "Animal.h"
#include "Celda.h"
#include "Lobo.h"
#include "Oveja.h"
#include "Raton.h"
#include "Zorro.h"

using namespace std;

class Controlador {
//atributos
public:
    static int columns;
    static int rows;
    static Celda*** terreno;

//Metodos
public:
    Controlador();
    virtual ~Controlador();
    void printTerreno(int columns, int rows, Celda*** terreno);
    void resetMarks(int columns, int rows, Celda*** terreno); //resetea el atributo alreadyReproduced al final de cada dia
    int run(int amountOfDays, char* fileName); //corre el juego
};

#endif // CONTROLADOR_H
