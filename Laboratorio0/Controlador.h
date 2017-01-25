#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>

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

#endif // CONTROLADOR_H
