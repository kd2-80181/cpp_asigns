#include <iostream>
using namespace std;

class factorial
{
private:
    int num1;

public:
    factorial()
    {
        this->num1 = 0;
    }

    factorial(int num1)
    {
        this->num1 = num1;
    }

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
    int n;
    try
    {
        cout << "Enter the number: " << endl;
        cin >> n;
        factorial F(n);
        F.display();
    }
    catch (int e)
    {
        cout << "You have entered wrong number." << endl;
    }
    catch (...)
    { // generic catch block
        cout << "Double";
    }
    return 0;
}