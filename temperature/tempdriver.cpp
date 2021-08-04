// sample.cpp -- sample test program starter for Temperature class
/////////////////////////////////////////////////////////

#include <iostream>
#include "temperature.h"

using namespace std;

int main()
{
   Temperature t1;		// should default to 0 Celsius
   Temperature t2(34.5, 'F');  // should init to 34.5 Fahrenheit 

   // display dates to the screen
   cout << "\nTemperature t1 is: ";
   t1.Show();			
   cout << "\nTemperature t2 is: ";
   t2.Show();

   t1.Input();			// Allow user to enter a temperature for t1
   cout << "\nTemperature t1 is: ";
   t1.Show();			
   
   t1.SetFormat('L');		// change format of t1 to "Long" format
   cout << "\nTemperature t1 is: ";
   t1.Show();	

   t1.SetFormat('P');		// change format of t1 to "Long" format
   cout << "\nTemperature t1 is: ";
   t1.Show();	

   t1.Convert('C');
   cout << "\nTemperature t1 is: ";
   t1.Show();	

   t1.Set(0, 'K');
   t2.Set(0, 'K');

    if (t1.Compare(t2) == 0)
        cout << "\nTemps are equal";
    else if (t1.Compare(t2) == 1)
        cout << "\nT1 is hotter";
    else if (t1.Compare(t2) == -1)
        cout << "\nT2 is hotter";

    t1.Set(20, 'K');
    t2.Set(0, 'K');

    if (t1.Compare(t2) == 0)
        cout << "\nTemps are equal";
    else if (t1.Compare(t2) == 1)
        cout << "\nT1 is hotter";
    else if (t1.Compare(t2) == -1)
        cout << "\nT2 is hotter";

    t1.Set(0, 'K');
    t2.Set(30, 'K');

    if (t1.Compare(t2) == 0)
        cout << "\nTemps are equal";
    else if (t1.Compare(t2) == 1)
        cout << "\nT1 is hotter";
    else if (t1.Compare(t2) == -1)
        cout << "\nT2 is hotter";

    t2.Set(-273.15, 'C');
    cout << "\nTemperature t2 is: ";
    t2.Show();

    t2.Convert('K');
    cout << "\nTemperature t2 is: ";
    t2.Show();

    t2.Increment(3, 'K');
    cout << "\nTemperature t2 is: ";
    t2.Show();        

}