#include<iostream>
using namespace std;

namespace NStudent
{
class Student
{
    private: 

    int roll_no;
    string name;
    float marks;

    public:

    void initStudent()
    {
        this->roll_no=0;
        this->name=" ";
        this->marks=0;
        cout << "Initialized Roll No." << endl;
        cout << "Initialized Name." << endl;
        cout << "Initialized Marks." << endl;     
    }

    void printStudentOnConsole()
    {
        cout << "roll_no: " << this->roll_no << endl;
        cout << "name: " << this->name << endl;
        cout << "marks: " << this->marks << endl;
    }

    void acceptStudentFromConsole()
    {
        cout << "Enter Roll No = ";
        cin >> this->roll_no;
        getchar();
        cout << "Enter Name = ";
        getline(cin,name);
        cout << "Enter Marks = ";
        cin >> this->marks;
    }

    int menu()
    {
        int choice;
        cout << "***MENU DRIVEN PROGRAM***" << endl;
        cout << "Press 1 to initialize students." << endl;
        cout << "Press 2 to accept data." << endl;
        cout << "Press 3 to print data" << endl;
        cout << "Press 0 to exit" << endl;
        cout << "Enter the choice: " << endl;

        cin >> choice;
        return choice;     
    }
};
}

int main() 
{
    int choice;
    NStudent::Student S1; 

    while((choice=S1.menu())!=0)
    {
        switch(choice)
        {
            case 1: S1.initStudent();
                    break;
            
            case 2: S1.acceptStudentFromConsole();
                    break;
            
            case 3: S1.printStudentOnConsole();
                    break;

            case 4: break; 
        }
    }
    return 0;
}