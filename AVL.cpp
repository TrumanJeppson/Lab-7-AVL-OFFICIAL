#include "AVL.h"

using namespace std;

///// CONSTRUCTORS /////
AVL:: AVL () {
	root = nullptr;
}

AVL:: AVL (Node* myRoot) {
	root = myRoot;
}

///// GET FUNCTIONS /////
NodeInterface* AVL::getRootNode() const {
	return root;
}

///// ADD FUNCTIONS /////
bool AVL::add(int item) {
	return(addHelper(this->root, item));
}

bool AVL:: addHelper(Node *&localRoot, int item) {
//cout << "adding " << item << " to tree..." <<endl;
  if (localRoot == NULL) {
		localRoot = new Node(item);
		//cout << "Added" << endl;
		return true;
	}
	else {
		if (item == localRoot->data) {
			//cout << "Item: " << item << " is already in tree. Did not add" << endl;
			return false;
		}
		else if (item < localRoot->data) {
			bool isAdded = addHelper(localRoot->leftChild, item);
			if (isAdded) {
				cout << "recursive add, ready to be balanced" << endl;
				calcHeight(localRoot);
				//rebalance(localRoot);
			}
			return isAdded;
		}
		else if (item > localRoot->data) {
			bool isAdded = addHelper(localRoot->rightChild, item);
			if (isAdded) {
				cout << "recursive add, ready to be balanced" << endl;
				calcHeight(localRoot);
				//rebalance(localRoot);
			}
			return isAdded;
		}		
	}
}

///// REMOVE FUNCTIONS /////
bool AVL::remove(int item) {
	return(removeHelper(this->root, item));
}

bool AVL:: removeHelper(Node*& localRoot, int item) {
	// value not found
	if (localRoot == NULL) {
		return false;
	}
	// traverse left and right...
	else {

		if (item < localRoot->data) {
			return removeHelper(localRoot->leftChild, item);
		}

		else if (item > localRoot->data) {
			return removeHelper(localRoot->rightChild, item);
		}
		// found...
		else {
			Node* oldRoot = localRoot;

			if (localRoot->leftChild == NULL) {
				localRoot = localRoot->rightChild;
				delete oldRoot;
			}

			else if (localRoot->rightChild == NULL) {
				localRoot = localRoot->leftChild;
				delete oldRoot;
			}

			else {
				replacer(oldRoot, localRoot->leftChild);
			}
		}
		return true;
	}
}

void AVL:: replacer(Node*& oldRoot, Node*& localRoot) {
	//Finding largest value in left subtree of value.
	if(localRoot->rightChild != NULL) {
		replacer(oldRoot, localRoot->rightChild);
	}
	// Found largest, now swapping the two and erasing.
	else {
		oldRoot->data = localRoot->data;
		removeHelper(oldRoot->leftChild, localRoot->data);
	}
}

///// CLEAR FUNCTIONS /////
void AVL:: clear() {
	clearHelper(this->root);
	this->root = NULL;
}

void AVL:: clearHelper(Node*& localRoot) {
	if (localRoot != NULL) {
		clearHelper(localRoot->leftChild);
		clearHelper(localRoot->rightChild);
		localRoot = nullptr;
		delete [] localRoot;
	}
}

///// ROTATE AND REBALANCE FUNCTIONS /////
void AVL::rotateLeft(Node*& localRoot) {
  Node* temp = localRoot;
	// Set pointer to localRoot to point to k
  localRoot = localRoot->rightChild;
	// Set localRoot's right to point to k's left
  temp->rightChild = localRoot->leftChild;
	// Set k's left to point to localRoot
  localRoot->leftChild = temp;
}

void AVL::rotateRight(Node*& localRoot) {
  Node* temp = localRoot;
  // Set pointer to localRoot to point to k
	localRoot = localRoot->leftChild;
  // Set localRoot's left to point to k's right
	temp->leftChild = localRoot->rightChild;
  // Set k's right to point to localRoot
	localRoot->rightChild = temp;
}

void AVL::rebalance(Node*& localRoot) {
  // Check node's balance (should be -2, -1, 0, 1, or 2)
  // Case: balance == -2 (LL or LR tree)
    // Case: LL tree (left balance is -1 or 0, so rotate right around localRoot)
    // Case: LR tree (left balance is 1, so rotate left around localRoot->left, then rotate right around localRoot)
  // Case: balance == 2 (RR or RL tree)
    // Case: RR tree (right balance is 1 or 0, so rotate left around localRoot)
    // Case: RL tree (right balance is -1, so rotate right around localRoot->right, then rotate left around localRoot)
  // Case: else (do nothing, not unbalanced)
}

///// HEIGHT FUNCTIONS /////

int AVL:: findHeight(Node* localRoot) {
	if (localRoot == nullptr) {
		return (0);
	}
	else {
		return localRoot->height;
	}
}

void AVL:: calcHeight(Node* localRoot) {
	if (localRoot == nullptr) {
		return;
	}
	else {
		int max = 0;
		if (findHeight(localRoot->leftChild) > max) {
			max = findHeight(localRoot->leftChild);
		}
		if (findHeight(localRoot->rightChild) > max) {
			max = findHeight(localRoot->rightChild);
		}
		localRoot->setHeight(max + 1);
		cout << "calcHeight " << localRoot->data << ": " << localRoot->height << endl;
	}
}