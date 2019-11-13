//robotsort.cpp
//Drew Bies
//username: abies2
// description: robotsort.cpp creates two buckets and fills them with random pebbles.
//				the two buckets are printed onto the screen and then sorted using the 
//				robotSort function. they are again printed onto the screen to show that
//				they are sorted like the Dutch flag.


#include "buckets.h"
#include <iostream>
using namespace std;


// runs the example
// pre: none
// post: an example of before and after of the robotSort function have printed to the screen
// usage: runExample();
void runExample();

// sorts the pebbles using the robot
// pre: pebbles is assigned. howManyBuckets is assigned
// post: the colors from pebbles is sorted into red, white, and then blue
// usage: robotSort(pebbles, howManyBuckets);
void robotSort(Buckets& pebbles, int howManyBuckets);

// prints the pebbles of the buckets
// pre: pebbles is assigned. howManyBuckets is assigned
// post: the colors of pebbles has been printed onto the screen
// usage: printPebblesInBuckets(pebbles, howManyBuckets);
void printPebblesInBuckets(Buckets& pebbles, int howManyBuckets);

// finds the last color in the buckets
// pre: pebbles is assigned. color is assigned. howManyBuckets is assigned. index is assigned.
// post: searches through pebbles to find the last color and saves it as index
// usage: findLastColor(pebbles, color, howManyBuckets, index);
void findLastColor(Buckets& pebbles, Pebble color, int howManyBuckets, int& index);

// prints new lines
// pre: num is positive and assigned
// post: num amount of lines are printed onto the screen
// usage: printLines(10);
void printLines(int num);


int main()
{
	printLines(4);
	
	runExample();
	printLines(3);
	
	return 0;
}

// runs the example
// pre: none
// post: an example of before and after of the robotSort function have printed to the screen
// usage: runExample();
void runExample()
{
	Buckets bucketOne(10);
	Buckets bucketTwo(12);
	
	bucketOne.fillBuckets();
	bucketTwo.fillBuckets();
	
	cout << "Before: " << endl;
	printLines(1);
	
	cout << "   Bucket one: "; 
	printPebblesInBuckets(bucketOne, 10);
	
	cout << "   Bucket two: ";
	printPebblesInBuckets(bucketTwo, 12);
	
	robotSort(bucketOne, 10);
	robotSort(bucketTwo, 12);
	
	cout << "After Robot Sort: " << endl;
	printLines(1);
	
	cout << "   Bucket one: ";
	printPebblesInBuckets(bucketOne, 10);
	
	cout << "   Bucket two: ";
	printPebblesInBuckets(bucketTwo, 12);
}

// sorts the pebbles using the robot
// pre: pebbles is assigned. howManyBuckets is assigned
// post: the colors from pebbles is sorted into red, white, and then blue
// usage: robotSort(pebbles, howManyBuckets);
void robotSort(Buckets& pebbles, int howManyBuckets)
{
	int lastRed, lastWhite, firstMixed;
	Pebble color;
	
	findLastColor(pebbles, RED, howManyBuckets, lastRed);
	findLastColor(pebbles, WHITE, howManyBuckets, lastWhite);
	
    firstMixed = 1;

    while (firstMixed <= howManyBuckets)
    {
		pebbles.look(color, firstMixed);
        if (color == RED)
		{
			
		}
        else if (color == WHITE)
		{
			if(firstMixed < lastRed)
			{
				pebbles.swap(firstMixed, lastRed);
			}
		}
        else // its BLUE
		{
			if(firstMixed < lastRed)
			{
				pebbles.swap(firstMixed, lastRed);
			}
			else if (firstMixed < lastWhite)
			{
				pebbles.swap(firstMixed, lastWhite);
			}
		}
		findLastColor(pebbles, RED, howManyBuckets, lastRed);
		findLastColor(pebbles, WHITE, howManyBuckets, lastWhite);
        firstMixed++;
    }
}

// prints the pebbles of the buckets
// pre: pebbles is assigned. howManyBuckets is assigned
// post: the colors of pebbles has been printed onto the screen
// usage: printPebblesInBuckets(pebbles, howManyBuckets);
void printPebblesInBuckets(Buckets& pebbles, int howManyBuckets)
{
	Pebble newPebble;
	for(int i = 1; i <= howManyBuckets; i++)
	{
		pebbles.look(newPebble, i);
		if(newPebble == RED)
		{
			cout << "Red ";
		}
		else if(newPebble == WHITE)
		{
			cout << "White ";
		}
		else
		{
			cout << "Blue ";
		}
	}
	printLines(4);
}

// finds the last color in the buckets
// pre: pebbles is assigned. color is assigned. howManyBuckets is assigned. index is assigned.
// post: searches through pebbles to find the last color and saves it as index
// usage: findLastColor(pebbles, color, howManyBuckets, index);
void findLastColor(Buckets& pebbles, Pebble color, int howManyBuckets, int& index)
{
	Pebble temp;
	for(int i = 1; i <= howManyBuckets; i++)
	{
		pebbles.look(temp, i);
		if(color == temp)
		{
			index = i;
		}
	}
}
// prints new lines
// pre: num is positive and assigned
// post: num amount of lines are printed onto the screen
// usage: printLines(10);
void printLines(int num)
{
	for(int i = 0; i < num; i++)
	{
		cout << endl;
	}
}