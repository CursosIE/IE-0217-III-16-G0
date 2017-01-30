/**
*@file Raton.cpp
*@version 1.0
*@date 29/01/17
*@author Luis Diego Fernandez, Daniel Jimenez
*@title Juego de la vida
*@brief Clase Raton
*/

#include "Raton.h"
#include "Celda.h"

/*! \brief Constructor por defecto.
 */
Raton::Raton() {

}

/*! \brief Constructor para crear un Raton con datos especificos.
 */
Raton::Raton(int Fila, int Columna, int Sexo) {
    this->Fila = Fila;
    this->Columna = Columna;
    this->Sexo = Sexo;
    Energia = 25;
    tipoAnimal = "Ratón";
}

/*! \brief Destructor.
 */
Raton::~Raton() {

}

/*! \brief Metodo para que el raton se mueva en el terreno. Es capaz de moverse
 *         solo un espacio en el terrreno siempre que este desocupado y
 *         sea aledaño.
 */
int Raton::Mover(int columns, int rows, Celda*** terreno) {
    //Verifico que el animal no se haya movido.
    if(terreno[this->Fila][this->Columna]->animal->alreadyMoved == false) {
        //Se busca si en las posiciones aledañas si hay algun espacio libre en donde se pueda mover el animal.
        //Este doble ciclo for esta configurado de manera que se busca alrededor de la celda en la cual se esta
        //evita tambien salirse de la matriz para no dar errores de segmentacion y evita utilizarse a si misma.
        for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
            for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
                if (!(xpos == this->Columna && ypos == this->Fila)) { //no se mete en si mismo
                    if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows)) {
                        //Si la celda no tiene animal, se mueve.
                        if(terreno[ypos][xpos]->ocupante.compare("Vacío") == 0){
                            //Creo el nuevo animal con las mismas caracteristicas que el original.
                            terreno[ypos][xpos]->animal = new Raton(ypos, xpos, terreno[this->Fila][this->Columna]->animal->Sexo);
                            terreno[ypos][xpos]->animal->Energia = terreno[this->Fila][this->Columna]->animal->Energia;
                            terreno[ypos][xpos]->ocupante = terreno[this->Fila][this->Columna]->ocupante;
                            //Indico que ya se movio.
                            terreno[ypos][xpos]->animal->alreadyMoved = true;
                            //Elimino el animal de la posicion de la cual se esta desplazando para dejar la celda vacia.
                            delete terreno[this->Fila][this->Columna]->animal;
                            terreno[this->Fila][this->Columna]->ocupante = "Vacío";
                            return 0;
                        }

                    }
                }
            }
        }
    }
    return 0;
}

/// \brief Metodo para comer. Se alimenta del zacate, consume 5 puntos del zacate y recupera la misma cantidad.
///        En caso de no haber suficiente zacate, consume lo que haya y recupera eso mismo. No puede excederse
///        de 25 la energia del Raton.
int Raton::Comer(int columns, int rows, Celda*** terreno) {
    //Si el zacate tiene mas de 5 puntos, consume 5 y los adquiere el animal.
    if(terreno[this->Fila][this->Columna]->zacate >= 5){
        terreno[this->Fila][this->Columna]->zacate -= 5;
        terreno[this->Fila][this->Columna]->animal->Energia += 5;
        //Se verifica que no se haya pasado de 25
        if(terreno[this->Fila][this->Columna]->animal->Energia > 25)
            terreno[this->Fila][this->Columna]->animal->Energia = 25;
    //En caso de que haya menos que 5 puntos consume la cantidad de puntos que haya nada mas.
    }else{
        terreno[this->Fila][this->Columna]->animal->Energia += terreno[this->Fila][this->Columna]->zacate;
        terreno[this->Fila][this->Columna]->zacate = 0;
        //Se verifica que no se haya pasado de 25
        if(terreno[this->Fila][this->Columna]->animal->Energia > 25)
            terreno[this->Fila][this->Columna]->animal->Energia = 25;
    }

    return 0;
}

/// \brief Metodo para reproducirse. Solo se puede reproducir con un animal y solo si es de su misma especie
///        pero de distinto sexo si se reproduce tanto este como la pareja no puede volver a resproducirse durante el dia.
///
/// \param reproduzcase Mediante esta variable se informa si hay una pareja disponible.
/// \param x Posicion del animal con el cual se puede reproducir.
/// \param y Posicion del animal con el cual se puede reproducir.
void Raton::Reproducir(int columns, int rows, Celda ***terreno) {
    bool reproduzcase = false; //Mediante esta variable se informa si hay una pareja disponible.
    int x =0, y = 0; //Posicion del animal con el cual se puede reproducir.

    //en este doble ciclo se busca que haya una pareja disponible y que NO se haya reproducido en el presente dia
    //este doble ciclo for esta configurado de manera que se busca alrededor de la celda en la cual se esta
    //evita tambien salirse de la matriz para no dar errores de segmentacion y evita utilizarse a si misma
    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila) && !reproduzcase) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows)) { //evita que se salga de la matriz
                    if (terreno[ypos][xpos]->ocupante.compare("Vacío") != 0) { //si hay un animal en la celda entra
                        if (terreno[ypos][xpos]->animal->tipoAnimal.compare(this->tipoAnimal) == 0) {//revisa que ambos animales sean del mismo tipo
                            if (terreno[ypos][xpos]->animal->Sexo != this->Sexo && !terreno[ypos][xpos]->animal->alreadyReproduced) { //revisa que ambos animales sean de distinto sexo
                                reproduzcase = true;//pone la bandera
                                terreno[ypos][xpos]->animal->alreadyReproduced = true;//marca que el animal target ya se va a reproducir por este dia
                                //estas posiciones se guardan en caso de que no se encuentro un espacio  para poner la
                                //cria, entonces se desmarca la pareja para que se pueda reproducir de nuevo
                                x = xpos;
                                y = ypos;
                            }
                        }
                    }
                }
            }
        }
    }

    //este doble ciclo busca una celda del terreno vacia en la cual se pueda poner un futuro hizo del apareaminteo
    for (int xpos1 = this->Columna-1; xpos1 <= this->Columna+1; ++xpos1) {
        for (int ypos1 = this->Fila-1; ypos1 <= this->Fila+1; ++ypos1) {
            if (!(xpos1 == this->Columna && ypos1 == this->Fila)) { //no se mete en si mismo
                if ((xpos1 >=  0 && xpos1 < columns) && (ypos1 >=  0 && ypos1 < rows)) {
                    if (terreno[ypos1][xpos1]->ocupante.compare("Vacío") == 0) {//busca uno que este vacio
                        if(reproduzcase && !this->alreadyReproduced){
                            //crea un animal nuevo con el sexo del animal ->this
                            terreno[ypos1][xpos1]->animal = new Raton(ypos1, xpos1, terreno[this->Fila][this->Columna]->animal->Sexo);
                            terreno[ypos1][xpos1]->ocupante = terreno[this->Fila][this->Columna]->ocupante;
                            reproduzcase = false;
                            terreno[this->Fila][this->Columna]->animal->alreadyReproduced = true;
                        }
                    }
                }
            }
        }
    }
    //en caso de que ->this no haya encontrado campo para poner el hijo, entonces desmarco a la pareja
    if (!terreno[this->Fila][this->Columna]->animal->alreadyReproduced)
        terreno[y][x]->animal->alreadyReproduced = false;
}

/*void Raton::PrintRaton() {
    cout << "Especie: Raton" << endl;
    this->Print();
}*/
