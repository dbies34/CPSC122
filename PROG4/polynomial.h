// Specification of ADT Polynomial
//    data object: a polynomial with integer coefficients
//    operations: create, destroy, 
//                find the degree, find a specific coefficient,
//                change a term's coefficient,
//                print the polynomial

class Polynomial
{
public:

// creates a new polynomial for a maximum of 10 terms
// post  memory for a polynomial with 10 terms exists
//       with all coefficients 0
Polynomial();

// destroys a polynomial, releases memory
// pre a polynomial exists
// post the memory for the polynomial has been released
//      with data members appropriately defined
~Polynomial();

// finds the degree of a polynomial
// pre   polynomial object exists
// post  returns the degree of the polynomial object
int findDegree();

// finds the coefficient of a specific term
// pre   power is assigned. polynomial object exists
// post  if there is a term with x^power then it returns the coefficient
//       else it returns 0;
int findCoefficient(int power);

// changes the coefficient of a specific term
// pre power and newCoefficient are assigned. polynomial object exists
// post  if there is a term with x^power, then 
//           it changes existing coefficient to newCoefficient
//       else it adds a term with that power and newCoefficient 
void changeCoefficient(int power, int newCoefficient);

// prints the polynomial as close to a mathematical version as possible
// pre  polynomial object exists
// post prints in user friendly manner
//      example:   4 x^2 + 3 x - 4
void printPolynomial();

private:

    // these will be dynamic arrays
int* powers;
int* coefficients;

};