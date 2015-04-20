//Phil, Julio, Marcus
#include <iostream>
#include <fstream>
#include <string>
#include "friendFuncs.h"
using namespace std;

//meet the variables
string newName;			//name to be associated with creating a new account
int newDOB;				//DOB to be associated with creating a new account




void friendGraph::displayMenuOne()
{
	cout<< " Welcome to Social Media" << endl;
	cout<< " Lets start by creating an account" << endl;
	cout<< " To create an account type (create)" << endl;
}

void friendGraph::displayMenuTwo()
{
	cout<< " Now that you have created an account would you like to...
	//cout<< " Create an Account? (create) " << endl;
	cout<< " Add a friend? (add) " << endl;
	cout<< " Delete a friend? (delete) "<< endl;
	cout<< " Check a friends birthday? (dob) " << endl;
	cout<< " Check how many friends seperate you and another account? (depth) " << endl;
}

void friendGraph::createAccount(string newName, int newDOB)
{
	cout<< "entered create" <<endl;
}
void friendGraph::addVertex()
{
	cout<<"entered add account"<<endl;
}
void friendGraph::deleteFriend()
{
	cout<<"entered delete"<<endl;
}
void friendGraph::checkDOB()
{
	cout << "entered dob" << endl;
}
void friendGraph::checkDepth()
{
	cout << "entered depth"<< endl;
}

void friendGraph::addEdge()
{
	cout<<"entered add friend"<<endl;
