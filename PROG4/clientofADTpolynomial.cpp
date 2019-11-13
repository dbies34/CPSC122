// client program of ADT Polynomial
// Program uses the functions in a user friendly manner through polynomial.h 
//   and allows the user access to the private members in polynomial.cpp, in turn allowing the 
//   clientofADTpolynomial.cpp to execute
// username: abies2
// Drew Bies
// Chris Martin

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "polynomial.h"
using namespace std;

/*
disc: prints the directions of the program in a user friendly way
pre: user must input any of the numbers given or the program will exit
post: the directions are printed out for the user to follow and 
	prints the input line for the function they want to run. 
	runs the function automatically when the input is taken in
usage: printDirections(poly);
*/
void printDirections(Polynomial& poly);

/*
disc: asks the user for their input and returns it
pre: input must be an integer
post: input is taken in and returned to the function that called it
usage: getInput();
*/
int getInput();

/*
disc: with the given input, the desired function is called and ran for the user
pre: must take in a valid integer as the input and the polynomial
post: the desired function is ran for the user. any other number will exit the program
usage: runInput(input, poly);
*/
void runInput(int input, Polynomial& poly);

/*
disc: uses the function findCoefficient and adds user input
pre: takes in the address of the polynomial to make use of it
post: returns the coefficient of the power they wanted to locate. 
	returns -1 if not found
usage: runFindCoefficient(poly);
*/
void runFindCoefficient(Polynomial& poly);

/*
disc: uses the function changeCoefficient to add or change the Coefficient. adds user input and a while loop for convience  
pre: user must input any integer for the coefficient and power
post: the polynomial is filled with the integers the user input
usage: runCoefficient(poly);
*/
void runCoefficient(Polynomial& poly);

/*
disc: prints new lines for the given number number of lines 
pre: given number is an int
post: number of new lines is printed
usage: printNewLines(desiredLines);
*/
void printNewLines(int desiredLines);

int main()
{
	Polynomial poly;
	
	printNewLines(2);
	printDirections(poly);
	printNewLines(2);

	return 0;
}


/*
disc: prints the directions of the program in a user friendly way
pre: user must input any of the numbers given or the program will exit
post: the directions are printed out for the user to follow and 
	prints the input line for the function they want to run. 
	runs the function automatically when the input is taken in
usage: printDirections(poly);
*/
void printDirections(Polynomial& poly)
{
	cout << "Dear user, please:" << endl;
	cout << "     type 1 if you wish to find the degree of the polynomial" << endl;
	cout << "     type 2 if you wish to find a specific coefficient of a term in the polynomial" << endl;
	cout << "     type 3 if you wish to change a coefficient or add a new term with power and coefficient" << endl;
	cout << "     type 4 if you wish to print the polynomial to the screen" << endl;
	printNewLines(3);
	cout << "(any other number will exit the program)" << endl;
	runInput(getInput(), poly);
}

/*
disc: asks the user for their input and returns it
pre: input must be an integer
post: input is taken in and returned to the function that called it
usage: getInput();
*/
int getInput()
{
	int input;
	cout << "  enter your choice-> ";
	cin >> input;
	return input;
}

/*
disc: with the given input, the desired function is called and ran for the user
pre: must take in a valid integer as the input and the polynomial
post: the desired function is ran for the user. any other number will exit the program
usage: runInput(input, poly);
*/
void runInput(int input, Polynomial& poly)
{
	printNewLines(2); 
	if(input == 1)
	{
		cout << "Degree of the polynomial: " << poly.findDegree() << endl;
	} 
	else if(input == 2)
	{
		runFindCoefficient(poly);
	} 
	else if(input == 3)
	{
		runCoefficient(poly);
	} 
	else if(input == 4)
	{
		poly.printPolynomial();
	}
	else	
	{
		cout << "exiting program now.";
		printNewLines(3);
		exit(1);
	}
	printNewLines(3);
	printDirections(poly);
	
}

/*
disc: uses the function findCoefficient and adds user input
pre: takes in the address of the polynomial to make use of it
post: returns the coefficient of the power they wanted to locate. 
	returns -1 if not found
usage: runFindCoefficient(poly);
*/
void runFindCoefficient(Polynomial& poly)
{
	int i;
	cout << "(prints out -1 if not found)" << endl;
	cout << "   Enter power of coefficient you wish to find-> ";
	cin >> i;
	cout << endl;
	cout << "Coefficient: " << poly.findCoefficient(i) << endl:
}

/*
disc: uses the function changeCoefficient to add or change the Coefficient. adds user input and a while loop for convience  
pre: user must input any integer for the coefficient and power
post: the polynomial is filled with the integers the user input
usage: runCoefficient(poly);
*/
void runCoefficient(Polynomial& poly)
{
	int power, coefficient;
	char in = 'y';
	while(in != 'n')
	{
		cout << "Enter your coefficient-> ";
		cin >> coefficient;
		cout << endl << "Enter the power-> ";
		cin >> power;
		cout << endl;
		poly.changeCoefficient(power, coefficient);
		cout << "Do you wish to add another one?" << endl << "Enter 'y' or 'n' -> ";
		cin >> in;
		cout << endl;
	}
}

/*
disc: prints new lines for the given number number of lines 
pre: given number is an int
post: number of new lines is printed
usage: printNewLines(desiredLines);
*/
void printNewLines(int desiredLines)
{
	for (int k = 0; k < desiredLines; k++)
	{
	   cout << endl;	
	}
}