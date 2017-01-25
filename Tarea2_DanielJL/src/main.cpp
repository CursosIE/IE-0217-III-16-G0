#include "../include/Polinomio.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {

  //Creo vectores con los valores de los coeficientes para cada polinomio.
  //La posicion 0 corresponde al coeficiente que no esta acompañado de la variable.
  double d1[] = {-3, 2, 4, -2, 3};
  double d2[] = {-1, -2, 1};

  //Creo los objetos polinomios con los valores definidos anteriormente.
  Polinomio* p0 = new Polinomio(2, d2);
  Polinomio* p1 = new Polinomio(4, d1);
  Polinomio* p2 = new Polinomio();

  //Imprimo los polinomios y realizo las operaciones basicas entre ellos.
  cout << endl << "Algebra con Polinomios" << endl << endl << "Primer Polinomio: " << endl;
  p0->print();
  cout << endl << "Segundo Polinomio: " << endl;
  p1->print();
  cout << endl << "Tercer Polinomio(vacio para realizar operaciones y guardarlas en el): " << endl;
  p2->print();

  cout << endl << "Suma. Polinomio1 + Polinomio2: " << endl;
  *p2 = *p1 + *p0;
  p2->print();

  cout << endl << "Resta. Polinomio1 - Polinomio2: " << endl;
  p2 = new Polinomio();
  *p2 = *p0 - *p1;
  p2->print();

  cout << endl << "Multiplicacion. Polinomio1 * Polinomio2: " << endl;
  p2 = new Polinomio();
  *p2 = *p1 * *p0;
  p2->print();

  cout << endl << "Division. Polinomio2 / Polinomio1: " << endl;
  p2 = new Polinomio();
  *p2 = *p1 / *p0;
  p2->print();

  delete p0;
  delete p1;
  delete p2;

  cout << endl << "Fin del Programa" << endl << endl;

  return 0;
}
