// ADT List
//    data object: a list of items such that there is a 1st, 2nd,...
//    operations: add new item anywhere, delete any item,
//                retrieve any item, check to see if it's empty,
//                create a list, release memory for a list, copy a list

#ifndef LIST_H
#define LIST_H

#include <string>
using namespace std;

typedef string ItemType;
struct ListStuff;

class List
{

// prints a list
// pre: output is determined. rhsList is assigned
// post: the items in rhsList are printed with 1st, 2nd, ... , one per line
// usage: cout << mylist;	
friend ostream& operator<< (ostream& output, const List& rhsList);

public:

// creates an empty list
// post: list object is empty
// usage: List mylist;
List();

// creates an empty list
// post: list object is empty
// usage: List mylist;
~List();

// copies a list, allows pass by value_comp
// pre: rhsList exists
// post: list object is a copy of rhsList
// usage  void doIt(List mylist);
List(const List& rhsList);

// adds a new item anywhere in the list
// pre: newitem has been assigned
//      newPosition >= 1 and newPosition <= size of list + 1st
// post: if there is memory in the heap, isAdded is true and
//       newitem has been added to the list object in position newPosition
//       else isAdded is false
// usage: mylist.addItem(newitem, 3, isAdded);
void addItem(ItemType newitem, int newPosition, bool& isAdded);

// deletes an item in any position in the list
// pre: position >= 1 and position <= size of list
// post: item at position is removed from the list
// usage: mylist.deleteItemAnywhere(2);
void deleteItemAnywhere(int position);

// retrieves any item in a list
// pre: index >= 1 and index <= size of list
// post: item is the list's item at index
// usage: mylist.retrieve(item, 2);
void retrieve(ItemType& item, int index) const;

// copies a list
// pre: rhsList is assigned. list object exists and may not be empty
// post: list object is a copy of rhsList
// usage: mylist = yourlist;
List& operator=(const List& rhsList);

// checks if a list is empty or not
// pre: list object exists
// post: returns true if list object is empty; else false
// usage: if (mylist.isEmpty())
bool isEmpty() const;

private:

ListStuff* listptr;

};
#endif