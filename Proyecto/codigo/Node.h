#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
//B+Tree node

template <typename D>
class Node {
public:

    int order;
    int* arrayKeys;
    Node<D>* arrayPtrs;

    Node() {
        order = 0;
        arrayKeys = nullptr;
        arrayPtrs = nullptr;
    }

    Node(int order) {
        this->order = order;
        arrayKeys = new int[order];
        arrayPtrs = new Node<D>[order + 1];
    }

    virtual ~Node() {

    }

};

#endif /* NODE_H */

