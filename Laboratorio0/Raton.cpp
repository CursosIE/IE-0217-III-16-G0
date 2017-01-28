#include "Raton.h"
#include "Celda.h"

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

int Raton::Comer(int columns, int rows, Celda*** terreno) {
    if(terreno[this->Fila][this->Columna]->zacate >= 5){
        terreno[this->Fila][this->Columna]->zacate -= 5;
        terreno[this->Fila][this->Columna]->animal->Energia += 5;
        if(terreno[this->Fila][this->Columna]->animal->Energia > 25)
            terreno[this->Fila][this->Columna]->animal->Energia = 25;
    }else{
        terreno[this->Fila][this->Columna]->animal->Energia += terreno[this->Fila][this->Columna]->zacate;
        terreno[this->Fila][this->Columna]->zacate = 0;
        if(terreno[this->Fila][this->Columna]->animal->Energia > 25)
            terreno[this->Fila][this->Columna]->animal->Energia = 25;
    }

    return 0;
}

/*void Raton::PrintRaton() {
    cout << "Especie: Raton" << endl;
    this->Print();
}*/
