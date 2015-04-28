#include <iostream>
#include "mockFacebook.h"
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu1();
void displayMenu2(Person* user);
Person* makeAccount(int ID);
bool checkBD(int dob);

int main()
{
    mockFacebook fbData;
    ifstream infile;
    infile.open("fbInfo1.txt");
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
                if (token == "Users" && spot == 0)
                    spot = 1;
                else if (token == "friends")
                    spot = 4;
                else if(token == "end")
                    spot = 4;
                else if (spot == 1)
                {
                    name = token;
                    spot++;
                }
                else if (spot == 2)
                {
                    dob = stoi(token);
                    spot++;
                }
                else if(spot == 3)
                {
                    location = token;
                    Person* newUser = new Person(name, dob, location, id);
                    fbData.addPerson(newUser);
                    spot = 1;
                    id++;
                }
                else if (spot == 4)
                {
                    currentUser = stoi(token);
                    spot = 5;
                }
                else if (spot == 5)
                {
                    addingFriend = stoi(token);
                    fbData.addFriend(currentUser, addingFriend);
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
            displayMenu1();
            cin >> command;
            if (command == 1)
            {
                string username;
                cout << "Enter username: ";
                getline(cin >> ws, username);
                currentLogin = fbData.getUser(username);
                if (currentLogin == NULL)
                    cout << "User not found!" << endl;
                else
                {
                    cout << "User found!" << endl;
                    cout << "Welcome " << currentLogin->name << '!' << endl;
                    menu = 2;
                }
            }
            else if (command == 2)
            {
                fbData.addPerson(makeAccount(id));
                id++;
                cout << "Account made successfully!" << endl;
            }
            else if (command == 3)
                fbData.printUsers();
            else if (command == 4)
            {
                cout << "Welcome to a smaller version of Facebook. Currently we \n"  << \
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
                quit = true;
            }
        }
        else if (menu == 2)
        {
            displayMenu2(currentLogin);
            cin >> command;
            if (command == 1)
            {
                fbData.printFriends(currentLogin);
            }
            else if (command == 2)
            {
                string newFriend;
                cout << "What is your friends name?" << endl;
                getline(cin>>ws, newFriend);
                int userId = fbData.getUserId(currentLogin);
                fbData.addFriend(userId,newFriend);
            }
            else if (command == 3 )
            {
                string exFriend;
                cout << "Which friend would you like to remove?" << endl;
                getline(cin>>ws, exFriend);
                fbData.deleteFriend(currentLogin, exFriend);
            }
            else if (command == 4)
            {
                /** Marcus **/

                // if friend, pass in name
                // if personal, pass in current login

            }
            else if (command == 5)
            {
                /** Also Marcus and Phil **/
                string user_input, user_input1;
                cout<<"Would you like to view your profile or a friend's(personal/friend):"<<endl;
                cin>>user_input;
                if(user_input == "personal")
                    fbData.display(currentLogin);
                else if(user_input == "friend"){
                    cout<<"Enter a friend you would like to find: "<<endl;
                    getline(cin>>ws,user_input1);
                    fbData.displayInfo(user_input1);
                }
                else
                    cout<<"User was not found. "<<endl;
            }
            else if (command == 6)
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
            else if (command == 7)
            {
                cout << "Welcome " << currentLogin->name << '!' << " Now that you're logged in, " << \
                              "you have more options on what you can do. By selecting 1, you can see" << \
                              "all of the friends you currently have. 2 will ask you for the name of a friend" << \
                              "and will add them to your friends list if they are found. 3 will let you remove" << \
                              "a friend from your friends list list. With 4, you can see how many friends you" << \
                              "and your friend both have in common (mutual friends). 5 will let you see " << \
                              "either you or a friends information. 6 will let you delete your account, and 8" << \
                              "will let you sign out" << endl;
            }
            else if (command == 8 )
            {
                currentLogin = NULL;
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
    cout << user->name << endl;
    cout << "1. Show friends" << endl;
    cout << "2. Add friend" << endl;
    cout << "3. Delete friend" << endl;
    cout << "4. Show mutual friends" << endl;
    cout << "5. Info" << endl;
    cout << "6. Delete Account" << endl;
    cout << "7. Help" << endl;
    cout << "8. Logout" << endl;
}

Person* makeAccount(int ID)
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
