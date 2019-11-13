// stack.cpp
// Drew Bies, Chris Martin
// username: abies2
// Abstract Data Type Stack: 
//    data object is a stack where the most-recently-added (or top) item
//                is most-easily accessible
//    operations on a stack:
//        create an empty stack
//        delete memory or "destroy" the stack
//        add a new item as the most-recently-added or top item
//        retrieve the most-recently-added or top item from the stack and copy
//        remove the most-recently-added (or top item) from the stack
//        check if the stack is empty
//        print the stack

#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

struct Node
{
   ItemType item;
   Node* next;
};

// creates an empty stack (called the constructor)
Stack::Stack()
{
	stackptr = nullptr;
	stackptr = new Node;
}
   
// destroys the stack (called the destructor)
// code after pop() is tested
Stack::~Stack()
{
	while(!isEmpty())
	{
		pop();
	}
}

// adds a new item as the most-recently added or top item
// pre: newItem has been assigned; stack object exists
// post: if the stack is not full, newItem is added at the top
//          and isAdded is true; else isAdded is false
void Stack::push (ItemType newItem, bool& isAdded)
{
	if(isEmpty())
	{
		stackptr = new Node;
		stackptr -> item = newItem;
		stackptr -> next = nullptr;
	} else{
		helperptr = new Node;
		helperptr -> item = newItem;
		helperptr -> next = stackptr;
		stackptr = helperptr;
	}
	isAdded = true;
}
   
// removes the most-recently-added or top item
// pre: stack object exists and is not empty
// post: most-recently added or top item has been removed from the stack 
void Stack::pop()
{
	helperptr = stackptr -> next;
	delete stackptr;
	stackptr = helperptr;
}

// copies the most-recently added or top item from the stack
// pre: stack object exists and is not empty
// post: top item has been copied into topItem. stack is unchanged.
void Stack::retrieve(ItemType& topItem)
{
	topItem = stackptr -> item;
}
 
// checks whether or not a stack is empty
// pre: stack object exists
// post: if stack object is empty then returns true; else returns false
bool Stack::isEmpty()
{
	if(stackptr == nullptr)
	{
		return true;
	} else{
		return false;
	}
}

// prints the stack so that the top of the stack is at the "top" of the output
   // pre: stack object exists and may be empty
   // post: if stack is empty, output is "stack is empty" 
   //       else output shows user stack as it is 
   //       For example: if the stack is bottom to top: c b a
   //                    then output is
   //                    a
   //                    b
   //                    c
void Stack::print()
{
	ItemType top;
	
	if(isEmpty())
	{
		cout << "stack is empty" << endl;
	} else{	
		while(!isEmpty())
		{
		retrieve(top);
		cout << top << endl;
		pop();
		}
	}
}