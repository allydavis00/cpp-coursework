//-----ALLYSON DAVIS-----
//-----SECTION 2-----

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <string>
#include "myint.h"

using namespace std;

//-----------------operator overloads------------------
ostream& operator<< (ostream& os, const MyInt& x)
{
   for (int i = 0; i < x.size; i++){
      os << x.value[i];
   }
   return os;
}//end output

istream& operator>> (istream& in,  MyInt& x)
{
   delete [] x.value;   //delete any previous data stored in object
   x.size = 0;
   x.max = 5;

   x.value = new int[x.max];	

   char c = ' ';
   int count = 0;

   //loop
   while(isspace(c)){
      c = in.peek();
      in.ignore();
   }
   in.ignore();
   while(isdigit(c)) {
      if (x.size == x.max)		// If the directory is full, grow it.
            x.Grow();

      c = in.get();

      x.value[count] = (c - '0');
      //increase counter
      count++;
   }
   return in;

}//end input

MyInt operator+ (const MyInt& x, const MyInt& y)
{
   MyInt result;
   //which is larger in size
   if (x < y) {
      result.size = y.size + 1;
      result.max = result.size + 5;
      delete [] result.value;
      result.value = new int[result.max];

      for(int i = y.size; i > 0; i ++){
         for (int j = x.size; j > 0; j++) {
            result.value[i] = y.value[i] + x.value[j];
         }
      }
   }//if x < y
   else {
      result.size = x.size + 1;
      result.max = result.size + 5;
      delete [] result.value;
      result.value = new int[result.max];

      for(int i = x.size; i > 0; i ++){
         for (int j = y.size; j > 0; j++) {
            result.value[i] = x.value[i] + y.value[j];
         }
      }
   }//end else

   result.Simplify();

   return result;
}//end +

MyInt operator* (const MyInt& x, const MyInt& y)
{
   MyInt result;
   if (x < y) {
      result.size = y.size + 1;
      result.max = result.size + 5;
      delete [] result.value;
      result.value = new int[result.max];

      for(int i = y.size; i > 0; i ++){
         for (int j = x.size; j > 0; j++) {
            result.value[i] = y.value[i] * x.value[j];
         }
      }
   }//if x < y
   else {
      result.size = x.size + 1;
      result.max = result.size + 5;
      delete [] result.value;
      result.value = new int[result.max];

      for(int i = x.size; i > 0; i ++){
         for (int j = y.size; j > 0; j++) {
            result.value[i] = x.value[i] * y.value[j];
         }
      }
   }//end else

   result.Simplify();

   return result;
}//end *

bool operator< (const MyInt& x, const MyInt& y)
{
   if (x.size == y.size){
      for (int i = 0; i < x.size; i++){
         if (x.value[i] < y.value[i])
            return true;
         else if (x.value[i] > y.value[i])
            return false;
      }
   }//end if size
   else if (x.size < y.size)
      return true;
   else
      return false;
}//end <

bool operator> (const MyInt& x, const MyInt& y){
   if (!(x < y))
      return true;
   else
      return false;
}//end >

bool operator<= (const MyInt& x, const MyInt& y)
{
   if(x < y || x == y)
      return true;
   else 
      return false;
}//end <=

bool operator>= (const MyInt& x, const MyInt& y)
{
   if(x > y || x == y)
      return true;
   else 
      return false;
}//end >=

bool operator== (const MyInt& x, const MyInt& y)
{
   if(x.size != y.size)
      return false;
   else {
      for (int i = 0; i < x.size; i++) {
         if (x.value[i] != y.value[i])
            return false;
      }//end for

      return true;
   }
}//end ==

bool operator!= (const MyInt& x, const MyInt& y)
{
   if (x == y)
      return false;
   else
      return true;
}//end !=

