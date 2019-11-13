#include <iostream>
#include "stack.h"
using namespace std;

// determines if a character is the designated backspace character
// pre: aCharacter has been assigned an ASCII character
// post: returns true if aCharacter is '#' else returns false
// usage: if (isBackspace(aCharacter))
bool isBackspace(char aCharacter);

// determines if a character is the NEWLN character
// pre: aCharacter has been assigned an ASCII character
// post: returns true if aCharacter is not the NEWLN character else returns false
// usage: if (isNotNewlineCharacter(aCharacter)) 
bool isNotNewlineCharacter(char aCharacter);

// prints the contents of the stack from top to bottom (which is the input line in reverse)
// pre: aLine has been filled. Passing by reference because we are not able to pass by value yet
// post: aLine is printed from the top character to the bottom character
// usage: printStackInReverse(aLine);
void printStackInReverse(Stack& aLine);

// gets a line of characters from the user with '#' denoting the backspace character
// post: lineCharacters has been input from the user with the backspace character correcting as we good
// usage: getLineAndCorrect(lineCharacters);
void getLineAndCorrect(Stack& lineCharacters);

void printStack(Stack& aLine);

int main()
{
    Stack lineCharacters;
    getLineAndCorrect(lineCharacters);
    printStackInReverse(lineCharacters);
    
    return 0;
}

// determines if a character is the designated backspace character
// pre: aCharacter has been assigned an ASCII character
// post: returns true if aCharacter is '#' else returns false
// usage: if (isBackspace(aCharacter))
bool isBackspace(char aCharacter)
{
   return (aCharacter == '#');
}

// determines if a character is the NEWLN character
// pre: aCharacter has been assigned an ASCII character
// post: returns true if aCharacter is not the NEWLN character else returns false
// usage: if (isNotNewlineCharacter(aCharacter)) 
bool isNotNewlineCharacter(char aCharacter)
{
   return (aCharacter != '\n');
}

// prints the contents of the stack from top to bottom (which is the input line in reverse)
// pre: aLine has been filled. Passing by reference because we are not able to pass by value yet
// post: aLine is printed from the top character to the bottom character
// usage: printStackInReverse(aLine);
void printStackInReverse(Stack& aLine)
{
	ItemType top;
	while(!aLine.isEmpty())
	{	   
	   aLine.retrieve(top);
	   cout << top << endl;
	   aLine.pop();
	}
}

void printStack(Stack& aLine)
{
	ItemType top;
	Stack temp;
	bool isAdded;
	
	while(!aLine.isEmpty())
   {
	   aLine.retrieve(top);
	   temp.push(top, isAdded);
	   aLine.pop();
   }
   
   while(!temp.isEmpty())
   {
	   temp.retrieve(top);
	   cout << top << endl;
	   aLine.push(top, isAdded);
	   temp.pop();
   }
}

// gets a line of characters from the user with '#' denoting the backspace character
// post: lineCharacters has been input from the user with the backspace character correcting as we good
// usage: getLineAndCorrect(lineCharacters);
void getLineAndCorrect(Stack& lineCharacters)
{
   char aChar;
   bool isAdded;
   cin.get(aChar);
   while(isNotNewlineCharacter(aChar))
   {
	   if(lineCharacters.isEmpty() && isBackspace(aChar))
	   {
		   // do nothing
	   } else if(isBackspace(aChar)){
		   lineCharacters.pop();
	   } else {
		   lineCharacters.push(aChar, isAdded);
	   }
	   cin.get(aChar);
   }
}