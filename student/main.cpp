#include <iomanip>
#include <iostream>
#include "studentlist.h"

using namespace std;

void Menu();
void Import(StudentList& s);
void Export(StudentList& s);
void ShowList(StudentList& s);
char GetAChar(const char*);
bool Legal(char);
char GetCommand();
void Sort(StudentList& s);


int main () {
    StudentList s1;
    char command;

    Menu();

    do {
        command = GetCommand();

        switch (command) {
            case 'I':
                Import(s1);
                break;
            case 'S':
                ShowList(s1);
                break;
            case 'E':
                Export(s1);
                break;
            case 'M':
                Menu();
                break;
            case 'O':
                Sort(s1);
                break;
            case 'Q':
                break;
        }//end switch;

    } while (command != 'Q');

    cout << "Goodbye!" << endl;

    return 0;
}//end main

void Menu() 
{
    cout << "\t\t*** Student List menu ***\n";
    cout << "I\tImport students from a file\n";
    cout << "S\tShow student list (brief)\n";
    cout << "E\tExport a grade report (to file)\n";
    cout << "M\tShow this Menu\n";
    cout << "O\tsOrt student list\n";
    cout << "Q\tQuit Program" << endl;

}//end menu

void Import(StudentList& s)
{
    char * filename;
    cout << "Enter filename: ";
    cin >> filename;

    if (!(s.ImportFile(filename))) {
        cout << "Invalid file. No data Imported." << endl;
    }
    else {
        s.ImportFile(filename);
    }
    

}//end import

void Export(StudentList& s)
{
    char * filename;
    cout << "Enter filename: ";
    cin >> filename;

    if (!(s.CreateReportFile(filename))) {
        cout << "Cannot open file. No data exported.." << endl;
    }
    else {
        s.CreateReportFile(filename);
    }
}//end export

void ShowList(StudentList& s)
{
    s.ShowList();
}//end showlist

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
	return	((c == 'I') || (c == 'S') || (c == 'E') || (c == 'M') ||
			 (c == 'Q') || (c == 'O'));
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

void Sort(StudentList& s)
//sprt student list alphabetically by last name 
//iflname the same, sort by fname
{
    s.SortList();
}//end sort