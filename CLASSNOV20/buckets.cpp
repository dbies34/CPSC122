// Implementation of ADT Buckets
//    data object: buckets with one pebble in each bucket
//    operations:

struct BucketStuff
{
	Node* frontptr;
    Node* backptr;
	int numberOfBuckets;
};

struct Node
{
	Node* previous;
	Node* next;
	Pebble color;
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
	} else{
		newptr -> next = firstptr;
		firstptr -> previous = newptr;
		firstptr = newptr;
	}
}

// helper function for the deconstructor
void deleteAtBack(Node*& firstptr, Node*& lastptr) // add special case for one node
{
	Node* delptr;
	delptr = lastptr;
	if(firstptr == lastptr)
	{
		buckets -> frontptr = nullptr;
		buckets -> backptr = nullptr;
	}
	else
	{
		delptr -> previous -> next = nullptr;
		delptr -> previous = nullptr;
	}
	delete delptr;
}

// helper function
void pointFromLeft(Node*& ptr, int index)
{
	for(int i = 1; i < index; i++)
	{
		ptr = ptr -> next;
	}
}

// helper function
void pointFromRight(Node*& ptr, int index)
{
	
	for(int i = 1; i < index; i++)
	{
		ptr = ptr -> next;
	}
}

// Adam and Drew
// creates the buckets in front of the robot
Buckets::Buckets(int numberBuckets)
{
	buckets = new BucketStuff;
	buckets -> frontptr = nullptr;
	buckets -> backptr = nullptr;
	buckets -> numberOfBuckets = numberBuckets;
   
	for(int i = 0; i > numberBuckets; i++)
	{
		addAtFront(buckets -> frontptr, buckets -> backptr);
	}
}

// Bo and Matt
// trashes the buckets 
Buckets::~Buckets()
{
   for(int i = 0; i < numberOfBuckets; i++)
   {
	   deleteAtBack(buckets -> frontptr, buckets -> backptr);
   }
   delete buckets;
}

// Andrew and Scott
void Buckets::look (Pebble& color, int bucketNumber)
{
	Node* newptr;
	newptr = buckets -> frontptr;
	pointFromLeft(newptr, bucketNumber);
	color = newptr -> color;
}

// Evan and Ryan
void Buckets::swap(int leftBucket, int rightBucket)
{
	Pebble temp;
	Node* oneptr, twoptr;
	pointFromLeft(oneptr, leftBucket);
	pointAtBucket(twoptr, rightBucket);
	temp = oneptr -> color;
	oneptr -> color = twoptr -> color;
	twoptr -> color = temp;
}

// Megan, Alli, Esther
// puts a random pebble in each bucket
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





