#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

/*! \brief Metodo que hace una busqueda en una lista ordenada del tipo Binary Search
 *
 *  \param myVector[] Vector en el cual vienen los numeros ordenados para hacer la busqueda.
 *  \param size Tamanno del vector myVector[].
 *  \param find Numero que se quiere encontrar.
 */
int binarySearch (int myVector[], int size, int find) {
	int min = 0;
	int max = size-1;
	int flag = 0;

	clock_t begin = clock(); //se inicia un clocl

	while (flag == 0) {
		//si el elemento en la posicion de buscqueda es igual a find hay exito
		if (myVector[(min + max) / 2] == find) {
            flag = 1;
            clock_t end = clock(); //se inicia otro clock
            cout << 1;
            //se imprime el tiempo de ejecucion del programa
            //cout << "\ntime: " << (1000000 * (end - begin)) / CLOCKS_PER_SEC << "\u00B5s" << endl;
            cout << "\ntime: " << (1000* (end - begin)) / CLOCKS_PER_SEC << "ms." << endl;
            return 1;
        }
        else if (myVector[(min + max) / 2] > find)
            max = (min + max) / 2;
        else if (myVector[(min + max) / 2] < find)
            min = (min + max) / 2;
       
       //si se revisaron todos los numeros se acaba la ejecucion con una condicio de no exito
       if(max == min + 1) {
        	clock_t end = clock(); //se inicia otro clock
        	cout << 0;
        	//se imprime el tiempo de ejecucion del programa
        	//cout << "\ntime: " << (1000000 * (end - begin)) / CLOCKS_PER_SEC << "\u00B5s" << endl;
        	cout << "\ntime: " << (1000* (end - begin)) / CLOCKS_PER_SEC << "ms." << endl;
        	return 0;
        }
	}
	return 0;
}

/*! \brief Metodo ordena un vector de numeros en orden ascendente utilizando el Selection Sort
 *
 *  \param myVector[] Vector en el cual vienen los numeros no ordenados.
 *  \param size Tamanno del vector myVector[].
 */
void selectionSort (int myVector[], int size) {
    clock_t begin = clock(); // se inicia un clock

    int temp = 0;
    int posMin = 0;
    //primer for de ordenamiento
    for (int n = 0; n < size - 1; n++){
    	posMin = n;
    	//segundo for de ordenamiento
		for (int m = n + 1; m < size; m++) {
			if (myVector[m] < myVector[posMin]) 
				posMin = m;
		}
		//intercambio de valores en caso de que haya que ordenar
		if (posMin != n) {
			temp = myVector[n];
			myVector[n] = myVector[posMin];
			myVector[posMin] = temp;
		}
	}

	clock_t end = clock(); //se inicia otro clock

	//se imprime el vector
	for (int i = 0; i < size; ++i) {
		cout << myVector[i] << " ";
	}

	//se imprime el tiempo de ejecucion del programa
	//cout << "\ntime: " << (1000000 * (end - begin)) / CLOCKS_PER_SEC << "\u00B5s" << endl; //imprime en micro segundos
	cout << "\ntime: " << (1000* (end - begin)) / CLOCKS_PER_SEC << "ms." << endl;
}

/*! \brief Metodo Main
 *
 *  \param argc Contador de la cantidad de argumentos que recibe el programa.
 *  \param argv Un vector que tiene los argumentos pasados por la linea de comandos.
 */
int main(int argc, char *argv[]) {
	//se definen ciertas variables de utilidad
	int find = 0; //va a recibir el numero que quiere buscar el binary search
	int size = 0; //ve a tener el tamano del vector
    int temp = 0;
    int ss = true; //para saber si meterme a la funcion del selection sort o binary search
    char* fileName; //va a tener el nombre del archivo de datos

    //dependiendo de la funcion que haya que hacer se van a recibir los argumentos de la
    //linea de comando de manera diferente
    if (strcmp (argv[1], "ss") ==  0) //"ss" = selection sort
    	fileName = argv[2];
    else if (strcmp (argv[1], "bs") ==  0){ //"bs" = binary search
    	find = atoi(argv[2]);
    	fileName = argv[3];
    	ss = false;
    }

    ifstream dataFile;

    dataFile.open(fileName); //abre el archivo 

    //obtiene el tamanno + 1 del archivo
   	while (!dataFile.eof()) {
   		dataFile >> temp;
   		size += 1;
   	}

    dataFile.close(); //cierra el archivo

    size -= 1; //pone el tamanno real
    
    int myVector[size]; // vector que va a contener los numeros 

    dataFile.open(fileName); //se vuelve a abrir el archivo

    //se llena el vector
    for (int index = 0; index < size; ++index)
    	dataFile >> myVector[index];

    dataFile.close(); //cierra el archivo

    //se llama alguna de las 2 funciones dependiendo de los argumentos
    //que se le pasaron al programa
    if (ss)
    	selectionSort(myVector, size);
    else 
    	return binarySearch(myVector, size, find);
    
    return 0;
}