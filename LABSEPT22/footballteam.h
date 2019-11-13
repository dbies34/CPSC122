// Specification of Abstract Data Type FootballTeam
//     data object: name, mascot, home city, wins and losses for an NFL Football team
//     operations: read data from a file, print data onto a file
//                 get the name of the team
//                 get the mascot of the team
//                 get the home city of the team
//                 get the number of wins of the team
//                 get the number of losses of the team

// what includes do we need?
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class FootballTeam{
public: // these are called member functions or methods of the class
        // a client function can call any of these functions

// creates an empty team object
// post team object exists and is empty
FootballTeam();		// the constructor

// destroys a team object
// pre team object exists
// post team object does not exist
~FootballTeam();	// the destructor

// reads data for one football team from an input file
// pre  infile has been opened with infile's place holder at the
//      beginning of a line that contains the information for a team object
//      name mascot homeCity wins losses
// post infile's place holder is at the end before the newline character
//      the team's data is in the data members
void readFootballTeam(ifstream& infile);

// prints data for one football team object on an output file or the screen
// pre  outfile has been opened with outfile's place holder at the start of a new line
// post the data for a team has been written on output in the order
//      name mascot homeCity wins losses
//      but is such that the strings are left-justified and the numbers are right-justified
void printFootballTeam(ostream& output);

// copies the name of a football team from team object
// post theName has the name of the team object
void getName(string& theName);

// copies the name of a football team's mascot from team object
// post theMascot has the name of the team object's mascot
void getMascot(string& theMascot);

// copies the name of a football team's home city from team object
// post theHomeCity has the name of the team object's city
void getHomeCity(string& theHomeCity);

// copies the name of a football team's wins from team object
// post theWins has the name of the team object's number of wins
void getWins(int& theWins);

// copies the name of a football team's losses from team object
// post theLosses has the name of the team object's number of losses
void getLosses(int& theLosses);

// copies the number of wins into a team object
// pre theWins has been assigned a non-negative value_comp
// post wins in the team object has been assigned theWins value
void setWins(int theWins);

// copies the number of losses into a team object
// pre theLosses has been assigned a non-negative value_comp
// post losses in the team object has been assigned theLosses value
void setLosses(int theLosses);

private: // these are the data members of the class
         // they can only be accessed by member functions or methods of the class
		 // a client function cannot access these directly. There is a WALL between
		 // this data object, team object, and a client program.
		 
   string name;
   string mascot;
   string homeCity;
   int wins;
   int losses;
};