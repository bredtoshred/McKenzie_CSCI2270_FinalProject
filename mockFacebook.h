#ifndef MOCKFACEBOOK_H
#define MOCKFACEBOOK_H
#include <vector>
#include <string>


struct edge;

struct Person
{
    std::string name;
    int DOB;
    int ID;
    std::string location;
    std::vector<edge> friends;

    Person(){};

    Person(std::string in_name, int in_dob, std::string in_location, int id)
    {
        name = in_name;
        DOB = in_dob;
        location = in_location;
        ID = id;
    }
};

struct edge
{
    Person* fbFriend;
};

class mockFacebook
{
    public:
        mockFacebook();
        virtual ~mockFacebook();
        void addPerson(Person* user);
        void deletePerson(Person* user);
        void printUsers();
        void printFriends(Person* user);
        void addFriend(int userID, std::string friendName);
        void addFriend(int userID, int friendId);
        void deleteFriend(Person* user, std::string exFriend);
        void display(Person* user);
        Person* getUser(std::string in_name);
        int getUserId(Person* username);
        void displayInfo(std::string friend_name);
        void mutualFriends(Person* user, Person* currentUserThis);
    protected:
    private:
        std::vector<Person*> people;
};

#endif // MOCKFACEBOOK_H
