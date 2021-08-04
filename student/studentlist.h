//-----------STUDENTLIST.H-----------

//-----------ALLYSON DAVIS-----------
//-----------SECTION 2-----------
#include "student.h"

using namespace std;

class StudentList {
    public:
    StudentList();		// starts out empty
    ~StudentList();		// cleanup (destructor)

    bool ImportFile(const char* filename);
    bool CreateReportFile(const char* filename);
    void ShowList() const;	// print basic list data

    void SortList();

    int GetSize() const;

    private:
        Student ** list; //array of student pointers
        int size;
        int max;

        void Grow(int num);

};//end StudentList class