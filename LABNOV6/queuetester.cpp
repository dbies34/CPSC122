// queuetester.cpp

#include "queue.h"

int main()
{
	Queue aq;
	bool isAdded;
	ItemType it;
	
	it = 5;
	aq.lineUp(it, isAdded);
	cout << aq << endl;
	
	return 0;
}