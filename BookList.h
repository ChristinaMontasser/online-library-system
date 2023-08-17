#ifndef BOOKLIST_H_INCLUDED
#define BOOKLIST_H_INCLUDED
#include "Book.h"
#include<iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class BookList{
    private:
        int capacity;
        int booksCount;
    public:
        Book* books;
        BookList(const BookList& anotherList);
        BookList();
        Book& searchBook(string name);
        Book& searchBook(int id);
        void deleteBook(int id); //delete a book
        void addBook(Book& addedBook);
        Book getTheHighestRatedBook();
        vector<Book> getBooksForUser(int useID); // get all books of this author
        Book & operator [ ] (int position);
        int getBooksCount();
        void increamentBooks();
        friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books
        friend istream &operator>>( istream  &input, BookList &booklist );
        ~BookList();
    };


#endif // BOOKLIST_H_INCLUDED
