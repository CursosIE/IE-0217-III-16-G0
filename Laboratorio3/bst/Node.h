

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
//BST node

template <typename D>
class Node {
public:

    Node* l;
    Node* r;
    Node* f;
    D* d;

    Node() {
    }

    Node(Node* l, Node* r, D* d, Node* f) {
        this->l = l;
        this->d = d;
        this->r = r;
        this->f = f;
    }

    Node(const Node& orig) { // hacerlo
    }

    virtual ~Node() {
        cout << "deleting node " << this << endl;
        if (*(this->f->d) > *(this->d)) {
            this->f->l = nullptr;
        } else {
            this->f->r = nullptr;
        }


        delete d;

    }

};

#endif /* NODE_H */

