// all function must be done with recursive design
// There are NO loops anywhere

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int MAXSIZE = 5000;

// makes a list with either random integers or in ascending order
// pre: makeRandomly is assigned
// post: if makeRandomly then list[first..last] is assigned random integers
//       else list[first..last] is in sorted order
void createList(int list[], int first, int last, bool makeRandomly);

// prints a list in normal forward order
// pre: list[first..last] is assigned
// post: contents of list[first..last] are printed, one item per line after the index
void printList(int list[], int first, int last);

// gets the desired list size from the user
// post: user enters a list size after a prompt
int getListSize();

// gets the target to search for
// post: user enters a target integer to search for
int getTarget();

// prints a number of newlines
// pre: desiredNumber is assigned
// post: prints desiredNumber newlines on the screen
void printNewLines(int desiredNumber);

// finds the maximum value in a list of numbers
// pre: list[first..last] is assigned, first and last are non=negative integers
// post: returns the maximum value found in list[first..last]
int findMaximumValue(int list[], int first, int last);

// finds the mininum value in a list of numbers
// pre: list[first..last] is assigned
// post: returns the mininum value found in list[first..last]
int findMinimumValue(int list[], int first, int last);

// finds the sum of the numbers in a list
// pre: list[first..last] is assigned; first and last are nonnegative integers
// post: returns the sum of the numbers in list[first..last]
int sumIt(int list[], int first, int last);

// finds the product of the numbers in a list
// pre: list[first..last] is assigned values, 
// first and last are non-negative integers
// post: returns the product of the numbers in list[first..last]
// For example, if the list contains 3, 2, 5 then returns 30
int findProduct (int list[], int first, int last);

// prints a given number with a message
// pre: message and number are assigned
// post: prints number on the screen after message
void printOne(string message, int number);

// searches a list for a target
// pre: list[first..last] is assigned values, 
//      first and last are non-negative integers
// post: returns index of target in list and -1 if target is not found
int linearSearch(int list[], int target, int first, int last);

// searches a list for a target
// pre: list[first..last] is sorted into ascending order
// post: if target is found in list[first..last] then returns the corresponding index
//       else returns -1
int binarySearch(int list[], int target, int first, int last);

int main()
{
	int list[MAXSIZE];
    int listSize = 10;
	int target;
	srand(time(0));
	printNewLines(3);	
	
	createList(list, 0, listSize - 1, true);
    printList(list, 0, listSize - 1);
	printNewLines(2);
	
    printOne("Summing items in above list", sumIt(list, 0, listSize - 1));
    printNewLines(1);
	
    printOne("Multiplying items in above list", findProduct(list, 0, listSize - 1));
	printNewLines(2);
	
	printOne("Finding the greatest value in above list", findMaximumValue(list, 0, listSize - 1));
	printNewLines(1);
	
	printOne("Finding the smallest value in above list", findMinimumValue(list, 0, listSize - 1));
	printNewLines(5);
	
	createList(list, 0, listSize - 1, false);
	printList(list, 0, listSize - 1);	
	printNewLines(1);
	
	target = (rand() % 100 + 1) / 10 * 10;
	printOne("Target value for linear search", target);
	printNewLines(1);
	printOne("Index of the target in the list above using linear search", linearSearch(list, target, 0, listSize - 1));
	printNewLines(3);
	
	target = (rand() % 100 + 1) / 10 * 10;
	printOne("Target value for binary search", target);
	printNewLines(1);
	printOne("Index of the target in the list above using binary search", binarySearch(list, target, 0, listSize - 1));
	printNewLines(5);
	
	return 0;
}

// makes a list with either random integers or in ascending order
// pre: makeRandomly is assigned
// post: if makeRandomly then list[first..last] is assigned random integers
//       else list[first..last] is in sorted order
// usage: createList(list, 0, size - 1, true);
void createList(int list[], int first, int last, bool makeRandomly)
{
	if(first <= last)
	{
		if(makeRandomly)
		{
			list[first] = rand() % 1000;
			createList(list, first + 1, last, true);	   
		} else {
			list[first] = 10 * first;
			createList(list, first + 1, last, false);
		}
	}
}

