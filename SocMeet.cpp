//Phil, Julio, Marcus
#include <iostream>
#include <fstream>
#include <string>
#include "friendFuncs.h"
using namespace std;

int main(int argc, char*argv[])
{
	friendGraph *FG = new friendGraph();
	string cmd = "";
	string newName;			//name to be associated with creating a new account
	int newDOB;				//DOB to be associated with creating a new account
	FG->displayMenuOne();
		cout<< "What is your name? " <<endl;
		getline(cin , newName);
		cout<< "what is your date of birth? (enter in format mmddyy)"<<endl;
		getline(cin, newDOB);

	FG->displayMenuTwo;
	getline(cin,cmd);
	if(cmd == "create" || cmd == "add" || cmd == "delete" || cmd == "dob" || cmd == "depth")
	{
		if( cmd == "create")
		{
			FG->addVertex();
		}
		else if( cmd == "add")
		{
			FG->addEdge();
		}
		else if( cmd == "delete")
		{
			FG->deleteFriend();
		}
		else if( cmd == "dob")
		{
			FG->checkDOB();
		}
		else if( cmd == "depth")
		{
			FG->checkDepth();
		}
	}
		else
		{
		cout << "Please enter valid command" << endl;
		void displayMenu();
		}
}
