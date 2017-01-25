#include "../include/Polinomio.hpp"

//Constructor vacio.
Polinomio::Polinomio(){
  grado = 1;
  this->datos = new double [this->grado];
  datos[0] = 0;
}

//Constructor por copia.
Polinomio::Polinomio(const Polinomio& orig){
  grado = orig.grado;
  this->datos = new double [this->grado];
  for (int i = 0; i < orig.grado; i++){
    datos[i] = orig.datos[i];
  }
}

//Constructor con grado y coeficientes dados.
Polinomio::Polinomio(int grado, double* datos){
  this->grado = grado + 1;
  this->datos = new double [this->grado];
  for (int i = 0; i < this->grado; i++) {
    this->datos[i] = datos[i];
  }
}

//Destructor.
Polinomio::~Polinomio(){
  delete[] datos;
}

//Funcion para imprimir el grado y la ecuacion correspondiente a un objeto.
void Polinomio::print(){
  cout << "Grado: " << grado - 1 << endl;
  cout << "Ecuacion: ";
  for (int i = 1; i < grado; i++) {
    cout << datos[grado - i] <<  "x^" << grado - i << " + " ;
  }
  cout << datos[0] << endl;
}

//Sobrecarga de operador para igualar (=).
Polinomio& Polinomio::operator=(const Polinomio &orig){
  grado = orig.grado;
  datos = new double [grado];
  for (int i = 0; i < orig.grado; i++){
    datos[i] = orig.datos[i];
  }
  return *this;
}

//Sobrecarga de operador de suma (+).
Polinomio& Polinomio::operator+(const Polinomio &orig){
  if(orig.grado >= this->grado){
    double newData[orig.grado];
    int temp = 0;
    for (int i = 0; i < this->grado; i++) {
      newData[i] = orig.datos[i] + this->datos[i];
      temp = i;
    }
    while(temp < orig.grado){
      temp += 1;
      newData[temp] = orig.datos[temp];
    }
    Polinomio* newP = new Polinomio(orig.grado - 1, newData);
    return *newP;
  }else{
    double newData[this->grado];
    int temp = 0;
    for (int i = 0; i < orig.grado; i++) {
      newData[i] = orig.datos[i] + this->datos[i];
      temp = i;
    }
    while(temp < this->grado){
      temp += 1;
      newData[temp] = this->datos[temp];
    }
    Polinomio* newP = new Polinomio(this->grado - 1, newData);
    return *newP;
  }
}

//Sobrecarga de operador de resta (-).
Polinomio& Polinomio::operator-(const Polinomio &orig){
  if(orig.grado >= this->grado){
    double newData[orig.grado];
    int temp = 0;
    for (int i = 0; i < this->grado; i++) {
      newData[i] = this->datos[i] - orig.datos[i];
      temp = i;
    }
    while(temp < orig.grado){
      temp += 1;
      newData[temp] = -orig.datos[temp];
    }
    Polinomio* newP = new Polinomio(orig.grado - 1, newData);
    return *newP;
  }else{
    double newData[this->grado];
    int temp = 0;
    for (int i = 0; i < orig.grado; i++) {
      newData[i] = this->datos[i] - orig.datos[i];
      temp = i;
    }
    while(temp < this->grado){
      temp += 1;
      newData[temp] = this->datos[temp];
    }
    Polinomio* newP = new Polinomio(this->grado - 1, newData);
    return *newP;
  }
}

//Sobrecarga de operador de Multiplicacion (*)
Polinomio& Polinomio::operator*(const Polinomio &orig){
  int newGrado = orig.grado + this->grado - 1;
  double newData[newGrado];
  for (int i = 0; i < orig.grado; i++) {
    for (int j = 0; j < this->grado; j++) {
      newData[i+j] = (orig.datos[i]*this->datos[j]) + newData[i+j];
    }
  }
  Polinomio* newP = new Polinomio(newGrado - 1, newData);
  return *newP;
}

//Sobrecarga de operador de Division (/).
Polinomio& Polinomio::operator/(const Polinomio &orig){
  if(this->grado > orig.grado){
    int DeltaExp;
    float DivCoef;
    double TempDatos[this->grado];
    double TempDatos2[this->grado];
    for (int i = 0; i < this->grado; i++) {
      TempDatos[i] = this->datos[i];
    }

    double newData[this->grado-orig.grado];

    for (int j = this->grado-1; j >= 0; j--) {
      if(j >= orig.grado-1){
        DivCoef = TempDatos[j] / orig.datos[orig.grado-1];
        // cout << TempDatos[j] << endl << orig.datos[orig.grado-1] << endl << DivCoef << endl;
        DeltaExp = j - (orig.grado - 1);

        for (int i = 0; i < orig.grado; i++) {
          TempDatos2[i+DeltaExp] = orig.datos[i] * DivCoef;
        }
        for (int i = 0; i < DeltaExp; i++) {
          TempDatos2[i] = 0;
        }
        for (int i = 0; i < this->grado; i++) {
          TempDatos[i] = TempDatos[i] - TempDatos2[i];
        }
        newData[j-(orig.grado-1)] = DivCoef;
      }else{
        Polinomio* newP = new Polinomio(this->grado-orig.grado, newData);
        return *newP;
      }
    }
  }else{
    cout << "No se puede realizar la operacion." << endl;
    Polinomio* newP = new Polinomio();
    return *newP;
  }
}
