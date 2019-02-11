#include "cric.h"

CricketTeam::CricketTeam() // constructor
{
	memberNames = nullptr;
	no_of_members = 0;
	teamName = NULL;
	for (int i = 0; i < 10; i++)
		scoreInLast10Matches[i] = -1;
	rank = -1;
	captain = "NOTHING" ;
}

CricketTeam::CricketTeam(string name, int members) 
{
	int size = name.length() , i;
	teamName = new char[size + 1];
	for (i = 0 ; i< size ; i++)
	{
		teamName[i] = name[i];
	}
	teamName[size] = NULL ;
	no_of_members = members;
	memberNames = new string[members];
	rank = 0;
	for (i = 0; i < 10; i++) {
		scoreInLast10Matches[10] = -1;
	}
	captain = "NOTHING";
}

CricketTeam::CricketTeam(string filename) 
{
	ifstream read;
	read .open (filename);
	while (!read.eof())
	{
		string waste, tName;
		getline(read, waste, ':');
		getline(read, waste);
		int size = waste.length();
		teamName = new char[size + 1];
		int i;
		for (i = 0; i < size; i++)
			teamName[i] = waste[i];
		teamName[i] = NULL;
		getline(read, waste, ':');
		read >> no_of_members;
		memberNames = new string[no_of_members];
		getline(read, waste);
		for (int i = 0; i < no_of_members; i++)
		{
			getline(read, waste);
			memberNames[i] = waste;
		}
		getline(read, waste, ':');
		read >> rank;
		getline(read, waste);
		getline(read, captain);
		getline(read, waste, ':');
		for (int i = 0; i < 10; i++)
		{
			read >> scoreInLast10Matches[i];
		}
	}
}



void CricketTeam::setCaptain(string cpt)
{
	captain = cpt;
}
void CricketTeam::setTeamName(string name)
{
	name = teamName;
}

void CricketTeam::setno_of_members(int member)
{
	member = no_of_members;
}

void CricketTeam::setRank(int top)
{
	rank = top;
}


int CricketTeam::getRank()
{
	return rank;
}

string CricketTeam::getCaptain()
{
	return captain;
}

string CricketTeam::getTeamName()
{
	return teamName;
}

int CricketTeam::getno_of_members()
{
	return no_of_members;
}
void CricketTeam::printTeam()
{
	cout << "Team Name: " << teamName << endl;
	cout << "Total team players: " << no_of_members << endl;
	for (int i = 0; i < no_of_members; i++)
		cout << memberNames[i] << endl;
	cout << "Rank: " << rank<<endl;
	cout << "Captain: " << captain << endl;
	cout << "Score: ";
	for (int i = 0; i < 10; i++)
	{
		if (scoreInLast10Matches[i] != -1)
			cout << scoreInLast10Matches[i] << ",";
	}
}

CricketTeam::~CricketTeam() // destructor
{
	delete[]memberNames;
	delete[]teamName;
	memberNames = nullptr;
	teamName = nullptr;
}

