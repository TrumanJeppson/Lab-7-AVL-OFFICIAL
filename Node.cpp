#include "Node.h"

Node:: Node(const int& myData) {
	data = myData;
	height = 0;
}


int Node::getData() const {
  return data;
}

NodeInterface* Node::getLeftChild() const {
	return leftChild;
}

NodeInterface* Node::getRightChild() const {
  return rightChild;
}

/*
* Returns the height of this node. The height is the number of nodes
* along the longest path from this node to a leaf.  While a conventional
* interface only gives information on the functionality of a class and does
* not comment on how a class should be implemented, this function has been
* provided to point you in the right direction for your solution.  For an
* example on height, see page 448 of the text book.
*
* @return the height of this tree with this node as the local root.
*/
int Node::getHeight() {
  return height;
}

void Node:: setHeight(int nodeHeight) {
	height = nodeHeight;
}