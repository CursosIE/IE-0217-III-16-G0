#ifndef CELL_H
#define CELL_H

using namespace std;

template <typename D> class Cell {
   public:
      ///Puntero a la celda siguiente.
   	Cell* next;
      ///Puntero al dato que tiene la celda.
   	D* data;

   public:
      /*! \brief Constructor por defecto. Se crea con los atributos nulos.
       */
   	Cell() {
   		data = nullptr;
   		next = nullptr;
   	}

      /*! \brief Constructor para crear una Celda con datos especificos.
       */
   	Cell(D* data, Cell* next) {
   		this->data = data;
   		this->next = next;
   	}

      /*! \brief Constructor por copia.
       */
   	Cell(const Cell& cell) {
   		this->data = cell.data;
   		this->next = cell.next;
   	}

      /*! \brief Destructor.
       */
   	virtual ~Cell() {
   		delete this->data; //se libera la memoria dinamica utilizada para guardar el dato.
   	}
};
#endif // CELL_H