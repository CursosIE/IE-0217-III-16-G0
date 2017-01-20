#ifndef POKEMON_HPP
#define  POKEMON_HPP
#include <iostream>

using namespace std;

class Pokemon{
public:
  //Atributos
  string nombre;
  string especie;
  string call;
  int hp;
  int atk;
  int defensa;
  int atkEspecial;
  int defensaEspecial;
  int experiencia;
  int spd;

public:
  //Metodos
  Pokemon();
  virtual ~Pokemon();

  void print();
  string callFun();
  virtual void ataque1(Pokemon &other) = 0;
  virtual void ataque2(Pokemon &other) = 0;
  virtual void ataque3(Pokemon &other) = 0;
  virtual void ataque4(Pokemon &other) = 0;
};

#endif //POKEMON_HPP
