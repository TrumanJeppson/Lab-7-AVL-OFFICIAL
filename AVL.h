#pragma once

#include "Node.h"
#include "AVLInterface.h"
//#include "AVL_Tree.h"
#include <iostream>

using namespace std;

class AVL : public AVLInterface {
public:
	AVL(Node* myRoot);
	AVL();
	virtual ~AVL() {}

	NodeInterface* getRootNode() const;

	///// ADD FUNCTIONS /////
	bool add(int item);

	bool addHelper(Node*& localRoot, int item);

	///// REMOVE FUNCTIONS /////
	bool remove(int item);

	bool removeHelper(Node*& localRoot, int item); 

	void replacer(Node*& oldRoot, Node*& localRoot);

	///// CLEAR FUNCTIONS /////
	void clear();

	void clearHelper(Node*& localRoot);

	///// ROTATE AND REBALANCE FUNCTIONS /////
	void rotateLeft(Node*& localRoot);

	void rotateRight(Node*& localRoot);

	void rebalance(Node*& localRoot);

	///// HEIGHT FUNCTIONS /////

	int findHeight(Node* localRoot);

	void calcHeight(Node* localRoot);

private:
  //AVL_Tree booktree;
	
	Node* root = nullptr;

};