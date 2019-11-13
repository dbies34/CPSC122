// calculator.cpp
// Drew Bies
// Matthew Williams

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "stack.h"
using namespace std;

char getInput();
void printScreen(Stack& numbers, string error);
void fillStack(Stack& numbers, char input);
void runChar(Stack& numbers, char input);
void executeMath(Stack& numbers, char c);
void fillTemp(Stack& temp, Stack& numbers);
void emptyStack(Stack& numbers);
int changeCharToInt(char c);
char changeIntToChar(int i);
bool isAddition(char input);
bool isMultiplication(char input);
bool isSubtraction(char input);
bool isDivision(char input);
bool isInteger(char input);
bool isOverflow(int i);
bool isUnderflow(int i);
void printNewLines(int desiredLines);

int main()
{
	Stack numbers;
	
	printNewLines(4);
	runChar(numbers, getInput());	
	printNewLines(3);
	
	return 0;
}

char getInput()
{
	char i;
	cout << "input> ";
	cin >> i;
	printNewLines(2);
	return i;
}

void printScreen(Stack& numbers, string error)
{
	ItemType top;
	Stack temp;
	fillTemp(temp, numbers);
	bool isAdded;
	for(int i = 3; i > 0; i--)
	{
		temp.retrieve(top);
		cout << "         "<< i << ": " << top;
		if(i == 1 && numbers.isEmpty())
		{
			cout << error;
		}
		cout << endl;
		temp.pop();
	}
	printNewLines(3);
	//emptyStack(temp);  //** not needed
	runChar(numbers, getInput());
}

void fillStack(Stack& numbers, char input)
{
	bool isAdded;	
	numbers.push(input, isAdded);
	if(!isAdded)
	{
		emptyStack(numbers);
		printScreen(numbers, "STACKFULL");
	} else{
		printScreen(numbers, "");
	}
}

void runChar(Stack& numbers, char input)
{
	if(isInteger(input))
	{
		fillStack(numbers, input);
	} else if(isAddition(input) || isSubtraction(input) ||
			  isMultiplication(input) || isDivision(input)){
		executeMath(numbers, input);
	} else if(input == 'x'){
		cout << "         Goodbye. Thanks for using our calculator.";
		printNewLines(4);
		exit(1);
	} else{
		cout << "Input unrecognized.";
		printNewLines(3);
		runChar(numbers, getInput());
	}
	
}

void executeMath(Stack& numbers, char c)
{
	char a, b; 
	int ans;
	numbers.retrieve(b);
	numbers.pop();
	numbers.retrieve(a);
	numbers.pop();
	
	int num1 = changeCharToInt(a);
	int num2 = changeCharToInt(b);
	if(isAddition(c))
	{
		ans = num1 + num2;
	} else if(isSubtraction(c)){
		ans = num1 - num2;
	} else if(isMultiplication(c)){
		ans = num1 * num2;
	} else{
		ans = num1 / num2;
	}
	if(isOverflow(ans))
	{
		emptyStack(numbers);
		printScreen(numbers, "OVERFLOW");
	} else if(isUnderflow(ans)){
		emptyStack(numbers);
		printScreen(numbers, "UNDERFLOW");
	} else{
		char answer = changeIntToChar(ans);
		fillStack(numbers, answer);
	}
}

void fillTemp(Stack& temp, Stack& numbers)
{
	bool isAdded;
	ItemType top;
	Stack temp2;
	for(int i = 0; i < 3; i++)
	{
		numbers.retrieve(top);
		if(numbers.isEmpty())
		{
			numbers.push(' ', isAdded);
		} else{
			temp2.push(top, isAdded);
		}
		temp.push(top, isAdded);	
		numbers.pop();
	}
	
	while(!numbers.isEmpty())
    {
	   numbers.retrieve(top);
	   temp2.push(top, isAdded);
	   numbers.pop();
    }
	
	while(!temp2.isEmpty())
    {
	   temp2.retrieve(top);
	   numbers.push(top, isAdded);
	   temp2.pop();
    }
}

void emptyStack(Stack& numbers)
{
	while(!numbers.isEmpty())
	{
		numbers.pop();
	}
}

int changeCharToInt(char c)
{
	return c - 48;
}

char changeIntToChar(int i)
{
	return i + 48;
}

bool isAddition(char input)
{
	if(input == '+')
	{
		return true;
	} else {
		return false;
	}
}

bool isMultiplication(char input)
{
	if(input == '*')
	{
		return true;
	} else {
		return false;
	}
}

bool isSubtraction(char input)
{
	if(input == '-')
	{
		return true;
	} else {
		return false;
	}
}

bool isDivision(char input)
{
	if(input == '/')
	{
		return true;
	} else {
		return false;
	}
}

bool isInteger(char input)
{
	if('0' <= input && input <= '9')
	{
		return true;
	} else {
		return false;
	}
}

bool isOverflow(int i)
{
	if(i >= 10)
	{
		return true;
	} else{
		return false;
	}
}

bool isUnderflow(int i)
{
	if(i < 0)
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