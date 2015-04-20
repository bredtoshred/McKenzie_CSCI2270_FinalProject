//Phil, Julio, Marcus
#ifndef FRIENDFUNCS_H
#define FRIENDFUNCS_H
#include <string>

class friendGraph
{
	public:
	friendGraph(){}
	~friendGraph();
	void buildGraph();
	void displayMenu();
	void createAccount();
	void addFriend();
	void deleteFriend();
	void checkDOB();
	void checkDepth();
	
};


/*struct friend
{
	std::string name;
	int DOB;
};
*/


#endif 
