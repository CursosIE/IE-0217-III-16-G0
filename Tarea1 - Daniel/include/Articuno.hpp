#ifndef ARTICUNO_HPP
#define  ARTICUNO_HPP
#include <iostream>
#include "Flying.hpp"
#include "Ice.hpp"

using namespace std;

class Articuno : public Flying, public Ice{
public:
  //Atributos
  string type;
  string strongVs;
  string weekVs;

public:
  //Metodos
  Articuno();
  Articuno(string Nombre);
  virtual ~Articuno();

  void printArticuno();
  void ataque1(Pokemon &other);
  void ataque2(Pokemon &other);
  void ataque3(Pokemon &other);
  void ataque4(Pokemon &other);
};

#endif //ARTICUNO_HPP
