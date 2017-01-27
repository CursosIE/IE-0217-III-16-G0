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

int Raton::Comer(Celda &otra, Celda*** terreno) {
    if(otra.zacate >= 5){
        otra.zacate -= 5;
        Energia += 5;
        if(Energia > 25)
            Energia = 25;
    }else{
        Energia += otra.zacate;
        otra.zacate = 0;
        if(Energia > 25)
            Energia = 25;
    }

    return 0;
}

/*void Raton::PrintRaton() {
    cout << "Especie: Raton" << endl;
    this->Print();
}*/
