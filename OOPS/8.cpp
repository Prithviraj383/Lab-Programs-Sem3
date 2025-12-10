#include <iostream>
using namespace std;

class Shape{
public:
        void display(){
                cout << "This is a Shape\n";
        }
};

class Polygon: public Shape{
public:
        void display(){
                cout << "Polygon is a Shape\n";
        }
};

class Rectangle: public Polygon{
public:
        void display(){
                cout << "Rectangle is a Polygon\n";
        }
};

class Triangle: public Polygon{
public:
        void display(){
                cout << "Triangle is a Polygon\n";
        }
};

class Square: public Rectangle{
public:
        void display(){
                cout << "Square is a Rectangle\n";
        }
};

int main(){

        Shape s;
        Polygon p;
        Rectangle r;
        Triangle t;
        Square sq;
        cout << "Calling display functions\n";
        s.display();
        p.display();
        r.display();
        t.display();
        sq.display();
        return 0;
}