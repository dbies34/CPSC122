// palindrome.cpp
// Drew Bies
// username: abies2
// 11-6-17
// disc: "pals.dat" is opened and stored as infile. infile is then copied into 
//			stringArray. the strings from stringArray are then printed onto 
//			the screen with the result of whether or not they are a palindrome.

#include "stack.h"
#include "queue.h"
#include <string>
#include <fstream>

// prints the results
// pre: stringArray has been created
// post: the result of each string from stringArray is printed 
void printPalResults(string stringArray[]);

// reads strings from a file and puts them into an array
// pre: infile has been created. stringArray has been created 
// post: infile has been copied into stringArray
void readPalsFile(ifstream& infile, string stringArray[]);

// finds if a string is a palindrome
// pre: aString has no spaces
// post: returns true if aString is a palindrome and false if not
bool isPalindrome(string aString);
// opens an input file
// pre: infile has been created.
// post: if a file named herecometheblobs.dat exists in the same directory as source program,
// 			then infile has been opened with infile's placeholder at the beginning of the file 
//		 	if not, the program exits.
void openInputFile(ifstream& infile);

// prints new lines
// pre: num is a positve integer
// post: using num, the number of new lines are printed onto the screen
void printNewLines(int num);

const int NUMBER_OF_WORDS = 6;

int main()
{
	ifstream infile;
	printNewLines(3);
	openInputFile(infile);
	string stringArray[NUMBER_OF_WORDS];
	readPalsFile(infile, stringArray);
	printPalResults(stringArray);
	
	printNewLines(3);
	
	return 0;
}

// prints the results
// pre: stringArray has been created
// post: the result of each string from stringArray is printed 
void printPalResults(string stringArray[])
{
	for(int i = 0; i < NUMBER_OF_WORDS; i++)
	{
		cout << "Word: " << stringArray[i] << ". Palindrome? ";
		if(isPalindrome(stringArray[i]))
		{
			cout << "true." << endl;
		} else{
			cout << "false." << endl;
		}
	}
}

// reads strings from a file and puts them into an array
// pre: infile has been created. stringArray has been created 
// post: infile has been copied into stringArray
void readPalsFile(ifstream& infile, string stringArray[])
{
	for(int i = 0; i < NUMBER_OF_WORDS; i++)
	{
		infile >> stringArray[i];
	}
}

// finds if a string is a palindrome
// pre: aString has no spaces
// post: returns true if aString is a palindrome and false if not
bool isPalindrome(string aString)
{
	Queue aQueue;
	Stack aStack;
	bool isAdded;
	int length = aString.length();
	for(int i = 0; i < length; i++)
	{
		char aChar = aString.at(i);
		aStack.push(aChar, isAdded);
		aQueue.lineUp(aChar, isAdded); // bug causer
	}
	
	bool charsAreEqual = true;
	
	char queueFront, stackTop;
	while(!aQueue.isEmpty() && charsAreEqual && !aStack.isEmpty())
	{
		aQueue.serve(queueFront);
		aStack.retrieve(stackTop);
		if(queueFront == stackTop)
		{
			aQueue.deleteAtFront();
			aStack.pop();
		} else{ //check
			charsAreEqual = false;	
		}			
	}
	return charsAreEqual;
}

// opens an input file
// pre: infile has been created.
// post: if a file named pals.dat exists in the same directory as source program,
// 			then infile has been opened with infile's placeholder at the beginning of the file 
//		 	if not, the program exits.
void openInputFile(ifstream& infile)
{
	infile.open("pals.dat");
	if(infile.fail())
	{
		cout << "Error in opening pals file." << endl;
		exit(1);
	}
}

// prints new lines
// pre: num is a positve integer
// post: using num, the number of new lines are printed onto the screen
void printNewLines(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << endl;
   }
}