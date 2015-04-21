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
    bool found = false;
    //cout<<"FIRST"<<n<<endl;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == n){
            found = true;
            //cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false)
    {
        vertex v;
        v.name = n;
        //IDK WHAT ID EQUALSSSSSSSSSSS
        v.district = -1;
        vertices.push_back(v);

    }
    //cout<<"Verticesssssss"<<endl;
    //for(int x = 0; x < vertices.size(); x++)
        //cout<<vertices[x].name<<endl;
}


void friendGraph::addVertex()
{
    //cout<<"ADDING EDGE"<<endl;
    if(weight != 0 && weight != -1)
    {
    for(int i = 0; i < vertices.size(); i++)
    {
        //cout<<"first for"<<endl;
        if(vertices[i].name == v1)
        {
            //cout<<"first if"<<endl;
            for(int j = 0; j < vertices.size(); j++)
            {
                //cout<<"second for"<<endl;
                if(vertices[j].name == v2 && i != j && weight != 0 && weight != -1)
                {
                    //cout<<"second if"<<endl;
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //cout<<av.v->name<<"~~~~~~~~~~~~~~~~~~"<<vertices[i].name<<endl;
                    /*another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                    */ 
                }
            }
        }
    }
}
    //cout<<"adjacent vertices"<<endl;
    //for(int i = 0; i < 16; i++)
        //cout<<vertices[7].adj[i].v->name;
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
