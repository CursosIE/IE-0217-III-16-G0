/**
*@file Lobo.cpp
*@version 1.0
*@date 29/01/17
*@author Luis Diego Fernandez, Daniel Jimenez
*@title Juego de la vida
*@brief Clase Lobo
*/

#include "Lobo.h"

/*! \brief Constructor por defecto.
 */
Lobo::Lobo() {

}

/*! \brief Constructor para crear un Lobo con datos especificos.
 */
Lobo::Lobo(int Fila, int Columna, int Sexo) {
    this->Columna = Columna;
    Energia = 100;
    this->Fila = Fila;
    this->Sexo = Sexo;
    tipoAnimal = "Lobo";
}

/*! \brief Destructor.
 */
Lobo::~Lobo() {

}

/*! \brief Metodo para que el Lobo se mueva en el terreno. Es capaz de moverse
 *         hasta tres espacios en el terrreno siempre que estan desocupados y
 *         sean aledaños.
 *
 *  \param xActual Posicion actual del animal.
 *  \param yActual Posicion actual del animal.
 *  \param xPrevio Posicion previa del animal.
 *  \param yPrevio Posicion previa del animal.
 *  \param contador Numero de veces que se ha desplzado el animal.
 */
int Lobo::operator!() {
    int xActual = this->Columna; //Posicion actual del animal.
    int yActual = this->Fila;
    int yPrevio, xPrevio; //Posicion previa del animal.
    int contador = 0; //Numero de veces que se ha desplazado el animal.
    int temp;

    //Verifico que el animal no se haya movido.
    if(Controlador::terreno[this->Fila][this->Columna]->animal->alreadyMoved == false) {
        //Si el animal se mueve se deben empezar de nuevo los ciclos for por lo tanto se utiliza este ciclo while para ello.
        while (temp) {
            temp = 0;
            //Se busca si en las posiciones aledañas si hay algun espacio libre en donde se pueda mover el animal.
            //Este doble ciclo for esta configurado de manera que se busca alrededor de la celda en la cual se esta
            //evita tambien salirse de la matriz para no dar errores de segmentacion y evita utilizarse a si misma.
            for (int xpos = xActual-1; xpos <= xActual+1; ++xpos) {
                for (int ypos = yActual-1; ypos <= yActual+1; ++ypos) {
                    if (!(xpos == xActual && ypos == yActual)) { //no se mete en si mismo
                        if ((xpos >=  0 && xpos < Controlador::columns) && (ypos >=  0 && ypos < Controlador::rows))
                            //Si la celda no tiene animal y ademas no es la posicion previa en la cual estuvo, se mueve.
                            if((Controlador::terreno[ypos][xpos]->ocupante.compare("Vacío") == 0) && ypos != yPrevio && xpos != xPrevio){
                                //Creo el nuevo animal con las mismas caracteristicas que el original.
                                Controlador::terreno[ypos][xpos]->animal = new Lobo(ypos, xpos, Controlador::terreno[yActual][xActual]->animal->Sexo);
                                Controlador::terreno[ypos][xpos]->animal->Energia = Controlador::terreno[yActual][xActual]->animal->Energia;
                                Controlador::terreno[ypos][xpos]->ocupante = Controlador::terreno[yActual][xActual]->ocupante;
                                //Indico que ya se movio.
                                Controlador::terreno[ypos][xpos]->animal->alreadyMoved = true;
                                //Elimino el animal de la posicion de la cual se esta desplazando para dejar la celda vacia.
                                delete Controlador::terreno[yActual][xActual]->animal;
                                Controlador::terreno[yActual][xActual]->ocupante = "Vacío";
                                //Actualizo variables de control.
                                yPrevio = yActual;
                                xPrevio = xActual;
                                yActual = ypos;
                                xActual = xpos;
                                contador += 1;
                                temp = 1;
                                if(contador == 3)
                                    return 0;
                            }
                    }
                }
            }
        }

    }
    return 0;
}

