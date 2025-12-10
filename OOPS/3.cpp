#include <iostream>

using namespace std;

void swap_val(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	cout << "a = " << a << "b = " << b << endl;
}

void swap_ptr(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_ref(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){

	int x, y;
	cout << "Enter two numbers: ";
	cin >> x >> y;
	cout << "Before swapping: x = " << x << " y = " << y << endl;
	swap_val(x, y);
	cout << "After call by value: x = " << x << " y = " << y << endl;
	swap_ptr(&x, &y);
	cout << "After call by Pointer: x = " << x << " y = " << y << endl;
	swap_ref(x, y);
	cout << "After call by Reference: x = " << x << " y = " << y << endl;
	return 0;
}

