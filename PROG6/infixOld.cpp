/* 
	Chris Martin, Drew Bies
	Programming Assignment 6
	File: infix.cpp
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <istream>
#include "stack.h"

using namespace std;


void getInput(char& achar);

void convertToPostfix(Stack& opStack, Stack& postfixExp, char& achar);

void printStack(Stack& postfixExp);

int precedence(char achar);

bool isOperatorCharacter(char achar);

bool isLeftParenthesis(char achar);

bool isRightParenthesis(char achar);

bool isNewlineCharacter(char achar);

// prints new lines
// pre: desiredLines has been assigned a value
// post: has added new lines based on desiredLines
void printNewLines(int desiredLines);



int main()
{	
	Stack opStack;
	Stack postfixExp;
	char achar;
	
	
	printNewLines(3);
	getInput(achar);
	convertToPostfix(opStack, postfixExp, achar);
	
	printNewLines(3);
	
	return 0;
}	
	
	
void getInput(char& achar)
{
	cout << "input an infix expression without spaces > ";
	cin.get(achar);
}


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
		printNewLines(2);
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
			//opStack.retrieve(temp);
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
		getInput(achar);
		convertToPostfix(opStack, postfixExp, achar);
	}	
}

void printStack(Stack& postfixExp)
{
	ItemType top;
	Stack temp;
	bool isAdded;
	
	while(!postfixExp.isEmpty())
   {
	   postfixExp.retrieve(top);
	   if(isLeftParenthesis(top))
	   {
		   postfixExp.pop();
		   postfixExp.retrieve(top);
	   }
	   temp.push(top, isAdded);
	   postfixExp.pop();
   }
   cout << "the equivalent postfix expression > ";
   while(!temp.isEmpty())
   {
	   temp.retrieve(top);
	   cout << top;
	   temp.pop();
   }
   cout << endl;
}

int precedence(char achar)
{
	if(achar == '*' || achar == '/')
	{
		return 2;
	} else{
		return 1;
	}
}

bool isOperatorCharacter(char achar)
{
	if(achar == '+' || achar == '/' || achar == '*' || achar == '-')
	{
		return true;
	} else{
		return false;
	}
}

bool isLeftParenthesis(char achar)
{
	if(achar == '(')
	{
		return true;
	} else{
		return false;
	}
}

bool isRightParenthesis(char achar)
{
	if(achar == ')')
	{
		return true;
	} else{
		return false;
	}
}

bool isNewlineCharacter(char achar)
{
	if(achar == '\n')
	{
		return true;
	} else{
		return false;
	}
}

void printNewLines(int desiredLines)
{
	for (int k = 0; k < desiredLines; k++)
	{
	   cout << endl;	
	}
}