#include <cstdlib>
#include "Node.h"
#include "Tree.h"

#define NL cout << endl
#define SP " "

using namespace std;

int main(int argc, char** argv) {

    Tree<int>* T = new Tree<int>();

    // L,R,P,D
    Node<int>* _2 = new Node<int>(0x0, 0x0, 0x0, new int(2));
    Node<int>* _5 = new Node<int>(0x0, 0x0, 0x0, new int(5));
    Node<int>* _7 = new Node<int>(0x0, 0x0, 0x0, new int(7));
    Node<int>* _10 = new Node<int>(0x0, 0x0, 0x0, new int(10));
    Node<int>* _15 = new Node<int>(0x0, 0x0, 0x0, new int(15));
    Node<int>* _20 = new Node<int>(0x0, 0x0, 0x0, new int(20));
    Node<int>* _25 = new Node<int>(0x0, 0x0, 0x0, new int(25));


    _2->L = 0x0;
    _2->R = 0x0;
    _2->P = _5;
    _5->L = _2;
    _5->R = _10;
    _5->P = 0x0;
    _7->L = 0x0;
    _7->R = 0x0;
    _7->P = _10;
    _10->L = _7;
    _10->R = _20;
    _10->P = _5;
    _15->L = 0x0;
    _15->R = 0x0;
    _15->P = _20;
    _20->L = _15;
    _20->R = _25;
    _20->P = _10;
    _25->L = 0x0;
    _25->R = 0x0;
    _25->P = _20;


    T->root = _5;


    T->preOrder();
    NL;
    
    T->balance();
    
    T->preOrder();
    NL;

    return 0;
}

