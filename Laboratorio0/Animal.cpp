#include "Animal.h"

Animal::Animal() {

}

Animal::Animal(int Fila, int Columna, int Sexo) {
    this->Fila = Fila;
    this->Columna = Columna;
    this->Sexo = Sexo;
    Energia = 100;
    cout << "SE CREO EL ANIMAL" << endl;
}

Animal::~Animal(){

}

void Animal::Reproducir() {

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
