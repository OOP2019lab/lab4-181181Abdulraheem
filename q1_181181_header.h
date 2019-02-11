#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

class CricketTeam
{
	string* memberNames;
	int noOfMembers; ///////////////////
	char *teamName;
	int scoreInLast10Matches[10];    ////////////////////
	int rank;             ////////////
	string captain;

public:
	CricketTeam();          //constructor
	CricketTeam(string, int);
	CricketTeam(string);
	void setCaptain(string);
	void setRank(int);
	void setTeamName(string);
	void setNoOfMembers(int);
	string getCaptain();
	int getRank();
	string getTeamName();
	int getNoOfMembers();
	void printTeam();
	~CricketTeam(); // destructor
};
