#ifndef ICE_H
#define ICE_H

#include "Pokemon.h"

using namespace std;

//virtual public Pokemon nos dice que hereda de pokemon
class Ice : virtual public Pokemon {
public:
    Ice();
    virtual ~Ice();

    static string type();
    static string strongVs();
    static string weakVs();
};

#endif // ICE_H
