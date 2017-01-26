#include "Celda.h"

Celda::Celda() {

}

Celda::Celda(int cantidadZacate, string tipoOcupante, int fila, int columna) {
    zacate = cantidadZacate;
    ocupante = tipoOcupante;
    this->fila = fila;
    this->columna = columna;
    if(ocupante.compare("LM"))
        animal = new Lobo(fila, columna, 1);
    if(ocupante.compare("LH"))
        animal = new Lobo(fila, columna, 2);
    if(ocupante.compare("OM"))
        animal = new Oveja(fila, columna, 1);
    if(ocupante.compare("OH"))
        animal = new Oveja(fila, columna, 2);
    if(ocupante.compare("ZM"))
        animal = new Lobo(fila, columna, 1);
    if(ocupante.compare("ZH"))
        animal = new Lobo(fila, columna, 2);
    if(ocupante.compare("RM"))
        animal = new Lobo(fila, columna, 1);
    if(ocupante.compare("RH"))
        animal = new Lobo(fila, columna, 2);
}

Celda::~Celda() {

}

void Celda::print() {
    cout << "Posición: [" << fila << ", " << columna << "]" << endl;
    cout << "Nivel zacate: " << zacate << endl;
    cout << "Ocupante: " << ocupante << endl;
    if (ocupante != "Vacío")
        animal->Print();
    cout << endl;
}
