//-----Allyson Davis-----
//-----section 2-----

//-----STORE.CPP-----

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "store.h"

using namespace std;

/*member variables
  double cashReg;
  int size;
  int max;
  Book * books;*/

Store::Store()
//defaul store
//set to empty store
{
    cashReg = 0.00;
    size = 0;
    max = 5;
    books = new Book[max];
}//end Store

Store::~Store()
//clean up
{
    delete [] books;
}//end ~Store

void Store::SetMoney(double m)
//set amount of money in register
//if param is negative, set to 0.00
{
    cashReg = m;
}//end SetMoney

double Store::GetMoney()
//get amount of money in register
{
    return cashReg;
}//end GetMoney

void Store::DisplayInventory()
//each line should contain one books info
//display num of books in inventory list
//display current amt of money in register
//if there are no books display "No books" message
{
    if (size == 0)
        cout << "Book inventory is empty\n";
    else {
        cout << "**Title**\t" << "**Author**\t" << "**Genre**\t" << "**Price**" <<endl;
        for (int i = 0; i < size; i++) {
            books[i].Display();
        }
    }

    cout << "\nNumber of books = " << size << endl;
    cout << "Money in register = $ " << fixed << setprecision(2) << cashReg << endl;

}//end ShowInventory

void Store::AddBook(const char* t, const char* a, Genre g, double p)
//add a book to store's inventory
{
    books[size++].Set(t, a, g, p);

        if (size == max)        //if list is full, grow
        Grow();

}//end AddBook

void Store::SellBook(const char* t)
{
    int x = FindTitle(t);

    if (x == -1){
        cout << '\n' << t << " not found in the inventory\n";
        cout << "* No sale made *\n";
    }
    else {

        for (int i = 0; i < size; i++){
            books[i - 1] = books[i];
        }//end for

        Shrink();
        cout << "\nSale Complete!\n";
    }//end else

}//end SellBook

void Store::FindGenre(Genre g)
{
    int count = 0;
    double total = 0.00;

    for (int i = 0; i < size; i++){
        if(g == books[i].GetGenre()) {
            books[i].Display();
            total = total + books[i].GetPrice();
            count++;
        }//end if
    }//end for loop

    cout << fixed;
    cout << setprecision(2);

    cout << "\nTotal books in this genre " << g << " = " << count << endl;
    cout << "Total price of books in this genre = " << total << endl;

}//end FindGenre

void Store::FindBook(const char* b)
{
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(books[i].GetTitle(), b) == 0) {
            cout << "\nBook found.\n";
            books[i].Display();
            count++;
        }
        if (strcmp(books[i].GetAuthor(), b) == 0) {
            books[i].Display();
            count++;
        }
    }//end for loop

    if (count == 0)
        cout << b << ": Not found." << endl;

}//end FindBook


//private functions
void Store::Grow()
{
    max = size + 5;     //determine new size
    Book * newBooks = new Book[max];    //new array

    for(int i = 0; i< size; i++) {
        newBooks[i] = books[i];
    }

    delete [] books;     //remove old array
    books = newBooks;   //point old name to new array

}//end grow

void Store::Shrink()
{
    size--;
    max = size + 5;

    Book * newBooks = new Book[max];

    for(int i = 0; i < size; i++) {
        newBooks[i] = books[i];
    }

    delete [] books;
    books = newBooks;

}//end Shrink

int Store::FindTitle(const char* t) const
//compare each title with param t (for loop)
{
    for (int i = 0; i < size; i++){
        if(strcmp(books[i].GetTitle(), t) == 0)
        return i;
    }//end for loop

    return -1;

}//end FindTitle