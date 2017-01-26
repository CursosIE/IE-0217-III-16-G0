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

public:
    Controlador();
    virtual ~Controlador();
    int run();
};

template <typename DataType>
void print (DataType objeto) {
    cout << &objeto << endl;
    cout << "Posicion: [" << objeto.fila << ", " << objeto.columna << "]" << endl;
    cout << "Animal: " << objeto.tipoAnimal << endl;
    if (objeto.sexo == 1)
        cout << "Sexo: macho" << endl;
    else
        cout << "Sexo: hembra" << endl;
    cout << "Energía: " << objeto.energia << endl;
}


#endif // CONTROLADOR_H
