#ifndef FLYING_H
#define FLYING_H

#include "Pokemon.h"

using namespace std;

//virtual public Pokemon nos dice que hereda de pokemon
class Flying : virtual public Pokemon {
public:
    Flying();
    virtual ~Flying();

    static string type ();
    static string strongVs();
    static string weakVs();
};

#endif // FLYING_H