//-----------------constructors------------------
MyInt::MyInt(int n)
//if negative param is passed -> set object to represent 0
//otherwise, set object to represent value in param
{
   if (n > 0){
      int s = 0;
      unsigned int temp = n;

      while (temp > 10) {  //to get size of value
         temp = temp / 10;
         s++;
      }//end while

      size = s;
      max = size + 5;

      value = new int[max];


      for(int i = size-1; i >= 0; i--){   //convert int to array of digits
         value [i] = n % 10;
         n = n / 10;
      }//end for loop

   }//end if
   else {
      size = 1;
      max = 6;
      value = new int[max];
      
      value[0] = 0;
   }//end else
}//end default constructor

MyInt::MyInt(const char* str)
//if string is empty or contains chars other than digits 0-9 -> set object to 0
//otherwise set object to param
{
   //if its good
   int s = strlen(str);

   char * temp;
   temp = new char [s+5];
   strcpy(temp, str);

   bool bad = false;

   if (temp == 0)
      bad = true;

   for(int i = 0; i < s; i++){
      if (temp[i] < '0' || temp[i] > '9') {
         bad = true;
      }
   }

   if (!bad) {
      size = s;
      max = size + 5;

      value = new int[max];

      for (int i = 0; i < size; i++)
         value[i] = C2I(temp[i]);

   }//end if
   else {
      size = 1;
      max = 6;
      value = new int[max];
      
      value[0] = 0;
   }//end else

   delete [] temp;

}//end constructor w/ c-string param

//-----------------automatics------------------
MyInt::~MyInt()
//destuctor
{
   delete [] value;
}//end destructor

MyInt::MyInt(const MyInt& x)
//copy construstor
{
   size = x.size;
   max = x.max;

   value = new int[max];

   for (int i = 0; i < size; i++)
      value[i] = x.value[i];

}//end copy constructor

MyInt& MyInt::operator= (const MyInt& x)
//assignment operator
{
   if (this != &x)		//only make copy if original is not this object
   {			

      //delete the existing array
      delete [] value;

      //copy
      max = x.max;
      size = x.size;
      value = new int[max];
      for (int i = 0; i < size; i++)
	      value[i] = x.value[i];
   }//end if

   return *this;		// return this object

}//end assignment operator

//-----------------increment/decrements------------------
MyInt& MyInt::operator++()
//pre-increment
{
   value[size - 1] += 1;

   //simplify
   this->Simplify();

   return *this;
}//end ++

MyInt MyInt::operator++ (int)
//post increment
{
   MyInt temp = *this;

   //increment
   value[size - 1] += 1;

   //simplify
   this->Simplify();

   return temp;
}//end ++

MyInt& MyInt::operator--()
//pre-decrement
{
    value[size - 1] -= 1;

   //simplify
   this->Simplify();

   return *this;
}//end --

MyInt MyInt::operator--(int)
//post decrement
{
   MyInt temp = *this;

   //decrement
   value[size - 1] -= 1;

   //simplify
   this->Simplify();

   return temp;
}//end --

//-----------------private------------------

int MyInt::C2I(char c)
//from Bob Meyers note set
// converts character into integer (returns -1 for error)
{
   if (c < '0' || c > '9')	
      return -1;	// error

   return (c - '0');				// success
}//end C2I

char MyInt::I2C(int x)
//from Bob Meyers note set
// converts single digit integer into character (returns '\0' for error)
{
   if (x < 0 || x > 9)		
      return '\0';	// error

   return (static_cast<char>(x) + '0'); 	// success
}//end I2C

void MyInt::Simplify()
{
   for (int i = size - 1; i > 0; i--) {
      while (value[i] > 9){
         value[i] = value[i] % 10;
         value[i-1]++;
      }
      if (value[i] < 0) {
         value[i] = 9;
         value [i-1]--;
      }
   }//end for
}//end simplify

void MyInt::Grow()
{
   max = size + 5;
   int* newValue = new int [max];		// Allocate a new array.
	
   for (int i = 0; i < size; i++)	// Copy each entry into
	   newValue[i] = value[i];		// the new array.
		
   delete [] value;			// Remove the old array
   value = newValue;			// Point old name to new array.

}//end grow
