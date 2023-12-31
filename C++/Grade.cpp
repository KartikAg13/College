#include <iostream>

using namespace std;

class College {
    private:
    static string principal_name;

    public:
    void setPrincipalName(string name) {
        principal_name = name;
    }

    string getPrincipalName() {
        return principal_name;
    }
};

class Student {
    private:
    int id;
    string name;
    float marks[5];
    float average;
    char grade;
    College cobj;

    public:
    void getStudentDetails();
    float calculateAverage();
    char findGrade();
    void displayStudentDetails();

    void setID(int id) {
        this->id = id;
    }

    int getID() {
        return id;
    }

    void setName(string n) {
        this->name = n;
    }

    string getName() {
        return name;
    }

    void setMarks(float m[]) {
        for(int i = 0; i < 5; i++)
            this->marks[i] = m[i];
    }

    float *getMarks() {
        return marks;
    }

    College getCollegeObject() {
        return cobj;
    }
};
string College::principal_name = "John";

void Student::getStudentDetails() {
    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter the five subject marks: " << endl;
    for(int i = 0; i < 5; i++)
        cin >> marks[i];
}

float Student::calculateAverage() {
    float sum = 0;
    for(int i = 0; i < 5; i++)
        sum = sum + marks[i];
    average = sum / 5;
    return average;
}

char Student::findGrade() {
    if(average <= 100 && average >= 80)
        grade = 'O';
    else if(average < 80 && average >= 50)
        grade = 'A';
    else
        grade = 'F';
    return grade;
}

void Student::displayStudentDetails() {
    cout << "Student Name: " << name << endl;
    cout << "Student ID: " << id << endl;
    cout << "Principal Name: " << cobj.getPrincipalName() << endl;
    cout << "Average: " << calculateAverage() << endl;
    cout << "Grade: " << findGrade() << endl;
}

int main() {
    Student s1;
    s1.getStudentDetails();
    s1.displayStudentDetails();
    return 0;
}