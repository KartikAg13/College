#include <iostream>

using namespace std;

class Student {
    string name;
    
    public:
    int age;
    bool gender;

    Student() { //Default Constructor
        cout << "Constructor" << endl;
    }

    Student(string s, int a, int g) {   //Parameterized constructor
        name = s;
        age = a;
        gender = g;
    }

    Student(Student &a) {   //Deep Copy Constructor
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    ~Student() {
        cout << "Destructor" << endl;
    }

    void setName(string s) {    //Setter
        this->name = name;
    }

    void getName(string s) {    //Getter
        cout << name << endl;
    }

    void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }

    bool operator == (Student &a) {
        if(name == a.name && age == a.age && gender == a.gender)
            return true;
        return false;
    }
};

int main() {

    /*
    Student arr[3];
    string s;
    for(int i = 0; i < 3; i++) {
        cout << "Please enter the name of the student: ";
        cin >> s;
        arr[i].setName(s);
        cout << "Please enter the age of the student: ";
        cin >> arr[i].age;
        cout << "Please enter the gender of the student: ";
        cin >> arr[i].gender;
    }
    for(int i = 0; i < 3; i++)
        arr[i].printInfo();
    */
   
    Student a("Urvi", 20, 1);    //Parameterized constructor
    a.printInfo();
    Student b;   //Default Constructor
    Student c = a;   //Deep Copy Constructor
    if(c == a)
        cout << "Both are same" << endl;
    else
        cout << "Both are different" << endl;

    return 0;
}