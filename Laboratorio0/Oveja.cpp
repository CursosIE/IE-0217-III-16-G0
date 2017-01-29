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

int Oveja::Mover(int columns, int rows, Celda*** terreno) {
    int xActual = this->Columna;
    int yActual = this->Fila;
    int yPrevio, xPrevio;
    int contador = 0;

    for (int xpos = xActual-1; xpos <= xActual+1; ++xpos) {
        for (int ypos = yActual-1; ypos <= yActual+1; ++ypos) {
            if (!(xpos == xActual && ypos == yActual)) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows))
                    if((terreno[ypos][xpos]->ocupante.compare("Vacío") == 0) && ypos != yPrevio && xpos != xPrevio){
                        terreno[ypos][xpos]->animal = new Zorro(ypos, xpos, terreno[yActual][xActual]->animal->Sexo);
                        terreno[ypos][xpos]->ocupante = terreno[yActual][xActual]->ocupante;
                        delete terreno[yActual][xActual]->animal;
                        terreno[yActual][xActual]->ocupante = "Vacío";
                        yPrevio = yActual;
                        xPrevio = xActual;
                        yActual = ypos;
                        xActual = xpos;
                        contador += 1;
                        if(contador == 2)
                            return 0;
                    }
            }
        }
    }
    return 0;
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

void Oveja::Reproducir(int columns, int rows, Celda ***terreno) {
    bool reproduzcase = false;

    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila)) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows)) {
                    if (terreno[ypos][xpos]->ocupante.compare("Vacío") != 0) {
                        if (terreno[ypos][xpos]->animal->tipoAnimal.compare(this->tipoAnimal) == 0) {
                            if (terreno[ypos][xpos]->animal->Sexo != this->Sexo) {
                                reproduzcase = true;
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
                        if(reproduzcase){
                            terreno[ypos1][xpos1]->animal = new Oveja(ypos1, xpos1, terreno[this->Fila][this->Columna]->animal->Sexo);
                            terreno[ypos1][xpos1]->ocupante = terreno[this->Fila][this->Columna]->ocupante;
                            reproduzcase = false;
                        }
                    }
                }
            }
        }
    }
}

/*void Oveja::PrintOveja() {
    cout << "Especie: Oveja" << endl;
    this->Print();
}*/
