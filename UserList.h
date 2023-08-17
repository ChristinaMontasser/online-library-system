#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED
#include "User.h"
#include<iostream>
#include <stdlib.h>
using namespace std;

class UserList{
    private:

        int capacity;

    public:
        User* users;
        int usersCount;
        UserList();
        UserList(const UserList& anotherList);
        void addUser(User user); // at the end of the array.
        User& searchUser(string name);
        User& searchUser(int id);
        void increamentUsers();
        void deleteUser(int id);
        friend ostream &operator<<( ostream &output, UserList &userList );//to display all books
        ~UserList();
};



#endif // USERLIST_H_INCLUDED
