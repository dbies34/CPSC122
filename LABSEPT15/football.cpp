// This program reads data from a file for NFL football team.
// It then prints the information in a nice format on a file.
// Friday, September 15

#include <string>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

struct FootballTeam
{
    string name;
	string mascot;
	string homeCity;
	int wins;
	int losses;
};

void openInputFile(ifstream& infile);
void openOutputFile(ofstream& outfile);
void readFootballTeam(ifstream& infile, FootballTeam& ateam);
void printFootballTeam(ofstream& outfile, FootballTeam ateam);

int main()
{
    ifstream infile;
	ofstream outfile;
	FootballTeam ateam;
	
	openInputFile(infile);
	openOutputFile(outfile);
	
	readFootballTeam(infile, ateam);
	printFootballTeam(infile, ateam);
	
	return 0;

}

void openInputFile(ifstream& infile)
{
	infile.open("infootball.dat");
	if (infile.fail())
	{
		cout << "Error opening file named infootball.dat";
		exit(1);
	}
}

void openOutputFile(ofstream& outfile)
{
	outfile.open("outfootball.dat");
	if (outfile.fail())
	{
		cout << "Error opening file named outfootball.dat";
		exit(1);
	}
}

void readFootballTeam(ifstream& infile, FootballTeam& ateam)
{
	infile >> ateam.name;
	infile >> ateam.mascot;
	infile >> ateam.homeCity;
	infile >> ateam.wins;
	infile >> ateam.losses;
}

void printFootballTeam(ofstream& outfile, FootballTeam ateam)
{
	outfile << left << setw(20) << ateam.name;
	outfile << left << setw(20) << ateam.mascot;
	outfile << left << setw(15) << ateam.homeCity;
	outfile << right << setw(5) << ateam.wins;
	outfile << right << setw(5) << ateam.losses;
}