#include <iostream>
using namespace std;

class factorial
{
private:
    int num1;

    factorial(int num1)
    {
        this->num1 = num1;
    }
        

public:

    int calculation(int num1)
    {
        if (num1 < 0)
            throw 2.3;
        if (num1 == 0 || (num1) == 1)
        {
            return 1; // base condition
        }
        return num1 * calculation(num1 - 1);
    }

    void display()
    {
        int res = calculation(this->num1);
        cout << "Factorial of " << this->num1 << ": " << res << endl;
    }
    

    static factorial  *createfactorial()
    {
        int num1;
        cin >> num1;
        return new factorial(num1);
    }

    factorial()
    {
        this->num1 = 0;
    }

    // factorial(int num1)
    // {
    //     this->num1 = num1;
    // }

    void set_num1(int s)
    {
        this->num1 = s;
    }

    int get_num1(int s)
    {
        return s;
    }
};

int main()
{
    factorial *fptr = factorial::createfactorial();
    fptr->display();
    delete fptr;
    return 0;
}