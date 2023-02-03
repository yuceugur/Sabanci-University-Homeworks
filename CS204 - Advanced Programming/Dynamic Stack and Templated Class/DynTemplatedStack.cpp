#include <iostream>
#include "DynTemplatedStack.h"
using namespace std;

//************************************************
// Constructor to generate an empty stack.       *
//************************************************
template <class t_type>
DynTemplatedStack<t_type>::DynTemplatedStack()
{
	top = NULL; 
}

//************************************************
// Member function push pushes the argument onto *
// the stack.                                    *
//************************************************
template <class t_type>
void DynTemplatedStack<t_type>::push(t_type num)
{
	StackNode<t_type> *newNode;

	// Allocate a new node & store Num
	newNode = new StackNode<t_type>;
	newNode->value = num;

	// If there are no nodes in the list
	// make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = NULL;
	}
	else	// Otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************

template <class t_type>
void DynTemplatedStack<t_type>::pop(t_type &num)
{
	StackNode<t_type> *temp;

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else	// pop value off top of stack
	{
		num = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}

//****************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************
template <class t_type>
bool DynTemplatedStack<t_type>::isEmpty(void)
{
	bool status;

	if (top == NULL)
		status = true;
	else
		status = false;

	return status;
}

