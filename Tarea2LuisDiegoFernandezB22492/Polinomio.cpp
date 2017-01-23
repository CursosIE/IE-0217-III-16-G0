#include "Polinomio.h"

Polinomio::Polinomio() {

}

Polinomio::Polinomio(int grado, double* data) {
    this->grado = grado;
    this->data = new double [this->grado + 1];
    for (int index = 0; index <= this->grado; ++index)
        this->data[index] = data[index];
}

Polinomio::Polinomio(const Polinomio& other) {
    this->grado = other.grado;
    this->data = new double [this->grado + 1];
    for (int index = 0; index <= this->grado; ++index)
        this->data[index] = other.data[index];
}

Polinomio::~Polinomio() {
    delete [] this->data;
}

Polinomio Polinomio::operator=(const Polinomio& other) {
    if (this == &other)
        return *this;

    this->grado = other.grado;
    this->data = new double [this->grado + 1];
    for (int index = 0; index <= this->grado; ++index)
        this->data[index] = other.data[index];

    return *this;

    //return Polinomio(other);
}

Polinomio Polinomio::operator+(const Polinomio& other) {
    int nuevoGrado = 0;
    if (this->grado > other.grado)
        nuevoGrado = this->grado;
    else
        nuevoGrado = other.grado;

    double resultVector[nuevoGrado + 1];

    for (int index = 0; index < nuevoGrado + 1; ++index) {
        if (this->grado >= index && other.grado >= index)
            resultVector[index] = this->data[index] + other.data[index];
        else {
            if (this->grado < index)
                resultVector[index] = other.data[index];
            else
                resultVector[index] = this->data[index];
        }
    }

    Polinomio* result = new Polinomio(nuevoGrado, resultVector);
    return *result;
}

Polinomio Polinomio::operator-(const Polinomio& other) {
    int nuevoGrado = 0;
    if (this->grado > other.grado)
        nuevoGrado = this->grado;
    else
        nuevoGrado = other.grado;

    double resultVector[nuevoGrado + 1];

    for (int index = 0; index < nuevoGrado + 1; ++index) {
        if (this->grado >= index && other.grado >= index)
            resultVector[index] = this->data[index] - other.data[index];
        else {
            if (this->grado < index)
                resultVector[index] = other.data[index];
            else
                resultVector[index] = this->data[index];
        }
    }

    Polinomio* result = new Polinomio(nuevoGrado, resultVector);
    return *result;
}

Polinomio Polinomio::operator*(const Polinomio& other) {
    int nuevoGrado = this->grado + other.grado;
    double resultData [nuevoGrado + 1];

    for (int index = 0; index <= nuevoGrado; ++index)
        resultData[index] = 0.0;

    for (int outIndex = 0; outIndex <= this->grado; ++outIndex) {
        for (int inIndex = 0; inIndex <= other.grado; ++inIndex) {
            resultData[outIndex + inIndex] = (this->data[outIndex] * other.data[inIndex])
            + resultData[outIndex + inIndex];
        }
    }

    Polinomio* result = new Polinomio(nuevoGrado, resultData);
    return *result;
}

Polinomio Polinomio::operator/(const Polinomio& other) {
    /*int resultGrade = other.grado;
    double restar = 0.0;
    double resultData [resultGrade + 1];
    double* temp = this->data;

    for (int index = 0; index <= resultGrade; ++index)
        resultData[index] = 0.0;


    for (int divideIndex = 0; divideIndex <= this->grado; ++divideIndex) {
        resultData[resultGrade - divideIndex] = temp[this->grado - divideIndex] / other.data[other.grado];
        for (int substractIndex = 0; substractIndex < this->grado; ++substractIndex) {
            restar = (resultData[resultGrade - divideIndex] * other.data[this->grado - substractIndex -2x]);
            temp[this->grado - substractIndex - 1] = temp[this->grado - substractIndex -1] - restar;
        }
    }

    Polinomio* result = new Polinomio(resultGrade, resultData);
    return *result;*/
}

void Polinomio::print() {
    //cout << "El polinomio está en: " << this << endl;
    for (int index = 0; index <= this->grado; ++index) {
        if (index != grado) {
            if (this->data[grado - index] == 1)
                cout << "x^" << this->grado - index << " + ";
            else
            cout << this->data[grado - index] << "x^" << this->grado - index << " + ";
        }
        else
            cout << this->data[grado - index] << endl;
    }
}
