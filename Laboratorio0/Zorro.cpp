#include "Zorro.h"

Zorro::Zorro() {

}

Zorro::Zorro(int Fila, int Columna, int Sexo) {
    this->Fila = Fila;
    this->Columna = Columna;
    this->Sexo = Sexo;
    Energia = 50;
}

Zorro::~Zorro() {

}

void Zorro::Mover() {

}

void Zorro::Comer() {

}

void Zorro::PrintZorro() {
    cout << "Especie: Zorro" << endl;
    this->Print();
}


