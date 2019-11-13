/** 
Drew Bies
username: abies2
blobsgame.cpp
11-3-17

this program opens a file with the name of herecometheblobs.dat using infile.
	bool blobs is created and filled with the contents of the file.
	prints the directions for the users to follow.
	run the game with a recursive design
		display is printed out for the possible coordinates of the blobs
		displays the remaining blobs left
		asks the player for their desired coordinate and checks if there is a blob 
			and gives them the respected points
		prints the score of the player during their turn
		erases and blob that is found
		allows user to exit by entering -1 into the column input
		calls itself at the end of the function while switching player turns
		final scores and the winner are printed when the user exits the program 
			or when no more blobs are left. the program exits after this.

**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

const int MAXROWS = 25;
const int MAXCOLUMNS = 50;

const string PLAYER_ONE = "Chris the Great";
const string PLAYER_TWO = "Lieutenant Martin";

// opens an input file
// pre: infile has been created.
// post: if a file named herecometheblobs.dat exists in the same directory as source program,
// 			then infile has been opened with infile's placeholder at the beginning of the file 
//		 	if not, the program exits.
void openInputFile(ifstream& infile);

// reads the file and inserts it into the blobs array
// pre: infile has been opened. 
//		infile has the same dimensions as blobs. blobs has been created
// post: each character from infile is read copied into blobs as an integer
void readBlobsFile(ifstream& infile, bool blobs[][MAXCOLUMNS]);

// runs the game 
// pre: blobs and display are filled with integers with the dimensions of MAXCOLUMNS ans MAXROWS.
//		player is an integer with the value 1. scores is an integer array with room for only two integers.
// 		blobCount is an integer
// post: blobs is used to check if a blob is hit or not.
//		 display is used to keep track of unsuccessful blob hits.
//		 player is used to keep track of the player and to switch players at the end of each turn.
//		 scores is used to keep track of the respected player and uses blobCount for the correct 
//		  amount of points.
void runGame(bool blobs[][MAXCOLUMNS], bool display[][MAXCOLUMNS], int player, int scores[], int& blobCount);

// prints the blobs onto the screen
// pre: blobs is filled with integers with the dimensions of MAXCOLUMNS and MAXROWS
// post: prints the array blobs onto the screen
void printBlobs(bool blobs[][MAXCOLUMNS]);

// counts the blobs in the given 2D array
// pre: blobs is filled ones and zeros with the dimensions of MAXCOLUMNS and MAXROWS
// post: returns the numbers of blobs in the blobs array
int countBlobs(bool blobs[][MAXCOLUMNS]);

// erases a blob in all eight directions
// pre: arow, acolumn, and blobSize are integers
//      blobs and display are filled with ones and zeros with the dimensions of MAXCOLUMNS and MAXROWS		
// post: the blob in the blobs array of ones is replaced with zeros
//		 display is filled with the newly erased blob.
//		 blobSize contains the size of the erased blob
void eraseABlob(int arow, int acolumn, bool blobs[][MAXCOLUMNS], bool display[][MAXCOLUMNS], int& blobSize);

// prints the directions
// pre: none
// post: the directions are printed onto the screen
void printDirections();

// prints the scores and declares a winner
// pre: scores is intialed with only two integers
// post: scores is printed onto the screen under the correct name 
//		 and the winner is declared. exits the program after.
void printScores(int scores[]);

// fills the display
// pre: display is intialized with the dimensions of MAXCOLUMNS and MAXROWS
// post: display is filled with 0s
void fillDisplay(bool display[][MAXCOLUMNS]);

// prints new lines
// pre: num is a positve integer
// post: using num, the number of new lines are printed onto the screen
void printNewLines(int num);


int main()
{
	ifstream infile;
    bool blobs[MAXROWS][MAXCOLUMNS];
	bool display[MAXROWS][MAXCOLUMNS];
	int scores[2] = {0, 0};
	fillDisplay(display);
	printNewLines(5);

    openInputFile(infile);
    readBlobsFile(infile, blobs);
	
	printDirections();
	int blobCount = countBlobs(blobs);
	runGame(blobs, display, 1, scores, blobCount);
	
	return 0;
}

// opens an input file
// pre: infile has been created.
// post: if a file named herecometheblobs.dat exists in the same directory as source program,
// 			then infile has been opened with infile's placeholder at the beginning of the file 
//		 	if not, the program exits.
void openInputFile(ifstream& infile)
{
    infile.open("herecometheblobs.dat");
    if (infile.fail())
    {
        cout << "Error in Opening blobs file" << endl;
        exit(1);
    }
}

// reads the file and inserts it into the blobs array
// pre: infile has been opened. 
//		infile has the same dimensions as blobs. blobs has been created
// post: each character from infile is read copied into blobs as an integer
void readBlobsFile(ifstream& infile, bool blobs[][MAXCOLUMNS])
{
	char achar; int ascii, realValue;
	for(int row = 0; row < MAXROWS; row++)
	{
		for(int column = 0; column < MAXCOLUMNS; column++)
		{
			infile.get(achar);
			ascii = achar;
			realValue = ascii - '0';
			blobs[row][column] = realValue;
		}
		infile.get(achar);
	}
}
// runs the game 
// pre: blobs and display are filled with integers with the dimensions of MAXCOLUMNS ans MAXROWS.
//		player is an integer with the value 1. scores is an integer array with room for only two integers.
// 		blobCount is an integer
// post: blobs is used to check if a blob is hit or not.
//		 display is used to keep track of unsuccessful blob hits.
//		 player is used to keep track of the player and to switch players at the end of each turn.
//		 scores is used to keep track of the respected player and uses blobCount for the correct 
//		  amount of points.
void runGame(bool blobs[][MAXCOLUMNS], bool display[][MAXCOLUMNS], int player, int scores[], int& blobCount)
{
	int row, column;
	printNewLines(6);
	printBlobs(display);
	cout << "(Number of blobs left: " << blobCount << ")" << endl;
	printNewLines(2);
	if(player == 1)
	{
		cout << "	" << PLAYER_ONE << ": (score: " << scores[0] << ")" << endl;
	} else{
		cout << "	" << PLAYER_TWO << ": (score: " << scores[1] << ")" << endl;
	}
	printNewLines(1);
	cout << "(number between " << 0 << " and " << MAXCOLUMNS - 1 << ", enter -1 to exit) ";
	cout << "Enter a column: ";
	cin >> column;
	
	if(column == -1)
	{
		printScores(scores);
	}
	
	printNewLines(1);
	cout << "(number between " << 0 << " and " << MAXROWS - 1 << ") ";
	cout << "Enter a row: ";
	cin >> row;
	cout << endl;
	
	if(blobs[row][column])
	{
		blobCount--;
		int score = 0;
		eraseABlob(row, column, blobs, display, score);
		cout << "Successful! You scored " << score << " point(s)." << endl;
		scores[player - 1] = scores[player - 1] + score;
	} else{
		// no blobs
		printNewLines(2);
		display[row][column] = 1;
		cout << "Unsuccessful. No blob at that coordinate." << endl;
	}
	
	if(blobCount < 1)
	{
		printScores(scores);		
	}
	
	if(player == 1)
	{
		runGame(blobs, display, 2, scores, blobCount);
	} else{
		runGame(blobs, display, 1, scores, blobCount);
	}
}

// prints the blobs onto the screen
// pre: blobs is filled with integers with the dimensions of MAXCOLUMNS and MAXROWS
// post: prints the array blobs onto the screen
void printBlobs(bool blobs[][MAXCOLUMNS])
{
	cout << "    .................Display Board...................." << endl;
	for(int row = 0; row < MAXROWS; row++)                        
	{
		if(row < 10)
		{
			cout << " ";
		}
		cout << row << ": ";
		for(int column = 0; column < MAXCOLUMNS; column++)
		{
			if(blobs[row][column])
			{
				cout << 'X';
			} else{
				cout << '#';
			}
		}
		cout << endl;
	}
	cout << "(# = unknown territory, X = unsuccessful hits/discovered blobs)" << endl;
}

// erases a blob in all eight directions
// pre: arow, acolumn, and blobSize are integers
//      blobs and display are filled with ones and zeros with the dimensions of MAXCOLUMNS and MAXROWS		
// post: the blob in the blobs array of ones is replaced with zeros
//		 display is filled with the newly erased blob.
//		 blobSize contains the size of the erased blob
void eraseABlob(int arow, int acolumn, bool blobs[][MAXCOLUMNS], bool display[][MAXCOLUMNS], int& blobSize)
{
	if(arow >= 0 && arow < MAXROWS && acolumn >= 0 && acolumn < MAXCOLUMNS)
	{
		if(blobs[arow][acolumn])
		{
			blobSize++;
			display[arow][acolumn] = 1;
			blobs[arow][acolumn] = 0; // erase
			eraseABlob(arow - 1, acolumn, blobs, display, blobSize); // up
			eraseABlob(arow + 1, acolumn, blobs, display, blobSize); // down
			eraseABlob(arow, acolumn - 1, blobs, display, blobSize); // left
			eraseABlob(arow, acolumn + 1, blobs, display, blobSize); // right
			eraseABlob(arow - 1, acolumn - 1, blobs, display, blobSize); // up and left
			eraseABlob(arow - 1, acolumn + 1, blobs, display, blobSize); // up and right
			eraseABlob(arow + 1, acolumn - 1, blobs, display, blobSize); // down and left
			eraseABlob(arow + 1, acolumn + 1, blobs, display, blobSize); // down and right
		}
	}
}

// counts the blobs in the given 2D array
// pre: blobs is filled ones and zeros with the dimensions of MAXCOLUMNS and MAXROWS
// post: returns the numbers of blobs in the blobs array
int countBlobs(bool blobs[][MAXCOLUMNS])
{
	int countOfBlobs = 0, size;
	bool temp[MAXROWS][MAXCOLUMNS];
	// make a copy of blobs
	bool copy[MAXROWS][MAXCOLUMNS];
	for(int row = 0; row < MAXROWS; row++)
	{
		for(int column = 0; column < MAXCOLUMNS; column++)
		{
			copy[row][column] = blobs[row][column];
		}
	}
	//search for the start of each blob
	for(int row = 0; row < MAXROWS; row++)
	{
		for(int column = 0; column < MAXCOLUMNS; column++)
		{
			if(copy[row][column])
			{
				countOfBlobs++;
				eraseABlob(row, column, copy, temp, size);
			}
		}
	}
	return countOfBlobs;
}

// prints the directions
// pre: none
// post: the directions are printed onto the screen
void printDirections()
{
	cout << "************Directions************" << endl;
	cout << "Enter the coordinates of the blob." << endl;
	cout << "Board size: " << MAXCOLUMNS << " * " << MAXROWS << "." << endl;
	cout << "Points are based on the size of the blob that is hit." << endl;
	cout << "Enter -1 to exit program." << endl;
	cout << "Player with the most points at the end of the game wins." << endl;
}

// prints the scores and declares a winner
// pre: scores is intialed with only two integers
// post: scores is printed onto the screen under the correct name 
//		 and the winner is declared. exits the program after.
void printScores(int scores[])
{
	printNewLines(4);
	cout << "Final Scores:" << endl;
	printNewLines(1);
	cout << "		" << PLAYER_ONE << ": " << scores[0] << endl;
	cout << "		" << PLAYER_TWO << ": " << scores[1] << endl;
	printNewLines(2);
	if(scores[0] > scores[1])
	{
		cout << PLAYER_ONE << " wins!" << endl;
	} else if(scores[0] < scores[1]){
		cout << PLAYER_TWO << " wins!" << endl;
	} else{
		cout << "It's a tie!" << endl;
	}
	printNewLines(2);
	cout << "             Thanks for playing. Exiting now.";
	printNewLines(5);
	exit(1);
}

// fills the display
// pre: display is intialized with the dimensions of MAXCOLUMNS and MAXROWS
// post: display is filled with 0s
void fillDisplay(bool display[][MAXCOLUMNS])
{
	for(int row = 0; row < MAXROWS; row++)
	{
		for(int column = 0; column < MAXCOLUMNS; column++)
		{
			display[row][column] = 0;
		}
	}
}

// prints new lines
// pre: num is a positve integer
// post: using num, the number of new lines are printed onto the screen
void printNewLines(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << endl;
   }
}