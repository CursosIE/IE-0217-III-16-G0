#ifndef LEAF_H
#define LEAF_H

#include <iostream>
using namespace std;
//BST node

template <typename Data>
class Leaf : public Node<Data> {
public:

    Data* arrayData;

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
        this->arrayData = new Data[order];
    }

    virtual ~Leaf() {
        delete[] this->arrayData;
    }

};

#endif /* LEAF_H */
