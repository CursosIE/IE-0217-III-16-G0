#include <iostream>

#include "Cell.h"
#include "ListWithPointer.h"
//#include "ListaConArreglo.h"

using namespace std;

int main(int argc, char** argv) {
    ListWithPointer<int, Cell<int> >* list = new ListWithPointer<int, Cell<int> >();

    list->printList();
    cout << "n: " << list->getSize() << endl; //getSize()
    cout << endl;

    list->insert(36);
    list->insert(27);
    list->printList();
    cout << "n: " << list->getSize() << endl; //getSize()
    cout << endl;

    list->insert(11);
    list->insert(5);
    list->printList(); 
    cout << "n: " << list->getSize() << endl; //getSize()
    cout << endl;

    list->sort();
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

    list->prev(list->prev((list->prev(*(list->last)))));

    list->testAssign();
    list->printList(); 
    cout << "n: " << list->getSize() << endl;
    cout << endl;

    list->emptyList();
    list->printList();
    cout << "n: " << list->getSize() << endl;
    
    return 0;
}

