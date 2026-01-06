#include <iostream>
#include <string>
using namespace std;

class stackOverflowException
{
public:
    string message;
    stackOverflowException(string s) { message = s; }
};

class stackUnderflowException
{
public:
    string message;
    stackUnderflowException(string s) { message = s; }
};

class stack
{
    int top;
    int size;
    int *arr;

public:
    stack(int s)
    {
        size = s;
        arr = new int[size];
        top = -1;
    }
    void push(int x)
    {
        if (top == (size - 1))
            throw stackOverflowException("Stack overflow.. element cant be pushed\n");
        arr[++top] = x;
        cout << x << "Pushed to the stack\n";
    }
    void pop()
    {
        if (top == -1)
            throw stackUnderflowException("Stack underflow.. no element to pop\n");
        cout << arr[top--] << " popped from the stack\n";
    }
    void display()
    {
        if (top == -1)
            cout << "Stack is empty\n";
        else
        {
            cout << "Stack Elements\n";
            for (int i = top; i >= 0; --i)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    stack s(3);
    try
    {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
    }
    catch (stackOverflowException &e)
    {
        cout << "Exception caught: " << e.message << endl;
    }
    try
    {
        s.pop();
        s.pop();
        s.pop();
    }
    catch (stackUnderflowException &e)
    {
        cout << "Exception caught: " << e.message << endl;
    }
    return 0;
}