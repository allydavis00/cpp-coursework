//-----------STUDENTLIST.CPP-----------

//-----------ALLYSON DAVIS-----------
//-----------SECTION 2-----------

#include "studentlist.h"
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

StudentList::StudentList()
//default constructor, sets up an empty list
{
    size = 0;
    max = 0;
    list = new Student*[size];

}//end constructor

StudentList::~StudentList()
//destructor
//cleans up all dynamically managed data inside StudentList object
{
    delete [] list;
}//end destructor

bool StudentList::ImportFile(const char* filename) {

    ifstream file;
    int numStud;

    file.open(filename);

    if (!file)
        return false;

    file >> numStud;
    file.ignore(80, '\n');

    if (size == 0) {
        size = numStud;
        delete [] list;
        list = new Student * [size];

        char fname[21];
        char lname[21];
        char c[17];

        for (int i = 0; i < numStud; i ++) {
            file.getline(lname, ',');
            file.ignore(1);
            
            file.getline(fname, '\n');
            file.ignore(80, '\n');

            file.getline(c, 16, ' ');
            file.ignore(1);

            if(c[0] == 'B') {
                int lg, t1, t2, t3, f;
                // list[i] = new Biology(fname, lname, c, lg, t1, t2, t3, f);

                file >> lg;
                file >> t1;
                file >> t2;
                file >> t3;
                file >> f;

                list[i] = new Biology(fname, lname, c, lg, t1, t2, t3, f);

                //list[i]->SetGrades(lg, t1, t2, t3, f);
            }//end if B

            else if(c[0] == 'T') {
                int part, mid, f;
                // list[i] = new Theater(fname, lname, c, part, mid, f);

                file >> part;
                file >> mid;
                file >> f;

                list[i] = new Theater(fname, lname, c, part, mid, f);

                //list[i]->SetGrades(part, mid, f);
            }//end if T
        
            else if(c[0] == 'C') {
                int pg1, pg2, pg3, pg4, pg5, pg6, t1, t2, f;
                char c2 []= {'C', 'o', 'm', 'p', 'u', 't', 'e', 'r', ' ', 'S', 'c', 'i', 'e', 'n', 'c', 'e'};
                // list[i] = new CompSci(fname, lname, c, pg1, pg2, pg3, pg4, pg5, pg6, t1, t2, f);

                file.ignore(8);

                file >> pg1;
                file >> pg2;
                file >> pg3;
                file >> pg4;
                file >> pg5;
                file >> pg6;
                file >> t1;
                file >> t2;
                file >> f;

                list[i] = new CompSci(fname, lname, c2, pg1, pg2, pg3, pg4, pg5, pg6, t1, t2, f);

                // list[i]->SetGrades(pg1, pg2, pg3, pg4, pg5, pg6, t1, t2, f);
            }//end if C
        }//end for
    }//end if size = 0

    else {
        int temp = size;
        char fname[21];
        char lname[21];
        char c[17];

        this->Grow(numStud);

        for (int i = temp; i < size; i ++){
            file.getline(lname, ',');
            file.ignore(1);

            file.getline(fname, '\n');
            file.ignore(80, '\n');

            file.getline(c, 16, ' ');
            file.ignore(1);

            if(c[0] == 'B') {
                int lg, t1, t2, t3, f;
                // list[i] = new Biology(fname, lname, c, lg, t1, t2, t3, f);

                file >> lg;
                file >> t1;
                file >> t2;
                file >> t3;
                file >> f;

                list[i] = new Biology(fname, lname, c, lg, t1, t2, t3, f);

                //list[i]->SetGrades(lg, t1, t2, t3, f);
            }//end if B

            else if(c[0] == 'T') {
                int part, mid, f;
                // list[i] = new Theater(fname, lname, c, part, mid, f);

                file >> part;
                file >> mid;
                file >> f;

                list[i] = new Theater(fname, lname, c, part, mid, f);

                //list[i]->SetGrades(part, mid, f);
            }//end if T
        
            else if(c[0] == 'C') {
                int pg1, pg2, pg3, pg4, pg5, pg6, t1, t2, f;
                char c2 []= {'C', 'o', 'm', 'p', 'u', 't', 'e', 'r', ' ', 'S', 'c', 'i', 'e', 'n', 'c', 'e'};
                // list[i] = new CompSci(fname, lname, c, pg1, pg2, pg3, pg4, pg5, pg6, t1, t2, f);

                file.ignore(8);

                file >> pg1;
                file >> pg2;
                file >> pg3;
                file >> pg4;
                file >> pg5;
                file >> pg6;
                file >> t1;
                file >> t2;
                file >> f;

                list[i] = new CompSci(fname, lname, c2, pg1, pg2, pg3, pg4, pg5, pg6, t1, t2, f);

                // list[i]->SetGrades(pg1, pg2, pg3, pg4, pg5, pg6, t1, t2, f);
            }//end if C
        }//end for
    }//end else
    
    file.close();

}//end importfile

