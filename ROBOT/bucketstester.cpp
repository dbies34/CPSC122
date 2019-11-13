// bucketstester.cpp

#include "buckets.h"
#include <iostream>
#include <string>
using namespace std;

// helper printer function
void printBuckets(Buckets& b, int total)
{
	Pebble color;
	for(int i = 1; i <= total; i++)
	{		
		b.look(color, i);
		
		if(color == RED)
		{
			cout << "Red ";
		}
		else if(color == WHITE)
		{
			cout << "White ";
		}
		else
		{
			cout << "Blue ";
		}
	}
	cout << endl;
}

void printLines(int num)
{
	for(int i = 0; i < num; i++)
	{
		cout << endl;
	}
}


int main()
{
	int num = 10;
	Pebble color;
	
	Buckets buckets(num);
	
	buckets.fillBuckets();
	
	printLines(3);
	
	cout << "before swap: ";
	printBuckets(buckets, num);
	
	printLines(3);
	buckets.swap(3, 6);
	
	cout << "swap buckets 3 and 6." << endl;
	
	printLines(2);
	
	cout << "after swap: ";
	printBuckets(buckets, num);
	printLines(3);
	
	return 0;
}