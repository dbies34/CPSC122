// Drew Bies
// username: abies2
// blobs.cpp
// 11-3-17
// this program opens a file with the name of herecometheblobs.dat using infile.
//		bool blobs is created and filled with the contents of the file.
//		blobs is printed onto the screen and the number of blobs are printed below.
//		the blobs are counted in all eight directions.



#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAXROWS = 25;
const int MAXCOLUMNS = 50;

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

// prints the blobs on to the screen
// pre: blobs is filled ones and zeros with the dimensions of MAXCOLUMNS and MAXROWS
// post: prints the array blobs onto the screen
void printBlobs(bool blobs[][MAXCOLUMNS]);

// counts the blobs in the given 2D array
// pre: blobs is filled ones and zeros with the dimensions of MAXCOLUMNS and MAXROWS
// post: returns the numbers of blobs in the blobs array
int countBlobs(bool blobs[][MAXCOLUMNS]);

// erases a blob in all eight directions
// pre: arow and acolumn are integers
//      blobs is filled with ones and zeros with the dimensions of MAXCOLUMNS and MAXROWS
// post: the blob in the blobs array of ones is replaced with zeros
void eraseABlob(int arow, int acolumn, bool blobs[][MAXCOLUMNS]);

// prints new lines
// pre: num is a positve integer
// post: using num, the number of new lines are printed onto the screen
void printNewLines(int num);
 
int main()
{
    ifstream infile;
    bool blobs[MAXROWS][MAXCOLUMNS];
	printNewLines(5);

    openInputFile(infile);
    readBlobsFile(infile, blobs);
    printBlobs(blobs);
	printNewLines(3);
	
	cout << "Number of blobs: " << countBlobs(blobs) << endl;
	
	printNewLines(5);
	
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

// prints the blobs on to the screen
// pre: blobs is filled ones and zeros with the dimensions of MAXCOLUMNS and MAXROWS
// post: prints the array blobs onto the screen
void printBlobs(bool blobs[][MAXCOLUMNS])
{
	cout << "    0123456789" << endl;
	for(int row = 0; row < MAXROWS; row++)
	{
		if(row < 10)
		{
			cout << " ";
		}
		cout << row << ": ";
		for(int column = 0; column < MAXCOLUMNS; column++)
		{
			cout << blobs[row][column];
		}
		cout << endl;
	}
}

// counts the blobs in the given 2D array
// pre: blobs is filled ones and zeros with the dimensions of MAXCOLUMNS and MAXROWS
// post: returns the numbers of blobs in the blobs array
int countBlobs(bool blobs[][MAXCOLUMNS])
{
	int countOfBlobs = 0;
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
				eraseABlob(row, column, copy);
			}
		}
	}	
	return countOfBlobs;
}

// erases a blob in all eight directions
// pre: arow and acolumn are integers
//      blobs is filled with ones and zeros with the dimensions of MAXCOLUMNS and MAXROWS
// post: the blob in the blobs array of ones is replaced with zeros
void eraseABlob(int arow, int acolumn, bool blobs[][MAXCOLUMNS])
{
	if(arow >= 0 && arow < MAXROWS && acolumn >= 0 && acolumn < MAXCOLUMNS)
	{
		if(blobs[arow][acolumn])
		{
			blobs[arow][acolumn] = 0; // erase
			eraseABlob(arow - 1, acolumn, blobs); // up
			eraseABlob(arow + 1, acolumn, blobs); // down
			eraseABlob(arow, acolumn - 1, blobs); // left
			eraseABlob(arow, acolumn + 1, blobs); // right
			eraseABlob(arow - 1, acolumn - 1, blobs); // up and left
			eraseABlob(arow - 1, acolumn + 1, blobs); // up and right
			eraseABlob(arow + 1, acolumn - 1, blobs); // down and left
			eraseABlob(arow + 1, acolumn + 1, blobs); // down and right
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