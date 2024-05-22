#include <iostream>
using namespace std;
class Shape {
    public:
    int *length;
    double area;

    Shape() {
        cout << "Constructor of Shape" << endl;
        length = new int();
        area = 0;
    }

    //virtual function
    virtual void input() {
        cout << "Please enter the length: ";
        cin >> *length;
    }

    double getArea() {
        return area;
    }

    //virtual destructor
    virtual ~Shape() {
        cout << "Destructor of Shape" << endl;
        delete length;
    }
};

//virtual public inheritance
class Rectangle : virtual public Shape {
    public:
    int *breadth;

    Rectangle() {
        cout << "Constructor of Rectangle" << endl;
        breadth = new int();
    }

    void input() {
        Shape::input();
        cout << "Please enter the breadth: ";
        cin >> *breadth;
        area = (*length) * (*breadth);
    }

    ~Rectangle() {
        cout << "Destructor of Rectangle" << endl;
        delete breadth;
    }
};

class Square : virtual public Shape {
    public:
    Square() {
        cout << "Constructor of Square" << endl;
    }

    void input() {
        Shape::input();
        area = (*length) * (*length);
    }

    ~Square() {
        cout << "Destructor of Square" << endl;
    }
};

class Circle : public Rectangle, public Square {
    public:
    const double pi = 3.14;

    Circle() {
        cout << "Constructor of Circle" << endl;
    }

    void input() {
        area = pi * (*length) * (*length);
    }

    ~Circle() {
        cout << "Destructor of Circle" << endl;
    }
};

int main() {
    Shape *s = new Shape();
    s->input();
    delete s;
    Circle c;
    Shape *s=new Circle();
    s->input();
    cout << "Area: " << s->getArea() << endl;
    return 0;
}