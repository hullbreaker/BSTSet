template <typename E>
class Stack
{
public:
	virtual bool isEmpty() = 0;
	virtual E top() = 0;
	virtual void push(const E& e) = 0;
	virtual E pop() = 0;
};

