#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>

using namespace std;

class Pokemon {

//atributos de la clase pokemon
public:
    string name;
    string species;
    string cry;
    string status;
    int SPD;
    int HP;
    int ATK;
    int DEF;
    int sATK;
    int sDEF;
    int EXP;

public:
    Pokemon();
    virtual ~Pokemon();

    void printInfo ();
    string call ();
    //definicion de 4 metodos virtuales puros
    //no se implementan
    virtual void atk1(Pokemon &other) = 0;
    virtual void atk2(Pokemon &other) = 0;
    virtual void atk3() = 0; //este ataque tiene implicaciones sobre el mismo pokemon, no sobre el otro
                             // se implementó así y no como dice el enunciado de la tarea xq es más real
    virtual void atk4(Pokemon &other) = 0;

};

#endif // POKEMON_H
