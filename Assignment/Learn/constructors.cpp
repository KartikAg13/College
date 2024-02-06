#include <iostream>

using namespace std;

class Student {
    string name;    //private data member

    protected:
        long enrollment;

    public:
        int *marks;
        int size;

        Student() { //default non-parameterized constructor
            cout << "Default constructor called" << endl;
            name = "";
            enrollment = 0;
            size = 3;
            marks = new int[size]();
        }

        Student(string n, long e = -1) {
            //parameterized constructor 1 with default arguments
            cout << "Parameterized constructor 1 called" << endl;
            name = n; //this->name = n
            enrollment = e;   //this->enrollment = e
            size = 3;
            marks = new int[size]();
        }

        Student(string n, long e, int m) {
            //constructor overloading of parameterized constructor 2
            cout << "Parameterized constructor 2 called" << endl;
            name = n;
            enrollment = e;
            size = m;
            marks = new int[size]();
        }

        Student(const Student &s) { //deep copy constructor
            cout << "Deep copy constructor called" << endl;
            name = s.name;
            enrollment = s.enrollment;
            size = s.size;
            marks = new int[size]();
            for(int i = 0; i < size; i++)
                marks[i] = s.marks[i];
        }

        ~Student() {    //destructor
            cout << "Destructor called" << endl;
            delete [] marks;
        }

        void display() {
            cout << "Name: " << name << endl;
            cout << "Enrollment Number: " << enrollment << endl;
            for(int i = 0; i < size; i++)
                cout << *(marks + i) << " ";
            cout << endl;
        }
};

int main() {
    string n1 = "Kartik";
    long e1 = 23803013L;
    int m1 = 3;
    Student s1;  //s1 calls default non-parameterized constructor
    s1.display();
    Student s2(n1); //s2 calls parameterized constructor 1
    s2.display();
    Student s3(n1, e1, m1); //s3 calls parameterized constructor 2
    for(int i = 0; i < s3.size; i++)
        s3.marks[i] = i + 1;
    s3.display();
    Student s4 = s3;
    //s4 calls deep copy contructor
    //Student s4(s3)
    s4.display();
    return 0;
}