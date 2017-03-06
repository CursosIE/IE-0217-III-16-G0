/**
*@file Node.h
*@version 1.0
*@date 6/03/17
*@author Luis Diego Fernandez, Daniel Jimenez
*@title Arbol B+
*@brief Clase ArbolB+
*/

#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <cmath>
#include <iostream>

#include "Node.h"
#include "Leaf.h"

using namespace std;

//se crea la clase como una plantilla
template <typename Data>
class BPlusTree {
   public:
    Node<Data>* root; //puntero a la raiz del arbol
    int levels; //cantidad de niveles del arbol
    int order; //orden del arbol
    int treeElements; //elementos del arbol

   public:

    /*! \brief Constructor por defecto.
     */
    BPlusTree() {
        root = nullptr;
        this->levels = 0;
        this->order = 0;
        this->treeElements = 0;
    }

    /*! \brief Constructor para crear un Arbol de un orden pre establecido.
     */
    BPlusTree(int order) {
        this->levels = 0;
        this->order = order;
        this->treeElements = 0;
        this->root = new Leaf<Data>(order);
    }

    /*! \brief Destructor.
     */
    virtual ~BPlusTree() {
        auxDestructor(this->root);
        delete root;
    }

    /*! \brief Metodo auxiliar del destructor de la clase.
     *
     *  \param node Nodo al cual le debe elmiminar los nodos que apunta y a si misma.
     */
    void auxDestructor (Node<Data>* node) {
        for (int index = 0; index < node->elements; ++index) {
            if(node->arrayPtrs[index] != nullptr){
                if (node->arrayPtrs[index]->isLeaf)
                    delete node->arrayPtrs[index];
                else {
                    auxDestructor(node->arrayPtrs[index]);
                    delete node->arrayPtrs[index];
                }
            }   
        }
    }

    /*! \brief Metodo para insertar un dato al arbol.
     *
     *  \param key Llave que se va a insertar al arbol.
     */
    void insertAk7 (int key) {
        auxInsertAk7(key, this->root);
    }

    /*! \brief Metodo para insertar un dato al arbol.
     *
     *  \param key Llave que se va a insertar al arbol.
     *  \param node Nodo en el cual se va a tratar de insertar la llave.
     */
    void auxInsertAk7 (int key, Node<Data>* node) {
        if(node->isLeaf == 1){ //pregunto si es una HOJA
            if (node->elements < this->order) { //caso en que haya campo en la hoja
                node->arrayKeys[node->elements] = key;  //meto la llave
                node->elements += 1; //aumento la cantidad de elementos del nodo en 1
                this->treeElements += 1; //aumento la cantidad de elementos del arbol en 1
                sort(node->arrayKeys, node->elements); //ordeno el nodo
            }
            else {
                this->treeElements += 1; //aumento la cantidad de elementos del arobl en 1, xq al entrar aqui va a insertar 
                splitAk7(node, key, nullptr, nullptr); //divido el nodo
            }
        }
        else {
            auxInsertAk7(key, node->arrayPtrs[pointerToGo(key, node)]);
        }
    }

