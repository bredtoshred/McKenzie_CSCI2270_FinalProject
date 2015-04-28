// Group Project
// members: Julio Lopez, Marcus Garza, Phil McKenzie
#include <iostream>
#include "mockFacebook.h"
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu1();// first display menu to allow you to login and create an account
void displayMenu2(Person* user);// display once you're logged in as an account
Person* makeAccount(int ID);// make an account
bool checkBD(int dob);// check if the date entered is valid

int main()
{
    mockFacebook fbData;// instance of the class
    ifstream infile;
    infile.open("fbInfo1.txt");// reads in text file in order to add in preloaded users and their friends list
    string line, token, name, location;
    int dob,addingFriend;
    int id = 0;
    int spot = 0;
    int currentUser = -1;
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            istringstream iss (line);
            while (getline(iss, token, ','))
            {
                if (token == "Users" && spot == 0)// once the text file hits Users, the next spot is the name
                    spot = 1;
                else if (token == "friends")// once it hits friends, read in user's list of friends
                    spot = 4;
                else if(token == "end")// also knows it's still parsing the friend list, does not include end.
                    spot = 4;
                else if (spot == 1)
                {
                    name = token;// sets name
                    spot++;
                }
                else if (spot == 2)
                {
                    dob = stoi(token);//sets date of birth
                    spot++;
                }
                else if(spot == 3)
                {
                    location = token;// sets location
                    Person* newUser = new Person(name, dob, location, id);//creates a new user, stores in name, DOB, location, id into the person struct
                    fbData.addPerson(newUser);//adds the new user to the graph
                    spot = 1;
                    id++;// increases id, so there are no two similar ids
                }
                else if (spot == 4)
                {
                    currentUser = stoi(token);// sets current user to last in list of users
                    spot = 5;
                }
                else if (spot == 5)
                {
                    addingFriend = stoi(token);
                    fbData.addFriend(currentUser, addingFriend);//creates new user's friend list
                }

            }
        }
    }
    cout << "------ Welcome! ------" << endl;
    Person* currentLogin;
    int menu = 1;
    int command = -1;
    bool quit = false;
    while( !quit)
    {
        if (menu == 1)
        {
            displayMenu1();// displays login menu as long as menu =1
            cin >> command;
            if (command == 1)
            {
                string username;
                cout << "Enter username: ";
                getline(cin >> ws, username);
                currentLogin = fbData.getUser(username);// retrieves user from current list of users, sets it as current
                if (currentLogin == NULL)
                    cout << "User not found!" << endl;
                else
                {
                    cout << "User found!" << endl;
                    cout << "Welcome " << currentLogin->name << '!' << endl;
                    menu = 2;// sets menu to 2, brings user to main menu
                }
            }
            else if (command == 2)
            {
                fbData.addPerson(makeAccount(id));// creates account, iterate id afterwards
                id++;
                cout << "Account made successfully!" << endl;
            }
            else if (command == 3)
                fbData.printUsers();// displays all users
            else if (command == 4)// displays help menu
            {
                cout << "Welcome to a smaller version of Facebook. Currently we have \n"  << \
                              "five options to choose from. Option 1 lets you sign into a user \n" << \
                              "account where you'll have the option of viewing friends, adding \n" << \
                              "friends, deleting them, etc. Option 2 lets you create an account. \n" << \
                              "Option 3 gives a list of all the users. Option 4 will show this \n" << \
                              "small tutorial. Option 5 will end program, and will also save user and \n" << \
                              "friend information for future use." << endl;
            }
            else if (command == 5)
            {
                cout << "Goodbye!" << endl;
                quit = true;// quits program
            }
        }
        else if (menu == 2)
        {
            displayMenu2(currentLogin);//displays main menu
            cin >> command;
            if (command == 1)
            {
                cout<<currentLogin->name<<"'s current friends:"<<endl;
                fbData.printFriends(currentLogin);// prints the current user's friend list, iterates through the friend struct
            }
            else if (command ==2)
            {
                cout<<"All current users: "<<endl;
                fbData.printUsers();// displays all users, not just friends, iterates through the people struct

            }

            else if (command == 3)
            {
                string newFriend;
                cout << "What is your friends name?" << endl;
                getline(cin>>ws, newFriend);
                int userId = fbData.getUserId(currentLogin);// adds new friend using the currentLogin's userId, and newFriend
                fbData.addFriend(userId,newFriend);
            }
            else if (command == 4 )
            {
                string exFriend;
                cout << "Which friend would you like to remove?" << endl;
                getline(cin>>ws, exFriend);
                fbData.deleteFriend(currentLogin, exFriend);// accesses delete function, removes exFriend from currentLogin's friend list
            }
            else if (command == 5)
            {

                /** Marcus **/
                string mutualFriend;
                cout<<"Please enter a friend you would like to compare friends: "<<endl;
                getline(cin>>ws, mutualFriend);
                Person* friendCompare = fbData.getUser(mutualFriend);//retrieves user that you're looking for
                if(friendCompare != NULL)
                    fbData.mutualFriends(friendCompare, currentLogin);//compares friend's vectors between currentLogin and the requested user
                else
                    cout<<"Friend does not exist!"<<endl;
            }
            else if (command == 6)
            {
                /** Also Marcus and Phil **/
                string user_input, user_input1;
                cout<<"Would you like to view your profile or a friend's(personal/friend):"<<endl;
                cin>>user_input;
                if(user_input == "personal")
                    fbData.display(currentLogin);//displays current
                else if(user_input == "friend"){
                    cout<<"Enter a friend you would like to find: "<<endl;
                    getline(cin>>ws,user_input1);
                    fbData.displayInfo(user_input1);// displays desired user by first searching through the people struct
                }
                else
                    cout<<"User was not found. "<<endl;
            }
            else if (command == 7)// deletes account
            {
                string confirmation;
                cout << "Are you sure you want to delete this account (yes/no)" << endl;
                getline(cin>>ws,confirmation);
                if (confirmation == "yes")
                {
                    fbData.deletePerson(currentLogin);
                    currentUser = NULL;
                    menu = 1;
                }
            }
            else if (command == 8)//help screen
            {
                cout << "Welcome " << currentLogin->name << '!' << " Now that you're logged in, " << \
                              "you have more options on what you can do. By selecting 1. you can see" << \
                              "all of the friends you currently have. 2. will display all users. 3. will ask you for the name of a friend" << \
                              "and will add them to your friends list if they are found. 4. will let you remove" << \
                              "a friend from your friends list list. With 5, you can see how many friends you" << \
                              "and your friend both have in common (mutual friends). 6 will let you see " << \
                              "either you or a friends information. 7. will let you delete your account, and 9." << \
                              "will let you sign out" << endl;
            }
            else if (command == 9 )
            {
                currentLogin = NULL;// resets display to login screen
                menu = 1;
            }
        }
    }
}

