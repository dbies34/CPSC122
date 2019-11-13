// queuetester.cpp

#include "queue.h"

int main()
{
	Queue aq;
	Queue copy;
	bool isAdded;
	ItemType it;
	int size;
	
	it = 5;
	aq.lineUp(it, isAdded);
	aq.lineUp(6, isAdded);
	aq.lineUp(7, isAdded);
	cout << aq << endl;
	
	copy = aq;
	cout << "copy" << endl;
	cout << copy << endl;
	
	size = aq.getSize();
	cout << "Size: " << size << endl;
	
	
	aq.deleteAtFront();
	
	size = aq.getSize();
	cout << "Size: " << size << endl;
	cout << "one less: " << endl;
	cout << aq << endl;
	
	return 0;
}