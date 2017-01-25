#ifndef ZAPDOS_HPP
#define  ZAPDOS_HPP
#include <iostream>
#include "Flying.hpp"
#include "Electric.hpp"

using namespace std;

class Zapdos : public Flying, public Electric{
public:
  //Atributos
  string type;
  string strongVs;
  string weekVs;

public:
  //Metodos
  Zapdos();
  Zapdos(string Nombre);
  virtual ~Zapdos();

  void printZapdos();
  void ataque1(Pokemon &other);
  void ataque2(Pokemon &other);
  void ataque3(Pokemon &other);
  void ataque4(Pokemon &other);
};

#endif //ZAPDOS_HPP
