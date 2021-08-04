//-------TIME.H------
//----Allyson Davis----
//-----section 2-----

#include <iostream>
using namespace std;

class Time {

    //friend functions
    friend ostream& operator<< (ostream& os, const Time& t);
    friend istream& operator>> (istream& in, Time& t);

    friend Time operator- (const Time&, const Time&);
    friend Time operator+ (const Time&, const Time&);
    friend Time operator* (const Time&, int);

    friend bool operator< (const Time& , const Time& );
    friend bool operator> (const Time& , const Time& );
    friend bool operator<= (const Time& , const Time& );
    friend bool operator>= (const Time& , const Time& );
    friend bool operator== (const Time& , const Time& );
    friend bool operator!= (const Time& , const Time& );

    public:
        //contructors
        Time();
        Time (int sec);
        Time (int d, int hr, int min, int sec);

        Time& operator++();
        Time operator++(int);
        Time& operator--();
        Time operator--(int);  

        //extra functions
        Time Simplify();

    private:
        int days;
        int hours;
        int minutes;
        int seconds;

};