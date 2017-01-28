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

int Lobo::Comer(int columns, int rows, Celda*** terreno) {
    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila)) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows)){
                    if(terreno[ypos][xpos]->ocupante.compare(" OM")  == 0 || terreno[ypos][xpos]->ocupante.compare(" OH")  == 0) {
                        delete terreno[ypos][xpos]->animal;
                        terreno[ypos][xpos]->ocupante = "Vacío";
                        terreno[this->Fila][this->Columna]->animal->Energia += 10;
                        if(terreno[this->Fila][this->Columna]->animal->Energia > 100)
                            terreno[this->Fila][this->Columna]->animal->Energia = 100;
                        return 0;
                    }else if(terreno[ypos][xpos]->ocupante.compare(" ZM")  == 0 || terreno[ypos][xpos]->ocupante.compare(" ZH")  == 0) {
                        delete terreno[ypos][xpos]->animal;
                        terreno[ypos][xpos]->ocupante = "Vacío";
                        terreno[this->Fila][this->Columna]->animal->Energia += 5;
                        if(terreno[this->Fila][this->Columna]->animal->Energia > 100)
                            terreno[this->Fila][this->Columna]->animal->Energia = 100;
                        return 0;
                    }else if(terreno[ypos][xpos]->ocupante.compare(" RM")  == 0 || terreno[ypos][xpos]->ocupante.compare(" RH")  == 0) {
                        delete terreno[ypos][xpos]->animal;
                        terreno[ypos][xpos]->ocupante = "Vacío";
                        terreno[this->Fila][this->Columna]->animal->Energia += 2;
                        if(terreno[this->Fila][this->Columna]->animal->Energia > 100)
                            terreno[this->Fila][this->Columna]->animal->Energia = 100;
                        return 0;
                    }else if(terreno[ypos][xpos]->ocupante.compare(" LM") == 0 && terreno[this->Fila][this->Columna]->ocupante.compare(" LM") == 0){
                        if((rand() % 10) < 5){
                            delete terreno[ypos][xpos]->animal;
                            terreno[ypos][xpos]->ocupante = "Vacío";
                            return 0;
                        }else{
                            delete terreno[this->Fila][this->Columna]->animal;
                            terreno[this->Columna][this->Fila]->ocupante = "Vacío";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

/*void Lobo::PrintLobo() {
    cout << "Especie: Lobo" << endl;
    this->Print();
}*/

