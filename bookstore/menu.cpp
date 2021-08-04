//-----Allyson Davis-----
//-----section 2-----

//-----MENU.CPP-----

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include "book.h"
#include "store.h"

using namespace std;

void Menu();
char GetAChar(const char*);
bool Legal (char c);
char GetCommand();
void Add(Store);
void Find(Store);
void Sell(Store);
void Display(Store);
void GenreSummary(Store);

int main() {

    Store s;
    double cash;

    cout << "*** Welcome to the Bookstore Inventory Manager ***\n";
    cout << "Please input the starting money in the cash register: ";
    cin >> cash;

    while (cash < 0) {
        cout << "Must enter a positive price.  Please re-enter: ";
        cin >> cash;
    }

    s.SetMoney(cash);
    Menu();
    char command;

    do {
        command = GetCommand();

        switch (command) 
        {
            case 'A':
                Add(s);
                break;
            case 'F':
                Find(s);
                break;
            case 'S':
                Sell(s);
                break;
            case 'D':
                Display(s);
                break;
            case 'G':
                GenreSummary(s);
                break;
            case 'M':
                Menu();
                break;
            case 'X':
                break;

        }//end switch

    } while (command != 'X');
       
    cout << "\nFinal Cash in Register: " << s.GetMoney() << endl;
    cout << "Goodbye!\n" << endl;

    return 0;
}//end main

void Menu () 
{
    cout << "\n\t\t*** BOOKSTORE MENU ***\n";
    cout << "\tA:\tAdd a book to inventory" << endl;
    cout << "\tF:\tFind a book from innventory" << endl;
    cout << "\tS:\tSell a book" << endl;
    cout << "\tD:\tDisplay the inventory list" << endl;
    cout << "\tG:\tGenre summary" << endl;
    cout << "\tM:\tShow this Menu" << endl;
    cout << "\tX:\teXit the program" << endl; 
}//end menu

char GetAChar(const char* promptString)
// Prompt the user and get a single character,
// discarding the Return character.
// Used in GetCommand.
{
   char response;			// the char to be returned

   cout << promptString;		// Prompt the user
   cin >> response;			// Get a char,
   response = toupper(response);	// and convert it to uppercase
   cin.get();				// Discard newline char from input.

   return response;
}

bool Legal(char c)
// Determine if a particular character, c, corresponds
// to a legal menu command.  Returns true if legal, false if not.
// Used in GetCommand.
{
	return	((c == 'A') || (c == 'F') || (c == 'S') || (c == 'D') ||
			 (c == 'G') || (c == 'M') || (c == 'X'));
}//end legal

char GetCommand()
// Prompts the user for a menu command until a legal 
// command character is entered.  Return the command character.
// Calls GetAChar, Legal, ShowMenu.
{
   char cmd = GetAChar("\n\n>");	// Get a command character.
	
   while (!Legal(cmd))		// As long as it's not a legal command,
   {				// display menu and try again.
	cout << "\nIllegal command, please try again . . .";
	Menu();
	cmd = GetAChar("\n\n>");
   }
   return cmd;
}//end get commmand

void Add (Store s)
//add book to inventory list
//info sent to store object and stored in list of books
{
    char t[31];	
    char a[21];	
    Genre g;
    double p;
    char x, y;

    cout << "Enter Title: ";
    cin.ignore();
    cin.getline(t, 30);

    cout << "Enter Author: ";
    cin.getline(a, 20);

    cout << "Enter Genre - (F)ICTION, (M)YSTERY, (S)CIFI, or (C)OMPUTER): ";
    
    do {
        cin >> x;
    
        y = (toupper(x));

        if(y == 'F') {
            g = FICTION;
        }
        else if (y == 'M'){
            g = MYSTERY;
        }
        else if (y == 'S') {
            g = SCIFI;
        }
        else if (y == 'C') {
            g = COMPUTER;
        }
        else {
            cout << "Invalid genre entry. Try Again\n";
        }
    } while (y != 'M' && y != 'F' && y != 'S' && y != 'C');
    
    do {
        cout << "Enter Price: ";
        cin.ignore();
        cin >> p;

        if (p < 0)
            cout << "Must enter a positive price. Please re-enter";
    }while (p < 0);

    s.AddBook(t, a, g, p);

}//end add

void Find(Store s) 
//search in inventory list by title or author
{
    char search[31];

    cout <<  "Enter search string (title or author): ";
    cin.getline(search, 30);

    s.FindBook(search);

}//end find

void Sell(Store s)
//allow for a sale to be made
{
    char search[31];

    cout << "Enter title to sell: ";
    cin.getline(search, 30);

    s.SellBook(search);

}//end sell

void Display(Store s)
//display entire inventory list
//display number of books in inventory
//display current amount of moey in register
{
    s.DisplayInventory();
}//end display

void GenreSummary(Store s)
{
    char x, y;
    Genre g;

    cout << "Enter Genre ([F]ICTION, [M]YSTERY, [S]CIFI, [C]OMPUTER): ";
    
    do {
        cin >> x;
        y = (toupper(x));

        if(y == 'F') {
            g = FICTION;
        }
        else if (y == 'M'){
            g = MYSTERY;
        }
        else if (y == 'S') {
            g = SCIFI;
        }
        else if (y == 'C') {
            g = COMPUTER;
        }
        else {
            cout << "Invalid genre entry. Try Again\n";
        }
    } while (y != 'M' && y != 'F' && y != 'S' && y != 'C');

    s.FindGenre(g);
}//end GenreSummary

