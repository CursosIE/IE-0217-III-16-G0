#ifndef LOBO_H
#define LOBO_H
#include "Animal.h"

class Lobo : public Animal {

//Metodos
public:
    Lobo();
    virtual ~Lobo();

    void Mover();
    void Comer();
};

#endif // LOBO_H
