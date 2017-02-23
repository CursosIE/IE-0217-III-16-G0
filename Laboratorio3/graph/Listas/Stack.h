#ifndef STACK_H
#define STACK_H

#include <iostream>

#include "Cell.h"
#include "List.h"

using namespace std;

template <typename D, typename P>
class Stack : public List<D, P> {
   public:
   	P* first;
   	P* last;

   public:
    /*! \brief Constructor por defecto. Se crea con los atributos nulos y n en 0.
     */
    Stack() {
        this->n = 0;
        this->first = nullptr;
        this->last = nullptr;
    }

    /*! \brief Destructor. LLama al metodo emptyList.
     */
    virtual ~Stack() {
    	emptyList();
    }

    /*! \brief Metodo para insertar un dato a una pila. Se crea una nueva celda y se enlaza a la ultima
     *         en caso de no haber ninguna se pone como la primera. 
     *
     *  \param data El dato que se quiere insertar.
     *  \param cell Celda que se crea para insertar el nuevo dato.
     */ 
    void insert(D data) {
        cout << "Inserting: " << data << endl; //mensaje de insercion

        P* cell = new P(new D(data), nullptr); 

        //se pregunta si la lista NO tiene algun elemento, entonces la nueva celda se pone como first y last
        if (this->n == 0) {
            this->first = cell;
            this->last = cell;
        }
        //en caso contrario se agrega al final y se le pone el puntero last
        else {
            this->last->next = cell;
            this->last = cell;   
        }

        this->n++; //aumenta el contador de elementos de la lista
    }

    /*! \brief Metodo para remover una celda de la pila.
     *
     *  \param data Este parametro no importa porque la pila solo puede eliminar una celda, la ultima.
     */ 
    void remove(D data) {
        cout << "Removing" << endl;
    	if (this->n == 1) {
    		delete this->first;
    		this->n -= 1;
        first = nullptr;
        last = nullptr;
    	}
    	else {
            P* temp = this->last;
            P* temp2 = prevs(*(temp));
            delete temp;
            this->last = temp2;
            this->n -= 1;
	    }
        //cout << "Last: " << *(this->last->data) << endl;
    }

    /*! \brief Metodo para encontrar un dato en la pila.
     *
     *  \param data Dato que queremos encontrar.
     *  \return Referencia de la cela que contiene dicho dato.
     */ 
    P& find(D data) {
        cout << "Looking for: " << data << " on the stack." << endl;

        P* temp = this->first;
        for (int index = 0; index < this->n; ++index) {
            if (*(temp->data) == data){
                cout << "Number " << data << " was found on the stack!!\n" << endl; //mensaje de exito
                return *temp;
            }
            if (temp->next != nullptr) 
                temp = &(next(*temp));
        }

        cout << "Number " << data << " was not found on the stack...\n" << endl; //mensaje que no se encontro
    }

    D& get(P& cell) {
      
    }

    /*! \brief Metodo para encontrar el tamanno de la pila.
     *
     *  \return Un entero con el numero de elementos que tiene la pila.
     */ 
    int getSize() {
        return this->n;
    }

    /*! \brief Metodo para imprimir la pila.
     */ 
    void printList() {
        if (this->n == 0)
            cout << "Stack is empty..!" << endl; //se indica que la pila esta vacia.
        else {
            P* temp = this->last;

            cout << "Printing stack:\nIn/Out -> <- "; //mensaje de impresion de la pila/
            for (int index = 0; index < this->n; ++index) {
                cout << *(temp->data) << "  ";
                temp = prevs(*(temp));
            }
            cout << endl;
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

    P& prev(P& cell) {

    }

    /*! \brief Metodo para encontrar un puntero a la celda previa a una dada.
     *
     *  \param cell La celda de la cual que quiere la celda previa.
     *  \return Puntero a la celda previa a cell.
     */ 
    P* prevs(P& cell) {
        P* prev = nullptr;
        P* temp = this->first;

        if (&cell != (this->first)) {
            for (int index = 0; index < this->n; ++index) {
                prev = temp;
                temp = temp->next;
                //se busca la celda previa
                if (*(temp->data) == *(cell.data) && &(temp->next) == &(cell.next)) {
                    return (prev);
                }
            }
        }
    }

    /*! \brief Metodo para vaciar la pila.
     */ 
    void emptyList() {
    	cout << "Emptying stack..." << endl;
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
#endif // STACK_H
