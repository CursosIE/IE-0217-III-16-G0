#include "Controlador.h"

Controlador::Controlador() {

}

Controlador::~Controlador() {

}

int Controlador::run() {
    cout << "Bienvenido al  Juego de la Vida! \nMay the odds be in  your favor..!\n" << endl;

    int amountOfDays = 4;
    string animal;
    int columns = 0;
    string line;
    int posicionColumna = 0;
    int posicionFila = 0;
    int rows = 0;
    int zacate = 0;

    ifstream dataFile;
    dataFile.open("datos.txt");

    if (dataFile.is_open()) {
        dataFile >> columns;
        dataFile >> rows;
    }

    Celda*** terreno = new Celda**[columns];
    for (int index = 0; index < columns; ++index) {
        terreno[index] = new Celda*[rows];
    }

    cout << "Estado inicial: " << endl;
    for (int colIndex = 0; colIndex < columns; ++colIndex) {
        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {

            dataFile >> posicionColumna;
            dataFile >> posicionFila;
            dataFile >> zacate;
            getline(dataFile, animal);
            if (animal == " ")
                animal = "Vacío";
            terreno[posicionColumna][posicionFila] = new Celda(zacate, animal);
            terreno[posicionColumna][posicionFila]->print();
        }
    }
    cout << "Final: \n" << endl;

    dataFile.close();


    //EMPEZAMOS A CORRER LOS DIAS
    for (int daysIndex = 1; daysIndex <= amountOfDays; ++daysIndex) {
        cout << "Día " << daysIndex << ": " << endl;
        for (int colIndex = 0; colIndex < columns; ++colIndex) {
            for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
                if (terreno[colIndex][rowIndex]->zacate > 0 && terreno[colIndex][rowIndex]->zacate < 100 && daysIndex %3 == 0)
                    terreno[colIndex][rowIndex]->zacate += 1;
                terreno[colIndex][rowIndex]->print();
            }
        }
        cout << "Final día " << daysIndex << "..! \n" << endl;
    }

    cout << endl;


    //SE CREA EL TERRENO CON LOS DATOS POR DEFECTO QUE NOS DA EL PROFE QUE ESTAN EN datos.txt

    //Celda* prueba = new Celda(100, "Lobo");
    //prueba->print();

    /*Lobo* L1 = new Lobo(12, 13, 1);
    L1->PrintLobo();
    cout << endl;

    Oveja* O1 = new Oveja(9, 1, 2);
    O1->PrintOveja();
    cout << endl;

    Raton* R1 = new Raton(5, 2, 2);
    R1->PrintRaton();
    cout << endl;

    Zorro* Z1 = new Zorro(4, 6, 1);
    Z1->PrintZorro();
    cout << endl;

    Z1->Energia = 0;
    if(Z1->Morir())
        delete Z1;

    */


    return 0;
}
