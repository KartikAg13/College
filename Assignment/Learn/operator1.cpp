#include <iostream>
#include <iomanip>

using namespace std;

class Student {
    string name;

    protected:
        long enrollment;
    
    public:
        int *marks;
        int size;

        Student() {
            name = "";
            enrollment = 0;
            size = 0;
        }

        int &operator[](int i) {
            //overloading of [] operator
            //returns the element at i from the marks array when the object calls it
            return marks[i];
        }

        friend istream &operator>>(istream &, Student &);   //input stream operator overloading
        friend ostream &operator<<(ostream &, const Student &); //output stream operator overloading
};

istream &operator>>(istream &input, Student &s) {
    input >> setw(10) >> s.name;    //max length of name is 10
    input >> s.enrollment;
    input >> s.size;
    s.marks = new int[s.size]();
    for(int i = 0; i < s.size; i++)
        input >> s[i];
    //calls [] overloading function
    //s[i] can be used because Student object is not constant
    return input;
}

ostream &operator<<(ostream &output, const Student &s) {
    output << "Name: " << s.name << endl;
    output << "Enrollment: " << s.enrollment << endl;
    //name and enrollment will be inaccessible if the class is not constant
    for(int i = 0; i < s.size; i++)
        output << s.marks[i] << " ";
    //does not call [] overloading function
    //s[i] cannot be used because Student object is constant
    return output;
}

int main() {
    Student student;
    cout << "Enter the details:" << endl;
    cin >> student;
    cout << "Details: " << endl;
    cout << student << endl;
    delete [] student.marks;    //deallocation of marks array
    return 0;
}