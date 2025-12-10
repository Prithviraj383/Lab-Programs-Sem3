#include <iostream>

using namespace std;

class Complex{
        float real, img;

public:
        Complex() : real(0), img(0){}

        Complex(float r, float i) : real(r), img(i) {}

        Complex add(int a, Complex c){
                Complex temp;
                temp.real = a+c.real;
                temp.img = c.img;
                return temp;
        }

        Complex add(Complex a, Complex b){
                Complex temp;
                temp.real = a.real + b.real;
                temp.img = a.img + b.img;
                return temp;
        }

        void display(){ cout << real << " + " << img << "i" << endl;}
};

int main(){

        Complex c1(3,2), c2(1,7), c3;
        int a = 5;
        cout << "ADD(a, c2): ";
        c3 = c3.add(a, c2);
        c3.display();

        cout << "ADD(c1, c2): ";
        c3 = c3.add(c1, c2);
        c3.display();
        return 0;
}