#ifndef FIRE_H
#define FIRE_H

#include "Pokemon.h"

using namespace std;

//virtual public Pokemon nos dice que hereda de pokemon
class Fire : virtual public Pokemon {
public:
    Fire();
    virtual ~Fire();

    static string type();
    static string strongVs();
    static string weakVs();
};

#endif // FIRE_H
