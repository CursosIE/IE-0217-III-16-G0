
#ifndef LISTA_H
#define LISTA_H

template <typename D, typename P>
class List {
public:

    List() {
    }

    List(const List& orig) {
    }

    virtual ~List() {
    }

    virtual void insert(D d) = 0; //insertar
    virtual void remove(D d) = 0; //remover
    virtual P find(D d) = 0; //buscar
    virtual D& get(P& k) = 0; //obtener
    virtual void assign(P& k, D d) = 0; //asignar
    virtual void sort() = 0; //ordenar
    virtual int getSize() = 0; //tamaño
    virtual void printList() = 0; //imprimir
    virtual P& next(P& k) = 0; //siguiente
    virtual P prev(P k) = 0; //anterior
    virtual void emptyList() = 0; //vaciar
    // virtual D getLast() = 0; //devuele el dato de la ultima celda

protected:
    int n; //num. elementos
};

#endif /* LISTA_H */

