#include <iostream>
#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"

using namespace std;
UserList userlist;
BookList BL;
void UserPage()
{
          //Loops of appearing the user menu
          while (true){
                int In_2;
                cout << "USERS MENU" << endl << "1- Create a USER and add it to the list" << endl
                << "2- Search for a user" << endl << "3- Display all users" << endl
                << "4- Back to the main menu" << endl;
                cin >> In_2;

                //when Create a USER is chosen
                if(In_2 == 1){
                     User u1;
                     cout<<"Enter the user information in this order "<<endl
                     <<"Name Age Email Password (space separated)"<<endl;
                     cin >> userlist.users[userlist.usersCount];
                     userlist.increamentUsers();
                     }

                 //when Searching is chosen is chosen
                else if(In_2== 2) {
                   //  User u2;
                     int DeleID;
                     int In_3;
                     while(true){
                        cout << "SEARCH FOR A USER"<< endl << "1-Search by name" <<
                        endl << "2-Search by id" <<endl << "3-Return to Users Menu"<<endl;
                        cin >> In_3;

                        if(In_3==1){
                            cout<< "Enter Name"<<endl;
                            string name;
                            cin >> name;
                            cout<< userlist.searchUser(name);
                            DeleID = userlist.searchUser(name).getId();
                            int In_4;
                            cout << "1- Delete user" <<endl << "2- Return to Users Menu" <<endl;
                            cin >> In_4;

                            while(true){
                             if(In_4==1){
                                userlist.deleteUser(DeleID);
                                break;
                             }
                             else if (In_4==2) {
                                break;
                             }
                            }
                        }

                        else if(In_3==2){
                          cout << "Enter Id"<< endl;
                          int inID;
                          cin >> inID;
                          cout << userlist.searchUser(inID);

                          int In_4;
                          cout << "1- Delete user" <<endl << "2- Return to Users Menu" <<endl;
                          cin >> In_4;

                          while(true){
                            if(In_4==1){
                                userlist.deleteUser(inID);
                                break;
                            }
                            else if (In_4==2) {
                               break;
                            }
                          }
                        }




                        else{
                          break;
                        }
                    }

                }

                //when 3 is chosen
                else if(In_2== 3) {

                    cout << userlist;
                }

                else{

                  break;
                }

       }

}


void BookPage()
{
        while (true){
            int In_2;
            cout << "1- Create a book and add it to the list"<<endl<< "2- Search for a book"<< endl<<
            "3- Display al1 books (with book rating)"<< endl << "4- Get the hihest rating book" << endl
            << "5- Get all books of a user" <<endl<< "6- Copy the current Book List to a new Book List and switch to it" <<
            endl << "7- Back to the main menu" << endl;
            cin >> In_2;

            //When Create a book is chosen
            switch (In_2){
                case 1:
                    {
                        cout<<"Enter the user information in this order "<<endl
                        <<"Title ISBN Category (Space separated)"<<endl;
                        cout << BL.getBooksCount();
                        cin >> BL.books[BL.getBooksCount()];
                        BL.increamentBooks();
                        int In_3;
                        cout << "1- Assign author" << endl <<"2- Continue" << endl;
                        cin >> In_3;
                        while (true){
                            switch(In_3)
                            {
                                case 1: {
                                    cout << "Enter ID" << endl;
                                    int In_ID;
                                    cin >> In_ID;
                                    cout <<userlist.searchUser(In_ID);
                                    BL.books[BL.getBooksCount()-1].setAuthor(userlist.searchUser(In_ID));
                                    break;
                                }
                                case 2: {
                                    break;
                                }
                                default:
                                    cout << "Unexpected Input" << endl;
                                    break;
                            }
                            break;
                        }
                    break;
                    }
                    case 2:{
                        cout << "SEARCH FOR A BOOK\n1- Search by name\n2- Search by id\n3- Return to books menu\n";
                        int book2choose;
                        cin >> book2choose;
                        switch(book2choose){
                        case 1:
                            {
                                cout << "Enter Name\n";
                                string namesearch;cin >> namesearch;
                                Book book = BL.searchBook(namesearch);cout << book;
                                cout << "1- Update author\n"
                                        "2- Update name\n"
                                        "3- Update Category\n"
                                        "4- Delete Book\n"
                                        "5- Rate book"
                                        "\n6- Get back to books menu\n";
                                int book3choose;
                                cin >> book3choose;
                                while(true){
                                    switch (book3choose){
                                        case 1:
                                        {
                                            User new_User;
                                            cout << "Enter new Author ID:\n";
                                            book.setAuthor(new_User);
                                            break;
                                        }
                                        case 2:
                                        {
                                            cout << "Enter New Name:\n";
                                            string name;
                                            cin >> name;
                                            book.setTitle(name);
                                            break;
                                        }
                                        case 3:
                                        {
                                            cout << "Enter Category:\n";
                                            string catg;
                                            cin >> catg;
                                            book.setCategory(catg);
                                            break;
                                        }
                                        case 4:
                                        {
                                            cout << "Enter Id:\n";
                                            int id;
                                            cin >> id;
                                            BL.deleteBook(id);
                                            break;
                                        }
                                        case 5:
                                        {
                                            cout << "Enter Rating Value:\n";
                                            int rate;
                                            cin >> rate;
                                            book.rateBook(rate);
                                            break;
                                        }
                                        case 6:
                                        {
                                            break;
                                        }
                                        default:
                                            cout << "Unexpected Input" << endl;
                                            break;
                                    }

                                }
                                break;
                        }
                        case 2:
                            {

                                cout << "Enter Id\n";
                                int id;
                                cin >> id;
                                Book book = BL.searchBook(id);
                                cout << book;
                                break;
                            }
                        case 3:
                        {
                                break;
                        }
                        default:
                                cout << "Unexpected Input" << endl;
                                break;
                }

                    break;
}

                case 3:{
                    cout << BL;
                    break;
                }

                case 4:{
                      cout<<BL.getTheHighestRatedBook();
                      break;
                   }

                case 5:{
                    int UsId;
                    cout << "Enter User ID" <<endl;
                    cin >> UsId;
                    vector<Book> returnedBooks = BL.getBooksForUser(UsId);
                    if (!returnedBooks.empty()) {
                        for (auto iter = returnedBooks.begin(); iter != returnedBooks.end(); iter++) {
                                cout << *iter << endl;
                        }
                    }
                    else{
                            cout << "No books found for the specified user." << endl;
                    }
                    break;
                   }

                case 6:{
                    cout << "Copied current list (" << BL.getBooksCount() << ") to a new List and switched ti it " << endl;
                    BookList Cpbooklist (BL);
                    break;
                   }
                case 7:
                    break;

                default:
                    cout << "Unexpected Input" << endl;
                    break;

            }
            break;
         }

}
int main()
{
    //UserList userlist;
    //Program Choices
    while (true){
        int In_1;
        cout << "Select one of the following choices: "<< endl<<
        "1- Books Menu" <<endl << "2- Users Menu" << endl << "3- Exit" <<endl;
        cin >> In_1;

        switch (In_1) {
            case 1:
            {

                BookPage();
                break;
            }
            case 2:
            {
                UserPage();
                break;
            }
            default:
                cout << "Unexpected Input" << endl;
                break;
        }

    }
    return 0;
}


