#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#include "Cell.h"
#include "List.h"

using namespace std;

template <typename D, typename P>
class Queue : public List<D, P> {
   public:
   	P* first;
   	P* last;

   public:
   /*! \brief Constructor por defecto. Se crea con los atributos nulos y n en 0.
    */
    Queue() {
        this->n = 0;
        this->first = nullptr;
        this->last = nullptr;
    }

    /*! \brief Destructor. LLama al metodo emptyList.
     */
    virtual ~Queue() {
    	emptyList();
    }

    /*! \brief Metodo para insertar un dato a una cola. Se crea una nueva celda y se enlaza a la ultima
    *         en caso de no haber ninguna se pone como la primera.
    *
    *  \param data El dato que se quiere insertar.
    *  \param cell Celda que se crea para insertar el nuevo dato.
    */
    void insert(D data) {
      	cout << "Inserting: " << data << endl;
        //se pregunta si la lista NO tiene algun elemento, entonces la nueva celda se pone como first y last
        if (this->n == 0) {
            P* cell = new P(new D(data), nullptr);
            this->first = cell;
            this->last = cell;
        }
        //en caso contrario se agrega al final y se le pone el puntero de first.
        else {
            P* cell = new P(new D(data), this->first);
            this->first = cell;
        }
        this->n++; //aumenta el contador de elementos de la lista
    }

    /*! \brief Metodo para remover una celda de la cola.
     *
     *  \param data Este parametro no importa porque la cola solo puede eliminar una celda, la ultima.
     */
    void remove(D data) {
      cout << "Removing" << endl;
      //Reviso si solo hay un elemento.
      if (this->n == 1) {
    		delete this->first;
    		this->n -= 1;
        first = nullptr;
        last = nullptr;
    	}	else { //si hay mas elementos acualizo cual sera el ultimo elemento.
            P* temp = this->first;
          	for (int index = 0; index < this->n; ++index) {
          		if (temp->next == this->last){
                delete this->last;
                this->last = temp;
              } else {
                if (temp->next != nullptr)
                  temp = temp->next;
              }
            }
            this->n -= 1;
	    }
    }

    /*! \brief Metodo para encontrar un dato en la cola.
     *
     *  \param data Dato que queremos encontrar.
     *  \return Referencia de la cela que contiene dicho dato.
     */
    P& find(D data) {
      cout << "Looking for: " << data << " on the queue." << endl;

      P* temp = this->first;
      for (int index = 0; index < this->n; ++index) {
          if (*(temp->data) == data){
              cout << "Number " << data << " was found on the queue!!\n" << endl; //mensaje de exito
              return *temp;
          }
          if (temp->next != nullptr)
              temp = &(next(*temp));
      }
      cout << "Number " << data << " was not found on the queue...\n" << endl; //mensaje que no se encontro
    }

    D& get(P& cell) {

    }

    /*! \brief Metodo para encontrar el tamanno de la cola.
     *
     *  \return Un entero con el numero de elementos que tiene la cola.
     */
    int getSize() {
        return this->n;
    }

    /*! \brief Metodo para imprimir la pila.
     */
    void printList() {
        if (this->n == 0)
            cout << "Queue is empty..!" << endl;
        else {
            P* temp = this->first;
            cout << "Printing queue:\nIn-> ";
            for (int index = 0; index < this->n; ++index) {
                cout << *(temp->data) << "  ";
                if (temp->next != nullptr)
                	temp = temp->next;
            }
            cout << "-> Out" << endl;
        }
    }

    /*! \brief Metodo para encontrar la celda siguiente a una dada.
     *
     *  \param cell La celda de la cual que quiere la celda siguiente.
     *  \return Referencia de la celda siguiente a cell.
     */
    P& next(P& cell) {
      //se evita el caso de la celda last
      if (&(cell) != &(*(this->last)))
          return *(cell.next);
    }

    /*! \brief Metodo para encontrar un puntero a la celda previa a una dada.
     *
     *  \param cell La celda de la cual que quiere la celda previa.
     *  \return Puntero a la celda previa a cell.
     */
    P& prev(P& cell) {
      P* prev = nullptr;
      P* temp = this->first;

      if (&cell != (this->first)) {
          for (int index = 0; index < this->n; ++index) {
              prev = temp;
              temp = temp->next;
              //se busca la celda previa
              if (*(temp->data) == *(cell.data) && &(temp->next) == &(cell.next)) {
                  return *(prev);
              }
          }
      }
    }

    /*! \brief Metodo para vaciar la pila.
     */
    void emptyList() {
    	cout << "Emptying queue..." << endl;
    	erase(this->first);
    	this->n = 0;
    }

    /*! \brief Metodo auxiliar para vaciar la pila. Trabaja recursivamente.
     */
    void erase(P* k) {
    	if (k->data != nullptr && k->next != nullptr) {
    		erase(k->next);
    		delete k;
    	}
    }

    void assign(P& k, D d) {

    }

    void sort() {

    }

};
#endif // QUEUE_H
