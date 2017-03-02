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

    void newInsert(int key) {
        newAuxInsert(key, this->root);
    }

    void newAuxInsert(int key, Node<Data>* node) {
        if (node->isLeaf) {
            if (node->elements < this->order) { //caso en que haya campo en la hoja
                node->arrayKeys[node->elements] = key;
                node->elements += 1;
                sort(node->arrayKeys, node->elements);
            }
            else 
                splitLeaf(key, node);
        }
        else { //2 casos. Nodo lleno, Nodo con espacio
            if (node->elements < this->order) { //caso en que nodo tiene espacio
                insertInNotFullNode(node, key);
            } 
            else   
                insertInFullNode(node, key);
        } 
            
    }

    void insertInFullNode (Node<Data>* node, int key) {
        int* arrayToSplit = arrayToSplitFunc(node, key);

        int* leftSplit = new int[this->order];
        int* rightSplit = new int[this->order];

        Node<Data>* newNode;

        //llena left y right con 0's
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

        newNode = new Node<Data>(this->order);

        deleteFirstElement(rightSplit, this->order);

        node->arrayKeys = leftSplit;
        newNode->arrayKeys = rightSplit;

        newNode->father =  node->father;

        newAuxInsert(arrayToSplit[(int)floor((this->order + 1) / 2)], node->father);

    }

    void insertInNotFullNode (Node<Data>* node, int key) {
        node->arrayKeys[node->elements] = key;
        node->elements += 1;
        sort(node->arrayKeys, node->elements);

        Node<Data>* temp = node->arrayPtrs[0];
        //voy a poner los punteros bien
        for (int index1 = 0; index1 < node->elements; ++index1) { //mueve los next
            for (int index = 0 ; index < this->order; ++index) {//se mueve en los keys del nodo
                if (temp->arrayKeys[0] < node->arrayKeys[index]) {
                    node->arrayPtrs[index] = temp;
                    break;
                }
            }
            if(temp->next != nullptr)
                temp = temp->next;
        }
        node->arrayPtrs[node->elements] = temp;
    }

    void splitLeaf (int key, Node<Data>* node) {
        int* arrayToSplit = arrayToSplitFunc(node, key);

        int* leftSplit = new int[this->order];
        int* rightSplit = new int[this->order];

        Leaf<Data>* newNode;

        //llena left y right con 0's
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

        newNode = new Leaf<Data>(this->order);

        //enlazo la nueva hoja
        if (node->next == nullptr)
            node->next = newNode; 
        else {
            newNode->next = node->next;
            node->next = newNode;
        }

        node->arrayKeys = leftSplit;
        newNode->arrayKeys = rightSplit;

        newNode->father = node->father;

        node->elements = amountElements(node->arrayKeys, this->order);
        newNode->elements = amountElements(newNode->arrayKeys, this->order);

        newAuxInsert(arrayToSplit[(int)floor((this->order + 1) / 2)], node->father);
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

    int amountElements (int* array, int size) {
        int result = 0;
        for (int index = 0; index < size; ++index) {
            if (array[index] != -1)
                result += 1;
        }
        return result;
    }

    void deleteFirstElement(int* array, int  size) {
        for (int index = 0; index < size - 1; ++index)
            array[index] = array[index + 1];
        array[size - 1] = -1;
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
            else {
                if (node->isLeaf)
                    rightSplit[index - ((order + 1) / 2)] = arrayWNewKey[index];
                else {
                    rightSplit[index - ((order + 1) / 2)] = arrayWNewKey[index + 1];
                    index += 1;
                }
            }
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
        if (node->isLeaf){ 
            newNode = new Leaf<Data>(this->order);
            newNode->elements = (int)ceil((this->order + 1) / 2);
        }
        else {
            newNode = new Node<Data>(this->order);
            newNode->elements = (int)ceil((this->order + 1) / 2) - 1;
        }

        newNode->arrayKeys = rightSplit;
        
        //Revisar que pasa si es el root y no tiene padre.
        if (node != this->root)
            newNode->father = node->father;

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
                split(arrayWNewKey[(int)ceil((this->order + 1) / 2)], node->father);
                fixPointers(node->father, node, newNode);
            }
        }
        fatherPtrs(newNode);
    }

    void fixNewNodePointers (Node<Data>* old, Node<Data>* newOne) {
        for (int index = 0; index < this->order + 1; ++index) {
            //cout << index << "  " << endl;
            //cout << "old elements: " << old->elements << endl;
            if (index >= old->elements) {
                //cout << "index - old->elements + 1 = " <<index - old->elements + 1 << endl;
                if (old->arrayPtrs != nullptr) {
                    newOne->arrayPtrs[index - old->elements] = old->arrayPtrs[index];
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
        int* array = new int[this->order + 1];
        for (int index = 0; index < this->order + 1; ++index) {
            if (index != order)
                array[index] = keys[index];
            else
                array[index] = newKey;
        }

        sort(array, this->order + 1);

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
        // if (!auxFind(key, this->root))
        //     cout << key << " Was NOT found!!!" << endl;
        // else
        //     cout << key << " Was found!!!" << endl;
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
