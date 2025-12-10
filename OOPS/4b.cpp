#include <iostream>

using namespace std;

int sum_two_nums(int, int);
float sum_two_nums(float, float);

int main(){
	cout << "Sum of integers: " << sum_two_nums(10,20) << endl;
	cout << "Sum of floats: " << sum_two_nums(10.52, 20.71) << endl;
	return 0;
}

int sum_two_nums(int a, int b){
	return a+b;
}

float sum_two_nums(float a, float b){
	return a+b;
}