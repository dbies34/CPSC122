// filename   grades.cpp
// author
// description: This program reads the number of homework scores and those scores
//              from an input file. It then prints headings and scores onto the screen.

const int MAXHWSIZE = 30; // should be the maximum that might be read

// reads a certain number of homework scores from a file
// pre: infile has been opened and file pointer is at the beginning of the file
//      infile is organized with the number of scores first followed by that number of scores
//      Example:
//      4 10 8 9 3
// post: numberOfHomeworks contains the number of homework scores
//       myHomework[0..numberOfHomeworks -1] contains the scores
void readHomeworkScores(ifstream& infile, int myHomework[], int& numberOfHomeworks);

// prints a number of homework scores on the screen with headings
// pre: myHomework[0..numberOfHomeworks - 1] has been filled with scores
// post: after appropriate headings, contents of myHomework[0..numberOfHomeworks - 1]
//       has been output to the screen
void printHomeworkScores(int myHomework[], int numberOfHomeworks);

int main()
{
   int myHomework[MAXHWSIZE];
   ifstream infile;
   
   infile.open("scores.dat");
   


   return 0;
}

// reads a certain number of homework scores from a file
// pre: infile has been opened and file pointer is at the beginning of the file
//      infile is organized with the number of scores first followed by that number of scores
//      Example:
//      4 10 8 9 3
// post: numberOfHomeworks contains the number of homework scores
//       myHomework[0..numberOfHomeworks -1] contains the scores
void readHomeworkScores(ifstream& infile, int myHomework[], int& numberOfHomeworks)
{
	
}

// prints a number of homework scores on the screen with headings
// pre: myHomework[0..numberOfHomeworks - 1] has been filled with scores
// post: after appropriate headings, contents of myHomework[0..numberOfHomeworks - 1]
//       has been output to the screen
void printHomeworkScores(int myHomework[], int numberOfHomeworks)
{
	
}