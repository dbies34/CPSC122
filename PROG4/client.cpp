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

int main()
{
	Polynomial poly;
	
	poly.changeCoefficient(4, 5);
	poly.changeCoefficient(7, 6);
	poly.changeCoefficient(2, -7);
	poly.printPolynomial();
	//~Polynomial poly;
	return 0;
}