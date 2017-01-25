#include "Animal.h"

Animal::Animal() {

}

Animal::Animal(int Fila, int Columna, int Sexo) {
    this->Fila = Fila;
    this->Columna = Columna;
    this->Sexo = Sexo;
    Energia = 100;
}

Animal::~Animal(){

}

void Animal::Reproducir() {

}

void Animal::Morir() {
    if(Energia == 0){
        cout << "Murió: " << this << endl;
        delete this;
    }
}

void Animal::Print() {
    cout << "Fila: " << Fila << endl;
    cout << "Fila: " << Columna << endl;
    if(Sexo == 1)
        cout << "Sexo: Masculino" << endl;
    else
        cout << "Sexo: Femenino" << endl;
    cout << "Energia: " << Energia << endl;
}
