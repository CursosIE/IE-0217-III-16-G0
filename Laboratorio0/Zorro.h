#ifndef ZORRO_H
#define ZORRO_H
#include "Animal.h"

class Zorro : public Animal {

//Metodos
public:
    Zorro();
    virtual ~Zorro();

    void Mover();
    void Comer();
};

#endif // ZORRO_H