    /*! \brief Metodo que divide un nodo al ingresar una llave.
     *
     *  \param node Nodo que tiene que dividir.
     *  \param key Llave que se va a insertar al arbol.
     *  \param oldSon Hijo viejo en caso de que sea un nodo que se divide y antes se dividio otro nodo u hoja.
     *  \param newSon Hijo nuevo en caso de que sea un nodo que se divide y antes se dividio otro nodo u hoja.
     */
    void splitAk7 (Node<Data>* node, int key, Node<Data>* oldSon, Node<Data>* newSon) {
        int* arrayToSplit = arrayToSplitFunc(node, key); //arreglo que hay que dividir en el nodo viejo y nuevo

        int* leftSplit = new int[this->order]; //arreglo que va a tener los datos de la mitad a la izquierda
        int* rightSplit = new int[this->order]; //arreglo que va a tener los datos de la mitad a la derecha

        Node<Data>* newNode; //nuevo nodo que se crea

        //se llenan los vectores de -1 por control, porque por se un dato primitivo 
        //no se pueden llenar de nulos o.O
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
        delete[] node->arrayKeys;
        node->arrayKeys = leftSplit;
        newNode->arrayKeys = rightSplit;

        //asignamos la cantidad de elementos
        node->elements = amountElements(node->arrayKeys, this->order);
        newNode->elements = amountElements(newNode->arrayKeys, this->order);

        if(node->isLeaf == 0) { 
            //arreglar los punteros hacia abajo
            assignDownwardPtrs(node, newNode, oldSon, newSon, key);
            //asignar padres correctamente
            fatherPtrs(node);
            fatherPtrs(newNode);
        }

        //en caso de que el nodo dividido fuer la raiz hay que trabajarla un poco 
        if(node == this->root) {
            this->levels += 1; //aumentar la cantidad de niveles del arbol en 1
            Node<Data>* newRoot = new Node<Data>(this->order); //crear una nuveva raiz

            newRoot->arrayKeys[0] = arrayToSplit[(int)floor((this->order + 1) / 2)]; //meterle la llave correspondiente
            newRoot->elements += 1; 
            //ponerle los hijos
            newRoot->arrayPtrs[0] = node; 
            newRoot->arrayPtrs[1] = newNode;

            this->root = newRoot; //decirle que es la raiz
            this->root->arrayPtrs[0]->father = this->root;
            this->root->arrayPtrs[1]->father = this->root;
        }
        else {
            if(node->father->elements < this->order){ //caso que el padre tuviera campo para la llave que se sube
                node->father->arrayKeys[node->father->elements] = arrayToSplit[(int)floor((this->order + 1) / 2)];
                delete[] arrayToSplit;
                node->father->elements += 1;
                specialSort(node->father->arrayKeys, node->father->arrayPtrs, node, newNode, node->father->elements);
            }
            else
                splitAk7(node->father, arrayToSplit[(int)floor((this->order + 1) / 2)], node, newNode);
        }
    }

    /*! \brief Metodo que dice a cual nodo del arreglo de punteros de nodos hay que ir al meter una llave.
     *
     *  \param key Llave que va a busacarle a donde ir.
     *  \param node Nodo en donde tiene que buscar.
     *  \return Posicion a la cual hay que bajar para llegar a la hoja en la cual hay que insertar una llave.
     */
    int pointerToGo(int key, Node<Data>* node) {
        for (int index = 0; index < node->elements; ++index) {
            if (node->arrayKeys[index] > key) //si la llave es menor al dato en index, devuelve el indice
                return index;
        }
        return node->elements;
    }

    /*! \brief Metodo que crea el arreglo que luego hay que dividir.
     *
     *  \param node Nodo que esta lleno.
     *  \param key Llave que tiene que agregar a las llaves del node.
     *  \return Arreglo de enteros que hay que dividir.
     */
    int* arrayToSplitFunc(Node<Data>* node, int key) {
        int* array = new int[this->order + 1]; //crea un arreglo con un campo para una llave mas 
        //agrega la llave al final del arreglo de llaves del nodo
        for (int index = 0; index < this->order + 1; ++index) {
            if (index < order)
                array[index] = node->arrayKeys[index];
            else
                array[index] = key;
        }
        sort(array, order + 1); //ordena el arreglo 
        return array;
    }

    /*! \brief Metodo que elimina el primer dato de un arreglo.
     *  \param array Arreglo al que hay que eliminarle el primer dato.
     *  \param size Tamanno del arreglo.
     */
    void deleteFirstElement(int* array, int  size) {
        //pasa todos los elementos una posicion hacia atras en el arreglo
        for (int index = 0; index < size - 1; ++index)
            array[index] = array[index + 1];
        array[size - 1] = -1; //pone el ultimo espacio del arreglo en -1 (para control)
    }

    /*! \brief Metodo que devuelve la cantidad de elementos de un arreglo.
     *  \param array Arreglo al que hay que contarle la cantidad de elementos.
     *  \param size Tamanno del arreglo.
     *  \return Cantidad de elementos del arreglo.
     */
    int amountElements (int* array, int size) {
        int result = 0;
        //cuenta la cantidad de elementos
        for (int index = 0; index < size; ++index) {
            if (array[index] != -1) //si el elemento no es -1 lo cuenta
                result += 1;
        }
        return result;
    }

