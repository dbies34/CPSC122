// queens.cpp








Queens()
{
	
}
	
Queens(int desiredBoardSize)
{
	boardSize = desiredBoardSize;
}
	
~Queens()
{
	
}
	
void placeQueen(int column)
{
	
}
	
void removeQueen(int column)
{
	
}
	
void printBoard()
{
	for(int row = 0; row < boardSize; row++)
	{
		if(row < 10)
		{
			cout << " ";
		}
		cout << row << ": ";
		for(int column = 0; column < boardSize; column++)
		{
			if(board[row][column])
			{
				
			}
		}
		cout << endl;
	}
}
	
bool isValidSquare(int column)
{
	
}
	
bool isPuzzleSolved()
{
	if(queensCount == boardSize)
	{
		return true;
	} else{
		return false;
	}
}