#include "Lobo.h"
//#include "Celda.h"

Lobo::Lobo() {

}

Lobo::Lobo(int Fila, int Columna, int Sexo) {
    this->Fila = Fila;
    this->Columna = Columna;
    this->Sexo = Sexo;
    Energia = 100;
    tipoAnimal = "Lobo";
}

Lobo::~Lobo() {

}

void Lobo::Mover() {

}

void Lobo::Comer(Celda &otra) {

}

/*void Lobo::PrintLobo() {
    cout << "Especie: Lobo" << endl;
    this->Print();
}*/

