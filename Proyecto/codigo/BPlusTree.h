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
            auxInsert(key, root);
        }
    }

    void auxInsert(int key, Node<Data>* node) {
        //cout << "LLegó a auxInsert..!" << endl;

        if (!node->isLeaf) {
            auxInsert(key, node->arrayPtrs[pointerToGo(key, node)]);
        }
        else {
            //cout << "Entró a el ELSE que dice que ES una hoja..!" << endl;
            //LLEGO A UNA HOJA
            if (node->elements < order) {
                node->arrayKeys[node->elements] = key;
                node->elements += 1;
                sort(node->arrayKeys, node->elements);
            }
            else {
                //cout << "Vamos a hacer SPLIT!!!" << endl;
                //SPLIT
                split(key, node);
            }
        }
    }

    void split (int key, Node<Data>* node) {
        int* arrayWNewKey = midKey(node->arrayKeys, key);

        // //////////////////////////////
        // cout << "arrayWNewKey: ";
        // for (int index = 0; index < this->order + 1; ++index) {
        //     cout << arrayWNewKey[index] << "  "; 
        // }
        // cout << endl;
        // ///////////////////////////////
        

        Node<Data>* newNode;

        int* leftSplit = new int[this->order];
        int* rightSplit = new int[this->order];

        for (int index = 0; index < this->order; ++ index) {
            leftSplit[index] = -1;
            rightSplit[index] = -1;
        }
        //hacemos el split y los ponemos en leftSplit y rightSplit
        for (int index = 0; index < order + 1; ++index){
            if (index < (order + 1) / 2)
                leftSplit[index] = arrayWNewKey[index];
            else
                rightSplit[index - ((order + 1) / 2)] = arrayWNewKey[index];
        }
        //cout << "Hizo el for después de leftSplit y rightSplit" << endl;

        // //////////////////////////////
        // cout << "leftSplit: ";
        // for (int index = 0; index < this->order; ++index) {
        //     cout << leftSplit[index] << "  "; 
        // }
        // cout << endl;
        // ///////////////////////////////

        // //////////////////////////////
        // cout << "rightSplit: ";
        // for (int index = 0; index < this->order; ++index) {
        //     cout << rightSplit[index] << "  "; 
        // }
        // cout << endl;
        // ///////////////////////////////

        //si lo que se splitea es una hoja o un nodo interno
        if (node->isLeaf) {
            newNode = new Leaf<Data>(this->order);
            newNode->arrayKeys = rightSplit;
            newNode->elements = (int)ceil((this->order + 1) / 2);
            //Revisar que pasa si es el root y no tiene padre.
            if (node != this->root)
                newNode->father = node->father;
        }
        else {
            newNode = new Node<Data>(this->order);
            newNode->arrayKeys = rightSplit;
            newNode->elements = (int)ceil((this->order + 1) / 2);
            if (node != this->root)
                newNode->father = node->father;
        }
        //cout << "Hizo el nuevo nodo u hoja..!" << endl;
        node->arrayKeys = leftSplit;
        node->elements = (int)floor((this->order + 1) / 2);

        //cout << "right elements: " << newNode->elements << endl;
        //cout << "left elements: " << node->elements << endl;

        fixNewNodePointers(node, newNode);

        // cout << "right elements: " << newNode->elements << endl;
        // cout << "left elements: " << node->elements << endl;

        // //////////////////////////////
        // cout << "node: ";
        // for (int index = 0; index < this->order; ++index) {
        //     cout << node->arrayKeys[index] << "  "; 
        // }
        // cout << endl;
        // ///////////////////////////////
        // //////////////////////////////
        // cout << "newNode: ";
        // for (int index = 0; index < this->order; ++index) {
        //     cout << newNode->arrayKeys[index] << "  "; 
        // }
        // cout << endl;
        // ///////////////////////////////

        //cout << "Corrió fixNewNodePointers!!" << endl;

        //HASTA AQUI TENEMOS LOS 2 VECTORES SPLITEADOS

        //Revisar los elementos de node y newNode.        

        //Reviso si estoy haciendo split al root, para crear un root nuevo.

        if(node == this->root) {
            //cout << "Entró al: if(node == this->root) //line 135" << endl;
            this->levels += 1;
            Node<Data>* newRoot = new Node<Data>(this->order);

            newRoot->arrayKeys[0] = arrayWNewKey[(int)ceil((this->order + 1) / 2)];
            newRoot->elements += 1;
            newRoot->arrayPtrs[0] = node;
            newRoot->arrayPtrs[1] = newNode;

            this->root = newRoot;
            this->root->arrayPtrs[0]->father = this->root;
            this->root->arrayPtrs[1]->father = this->root;

            // //////////////////////////////
            // cout << "hijo izq: ";
            // for (int index = 0; index < this->order; ++index) {
            //     cout << this->root->arrayPtrs[0]->arrayKeys[index] << "  "; 
            // }
            // cout << endl;
            // ///////////////////////////////

            // //////////////////////////////
            // cout << "hijo der: ";
            // for (int index = 0; index < this->order; ++index) {
            //     cout << this->root->arrayPtrs[1]->arrayKeys[index] << "  "; 
            // }
            // cout << endl;
            // ///////////////////////////////

        } else {
            if (node->father->elements < this->order) {
                // cout << "Entró al  if (node->father->elements < this->order).." << endl;
                // cout << "Voy para  insertSortAndMvPointers" << endl;
                insertSortAndMvPointers(node, arrayWNewKey[(int)ceil((this->order + 1) / 2)], node, newNode);
                // cout << "Hizo insertSortAndMvPointers" << endl;
            } else {
                split (arrayWNewKey[(int)ceil((this->order + 1) / 2)], node->father);
                fixPointers(node->father, node, newNode);
            }
        }
    }

    void fixNewNodePointers (Node<Data>* old, Node<Data>* newOne) {
        for (int index = 0; index < this->order + 1; ++index) {
            //cout << index << "  " << endl;
            //cout << "old elements: " << old->elements << endl;
            if (index >= old->elements) {
                //cout << "index - old->elements + 1 = " <<index - old->elements + 1 << endl;
                if (old->arrayPtrs != nullptr) {
                    newOne->arrayPtrs[index - old->elements + 1] = old->arrayPtrs[index];
                    old->arrayPtrs[index] = nullptr;
                }
            }
        }
    }

    void insertSortAndMvPointers(Node<Data>* node, int key, Node<Data>* left, Node<Data>* right) {
        node->father->arrayKeys[node->father->elements] = key;
        node->father->elements += 1;
        //cout << "Voy para specialSort" << endl;
        //cout << this->root << endl;
        //cout << node->father << endl;
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
        int* array = new int[order];
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

    void fixPointers(Node<Data>* node, Node<Data>* left, Node<Data>* right) {
        for (int index = 0; index < this->order; index++) {
            if (node->arrayKeys[index] >= right->arrayKeys[0]) {
                if(node->arrayKeys[index] == right->arrayKeys[0]) {
                    node->arrayPtrs[index] = left;
                    node->arrayPtrs[index + 1] = right;
                } else {
                    node->arrayPtrs[index - 1] = left;
                    node->arrayPtrs[index] = right;
                }
                return;
            }
        }
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
                if (array[m] < array[posMin] && array[m] > -1 && array[posMin] > -1)
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

    void specialSort (int* array, Node<Data>** arrayPtrs, Node<Data>* left, Node<Data>* right, int size) {
        Node<Data>* temp1;
        int toFind = array[size - 1];
        //cout << "Array: ";
        // for (int index = 0; index < size; ++index)
        //     cout << array[index];
        bool estabaOrdenado = true;
        //cout << "Empieza specialSort..!" << endl;

        // //////////////////////////////
        // cout << "left: ";
        // for (int index = 0; index < this->order; ++index) {
        //     cout << left->arrayKeys[index] << "  "; 
        // }
        // cout << endl;
        // ///////////////////////////////
        // //////////////////////////////
        // cout << "right: ";
        // for (int index = 0; index < this->order; ++index) {
        //     cout << right->arrayKeys[index] << "  "; 
        // }
        // cout << endl;
        // ///////////////////////////////

        int temp = 0;
        int posMin = 0;
        //primer for de ordenamiento
        for (int n = 0; n < size - 1; n++){
            posMin = n;
            //segundo for de ordenamiento
            for (int m = n + 1; m < size; m++) {
                if (array[m] < array[posMin]  && array[m] > -1 && array[posMin] > -1)
                    posMin = m;
            }
            //intercambio de valores en caso de que haya que ordenar
            if (posMin != n) {
                estabaOrdenado = false;
                //cout << "Entró al  if (posMin != n)" << endl;
                temp = array[n];
                array[n] = array[posMin];
                array[posMin] = temp;
                //cambio punteros
                // cout << "size: " << size << endl;
                // cout << "posMin: " << posMin << endl;
                // cout << "n: " << n << endl;
                
                temp1= arrayPtrs[posMin + 1];
                arrayPtrs[posMin + 1] = arrayPtrs[n + 1];
                arrayPtrs[n + 1] = temp1;  
            }
        }
        if (estabaOrdenado)
            arrayPtrs[size] = right;
        else {
            for (int index = 0; index < size; ++index) {
                if (array[index] == toFind) {
                    arrayPtrs[index] = left;
                    arrayPtrs[index + 1] = right;
                }
            }
        }
    }

    void printTree () {
        auxPrint(this->root, 1, -1);
    }

    void auxPrint(Node<Data>* node, int level, int index) {
        if (node->isLeaf) {
            cout << "Level: " << level << endl;
            cout << "Father: " << node->father << endl;
            cout << "Father index ptr: " << index << endl;
            cout << node << ":  ";
            for (int keysIndex = 0; keysIndex < node->elements; ++keysIndex){
                cout << node->arrayKeys[keysIndex] << "  ";
            }
            cout << "\n" << endl;
        }
        else {
            for (int index = 0; index < node->elements + 1; ++index) {
                if (node->arrayPtrs[index] != nullptr)
                    auxPrint(node->arrayPtrs[index], level + 1, index);  
            }

            cout << "Level: " << level << endl;
            if (node != this->root){
                cout << "Father: " << node->father << endl;
                cout << "Father index ptr: " << index << endl;
            }
            else
                cout << "Root: " << endl;
            cout << node << ":  ";
            for (int keysIndex = 0; keysIndex < node->elements; ++keysIndex){
                    cout << node->arrayKeys[keysIndex] << "  ";
                }
            cout << "\n" << endl;
        }
    }

    void find (int key) {
        auxFind(key, this->root);
    }

    void auxFind (int key, Node<Data>* node) {
        if (node->isLeaf) {
            for (int index = 0; index < node->elements; ++index) {
                if (key == node->arrayKeys[index]) 
                    cout << key << " Was found!!!" << endl;
            }
        }
        else {
            for (int index = 0; index < node->elements; ++index) {
                if (node->arrayKeys[index] > key)
                    auxFind(key, node->arrayPtrs[index]);

                else if (index == node->elements -1)
                    auxFind(key, node->arrayPtrs[index + 1]);
            }
        }
    }
};

#endif /* BPLUSTREE_H */
