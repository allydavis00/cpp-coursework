//-------TIME.H------
//----Allyson Davis----
//-----section 2-----

#include "time.h"

using namespace std;

//-----friend functions-----
ostream& operator<< (ostream& os, const Time& t)
//overload of insertion operator
//days~hh:mm:ss
//output of time objects
{
    os << t.days << "~" << t.hours << ":" << t.minutes << ":" << t.seconds;

    return os;
}//end << operator

istream& operator>> (istream& is, Time& t)
//overload of extraction operator
//days~hh:mm:ss
//input of time objects
{
    char symbol, colon1, colon2;    //for ~ : :

    is >> t.days >> symbol >> t.hours >> colon1 >> t.minutes >> colon2 >> t.seconds;

    if (t.days < 0 || t.hours < 0 || t.minutes < 0 || t.seconds < 0) {
        t.days = 0;
        t.hours = 0;
        t.minutes = 0;
        t.seconds = 0;
    }
    else
        t.Simplify();

    return is;

}//end >> operator


Time operator- (const Time& t1, const Time& t2)
//subtraction of time objects
//return in simplest form
{
    //if first Time < second Time default to 0
    if(t1 < t2) {
        Time r;
        return r;
    }//end if
    else {
        int d, hr, min, sec;

        d = t1.days - t2.days;
        hr = t1.hours - t2.hours;
        min = t1.minutes - t2.minutes;
        sec = t1.seconds - t2.seconds;

        if (d >= 0) {
            if (hr < 0) {
                hr = 23;
                d--;
            }
            if (min < 0) {
                min = 59;
                hr--;
            }
            if (sec < 0) {
                sec = 59;
                min--;
            }
        }//end d>=0

        Time r(d, hr, min, sec);     //result
        return r;

    }//end else

}//end -

Time operator+ (const Time& t1, const Time& t2)
//addition of time objects
//return in simplest form
{
    Time r;     //result

    r.days = t1.days + t2.days;
    r.hours = t1.hours + t2.hours;
    r.minutes = t1.minutes + t2.minutes;
    r.seconds = t1.seconds + t2.seconds;

    //if values are too high, simplify
    r.Simplify();

    return r;
}//end +

Time operator* (const Time& t, int num) 
//allows time object to be multiplied with an integer multiplier
//ex) t1 * 2
{
    Time r;

    r.days = t.days * num;
    r.hours = t.hours * num;
    r.minutes = t.minutes * num;
    r.seconds = t.seconds * num;

    r.Simplify();

    return r;

}//end *

bool operator< (const Time& t1, const Time& t2)
{
    if (t1.days > t2.days)
    {
        return false;
    }
    else
    {
        if(t1.hours > t2.hours)
        {
            return false;
        }
        else
        {
            if(t1.minutes > t2.minutes)
            {
                return false;
            }
            else
            {
                if(t1.seconds > t2.seconds)
                {
                    return false;
                }
                else
                {
                    return true;
                }                
            }//end else min            
        }//end else hours
    }//end else days
}//end operator <

bool operator> (const Time& t1, const Time& t2)
{
    if (t1.days > t2.days)
        return true;
    else
    {
        if(t1.hours > t2.hours)
            return true;
        else
        {
            if(t1.minutes > t2.minutes)
                return true;
            else
            {
                if(t1.seconds > t2.seconds)
                    return true;
                else
                {
                    return false;
                }                
            }//end else min            
        }//end else hours
    }//end else days
    
}//end operator >

bool operator<= (const Time& t1, const Time& t2)
{
    Time temp = t1 - t2;

    if (temp.days <= 0 || temp.hours <= 0 || temp.minutes <= 0 || temp.seconds <= 0)
        return true;
    else 
        return false;
}//end <=

bool operator>= (const Time& t1, const Time& t2)
{
    Time temp = t1 - t2;

    if (temp.days >= 0 || temp.hours >= 0 || temp.minutes >= 0 || temp.seconds >= 0)
        return true;
    else 
        return false;
}//end >=

bool operator== (const Time& t1, const Time& t2)
{
    if (t1.days == t2.days && t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds == t2.seconds)
        return true;
    else
        return false;    
}//end ==

bool operator!= (const Time& t1, const Time& t2)
{
    if (t1.days != t2.days || t1.hours != t2.hours || t1.minutes != t2.minutes || t1.seconds != t2.seconds)
        return true;
    else
        return false; 
    
}//end !=

//----member functions----
//-----contructors-----
Time::Time()
//default contructor
//default everything to 0
{
    days=0;
    hours=0;
    minutes=0;
    seconds=0;
}//end default constructor

Time::Time (int sec)
//take in seconds and simplify time
//"conversion constructor" int -> Time
//cannot be negative
{
    if(sec >= 0){
        seconds = sec % 60;
        sec = sec / 60;
        minutes = sec % 60;
        sec = sec / 60;
        hours = sec % 24;
        sec = sec / 24;
        days = sec;
    }
    else {
        Time();
    }

}//end single param contructor

Time::Time (int d, int hr, int min, int sec)
//initializes object
//if negative set to 0
//if any of the provided values are too high, simplfy to appropriate rep
{
    //if values are valid, set and simplify
    if (d >= 0 && hr >= 0 && min >= 0 && sec >= 0) {
        days = d;
        hours = hr;
        minutes = min;
        seconds = sec;

        //if values are too high, simplify
        Simplify();

    }//end if
    
    //if values are negative, default everything to 0
    else {
        Time();
    }
}//end 4 param constructor


//-----operator overlaoding-----
//increment and decrement by 1 second
//handle pre and post forms
//if already at 0, decrement doesn't change it
Time& Time::operator++()
{
    seconds = seconds + 1;  //increment seconds
    Simplify();
    return *this;           //return reference to calling object
}//end pre increment

Time Time::operator++(int)
{
    Time temp = *this;      //copy current object into temp
    seconds = seconds + 1;  //increment
    Simplify();
    return temp;            //return old value
}//post increment

Time& Time::operator--()
{
    seconds = seconds - 1;  //decrement seconds
    return *this;           //return reference to calling object
}//end pre decrement

Time Time::operator--(int)
{
    Time temp = *this;      //copy current object into temp
    seconds = seconds - 1;  //decrement
    return temp;            //return old value
}//post decrement

//-----EXTRA FUNCTIONS-----
Time Time::Simplify()
{
    if(seconds > 59){
        seconds = seconds % 60;
        minutes = minutes + (seconds / 60);
        minutes++;
    }
    if (minutes > 59) {
        minutes = minutes % 60;
        hours = hours + (minutes / 60);
        hours++;
    }
    if (hours > 23) {
        hours = hours % 24;
        days = days + (hours / 24);
        days++;
    }
}//end Simplify
