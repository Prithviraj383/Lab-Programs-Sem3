#include <iostream>
using namespace std;

class Vehicle{
public:
        void vehicle(){cout << "I am a vehicle\n";}
};

class FourWheeler: public Vehicle{
public:
        void fourWheeler(){cout << "I am a Four Wheeler\n";}
};

class Car: public FourWheeler{
public:
        void car(){cout << "I am a Car\n";}
};

int main(){
        Car c;
        c.car();
        c.fourWheeler();
        c.vehicle();
        return 0;
}