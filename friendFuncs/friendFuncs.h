//Phil, Julio, Marcus
#ifndef FRIENDFUNCS_H
#define FRIENDFUNCS_H
#include <string>

class friendGraph
{
	public:
	friendGraph(){}
	~friendGraph();
	//friendGraph buildGraph();
	
	void addEdge();
	void addVertex();
	void displayMenuOne();
	void displayMenuTwo();
	void createAccount();
	void deleteFriend();
	void checkDOB();
	void checkDepth();
	//void addFriend();
	
};


/*struct friend
{
	std::string name;
	int DOB;
};
*/


#endif 
