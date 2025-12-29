#include <iostream>
#include <stdexcept>
using namespace std;

void divide(int a, int b)
{
    if (b == 0)
        throw runtime_error("Division by zero error");
    else
        cout << "Result = " << (a / b) << endl;
}

int main()
{
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    try
    {
        divide(x, y);
    }
    catch (const exception& e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "Program continues successfully" << endl;
    return 0;
}
