#include <iostream>

using namespace std;

int main() {
    int employeeId = 0;
    int workingHours = 0;
    int salaryPerHour = 0;
    int totalSalary = 0;
    cout << "Input the Employee ID: ";
    cin >> employeeId;
    cout << "Input the working hrs: ";
    cin >> workingHours;
    cout << "Salary amount/hr: ";
    cin >> salaryPerHour;
    totalSalary = salaryPerHour * workingHours;
    cout << "Employee ID = " << employeeId << endl;
    cout << "Salary = " << totalSalary << endl;
    return 0;
}