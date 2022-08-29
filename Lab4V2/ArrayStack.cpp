#include "ArrayStack.h"
#include <stdexcept>

bool ArrayStack::isEmpty() {
	return (topIndex < 0);
}


void ArrayStack::push(TNode*& e) {
	if (topIndex == capacity - 1) {
		TNode** newArray = new TNode * [2 * capacity];
		for (int i = 0; i < capacity; i++) {
			newArray[i] = items[i];
		}
		delete[] items;
		items = newArray;
		capacity *= 2;
	}
	items[++topIndex] = e;
}


TNode* ArrayStack::top() {
	if (isEmpty()) {
		throw std::underflow_error("stack underflow");
	}
	else {
		return (items[topIndex]);
	}
}


TNode* ArrayStack::pop() {
	if (isEmpty()) {
		throw std::underflow_error("stack underflow");
	}
	else {
		TNode* tempE = items[topIndex];
		topIndex--;
		return(tempE);
	}
}