#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

#include "Edge.h"
#include "Node.h"

using namespace std;

template <typename D, typename P>
class Graph {
   public:
   	ListWithPointer<Node, Cell<Node> >* listOfNodes;

   public:
   	Graph() {
   		listOfNodes = new ListWithPointer<Node> >();
   	}

   	virtual ~Graph() {

   	}

   	void insert(Node node) {
   		listOfNodes->insert(node);
   	}

   	void remove(Node node) {
   		listOfNodes->remove(node);
   	}

};
#endif /* GRAPH_H */