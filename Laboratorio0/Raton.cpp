#include "Raton.h"

Raton::Raton() {

}

Raton::Raton(int Fila, int Columna, int Sexo) {
    this->Fila = Fila;
    this->Columna = Columna;
    this->Sexo = Sexo;
    Energia = 25;
    tipoAnimal = "Ratón";
}

Raton::~Raton() {

}

void Raton::Mover() {

}

void Raton::Comer() {

}

/*void Raton::PrintRaton() {
    cout << "Especie: Raton" << endl;
    this->Print();
}*/
