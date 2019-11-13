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
	aq.lineUp('g', isAdded);
	aq.lineUp('w', isAdded);
	cout << aq << endl;
	
	copy = aq;
	cout << "copy" << endl;
	cout << copy << endl;
	
	size = aq.getSize();
	cout << "Size: " << size << endl;
	
	cout << "one less: " << endl;
	aq.deleteAtFront();
	
	size = aq.getSize();
	cout << "Size: " << size << endl;
	
	cout << aq << endl;
	
	while(!aq.isEmpty())
	{
		aq.deleteAtFront();
	}
	cout << aq << endl;
	
	Queue c(copy);
	
	
	return 0;
}