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

int Zorro::Mover(int columns, int rows, Celda*** terreno) {
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

int Zorro::Comer(int columns, int rows, Celda*** terreno) {
    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila)) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows)){
                    if(terreno[ypos][xpos]->ocupante.compare(" RM")  == 0 || terreno[ypos][xpos]->ocupante.compare(" RH")  == 0) {
                        delete terreno[ypos][xpos]->animal;
                        terreno[ypos][xpos]->ocupante = "Vacío";
                        terreno[this->Fila][this->Columna]->animal->Energia += 2;
                        if(terreno[this->Fila][this->Columna]->animal->Energia > 50)
                            terreno[this->Fila][this->Columna]->animal->Energia = 50;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}

/*void Zorro::PrintZorro() {
    cout << "Especie: Zorro" << endl;
    this->Print();
}*/


