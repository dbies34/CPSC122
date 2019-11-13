// client program of ADT Football Team
// Drew Bies

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include "footballteam.h"
using namespace std;

void openInputFile(ifstream& infile);
void openOutputFile(ofstream& outfile);

int main()
{
	ifstream infile;
	ofstream outfile;
	FootballTeam oneTeam;	// runs the constructor of class Football
	
	string mascot; // for problem 1
	openInputFile(infile);
	openOutputFile(outfile); // for problem 2
	oneTeam.readFootballTeam(infile);
	
	oneTeam.getMascot(mascot); // for problem 1
	cout << mascot << endl; // for problem 1
	
	oneTeam.setLosses(0); // for problem 2
	oneTeam.printFootballTeam(outfile); // for problem 2
	
	return 0;
}

void openInputFile(ifstream& infile)
{
	infile.open("team.dat");
	if(infile.fail())
	{
		cout << "Error opening file named team.dat. Exiting now" << endl;
		exit(1);
	}
}

void openOutputFile(ofstream& outfile)
{
	outfile.open("outTeam.dat");
	if (outfile.fail())
	{
		cout << "Error opening file named outTeam.dat";
		exit(1);
	}
}