#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#include "Cell.h"
#include "List.h"

using namespace std;

template <typename D, typename P>
class Queue : public List<D, P> {
   public:
   	P* first;
   	P* last;

   public:
    Queue() {
        this->n = 0;
        this->first = nullptr;
        this->last = nullptr;
    }

    virtual ~Queue() {
    	emptyList();
    }

    void insert(D data) {
    	cout << "Inserting: " << data << endl;
        if (this->n == 0) {
            P* cell = new P(new D(data), nullptr);
            this->first = cell;
            this->last = cell;
        }
        else {
            P* cell = new P(new D(data), this->first);
            this->first = cell;
        }
        this->n++;
    }

    void remove(D data) {
    	if (this->n == 1) {
    		delete this->first;
    		this->n -= 1;
        first = nullptr;
        last = nullptr;
    	}
    	else {
	    	cout << "Removing" << endl;
        P* temp = this->first;
      	for (int index = 0; index < this->n; ++index) {
      		if (temp->next == this->last){
            delete this->last;
            this->last = temp;
          } else {
            if (temp->next != nullptr)
              temp = temp->next;
          }
        }
        this->n -= 1;
	    }
    }

    P& find(D data) {

    }

    D& get(P& cell) {
      if (this->n == 1) {
        P* temp = this->first;
        delete this->first;
        this->n -= 1;
        first = nullptr;
        last = nullptr;
        return *(temp->data);
      }
      else {
        P* temp = this->first;
        for (int index = 0; index < this->n; ++index) {
          if (temp->next == this->last){
            P* temp2 = this->last;
            delete this->last;
            this->last = temp;
            return *(temp2->data);
          } else {
            if (temp->next != nullptr)
              temp = temp->next;
          }
        }
      }
    }

    int getSize() {
        return this->n;
    }

    void printList() {
        if (this->n == 0)
            cout << "List is empty..!" << endl;
        else {
            P* temp = this->first;
            cout << "Printing list: ";
            for (int index = 0; index < this->n; ++index) {
                cout << *(temp->data) << "  ";
                if (temp->next != nullptr)
                	temp = temp->next;
            }
            cout << endl;
        }
    }

    P& next(P& cell) {

    }

    P& prev(P& cell) {

    }

    void emptyList() {
    	cout << "Emptying list..." << endl;
    	erase(this->first);
    	this->n = 0;
    }

    void erase(P* k) {
    	if (k->data != nullptr && k->next != nullptr) {
    		erase(k->next);
    		delete k;
    	}
    }

    void assign(P& k, D d) {

    }

    void sort() {

    }

};
#endif // QUEUE_H
