#ifndef LEAF_H
#define LEAF_H

#include <iostream>
using namespace std;
//BST node

template <typename D>
class Leaf : public Node<D> {
public:

    D* arrayData;

    Node() {
        order = 0;
        arrayKeys = nullptr;
        arrayPtrs = nullptr;
        arrayData = nullptr;
    }

    Node(int order) {
        this->order = order;
        arrayKeys = nullptr
        arrayPtrs = nullptr;
        arrayData = new D[order];
    }

    virtual ~Node() {
        delete[] arrayData;
    }

};

#endif /* LEAF_H */

