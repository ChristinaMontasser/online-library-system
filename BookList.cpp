#include<iostream>
#include <stdlib.h>
using namespace std;
#include "BookList.h"
#include "Book.h"

 /* Book* books;
          int capacity;
          int booksCount;*/
BookList::BookList(const BookList& anotherList) {
    booksCount = anotherList.booksCount;
    books = new Book[anotherList.booksCount];

    for (int i = 0; i < booksCount; i++) {
        books[i] = anotherList.books[i];
    }
}
//Default Constructor
BookList::BookList(){

    books=new Book[10];
    this->booksCount=0;
};


Book&BookList:: searchBook(string name){
        int index;
        for(int i=0; i<booksCount; i++)
           {
            if(name == books[i].getTitle()){
                index = i;
                //If it's found, break loop and return it...
                break;
            }
    }
     return books[index];
};


Book& BookList::searchBook(int id){
        return books[id-1];
};
void BookList::increamentBooks(){
    this->booksCount++;
}

void BookList::addBook(Book& addedBook){

    this->books[this->getBooksCount()] = addedBook;
    this->booksCount++;
}
void BookList::deleteBook(int id){
    for (int i = id-1 ; i<booksCount; i++)
    {
        books[i] = books[i+1];

    }
    books[0].Count--;
    booksCount = booksCount-1;

};//delete a book


Book BookList::getTheHighestRatedBook(){
    double MR=books[0].getrate(); //Maximum Rate
    int In=0; //Assume Maximum rate is the first element, intial value
    for(int i=1; i<booksCount; i++)
        {
            if (books[i].getrate()> MR){
                MR=books[i].getrate();
                In=i;
            }

        }
return books[In];
};


vector<Book> BookList:: getBooksForUser(int useID){
        vector<Book> books;
        for (int i =0; i<booksCount; i++)
        {
            if (this->books[i].getAuthor().getId()== useID)
            {

                books.push_back(this->books[i]);
            }
         }
         return books;
  };


Book & BookList::operator [ ] (int position){
        return books[position];
};

int BookList:: getBooksCount(){
        return booksCount;
}

ostream &operator <<( ostream &output, BookList &booklist ){
    for (int i=0; i<booklist.booksCount; i++){
        output << booklist.books[i]<<endl;
       /* if(booklist.books[i].authorcheck==true)
            output <<booklist.books[i].author <<endl<<"=========================================="<<endl;*/
    }
return output;
}; //to display all books

istream &operator>>( istream  &input, BookList &booklist )
{
    //input >> obj.title>>obj.isbn>>obj.category;
    cout << endl;
    //return input;
}

BookList::~BookList(){
    delete [] books;
};

