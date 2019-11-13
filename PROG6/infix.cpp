/* 
	Chris Martin, Drew Bies
	username: abies2
	Programming Assignment 6
	File: infix.cpp
	Abstract Data Type Stack:
		data object is a stack where the most-recently-added (or top) item
        is most-easily accessible
	use:
		input an infix expressions and recieves a printed out postfix expression
	functions:
		getInput
		convertToPostfix
		printStack
		precedence
		isOperatorCharacter
		isLeftParenthesis
		isRightParenthesis
		isNewlineCharacter
		printDirections
		emptyStack
		printNewLines
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <istream>
#include "stack.h"

using namespace std;

//User enters infix expression
//Pre: given char is intialized
//Post: User enters infix mathematical expression, then assigns each character of the expression to the char
void getInput(char& achar);

//Transfers infix expression to postfix
//Pre: the given char and the two stacks are intialized
//Post: takes in a char from the input buffer and uses the two stacks to convert the given chars to a 
//      postfix expression from the infix expression
//Ex. (a+b)*c turns into ab+c*
void convertToPostfix(Stack& opStack, Stack& postfixExp, char& achar);

//Prints out new postfix expression
//Pre: given stack is intialized
//Post: prints out the given stack onto the screen
void printStack(Stack& postfixExp);

//Pre: given char is intialized
//Post: returns a precedence value from the given char based on the operator
int precedence(char achar);

//Pre: given char is intialized
//Post: returns true or false depending if the given char is a operator or not
bool isOperatorCharacter(char achar);

//Pre: given char is intialized
//Post: returns true or false depending if the given char is a left parenthesis or not
bool isLeftParenthesis(char achar);

//Pre: given char is intialized
//Post: returns true or false depending if the given char is a right parenthesis or not
bool isRightParenthesis(char achar);

//Pre: given char is intialized
//Post: returns true or false depending if the given char is a new line character or not 
bool isNewlineCharacter(char achar);

// prints out directions for the user
// pre: none
// post: directions print out to the screen
void printDirections();

// empties the given stack
// Pre: given Stack is intialized
// Post: the given stack is emptied
void emptyStack(Stack& stack);

// prints new lines
// pre: given int is intialized
// post: has added new lines based on given int
void printNewLines(int desiredLines);



int main()
{	
	Stack opStack;
	Stack postfixExp;
	char achar;
	
	
	printNewLines(3);
	printDirections();
	getInput(achar);
	convertToPostfix(opStack, postfixExp, achar);
	
	printNewLines(3);
	
	return 0;
}	

//User enters infix expression
//Pre: given char is intialized
//Post: User enters infix mathematical expression, then assigns each character of the expression to the char
void getInput(char& achar)
{
	cout << "input an infix expression without spaces > ";        
	cin.get(achar);
}

//Transfers infix expression to postfix
//Pre: the given char and the two stacks are intialized
//Post: takes in a char from the input buffer and uses the two stacks to convert the given chars to a 
//      postfix expression from the infix expression
//Ex. (a+b)*c turns into ab+c*
void convertToPostfix(Stack& opStack, Stack& postfixExp, char& achar)
{
	bool isAdded;
	char temp;
	
	if(!opStack.isEmpty())
	{
		opStack.retrieve(temp);
	}
	
	if(achar == 'x')
	{
		cout << "thank you for using our infix to postfix converter";		
		printNewLines(5);
		exit(1);
	} else if (!isNewlineCharacter(achar)) {
		if (!isOperatorCharacter(achar) && !isLeftParenthesis(achar) && !isRightParenthesis(achar))
		{
			postfixExp.push(achar, isAdded);
		} else if (isLeftParenthesis(achar)){
			opStack.push(achar, isAdded);
		} else if (isOperatorCharacter(achar)){
			while(!opStack.isEmpty() && !isLeftParenthesis(temp) && precedence(achar) <= precedence(temp))
			{
				opStack.retrieve(temp);
				postfixExp.push(temp, isAdded);
				opStack.pop();
			}
			opStack.push(achar, isAdded);
		} else if (isRightParenthesis(achar)){
			opStack.retrieve(temp);
			while(!isLeftParenthesis(temp))
			{
				opStack.retrieve(temp);
				postfixExp.push(temp, isAdded);
				opStack.pop();
			}
			opStack.pop();
		}	
	cin.get(achar);
	convertToPostfix(opStack, postfixExp, achar);		
	} else {
		while(!opStack.isEmpty())
		{
			opStack.retrieve(temp);
			postfixExp.push(temp, isAdded);
			opStack.pop();
		}
		printStack(postfixExp);
		emptyStack(postfixExp);
		emptyStack(opStack);
		getInput(achar);
		convertToPostfix(opStack, postfixExp, achar);
	}	
}
//Prints out new postfix expression
//Pre: given stack is intialized
//Post: prints out the given stack onto the screen
void printStack(Stack& postfixExp)
{
	char top;
	Stack temp;
	bool isAdded;
	while(!postfixExp.isEmpty())
    {
	   postfixExp.retrieve(top);
	   while(isLeftParenthesis(top))
	   {
		   postfixExp.pop();
		   postfixExp.retrieve(top);
	   }
	   temp.push(top, isAdded);
	   postfixExp.pop();
    }
	
    cout << "       the equivalent postfix expression > ";
    while(!temp.isEmpty())
    {
	   temp.retrieve(top);	   
	   cout << top;
	   temp.pop();
    }
    printNewLines(1);
}

//Pre: given char is intialized
//Post: returns a precedence value from the given char based on the operator
int precedence(char achar)
{
	if(achar == '*' || achar == '/')
	{
		return 2;
	} else{
		return 1;
	}
}

//Pre: given char is intialized
//Post: returns true or false depending if the given char is a operator or not
bool isOperatorCharacter(char achar)
{
	if(achar == '+' || achar == '/' || achar == '*' || achar == '-')
	{
		return true;
	} else{
		return false;
	}
}

//Pre: given char is intialized
//Post: returns true or false depending if the given char is a left parenthesis or not
bool isLeftParenthesis(char achar)
{
	if(achar == '(')
	{
		return true;
	} else{
		return false;
	}
}

//Pre: given char is intialized
//Post: returns true or false depending if the given char is a right parenthesis or not
bool isRightParenthesis(char achar)
{
	if(achar == ')')
	{
		return true;
	} else{
		return false;
	}
}

//Pre: given char is intialized
//Post: returns true or false depending if the given char is a new line character or not 
bool isNewlineCharacter(char achar)
{
	if(achar == '\n')
	{
		return true;
	} else{
		return false;
	}
}

// prints out directions for the user
// pre: none
// post: directions print out to the screen
void printDirections()
{
	cout << "           type x to quit" << endl;
}

// empties the given stack
// Pre: given Stack is intialized
// Post: the given stack is emptied
void emptyStack(Stack& stack)
{
	while(!stack.isEmpty())
	{
		stack.pop();
	}
}

// prints new lines
// Pre: given int is intialized
// Post: has added new lines based on given int
void printNewLines(int desiredLines)
{
	for (int k = 0; k < desiredLines; k++)
	{
	   cout << endl;	
	}
}