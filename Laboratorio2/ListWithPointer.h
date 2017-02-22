#ifndef LISTWITHPOINTER_H
#define LISTWITHPOINTER_H

#include <iostream>

#include "Cell.h"
#include "List.h"

using namespace std;

template <typename D, typename P> 
class ListWithPointer : public List<D, P> {
   public:
   	P* first;
   	P* last;

   public:
    ListWithPointer () {
        this->n = 0;
        this->first = nullptr;
        this->last = nullptr;
    }

    virtual ~ListWithPointer() {
    	emptyList();
    }

    void insert(D data) {
    	cout << "Inserting: " << data << endl;
        P* cell = new P(new D(data), nullptr);
        if (this->n == 0) {
            this->first = cell;
            this->last = cell;
        }
        else {
            this->last->next = cell;
            this->last = cell;   
        }
        this->n++;
        /*cout << "First dir: " << &(this->first) << "\nFirst Data: " << *(this->first->data) << endl;
        cout << "Last dir: " << &(this->last) << "\nLast Data: " << *(this->last->data) << endl;
        cout << endl;*/
    }

    void remove(D data) {
    	if (this->n == 1 && *(this->first->data) == data) {
    		delete first;
    		this->n -= 1;
    	}
    	else {
	    	cout << "Removing: " << data << endl;
	        P* del = nullptr;
	        P* pre = nullptr;
	        if (*(this->first->data) == data) {
	        	del = this->first;
	        	this->first = del->next;
	        	delete del;
	        	this->n -= 1;
	        }

	        pre = this->first;
	        del = this->first->next;

	        while(del != nullptr) {
	        	if (*(del->data) == data) {
	        		pre->next = del->next;
	        		if (del == this->last)
	        			this->last = pre;
	        		delete del;
	        		this->n -= 1;
	        		break;
	        	}
	        	pre = del;
	        	del = del->next;
	        }
	    }
    }

    P find(D data) {
    	P* temp = this->first;
    	for (int index = 0; index < this->n; ++index) {
    		if (*(temp->data) == data)
    			return *temp;
    	}
    }

    D& get(P& cell) { 
        return *(cell.data);
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
                cout << get(*temp) << "  ";
                if (temp->next != nullptr) 
                	temp = &(next(*temp));
            }
            cout << endl;
        }
    }

    P& next(P& cell) {
        return *(cell.next);
    }

    P prev(P cell) {
        /*P temp = this->first;
        if (&cell == &(this->first))
            return Cell<D>();

        for (int index = 0; index < this->n; ++index) {
            if (temp.next->next == cell.next && index < this->n-1)
                return temp;
            else {
                if (&cell == &(this->last))
                    return temp;
            }
        }*/
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
        *(k.data) = d;
    }

    void testAssign () {
        assign(*(first), 5);
    }

    void sort() {

    }

    D getLast() {
        return *(this->last->data);
    }

};
#endif // LISTWITHPOINTER_H