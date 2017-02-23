#include <iostream>

#include "Cell.h"
#include "ListWithPointer.h"
#include "Queue.h"
#include "Stack.h"
//#include "ListaConArreglo.h"

using namespace std;

int main(int argc, char** argv) {
    ListWithPointer<int, Cell<int> >* list = new ListWithPointer<int, Cell<int> >();

    cout << endl << "ListWithPointer:\n" << endl; 

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
    cout << endl; 

    list->find(69);
    list->find(11);
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
    cout << endl;

    list->testAssign(121);
    list->printList();
    cout << "n: " << list->getSize() << endl;
    cout << endl;

    list->emptyList();
    list->printList();
    cout << "n: " << list->getSize() << endl;
    cout << endl;

    cout << "-----------------" << endl;
    cout << "-----------------" << endl;
    cout << "-----------------" << endl;

    cout << endl << "Queue:" << endl;
    cout << endl;

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
    cout << endl;

    cout << "-----------------" << endl;
    cout << "-----------------" << endl;
    cout << "-----------------" << endl;

    cout << endl << "Stack:" << endl;
    cout << endl;

    Stack<int, Cell<int> >* stack = new Stack<int, Cell<int> >();

    stack->printList();
    cout << "n: " << stack->getSize() << endl; //getSize()
    cout << endl;

    stack->insert(5);
    stack->insert(11);
    stack->printList();
    cout << "n: " << stack->getSize() << endl; //getSize()
    cout << endl;

    stack->insert(27);
    stack->insert(36);
    stack->printList();
    cout << "n: " << stack->getSize() << endl; //getSize()
    cout << endl;

    stack->find(69);
    stack->find(11);
    cout << endl;

    stack->remove(5);
    stack->printList();
    cout << "n: " << stack->getSize() << endl; //getSize()
    cout << endl;

    stack->remove(27);
    stack->printList();
    cout << "n: " << stack->getSize() << endl; //getSize()
    cout << endl;

    stack->remove(36);
    stack->printList();
    cout << "n: " << stack->getSize() << endl; //getSize()
    cout << endl;

    stack->remove(11);
    stack->printList();
    cout << "n: " << stack->getSize() << endl; //getSize()
    cout << endl;

    stack->insert(66);
    stack->insert(77);
    stack->insert(99);
    stack->printList();
    cout << "n: " << stack->getSize() << endl;
    cout << endl;

    stack->emptyList();
    stack->printList();
    cout << "n: " << stack->getSize() << endl;
    cout << endl;

    return 0;
}
