#ifndef CELL_H
#define CELL_H

using namespace std;

template <typename D> class Cell {
   public:
   	Cell* next;
   	D* data;

   public:
   	Cell() {
   		data = nullptr;
   		next = nullptr;
   	}

   	Cell(D* data, Cell* next) {
   		this->data = data;
   		this->next = next;
   	}

   	Cell(const Cell& cell) {
   		this->data = cell.data;
   		this->next = cell.next;
   	}

   	virtual ~Cell() {
   		delete this->data;
   	}
};
#endif // CELL_H