#include "Pokemon.h"

Pokemon::Pokemon() {

}

Pokemon::~Pokemon() {

}

string Pokemon::call() {
    return cry;
}

//imprime informacion basica general de cualquier pokemon
void Pokemon::printInfo() {
    cout << "Nombre: " << name << endl;
    cout << "Especie: " << species << endl;
    cout << "Estado: " << status << endl;
    cout << "Speed: " << SPD << endl;
    cout << "Hp: " << HP << endl;
    cout << "Special attack: " << sATK << endl;
    cout << "Special defense: " << sDEF << endl;
    cout << "Experience: " << EXP << endl;
}
