//-----------STUDENTS.H-----------

//-----------ALLYSON DAVIS-----------
//-----------SECTION 2-----------

class Student {
    public:
        virtual double GetFinalAvg() = 0;
        virtual int GetFinalExam() = 0;
        virtual char GetLetterGrade() = 0;

        char* GetFname();
        char* GetLname();
        char* GetCourse();

    protected:
        char firstname[21];
        char lastname[21];
        char course[17];

        int totalStud;

};//end Students class

class Biology : public Student
//lab grade = 30%
//3 tests = 15% each
//final = 25%
{
    public:
        Biology(const char* lname, const char* fname, const char* c, const int lg, const int t1, const int t2, const int t3, const int f);
        double GetFinalAvg();
        int GetFinalExam();
        char GetLetterGrade();

        // char* GetFname();
        // char* GetLname();
        // char* GetCourse();

    private:
        int labGrade;
        int termTest1, termTest2, termTest3;
        int bioFinal;

};//end Biology class

class Theater : public Student
//participation = 40%
//midterm = 25%
//final = 35%
{
    public:
        Theater(const char* lname,const char* fname, const char* c, const int p, const int m, const int f);
        double GetFinalAvg();
        int GetFinalExam();
        char GetLetterGrade();

        // char* GetFname();
        // char* GetLname();
        // char* GetCourse();

    private:
        int participation;
        int midterm;
        int theaterFinal;

};//end Theatre class

class CompSci : public Student
//6 assignment avg = 30%
//test 1 = 20%
//test 2 = 20%
//final = 30%
{
    public:
        CompSci(const char* lname, const char* fname, const char* c, const int p1, const int p2, const int p3, const int p4, const int p5, const int p6, const int t1, const int t2, const int f);
        double GetFinalAvg();
        int GetFinalExam();
        char GetLetterGrade();

        // char* GetFname();
        // char* GetLname();
        // char* GetCourse();

    private:
        int pg1, pg2, pg3, pg4, pg5, pg6;   //program grades
        double programAvg;
        int test1, test2;
        int compSciFinal;
}; //end Computer Science