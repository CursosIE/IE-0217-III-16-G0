#include "Lobo.h"
#include "Celda.h"

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

int Lobo::Comer(Celda &otra, Celda*** terreno) {
    if(otra.ocupante.compare(" OM")  == 0 || otra.ocupante.compare(" OH")  == 0) {
        delete otra.animal;
        return 10;
    }else if(otra.ocupante.compare(" ZM")  == 0 || otra.ocupante.compare(" ZH")  == 0) {
        delete otra.animal;
        return 5;
    }else if(otra.ocupante.compare(" RM")  == 0 || otra.ocupante.compare(" RH")  == 0) {
        delete otra.animal;
        return 2;
    }else
        return 0;
}

/*void Lobo::PrintLobo() {
    cout << "Especie: Lobo" << endl;
    this->Print();
}*/

