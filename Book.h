//
// Created by EGYPT on 22/11/2020.
//

#ifndef ONLINE_LIBRARY_SYSTEM_BOOKS_H
#define ONLINE_LIBRARY_SYSTEM_BOOKS_H

#include<cstring>
#include<iostream>
#include "user.h"

using namespace std;

class Book {
private:
    string title;
    string isbn;
    int id;
    string category;
    double averageRating;

    // this variable should contain the average rating for the book, rateBook function
    // should update this attribute with the new average rating for the book
    User author;
public:
    bool authorcheck =false;
    static int Count;
    Book();
    Book(int BookListCount);
    Book(string title, string isbn, string category);
    Book(const Book& obj);
    void setTitle(string title);
    string getTitle();
    void setISBN(string isbn);
    string getISBN();
    void setId(int id);
    int getId();
    void setCategory(string category);
    string getCategory();
    void setAuthor(const User& user);
    User getAuthor();
    double getrate();
    // this function should update averageRating attribute as a new rating is
    // introduced to the book so the average rating should be affected.
    // Check the main screenshot to know more information
    void rateBook(int rating);
    bool operator==(const Book& book);
    friend ostream &operator<<(ostream &output, const Book &book );
    friend istream &operator>>( istream  &input, Book &book );
};
#endif //ONLINE_LIBRARY_SYSTEM_BOOKS_H
