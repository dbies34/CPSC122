/*
Drew Bies
abies2
cpsc 122
9/24/17
polynomial.h
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class polynomial{
public:

polynomial();

~polynomial();

// returns the degree of a polynomial
int degree();

// returns the coefficent of the x^power term
int coefficent(int power);

// replaces the coefficent of the x^power term with newCoefficient
void changeCoefficient(int& newCoefficient, int& power);

};