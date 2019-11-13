// ADT List
//    data object: a list of items such that there is a 1st, 2nd,...
//    operations: add new item anywhere, delete any item,
//                retrieve any item, check to see if it's empty,
//                create a list, release memory for a list, copy a list

#include "list.h"
#include <cstdlib>
using namespace std;

struct Node
{
	ItemType item;
	Node* next;
	Node* previous;
};

struct ListStuff
{
	Node* frontptr;
	Node* backptr;
	int numberOfItems;
};
	
// prints a list
// pre: output is determined. rhsList is assigned
// post: the items in rhsList are printed with 1st, 2nd, ... , one per line
// usage: cout << mylist;		
ostream& operator<< (ostream& output, const List& rhsList)
{
	if(rhsList.isEmpty()){
		output << "The list is empty!" << endl;
	} else{
		
	}
	return output;
}

// creates an empty list
// post: list object is empty
// usage: List mylist;
List::List()
{
   listptr = new ListStuff;
   listptr -> frontptr = nullptr;
   listptr -> backptr = nullptr;
   listptr -> numberOfItems = 0;   
}

// creates an empty list
// post: list object is empty
// usage: List mylist;
List::~List()
{
	/* must wait until deleteItemAnywhere is coded and tested
	int numberTimes = listptr -> numberOfItems
	for (int num = 0; num < numberTimes; num++)
	{
	   deleteItemAnywhere(1);
	}
	*/
}


// copies a list, allows pass by value_comp
// pre: rhsList exists
// post: list object is a copy of rhsList
// usage  void doIt(List mylist);
List::List(const List& rhsList)
{
   listptr = new ListStuff;
   listptr -> frontptr = nullptr;
   listptr -> backptr = nullptr;
   listptr -> numberOfItems = 0;   
   operator=(rhsList);
}

// adds a new item anywhere in the list
// pre: newitem has been assigned
//      newPosition >= 1 and newPosition <= size of list + 1st
// post: if there is memory in the heap, isAdded is true and
//       newitem has been added to the list object in position newPosition
//       else isAdded is false
// usage: mylist.addItem(newitem, 3, isAdded);
void List::addItem(ItemType newitem, int newPosition, bool& isAdded)
{
	Node* newptr = new (nothrow) Node;
	if (newptr != nullptr) // list is not full
	{
		isAdded = true;
 
        if (isEmpty())
        {
	       listptr -> frontptr = newptr;
		   listptr -> backptr = newptr;
		   listptr -> numberOfItems = 1;
		   newptr -> item = newitem;
		   newptr -> next = nullptr;
		   newptr -> previous = nullptr;
	    } else if (newPosition == 1) {
			listptr -> frontptr -> previous = newptr;
			newptr -> next = listptr -> frontptr;
			listptr -> frontptr = newptr;
	    } else if (newPosition == listptr -> numberOfItems + 1) {
			listptr -> backptr -> next = newptr;
			newptr -> previous = listptr -> backptr;
			listptr -> backptr = newptr;
		} else {// newPosition > 1 and newPosition <= size of list 
			Node* helptr = listptr -> frontptr;
			for(int i = 1; i < newPosition; i++)
			{
				helptr = helptr -> next;
			}
			helptr -> previous -> next = newptr;
			newptr -> previous = helptr -> previous;
			newptr -> next = helptr;
			helptr -> previous = newptr;
		}
	} else {
		isAdded = false;
	}
}

// deletes an item in any position in the list
// pre: position >= 1 and position <= size of list
// post: item at position is removed from the list
// usage: mylist.deleteItemAnywhere(2);
void List::deleteItemAnywhere(int position)
{
	Node* delptr;
	
	if (listptr -> numberOfItems == 1)
	{
		delptr = listptr -> frontptr;
		listptr -> frontptr = nullptr;
		listptr -> backptr = nullptr;
	} else if (position == 1) {
		delptr = listptr -> frontptr;
	} else if (position == listptr -> numberOfItems) {
		delptr = listptr -> backptr;
	} else { // position is in the middle
		delptr = delptr -> frontptr;
		for(int i = 1; i < position; i++)
		{
			delptr = delptr -> next;
		}
	}
	delptr -> previous = nullptr;
	delptr -> next = nullptr;
	delete delptr;
}

// retrieves any item in a list
// pre: index >= 1 and index <= size of list
// post: item is the list's item at index
// usage: mylist.retrieve(item, 2);
void List::retrieve(ItemType& item, int index) const
{
	Node* retrieveptr = listptr -> frontptr;
	
	for (int k = 1; k < index; k++)
	{
		retrieveptr = retrieveptr -> next;
	}
	item = retrieveptr -> item;
}

// copies a list
// pre: rhsList is assigned. list object exists and may not be empty
// post: list object is a copy of rhsList
// usage: mylist = yourlist;
List& List::operator=(const List& rhsList)
{
	Node* currptr = listptr -> frontptr;
	bool isAdded;
	
	if (this != &rhsList)
	{
		// delete all of the nodes of object to be copied to
		int numberTimes = listptr -> numberOfItems;
		for (int num = 0; num < numberTimes; num++)
		{
			deleteItemAnywhere(1);
		}
		// assuming deleteItemAnywhere is correct or it is already an empty object, we should have 
		// listptr -> frontptr = nullptr; listptr -> backptr = nullptr; listptr -> numberOfItems = 0
		
		// copy items from rhsList
		for (int position = 1; position <= rhsList.listptr -> numberOfItems; position++)
		{
			addItem(currptr -> item, position, isAdded);
			currptr = currptr -> next;
		}
	}
	return *this;
}

// checks if a list is empty or not
// pre: list object exists
// post: returns true if list object is empty; else false
// usage: if (mylist.isEmpty())
bool List::isEmpty() const
{
	return (numberOfItems == 0);
}