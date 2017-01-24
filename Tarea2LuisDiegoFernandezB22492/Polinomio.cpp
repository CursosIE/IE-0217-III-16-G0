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
    int grado = other.grado;
    double quotient [grado + 1];
    double remainder [grado + 1];

    double temp [this->grado + 1];
    for (int index = 0; index <= this->grado; ++index)
        temp[index] = this->data[index];

    for (int dividendIndex = 0; dividendIndex <= other.grado; ++dividendIndex) {
        quotient[grado - dividendIndex] = temp[this->grado - dividendIndex] / other.data[other.grado];

        for (int remainderIndex = 0; remainderIndex <= other.grado; ++remainderIndex) {
            remainder[grado - remainderIndex] = quotient[grado - dividendIndex] * other.data[other.grado - remainderIndex];
        }

        for (int restIndex = 0; restIndex <= other.grado; ++restIndex) {
            temp[this->grado - restIndex - dividendIndex] = temp[this->grado - restIndex - dividendIndex] - remainder[other.grado - restIndex];
        }
    }

    Polinomio* semiResult = new Polinomio(grado, quotient);
    Polinomio* tempo = new Polinomio(this->grado, temp);

    return *semiResult + *tempo;
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
