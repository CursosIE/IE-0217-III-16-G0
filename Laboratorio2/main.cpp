#include <iostream>

#include "Cell.h"
#include "ListWithPointer.h"
#include "Queue.h"
//#include "ListaConArreglo.h"

using namespace std;

int main(int argc, char** argv) {
    ListWithPointer<int, Cell<int> >* list = new ListWithPointer<int, Cell<int> >();

    cout << endl << "ListWithPointer:" << endl; 

    list->printList();
    cout << "n: " << list->getSize() << endl; //getSize()
    cout << endl;

    list->insert(5);
    list->insert(11);
    list->printList();
    cout << "n: " << list->getSize() << endl; //getSize()
    cout << endl;

    list->insert(27);
    list->insert(36);
    list->printList();
    cout << "n: " << list->getSize() << endl; //getSize()
    cout << endl;


    list->remove(5);
    list->printList();
    cout << "n: " << list->getSize() << endl; //getSize()
    cout << endl;

    list->remove(27);
    list->printList();
    cout << "n: " << list->getSize() << endl; //getSize()
    cout << endl;

    list->remove(36);
    list->printList();
    cout << "n: " << list->getSize() << endl; //getSize()
    cout << endl;

    list->remove(11);
    list->printList();
    cout << "n: " << list->getSize() << endl; //getSize()
    cout << endl;

    list->insert(66);
    list->insert(77);
    list->insert(99);
    list->printList();
    cout << "n: " << list->getSize() << endl;
    cout << endl;

    list->testAssign();
    list->printList();
    cout << "n: " << list->getSize() << endl;
    cout << endl;

    list->emptyList();
    list->printList();
    cout << "n: " << list->getSize() << endl;

    cout << "-----------------" << endl;
    cout << "-----------------" << endl;
    cout << "-----------------" << endl;

    cout << endl << "Queue:" << endl;

    Queue<int, Cell<int> >* queue = new Queue<int, Cell<int> >();

    queue->printList();
    cout << "n: " << queue->getSize() << endl; //getSize()
    cout << endl;

    queue->insert(5);
    queue->insert(11);
    queue->printList();
    cout << "n: " << queue->getSize() << endl; //getSize()
    cout << endl;

    queue->insert(27);
    queue->insert(36);
    queue->printList();
    cout << "n: " << queue->getSize() << endl; //getSize()
    cout << endl;


    queue->remove(5);
    queue->printList();
    cout << "n: " << queue->getSize() << endl; //getSize()
    cout << endl;

    queue->remove(27);
    queue->printList();
    cout << "n: " << queue->getSize() << endl; //getSize()
    cout << endl;

    queue->remove(36);
    queue->printList();
    cout << "n: " << queue->getSize() << endl; //getSize()
    cout << endl;

    queue->remove(11);
    queue->printList();
    cout << "n: " << queue->getSize() << endl; //getSize()
    cout << endl;

    queue->insert(66);
    queue->insert(77);
    queue->insert(99);
    queue->printList();
    cout << "n: " << queue->getSize() << endl;
    cout << endl;

    queue->emptyList();
    queue->printList();
    cout << "n: " << queue->getSize() << endl;

    return 0;
}
