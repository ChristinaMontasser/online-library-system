//
// Created by EGYPT on 22/11/2020.
//

#include<cstring>
#include<iostream>
#include "user.h"
#include <cstdlib>
using namespace std;

//Default constructor
User::User()
{
    name ="";
    age =0;
    id = 0;
    password="";
    email="";
}

//Parameterized constructor
User::User(string name, int age, string email, string password, int id)
{

    //Using this to avoid missing up between the parameter and member variables names
    this->name = name;
    setAge(age);
    this->email = email;
    this->password= password;
    id= 0;

}
//Copy constructor
User::User(const User &obj)
{
    this->name=obj.name;
    age=obj.age;
    email=obj.email;
    password=obj.password;
    id=obj.id;
}


//This function checks if two parameters are equal or not
// It's called by an object from the class, and the another comparative with is sent as a parameter
// it's sent by reference for saving storage...
bool User::operator==(const User &obj)
{
    return name == obj.name && email == obj.email &&  age == obj.age;
}


//Through these kind of functions we can set and get values of private member variables...
void User::setName(string name)
{
    this ->name=name;
}

string User::getName() const
{
    return name;
}

void User::setPassword(string password)
{
    this ->password=password;
}

string User:: getPassword()
{
    return password;
}

void User ::setEmail(string email)
{
    this ->email=email;
}

string User:: getEmail()
{
    return email;
}

void User::setAge(int age)
{

    this->age= age;
}

int User ::getAge()
{
    return age;
}

void User::setId(int id)
{
    this->id=id;
}

int User::getId()
{
    return id;
}

/*User &User::operator =(const User &obj){
    this->name=obj.name;
    age=obj.age;
    email=obj.email;
    password=obj.password;
    id=obj.id;
    return *this;
}*/
//To use output for objects
ostream &operator<<(ostream &output, const User &obj )//cout stream
{
    output << "========User " << obj.id << " info=======" << endl
    << "Name: " << obj.name << endl << "Age: " << obj.age <<endl<<
           "Id: " << obj.id << endl << "Email:" << obj.email << endl<<
           "=========================================="<<endl;
    return output;
}

//To use input for objects
istream &operator>>( istream  &input, User &obj )
{
    input
    >>obj.name>>
    obj.age>>
    obj.email>>
    obj.password;
    cout << endl;
    return input;
}
