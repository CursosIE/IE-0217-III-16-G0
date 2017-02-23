#ifndef LISTWITHARRAY_H
#define LISTWITHARRAY_H

#include <iostream>

#include "List.h"
#include "MyInt.h"

using namespace std;

template <typename D, typename P>
class ListWithArray : public List<D, P> {
public:

/*! \brief Constructor por defecto. Se crea con los atributos nulos y n en 0.
 */
ListWithArray() {
    data = nullptr;
    this->n = 0;
    this->maxElements = 0;
}

/*! \brief Constructor para un numero maximo de elementos dados.
 */
ListWithArray(int t) {
    data = new D[t];
    this->n = 0;
    this->maxElements = t;
}

/*! \brief Constructor por copia.
 */
ListWithArray(const ListWithArray& orig) {
}

/*! \brief Destructor.
 */
~ListWithArray() {
    delete[] data;

}

/*! \brief Metodo para insertar un dato a la lista. El dato insertado se hace al final de la lista.
 *
 *  \param d El dato que se quiere insertar.
 */
void insert(D d) { //insertar
    cout << "Inserting: " << d << endl;
    if (this->getSize() == 0) { //lista vacia
        this->data = new D[10];
        this->n = 1;
        this->last.i = 1;
        this->maxElements = 10;
        this->data[0] = d;
    } else { //lista con algo
        if (this->getSize() - 1 != last.i) { //arreglo con espacio
            this->data[last.i] = d;
            this->last.i++;
            this->n++;
        } else { //arreglo sin espacio
            D* tmp = new D[this->getSize()*2];
            for (int i = this->getSize(); i>0; i--) {
                tmp[this->getSize() - i] = this->data[last.i - i];
            }
            this->maxElements = this->getSize()*2;
            delete[] this->data;
            this->data = tmp;
            this->data[last.i] = d;
            this->last.i++;
            this->n++;
        }
    }
}

/*! \brief Metodo para remueve un dato de la lista.
 *
 *  \param d El dato que debe contener la cela a eliminar.
 */
void remove(D d) { //remover
    P temp = this->find(d);
    if (temp.i != -1) {
        cout << "Removing: " << d << endl;
        for (temp.i; temp.i< this->getSize() - 1; temp.i++) {
            assign(temp, this->data[temp.i + 1]);
        }
        this->n--;
        this->last.i--;
    }
}

/*! \brief Metodo para encontrar un dato en la lista.
 *
 *  \param d Dato que queremos encontrar.
 *  \return Referencia de la posicion que contiene dicho dato.
 */
P& find(D d) { //buscar
    cout << "Looking for: " << d << " on the list." << endl;
    for (int i = this->getSize(); i > 0; i--) {
        if (d == this->data[last.i - i]) {
            P* temp = new P(last.i - i);
            cout << "Number " << d << " was found on the list!!\n" << endl;
            return *temp;
        }
    }
    cout << "Number " << d << " was not found on the list...\n" << endl;
    P* temp = new P(-1);
    return *temp;
}

/*! \brief Metodo encontrar el dato de la posicion que se pasa como parametro.
 *
 *  \param k La celda de la cual ocupamos encontrar el dato.
 *  \return Referencia del dato que contiene la posicion.
 */
D& get(P& k) { //obtener
    if(k.i < this->getSize()){
      cout << "Geting Data in posicion: " << k.i << endl;
      return data[k.i];
    }
}

/*! \brief Metodo para assignarle el dato d a la posicion k.
 *
 *  \param d El dato que se quiere asignar.
 *  \param k Posicion a la que se le quiere asignar este dato.
 */
void assign(P& k, D d) {
    this->data[k.i] = d;
}

/*! \brief Metodo para ordenar la lista. Se usa el algoritmo bubble sort.
 */
void sort() { //ordenar
    if(this->last.i != 0){
        cout << "Sorting list:" << endl; //mensaje de que se esta ordenando la lista
        int flag = 0;
        P temp(this->last.i);
        D Menor = data[temp.i];
        D dataTemp;
        for (int j = this->getSize(); j > 0; j--) {
            for (int k = 0; this->last.i - j + k < this->getSize(); k++) {
                if(data[this->last.i - j] > data[this->last.i - j + k]){
                    Menor = data[this->last.i - j + k];
                    temp.i = this->last.i - j + k;
                    flag = 1;
                }
            }
            if(flag){
                dataTemp = data[this->last.i - j];
                data[this->last.i - j] = Menor;
                data[temp.i] = dataTemp;
                flag = 0;
            }
        }
    }
}

/*! \brief Metodo para encontrar el tamanno de la lista.
 *
 *  \return Un entero con el numero de elementos que tiene la lista.
 */
int getSize() { //tamaño
    return this->n;
}

/*! \brief Metodo para imprimir la lista.
 */
void printList() { //imprimir
    if(this->getSize()) {
        cout << "Printing list: ";
        for (int i = this->getSize(); i > 0; i--) {
            cout << this->data[last.i-i] << " ";
        }
        cout << endl;
    }else
      cout << "List is empty..!" << endl;
}

/*! \brief Metodo para encontrar el dato siguiente a una posicion dada.
 *
 *  \param k La posicion de la cual se quiere el dato siguiente.
 *  \return Referencia de la posicion siguiente.
 */
P& next(P& k) { //siguiente(
    if (k.i < this->getSize()) {
        P* temp = new P(k.i+1);
        cout << "Next to: " << data[k.i] << "\t\tis: " << data[k.i+1] << endl;
        return *temp;
    } else {
        P* temp = new P(-1);
        return *temp;
    }
}

/*! \brief Metodo para encontrar el dato anterior a una posicion dada.
 *
 *  \param k La posicion de la cual se quiere el dato anterior.
 *  \return Referencia de la posicion anterior.
 */
P& prev(P& k) { //anterior
    if (k.i > 0){
      P* temp = new P(k.i-1);
      cout << "Previous to: " << data[k.i] << "\t\tis: " << data[k.i-1] << endl;
      return *temp;
    } else {
      P* temp = new P(-1);
      return *temp;
    }
}

/*! \brief Metodo para vaciar la lista.
 */
void emptyList() { //vaciar
    cout << "Emptying list..." << endl;
    this->last.i = 0;
    this->n = 0;
}


private:
    int n; //num. elementos
    int maxElements; //máximo;
    P last; //ultimo
    D* data; //datos
};

#endif /* LISTWITHARRAY_H */
