#include "Animal.h"
#include "Celda.h"

Animal::Animal() {
    alreadyReproduced = false;
}

Animal::~Animal(){

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
