#ifndef RATON_H
#define RATON_H
#include "Animal.h"

class Raton : public Animal {

//Metodos
public:
    Raton();
    virtual ~Raton();

    void Mover();
    void Comer();
};

#endif // RATON_H
