#include "Animal.h"
#include "Celda.h"

Animal::Animal() {

}

Animal::~Animal(){

}

void Animal::Reproducir(int columns, int rows, Celda*** terreno) {
    //cout << "This columna: " << this->Columna << endl;
    //cout << "This fila: " << this->Fila << endl;
    bool reproduzcase = false;

    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila)) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows)) {
                    if (terreno[ypos][xpos]->ocupante.compare("Vacío") != 0) {
                        if (terreno[ypos][xpos]->animal->tipoAnimal.compare(this->tipoAnimal) == 0) {
                            if (terreno[ypos][xpos]->animal->Sexo != this->Sexo) {
                                cout << "ENTRO!!!!" << endl;
                                terreno[ypos][xpos]->print();
                                reproduzcase = true;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila)) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows)) {
                    if (terreno[ypos][xpos]->ocupante.compare("Vacío") == 0 && reproduzcase) {
                        //HASTA AQUI ESTA BIEN
                        if (terreno[ypos][xpos]->animal->tipoAnimal.compare("Lobo") == 0) {
                            cout << "Entra..!" << endl;
                            terreno[ypos][xpos]->animal = new Lobo(ypos, xpos, terreno[this->Fila][this->Columna]->animal->Sexo);
                            terreno[ypos][xpos]->ocupante = terreno[this->Fila][this->Columna]->ocupante;
                        }
                        else {
                            if (terreno[ypos][xpos]->animal->tipoAnimal.compare("Oveja") == 0) {
                                cout << "Entra..!" << endl;
                                terreno[ypos][xpos]->animal = new Oveja(ypos, xpos, terreno[this->Fila][this->Columna]->animal->Sexo);
                                terreno[ypos][xpos]->ocupante = terreno[this->Fila][this->Columna]->ocupante;
                            }
                            else {
                                if (terreno[ypos][xpos]->animal->tipoAnimal.compare("Ratón") == 0) {
                                    cout << "Entra..!" << endl;
                                    terreno[ypos][xpos]->animal = new Raton(ypos, xpos, terreno[this->Fila][this->Columna]->animal->Sexo);
                                    terreno[ypos][xpos]->ocupante = terreno[this->Fila][this->Columna]->ocupante;
                                }
                                else {
                                    if (terreno[ypos][xpos]->animal->tipoAnimal.compare("Zorro") == 0) {
                                        cout << "Entra..!" << endl;
                                        terreno[ypos][xpos]->animal = new Zorro(ypos, xpos, terreno[this->Fila][this->Columna]->animal->Sexo);
                                        terreno[ypos][xpos]->ocupante = terreno[this->Fila][this->Columna]->ocupante;
                                    }
                                    else
                                        cout << "Entra..!" << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Animal::Morir() {
    if(Energia == 0){
        cout << "Murió: " << this << endl;
        return 1;
    }
    return 0;
}

void Animal::Print() {
    cout << "Energia: " << Energia << endl;
    cout << "Sexo: " << Sexo << endl;
}
