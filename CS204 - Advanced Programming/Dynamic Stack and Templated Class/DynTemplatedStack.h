#ifndef _DYNTEMPLATEDSTACK_H
#define _DYNTEMPLATEDSTACK_H
template <class my_type>
struct StackNode
{
	my_type value;
	StackNode *next;
};


template <class my_type>
class DynTemplatedStack
{
private:
	StackNode<my_type> *top;

public:
	DynTemplatedStack(void);
	void push(my_type);
	void pop(my_type &);
	bool isEmpty(void);
};
#endif