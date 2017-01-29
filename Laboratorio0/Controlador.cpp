#include "Controlador.h"

Controlador::Controlador() {

}

Controlador::~Controlador() {

}

int Controlador::run(int amountOfDays, char* fileName) {
    cout << "Bienvenido al  Juego de la Vida! \nMay the odds be in  your favor..!\n" << endl;

    //declaracion de variables de interes
    //int amountOfDays = 5;
    string animal;
    int columns = 0;
    string line;
    int posicionColumna = 0;
    int posicionFila = 0;
    int rows = 0;
    int zacate = 0;

    //se abre el archivo donde esta el estado inicial
    ifstream dataFile;
    dataFile.open(fileName);

    if (dataFile.is_open()) {
        dataFile >> columns;
        dataFile >> rows;
    }

    //se crea una matriz de objetos tipo Celda
    Celda*** terreno = new Celda**[columns];
    for (int index = 0; index < columns; ++index) {
        terreno[index] = new Celda*[rows];
    }

    cout << "Estado inicial (creción de la Tierra): " << endl;

    //se llena la matriz con inicializaciones de celdas con sus respectivos datos
    //el estado inicial
    for (int colIndex = 0; colIndex < columns; ++colIndex) {
        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
            dataFile >> posicionColumna;
            dataFile >> posicionFila;
            dataFile >> zacate;
            getline(dataFile, animal);
            if (animal == " ")
                animal = "Vacío";
            terreno[posicionColumna][posicionFila] = new Celda(zacate, animal, posicionColumna, posicionFila);
            terreno[posicionColumna][posicionFila]->print();
        }
    }

    dataFile.close(); //se cierra el archivo ya que no se ocupa mas

    //EMPEZAMOS A CORRER LOS DIAS
    for (int daysIndex = 1; daysIndex <= amountOfDays; ++daysIndex) {
        cout << "\nInicio día " << daysIndex << ": \n" << endl;
        for (int colIndex = 0; colIndex < columns; ++colIndex) {
            for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
                //cada 3 dias el terreno gana 5 de energia
                if (terreno[colIndex][rowIndex]->zacate > 0 && daysIndex %3 == 0) {
                    if (terreno[colIndex][rowIndex]->zacate <= 95)
                        terreno[colIndex][rowIndex]->zacate += 5;
                    else {
                        if (terreno[colIndex][rowIndex]->zacate > 95)
                            terreno[colIndex][rowIndex]->zacate = 100;
                    }
                }
                //si hay algun animal en el terreno, ejecutamos las acciones de los animales
                if (terreno[colIndex][rowIndex]->ocupante != "Vacío") {
                    //Funcion mover
                    //terreno[colIndex][rowIndex]->animal->Mover(columns, rows, terreno);
                    //Funcion Comer
                    terreno[colIndex][rowIndex]->animal->Comer(columns, rows, terreno);
                    //Funcion reproducir
                    terreno[colIndex][rowIndex]->animal->Reproducir(columns, rows, terreno);
                    //al final de cada dia los animales pierden 1 de energia
                    terreno[colIndex][rowIndex]->animal->Energia -= 1;
                    //si el animal perdio energia y llego a cero, se muere
                    //Funcion morir
                    if(terreno[colIndex][rowIndex]->animal->Morir()){
                        terreno[colIndex][rowIndex]->ocupante = "Vacío";
                        delete terreno[colIndex][rowIndex]->animal;
                    }
                }
                terreno[colIndex][rowIndex]->print();
            }
        }
        resetReproduceMark(columns, rows, terreno);
        cout << "Final día " << daysIndex << "..! \n" << endl;
    }
    cout << endl;

    return 0;
}

void Controlador::resetReproduceMark(int columns, int rows, Celda*** terreno) {
    for (int colIndex = 0; colIndex < columns; ++colIndex) {
        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
            if (terreno[colIndex][rowIndex]->ocupante.compare("Vacío") != 0)
                terreno[colIndex][rowIndex]->animal->alreadyReproduced = false;
        }
    }
}
