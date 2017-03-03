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
        delete root;
    }

    void insertAk7 (int key) {
        auxInsertAk7(key, this->root);
    }

    void auxInsertAk7 (int key, Node<Data>* node) {
        if(node->isLeaf == 1){ //pregunto si es una HOJA
            if (node->elements < this->order) { //caso en que haya campo en la hoja
                node->arrayKeys[node->elements] = key;
                node->elements += 1;
                sort(node->arrayKeys, node->elements);
            }
            else {
                splitAk7(node, key, nullptr, nullptr);
            }
        }
        else {
            //cout << "pointerToGo: " << pointerToGo(key, node) << endl;
            auxInsertAk7(key, node->arrayPtrs[pointerToGo(key, node)]);
        }
    }

    void splitAk7 (Node<Data>* node, int key, Node<Data>* oldSon, Node<Data>* newSon) {
        //cout << "Entro a SplitAk7.." << endl;
        int* arrayToSplit = arrayToSplitFunc(node, key);

        int* leftSplit = new int[this->order];
        int* rightSplit = new int[this->order];

        Node<Data>* newNode;

        for (int index = 0; index < this->order; ++ index) {
            leftSplit[index] = -1;
            rightSplit[index] = -1;
        }

        //llena leftSplit y rightSplit
        for (int index = 0; index < this->order + 1; ++ index) {
            if (index < (order + 1) / 2)
                leftSplit[index] = arrayToSplit[index];
            else
                rightSplit[index - ((order + 1) / 2)] = arrayToSplit[index];
        }

        //cout << "llena left y right" << endl;

        //si es una hoja que no quede en el medio
        if (node->isLeaf == 0) {
            deleteFirstElement(rightSplit, this->order);
            //cout << "deleteFirstElement" << endl;
        }

        //creamos la nueva hoja o nodo, donde va a ir rightSplit
        if (node->isLeaf == 1)
            newNode = new Leaf<Data>(this->order);
        else
            newNode = new Node<Data>(this->order);

        //le decimos a newNode quien es su padre
        if (node != this->root)
            newNode->father = node->father;

        //asignamos las keys correctas a los nodos
        node->arrayKeys = leftSplit;
        newNode->arrayKeys = rightSplit;

        //asignamos la cantidad de elementos
        node->elements = amountElements(node->arrayKeys, this->order);
        newNode->elements = amountElements(newNode->arrayKeys, this->order);
        //cout << "amountElements" << endl;


        //cout << node->isLeaf << endl;

        if(node->isLeaf == 0) {
            //arreglar los punteros
            assignDownwardPtrs(node, newNode, oldSon, newSon, key);
            //cout << "assignDownwardPtrs" << endl;
            //papas
            fatherPtrs(node);
            fatherPtrs(newNode);
            //cout << "fathers..." << endl;
        }

        if(node == this->root) {
            //cout << "Entró al: if(node == this->root) //line 135" << endl;
            this->levels += 1;
            Node<Data>* newRoot = new Node<Data>(this->order);

            newRoot->arrayKeys[0] = arrayToSplit[(int)floor((this->order + 1) / 2)];
            newRoot->elements += 1;
            newRoot->arrayPtrs[0] = node;
            newRoot->arrayPtrs[1] = newNode;

            this->root = newRoot;
            this->root->arrayPtrs[0]->father = this->root;
            this->root->arrayPtrs[1]->father = this->root;
            //cout << "Salió al: if(node == this->root) //line 135" << endl;
        }
        else {
            //cout << "antes del if" << endl;
            if(node->father->elements < this->order){
                node->father->arrayKeys[node->father->elements] = arrayToSplit[(int)floor((this->order + 1) / 2)];
                node->father->elements += 1;
                //cout << node->father->arrayKeys << endl;
                //cout << node->father->arrayPtrs << endl;
                //cout << node << endl;
                //cout << newNode << endl;
                specialSort(node->father->arrayKeys, node->father->arrayPtrs, node, newNode, node->father->elements);
                //cout << "specialSort" << endl;
            }
            else
                splitAk7(node->father, arrayToSplit[(int)floor((this->order + 1) / 2)], node, newNode);
        }
    }

    int pointerToGo(int key, Node<Data>* node) {
        for (int index = 0; index < node->elements; ++index) {
            if (node->arrayKeys[index] > key)
                return index;
        }
        return node->elements;
    }

    int* arrayToSplitFunc(Node<Data>* node, int key) {
        int* array = new int[this->order + 1];
        for (int index = 0; index < this->order + 1; ++index) {
            if (index < order)
                array[index] = node->arrayKeys[index];
            else
                array[index] = key;
        }
        sort(array, order + 1);
        return array;
    }

    void deleteFirstElement(int* array, int  size) {
        for (int index = 0; index < size - 1; ++index)
            array[index] = array[index + 1];
        array[size - 1] = -1;
    }

    int amountElements (int* array, int size) {
        int result = 0;
        for (int index = 0; index < size; ++index) {
            if (array[index] != -1)
                result += 1;
        }
        return result;
    }

    void assignDownwardPtrs(Node<Data>* old, Node<Data>* newOne, Node<Data>* oldSon, Node<Data>* newSon, int key) {
        int continu = 0;
        //cout << "se metio a assignDownwardPtrs..." << endl;

        for (int ptrIndex = 0; ptrIndex < this->order + 1; ++ ptrIndex) {
            if (continu != 1) {
                for (int oldIndex = 0; oldIndex < this->order; ++oldIndex) {
                    if (old->arrayPtrs[ptrIndex]->arrayKeys[0] < old->arrayKeys[oldIndex]) {
                        old->arrayPtrs[oldIndex] = old->arrayPtrs[ptrIndex];
                        break;
                    }
                    else {
                        if (old->arrayKeys[oldIndex] == -1) {
                            old->arrayPtrs[oldIndex] = old->arrayPtrs[ptrIndex]; //agregamos esta union.
                            continu = 1;
                            ptrIndex -= 1;
                            break;
                        }
                    }
                }
            }
            else {
                for (int oldIndex = 0; oldIndex < this->order; ++oldIndex) {
                    if (old->arrayPtrs[ptrIndex]->arrayKeys[0] < newOne->arrayKeys[oldIndex]) {
                        newOne->arrayPtrs[oldIndex] = old->arrayPtrs[ptrIndex];
                        if (ptrIndex > old->elements)
                            old->arrayPtrs[ptrIndex] = nullptr; //Debo hacer nulo a partir del +1
                        break;
                    }
                    else {
                        if (newOne->arrayKeys[oldIndex] == -1) {
                            newOne->arrayPtrs[oldIndex] = old->arrayPtrs[ptrIndex];
                            //ptrIndex == this->order + 1;
                            break;
                        }
                    }
                }
            }

        }

        int keyPosition = 0;

        if (old->arrayKeys[old->elements - 1] < key){
            keyPosition = positionOfKey(key, newOne);
            newOne->arrayPtrs[keyPosition + 1] = newSon;
        }
        else{
            keyPosition = positionOfKey(key, old);
            old->arrayPtrs[keyPosition + 1] = newSon;
        }

        //cout << old->arrayPtrs[1]->arrayKeys[0] << " " << old->arrayPtrs[2]->arrayKeys[1] << " " << old->arrayPtrs[2]->arrayKeys[2] << endl;

    }

    int positionOfKey (int key, Node<Data>* node) {
        for(int index = 0; index < node->elements; ++index) {
            if (node->arrayKeys[index] == key)
                return index;
        }
        return -1;
    }

    void fatherPtrs(Node<Data>* node) { //ese node va a ser newNode
        if (node->arrayPtrs != nullptr) {
            for(int index = 0; index < node->elements + 1; ++index) {
                if (node->arrayPtrs[index] != nullptr) {
                    //cout << "Father: " << node->arrayPtrs[index]->father
                    //<< "   Son: " << node->arrayPtrs[index] << endl;
                    node->arrayPtrs[index]->father = node;
                }
            }
        }
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
        //cout << "Se metio a specialSort" << endl;
        Node<Data>* temp1;
        int toFind = array[size - 1];

        bool estabaOrdenado = true;

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
                temp = array[n];
                array[n] = array[posMin];
                array[posMin] = temp;

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

    void deleteAk7(int key) {
        auxDelete(key, this->root);
    }

    void auxDelete(int key, Node<Data>* node) {
        if(node->isLeaf == 0)
            auxDelete(key, node->arrayPtrs[pointerToGo(key, node)]);
        else {
            for(int index = 0; index < node->elements; index++) {
                if(node->arrayKeys[index] == key) {
                    if(node->elements-1 > this->order/2) {
                        node->arrayKeys[index] = -1;
                        sortWithMinusOne(node->arrayKeys, this->order);
                        node->elements -= 1;
                        if(index == 0)
                            deleteFromFather(node->father, key, node->arrayKeys[0]);
                        break;
                    } else {
                        Node<Data>* Sibling = findMySibling(node, node->arrayKeys[0]);
                        if(Sibling->elements - 1 > this->order/2)
                            keyFromSibling(key, node, Sibling);
                        else
                            merge(key, node);
                    }
                }
            }
        }
    }

    void merge(int key, Node<Data>* node) {

    }

    void keyFromSibling(int key, Node<Data>* node, Node<Data>* Sibling) {
            int siblingKey = Sibling->arrayKeys[Sibling->elements - 1];
            Sibling->arrayKeys[Sibling->elements - 1] = -1;
            Sibling->elements -= 1;
            for (int index = 0; index < node->elements; index++) {
                if(node->arrayKeys[index] == key) {
                    int tempKey = node->arrayKeys[0];
                    node->arrayKeys[index] = siblingKey;
                    sort(node->arrayKeys, this->order);
                    deleteFromFather(node->father, tempKey, node->arrayKeys[0]);
                }
            }
    }

    Node<Data>* findMySibling(Node<Data>* node, int key) {
        if(this->root != node){
            Node<Data>* fatherSibling;

            for (int index = 0; index < node->father->elements; index++) {
                if(node->father->arrayKeys[index] == key)
                    return node->father->arrayPtrs[index];
            }

            fatherSibling = findMySibling(node->father, key);

            if(fatherSibling != nullptr)
                return fatherSibling->arrayPtrs[fatherSibling->elements];
            else
                return nullptr;
        } else
            return nullptr;
    }

    void deleteFromFather(Node<Data>* node, int key, int newKey) {
        for(int index = 0; index < node->elements; index++) {
            if(node->arrayKeys[index] == key) {
                node->arrayKeys[index] = newKey;
                return;
            }
        }
        if(this->root != node)
            deleteFromFather(node->father, key, newKey);
    }

    void sortWithMinusOne(int* array, int size) {
    	int temp = 0;
    	for (int index = 0; index < size; index++) {
    		if(array[index] == -1) {
    			temp = index;
    			for (int indexMove = index; indexMove < size - 1; indexMove++) {
    				temp = array[indexMove + 1];
    				array[indexMove + 1] = array[indexMove];
    				array[indexMove] = temp;
    			}
    			break;
    		}
    	}
    }

    void printTree () {
        auxPrint(this->root, 1, -1);
    }

    void auxPrint(Node<Data>* node, int level, int index) {
        if (node->isLeaf) {
            cout << "Leaf!!" << endl;
            cout << "Elements: " << node->elements << endl;
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
                cout << "Node!!" << endl;
                cout << "Father: " << node->father << endl;
                cout << "Father index ptr: " << index << endl;
            }
            else
                cout << "Root: " << endl;
            cout << "Elements: " << node->elements << endl;
            cout << node << ":  ";
            for (int keysIndex = 0; keysIndex < node->elements; ++keysIndex){
                    cout << node->arrayKeys[keysIndex] << "  ";
                }
            cout << "\n" << endl;
        }
    }

    void find (int key) {
        auxFind(key, this->root);
        if (!auxFind(key, this->root))
            cout << key << " Was NOT found!!!" << endl;
        else
            cout << key << " Was found!!!" << endl;
    }

    bool auxFind (int key, Node<Data>* node) {
        if (node->isLeaf) {
            for (int index = 0; index < node->elements; ++index) {
                //cout << "Elements: " << node->elements << endl;
                if (key == node->arrayKeys[index])
                    return 1;
            }
            return 0;
        }
        else {
            for (int index = 0; index < node->elements; ++index) {
                if (node->arrayKeys[index] > key)
                    return auxFind(key, node->arrayPtrs[index]);
            }
            return auxFind(key, node->arrayPtrs[node->elements]);
        }
    }
};

#endif /* BPLUSTREE_H */
