// Implementation of Abstract Data Type FootballTeam
//     data object: name, mascot, home city, wins and losses for an NFL Football team
//     data structure: string's for name, mascot, and home city; integers for wins and losses
//     operations: read data from a file, print data onto a file
//                 get the name of the team
//                 get the mascot of the team
//                 get the home city of the team
//                 get the number of wins of the team
//                 get the number of losses of the team

#include "footballteam.h"

// creates an empty team object
// post team object exists and is empty
FootballTeam::FootballTeam() // ("::" scope resolution operator)
{
	wins = 0;
	losses = 0;
}

// destroys a team object
// pre team object exists
// post team object does not exist
FootballTeam::~FootballTeam()
{
	wins = 0;
	losses = 0;
}

// reads data for one football team from an input file
// pre  infile has been opened with infile's place holder at the
//      beginning of a line that contains the information for a team object
//      name mascot homeCity wins losses
// post infile's place holder is at the end before the newline character
//      the team's data is in the data members
void FootballTeam::readFootballTeam(ifstream& infile)
{
	infile >> name;
	infile >> mascot;
	infile >> homeCity;
	infile >> wins;
	infile >> losses;
}

// prints data for one football team object on an output file or the screen
// pre  output has been opened with output's place holder at the start of a new line
// post the data for a team has been written on output in the order
//      name mascot homeCity wins losses
//      but is such that the strings are left-justified and the numbers are right-justified
void FootballTeam::printFootballTeam(ostream& output)
{
	output << name << " ";
	output << mascot << " ";
	output << homeCity << " ";
	output << wins << " ";
	output << losses;
}

// copies the name of a football team from team object
// post theName has the name of the team object
void FootballTeam::getName(string& theName)
{
	theName = name;
}

// copies the name of a football team's mascot from team object
// post theMascot has the name of the team object's mascot
void FootballTeam::getMascot(string& theMascot)
{
	theMascot = mascot;
}

// copies the name of a football team's home city from team object
// post theHomeCity has the name of the team object's city
void FootballTeam::getHomeCity(string& theHomeCity)
{
	theHomeCity = homeCity;
}

// copies the name of a football team's wins from team object
// post theWins has the name of the team object's number of wins
void FootballTeam::getWins(int& theWins)
{
	theWins = wins;
}

// copies the name of a football team's losses from team object
// post theLosses has the name of the team object's number of losses
void FootballTeam::getLosses(int& theLosses)
{
	theLosses = losses;
}

// copies the number of wins into a team object
// pre theWins has been assigned a non-negative value_comp
// post wins in the team object has been assigned theWins value
void FootballTeam::setWins(int theWins)
{
	wins = theWins;
}

// copies the number of losses into a team object
// pre theLosses has been assigned a non-negative value_comp
// post losses in the team object has been assigned theLosses value
void FootballTeam::setLosses(int theLosses)
{
	losses = theLosses;
}