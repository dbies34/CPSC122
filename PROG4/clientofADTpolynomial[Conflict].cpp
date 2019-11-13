// client program of ADT Polynomial
// 
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

void printDirections(Polynomial& poly);
int getInput();
void runInput(int input, Polynomial& poly);
void runFindCoefficient(Polynomial& poly);
void runCoefficient(Polynomial& poly);
void printNewLines(int desiredLines);

int main()
{
	Polynomial poly;
	
	printNewLines(2);	
	printDirections(poly);
	printNewLines(2);
	/*
	poly.changeCoefficient(3, 3);
	poly.changeCoefficient(2, -2);
	poly.printPolynomial();
	*/
	~Polynomial poly;
	return 0;
}


/*

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

*/
int getInput()
{
	int input;
	cout << "  enter your choice-> ";
	cin >> input;
	return input;
}

/*

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

*/
void runFindCoefficient(Polynomial& poly)
{
	int i;
	cout << "Enter power of coefficient you wish to find-> ";
	cin >> i;
	cout << endl;
	poly.findCoefficient(i);
}

/*
disc: 
pre:
post:
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
void sortPolynomial(Polynomial& poly)
{
	
	bool sorted = false;
	int pass = 1;
	while(!sorted && (pass < numberOfTeams)){
		sorted = true;
		for(int i = 0; i < numberOfTeams - pass; i++){
			if(teams[i].type > teams[i + 1].type){
				swap(teams[i].type, teams[i + 1].type);
				sorted = false;
			}
		}
		pass++;
	}
}

int findCoefficientTotal(Polynomial& poly)
{
	int total = 0;
	while9
}
*/
/*
disc: prints new lines for the given number number of lines 
pre: given number is an int
post: number of new lines is printed
*/
void printNewLines(int desiredLines){
	for (int k = 0; k < desiredLines; k++){
	   cout << endl;	
	}
}