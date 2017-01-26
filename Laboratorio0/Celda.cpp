#include "Celda.h"

Celda::Celda() {

}

Celda::Celda(int cantidadZacate, string tipoOcupante, int fila, int columna) {
    zacate = cantidadZacate;
    ocupante = tipoOcupante;
    if(ocupante == "LM")
        animal = new Lobo(fila, columna, 1);
    if(ocupante == "LH")
        animal = new Lobo(fila, columna, 2);
    if(ocupante == "OM")
        animal = new Oveja(fila, columna, 1);
    if(ocupante == "OH")
        animal = new Oveja(fila, columna, 2);
    if(ocupante == "ZM")
        animal = new Lobo(fila, columna, 1);
    if(ocupante == "ZH")
        animal = new Lobo(fila, columna, 2);
    if(ocupante == "RM")
        animal = new Lobo(fila, columna, 1);
    if(ocupante == "RH")
        animal = new Lobo(fila, columna, 2);
}

Celda::~Celda() {

}

void Celda::print() {
    cout << "Nivel zacate: " << zacate << endl;
    cout << "Ocupante: " << ocupante << endl;

}
