#include <iostream>

using namespace std;

class Employee{
        int emp_no;
        string emp_name;
        float basic, da, it, net_salary;

public:
        void read(){
        cout << "\nEnter Employee number: ";
        cin >> emp_no;
        cout << "Enter Employee name: ";
        cin >> emp_name;
        cout << "Enter basic salary: ";
        cin >> basic;
        }

        void calculate(){
                da = 0.52*basic;
                float gross = basic + da;
                it = 0.30*gross;
                net_salary = gross - it;
        }

        void display(){
                cout << "Employee number: " << emp_no << endl;
                cout << "Employee Name: " << emp_name << endl;
                cout << "Basic: " << basic << endl;
                cout << "DA: " << da << endl;
                cout << "IT: " << it << endl;
                cout << "Net Salary: " << net_salary << endl;
        }
};

int main(){

        int n;
        cout << "Enter no. of employees: ";
        cin >> n;
        Employee e[n];
        for(int i=0;i<n;++i){
                e[i].read();
                e[i].calculate();
        }
        cout << "\n--------Employee details-----\n";
        for(int i=0;i<n;++i) e[i].display();
        return 0;
}