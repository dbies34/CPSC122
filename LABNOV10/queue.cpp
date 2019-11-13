// author Dr Y and CPSC 122 Fall 2017
// date: November 6, 2017
// file queue.cpp

//   Specification for ADT Queue
//   data object: a queue which is a First In First Out List
//   operations: create, destroy, check if empty, copy
//               (finish)

#include <iostream>
#include <cstdlib>
#include "queue.h"
using namespace std;

struct Node
{
	ItemType item;
	Node* next;
};



	
//outputs a queue to a file or the screen
//pre  : rhsq exists. output is open.
//post : contents of rhsq have been output
//usage: cout << rhsq << endl;
ostream& operator<< (ostream& output, const Queue& rhsq)
{
	if(rhsq.isEmpty())
	{
		output << "The queue is empty!" << endl;
	} else{
		Node* frontptr = rhsq.backptr -> next;
		while(frontptr != rhsq.backptr)
		{
			output << frontptr -> item << endl;
			frontptr = frontptr -> next;
		}
		output << frontptr -> item << endl;
	}
	return output;
}



//creates an empty queue
//post : an empty queue
//usage: Queue q;
Queue::Queue()
{
   backptr = nullptr;
}
   
//copies an existing queue
//pre  : rhsq exists
//post : queue object is a copy of rhsq
//usage: Queue q(anotherq); or passing a Que object by value
Queue::Queue(const Queue& rhsq) // contructor
{
	   
}
   
//destroys a queue
//pre  : queue object exists
//post : queue object does not exist
//usage: automatically done at the end of scope
Queue::~Queue()
{
   while(!isEmpty())
   {
	   deleteAtFront();
   }
}
   
//finds the size of a queue object
//pre  : queue object exists
//post : returns the size of the queue object
//usage: cout << q.getSize();
int Queue::getSize() const
{
	Node* frontptr;
	int size = 1; // test
	frontptr = backptr -> next;
	while(frontptr != backptr)
	{
		frontptr = frontptr -> next;
		size++;
	}
	return size;
}
   
//checks to see if a queue object is empty
//pre  : queue object exists
//post : if queue is empty returns true else returns false
//usage: if (q.isEmpty())
bool Queue::isEmpty() const
{
    return (backptr == nullptr);
}
   
//inserts a new item at the rear of the queue
//pre  : newItem has an assigned value; queue exists
//post : if queue object is not full, newItem is added
//       at the rear of the queue and notFull is true else notFull is false
void Queue::lineUp(ItemType newItem, bool& isAdded)
{
	Node* newptr;
	newptr = new (nothrow) Node;
	if(newptr == nullptr) // no memory available in heap 
	{
		isAdded = false;
	} else{
		isAdded = true;
		newptr -> item = newItem;
		if(isEmpty())
		{			
			newptr -> next = newptr;
			backptr = newptr;
		} else{
			newptr -> next = backptr -> next;
			backptr -> next = newptr;
			backptr = newptr;
		}
	}
}
   
//deletes item from the front of the queue 
//pre  : queue exists
//post : if queue is nonempty, front of queue has been removed
//         and isNotEmpty is true else isNotEmpty is false
void Queue::deleteAtFront()
{
	if(!isEmpty())
	{
		Node* newptr;
		newptr = backptr -> next -> next;
		delete backptr -> next;
		backptr = newptr;
	}
}
   
//copies the front item
//pre  : queue exists and is not empty
//post : the front item in the queue is copied into frontItem
void Queue::serve(ItemType& frontItem)
{
	frontItem = backptr -> next -> item;
}
   
//copies the queue
//pre  : rhsq exists. queue object exists but may be empty
//post : queue object is a copy of rhsq
//usage: copyq.operator=(rhsq);
//      or        copyq = rhsq;
Queue& Queue::operator=(const Queue& rhsq)
{
	Node* helperptr;
	bool isOk;
	
	if(backptr != nullptr)
	{
		// deconstruct old queue
		while(!isEmpty())
		{
			deleteAtFront();
		}
		backptr = nullptr;
	}
	
	if(this != &rhsq)
	{
		if(!rhsq.isEmpty())
		{
			helperptr = rhsq.backptr -> next;
			lineUp(helperptr -> item, isOk);
			while(helperptr != rhsq.backptr)
			{
				helperptr = helperptr -> next;
				lineUp(helperptr -> item, isOk);
			}
		}
	}
	return *this;
}