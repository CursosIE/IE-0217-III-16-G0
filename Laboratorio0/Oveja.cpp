#include "Oveja.h"
#include "Celda.h"

Oveja::Oveja() {

}

Oveja::Oveja(int Fila, int Columna, int Sexo) {
    this->Fila = Fila;
    this->Columna = Columna;
    this->Sexo = Sexo;
    Energia = 75;
    tipoAnimal = "Oveja";
}

Oveja::~Oveja() {

}

void Oveja::Mover() {

}

int Oveja::Comer(int columns, int rows, Celda*** terreno) {
    if(terreno[this->Fila][this->Columna]->zacate >= 10){
        terreno[this->Fila][this->Columna]->zacate -= 10;
        terreno[this->Fila][this->Columna]->animal->Energia += 10;
        if(terreno[this->Fila][this->Columna]->animal->Energia > 75)
            terreno[this->Fila][this->Columna]->animal->Energia = 75;
    }else{
        terreno[this->Fila][this->Columna]->animal->Energia += terreno[this->Fila][this->Columna]->zacate;
        terreno[this->Fila][this->Columna]->zacate = 0;
        if(terreno[this->Fila][this->Columna]->animal->Energia > 75)
            terreno[this->Fila][this->Columna]->animal->Energia = 75;
    }

    return 0;
}

/*void Oveja::PrintOveja() {
    cout << "Especie: Oveja" << endl;
    this->Print();
}*/
