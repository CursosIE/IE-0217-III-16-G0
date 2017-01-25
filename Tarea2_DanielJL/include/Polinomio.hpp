#ifndef POLINOMIO_HPP
#define  POLINOMIO_HPP
#include <iostream>

using namespace std;

class Polinomio{
//Atributos:
public:
  int grado;
  double* datos;

//Metodos:
public:
  //Constructores y destructores.
  Polinomio();
  Polinomio(const Polinomio& orig);
  Polinomio(int grado, double* datos);
  virtual ~Polinomio();

  //Imprimir informacion y sobrecarga de operadores.
  void print();
  Polinomio& operator=(const Polinomio &orig);
  Polinomio& operator+(const Polinomio &orig);
  Polinomio& operator-(const Polinomio &orig);
  Polinomio& operator*(const Polinomio &orig);
  Polinomio& operator/(const Polinomio &orig);
};
#endif // POLINOMIO_HPP
