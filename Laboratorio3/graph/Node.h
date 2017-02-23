#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "Edge.h"
#include "Listas/ListWithPointers.h"
#include "MyInt.h"

using namespace std;

template <typename D>
class Node {
   public:
    D* Data;
    ListWithPointer<MyInt, Cell<Edge<D> > >* list;

    Node() {
        Data = nullptr;
        list = new ListWithPointer<MyInt, Cell<Edge<D> > >();
    }

    Node(D* data) {
        this->data = data;
        list = new ListWithPointer<MyInt, Cell<Edge<D> > >();
    }

    void addEdge(Edge edge) {
        this->list->insert(edge);
    }
    
    virtual ~Node() {
        delete Data;
    }
};

#endif /* NODE_H */
