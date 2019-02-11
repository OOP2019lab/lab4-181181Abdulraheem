// oop lab 4.cpp : Defines the entry point for the console application.
//

#include "cric.h"


int main()
{
	string file = "Cric.txt", temp; // temp for taking input from console
	int num = 0; // as above
	CricketTeam Pakistan(file);
	Pakistan.printTeam();
	

    return 0;
}

