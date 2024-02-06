#include <iostream>

using namespace std;

class Complex {
    public:
        int a, b;

        Complex() {
            a = b = 0;
        }

        Complex(int x, int y) {
            a = x;
            b = y;
        }

        void display() {
            cout << "Complex Number: " << a << " + " << b << "i" << endl;
        }

        void operator=(const Complex &ob) {  //alternate to copy constructor
            a = ob.a;
            b = ob.b;
        }

        Complex operator+(const Complex &ob) {  //plus operator overloading
            Complex ob1;
            ob1.a = a + ob.a;  //ob1.a = this->a + ob.a
            ob1.b = b + ob.b;    //ob1.b = this->b + ob.b
            return ob1;
        }

        Complex operator++(int) {
            //post increment operator overloading
            //pre increment -> Complex operator++()
            Complex ob2;
            ob2.a = a++;
            ob2.b = b++;
            return ob2;
        }
};

bool operator<=(const Complex &ob1, const Complex &ob2) { //less than operator overloading
    if(ob1.a <= ob2.a && ob1.b <= ob2.b)
        return true;
    else 
        return false;
}

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    Complex c3 = c2;    //assignment operator overloading
    cout << "Assignment:" << endl;
    c3.display();
    cout << "Addition:" << endl;
    c3 = c1 + c2;   //plus operator overloading
    c3.display();
    cout << "Post Increment: " << endl;
    c3 = c1++;  //post increment operator overloading
    c3.display();
    c1.display();
    if(c1 <= c2)    //less than operator overloading
        cout << "c1 is less than c2" << endl;
    else 
        cout << "c1 is greater than c2" << endl;
}