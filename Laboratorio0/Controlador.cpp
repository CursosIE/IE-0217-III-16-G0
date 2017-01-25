#include "Controlador.h"

Controlador::Controlador() {

}

Controlador::~Controlador() {

}

int Controlador::run() {
    cout << "Bienvenido al  Juego de la Vida! \nMay the odds be in  your favor..!" << endl;

    //Celda terreno = new Ce

    Lobo* L1 = new Lobo(12, 13, 1);
    L1->PrintLobo();
    cout << endl;

    Oveja* O1 = new Oveja(9, 1, 2);
    O1->PrintOveja();
    cout << endl;

    Raton* R1 = new Raton(5, 2, 2);
    R1->PrintRaton();
    cout << endl;

    Zorro* Z1 = new Zorro(4, 6, 1);
    Z1->PrintZorro();
    cout << endl;

    Z1->Energia = 0;
    Z1->Morir();

    Z1->PrintZorro();


    return 0;
}
