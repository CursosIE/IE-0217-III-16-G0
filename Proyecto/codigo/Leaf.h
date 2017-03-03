#ifndef LEAF_H
#define LEAF_H

#include <iostream>

#include "Node.h"
using namespace std;
//BST node

template <typename Data>
class Leaf : public Node<Data> {
public:

    Data* arrayData;

    Leaf() {
        this->father = nullptr;
        this->order = 0;
        this->arrayKeys = nullptr;
        this->arrayPtrs = nullptr;
        this->arrayData = nullptr;
        this->isLeaf = 1;
    }

    Leaf(int order) {
        this->father = nullptr;
        this->isLeaf = 1;
        this->order = order;
        this->arrayKeys = new int[order];
        this->arrayPtrs = nullptr;
        this->arrayData = new Data[order];
        for (int index = 0; index < order; ++index)
                this->arrayKeys[index] = -1;
    }

    Leaf(int order, Node<Data>* father) {
        this->father = father;
        this->isLeaf = 1;
        this->order = order;
        this->arrayKeys = new int[order];
        this->arrayPtrs = nullptr;
        this->arrayData = new Data[order];
    }

    virtual ~Leaf() {
        delete[] this->arrayKeys;
        delete[] this->arrayData;
    }

};

#endif /* LEAF_H */
