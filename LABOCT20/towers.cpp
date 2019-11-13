//towers of hanoi: This program prints instructions on how to move
//                  the disks to solve the Towers of Hanoi Puzzle
//                  for any number of disks.
//towers.cpp
//December 2, 2016


#include <iostream>
using namespace std;

//solves the Towers of Hanoi Puzzle
//pre numberOfDisks is the number of disks that must be moved
//    from source to destination with the spare peg
//post prints the instructions for the disk mover
//usage solveTowers(4, 'A', 'C', 'B');
void solveTowers(int numberOfDisks, char source, char destination, char spare);

//allows the user to enter the number of disks for the puzzle
//post returns the number of disks
//usage numDisks = getNumberDisks();
int getNumberDisks();

//prints a number of new lines
//pre num is assigned
//post outputs num newlines
//usage PrintNewLines(30;
void PrintNewLines(int num);

// pre: num is which term
// post: return that Fibonacci number
int calcFibonacci(int num, int& numberOfCalls);

int main()
{
   int numDisks;
   int numberOfCalls = 0;
   PrintNewLines(3);
   numDisks = getNumberDisks();

   PrintNewLines(2);
   //solveTowers(numDisks, 'A', 'B', 'C' );
   
   cout << calcFibonacci(numDisks, numberOfCalls) << endl;
   PrintNewLines(3);
   cout << "number of calls: " << numberOfCalls;
   PrintNewLines(3);
  

   return 0;
}

//solves the Towers of Hanoi Puzzle
//pre numberOfDisks is the number of disks that must be moved
//    from source to destination with the spare peg
//post prints the instructions of the disk mover
//usage solveTowers(4, 'A', 'C', 'B');
void solveTowers(int numberOfDisks, char source, char destination, char spare)
{
	if(numberOfDisks == 1)
	{
		cout << "Move disk from " << source << " to " << destination << endl;
	} else{
		solveTowers(numberOfDisks - 1, source, spare, destination);
		solveTowers(1, source, destination, spare);
		solveTowers(numberOfDisks - 1, spare, destination, source);
	}
}
// f(n) = 2^n - 1, exponential time 


//allows the user to enter the number of disks for the puzzle
//post returns the number of disks
//usage numDisks = getNumberDisks();
int getNumberDisks()
{
   cout << "Enter number of disks for the Towers of Hanoi Puzzle -> ";
   int num;
   cin >> num;
   return num;
}

//prints a number of new lines
//pre num is assigned
//post outputs num newlines
//usage PrintNewLines(30);

void PrintNewLines(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << endl;
   }
}

// pre: num is which term
// post: return that Fibonacci number
int calcFibonacci(int num, int& numberOfCalls)
{
	numberOfCalls++;
	//cout << "cF(" << num << ")" << endl;
	if(num == 0 || num == 1)
	{
		return 1;
	} else{
		return (calcFibonacci(num - 1, numberOfCalls) + calcFibonacci(num - 2, numberOfCalls));
	}
}


