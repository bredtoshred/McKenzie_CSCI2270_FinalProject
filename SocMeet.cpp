//Phil, Julio, Marcus
#include <iostream>
#include <fstream>
#include <string>
#include "friendFuncs.h"
using namespace std;

int main(int argc, char*argv[])
{
	friendGraph *FG = new friendGraph();
	FG->displayMenu();
	string cmd = "";
	cin.ignore();
	getline(cin, cmd);
	
	if(cmd == "create" || cmd == "add" || cmd == "delete" || cmd == "dob" || cmd == "depth")
	{
		if( cmd == "create")
		{
			FG->createAccount();
		}
		else if( cmd == "add")
		{
			FG->addFriend();
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
