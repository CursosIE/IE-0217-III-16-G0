#include <iostream>

#include "Articuno.h"
#include "Electric.h"
#include "Fire.h"
#include "Flying.h"
#include "Ice.h"
#include "Moltres.h"
#include "Pokemon.h"
#include "Zapdos.h"

using namespace std;

int main()
{
    //se crean 3 objetos que heredan de pokemon, pero no son iguales
    Zapdos* p1 = new Zapdos("Piolín");
    Articuno* p2 = new Articuno("Pingüino");
    Moltres* p3 = new Moltres("Yigüirro");

    //se imprime cada objeto para ver sus atributos
    cout << "Estado de los 3 pokemones creados\n" << endl;
    p3->print();
    p2->print();
    p1->print();

    //se procede a utilizar las funciones de los ataques de cada pakemon
    //despues de cada ataque se muestra el estado de los pokemones afectados
    cout << "Fase de ataques\n" << endl;
    p2->atk1(*p1);
    p1->print();

    p2->atk3();
    p2->print();

    p3->atk4(*p2);
    p2->print();
    p3->print();

    //se procede a liberar la memoria del Heap section utilizada al hacer los new
    delete p1;
    delete p2;
    delete p3;

    return 0;
}
