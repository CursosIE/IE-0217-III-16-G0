#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>

using namespace std;

class Polinomio {
private:
    double* data;
    int grado;

public:
    Polinomio();
    Polinomio(int grado, double* data);
    Polinomio(const Polinomio& other);
    ~Polinomio();

    Polinomio operator=(const Polinomio& other);
    Polinomio operator+(const Polinomio& other);
    Polinomio operator-(const Polinomio& other);
    Polinomio operator*(const Polinomio& other);
    Polinomio operator/(const Polinomio& other);
    void print ();

};

#endif // POLINOMIO_H
