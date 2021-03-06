#include "mockFacebook.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

mockFacebook::mockFacebook()
{
    //ctor
}

mockFacebook::~mockFacebook()
{
    //dtor
}

void mockFacebook::addPerson(Person* user)
{
    people.push_back(user);
}

void mockFacebook::deletePerson(Person* user)
{
    people.erase(people.begin() + user->ID);
    for (int i = 0 ; i < people.size() ; i++ )
    {
        people[i]->ID = i;
    }
    delete user;
}

void mockFacebook::printUsers()
{
    for (int i = 0 ; i < people.size() ; i++)
    {
        cout << people[i]->name << endl;
    }
}

void mockFacebook::addFriend(int userId, string friendName)
{
    bool friendFound = false;
    int friendId;
    for (int i = 0 ; i < people.size() ; i++)
    {
        if (people[i]->name == friendName && i != userId )
        {
            friendId = i;
            friendFound = true;
        }
    }
    bool friendAlreadyAdded = false;
    if (friendFound)
    {
        for (int i = 0 ; i < people[userId]->friends.size() ; i++)
        {
            if (people[userId]->friends[i].fbFriend == people[friendId])
            {
                friendAlreadyAdded = true;
                cout << "You are already friends with this person" << endl;
                break;
            }
        }
    }
    else
        cout << "User not found!" << endl;
    if (!friendAlreadyAdded)
    {
        edge connection;
        connection.fbFriend = people[userId];
        people[friendId]->friends.push_back(connection);
        connection.fbFriend = people[friendId];
        people[userId]->friends.push_back(connection);
        cout << "Friend has been added successfully" << endl;
    }

}

void mockFacebook::addFriend(int userId, int friendId)
{
    bool friendAlreadyAdded = false;
    for (int i = 0 ; i < people[userId]->friends.size() ; i++)
    {
        if (people[userId]->friends[i].fbFriend == people[friendId])
        {
            friendAlreadyAdded = true;
            break;
        }
    }
    if (!friendAlreadyAdded)
    {
        edge connection;
        connection.fbFriend = people[userId];
        people[friendId]->friends.push_back(connection);
        connection.fbFriend = people[friendId];
        people[userId]->friends.push_back(connection);
    }
}

void mockFacebook::deleteFriend(Person* user, string exFriend)
{
    int id;
    for (int i = 0 ; i < people.size() ; i ++)
    {
        if (people[i]->name == exFriend)
        {
            people[i]->ID = id;
            break;
        }
    }
    int index = -1;
    int userIndex = -1;
    for (int i = 0 ; i < user->friends.size() ; i++)
    {
        if (user->friends[i].fbFriend->ID == id)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        user->friends.erase(user->friends.begin() + index);
        for (int j = 0 ; j < people[id]->friends.size() ; j++)
        {
            if (people[id]->friends[j].fbFriend->ID == user->ID)
            {
                index = j;
                break;
            }
        }
        people[id]->friends.erase(people[id]->friends.begin() + index);
    }
    else
        cout << "Person not found in your friends list" << endl;
}

Person* mockFacebook::getUser(string username)
{
    for (int i = 0 ; i < people.size() ; i++)
    {
        if (people[i]->name == username)
            return people[i];
    }
    return NULL;
}

int mockFacebook::getUserId(Person* username)
{
    return username->ID;
}

void mockFacebook::printFriends(Person* user)
{
    for (int i = 0 ; i < user->friends.size() ; i ++)
        cout << user->friends[i].fbFriend->name << endl;
}
void mockFacebook::displayInfo(string friend_name)
{
    for(int i=0; i< people.size(); i++)
    {
        if(people[i]->name== friend_name)
        {
            cout<<"User: "<<people[i]->name<<endl;
            cout<<"Birth date: "<< people[i]->DOB<<endl;
            cout<<"Hometown: "<< people[i]->location<<endl;
            break;
        }
        else if(people[i]->name!=friend_name && i==people.size()-1)
            cout<<"User not found!"<<endl;
    }

}

void mockFacebook::display(Person* user)
{
    for(int i=0; i< people.size(); i++)
    {
        if(people[i]->name== user->name)
        {
            cout<<"User: "<<people[i]->name<<endl;
            cout<<"Birth date: "<< people[i]->DOB<<endl;
            cout<<"Hometown: "<< people[i]->location<<endl;
            break;
        }
        else if((people[i]->name!=user->name) && (i==people.size()-1))
            cout<<"User not found!"<<endl;
    }


}
