#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <iostream>

#include "Node.h"
#include "Leaf.h"

using namespace std;

template <typename Data>
class BPlusTree {
   public:
    Node<Data>* root;
    int levels;
    int order;

   public:

    BPlusTree() {
        root = nullptr;
        this->levels = 0;
        this->order = 0;
    }

    BPlusTree(int order, int levels) {
        this->order = order;
        this->levels = levels;
        this->root = new Node<Data>(order);
        fillTree(order, levels - 1, this->root->arrayPtrs);
    }

    BPlusTree(const BPlusTree& orig) {
    }

    virtual ~BPlusTree() {

    }

    void fillTree (int order, int levels, Node<Data>** array) {
        if (levels != 1) {
            for (int index = 0; index < order + 1; ++index) {
                array[index] = new Node<Data>(order);
                fillTree(order, levels - 1, array[index]->arrayPtrs);
            }
        }
        else {
           for (int index = 0; index < order + 1; ++index) {
                array[index] = new Leaf<Data>(order);
            }
        }
    }

};

#endif /* BPLUSTREE_H */
