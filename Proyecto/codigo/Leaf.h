#ifndef LEAF_H
#define LEAF_H

#include <iostream>
using namespace std;
//BST node

template <typename D>
class Leaf : public Node<D> {
public:

    D* arrayData;

    Leaf() {
        this->order = 0;
        this->arrayKeys = nullptr;
        this->arrayPtrs = nullptr;
        this->arrayData = nullptr;
    }

    Leaf(int order) {
        this->order = order;
        this->arrayKeys = nullptr;
        this->arrayPtrs = nullptr;
        this->arrayData = new D[order];
    }

    virtual ~Leaf() {
        delete[] this->arrayData;
    }

};

#endif /* LEAF_H */
