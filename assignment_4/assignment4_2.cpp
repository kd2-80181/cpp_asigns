/* Q2. Stack is a Last-In-First-Out data structure. Write a Stack class. It implements stack using
Dynamically allocated array. Stack size should be passed in parameterized constructor. If size is not
given, allocate stack of size 5.
Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print(). */

#include <iostream>
using namespace std;

class stack
{
    int index = 0;
    int size;
    int *top;

public:
    stack(int size)
    {
        this->size = size;
        top = new int[size];
    }

    void push()
    {
        if (!isFull())
        {
            cout << "Enter Element: ";
            cin >> *(this->top);
            this->top++;
            index++;
        }
        else
            cout << "Stack is full." << endl;
    }

    void pop()
    {
        if (!isEmpty())
        {
            this->top--;
            cout << *(this->top);
            index--;
        }
        else
            cout << "Stack is empty." << endl;
    }

    void peek()
    {
        if (!isEmpty())
            cout << "Peek Element is: " << *(this->top - 1) << endl;
        else
            cout << "Stack is empty." << endl;
    }

    int isEmpty()
    {
        return (index <= 0);
    }

    int isFull()
    {
        return (index >= size);
    }

    void print()
    {
        int *st = top;
        int i = 0;

        while (i < index)
        {
            st--;
            cout << *st << " ";
            i++;
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter Size of stack: ";
    cin >> size;
    stack s(size);

    for (int i = 0; i < size; i++)
        s.push();

    s.peek();

    s.print();

    for (int i = 0; i < size; i++)
        s.pop();

    return 0;
}