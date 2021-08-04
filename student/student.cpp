//-----------STUDENTS.H-----------

//-----------ALLYSON DAVIS-----------
//-----------SECTION 2-----------

#include "student.h"
#include <cstring>

using namespace std;
char* Student::GetFname()
{
    return this->firstname;
}
char* Student::GetLname()
{
    return this->lastname;
}
char* Student::GetCourse()
{
    return this->course;
}

//-------------------BIOLOGY-------------------
//labGrade (30%), termTest1 (15%), termTest2 (15%), termTest3 (15%), finalExam (25%)
Biology::Biology(const char* lname, const char* fname, const char* c, const int lg, const int t1, const int t2, const int t3, const int f)
{
    strcpy(this->lastname, lname);
    strcpy(this->firstname, fname);
    strcpy(this->course, c);

    this->labGrade = lg;
    this->termTest1 = t1;
    this->termTest2 = t2;
    this->termTest3 = t3;
    this->bioFinal = f;

}//end constructor

double Biology::GetFinalAvg()
{
    double finalAvg = (labGrade * 0.30) + (termTest1 * 0.15) + (termTest2 * 0.15) + (termTest3 * 0.15) + (bioFinal * 0.25);

    return finalAvg;
}//end get final avg

int Biology::GetFinalExam()
{
    return bioFinal;
}//end get final exam

char Biology::GetLetterGrade()
{
    double g = GetFinalAvg();
    char grade;

    if (g > 89 && g <= 100)
        grade = 'A';
    else if (g > 79 && g <= 89)
        grade = 'B';
    else if (g > 69 && g <= 79)
        grade = 'C';
    else if (g > 50 && g <= 69)
        grade = 'D';
    else 
        grade = 'F';

    return grade;

}//end get letter grade

//-------------------THEATER-------------------
//participation (40%), midterm (25%), finalExam (35%)
Theater::Theater(const char* lname, const char* fname, const char* c, const int p, const int m, const int f)
{
    strcpy(this->lastname,lname);
    strcpy(this->firstname, fname);
    strcpy(this->course, c);

    this->participation = p;
    this->midterm = m;
    this->theaterFinal = f;
    
}//end constructor

double Theater::GetFinalAvg()
{
    double finalAvg = (participation * 0.40) + (midterm * 0.25) + (theaterFinal * 0.35);

    return finalAvg;
}//end get final avg

int Theater::GetFinalExam()
{
    return theaterFinal;
}//end get final exam

char Theater::GetLetterGrade()
{
    double g = GetFinalAvg();
    char grade;

    if (g > 89 && g <= 100)
        grade = 'A';
    else if (g > 79 && g <= 89)
        grade = 'B';
    else if (g > 69 && g <= 79)
        grade = 'C';
    else if (g > 50 && g <= 69)
        grade = 'D';
    else 
        grade = 'F';

    return grade;
}//end get letter grade

//-------------------COMPSCI-------------------
//pg1-6, programAvg (30%), test1 (20%), test2 (20%), finalExam (30%)
CompSci::CompSci(const char* lname, const char* fname, const char* c, const int p1, const int p2, const int p3, const int p4, const int p5, const int p6, const int t1, const int t2, const int f)
{
    strcpy(this->lastname,lname);
    strcpy(this->firstname, fname);
    strcpy(this->course, c);

    this->pg1 = p1;
    this->pg2 = p2;
    this->pg3 = p3;
    this->pg4 = p4;
    this->pg5 = p5;
    this->pg6 = p6;

    this->programAvg = (pg1 + pg2 + pg3 + pg4 + pg5 + pg6) / 6;

    this->test1 = t1;
    this->test2 = t2;

    this->compSciFinal = f;
    
}//end constructor

double CompSci::GetFinalAvg()
{
    double progAvg = (pg1 + pg2 + pg3 + pg4 + pg5 + pg6) / 6;

    double finalAvg = (progAvg * 0.30) + (test1 * 0.20) + (test2 * 0.20) + (compSciFinal * 0.30);

    return finalAvg;
}//end get final avg

int CompSci::GetFinalExam()
{
    return compSciFinal;
}//end get final exam

char CompSci::GetLetterGrade()
{
    double g = GetFinalAvg();
    char grade;

    if (g > 89 && g <= 100)
        grade = 'A';
    else if (g > 79 && g <= 89)
        grade = 'B';
    else if (g > 69 && g <= 79)
        grade = 'C';
    else if (g > 50 && g <= 69)
        grade = 'D';
    else 
        grade = 'F';

    return grade;
}//end get letter grade
