//authors cpsc 122 class of Fall 2017
//file queens.cpp
//date October 30, 2017

// ADT Queens (motivated by the famous Eight Queens Problem)
//      data object: a number of queens on a chess board
//      operations: create an empty board, 
//                  create a certain size empty board, 
//                  destroy the board,
//                  place a queen on the board, 
//                  remove a queen from the board,
//                  check if a square is valid (previous queens cannot attack),
//                  print queens on the board

#include "stdafx.h"
#include "queens.h"
#include <iostream>
using namespace std;

//creates an empty chessboard of default size 8
//post: empty chessboard is assigned with no queens yet on it
//usage: Queens queensOnBoard;
Queens::Queens()
{
	for(int row = 0; row < 8; row++)
	{
		for(int column = 0; column < 8; column++)
		{
			board[row][column] = false;
		}
	}
	boardSize = 8;
	queensCount = 0;
}
   
//creates an empty chessboard of size given
//post: empty chessboard is assigned with no queens yet on it
//usage: Queens queensOnBoard(4);
Queens::Queens(int desiredBoardsize)
{
	for(int row = 0; row < desiredBoardsize; row++)
	{
		for(int column = 0; column < desiredBoardsize; column++)
		{
			board[row][column] = false;
		}
	}
	boardSize = desiredBoardsize;
	queensCount = 0;
}  
   
//destroys the board
//pre: chessboard exists with or without queens on it
//post: empty chessboard is assigned with no queens yet on it
//usage: automatically done upon exit of scope   
Queens::~Queens()
{
	boardSize = 0;
}

//places a queen on the chessboard
//pre: board exists with queens in rows 0 to queensCount - 1
//post: a queen has been placed on the board in row queensCount and column
//usage: queensOnBoard.placeQueen(2);
void Queens::placeQueen(int column)
{
	board[queensCount][column] = true;
	queensCount++;
}
   
//removes a queen on the board in column col
//pre: there is a queen in the last occupied row called queensCount and column col
//post: the number of queens is decremented and
//     the queen has been removed from the board
//usage:
void Queens::removeQueen(int column)
{
	board[queensCount - 1][column] = false;
	queensCount--;
}
   
//checks to see of a square on the chessboard is safe for a queen
//pre: queens are on the board in rows 0 to queensCount - 1
//post: if the square at row queensCount and column col is safe for a queen
//          returns true else returns false
//usage: 
bool Queens::isValidSquare(int column) const
{
	// checking up from square in question
	for(int row = 0; row < queensCount; row++)
	{
		if(board[row][column])
		{
			return false;
		}
	}
	
	// checking up/right diagonal from square in question
	for(int row = 0; row < queensCount; row++)
	{
		if((column + queensCount - row) <= boardSize)
		{
			if(board[row][column + queensCount - row])
			{
				return false;
			}
		}
	}
	// checking up/left diagonal from square in question
	for(int row = 0; row < queensCount; row++)
	{
		if((column - queensCount + row) >= 0)
		{
			if(board[row][column - queensCount + row])
			{
				return false;
			}
		}
	}
	return true;
}
   
//prints the chessboard and queens on it
//pre: there may or may not be queens on the board
//post: prints the board to look like a chessboard with squares and shows the queens
//usage:
void Queens::printBoard() const
{
	char blank = 178;
	for(int row = 0; row < boardSize; row++)
	{
		cout << endl;
		for(int column = 0; column < boardSize; column++)
		{
			if(board[row][column])
			{
				cout << "♛ ";
			} else{
				cout << "☐ ";
				
			}
		}
	}
	cout << endl;
}

//checks to see if the queens problem is solved
//pre: there may or may not be queens on the board
//post: if the number of queens on the board is the same as board size
//          then it returns true else returns false
//usage: 
bool Queens::isPuzzleSolved() const
{
	return (queensCount == boardSize);
}


