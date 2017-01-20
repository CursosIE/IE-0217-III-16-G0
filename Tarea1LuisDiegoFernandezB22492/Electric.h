#ifndef ELECTRIC_H
#define ELECTRIC_H

#include "Pokemon.h"

using namespace std;

//virtual public Pokemon nos dice que hereda de pokemon
class Electric : virtual public Pokemon  {
public:
    Electric();
    virtual ~Electric();

    static string type();
    static string strongVs();
    static string weakVs();
};

#endif // ELECTRIC_H
