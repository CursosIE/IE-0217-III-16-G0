#include "Raton.h"
#include "Celda.h"

Raton::Raton() {

}

Raton::Raton(int Fila, int Columna, int Sexo) {
    this->Fila = Fila;
    this->Columna = Columna;
    this->Sexo = Sexo;
    Energia = 25;
    tipoAnimal = "Ratón";
}

Raton::~Raton() {

}

int Raton::Mover(int columns, int rows, Celda*** terreno) {
    for (int xpos = this->Columna-1; xpos <= this->Columna+1; ++xpos) {
        for (int ypos = this->Fila-1; ypos <= this->Fila+1; ++ypos) {
            if (!(xpos == this->Columna && ypos == this->Fila)) { //no se mete en si mismo
                if ((xpos >=  0 && xpos < columns) && (ypos >=  0 && ypos < rows))
                    if(terreno[ypos][xpos]->ocupante.compare("Vacío") == 0){
                        terreno[ypos][xpos]->animal = new Raton(ypos, xpos, terreno[this->Fila][this->Columna]->animal->Sexo);
                        terreno[ypos][xpos]->ocupante = terreno[this->Fila][this->Columna]->ocupante;
                        delete terreno[this->Fila][this->Columna]->animal;
                        terreno[this->Fila][this->Columna]->ocupante = "Vacío";
                        return 0;
                    }

            }
        }
    }
    return 0;
}

int Raton::Comer(int columns, int rows, Celda*** terreno) {
    if(terreno[this->Fila][this->Columna]->zacate >= 5){
        terreno[this->Fila][this->Columna]->zacate -= 5;
        terreno[this->Fila][this->Columna]->animal->Energia += 5;
        if(terreno[this->Fila][this->Columna]->animal->Energia > 25)
            terreno[this->Fila][this->Columna]->animal->Energia = 25;
    }else{
        terreno[this->Fila][this->Columna]->animal->Energia += terreno[this->Fila][this->Columna]->zacate;
        terreno[this->Fila][this->Columna]->zacate = 0;
        if(terreno[this->Fila][this->Columna]->animal->Energia > 25)
            terreno[this->Fila][this->Columna]->animal->Energia = 25;
    }

    return 0;
}

//Solo se puede reproducir con un animal y solo si es de su misma especie pero de distinto sexo
//si se reproduce tanto este como la pareja no puede volver a resproducirse durante el dia
void Raton::Reproducir(int columns, int rows, Celda ***terreno) {
    bool reproduzcase = false; //esta variable se va a poner en verdadero si existe una pareja disponeble
    int x =0, y = 0;

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
