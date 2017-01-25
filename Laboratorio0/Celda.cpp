#include "Celda.h"

Celda::Celda() {

}

Celda::Celda(int cantidadZacate, string tipoOcupante) {
    zacate = cantidadZacate;
    ocupante = tipoOcupante;
}

Celda::~Celda() {

}

void Celda::print() {
    cout << "Nivel zacate: " << zacate << endl;
    cout << "Ocupante: " << ocupante << endl;

}
