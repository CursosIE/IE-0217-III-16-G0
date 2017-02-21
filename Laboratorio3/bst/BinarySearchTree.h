

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include "ListWithPointer.h"
#include "Node.h"

using namespace std;

template <typename Data>
class BinarySearchTree {
   public:
    Node<Data>* root;
    int level, nodes;

   public:

    BinarySearchTree() {
    }

    BinarySearchTree(Node<Data>* r) {
        this->root = r;
    }

    BinarySearchTree(Data* d) {
        this->root = new Node<Data>(nullptr, nullptr, d, nullptr);
    }

    BinarySearchTree(const BinarySearchTree& orig) {
    }

    virtual ~BinarySearchTree() {
    }

    void insert(Data* d) {
        if (this->root == nullptr) {
            root = new Node<Data>(nullptr, nullptr, d, nullptr);
        } else {
            Node<Data>* t = root;
            bool end = 0;
            while (!end) {
                if (*d < *(t->d)) {
                    if (t->l == nullptr) {
                        t->l = new Node<Data>(nullptr, nullptr, d, t);
                        end = 1;
                    } else {
                        if (t->l != nullptr) {
                            t = t->l;
                        }
                    }
                } else {
                    if (t->r == nullptr) {
                        t->r = new Node<Data>(nullptr, nullptr, d, t);
                        end = 1;
                    } else {
                        if (t->r != nullptr) {
                            t = t->r;
                        }
                    }
                }
            }
        }
    }

    void removing(Node<Data>* n) {
        if (n && n->l == n->r && n->r == nullptr) // es hoja?
        {
            delete n; // =)
        } else {
            Node<Data>* t = replacementFor(n);
            if (t) {
                *(n->d) = *(t->d);
                removing(t);
            }
        }
    }

    void remove(Data* d) {
        removing(find(d));
    }

    Data * get(Node<Data>* n) {
        return n->d;
    }

    void set(Node<Data>* n, Data * d) {
    }

    Node<Data>* finding(Data* d, Node<Data>* n) {
        if (n && *(n->d) == *d) {

            return n;
        } else {
            if (n && *(n->d) > *d) {
                return finding(d, n->l);
            } else {
                if (n) {
                    return finding(d, n->r);
                } else {
                    return nullptr;
                }
            }
        }
    }

    Node<Data>* find(Data* d) {
        return finding(d, this->root);
    }

    void printTree() {
        this->inOrder(root, "");
    }

    void inOrder(Node<Data>* n, string s) {
        if (n) {
            //cout << s << *(n->d) << "@" << n << endl;
            cout << s << *(n->d) << endl;
            inOrder(n->r, s + "\t");
            inOrder(n->l, s + "\t");
        }
    }

    Node<Data>* replacementFor(Node<Data>* n) {
        if (n) {
            if (n->l) {
                return maxLesser(n);
            } else {
                if (n->r) {
                    return minGreater(n);
                }
            }
        }
        return nullptr;
    }

    Node<Data>* minGreater(Node<Data>* n) {
        Node<Data>* t = n->r;
        while (t->l) {
            t = t->l;
        }
        return t;
    }

    Node<Data>* maxLesser(Node<Data>* n) {

        Node<Data>* t = n->l;

        while (t->r) {
            t = t->r;
        }
        return t;
    }

    /*postOrder() {
    }

    preOrder() {
    }*/

    void treeToList(Node<Data>* node, ListWithPointer<Data, Cell<Data> > *list) {
    	if (node != nullptr) {
    		treeToList(node->l, list);
    		list->insert(*(node->d));
    		treeToList(node->r, list);
    	}
    }

    void balance() {
    	ListWithPointer<Data, Cell<Data> >* list = new ListWithPointer<Data, Cell<Data> >();
    	int pos;

    	treeToList((this->root), list);
    	//list->printList();
    	//cout << list->getDataPos(list->n / 2) << endl;

    	BinarySearchTree<D>* bstBalanced = new BinarySearchTree<D>(new D(list->getDataPos(list->n / 2)));

    	max = (list->n / 2) -1;
    	min = 0;
    	while (max != min) {
    		pos = (max-min)/2;
    		bstBalanced->insert(new D(list->getDataPos(pos)));
    		max = pos;
    	}


    	





    }




};

#endif /* BINARYSEARCHTREE_H */

