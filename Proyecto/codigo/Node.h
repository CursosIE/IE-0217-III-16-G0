#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
//B+Tree node

template <typename Data>
class Node {
public:

    int order;
    int* arrayKeys;
    Node<Data>** arrayPtrs;

    Node() {
        order = 0;
        arrayKeys = nullptr;
        arrayPtrs = nullptr;
    }

    Node(int order) {
        this->order = order;
        arrayKeys = new int[order];
        arrayPtrs = new Node<Data>*[order + 1];
    }

    virtual ~Node() {
        delete[] arrayKeys;
        delete[] arrayPtrs;
    }

};

#endif /* NODE_H */
