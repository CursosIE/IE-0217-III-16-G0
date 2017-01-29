#include "Animal.h"
#include "Celda.h"

Animal::Animal() {
    //por defecto un animal no se va a haber reproducido nunca cuando se crea
    alreadyReproduced = false;
}

Animal::~Animal(){

}

bool Animal::Morir() {
    //si un animal se queda sin energia se muere
    if(Energia == 0){
        cout << "Murió: " << this << endl; //mensaje de muerte de un animal
        return 1; //al retornar 1 se le hace delete al animal por fuera
    }
    return 0;
}

//Esta funcion se llama dentro de la funcion imprimir de celda
//ya que un atributo de una celda es un animal
void Animal::Print() {
    cout << "Energia: " << Energia << endl;
    cout << "Sexo: " << Sexo << endl;
}