// prints a list in normal forward order
// pre: list[first..last] is assigned
// post: contents of list[first..last] are printed, one item per line after the index
// usage: printList(list, 0, 3);
void printList(int list[], int first, int last)
{
	if (first == last)
	{                                            
		cout << setw(8) << first << ": " << setw(8) << list[first] << endl;
	} else {
		cout << setw(8) << first << ": " << setw(8) << list[first] << endl;		
		printList(list, first + 1, last);
	}
}

// gets the desired list size from the user
// post: user enters a list size after a prompt
// usage: size = getListSize();
int getListSize()
{
	int size;
	cout << "Enter the size of your list -> ";
	cin >> size;
	return size;
}

// gets the target to search for
// post: user enters a target integer to search for
// usage: target = getTarget();
int getTarget()
{
   int target;
   cout << "Enter the target value to search for -> ";
   cin >> target;
   return target;
   
}
// prints a number of newlines
// pre: desiredNumber is assigned
// post: prints desiredNumber newlines on the screen
// usage: printNewLines(4);
void printNewLines(int desiredNumber)
{
	if(desiredNumber == 1)
	{
		cout << endl;
	} else{
		cout << endl;
		printNewLines(desiredNumber - 1);
	}
}

// prints a given number with a message
// pre: message and number are assigned
// post: prints number on the screen after message
void printOne(string message, int number)
{
	cout << message << " : " << number << endl;
}

// finds the maximum value in a list of numbers
// pre: list[first..last] is assigned
// post: returns the maximum value found in list[first..last]
int findMaximumValue(int list[], int first, int last)
{
	if(first == last)
	{
		return list[first];
	} else if(list[first] > list[last]){
		return findMaximumValue(list, first, last - 1);
	} else{
		return findMaximumValue(list, first + 1, last);
	}
}

// finds the mininum value in a list of numbers
// pre: list[first..last] is assigned
// post: returns the mininum value found in list[first..last]
int findMinimumValue(int list[], int first, int last)
{
   if(first == last)
	{
		return list[first];
	} else if(list[first] < list[last]){
		return findMinimumValue(list, first, last - 1);
	} else{
		return findMinimumValue(list, first + 1, last);
	}
}

// finds the sum of the numbers in a list
// pre: list[first..last] is assigned values, 
// first and last are non-negative integers
// post: returns the sum of the numbers in list[first..last]
int sumIt(int list[], int first, int last)
{
   if (first == last)
   {
	   return list[first];
   } else {
	   return list[first] + sumIt(list, first + 1, last);
   }
}

// finds the product of the numbers in a list
// pre: list[first..last] is assigned values, 
// first and last are non-negative integers
// post: returns the product of the numbers in list[first..last]
// For example, if the list contains 3, 2, 5 then returns 30
int findProduct (int list[], int first, int last)
{
   if (first == last)
   {
	   return list[first];
   } else {
	   return list[first] * sumIt(list, first + 1, last);
   }
}

// searches a list for a target
// pre: list[first..last] is assigned values, 
//      first and last are non-negative integers
// post: returns index of target in list and -1 if target is not found
int linearSearch(int list[], int target, int first, int last)
{
	if(first > last)
	{
		return -1;
	} else if(list[first] == target){
		return first;
	} else{
		return linearSearch(list, target, first + 1, last);
	}
}

// searches a list for a target
// pre: list[first..last] is sorted into ascending order
// post: if target is found in list[first..last] then returns the corresponding index
//       else returns -1
int binarySearch(int list[], int target, int first, int last)
{
	int middleIndex;
	
	if (first > last)
	{
		return -1;
	} else {
		middleIndex = (first + last) / 2;
		if (target == list[middleIndex])
		{
			return middleIndex;
		} else if (target < list[middleIndex]) {
			return binarySearch(list, target, first, middleIndex - 1);
		} else {
			return binarySearch(list, target, middleIndex + 1, last);
		}
	}
}