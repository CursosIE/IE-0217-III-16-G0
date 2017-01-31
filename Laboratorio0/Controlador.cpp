/**
*@file Controlador.cpp
*@version 1.0
*@date 29/01/17
*@author Luis Diego Fernandez, Daniel Jimenez
*@title Juego de la vida
*@brief Clase Controlador
*/

#include "Controlador.h"

int Controlador::columns;
int Controlador::rows;
Celda*** Controlador::terreno;

/*! \brief Constructor por defecto.
 */
Controlador::Controlador() {

}

/*! \brief Destructor.
 */
Controlador::~Controlador() {

}

/*! \brief Metodo que imprime el estado del sistema (terreno)
 *
 *  \param columns Posicion en la cual se desea crear el animal y establecer los datos a la celda.
 *  \param rows Posicion en la cual se desea crear el animal y establecer los datos a la celda.
 *  \param terreno La matriz de celdas con el cual esta basado el juego
 */
void Controlador::printTerreno(int columns, int rows, Celda ***terreno) {
    for (int colIndex = 0; colIndex < columns; ++colIndex)
        for (int rowIndex = 0; rowIndex < rows; ++rowIndex)
            terreno[colIndex][rowIndex]->print();
}

/*! \brief Metodo que ejecuta la logica del juego.
 *
 *  \param animal Almacenar temporalmente el animal que se lee del archivo de texto.
 *  \param columns Posicion en la cual se desea crear el animal y establecer los datos a la celda.
 *  \param rows Posicion en la cual se desea crear el animal y establecer los datos a la celda.
 *  \param zacate Nivel de zacate en la celda.
 *  \param line Variable de utilidad a la hora de leer el archivo de datos.
 *  \param posicionColumna Variable para recorrer el terreno.
 *  \param posicionFila Variable para recorrer el terreno.
*/
int Controlador::run(int amountOfDays, char* fileName) {
    cout << "Bienvenido al  Juego de la Vida! \nMay the odds be in  your favor..!\n" << endl;

    //declaracion de variables de interes
    //int amountOfDays = 5; //esta se utilizaba antes de pasarla como argumento, para pruebas
    string animal; //Almacenar temporalmente el animal que se lee del archivo de texto.
    int zacate = 0; //Posicion en la cual se desea crear el animal y datos de la celda.
    string line; //Variable de utilidad a la hora de leer el archivo de datos.
    int posicionColumna = 0, posicionFila = 0; //Variables para recorrer el terreno.

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
    terreno = new Celda**[columns];
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
        //imprimo el estado del sistema al inicio del dia
        cout << "\nEstado al inicio del día " << daysIndex << ": \n" << endl;
        printTerreno(columns, rows, terreno);

        //Para estar seguros que cada día se apliquen todos los metodos sobre los animales recorremos la matriz dos veces
        for (int banderaControl = 0; banderaControl < 2; ++banderaControl) {
            for (int colIndex = 0; colIndex < columns; ++colIndex) {
                for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
                    //cada 3 dias el terreno gana 5 de energia
                    if(banderaControl == 1) {
                        if (terreno[colIndex][rowIndex]->zacate > 0 && daysIndex %3 == 0) {
                            if (terreno[colIndex][rowIndex]->zacate <= 95)
                                terreno[colIndex][rowIndex]->zacate += 5;
                            else {
                                //si el terreno tiene mas de 95 de energia solo se recupera a 100
                                if (terreno[colIndex][rowIndex]->zacate > 95)
                                    terreno[colIndex][rowIndex]->zacate = 100;
                            }
                        }
                    }
                    //si hay algun animal en el terreno, ejecutamos las acciones de los animales
                    if (terreno[colIndex][rowIndex]->ocupante != "Vacío") { //revisa que el campo tenga un animal
                        //Funcion mover
                        !(*terreno[colIndex][rowIndex]->animal);
                        //revisa nuevamente que el campo tenga un animal y que no se hayan aplicado los metodos sobre el
                        if (terreno[colIndex][rowIndex]->ocupante != "Vacío" && terreno[colIndex][rowIndex]->animal->allFunctions == false) {
                            //Funcion Comer
                            ++(*terreno[colIndex][rowIndex]->animal);
                            //Funcion reproducir
                            ~(*terreno[colIndex][rowIndex]->animal);
                            //al final de cada dia los animales pierden 1 de energia
                            terreno[colIndex][rowIndex]->animal->Energia -= 1;
                            //si el animal perdio energia y llego a cero, se muere
                            //Funcion morir sobrecargada con el operado --
                            if(--(*terreno[colIndex][rowIndex]->animal)){
                                terreno[colIndex][rowIndex]->ocupante = "Vacío";
                                delete terreno[colIndex][rowIndex]->animal;
                            }
                            //Inico que al animal se le aplicaron todos los metodos
                            terreno[colIndex][rowIndex]->animal->allFunctions = true;
                        }
                    }
                }
            }
        }

        resetMarks(columns, rows, terreno); //se resetean las marcas de reproduccion cada dia

        //imprimo el estado del sistema al final del dia
        cout << "Estado al final del día " << daysIndex << ":\n" << endl;
        printTerreno(columns, rows, terreno);
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

    //PRUEBA PLANTILLA
    //Lobo* l1 = new Lobo(1, 1, 1);


    return 0;
}

/// \brief Metodo para resetear banderas de control. Cada animal tiene una marca que dice si ya se reprodujo, se movio
///        y aplicaron demas metodos cada dia, entonces al finalizar cada dia se resetean las marcas de todos los animales
///        para que al dia siguiente puedan ser aplicadas nuevamente.
void Controlador::resetMarks(int columns, int rows, Celda*** terreno) {
    for (int colIndex = 0; colIndex < columns; ++colIndex) {
        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
            if (terreno[colIndex][rowIndex]->ocupante.compare("Vacío") != 0) {
                terreno[colIndex][rowIndex]->animal->allFunctions = false;
                terreno[colIndex][rowIndex]->animal->alreadyMoved = false;
                terreno[colIndex][rowIndex]->animal->alreadyReproduced = false;
            }
        }
    }
}
