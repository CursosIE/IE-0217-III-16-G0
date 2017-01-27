#include "Zorro.h"
//#include "Celda.h"

Zorro::Zorro() {

}

Zorro::Zorro(int Fila, int Columna, int Sexo) {
    this->Fila = Fila;
    this->Columna = Columna;
    this->Sexo = Sexo;
    Energia = 50;
    tipoAnimal = "Zorro";
}

Zorro::~Zorro() {

}

void Zorro::Mover() {

}

void Zorro::Comer(Celda &otra) {

}

/*void Zorro::PrintZorro() {
    cout << "Especie: Zorro" << endl;
    this->Print();
}*/


