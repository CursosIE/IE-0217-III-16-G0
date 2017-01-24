#ifndef OVEJA_H
#define OVEJA_H
#include "Animal.h"

class Oveja : public Animal {

//Metodos
public:
    Oveja();
    virtual ~Oveja();

    void Mover();
    void Comer();
};

#endif // OVEJA_H
