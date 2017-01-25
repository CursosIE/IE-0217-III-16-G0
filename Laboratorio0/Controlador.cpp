#include "Controlador.h"

Controlador::Controlador() {

}

Controlador::~Controlador() {

}

int Controlador::run() {
    cout << "Bienvenido al  Juego de la Vida! \nMay the odds be in  your favor..!" << endl;

    int columns = 0;
    int rows = 0;

    ifstream dataFile;
    dataFile.open("datos.txt");

    if (dataFile.is_open()) {
        dataFile >> columns;
        dataFile >> rows;
    }

    dataFile.close();

    cout << columns << endl;
    cout << rows << endl;


    /*Celda*** terreno = new Celda**[columns];
    for (int index = 0; index < columns; ++index) {
        terreno[index] = new Celda*[rows];
    }

    for (int colIndex = 0; colIndex < columns; ++colIndex) {
        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
            terreno[colIndex][rowIndex] = new Celda(100, 11);
            terreno[colIndex][rowIndex]->print();
        }
    }*/

    return 0;
}
