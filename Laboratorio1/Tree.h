
#ifndef TREE_H
#define TREE_H


#include <iostream>
#include <cstdlib>

#include "Node.h"
#include "List/List.h"
#include "List/ListWithArray.h"

template <typename T> class Tree {
public:
    int depth;
    Node<T>* root;

    Tree() {
        depth = 0;
        root = 0x0;
    };

    Tree(Node<T>* r) {
        depth = 0;
        root = r;
    };

    virtual ~Tree() {
        //borrar todos los nodos
        delete root;
    };

    void postOrder() {
        this->_postOrder(root);
    };

    void _postOrder(Node<T>* n) {
        if (n) {
            _postOrder(n->R);
            std::cout << *(n->D) << " ";
            _postOrder(n->L);

        }
    };

    bool isLeaf(Node<T>* n) {
        if (n->L == nullptr && n->R == nullptr) {
            return 1;
        } else {
            return 0;
        }

    };

    void preOrder() {
        this->_preOrder(root);
    };

    void _preOrder(Node<T>* n) {
        if (n) {

            _preOrder(n->L);
            n->display();
            _preOrder(n->R);

        }
    };

    void inOrder() {
        this->_inOrder(root);
    };

    void _inOrder(Node<T>* n) {
        if (n) {
            std::cout << *(n->D) << " ";
            _inOrder(n->L);
            _inOrder(n->R);
        }
    };

    Node<T>* addNode(T* d) {
        bool busqueda = true;
        Node<T>* nodoact = root;
        Node<T>* nodoret = new Node<T>;
        nodoret->D = d;
        while (busqueda) {
            if (*d == *(nodoact->D)) {
                busqueda = false;
            } else if (*d<*(nodoact->D) && nodoact->L != 0) {
                nodoact = nodoact->L;
            } else if (*d<*(nodoact->D) && nodoact->L == 0) {
                nodoact->L = nodoret;
            } else if (*d>*(nodoact->D) && nodoact->R != 0) {
                nodoact = nodoact->R;
            } else if (*d>*(nodoact->D) && nodoact->R == 0) {
                nodoact->R = nodoret;
            }
        }
    };

    void deleteNode(T* n) {
        if (n->isleaf()) {
            n = 0x0;
        } else {
            if (this->min_may((n)) && this->min_may((n))->isleaf()) {
                *(n->D) = *(this->min_may(n)->D);
                ((this->min_may((n))->P)->R) = 0;
            } else {
                *(n->D) = *(this->may_min((n))->D);
                ((this->may_min((n))->P)->L) = 0;
            }
        }
    };

    Node<T>* find(T* d) {
        bool busqueda = true;
        Node<T>* nodoact = root;
        while (busqueda) {
            if (*d<*(nodoact->D) && nodoact->L != 0) {
                nodoact = nodoact->L;
            } else if (*d>*(nodoact->D) && nodoact->R != 0) {
                nodoact = nodoact->R;
            } else if (*d == *(nodoact->D)) {
                busqueda = false;
            } else {
                nodoact = 0;
                busqueda = false;
                cout << "El nodo no está en el árbol" << endl;
            }
        }
        return nodoact;
    };

    Node<T>* min_may(Node<T>* n) {
        bool busqueda = true;
        Node<T>* nodoact = n->R; //mover primero a la derecha
        if (n->L) {
            while (busqueda) {
                if (nodoact->L != 0) {
                    nodoact = nodoact->L; //mover a la izquierda hasta no tener hijos a la izquierda
                } else {
                    busqueda = false;
                }
            }
            return nodoact;
        } else {
            return 0;
        }
    };

    Node<T>* may_min(Node<T>* n) {
        bool busqueda = true;
        if (n->L) {
            Node<T>* nodoact = n->L; //mover primero a la derecha
            while (busqueda) {
                if (nodoact->R != 0) {
                    nodoact = nodoact->R; //mover a la izquierda hasta no tener hijos a la izquierda
                } else {
                    busqueda = false;
                }
            }
            return nodoact;
        } else {
            return 0;
        }
    };

    Node<T>* _find(Node<T>* n, T* d) {
        if (*d == *(n->D)) {
            return n;
        } else {
            if (*d < *(n->D) && n->R != 0x0) {
                return _find(n->L, d);
            } else {
                if (*d > *(n->D) && n->L != 0x0) {
                    return _find(n->R, d);
                } else {
                    return 0x0;
                }
            }
        }
    };

    Node<T>* fatherOf(T* d) {
        return find(d)->P;
    };

    void tree2list(Node<T>* n, List* l) {
        if (n) {

            tree2list(n->L, l);
            l->agregar(*(n->D));
            tree2list(n->R, l);

        }
    };

    void balance() {
        List* L = new ListWithArray(50);
        // make a list out of the tree

        tree2list(this->root, L);
        L->imprimir();

        // find the medium! Because the list is ordered
        // we can find the middle element in various ways
        int mid = (int)(L->getUltimo()/2);
        
        this->root = 0x0;
        
        this->addNode(new int( L->recuperar(mid) ));
        
    };
    
    void _balance(List* l, int min, int max)
    {
        
    };

private:

};

#endif /* TREE_H */

