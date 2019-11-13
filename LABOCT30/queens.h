// queens.h 
// public functions include:
//		constructor
//		desired board size intializer
//		deconstructor
//		place a queen
//		remove a queen
//		print the board
//		valid square check
//		is game over check
// 		board size integer





// backtrack
// remove previous queen
// test if it is a valid location for a queen
// add a queen
// test to see if "done"
// print the board

#indef QUEENS.H
#define QUEENS.H
const int MAXSIZE = 20;

class Queens
{
public:
	
	Queens();
	
	Queens(int desiredBoardSize);
	
	~Queens();
	
	void placeQueen(int column);
	
	void removeQueen(int column);
	
	void printBoard();
	
	bool isValidSquare(int column);
	
	bool isPuzzleSolved();
	
	int boardSize;
	
private:
	
	bool board[MAXSIZE][MAXSIZE];
	
	int queensCount;
};
#endif