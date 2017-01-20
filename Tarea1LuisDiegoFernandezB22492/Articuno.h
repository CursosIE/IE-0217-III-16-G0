#ifndef ARTICUNO_H
#define ARTICUNO_H

#include "Flying.h"
#include "Ice.h"

using namespace std;

//no dice que esta clase hereda de Ice y de Flying
class Articuno : public Ice, public Flying {
public:
    string type;
    string strongVs;
    string weakVs;

public:
    Articuno ();
    Articuno(string nombre);
    virtual ~Articuno();

    void atk1 (Pokemon &other);
    void atk2 (Pokemon &other);
    void atk3 ();
    void atk4 (Pokemon &other);
    void print();

};

#endif // ARTICUNO_H
