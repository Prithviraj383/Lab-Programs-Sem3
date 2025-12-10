#include <iostream>
#include <cmath>

using namespace std;

int main(){

	double a, b, c, r1, r2, real_part, img_part, disc;
	cout << "Enter the coefficients of a, b and c: ";
	cin >> a >> b >> c;
	
	disc = b*b-4*a*c;
	if(disc>0){
		r1 = (-b+sqrt(disc))/2*a;
		r2 = (-b-sqrt(disc))/2*a;
		cout << "The roots are real and unique\n";
		cout << "r1 = " << r1 << ", r2 = " << r2 << endl;
	}else if(disc == 0){
		r1 = r2 = -b/2*a;
		cout << "The roots are real and equal\n";
		cout << "r1 = r2 = " << r1;
	}else{
		real_part = -b/2*a;
		img_part = sqrt(-disc)/2*a;
		cout << "The roots are complex\n";
		cout << "r1 = " << real_part << "+" << img_part << "i";
		cout << ", r2 = " << real_part << "-" << img_part << "i" << endl;
	}
	return 0;
}