void displayMenu1()
{
    cout << "  Main Menu  " << endl;
    cout << "1. Login" << endl;
    cout << "2. Create new account" << endl;
    cout << "3. See all accounts" << endl;
    cout << "4. Help" << endl;
    cout << "5. Quit" << endl;
}

void displayMenu2(Person* user)
{
    cout << "Current User: "<<user->name << endl;
    cout << "1. Show friends" << endl;
    cout << "2. Show all current users"<<endl;
    cout << "3. Add friend" << endl;
    cout << "4. Delete friend" << endl;
    cout << "5. Show mutual friends" << endl;
    cout << "6. Info" << endl;
    cout << "7. Delete Account" << endl;
    cout << "8. Help" << endl;
    cout << "9. Logout" << endl;
}

Person* makeAccount(int ID)// stores requested info into new Person, creates a new user.
{
    string name,location;
    int DOB;
    cout << "What is your name?" << endl;
    getline(cin>>ws, name);
    cout << "What is your birthday? (MMDDYYYY)" << endl;
    cin >> DOB;
    bool validBirthday = checkBD(DOB);
    while (!validBirthday)
    {
        cout << "Not valid Birthday, please enter again (MMDDYYYY)" << endl;
        cin >> DOB;
        validBirthday = checkBD(DOB);
    }
    cout << "What is your hometown?" << endl;
    getline(cin>>ws,location);
    Person* newUser = new Person(name, DOB, location, ID);
    return newUser;
}

bool checkBD(int dob)
{
    string str = to_string(dob);
    if (str.size() == 7)
    {
        string zero = "0";
        zero += str;
        str = zero;
    }
    if (stoi(str.substr(0,2))<= 12)
        return true;
    else
        return false;

}
