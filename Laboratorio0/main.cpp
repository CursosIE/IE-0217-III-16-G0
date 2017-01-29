#include <stdlib.h>

#include "Controlador.h"

int main(int argc, char *argv[]) {
    int amountOfDays = atoi(argv[1]);
    //string fileName = argv[2];
    Controlador controlador;
    return controlador.run(amountOfDays, argv[2]);
}
