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

int Lobo::Mover(int columns, int rows, Celda*** terreno) {
    int xActual = this->Columna;
    int yActual = this->Fila;
    int yPrevio, xPrevio;
    int contador = 0;

    for (int xpos = xActual-1; xpos <= xActual+1; ++xpos) {
        for (int ypos = yActual-1; ypos <= yActual+1; ++ypos) {
            if (!(xpos == xActual && ypos == yActual)) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows))
                    if((terreno[ypos][xpos]->ocupante.compare("Vacío") == 0) && ypos != yPrevio && xpos != xPrevio){
                        terreno[ypos][xpos]->print();
                        terreno[ypos][xpos]->animal = new Zorro(ypos, xpos, terreno[yActual][xActual]->animal->Sexo);
                        terreno[ypos][xpos]->ocupante = terreno[yActual][xActual]->ocupante;
                        delete terreno[yActual][xActual]->animal;
                        terreno[yActual][xActual]->ocupante = "Vacío";
                        yPrevio = yActual;
                        xPrevio = xActual;
                        yActual = ypos;
                        xActual = xpos;
                        contador += 1;
                        if(contador == 3){
                            return 0;}
                    }
            }
        }
    }
    return 0;
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

void Lobo::Reproducir(int columns, int rows, Celda ***terreno) {
    bool reproduzcase = false;

    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila) && !reproduzcase) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows)) {
                    if (terreno[ypos][xpos]->ocupante.compare("Vacío") != 0) {
                        if (terreno[ypos][xpos]->animal->tipoAnimal.compare(this->tipoAnimal) == 0) {
                            if (terreno[ypos][xpos]->animal->Sexo != this->Sexo && !terreno[ypos][xpos]->animal->alreadyReproduced) {
                                reproduzcase = true;
                                terreno[ypos][xpos]->animal->alreadyReproduced = true;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int xpos1 = this->Columna-1; xpos1 <= this->Columna+1; ++xpos1) {
        for (int ypos1 = this->Fila-1; ypos1 <= this->Fila+1; ++ypos1) {
            if (!(xpos1 == this->Columna && ypos1 == this->Fila)) { //no se mete en si mismo
                if ((xpos1 >=  0 && xpos1 < columns) && (ypos1 >=  0 && ypos1 < rows)) {
                    if (terreno[ypos1][xpos1]->ocupante.compare("Vacío") == 0) {
                        if(reproduzcase && !this->alreadyReproduced){
                            terreno[ypos1][xpos1]->animal = new Lobo(ypos1, xpos1, terreno[this->Fila][this->Columna]->animal->Sexo);
                            terreno[ypos1][xpos1]->ocupante = terreno[this->Fila][this->Columna]->ocupante;
                            reproduzcase = false;
                            terreno[this->Fila][this->Columna]->animal->alreadyReproduced = true;
                        }
                    }
                }
            }
        }
    }
}

/*void Lobo::PrintLobo() {
    cout << "Especie: Lobo" << endl;
    this->Print();
}*/

