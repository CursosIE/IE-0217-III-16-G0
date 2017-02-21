
#include <iostream>
#include "Node.h"
#include "BinarySearchTree.h"
#define D int

using namespace std;

int main(int argc, char** argv) {
    //0 to 18,446,744,073,709,551,615
    //    Node<D>* n0 = new Node<D>(nullptr, nullptr, new D(3), nullptr);
    //    Node<D>* n1 = new Node<D>(nullptr, nullptr, new D(1), nullptr);
    //    Node<D>* n2 = new Node<D>(nullptr, nullptr, new D(2), nullptr);
    //    Node<D>* n3 = new Node<D>(nullptr, nullptr, new D(4), nullptr);
    //
    //    n0->l = n1;
    //    n0->r = n3;
    //    n1->r = n2;
    //
    //    BinarySearchTree<D>* bst0 = new BinarySearchTree<D>(n0);
    //    bst0->printTree();
    //    cout << "======" << endl;
    //    
    BinarySearchTree<D>* bst1 = new BinarySearchTree<D>(new D(3));
    bst1->insert(new D(4));
    bst1->insert(new D(1));
    bst1->insert(new D(2));

    bst1->printTree();

    Node<D>* r = bst1->find(new D(666));
    if (r) {
        cout << *(r->d) << endl;
    } else {
        cout << "no esta" << endl;
    }

    r = bst1->maxLesser(bst1->root);
    if (r) {
        cout << *(r->d) << endl;
    } else {
        cout << "no esta" << endl;
    }

    r = bst1->minGreater(bst1->root);
    if (r) {
        cout << *(r->d) << endl;
    } else {
        cout << "no esta" << endl;
    }

    bst1->remove(new int(987));
    bst1->printTree();

    return 0;
}

