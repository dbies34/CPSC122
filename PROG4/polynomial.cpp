/* Program accesses the private members of polynomial.h
      and allows clientofADTpolynomial.cpp to run efficiently
*/

// Drew Bies
// Chris Martin

#include <fstream>
#include <iostream>
#include <string>
#include "polynomial.h"
using namespace std;

const int MAXSIZE = 10;


// creates a new polynomial for a maximum of 10 terms
// post  memory for a polynomial with 10 terms exists
//       with all coefficients 0
Polynomial::Polynomial()
{
	powers = new int [MAXSIZE];
	coefficients = new int [MAXSIZE];
	for(int i = 0; i < MAXSIZE; i++)
	{
		powers[i], coefficients[i] = 0;
	}
}

// destroys a polynomial, releases memory
// pre a polynomial exists
// post the memory for the polynomial has been released
//      with data members appropriately defined
Polynomial::~Polynomial()
{
	delete [] powers;
	delete [] coefficients;
}

// finds the degree of a polynomial
// pre   polynomial object exists
// post  returns the degree of the polynomial object
int Polynomial::findDegree()
{
	int degree = 0;
	for(int i = 0; i < MAXSIZE; i++)
	{
		if(powers[i] > degree)
		{
			degree = powers[i];
		}
	}
	return degree;
}

// finds the coefficient of a specific term
// pre   power is assigned. polynomial object exists
// post  if there is a term with x^power then it returns the coefficient
//       else it returns 0;
int Polynomial::findCoefficient(int power) // **fix
{
	int i = 0;
	bool hasFound = false;
	while(!hasFound)
	{
		if(powers[i] == power)
		{			
			hasFound = true;
		}
		i++;
	}
	if(hasFound)
	{
		return coefficients[i];
	} else{
		return -1;
	}
}

// changes the coefficient of a specific term
// pre power and newCoefficient are assigned. polynomial object exists
// post  if there is a term with x^power, then 
//           it changes existing coefficient to newCoefficient
//       else it adds a term with that power and newCoefficient 
void Polynomial::changeCoefficient(int power, int newCoefficient)
{
	bool hasSwapped = false;
	for(int i = 0; i < MAXSIZE; i++)
	{
		if(powers[i] == power)
		{
			coefficients[i] = newCoefficient;
			hasSwapped = true;
		} 
	}
	if(!hasSwapped)
	{
		int i = 0;
		while(i < MAXSIZE && !hasSwapped)
		{
			if(coefficients[i] == 0)
			{
				powers[i] = power;
				coefficients[i] = newCoefficient;
				hasSwapped = true;
			}
			i++;
		}
	}
}

// prints the polynomial as close to a mathematical version as possible
// pre  polynomial object exists
// post prints in user friendly manner
//      example:   4 x^2 + 3 x - 4
void Polynomial::printPolynomial() // **fix
{
	int i = 0;
	while(coefficients[i] != 0)
	{
		cout << coefficients[i];
		if(powers[i] != 0)
		{
			cout << "x";
			if(powers[i] == 1)
			{
				cout << " ";
			} else{
				cout << "^" << powers[i] << " ";
			}
			//if(
			if(coefficients[i + 1] > 0)
			{
				cout << "+ ";
			}
		}
		i++;
	}
	cout << endl << endl;
}