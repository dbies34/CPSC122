// Implementation of ADT Buckets
//    data object: buckets with one pebble in each bucket
//    operations:

struct BucketStuff
{
	Node* frontptr;
	int numberOfBuckets;
};

struct Node
{
	Node* previous;
	Node* next;
	Pebble color;
};

enum Pebble {RED, WHITE, BLUE};

// Adam and Drew
// creates the buckets in front of the robot
// pre: none
// post: 6 empty Buckets are made
// usage: Buckets b;
Buckets::Buckets()
{
	buckets -> numberOfBuckets = 6;
	Node* newptr;
	newptr = new Node;
	buckets -> frontptr = newptr;
	newptr -> previous = buckets;
	newptr -> next = nullptr;
	Node* prevptr;
	prevptr = newptr;
	
	for(int i = 0; i < numberOfBuckets; i++)
	{
		Node* helperptr;
		helperptr = new Node;
		heplertpr -> previous = prevptr;
		helperptr -> next = nullptr;
		prevptr = helperptr;
	}
	
}

//Bo and Matt
// trashes the buckets 
~Buckets()
{
	
}

//Andrew and Scott
void look (Pebble& color, int bucketNumber)
{
	Node* newptr;
	newptr = buckts -> frontptr -> next;
	for(int i = 0; i < bucketNumber; i++)
	{
		newptr = newptr -> next;
	}
	color = newptr -> color;
}

//Evan and Ryan
void swap(int bucket1, int bucket2)
{
	
}

//Megan, Alli, Esther
// puts a random pebble in each bucket
void fillBuckets()
{
	
}





