//-----Allyson Davis-----
//-----section 2-----

//-----BOOK.CPP-----

#include "book.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

/*char title[31];	// may assume title is 30 characters or less
  char author[21];	// may assume author name is 20 characters or less
  Genre type;
  double price;*/

Book::Book()
// default constructor, sets up blank book object
{
    *title = '\0';
    *author = '\0';
    price = 0.00;

}//end Book constructor	

void Book::Set(const char* t, const char* a, Genre g, double p)
  // the Set function should allow incoming data to be received through
  //  parameters and loaded into the member data of the object.  (i.e.
  //  this function "sets" the state of the object to the data passed in).
  //  The parameters t, a, g, and p represent the title, author, genre, 
  //  and price of the book, respectively.
{
    strcpy(title, t);
    strcpy(author, a);
    type = g;
    price = p;

}//end Set

const char* Book::GetTitle() const
// returns the title stored in the object
{
    const char * t;
    t = title;

    return title;
}//end GetTitle

const char* Book::GetAuthor() const
// returns the author
{
    const char * a;
    a = author;
    
    return author;
}//end GetAuthor

double Book::GetPrice() const
// returns the price
{
    return price;
}//end GetPrice

Genre Book::GetGenre() const
// returns the genre
{
    return type;
}//end GetGenre

void Book::Display() const
// described below
{
    cout << title << '\t' << author << '\t';

    if(type == FICTION)
        cout << "Fiction";
    if(type == MYSTERY)
        cout << "Mystery";
    if(type == SCIFI)
        cout << "SciFi";
    if(type == COMPUTER)
        cout << "Computer";

    cout << fixed << setprecision(2) << "$ " << price << endl;
}//end Display

/* Display() function

The member function Display() should print out a Book object on one line 
as follows, in an organized manner. (Monetary output should be in dollars
and cents notation, to two decimal places):
Title		              Author		  Genre		Price

Examples:
Programming for Dummies       Marvin Dipwart      Computer   $  24.95
Mutant Space Weasels          Bob Myers           Sci-Fi     $   5.95

*/ 