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

    //listo 
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
    }

    //listo
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

    //listo
    P& find(D data) {
    	P* temp = this->first;
    	for (int index = 0; index < this->n; ++index) {
    		if (*(temp->data) == data)
    			return *temp;
    	}
    }

    //listo
    D& get(P& cell) { 
        return *(cell.data);
    }

    //listo
    int getSize() {
        return this->n;
    } 

    //listo
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

    //listo
    P& next(P& cell) {
        return *(cell.next);
    }

    //listo
    P& prev(P& cell) {
        P* prev = nullptr;
        P* temp = this->first;

        if (&cell != (this->first)) {
            for (int index = 0; index < this->n; ++index) {
                prev = temp;
                temp = temp->next;
                if (*(temp->data) == *(cell.data) && &(temp->next) == &(cell.next)) {
                    cout << "Previous to: " << *(cell.data) << "\t\tis: " << *(prev->data) << endl;
                    return *(prev);
                }
            }
        }
    }

    //listo
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

    //listo
    void assign(P& k, D d) {
        *(k.data) = d;
    }

    void testAssign () {
        cout << "Assigning 5 to begining of list:\n";
        assign(*(first), 5);
    }

    /*void sort() {
        cout << "Sorting list:" << endl;

        if (this->first != nullptr) {
            int posMin = 0;
            P* current1 = nullptr;
            P* current2 = nullptr;
            P* temp = nullptr;

            for (int index = 0; index < this->n -1; ++index) {
                posMin = index;
                for (int index2 = index + 1; index2 < this->n; ++index2) {
                    if (getDataPos(index2) < getDataPos(posMin))
                        posMin = index2;
                }
                if (posMin != index) {
                    current1 = getNode(index);
                    current2 = getNode(posMin);

                    temp = getNode(index);
                    current1 = current2;
                    current2 = temp;
                }
            }
        }
    }*/

    //listo
    void sort() {
        cout << "Sorting list:" << endl;

        int size = this->n;
        int i = 0;

        while (size--) {
            P* current = this->first;
            P* prev = nullptr;
            while(current->next != nullptr) {
                P* after = current->next;
                if (*(current->data) > *(after->data)) {
                    current->next = after->next;
                    after->next = current;
                    if (prev == nullptr)
                        first = after;
                    else
                        prev->next = after;
                    prev = after;
                }
                else {
                    prev = current;
                    current = current->next;
                }
            }
        }
    }

    D& getDataPos(int pos) {
        P* temp = this->first;
        for (int index = 0; index < pos; ++index) {
            temp = &(next(*temp));
        }
        return get(*temp);
    }

};
#endif // LISTWITHPOINTER_H