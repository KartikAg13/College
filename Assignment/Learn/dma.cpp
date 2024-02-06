#include <iostream>

using namespace std;

class Student {
    public:
        static string head; //head has the same value for all the objects
        string name;
        int marks;

        static void display();  //has access to static data members only

        void output() {
            cout << "Name: " << name << endl;
            cout << "Marks: " << marks << endl;
        }
};

void Student::display() {
    cout << "Head: " << head << endl;
}

string Student::head = "Kartik";

int main() {
    Student *s = new Student[3]();
    for(int i = 0; i < 3; i++) {
        cout << "Please enter the name: ";
        cin >> s[i].name;
        cout << "Please enter the marks: ";
        cin >> s[i].marks;
    }
    //access the static data member and member function using scope resolution operator
    Student::head = "Arush";
    Student::display();
    for(int i = 0; i < 3; i++)
        s[i].output();
    return 0;
}