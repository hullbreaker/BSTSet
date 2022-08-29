#include "BSTSet.h"
#include <iostream>
#include <vector>
using namespace std;

BSTSet::BSTSet()
{
	// TODO

}

void insert(int x, TNode*& t) {
	if (t == NULL) {
		t = new TNode(x, NULL, NULL);
	}
	else if (x < t->element) {
		insert(x, t->left);
	}
	else if (x > t->element) {
		insert(x, t->right);
	}
	else {

	}
}

BSTSet::BSTSet(const std::vector<int>& input)
{
	/*

	for (int i = 0; i < tempVec.size(); i++) {
		for (int j = i; j < tempVec.size(); j++) {
			int temp = 0;
			if (tempVec[i] == tempVec[j] && i != j) {
				tempVec.erase(std::next(tempVec.begin(), j));
				j--;
			}

		}
	}
	for (int i = 0; i < tempVec.size(); i++) {
		for (int j = i; j < tempVec.size(); j++) {
			int temp = 0;
			if (tempVec[i] > tempVec[j]) {
				//std::cout << "swap" << tempVec[i] << ", " << tempVec[j] << std::endl;
				temp = tempVec[j];
				tempVec[j] = tempVec[i];
				tempVec[i] = temp;
			}
		}
	}
	*/

	// Time complexity n^2
	// Space complexity n
	std::vector<int> tempVec = input;
	TNode* current = NULL;
	for (int i = 0; i < tempVec.size(); i++) {
		insert(tempVec[i], root);
	}

}


void BSTSet::deleteTree(TNode* t) {
	if (t != NULL) {
		deleteTree(t->left);
		deleteTree(t->right);
		delete t;
	}
}

// Time complexity n
// Space complexity 1
BSTSet::~BSTSet()
{
	// TODO
	//deleteTree(root);
}

bool isInTree(int e, TNode*& t) {
	if (t == NULL) {
		return false;
	}
	else if (e < t->element) {
		return isInTree(e, t->left);
	}
	else if (e > t->element) {
		return isInTree(e, t->right);
	}
	else {
		return true;
	}
}

// Time complexity n
// Space complexity 1
bool BSTSet::isIn(int v)
{
	return isInTree(v, root); //change this after completing this function
}

// Time complexity n
// Space complexity 1
void BSTSet::add(int v)
{
	// TODO
	insert(v, root);
}

// Time complexity n
// Space complexity 1
TNode* findMin(TNode* t) {
	TNode* current = t;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}


bool removeElement(int x, TNode*& t) {
	if (t == NULL) {
		return false;
	}
	else if (x < t->element) {
		removeElement(x, t->left);
	}
	else if (x > t->element) {
		removeElement(x, t->right);
	}
	else if (t->left != NULL && t->right != NULL) {
		t->element = findMin(t->right)->element;
		removeElement(t->element, t->right);
	}
	else {
		TNode* oldNode = t;
		//t = (t->left != NULL) ? t->left : t->right;

		if (t->left != NULL) {
			t = t->left;
		}
		else {
			t = t->right;
		}
		delete oldNode;
		return true;
	}
}

// Time complexity n^2
// Space complexity 1
bool BSTSet::remove(int v)
{
	/*if (removeElement(v, root) == true) {
		return true;
	}*/
	
	return removeElement(v,root); //change this after completing this function
}

void BSTSet::preOrderUnion(TNode* subroot) {
	if (subroot != NULL) {
		insert(subroot->element, root);
		preOrderUnion(subroot->left);
		preOrderUnion(subroot->right);
	}
}

// Time complexity n
// Space complexity 1
void BSTSet::Union(const BSTSet& s)
{
	// TODO
	if (root == NULL) {
		root = s.root;
	}
	else {
		preOrderUnion(s.root);
	}

}

void BSTSet::preOrderIntersection(TNode* subroot, TNode* dest) {
	std::vector<int> temp;
	if (subroot != NULL) {
		if (isInTree(subroot->element, dest) == false) {
			temp.push_back(subroot->element);
		}
		preOrderIntersection(subroot->left, dest);
		preOrderIntersection(subroot->right, dest);
	}
	for (int i = 0; i < temp.size(); i++) {
		remove(temp[i]);
	}
}

// Time complexity n
// Space complexity n
void BSTSet::intersection(const BSTSet& s)
{
	// TODO
	if (root == NULL || s.root == NULL) {
		root = NULL;
	}
	else {
		preOrderIntersection(root, s.root);
	}

}

// Time complexity n
// Space complexity n
void BSTSet::preOrderDifference(TNode* subroot, TNode* dest) {
	std::vector<int> temp;
	if (subroot != NULL) {
		if (isInTree(subroot->element, dest) == true) {
			temp.push_back(subroot->element);
		}
		preOrderDifference(subroot->left, dest);
		preOrderDifference(subroot->right, dest);
	}
	for (int i = 0; i < temp.size(); i++) {
		remove(temp[i]);
	}
}

void BSTSet::difference(const BSTSet& s)
{
	// TODO
	preOrderDifference(root, s.root);
}

void preOrderSize(TNode* subroot, int& count) {
	if (subroot != NULL) {
		count++;
		preOrderSize(subroot->left, count);
		preOrderSize(subroot->right, count);
	}
}

// Time complexity n
// Space complexity 1
int BSTSet::size()
{
	// TODO
	int count = 0;
	preOrderSize(root, count);
	return count; //change this after completing this function
}

int findHeight(TNode* t) {
	if (t == NULL) {
		return -1;
	}
	else {
		int leftHeight = findHeight(t->left);
		int rightHeight = findHeight(t->right);

		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		}
		else {
			return rightHeight + 1;
		}
	}
}

// Time complexity n
// Space complexity 1
int BSTSet::height()
{
	// TODO
	int height = 0;
	if (root == NULL) {
		return -1;
	}
	else {
		height = findHeight(root);
	}
	return height; //change this after completing this function
}

// create and use class MyStack
// Time complexity n^2
// Space complexity n
void BSTSet::printNonRec()
{
	// TODO
	ArrayStack s;
	TNode* current = root;
	while (current != NULL || s.isEmpty() == false) {
		while (current != NULL) {
			s.push(current);
			current = current->left;
		}
		current = s.top();
		cout << current->element << ",";
		current = current->right;
		s.pop();
	}
}

// Do not modify following provided methods

void BSTSet::printBSTSet()
{
	if (root == NULL)
		std::cout << "";
	else {
		printBSTSet(root);
	}
}

void BSTSet::printBSTSet(TNode* t)
{
	if (t != NULL) {
		printBSTSet(t->left);
		std::cout << t->element << ",";
		printBSTSet(t->right);
	}
}
