//------TEMPERATURE.CPP------
//----Allyson Davis----
//-----section 2-----

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include "temperature.h"

using namespace std;

//Celsius = (Fahrenheit - 32) X (5/9)
//(or) Fahrenheit = (Celsius X 9/5) + 32
//Celsius = Kelvin - 273.15
//double degree;  //not below O K
//char scale;     //F, C, or K & lowercase

    Temperature::Temperature(double deg, char s)
    //0 K is lowest possible temp
    //-273.15 C & -459.67 F
    {
        s = toupper(s);
        format = 'D';

        if(!Set(deg, s)){
            Set(0, 'C');
        }
        else {
            Set(deg, s);
        }

    }//end Temperature constructor

    void Temperature::Input()
    //prompt user to enter temp 
    //if invalid, display error messgage and make them re-enter
    {
        double deg;
        char sc;
        cout << "\nEnter Temperature: ";
        cin >> deg >> sc;
        
        while (!Set(deg, sc)){
            cout << "\nInvalid temperature. Try again: ";
            cin >> deg >> sc; 
        }

        Set(deg, sc);

    }//end INPUT

    void Temperature::Show() const
    //Default: D S
    //Precison -1: D.d S
    //Long: D Scale
    {
        switch (format)
        {
        case 'P':
            cout << fixed << showpoint;
            cout << setprecision(1);

            cout << degree << ' ' << scale;
            break;

        case 'L':
            cout << degree << ' ';
            if(scale == 'C')
                cout << "Celcius";
            else if (scale == 'F')
                cout << "Fahrenheit";
            else if (scale == 'K')
                cout << "Kelvin";
            break;

        default:
            cout << degree << ' ' << scale;
            break;
        }

    }//end SHOW

    bool Temperature::Set(double deg, char s)
    //set temp to param values
    {
        switch(toupper(s)) {
            case 'K':
                if(deg < 0)
                    return false;
                break;
            case 'F':
                if(deg < -459.67)
                    return false;
                break;
            case 'C':
                if(deg <-273.15)
                    return false;
                break;
            default:
                return false;
        }//end switch

        degree = deg;
        scale = toupper(s);
        return true;

    }//end SET

    double Temperature::GetDegrees() const
    {   
        return degree;
    }//end GetDegree

    char Temperature::GetScale() const
    {
        return scale;
    }//end GetScale

    bool Temperature::SetFormat(char f)
    //allows caller to change format setting
    //if invalid code is passed in, do NOT alter format
    // D = default, P = precision-1, L = long
    {
        char form = toupper(f);
        if(form == 'D' || form == 'P' || form == 'L') {
            format = form;
            return true;
        }

        return false;

    }//end SetFormat

    bool Temperature::Convert(char sc)
    //convert current temperature to new scale (sc)
    //if invalid, abort and change nothing
    {
        switch(toupper(sc)) {
            case 'K':
                if (scale == 'C')
                    degree = degree + 273.15;
                else if (scale == 'F')
                    degree = ((degree - 32) * (5/9)) + 273.15;
                break;

            case 'F':
                if (scale == 'C')
                    degree = (degree * (9/5)) + 32;
                else if (scale == 'K')
                    degree = (degree - 273.15) * (9/5) + 32;
                break;

            case 'C':
                if (scale == 'F')
                    degree = (degree - 32) * (5/9);
                else if (scale == 'K')
                    degree = degree - 273.15;
                break;

            default:
                return false;
        }//end switch

        scale = toupper(sc);
        return true;

    }//end Convert

    int Temperature::Compare (const Temperature& d) const
    //compares temp objects
    //return -1 if calling object is the lower temp
    //return 0 if the objects are the same temp
    //return 1 if param object is lower
    {
        if(DegKelvin() < d.DegKelvin())
            return -1;
        else if (DegKelvin() == d.DegKelvin())
            return 0;
        else if (DegKelvin() > d.DegKelvin())
            return 1;

    }//end Compare

    //-----EXTRA FUNCTIONS-----
    double Temperature::DegKelvin() const 
    //convert temp to Kelvin for compare function
    {
        double degK = degree;

        if(scale == 'F')
            degK = ((degree - 32) * (5/9)) + 273.15;
        else if (scale == 'C')
            degK = degree + 273.15;

        return degK;
    }//end DegKelvin

    //-----EXTRA CREDIT FUNCT-----
    void Temperature::Increment(int deg, char sc) 
    //moves temp forward by the num degrees in the scale given
    //remaining result should remain in the original scale 
    {
        char origScale = scale;

        if (Convert('K') > 0) {
            Convert(sc);
            Set(degree + deg, sc);
            Convert(origScale);
        }//end if
    }//end Increment