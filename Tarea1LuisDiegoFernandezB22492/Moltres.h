#ifndef MOLTRES_H
#define MOLTRES_H

#include "Fire.h"
#include "Flying.h"

using namespace std;

//no dice que esta clase hereda de Fire y de Flying
class Moltres : public Fire, public Flying {
public:
    string type;
    string strongVs;
    string weakVs;

public:
    Moltres();
    Moltres(string nombre);
    virtual ~Moltres();

    void atk1 (Pokemon &other);
    void atk2 (Pokemon &other);
    void atk3 ();
    void atk4 (Pokemon &other);
    void print();

};

#endif // MOLTRES_H
