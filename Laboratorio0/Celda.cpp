#include "Celda.h"

Celda::Celda() {

}

Celda::Celda(int cantidadZacate, int tipoOcupante) {
    zacate = cantidadZacate;
    ocupante = tipoOcupante;
}

Celda::~Celda() {

}

void Celda::print() {
    cout << "Nivel zacate: " << zacate << endl;
    switch(ocupante) {
        case 0: cout << "Ocupante: vacío" << endl; break;
        case 11: cout << "Ocupante: Lobo" << endl; break;
        case 12: cout << "Ocupante: Loba" << endl; break;
        case 21: cout << "Ocupante: Oveja macho" << endl; break;
        case 22: cout << "Ocupante: Oveja hembra" << endl; break;
        case 31: cout << "Ocupante: Zorro" << endl; break;
        case 32: cout << "Ocupante: Zorra" << endl; break;
        case 41: cout << "Ocupante: Ratón macho" << endl; break;
        case 42: cout << "Ocupante: Ratón hembra" << endl; break;
    }
}
