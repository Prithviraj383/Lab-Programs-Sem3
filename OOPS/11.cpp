#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int index;

    cout << "Enter index to access (0-4): ";
    cin >> index;

    try
    {
        if (index < 0 || index >= 5) throw index;
        cout << "Value at index " << index << "=" << arr[index] << endl;
    }
    catch (int e)
    {
        cout << "Array Index Out of Bounds Exception !Invalid index : " << e << endl;
        cout << "Program executed successfully." << endl;
    }
    return 0;
}