//-----ALLYSON DAVIS-----
//-----SECTION 2-----

#include <iostream>
#include <cstring>
using namespace std;

class MyInt
{
   // these overload starters are declared as friend functions

   friend MyInt operator+ (const MyInt& x, const MyInt& y);
   friend MyInt operator* (const MyInt&, const MyInt&);
   // add in multiplication, as well

   friend bool operator< (const MyInt& x, const MyInt& y);
   friend bool operator> (const MyInt& x, const MyInt& y);
   friend bool operator<= (const MyInt& x, const MyInt& y);
   friend bool operator>= (const MyInt& x, const MyInt& y);
   friend bool operator== (const MyInt& x, const MyInt& y);
   friend bool operator!= (const MyInt& x, const MyInt& y);

   // declare overloads for input and output (MUST be non-member functions)
   friend ostream& operator<< (ostream& os, const MyInt& x);
   friend istream& operator>> (istream& in, MyInt& x);


public:
   MyInt(int n = 0);		// first constructor
   MyInt(const char* str);    //second constructor

   ~MyInt();      //destructor
   MyInt(const MyInt& x);  //copy-constructor
   MyInt& operator= (const MyInt& x);  //assignment operator

   MyInt& operator++();
   MyInt operator++ (int);

   MyInt& operator--();
   MyInt operator--(int);


private:
   // member data (suggested:  use a dynamic array to store the digits)
   int size;
   unsigned int max;
   int * value;

   int C2I(char c);
   char I2C(int x);

   void Simplify();
   void Grow();

};