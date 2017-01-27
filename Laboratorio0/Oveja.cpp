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

int Oveja::Comer(Celda &otra, Celda*** terreno) {
    if(otra.zacate >= 10){
        otra.zacate -= 10;
        Energia += 10;
        if(Energia > 75)
            Energia = 75;
    }else{
        Energia += otra.zacate;
        otra.zacate = 0;
        if(Energia > 75)
            Energia = 75;
    }

    return 0;
}

/*void Oveja::PrintOveja() {
    cout << "Especie: Oveja" << endl;
    this->Print();
}*/
