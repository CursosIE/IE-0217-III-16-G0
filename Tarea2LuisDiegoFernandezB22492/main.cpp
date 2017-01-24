#include <iostream>

#include "Polinomio.h"

using namespace std;

int main() {
    //se crean los vectores que van a tener los valores de los polinomios
    //el indice dentro el vector corresponde al coeficiente dentro del polinomio
    double vector0[] = {10, 1, 2, 3, 4, 5};
    double vector1[] = {20, 1, 2, 3, 4, 5, 6, 7};
    double vector2[] = {13, -8, -11, 15, 3, 9, -9, 8, 10, 1};
    double vector3[] = {-10, -3, 1};
    double vector4[] = {2, 1};
    double vector5[] = {-9, 6, 0, 0, 2, 0, 1};
    double vector6[] = {3, 0, 0, 1};

    //se crean 7 polinomio
    Polinomio* p0 = new Polinomio(5, vector0);
    Polinomio* p1 = new Polinomio(7, vector1);
    Polinomio* p2 = new Polinomio(9, vector2);
    Polinomio* p3 = new Polinomio(2, vector3);
    Polinomio* p4 = new Polinomio(1, vector4);
    Polinomio* p5 = new Polinomio(6, vector5);
    Polinomio* p6 = new Polinomio(3, vector6);

    //se crea un polinomio utilizando el constructor por copia
    Polinomio copia = *p0;

    //se procede a crear ciertos polinomios con el constructor por defecto
    //se les pone nombres significativos que indican el resultado que va a ser asignado a ellos
    Polinomio* sumaP0P1 = new Polinomio();
    Polinomio* sumaP0P2 = new Polinomio();
    Polinomio* restaP0P1 = new Polinomio();
    Polinomio* restaP1P0 = new Polinomio();
    Polinomio* restaP1P2 = new Polinomio();
    Polinomio* multP0P1 = new Polinomio();
    Polinomio* multP0P2 = new Polinomio();
    Polinomio* multP1P2 = new Polinomio();
    Polinomio* divP3P4 = new Polinomio();
    Polinomio* divP5P6 = new Polinomio();

    //se imprimen los 7 polinomios creados anteriormente
    cout << "P0: " << endl;
    p0->print();

    cout << "\nP1: " << endl;
    p1->print();

    cout << "\nP2: " << endl;
    p2->print();

    cout << "\nP3: " << endl;
    p3->print();

    cout << "\nP4: " << endl;
    p4->print();

    cout << "\nP5: " << endl;
    p5->print();

    cout << "\nP6: " << endl;
    p6->print();

    //se imprime el polinomio que resulto del constructor por copia
    cout << "\nCopia de P0: " << endl;
    copia.print();

    //se hacen las distintas operaciones, se asigan al polinomio correspondiente y se imprimen
    *sumaP0P1 = *p0 + *p1;
    cout << "\nP0 + P1: " << endl;
    sumaP0P1->print();

    *sumaP0P2= *p0 + *p2;
    cout << "\nP0 + P2: " << endl;
    sumaP0P2->print();

    *restaP0P1 = *p0 - *p1;
    cout << "\nP0 - P1: " << endl;
    restaP0P1->print();

    *restaP1P0 = *p1 - *p0;
    cout << "\nP1 - P0: " << endl;
    restaP1P0->print();

    *restaP1P2 = *p1 - *p2;
    cout << "\nP1 - P2: " << endl;
    restaP1P2->print();

    *multP0P1 = *p0 * *p1;
    cout << "\nP0 * P1: " << endl;
    multP0P1->print();

    *multP0P2 = *p0 * *p2;
    cout << "\nP0 * P2: " << endl;
    multP0P2->print();

    *multP1P2 = *p1 * *p2;
    cout << "\nP1 * P2: " << endl;
    multP1P2->print();

    *divP3P4 = *p3 / *p4;
    cout << "\nP3 / P4: " << endl;
    divP3P4->print();

    *divP5P6 = *p5 / *p6;
    cout << "\nP5 / P6: " << endl;
    divP5P6->print();

    //se finaliza el programa
    return 0;
}
