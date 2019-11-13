//file  : eight.cpp (TRADITION!!!!)
//authors:  dr y and Drew Bies
//date: November 9, 2017

// this program asks the user for their desired aboard size and make a Queens object.
// 	the function solveQueensProblem is called with the Queens object.
//	solveQueensProblem then places queens on the board till there is no more possible places.
//	with a recursive design, the function backtracks and removes the previous queen and places it on the next available column.
//	everytime a solution is found, the board is printed and asks the user to continue to the next solution.

#include "queens.h"
#include <iostream>
using namespace std;

//Solves the Queens Problem
//pre: board contains partial solution
//post: solved board is printed
//usage: solveQueensProblem (myboard);
void solveQueensProblem(Queens& board);

//Accept from user the number of queens for the problem
//post: returns number of queens input by user and gets past user's entered newline
//usage: numQueens = howManyQueens();
int howManyQueens();

//prints a number of new lines
//pre: num has a value > 0
//post: num newlines have been output to the screen
//usage: printNewlines(3);
void printNewlines(int num);

//Asks the user whether or not to continue 
//(gives the user time to consider reflectively what is on the screen)
//post: if yes hits <enter> program continues
//usage: toContinue();
void toContinue();

int main()
{
    Queens myboard(howManyQueens());
   
    solveQueensProblem(myboard);

    return 0;
}

// Solves the Queens Problem
// pre: boardStuff contains partial solution
// post: solved boardStuff is printed
// usage: solveQueensProblem(myboard);
void solveQueensProblem(Queens& boardStuff)
{
	if(boardStuff.isPuzzleSolved())
    {
		cout << "solution:" << endl;
		boardStuff.printBoard();
		toContinue();
    } else{
		for (int column = 0; column < boardStuff.boardSize; column++)
        {
			if (boardStuff.isValidSquare(column))
			{
				boardStuff.placeQueen(column);
				solveQueensProblem(boardStuff);
				boardStuff.removeQueen(column);
			}
		}
	}
}

// Accept from user the number of queens for the problem
// post: returns number of queens input by user and gets past user's entered newline
// usage: numQueens = howManyQueens();
int howManyQueens()
{
	int numberOfQueens;
	printNewlines(3);
	
	cout << "Enter how many queens you want to solve for: ";
	cin >> numberOfQueens;
	printNewlines(2);
   
	return numberOfQueens;
}

// prints a number of new lines
// pre: num has a value > 0
// post: num newlines have been output to the screen
// usage: printNewlines(3);
void printNewlines(int num)
{
	for (int k = 0; k < num; k++)
	{
		cout << endl;
	}
}

// Asks the user whether or not to continue 
// (gives the user time to consider reflectively what is on the screen)
// post: if yes hits <enter> program continues
// usage: toContinue();
void toContinue()
{
   printNewlines(2);
   cout << "To continue, hit <enter>";
   cin.get();
   printNewlines(1);
}
