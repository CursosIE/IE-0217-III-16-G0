#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>

using namespace std;

class Polinomio {
private:
    double* data;
    int grado;

public:
    ///constructor por defecto
    Polinomio();

    ///constructor por conversion
    Polinomio(int grado, double* data);

    ///constructor por copia
    Polinomio(const Polinomio& other);

    ///destructor
    ~Polinomio();

    //sobrecarga de diferentes operadores
    Polinomio operator=(const Polinomio& other);
    Polinomio operator+(const Polinomio& other);
    Polinomio operator-(const Polinomio& other);
    Polinomio operator*(const Polinomio& other);
    Polinomio operator/(const Polinomio& other);

    void print ();
};

#endif // POLINOMIO_H
