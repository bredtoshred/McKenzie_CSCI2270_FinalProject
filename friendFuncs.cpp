//Phil, Julio, Marcus
#include <iostream>
#include <fstream>
#include <string>
#include "friendFuncs.h"
using namespace std;

//meet the variables
string newName;
int newDOB;




void friendGraph::displayMenu()
{
	cout<< " Welcome to Social Media" << endl;
	cout<< " Would you like to... " <<endl;
	cout<< " Create an Account? (create) " << endl;
	cout<< " Add a friend? (add) " << endl;
	cout<< " Delete a friend? (delete) "<< endl;
	cout<< " Check a friends birthday? (dob) " << endl;
	cout<< " Check how many friends seperate you and another account? (depth) " << endl;
}

void friendGraph::createAccount();
{
	cout<< "create" <<endl;
}
void friendGraph::addFriend();
{
	cout<<"add"<<endl;
}
void friendGraph::deleteFriend();
{
	cout<<"delete"<<endl;
}
void friendGraph::checkDOB();
{
	cout << "dob" << endl;
}
void friendGraph::checkDepth();
{
	cout << "depth" endl;
}
	
