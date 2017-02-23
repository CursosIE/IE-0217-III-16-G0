#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "Edge.h"
#include "Listas/ListWithArray.h"

using namespace std;

template <typename D, typename P>
class Node {
public:
  D* Data;
  //Lista

  Node() {
    Data = nullptr;
    E = nullptr;
  }

  Node() {

  }

  addEdge(D d) {
  }

  virtual ~Node() {
    delete Data;
  }

};

#endif /* NODE_H */