/// \brief Metodo para comer. Se alimenta de cualquier otro animal que esten en posiciones aledañas. Recive 10 puntos
///        por Ovejas, 5 puntos por Zorros y 2 por ratones. Mata al otro animal. No puede excederse de 100 la energia
///        del Zorro. Si hay dos lobos machos alguno de los dos muere.
int Lobo::operator++() {
    //Se busca si en las posiciones aledañas hay un Animal de cualquier especie para eliminarlo y subir la energia del Lobo
    //este doble ciclo for esta configurado de manera que se busca alrededor de la celda en la cual se esta
    //evita tambien salirse de la matriz para no dar errores de segmentacion y evita utilizarse a si misma
    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila)) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < Controlador::columns) && (ypos >=  0 && ypos < Controlador::rows)){
                    //Verifico cual tipo de animal es porque la cantidad de puntos que recupera el lobo son diferentes
                    if(Controlador::terreno[ypos][xpos]->ocupante.compare(" OM")  == 0 || Controlador::terreno[ypos][xpos]->ocupante.compare(" OH")  == 0) {
                        delete Controlador::terreno[ypos][xpos]->animal; //Mato al animal.
                        Controlador::terreno[ypos][xpos]->ocupante = "Vacío"; //Asigno vacia la celda.
                        Controlador::terreno[this->Fila][this->Columna]->animal->Energia += 10; //Aumento energia del Lobo.
                        //Verifico que no se pase de 100 la energia.
                        if(Controlador::terreno[this->Fila][this->Columna]->animal->Energia > 100)
                            Controlador::terreno[this->Fila][this->Columna]->animal->Energia = 100;
                        return 0;
                    }else if(Controlador::terreno[ypos][xpos]->ocupante.compare(" ZM")  == 0 || Controlador::terreno[ypos][xpos]->ocupante.compare(" ZH")  == 0) {
                        delete Controlador::terreno[ypos][xpos]->animal;
                        Controlador::terreno[ypos][xpos]->ocupante = "Vacío";
                        Controlador::terreno[this->Fila][this->Columna]->animal->Energia += 5;
                        if(Controlador::terreno[this->Fila][this->Columna]->animal->Energia > 100)
                            Controlador::terreno[this->Fila][this->Columna]->animal->Energia = 100;
                        return 0;
                    }else if(Controlador::terreno[ypos][xpos]->ocupante.compare(" RM")  == 0 || Controlador::terreno[ypos][xpos]->ocupante.compare(" RH")  == 0) {
                        delete Controlador::terreno[ypos][xpos]->animal;
                        Controlador::terreno[ypos][xpos]->ocupante = "Vacío";
                        Controlador::terreno[this->Fila][this->Columna]->animal->Energia += 2;
                        if(Controlador::terreno[this->Fila][this->Columna]->animal->Energia > 100)
                            Controlador::terreno[this->Fila][this->Columna]->animal->Energia = 100;
                        return 0;
                    //Si se encuentra otro Lobo macho utilizo una función para generar un numero aleatorio y asi decidir cual muere.
                    }else if(Controlador::terreno[ypos][xpos]->ocupante.compare(" LM") == 0 && Controlador::terreno[this->Fila][this->Columna]->ocupante.compare(" LM") == 0){
                        if((rand() % 10) < 5){
                            delete Controlador::terreno[ypos][xpos]->animal;
                            Controlador::terreno[ypos][xpos]->ocupante = "Vacío";
                            return 0;
                        }else{
                            delete Controlador::terreno[this->Fila][this->Columna]->animal;
                            Controlador::terreno[this->Columna][this->Fila]->ocupante = "Vacío";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

/// \brief Metodo para reproducirse. Solo se puede reproducir con un animal y solo si es de su misma
///        especie pero de distinto sexo si se reproduce tanto este como la pareja no puede volver a
///        resproducirse durante el dia.
///
/// \param reproduzcase Mediante esta variable se informa si hay una pareja disponible.
/// \param x Posicion del animal con el cual se puede reproducir.
/// \param y Posicion del animal con el cual se puede reproducir.
//metodo reproducir
void Lobo::operator~() {
    bool reproduzcase = false; //Mediante esta variable se informa si hay una pareja disponible.
    int x =0, y = 0; //Posicion del animal con el cual se puede reproducir.

    //en este doble ciclo se busca que haya una pareja disponible y que NO se haya reproducido en el presente dia
    //este doble ciclo for esta configurado de manera que se busca alrededor de la celda en la cual se esta
    //evita tambien salirse de la matriz para no dar errores de segmentacion y evita utilizarse a si misma
    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila) && !reproduzcase) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < Controlador::columns) && (ypos >=  0 && ypos < Controlador::rows)) { //evita que se salga de la matriz
                    if (Controlador::terreno[ypos][xpos]->ocupante.compare("Vacío") != 0) { //si hay un animal en la celda entra
                        if (Controlador::terreno[ypos][xpos]->animal->tipoAnimal.compare(this->tipoAnimal) == 0) {//revisa que ambos animales sean del mismo tipo
                            if (Controlador::terreno[ypos][xpos]->animal->Sexo != this->Sexo && !Controlador::terreno[ypos][xpos]->animal->alreadyReproduced) { //revisa que ambos animales sean de distinto sexo
                                reproduzcase = true;//pone la bandera
                                Controlador::terreno[ypos][xpos]->animal->alreadyReproduced = true;//marca que el animal target ya se va a reproducir por este dia
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
                if ((xpos1 >=  0 && xpos1 < Controlador::columns) && (ypos1 >=  0 && ypos1 < Controlador::rows)) {
                    if (Controlador::terreno[ypos1][xpos1]->ocupante.compare("Vacío") == 0) {//busca uno que este vacio
                        if(reproduzcase && !this->alreadyReproduced){
                            //crea un animal nuevo con el sexo del animal ->this
                            Controlador::terreno[ypos1][xpos1]->animal = new Lobo(ypos1, xpos1, Controlador::terreno[this->Fila][this->Columna]->animal->Sexo);
                            Controlador::terreno[ypos1][xpos1]->ocupante = Controlador::terreno[this->Fila][this->Columna]->ocupante;
                            reproduzcase = false;
                            Controlador::terreno[this->Fila][this->Columna]->animal->alreadyReproduced = true;
                        }
                    }
                }
            }
        }
    }
    //en caso de que ->this no haya encontrado campo para poner el hijo, entonces desmarco a la pareja
    if (!Controlador::terreno[this->Fila][this->Columna]->animal->alreadyReproduced)
        Controlador::terreno[y][x]->animal->alreadyReproduced = false;
}

/*void Lobo::PrintLobo() {
    cout << "Especie: Lobo" << endl;
    this->Print();
}*/

