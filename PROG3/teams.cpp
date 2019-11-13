// This program reads data from a file for a number of  NFL football teams.
// It then prints the information in a nice format on a file.
// Friday, September 15 and Monday, September 18
// teams.cpp
// Drew Bies
// Chris Martin
// username: abies2

#include <string>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

struct FootballTeam{
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
void readMultipleTeams(ifstream& infile, FootballTeam*& teams, int& numberOfTeams);
void printMultipleTeams(ofstream& outfile, FootballTeam* teams, int numberOfTeams);
void bubbleSort(FootballTeam*& teams, int numberOfTeams, int n);
int searchForTeam(string targetName, FootballTeam* teams, int numberOfTeams);
void getTeamName(string& teamName);
void printNewLines(ostream& output, int desiredLines);

int main(){
    ifstream infile;
	ofstream outfile;
	FootballTeam* teams;
	int numberOfTeams;
	
	openInputFile(infile);
	openOutputFile(outfile);
	
	readMultipleTeams(infile, teams, numberOfTeams);
	printMultipleTeams(outfile, teams, numberOfTeams);
	bubbleSort(teams, numberOfTeams, 1);
	printMultipleTeams(outfile, teams, numberOfTeams);
	bubbleSort(teams, numberOfTeams, 2);
	printMultipleTeams(outfile, teams, numberOfTeams);
	bubbleSort(teams, numberOfTeams, 3);
	printMultipleTeams(outfile, teams, numberOfTeams);
	delete [] teams;
	return 0;
}

void openInputFile(ifstream& infile){
	infile.open("infootball.dat");
	if (infile.fail()){
		cout << "Error opening file named infootball.dat";
		exit(1);
	}
}

void openOutputFile(ofstream& outfile){
	outfile.open("outfootball.dat");
	if (outfile.fail()){
		cout << "Error opening file named outfootball.dat";
		exit(1);
	}
}

/*
pre-condition: infile has been opened with place holder at the beginning
	of a line and then has a team's information in the following order
		name mascot homeCity wins losses
post-condition: ateam has name, mascot, home city, wins, and losses
	from the line in the infile
   infile's place holder is at the end of the line of data before new line 
*/
void readFootballTeam(ifstream& infile, FootballTeam& ateam){
	infile >> ateam.name;
	infile >> ateam.mascot;
	infile >> ateam.homeCity;
	infile >> ateam.wins;
	infile >> ateam.losses;
}

/*
pre-condition: outfile has been opened successfully. infile has been written correctly. function readFootballTeam
	has been run correctly.
post-condition: prints the number of teams in the same format below
*/
void printFootballTeam(ofstream& outfile, FootballTeam ateam){
	outfile << left << setw(20) << ateam.name;
	outfile << left << setw(10) << ateam.mascot;
	outfile << left << setw(15) << ateam.homeCity;
	outfile << right << setw(10) << ateam.wins;
	outfile << right << setw(10) << ateam.losses << endl;
}

/*
pre-condition: infile has been opened correctly with the number of teams on the first line
	and the correct number of teams follow on the next lines
post-condition:	uses readFootballTeam to read multiple teams and put them into the file
*/
void readMultipleTeams(ifstream& infile, FootballTeam*& teams, int& numberOfTeams){
	infile >> numberOfTeams;
	teams = new FootballTeam [numberOfTeams];
	for(int k = 0; k < numberOfTeams; k++){
		readFootballTeam(infile, teams[k]);
	}
}

/*
pre-condition: outfile has been opened correctly. the information of teams array and number 
	of teams is correctly written
post-condition:	uses printFootballTeam to print multiple teams and put them into the file
*/
void printMultipleTeams(ofstream& outfile, FootballTeam* teams, int numberOfTeams){
	printNewLines(outfile, 3);
	outfile << "     " << left << setw(20) << "Team Name";
	outfile << left << setw(10) << "Mascot";
	outfile << left << setw(15) << "Home City";
	outfile << right << setw(10) << "Wins";
	outfile << right << setw(10) << "Losses" << endl;
	printNewLines(outfile, 2);
	for(int i = 0; i < numberOfTeams; i++){
		outfile << "     ";
		printFootballTeam(outfile, teams[i]);
	}
	printNewLines(outfile, 2);
}

/*
pre-condition: array teams has been filled correctly. numberOfTeams is the correct 
	number of teams. int n is either 1 for name, 2 for mascot or 3 for wins.
post-condition: will sort the arrays by either name, mascot, or wins.
*/
void bubbleSort(FootballTeam*& teams, int numberOfTeams, int n){
	bool hasSwapped = true;
	int pass = 1;
	while(hasSwapped && (pass < numberOfTeams)){
		hasSwapped = false;
		for(int i = 0; i < numberOfTeams - pass; i++){
			if(n == 1){
				if(teams[i].name > teams[i + 1].name){
					swap(teams[i], teams[i + 1]);
					hasSwapped = true;
				}
			} 
			if(n == 2){
				if(teams[i].mascot > teams[i + 1].mascot){
					swap(teams[i], teams[i + 1]);
					hasSwapped = true;
				}
			} 
			if(n == 3){
				if(teams[i].wins < teams[i + 1].wins){
					swap(teams[i], teams[i + 1]);
					hasSwapped = true;
				}
			}			
		}
		pass++;
	}
}

int searchForTeam(string targetName, FootballTeam* teams, int numberOfTeams){
	for(int i = 0; i < numberOfTeams; i++){
		if(teams[i].name == targetName){
			return i;
		}
	}
}

void getTeamName(string& teamName){ 
    printNewLines(cout, 3);
	cout << "Enter team name -> ";
	cin >> teamName;
}

void printNewLines(ostream& output, int desiredLines){
	for (int k = 0; k < desiredLines; k++){
	   output << endl;	
	}
}