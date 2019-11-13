//authors cpsc 122 class of Fall 2017
//file queens.h
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

#ifndef QUEENS_H
#define QUEENS_H

const int MAXSIZE = 20;

class Queens
{
public:
   //creates an empty chessboard of default size 8
   //post: empty chessboard is assigned with no queens yet on it
   //usage: Queens queensOnBoard;
   Queens();
   
   //creates an empty chessboard of default size 8
   //post: empty chessboard is assigned with no queens yet on it
   //usage: Queens queensOnBoard(4);
   Queens(int desiredBoardsize);  
   
   //destroys the board
   //pre: chessboard exists with or without queens on it
   //post: empty chessboard is assigned with no queens yet on it
   //usage: automatically done upon exit of scope   
   ~Queens();

   //places a queen on the chessboard
   //pre: board exists with queens in rows 0 to queensCount - 1
   //post: a queen has been placed on the board in row queensCount and column
   //usage: queensOnBoard.placeQueen(2);
   void placeQueen(int column);
   
   //removes a queen on the board in column col
   //pre: there is a queen in the last occupied row called queensCount and column col
   //post: the number of queens is decremented and
   //     the queen has been removed from the board
   //usage:
   void removeQueen(int column);
   
   //checks to see of a square on the chessboard is safe for a queen
   //pre: queens are on the board in rows 0 to queensCount - 1
   //post: if the square at row queensCount and column col is safe for a queen
   //          returns true else returns false
   //usage: 
   bool isValidSquare(int column) const; //const at end of a prototype is a signal to compiler that this class method does NOT change data member
   
   //prints the chessboard and queens on it
   //pre: there may or may not be queens on the board
   //post: prints the board to look like a chessboard with squares and shows the queens
   //usage:
   void printBoard() const;

   //checks to see if the queens problem is solved
   //pre: there may or may not be queens on the board
   //post: if the number of queens on the board is the same as board size
   //          then it returns true else returns false
   //usage: 
   bool isPuzzleSolved() const;

   int boardSize;

private:
   bool board[MAXSIZE][MAXSIZE];
   int queensCount; //also row number for next queen
};
#endif

