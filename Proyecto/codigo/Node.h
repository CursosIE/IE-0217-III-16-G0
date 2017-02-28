#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
//B+Tree node

template <typename Data>
class Node {
public:
    int elements;
    int order;
    int isLeaf;
    int* arrayKeys;
    Node<Data>** arrayPtrs;
    Node<Data>* father;
    Node<Data>* right;
    

    Node() {
        order = 0;
        this->father = nullptr;
        this->arrayKeys = nullptr;
        this->arrayPtrs = nullptr;
        right = nullptr;
        isLeaf = 0;
        this->elements = 0;
    }

    Node(int order) {
        this->father = nullptr;
        this->order = order;
        arrayKeys = new int[order];
        arrayPtrs = new Node<Data>*[order + 1];
        for (int index = 0; index < order + 1; ++index) {
            arrayPtrs[index] = nullptr;
            if (index < order)
                arrayKeys[index] = -1;
        }
        isLeaf = 0;
        this->elements = 0;
    }

    Node(int order, Node<Data>* father) {
        this->order = order;
        this->father = father;
        arrayKeys = new int[order];
        arrayPtrs = new Node<Data>*[order + 1];
        isLeaf = 0;
    }

    virtual ~Node() {
        delete[] arrayKeys;
        delete[] arrayPtrs;
    }

};

#endif /* NODE_H */
