//@file linkedplay.cpp
//@date: Oct 6, 2017    
//@author Dr Y
//@YOU DO

#include <cstdlib>     // for the use of new and delete
#include <iostream>
using namespace std;

typedef int ItemType;

struct Node
{
   ItemType item;
   Node* next;
};

void printList(Node* headptr);

int main()
{
   Node* headptr;
   
   headptr = nullptr;
   
   cout << "contents of headptr " << headptr << endl;
   headptr = new Node;
   cout << "contents of headptr " << headptr << endl;
   
   (*headptr).item = 6;
   (*headptr).next = nullptr;
   cout << "item in first node " << (*headptr).item << endl;
   
   headptr -> item = 12; // headptr -> item == (*headptr).item
   cout << "item in first node " << (*headptr).item << endl;
   
   headptr -> next = new Node;
   cout << headptr -> next << endl;
   
   headptr -> next -> item = 17;
   headptr -> next -> next = nullptr;
   cout << "item in second node " << headptr -> next -> item << endl;
   
   headptr -> next -> next = new Node;
   cout << headptr -> next -> next << endl;
   
   headptr -> next -> next -> item = 70;
   headptr -> next -> next -> next = nullptr;
   
   cout << "calling print list " << endl;
   printList(headptr);
   
   return 0;
}

void printList(Node* headptr)
{
	while(headptr != nullptr)
	{
		cout << headptr -> item << endl;
		headptr = headptr -> next;
	}
}
   