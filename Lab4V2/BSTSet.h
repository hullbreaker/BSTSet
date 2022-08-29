#ifndef BSTSET_H_
#define BSTSET_H_

#include "TNode.h"
#include <vector>
#include "ArrayStack.h"


class BSTSet
{
private:
	// must contain only one private field
	TNode* root = NULL;

	void preOrderUnion(TNode* subroot);
	void preOrderIntersection(TNode* subroot, TNode* dest);
	void preOrderDifference(TNode* subroot, TNode* dest);
	void deleteTree(TNode* t);

public:
	// required constructors/destructor
	BSTSet();
	BSTSet(const std::vector<int>& input);
	~BSTSet();

	// required methods
	bool isIn(int v);
	void add(int v);
	bool remove(int v);

	//void preOrderUnion(TNode* subroot);
	void Union(const BSTSet& s);

	//void preOrderIntersection(TNode* subroot,TNode* dest);
	void intersection(const BSTSet& s);

	//void preOrderDifference(TNode* subroot, TNode* dest);
	void difference(const BSTSet& s);

	int size();
	int height();
	void printNonRec(); // create and use class MyStack

	// provided recursive print method
	void printBSTSet();

	// Used for testing
	TNode* getRoot()
	{
		return root;
	}

private:
	// provided helper methods
	void printBSTSet(TNode* t);
};

#endif /* BSTSET_H_ */
