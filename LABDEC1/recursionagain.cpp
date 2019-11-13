// file recursionagain.cpp
// description: this program codes and tests functions on linked list
//              Each of the functions, except addAtFront, will be coded recursively
// date: December 1, 2017


#include <cstdlib>    
#include <iostream>
using namespace std;

typedef int ItemType;

struct Node
{
   ItemType item;
   Node* next;
};

// you write the documentation then decide on pass by value or by reference

// adds a new item at the front
// pre: headptr has been assigned. newguy has been assigned 
// post: newguy is added to the front of the headptr 
// usage: addAtFront(aPointer, 34);
void addAtFront(Node*& headptr, ItemType newguy);

// prints the list
// pre: headptr is a assigned
// post: items in headptr's list have been printed on one line
// usage: printList(aPointer);
void printList(Node* headptr);

void printListInReverse(Node* headptr);

// finds the sum
// pre: headptr is assigned
// post: returns the sum of the headptr's list
// usage: findSum(aPointer);
int findSum(Node* headptr);

// 
// pre
// post
// usage
int findMinimum (Node* headptr);

// retrieves the last item in the list
// pre: headptr is assigned to a non-empty list
// post: returns the last item in headptr's list
// usage: cout << retrieveLast(aPointer);
int retrieveLast(Node* headptr);

// 
// pre
// post
// usage
void freeThem(Node* headptr);

int main()
{
    Node* headptr;
	ItemType newItem;
   
    headptr = nullptr;
   
    addAtFront(headptr, 9);
    addAtFront(headptr, 7);
    addAtFront(headptr, 5);
    addAtFront(headptr, 3);
    printList (headptr);
	cout << "In Reverse: ";
	printListInReverse(headptr);
	cout << endl;
   
    if(headptr != nullptr)
	{
		
		
		newItem = retrieveLast(headptr);
		cout << "Last item: " << newItem << endl;
		
		newItem = findMinimum(headptr);
		cout << "Minimum: " << newItem << endl;
		
		newItem = findSum(headptr);
		cout << "Sum: " << newItem << endl;
	}
	
	freeThem(headptr);
	
   return 0;
}

// prints the list
// pre: headptr is a assigned
// post: items in headptr's list have been printed on one line
// usage: printList(aPointer);
void printList(Node* headptr)
{
	if(headptr != nullptr)
	{
		cout << headptr -> item << " ";
		printList(headptr -> next);
	} else{
		cout << endl;
	}
}

void printListInReverse(Node* headptr)
{
	if(headptr != nullptr)
	{
		printListInReverse(headptr -> next);
		cout << headptr -> item << " ";
	}
}

// adds a new item at the front
// pre: headptr has been assigned. newguy has been assigned 
// post: newguy is added to the front of the headptr 
// usage: addAtFront(aPointer, 34);
void addAtFront(Node*& headptr, ItemType newguy)
{
	Node* newptr;
	
	newptr = new Node;
	newptr -> item = newguy;
	newptr -> next = headptr;
	headptr = newptr;
}

// finds the sum
// pre: headptr is assigned to a non-empty list
// post: returns the sum of the headptr's list
// usage: findSum(aPointer);
int findSum(Node* headptr)
{
	if(headptr -> next == nullptr)
	{
		return headptr -> item;
	} else{
		headptr -> next -> item += headptr -> item;
		return findSum(headptr -> next);
	}
}

// finds the minimum
// pre: headptr is assigned to a non-empty list
// post: returns the smallest item in headptr's list
// usage: cout << findMinimum(aPointer) << endl;
int findMinimum (Node* headptr)
{
	if(headptr -> next == nullptr)
	{
		return headptr -> item;
	} else{
		ItemType minOfRest = findMinimum(headptr -> next);
		if(headptr -> item < minOfRest)
		{
			return headptr -> next;
		} else{
			return minOfRest;
		}
	}
}

// retrieves the last item in the list
// pre: headptr is assigned to a non-empty list
// post: returns the last item in headptr's list
// usage: cout << retrieveLast(aPointer);
int retrieveLast(Node* headptr)
{
	if(headptr -> next == nullptr)
	{
		return headptr -> item;
	} else{
		return retrieveLast(headptr -> next);
	}
}

// 
// pre
// post
// usage
void freeThem(Node* headptr)
{
	while (headptr != nullptr)
	{
		Node* delptr = headptr;
		headptr = headptr -> next;
		delete delptr;
	}		
}