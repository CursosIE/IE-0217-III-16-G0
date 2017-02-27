#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <cmath> 
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

    BPlusTree(int order) {
        this->levels = 0;
        this->order = order;
        this->root = new Leaf<Data>(order);
    }

    virtual ~BPlusTree() {

    }

    /*void fillTree (int order, int levels, Node<Data>** array) {
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
    }*/

    void insert (int key) {
        //caso cuando root esta vacio
        if (this->root->elements == 0) {
            this->root->arrayKeys[0] = key;
            this->root->elements += 1;
        }
        //caso cuando root todavia no esta llena y no tiene hijos
        else if (this->levels == 0 && this->root->elements < order) {
            this->root->arrayKeys[this->root->elements] = key;
            this->root->elements += 1;
            sort(this->root->arrayKeys, this->root->elements); 
        }
        else {
            //CASO CUANDO ROOT ESTA LLENO Y HAY QUE HACER SPLIT


        }
    }

    void auxInsert(int key, Node<Data>* node) {
        if (!node->isLeaf) {
            auxInsert(key, node->arrayPtrs[pointerToGo(key, node)]);
        }
        else {
            //LLEGO A UNA HOJA
            if (node->elements < order) {
                node->arrayKeys[node->elements] = key;
                node->elements += 1;
                sort(node->arrayKeys, node->elements);
            }
            else {
                //SPLIT
                split(key, node);
            }
        }
    }

    void split (int key, Node<Data>* node) {
        int* arrayWNewKey = midKey(node->arrayKeys, key);
        Node<Data>* newNode;

        int* leftSplit[this->order];
        int* rightSplit[this->order];
        //hacemos el split y los ponemos en leftSplit y rightSplit
        for (int index = 0; index < order + 1; ++index){
            if (index < (order + 1) / 2)
                leftSplit[index] = arrayWNewKey[index];
            else
                rightSplit[index - ((order + 1) / 2)] = arrayWNewKey[index];
        }

        //si lo que se splitea es una hoja o un nodo interno
        if (node->isLeaf) {
            newNode = new Leaf<Data>(this->order);
            newNode->arrayKeys = rightSplit;
            newNode->elements = ceil((this->order + 1) / 2);
            newNode->father = node->father;
        }
        else {
            newNode = new Node<Data>(this->order);
            newNode->arrayKeys = rightSplit;
            newNode->elements = ceil((this->order + 1) / 2);
            newNode->father = node->father;
        }
        node->arrayKeys = leftSplit;
        node->elements = floor((this->order + 1) / 2);

        //HASTA AQUI TENEMOS LOS 2 VECTORES SPLITEADOS
        if (node->father->elements < this->order) {
            insertSortAndMvPointers(node->father, arrayWNewKey[ceil((this->order + 1) / 2)], node, newNode);
        }
        else
            split (arrayWNewKey[ceil((this->order + 1) / 2)], node->father);
            //Arreglar los punteros de los nodos que quedan perdidos.

    }

    void insertSortAndMvPointers(Node<Data>* node, int key, Node<Data>* left, Node<Data>* right) {
        node->arrayKeys[node->elements] = key;
        node->elements += 1;
        specialSort(node->father->arrayKeys, node->father->arrayPtrs, left, right, node->father->elements);
    }

    int pointerToGo(int key, Node<Data>* node) {
        for (int index = 0; index < node->elements; ++index) {
            if (node->arrayKeys[index] > key)
                return index;
        }
        return node->elements;
    }

    //@return array ordered array with new key
    int* midKey(int* keys, int newKey) {
        int* array [order];
        for (int index = 0; index <= order; ++index) {
            if (index != order)
                array[index] = keys[index];
            else
                array[index] = newKey;
        }
        
        sort(array, order + 1);

        //return array[ceil(order / 2)];
        return array;
    }

    void newRoot(int key, Node<Data>* left, Node<Data>* right) {
        Node<Data>* node = new Node<Data>(this->order);
        node->arrayKeys[0] = key;
        node->arrayPtrs[0] = left;
        node->arrayPtrs[1] = right;
        this->root = node;
    }

    void sort (int* array, int size) {
        int temp = 0;
        int posMin = 0;
        //primer for de ordenamiento
        for (int n = 0; n < size - 1; n++){
            posMin = n;
            //segundo for de ordenamiento
            for (int m = n + 1; m < size; m++) {
                if (array[m] < array[posMin]) 
                    posMin = m;
            }
            //intercambio de valores en caso de que haya que ordenar
            if (posMin != n) {
                temp = array[n];
                array[n] = array[posMin];
                array[posMin] = temp;
            }
        }
    }

    void specialSort (int* array, Node<Data>** arrayPtrs, Node<Data>* left, Node<Data>* rigth, int size) {
        int temp = 0;
        int posMin = 0;
        Node<Data>* tempPtr1 = nullptr;
        //primer for de ordenamiento
        for (int n = 0; n < size - 1; n++){
            posMin = n;
            //segundo for de ordenamiento
            for (int m = n + 1; m < size; m++) {
                if (array[m] < array[posMin]) 
                    posMin = m;
            }
            //intercambio de valores en caso de que haya que ordenar
            if (posMin != n) {
                temp = array[n];
                array[n] = array[posMin];
                array[posMin] = temp;
                //cambio punteros
                for (int index = posMin + 2; index < size + 1; ++index) 
                    arrayPtrs[index] = arrayPtrs[index - 1];
                
                arrayPtrs[posMin] = left;
                arrayPtrs[posMin + 1] = rigth;
            }
        }
    }

    // *Node find (Data& data) {
    //     return tree_search(this->root, data);
    // }

    // Node<Data>* treeSearch (Node<Data>* node, Data data) {
    //     if (node->isLeaf) 
    //         return node;
    //     else {

    //     }
    // }


};

#endif /* BPLUSTREE_H */
