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
    Stack() {
        this->n = 0;
        this->first = nullptr;
        this->last = nullptr;
    }

    virtual ~Stack() {
    	emptyList();
    }

    /*! \brief Metodo para insertar un dato a la lista. Se crea una nueva celda y se enlaza a las anteriores
     *         en caso de no haber ninguna se pone como la primera. El dato insertado se hace al final de la lista.
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

    P& find(D data) {

    }

    D& get(P& cell) {
      
    }

    int getSize() {
        return this->n;
    }

    void printList() {
        if (this->n == 0)
            cout << "Stack is empty..!" << endl;
        else {
            P* temp = this->last;

            cout << "Printing stack:\nIn/Out -> <- ";
            for (int index = 0; index < this->n; ++index) {
                cout << *(temp->data) << "  ";
                temp = prevs(*(temp));
            }
            cout << endl;
        }
    }

    P& next(P& cell) {

    }

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

    void emptyList() {
    	cout << "Emptying stack..." << endl;
    	erase(this->first);
    	this->n = 0;
    }

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
