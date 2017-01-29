#include "Controlador.h"

Controlador::Controlador() {

}

Controlador::~Controlador() {

}

int Controlador::run(int amountOfDays, char* fileName) {
    cout << "Bienvenido al  Juego de la Vida! \nMay the odds be in  your favor..!\n" << endl;

    //declaracion de variables de interes
    //int amountOfDays = 5; //esta se utilizaba antes de pasarla como argumento, para pruebas
    string animal;
    int columns = 0, rows = 0, zacate = 0; //estos valores se van a tomar del archivo de datos
    string line; //variable de utilidad a la hora de leer el archivo de datos
    int posicionColumna = 0;
    int posicionFila = 0;

    //se abre el archivo donde esta el estado inicial
    ifstream dataFile;
    dataFile.open(fileName);

    //se extraen la cantidad de columnas y filas del archivo
    //estas estan en las primeras 2 lineas
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
            //las siguientes lineas obtienen valores del archivo de datos
            dataFile >> posicionColumna;
            dataFile >> posicionFila;
            dataFile >> zacate;
            getline(dataFile, animal);
            if (animal == " ")
                animal = "Vacío";
            //se crea la celda con los datos del archivo de datos
            terreno[posicionColumna][posicionFila] = new Celda(zacate, animal, posicionColumna, posicionFila);
            //se imprime cada celda como un estado inicial del terreno
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
                        //si el terreno tiene mas de 95 de energia solo se recupera a 100
                        if (terreno[colIndex][rowIndex]->zacate > 95)
                            terreno[colIndex][rowIndex]->zacate = 100;
                    }
                }
                //si hay algun animal en el terreno, ejecutamos las acciones de los animales
                if (terreno[colIndex][rowIndex]->ocupante != "Vacío") { //revisa que el campo tenga un animal
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
                    //if(terreno[colIndex][rowIndex]->animal->operator --()){
                    if(terreno[colIndex][rowIndex]->animal->operator--()){
                        terreno[colIndex][rowIndex]->ocupante = "Vacío";
                        delete terreno[colIndex][rowIndex]->animal;
                    }
                }
                //se imprime la celda para tener el estado de esta
                terreno[colIndex][rowIndex]->print();
            }
        }
        resetReproduceMark(columns, rows, terreno); //se resetean las marcas de reproduccion cada dia
        cout << "Final día " << daysIndex << "..! \n" << endl;
    }
    cout << endl;


    //al acabar la ejecucion del juego, al pasar todos los dias hay que liberar toda la memoria dinamica
    //que se utilizo. En este caso hay que liberar todos los animales y las celdas

    for (int colIndex = 0; colIndex < columns; ++colIndex) {
        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
            if(terreno[colIndex][rowIndex]->ocupante != "Vacío")
                delete terreno[colIndex][rowIndex]->animal; //libero cada objeto animal que cree
            delete terreno[colIndex][rowIndex]; //libero cada celda que se creo
        }
        delete terreno[colIndex];//libero cada puntero dentro del vector de punteros
    }
    delete terreno; //libero el vector de punteros a celda que se creo

    cout << "Finalización del programa..!" << endl;

    return 0;
}

//Cada animal tiene una marca que dice si ya se reprodujo cada dia.
//entonces al finalizar cada dia se resetean las marcas de todos los animales
//ya que al reproducirse esta marca se cambia para que no se reproduzcan mas de 1 vez al dia
void Controlador::resetReproduceMark(int columns, int rows, Celda*** terreno) {
    for (int colIndex = 0; colIndex < columns; ++colIndex) {
        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
            if (terreno[colIndex][rowIndex]->ocupante.compare("Vacío") != 0)
                terreno[colIndex][rowIndex]->animal->alreadyReproduced = false;
        }
    }
}
