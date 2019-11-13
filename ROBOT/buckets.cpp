// buckets.cpp
// Drew Bies
// username: abies2
// Implementation of ADT Buckets
//    data object: buckets with one pebble in each bucket
//    operations:	Buckets(int numberBuckets)
//					~Buckets()
//					look (Pebble& color, int bucketNumber)
//					swap(int leftBucket, int rightBucket)
//					fillBuckets()

#include "buckets.h"
#include <cstdlib>
#include <iostream>
using namespace std;

struct Node
{
	Node* previous;
	Node* next;
	Pebble color;
};

struct BucketStuff
{
	Node* frontptr;
    Node* backptr;
	int numberOfBuckets;
};

// helper function for the constructor
void addAtFront(Node*& firstptr, Node*& lastptr)
{
	Node* newptr;
	newptr = new Node;
	newptr -> next = nullptr;
	newptr -> previous = nullptr;
	if(firstptr == nullptr)
	{
		firstptr = newptr;
		lastptr = newptr;
	}
	else
	{
		newptr -> next = firstptr;
		firstptr -> previous = newptr;
		firstptr = newptr;
	}
}

// helper function for the deconstructor
void deleteAtBack(Node*& firstptr, Node*& lastptr)
{
	Node* delptr;
	delptr = lastptr;
	if(firstptr == lastptr)
	{
		firstptr = nullptr;
		lastptr = nullptr;
	}
	else
	{
		lastptr = lastptr -> previous;
		delptr -> previous -> next = nullptr;
		delptr -> previous = nullptr;
	}
	delete delptr;
}

// helper function for look and swap
// "left arm"
void pointFromLeft(Node*& ptr, int index)
{
	for(int i = 0; i < index; i++)
	{
		ptr = ptr -> next;
	}
}

// helper function for look and swap
// "right arm"
void pointFromRight(Node*& ptr, int index, int numBuckets)
{
	int reverseIndex = numBuckets - index;
	for(int i = 0; i < reverseIndex; i++)
	{
		ptr = ptr -> previous;
	}
}

// Adam and Drew
// creates the buckets in front of the robot
// pre: buckets exists
// post: empty Buckets are made
// usage: Buckets(10) b;
Buckets::Buckets(int numberBuckets)
{
	buckets = new BucketStuff;
	buckets -> frontptr = nullptr;
	buckets -> backptr = nullptr;
	buckets -> numberOfBuckets = numberBuckets;
   
	for(int i = 0; i < numberBuckets; i++)
	{
		addAtFront(buckets -> frontptr, buckets -> backptr);
	}
}

//Bo and Matt
// destroys the buckets object
// pre: buckets object exists
// post: buckets object does not exist
// usage: automatically done at the end of scope 
Buckets::~Buckets()
{
   for(int i = 0; i < buckets -> numberOfBuckets; i++)
   {
	   deleteAtBack(buckets -> frontptr, buckets -> backptr);
   }
   delete buckets;
}

//Andrew and Scott
//looks inside the bucket and determines what color 
//  the pebble is assigned and bucketNumber is between 1 and the total number of buckets
//pre: the struct of buckets has been created and there is a red, white, or blue pebble in each of the buckets
//post: the color of the pebble is returned from where that pebble is located 
//usage: look(color, 13);
void Buckets::look (Pebble& color, int bucketNumber)
{
	Node* newptr;
	int total = buckets -> numberOfBuckets;
	if(bucketNumber <= (total / 2))
	{
		newptr = buckets -> frontptr;
		pointFromLeft(newptr, bucketNumber - 1);
	} 
	else
	{
		newptr = buckets -> backptr;
		pointFromRight(newptr, bucketNumber, buckets -> numberOfBuckets);
	}
	color = newptr -> color;
}

//Evan and Ryan
//pre: leftBucket and rightBucket are positions of buckets
//			leftBucket and rightBucket are between 1 and the total number of buckets
//post: the contents at position leftBucket has been switched with the contents at position rightBucket
//		robot's left arm finds position of leftBucket starting from the left
//		robot's right arm finds position of rightBucket starting from the right
//usage: swap(leftBucket, rightBucket);
void Buckets::swap(int leftBucket, int rightBucket)
{
	Pebble temp;
	Node* oneptr;
	oneptr = buckets -> frontptr;
	Node* twoptr;
	twoptr = buckets -> backptr;
	pointFromLeft(oneptr, leftBucket - 1);
	pointFromRight(twoptr, rightBucket, buckets -> numberOfBuckets);
	temp = oneptr -> color;
	oneptr -> color = twoptr -> color;
	twoptr -> color = temp;
}

//Megan, Alli, Esther
//Puts a random color pebble in each bucket
//pre: buckets have been created and are in front of robot
//post: all buckets contain one pebble
//usage: robot.fillBuckets();
void Buckets::fillBuckets()
{ 
	Node* helperptr = buckets -> frontptr;
	
	for(int i = 0; i < buckets -> numberOfBuckets; i++)
	{		
		int randInt = rand() % 3;
		if(randInt == 0)
		{
			helperptr -> color = RED;
		}
		else if(randInt == 1)
		{
			helperptr -> color = WHITE;
		} 
		else
		{
			helperptr -> color = BLUE;
		}
		helperptr = helperptr -> next;
	}	
}





