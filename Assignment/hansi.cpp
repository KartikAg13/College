#include <iostream>
using namespace std;

class Derived;
class Base {
    private:    //No need to specify
    string name;

    protected:  //Need to specify
    long enrollment_no;

    public:     //Need to specify
    int marks;

    Base() {    //Default constructor
        name = "";
        enrollment_no = 0;
        marks = 0;
    }

    Base(string n, long en, int m) {    //Parameterized constructor
        this->name = name;
        this->enrollment_no = en;
        this->marks = m;
    }

    Base(const Base &b) {   //Deep copy constructor
        this->name = b.name;
        this->enrollment_no = b.enrollment_no;
        this->marks = b.marks;
    }

    Base operator+(const Base &b) { //Operator overloading of + operator
        Base result;
        result.marks = this->marks + b.marks;
        return result;
    }

    void input();   //Class method declaration

    friend void display(Base b, Derived d); //Friend function declaration
    friend class Derived;   //Friend class  
};

void Base::input() {    //Class method definition to store the values
        cout << "Please enter the name: ";
        cin >> name;
        cout << "Please enter the enrollment number: ";
        cin >> enrollment_no;
        cout << "Please enter the marks: ";
        cin >> marks;
}

class Derived {     //Friend class
    string back_subject;    //Private data member

    public:
    Derived() {     //Default constructor
        back_subject = "";
    }

    friend void display(Base b, Derived d); //Friend function declaration

    void input();   //Class method declaration
};

void Derived::input() { //Class method definition to store and change the values
    cout << "Sad: ";
    cin >> back_subject;
    Base b;
    b.name = "Sad";
}

void display(Base b, Derived d) {   //Friend function definition
    cout << "Name: " << b.name << endl;
    cout << "Enrollment Number: " << b.enrollment_no << endl;
    cout << "Marks: " << b.marks << endl;
    cout << "Back in " << d.back_subject << endl;
}

int main() {
    Base b; //Object for class Base
    Base b1("kumar", 23803022, 0);
    Base b2;
    Derived d;  //Object for class Derived
    b.input();
    b2 = b + b1;
    cout << "marks of 2 * kumar: " << b2.marks << endl;
    char choice = 'y';
    cout << "Are you sad? " << endl << "y: yes" << endl << "n: no" << endl;
    cin >> choice;
    if(choice == 'y')
        d.input();
    display(b, d);
    return 0;
}