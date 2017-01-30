/**
*@file Animal.cpp
*@version 1.0
*@date 29/01/17
*@author Luis Diego Fernandez, Daniel Jimenez
*@title Juego de la vida
*@brief Clase Animal
*/

#include "Animal.h"
#include "Celda.h"

/*! \brief Constructor por defecto.
 */
Animal::Animal() {
    //por defecto a un animal no se le va a haber aplicado ningun metodo al crearse
    allFunctions = false;
    alreadyMoved = false;
    alreadyReproduced = false;
}

/*! \brief Destructor.
 */
Animal::~Animal(){

}

/*! \brief Metodo para determinar si un animal debe morir.
 */
bool Animal::operator--() {
    //si un animal se queda sin energia se muere
    if(Energia == 0){
        cout << "Murió: " << this << endl; //mensaje de muerte de un animal
        return 1; //al retornar 1 se le hace delete al animal por fuera
    }
    return 0;
}

/// \brief Esta funcion se llama dentro de la funcion imprimir de celda
///        ya que un atributo de una celda es un animal
void Animal::Print() {
    cout << "Energia: " << Energia << endl;
    if(Sexo == 1)
        cout << "Sexo: Macho" << endl;
    else
        cout << "Sexo: Hembra" << endl;
}
