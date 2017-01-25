#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <fstream>
#include <iostream>

#include "Celda.h"

using namespace std;

class Controlador {

public:
    Controlador();
    virtual ~Controlador();
    int run();
};

#endif // CONTROLADOR_H
