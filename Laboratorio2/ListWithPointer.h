#ifndef LISTWITHPOINTER_H
#define LISTWITHPOINTER_H

#include <iostream>

#include "Cell.h"
#include "List.h"

using namespace std;

template <typename D, typename P> 
class ListWithPointer : public List<D, P> {
   public:
    ///Puntero a la primera celda de la lista.
   	P* first;
    ///Puntero a la ultima celda de la lista.
   	P* last;

   public:
    /*! \brief Constructor por defecto. Se crea con los atributos nulos y n en 0.
     */
    ListWithPointer () {
        this->n = 0;
        this->first = nullptr;
        this->last = nullptr;
    }

    /*! \brief Destructor. LLama al metodo emptyList.
     */
    virtual ~ListWithPointer() {
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

    /*! \brief Metodo para remueve una celda de la lista.
     *
     *  \param data El dato que debe contener la cela a eliminar.
     */ 
    void remove(D data) {
        cout << "Removing: " << data << endl; //mensaje de eliminacion/
        //si la lsita solo tiene una celda y es igual a data se elimina.
    	if (this->n == 1 && *(this->first->data) == data) {
    		delete first;
    		this->n -= 1;
    	}
        //se busca el dato en la lista y se elimina.
    	else {
	        P* del = nullptr;
	        P* pre = nullptr;
	        if (*(this->first->data) == data) {
	        	del = this->first;
	        	this->first = del->next;
	        	delete del;
	        	this->n -= 1;
	        }

	        pre = this->first;
	        del = this->first->next;

	        while(del != nullptr) {
	        	if (*(del->data) == data) {
	        		pre->next = del->next;
	        		if (del == this->last)
	        			this->last = pre;
	        		delete del;
	        		this->n -= 1;
	        		break;
	        	}
	        	pre = del;
	        	del = del->next;
	        }
	    }
    }

    /*! \brief Metodo para encontrar un dato en la lista.
     *
     *  \param data Dato que queremos encontrar.
     *  \return Referencia de la cela que contiene dicho dato.
     */ 
    P& find(D data) {
        cout << "Looking for: " << data << " on the list." << endl;

    	P* temp = this->first;
    	for (int index = 0; index < this->n; ++index) {
    		if (*(temp->data) == data){
                cout << "Number " << data << " was found on the list!!\n" << endl; //mensaje de exito
    			return *temp;
            }
            if (temp->next != nullptr) 
                temp = &(next(*temp));
    	}

        cout << "Number " << data << " was not found on the list...\n" << endl; //mensaje que no se encontro
    }

    /*! \brief Metodo encontrar el dato de la celda que se pasa como parametro.
     *
     *  \param cell La celda de la cual ocupamos encontrar el dato.
     *  \return Referencia del dato que contiene cell.
     */ 
    D& get(P& cell) { 
        return *(cell.data);
    }

    /*! \brief Metodo para encontrar el tamanno de la lista.
     *
     *  \return Un entero con el numero de elementos que tiene la lista.
     */ 
    int getSize() {
        return this->n;
    } 

    /*! \brief Metodo para imprimir la lista.
     */ 
    void printList() {
        //si la lista esta vacia, se  imprime dicha situacion
        if (this->n == 0)
            cout << "List is empty..!" << endl;
        else {
            P* temp = this->first;
            cout << "Printing list: "; //mensaje de que se va a imprimir la lista
            for (int index = 0; index < this->n; ++index) {
                cout << get(*temp) << "  ";
                if (temp->next != nullptr) 
                	temp = &(next(*temp));
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

    /*! \brief Metodo para encontrar la celda previa a una dada.
     *
     *  \param cell La celda de la cual que quiere la celda previa.
     *  \return Referencia de la celda previa a cell.
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
                    cout << "Previous to: " << *(cell.data) << "\t\tis: " << *(prev->data) << endl; //mensaje
                    return *(prev);
                }
            }
        }
    }

    /*! \brief Metodo para vaciar la lista.
     */ 
    void emptyList() {
    	cout << "Emptying list..." << endl; //mensaje de que se esta vaciando la lista.
    	erase(this->first);
    	this->n = 0;
    }

    /*! \brief Metodo auxiliar para vaciar la lista. Trabaja recursivamente.
     */ 
    void erase(P* k) {
    	if (k->data != nullptr && k->next != nullptr) {
    		erase(k->next);//llamado recursivo.
    		delete k; //eliminacion de la celda k.
    	}
    }

    /*! \brief Metodo para assignarle el datto d a la celda k.
     *
     *  \param d El dato que se quiere asignar.
     *  \param k Celda a la que se le quiere asignarr este dato.
     */ 
    void assign(P& k, D d) {
        *(k.data) = d;
    }

    /*! \brief Metodo auxiliar para probar assign.
     *
     *  \param d El dato que se quiere asignar.
     */ 
    void testAssign (D d) {
        cout << "Assigning " << d << " to the first cell of the list:" << endl; //mensaje de asignacion.
        assign(*(first), d);
    }

    /*! \brief Metodo para ordenar la lista. Se usa el algoritmo bubble sort.
     */ 
    void sort() {
        cout << "Sorting list:" << endl; //mensaje de que se esta ordenando la lista

        if (first != nullptr) {
            P* current = first;
            P* prev = nullptr;
            P* temp = nullptr;
            int flag = 0;
            for (int i = 0; i < this->n; i++) {
                while (current->next != nullptr) {
                    temp = current->next;
                    if(*(current->data) > *(temp->data)) {
                        flag = 1;
                        current->next = temp->next;
                        temp->next = current;
                        if (prev != nullptr) 
                            prev->next = temp;
                        prev = temp;
                        if (current == first)
                            first= temp;
                        if (current->next == nullptr)
                            last = current;
                    }
                    else {
                        prev = current;
                        current = current->next;
                    }
                }
                if (flag == 0)
                    break;
                else {
                    prev = nullptr;
                    current = first;
                    flag = 0;
                }
            }
        }     
    }


    /*! \brief Metodo para obtener el dato de una posicion especifica/
     *
     *  \param pos Posicion de la celda en la lista, empezando desde 0.
     *  \return Referencia del dato que se pide.
     */ 
    D& getDataPos(int pos) {
        P* temp = this->first;

        for (int index = 0; index < pos; ++index) {
            if (temp->next != nullptr)
                temp = &(next(*temp));
        }
        return get(*temp);
    }

};
#endif // LISTWITHPOINTER_H