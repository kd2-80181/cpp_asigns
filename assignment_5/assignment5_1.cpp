
#include <iostream>
#include <string.h>
#include <algorithm> // for std::transform
#include <cctype>    // for std::tolower
using namespace std;

int n;

class Student
{
    string name;
    string gender;
    int rollNumber;
    int marks[3];

public:
    Student()
    {
    }

    Student(int rollNumber, string name, string gender)
    {
        this->rollNumber = rollNumber;
        this->name = name;
        this->gender = gender;
        for (int i = 0; i < 3; i++)
        {

            this->marks[i] = 0;
        }
    }

    ~Student()
    {
    }

    void accept()
    {
        cout << "Enter Student Roll no. : ";
        cin >> this->rollNumber;

        cout << "\nEnter Student Name : ";
        cin.ignore();
        getline(cin, this->name);

        cout << "Enter gender : ";
        cin >> this->gender;

        cout << "Enter marks for 3 subjects : ";
        for (int i = 0; i < 3; i++)
        {
            cout << "Subject " << i + 1 << " : ";
            cin >> this->marks[i];
        }
    }

    void print()
    {
        int total = 0;
        cout << "\nStudent Roll no. is : " << this->rollNumber;
        cout << "\nStudent Name : " << this->name;
        cout << "\nGender : " << this->gender;

        cout << "\nMarks of 3 subjects are : \n";
        for (int i = 0; i < 3; i++)
        {
            cout << "Subject " << i + 1 << " : " << this->marks[i] << "\t";
            total += this->marks[i];
        }
        cout << "\nPercentage is : " << static_cast<double>(total) / 3.0 << "%" << endl;
    }
    friend int searchRecords(Student arr[]);
    friend void sortRecords(Student arr[]);
};

int searchRecords(Student arr[])
{
    string name;
    cout << "Enter Name to search : ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < n; i++)
    {
        string lowerStr1 = name;
        string lowerStr2 = arr[i].name;
        transform(lowerStr1.begin(), lowerStr1.end(), lowerStr1.begin(), ::tolower);
        transform(lowerStr2.begin(), lowerStr2.end(), lowerStr2.begin(), ::tolower);

        if (lowerStr1 == lowerStr2)
            return i;
    }
    return -1;
}



void sortRecords(Student arr[])
{
    Student temp;

    for (int pass = 0; pass < n - 1; pass++)
    {
        for (int j = 0; j < n - pass - 1; j++)
        {
            if (arr[j].rollNumber > arr[j + 1].rollNumber)
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

enum Smenu
{
    EXIT,
    Accept,
    Print,
    Search,
    Sort
};

int menu()
{
    int choice;
    cout << "\n0. EXIT\n1. Accept\n2. Print\n3. Search\n4. Sort\n";
    cout << "Enter Your choice : ";
    cin >> choice;
    return choice;
}

int main()
{   int n;
    int choice, index;
    cout << "Enter no of students records you want to enter : ";
    cin >> n;
    Student *s;
    s = new Student[n];

    while ((choice = menu()) != 0)
    {

        switch (choice)
        {
        case Accept:
            for (int i = 0; i < n; i++)
                s[i].accept();
            break;

        case Print:
            for (int i = 0; i < n; i++)
                s[i].print();
            break;

        case Search:
            index = searchRecords(s);
            if (index != -1)
            {
                cout << "Student Record found\n";
                s[index].print();
            }
            else
                cout << "Student Record Not found\n";
            break;

        case Sort:
            sortRecords(s);
            for (int i = 0; i < n; i++)
                s[i].print();
            break;

        default:
            cout << "\nEnter a valid option.\n";
            break;
        }
    }

    delete[] s;

    return 0;
}