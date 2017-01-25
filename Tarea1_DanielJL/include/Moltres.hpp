#ifndef MOLTRES_HPP
#define  MOLTRES_HPP
#include <iostream>
#include "Flying.hpp"
#include "Fire.hpp"

using namespace std;

class Moltres : public Flying, public Fire{
public:
  //Atributos
  string type;
  string strongVs;
  string weekVs;

public:
  //Metodos
  Moltres();
  Moltres(string Nombre);
  virtual ~Moltres();

  void printMoltres();
  void ataque1(Pokemon &other);
  void ataque2(Pokemon &other);
  void ataque3(Pokemon &other);
  void ataque4(Pokemon &other);
};

#endif //MOLTRES_HPP
