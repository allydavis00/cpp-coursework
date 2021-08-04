//-----Allyson Davis-----
//-----section 2-----

//-----STORE.H-----

#ifndef _STORE_H
#define _STORE_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "book.h"

using namespace std;

class Store
{

    public:
        Store();        //default constructor
        ~Store();       //final cleanup of dynamic space
        
        void SetMoney(double);
        double GetMoney();  

        void DisplayInventory();
        void AddBook(const char* t, const char* a, Genre g, double p);
        void SellBook(const char* t);

        // int FindAuthor(const char* a);
        void FindGenre(Genre g);
        void FindBook(const char* x);


    private:
        double cashReg;
        int size;
        int max;
        Book * books;
        
        void Grow();
        void Shrink();

        int FindTitle(const char* t) const;

};

#endif