    /*! \brief Metodo que arregla los punteros hacia abajo de un nodo dividido.
     *  \param old Nodo ya existente del nodo dividido.
     *  \param newOne Nodo nuevo creado al dividir el nodo viejo.
     *  \param oldSon El hijo del nodo viejo que ya existia al dividirse el nodo hijo viejo.
     *  \param newSon El hijo del nodo viejo que habia sido creado al dividirse el nodo hijo viejo
     *  \param key la llave.
     */
    void assignDownwardPtrs(Node<Data>* old, Node<Data>* newOne, Node<Data>* oldSon, Node<Data>* newSon, int key) {
        int continu = 0; //bandera de control

        //Revisa el primer elemento de todos los nodos apuntados por el arreglo de punteros a nodos del nodo
        //viejo y del nuevo y los corresponde con los campos respectivos del arreglo viejo y nuevo
        //con el fin de no perder hijos
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

    }

    /*! \brief Metodo que dice en que posicion qeudo la llave.
     *  \param key Llave que busca.
     *  \param node Nodo en donde se busca la posicion de la llave.
     *  \return Posicion de la llave.
     */
    int positionOfKey (int key, Node<Data>* node) {
        for(int index = 0; index < node->elements; ++index) {
            if (node->arrayKeys[index] == key)
                return index;
        }
        return -1;
    }

    /*! \brief Metodo que asigna  el correspondiente padre de un nodo
     *  \param node Nodo al que se busca sus punteros y les asigna como padre el mismo.
     */
    void fatherPtrs(Node<Data>* node) { //ese node va a ser newNode
        if (node->arrayPtrs != nullptr) {
            for(int index = 0; index < node->elements + 1; ++index) {
                if (node->arrayPtrs[index] != nullptr) {
                    node->arrayPtrs[index]->father = node;
                }
            }
        }
    }

    /*! \brief Metodo que ordena un arreglo con un selection sort.
     *  \param array Arreglo que hay que ordenar.
     *  \param size Tamanno del arreglo.
     */
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

    /*! \brief Metodo que ordena un arreglo con un selection sort y arregla los punteros de los elementos que se mueven.
     *  \param array Arreglo que hay que ordenar.
     *  \param arrayPtrs Arreglo de punteros del nodo.
     *  \param left Nodo hijo viejo al dividir.
     *  \param rigth Nodo hijo nuevo al dividir.
     *  \param size Tamanno del arreglo.
     */
    void specialSort (int* array, Node<Data>** arrayPtrs, Node<Data>* left, Node<Data>* right, int size) {
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
            for (int index = 0; index < size; ++index) { //arreglo de punteros
                if (array[index] == toFind) {
                    arrayPtrs[index] = left;
                    arrayPtrs[index + 1] = right;
                }
            }
        }
    }

    /*! \brief Metodo que elimina un dato del arbol.
     *  \param key Llave que se va a eliminar. 
     */
    void deleteAk7(int key) {
        auxDelete(key, this->root);
    }

    /*! \brief Metodo auxiliar que elimina un dato del arbol.
     *  \param key Llave que se va a eliminar. 
     *  \param node Nodo en el que se verifica si la llave esta para eliminar.
     */
    void auxDelete(int key, Node<Data>* node) {
        if(node->isLeaf == 0) //si el nodo no es una hoja llama de nuev con el respectivo nodo hijo
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

    /*! \brief Metodo para imprimir el arbol.
     */
    void printTree () {
        auxPrint(this->root, 1, -1);
    }

    /*! \brief Metodo auxiliar para imprimir el arbol.
     *  \param node Nodo que toca imprimir.
     *  \param level Nivel por el cual va, es un identificador.
     *  \param index Indice que se imprime.
     */
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

    /*! \brief Metodo para buscar un dato.
     *  \param key Llave que se busca.
     *  \return Si se encontro el dato.
     */
    bool find (int key) {
        return auxFind(key, this->root);
    }

    /*! \brief Metodo auxiliar para buscar un dato.
     *  \param key Llave que se busca.
     *  \param node Nodo en donde se busca la llave.
     *  \return Si se encontro el dato.
     */
    bool auxFind (int key, Node<Data>* node) {
        if (node->isLeaf) { //si el nodo es una llave busca el dato
            for (int index = 0; index < node->elements; ++index) {
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