bool StudentList::CreateReportFile(const char* filename)
//creats a grade report and writes to output file
//if file cannot be opened, return tru, else return false
{
    ofstream gradeReport;

    gradeReport.open(filename);

    if (!gradeReport)
        return false;

    //write to output file
    gradeReport << "Student Grade Summary\n" << "---------------------\n\n";
    gradeReport << "BIOLOGY CLASS" << endl;
    gradeReport << setw(30) << "Student" << setw(6) << "Final" << setw(8) << "Final" << "Letter" << endl;
    gradeReport <<  setw(30) << "Name" <<  setw(6) << "Exam" << setw(8) << "Avg" <<  setw(8) << "Grade" << endl;
    gradeReport << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i ++) {
        if(list[i]->GetCourse() == "Biology") {
            gradeReport.width (30);
            gradeReport << list[i]->GetFname() << " " << list[i]->GetLname();

            gradeReport.width(6);
            gradeReport << list[i]->GetFinalExam();

            gradeReport.width(8);
            gradeReport << list[i]->GetFinalAvg();

            gradeReport.width(8);
            gradeReport << list[i]->GetLetterGrade();

        }
    }//end for loop

    gradeReport << "\nTHEATER CLASS" << endl;
    gradeReport <<  setw(30) << "Student" <<  setw(6) << "Final" << setw(8) << "Final" << "Letter" << endl;
    gradeReport <<  setw(30) << "Name" <<  setw(6) << "Exam" << setw(8) << "Avg" <<  setw(8) << "Grade" << endl;
    gradeReport << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i ++) {
        if(list[i]->GetCourse() == "Theater") {
            gradeReport.width (30);
            gradeReport << list[i]->GetFname() << " " << list[i]->GetLname();

            gradeReport.width(6);
            gradeReport << list[i]->GetFinalExam();

            gradeReport.width(8);
            gradeReport << list[i]->GetFinalAvg();

            gradeReport.width(8);
            gradeReport << list[i]->GetLetterGrade();
        }
    }//end for loop 

    gradeReport << "\nCOMPSCI CLASS" << endl;
    gradeReport <<  setw(30) << "Student" <<  setw(6) << "Final" << setw(8) << "Final" << "Letter" << endl;
    gradeReport <<  setw(30) << "Name" <<  setw(6) << "Exam" << setw(8) << "Avg" <<  setw(8) << "Grade" << endl;
    gradeReport << "----------------------------------------------------------------------" << endl;

    for (int i = 0; i < size; i ++) {
        if(list[i]->GetCourse() == "Computer Science") {
            gradeReport.width (30);
            gradeReport << list[i]->GetFname() << " " << list[i]->GetLname();

            gradeReport.width(6);
            gradeReport << list[i]->GetFinalExam();

            gradeReport.width(8);
            gradeReport << list[i]->GetFinalAvg();

            gradeReport.width(8);
            gradeReport << list[i]->GetLetterGrade();
        }
    }//end for loop 

    gradeReport.close();
    
    return true;
}//end CreateReportFile

void StudentList::ShowList() const
// print current list of students to the screen
//lastname, firstname, course name
//output should line up in columns
{
    cout <<  setw(21) << "Last";
    cout <<  setw(21) << "First";
    cout <<  setw(17) << "Course\n" << endl;

    for (int i = 0; i < size; i++){
        cout <<  setw(21) << list[i]->GetLname();
        cout <<  setw(21) << list[i]->GetFname();
        cout <<  setw(17) << list[i]->GetCourse() << endl;
    }
}//end ShowList

int StudentList::GetSize() const
{
    return size;
}

void StudentList::Grow (int num)
//when adding to array, add number of students to size
{
    size = size + num;

    Student ** newList = new Student * [size];

    for (int i = 0 ; i < size; i ++)
        newList[i] = list[i];
    
    delete [] list;
    list = newList;
}

void StudentList::SortList()
{
        for(int i = 0; i < this->size; i++){
        for (int j = 0; i < this->size - i; j++){
            if(this->list[j]->GetLname() > this->list[j+1]->GetLname())
                swap(this->list[j], this->list[j+1]);
            else if (this->list[j]->GetLname() == this->list[j+1]->GetLname()){
                if(this->list[j]->GetFname() > this->list[j+1]->GetFname())
                    swap(this->list[j], this->list[j+1]);
            }
        }//end for j
    }//end for i
}
