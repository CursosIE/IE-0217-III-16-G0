#include "Zorro.h"
#include "Celda.h"

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

int Zorro::Comer(Celda &otra, Celda*** terreno) {
    if(otra.ocupante.compare(" RM")  == 0 || otra.ocupante.compare(" RH")  == 0) {
        delete otra.animal;
        return 2;
    }else
        return 0;
}

/*void Zorro::PrintZorro() {
    cout << "Especie: Zorro" << endl;
    this->Print();
}*/


