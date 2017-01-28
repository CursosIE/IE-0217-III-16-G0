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

int Raton::Mover(int columns, int rows, Celda*** terreno) {
    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila)) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows))
                    if(terreno[ypos][xpos]->ocupante.compare("Vacío") == 0){
                        terreno[ypos][xpos]->animal = new Raton(ypos, xpos, terreno[this->Fila][this->Columna]->animal->Sexo);
                        terreno[ypos][xpos]->ocupante = terreno[this->Fila][this->Columna]->ocupante;
                        delete terreno[this->Fila][this->Columna]->animal;
                        terreno[this->Fila][this->Columna]->ocupante = "Vacío";
                        return 0;
                    }

            }
        }
    }
    return 0;
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
