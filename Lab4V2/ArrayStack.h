#include "TNode.h"


class ArrayStack
{
private:
	int capacity;
	TNode** items;
	int topIndex = -1;
public:
	ArrayStack(){
		items = new TNode * [100];
		capacity = 100;
	}
	ArrayStack(int n) {
		items = new TNode*[n];
		capacity = n;
	}
	~ArrayStack() {
		delete[] items;
	}
	bool isEmpty();
	void push(TNode*& e);
	TNode* top();
	TNode* pop();
};

