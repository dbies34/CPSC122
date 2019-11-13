#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAXROWS = 50;
const int MAXCOLUMNS = 50;

void openInputFile(ifstream& infile);
void readBlobsFile(ifstream& infile, bool blobs[][]);
void printBlobs(bool blobs[][]);
 
int main()
{
    ifstream infile;
    bool blobs[][];


    openInputFile(infile);
    readBlobsFile(infile, blobs);
    printBlobs(blobs);

 
    return 0;
}

void openInputFile(ifstream& infile)
{
    infile.open("threeverticalblobs.dat");
    if (infile.fail())
    {
        cout << "Error in Opening blobs file" << endl;
        exit(1);
    }
}

void readBlobsFile(ifstream& infile, bool blobs[][])
{
    char achar; int ascii, realValue;
	for(int row = 0; row < MAXROWS; row++)
	{
		for(int colmun = 0; colmun < MAXCOLUMNS; colmun++)
		{
			infile.get(achar);
			ascii = achar;
			realValue = ascii - '0';
			
		}
	}
}

void printBlobs(bool blobs[25][40])
{
}