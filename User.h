//
// Created by EGYPT on 22/11/2020.
//

#ifndef ONLINE_LIBRARY_SYSTEM_USER_H
#define ONLINE_LIBRARY_SYSTEM_USER_H



#include<iostream>
#include <stdlib.h>
using namespace std;

class User {
private:
    string name;
    int age;
    int id; // Make sure that the id is incremental. First id is 1, second is 2 and so on
    string password;
    string email;
public:
    User();
    User(const User &obj);
    User(string nname, int age, string email, string password, int id);
    bool operator==(const User &obj);
    void setName(string name);
    string getName() const;
    void setPassword(string password);
    string getPassword();
    void setEmail(string email);
    string getEmail();
    void setAge(int age);
    int getAge();
    void setId(int id);
    int getId();
    //User& operator =(const User &obj);
    friend ostream &operator<<(ostream &output, const User &obj );
    friend istream &operator>>( istream  &input, User &obj );
};

#endif //ONLINE_LIBRARY_SYSTEM_USER_H
