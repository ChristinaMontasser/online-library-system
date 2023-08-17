//
// Created by EGYPT on 22/11/2020.
//

#include "Book.h"
#include<iostream>
#include <stdlib.h>
using namespace std;
/*/string title;
    string isbn;
    int id;
    string category;
    double averageRating;
    User author;
*/
int Book::Count = 0;
//Default constructor
Book :: Book(int BookListCount)
{
    Count++;
    isbn="";
    id=Count;
    category="";
    averageRating=0.0;
}

Book :: Book()
{
    Count++;
    isbn="";
    id=Count;
    category="";
    averageRating=0.0;
}
//Parameterized constructor
Book::Book(string title, string isbn, string category)
{
    Count++;
    this->title=title;
    this->isbn=isbn;
    this->category=category;
    id=Count;

}
//Copy constructor
Book::Book(const Book &obj)
{
    title=obj.title;
    isbn=obj.isbn;
    category=obj.category;
    author=obj.author;
    id = obj.id;
    authorcheck = obj.authorcheck;
}

//Through these kind of functions we can set and get values of private member variables...
void Book::setTitle(string title)
{
    this ->title=title;
}

string Book::getTitle()
{
    return title;
}

void Book::setISBN(string isbn)
{
    this ->isbn=isbn;
}

string Book:: getISBN()
{
    return isbn;
}
void Book::setId(int id)
{
    this ->id=id;
}
int Book:: getId()
{
     return id;
}

void Book ::setCategory(string category)
{
    this ->category=std::move(category);
}
string Book::getCategory()
{
    return category;
}
void Book:: setAuthor(const User& user)
{
    this->author=user;
    this->authorcheck = true;
}
User Book::getAuthor()
{
return author;
}
double Book:: getrate()
{
    return averageRating;
}

//The average of rating
    void Book::rateBook(int rrating)
    {
    averageRating+=((double)rrating/2);
    }

//This function checks if two parameters are equal or not
// It's called by an object from the class, and the another comparative with is sent as a parameter
// it's sent by reference for saving storage...
    bool Book:: operator==(const Book& obj)
    {
        return title == obj.title && isbn == obj.isbn && id == obj.id && category == obj.category &&
               author == obj.author;
    }

    ostream &operator<<(ostream &output, const Book &obj )
    {
        output << "========book " << obj.id << " info=======" << endl;
        output << "Title: " << obj.title << endl << "ISPN: " << obj.isbn << endl<<
               "Id: " << obj.id << endl << "Category Rating:cat" << obj.category << endl
                << "Avg rating:"<< obj.averageRating<<endl;

                    output <<obj.author <<endl<<"=========================================="<<endl;

        return output;
    }

    istream &operator>>( istream  &input, Book &obj )
    {
        input >> obj.title>>obj.isbn>>obj.category;
        cout << endl;
        return input;
    }
