#include <iostream>
#include <algorithm>
using namespace std;

class Student{
        string usn, name;
        int marks[3];
        float avg;

public:
        void read(){
                cout << "Enter USN number: ";
                cin >> usn;
                cout << "Enter your name: ";
                cin >> name;
                cout << "Enter marks of 3 tests: ";
                for(int i = 0;i<3;++i)  cin >> marks[i];
        }

        void calculate(){
                sort(marks, marks+3);
                avg = (marks[1]+marks[2])/2.0;
        }

        void display(){
                cout << "USN: " << usn << endl;
                cout << "Name: " << name << endl;
                cout << "Average: " << avg << endl;
        }
};

int main(){

        Student s[10];
        int n;
        cout << "Enter number of students: ";
        cin >> n;
        for(int i=0;i<n;++i){
                s[i].read();
                s[i].calculate();
        }
        cout << "\n--------STUDENTAVERAGES---------\n";
        for(int i=0;i<n;++i) s[i].display();
        return 0;
}