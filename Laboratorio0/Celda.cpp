#include "Celda.h"
#include "Animal.h"

Celda::Celda() {

}

Celda::Celda(int cantidadZacate, string tipoOcupante, int fila, int columna) {
    zacate = cantidadZacate;
    ocupante = tipoOcupante;
    this->fila = fila;
    this->columna = columna;

    //dependiendo del tipo de animal que diga el archivo de datos
    //ese tipo de animal es creado
    if(ocupante.compare(" LM") == 0)
        animal = new Lobo(fila, columna, 1);
    else if(ocupante.compare(" LH")  == 0)
        animal = new Lobo(fila, columna, 2);
    else if(ocupante.compare(" OM")  == 0)
        animal = new Oveja(fila, columna, 1);
    else if(ocupante.compare(" OH")  == 0)
        animal = new Oveja(fila, columna, 2);
    else if(ocupante.compare(" ZM")  == 0)
        animal = new Zorro(fila, columna, 1);
    else if(ocupante.compare(" ZH")  == 0)
        animal = new Zorro(fila, columna, 2);
    else if(ocupante.compare(" RM")  == 0)
        animal = new Raton(fila, columna, 1);
    else if(ocupante.compare(" RH")  == 0)
        animal = new Raton(fila, columna, 2);
}

Celda::~Celda() {

}

//se imprime toda la informacion relevane de una celda y de el animal que esta dentro de ella
void Celda::print() {
    cout << "Posición: [" << fila << ", " << columna << "]" << endl;
    cout << "Nivel zacate: " << zacate << endl;
    cout << "Ocupante: " << ocupante << endl;

    //si la celda no tiene una animal dentro entonces no se imprime la informacion del animal
    if (ocupante != "Vacío")
       animal->Print();
    cout << endl;
}
