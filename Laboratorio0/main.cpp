#include <stdlib.h>

#include "Controlador.h"

//se reciben 2 argumentos:
//el primero la cantidad de dias que van a pasar
//el segundo el nombre del archivo del cual se van a leer los datos
int main(int argc, char *argv[]) {
    int amountOfDays = atoi(argv[1]); //argv[] recibe un char* entonces hay que pasarlo a int
    
    //la clase controlador va a manejar el juego
    Controlador controlador;
    
    //se llama a la funcion run del controlador con los parametros respectivos
    return controlador.run(amountOfDays, argv[2]);
}
