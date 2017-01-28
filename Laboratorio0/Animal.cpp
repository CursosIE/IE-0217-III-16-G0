#include "Animal.h"
#include "Celda.h"

Animal::Animal() {

}

Animal::~Animal(){

}

void Animal::Reproducir(int columns, int rows, Celda*** terreno) {
    cout << "This columna: " << this->Columna << endl;
    cout << "This fila: " << this->Fila << endl;

    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila)) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows))
                    cout << "[" << xpos << ", " << ypos << "]" << endl;
            }
        }
    }
    cout << endl;
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
}
