#ifndef ZAPDOS_H
#define ZAPDOS_H

#include "Flying.h"
#include "Electric.h"

using namespace std;

//no dice que esta clase hereda de Electric y de Flying
class Zapdos : public Electric, public Flying {
public:
    string type;
    string strongVs;
    string weakVs;

public:
    Zapdos();
    Zapdos(string nombre);
    virtual ~Zapdos();

    void atk1 (Pokemon &other);
    void atk2 (Pokemon &other);
    void atk3 ();
    void atk4 (Pokemon &other);
    void print();

};

#endif // ZAPDOS_H
