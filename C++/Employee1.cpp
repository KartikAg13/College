#include <iostream>

using namespace std;

struct Employee {
    int empID;
    int basicSalary;
    int pf;
    int med;
    float sales;

    int calc_Bonus() {
        int bonus = 0;
        if(basicSalary <= 7000 && sales <= 10)
            bonus = 1500;
        else if(basicSalary <= 7000 && sales > 10)
            bonus = 3000;
        else if(basicSalary > 7000 && basicSalary <= 15000 && sales <= 10)
            bonus = 2000;
        else if(basicSalary <= 7000 && basicSalary <= 15000 && sales > 10)
            bonus = 4000;
        else if(basicSalary > 15000 && sales <= 10)
            bonus = 2500;
        else if(basicSalary > 15000 && sales > 10)
            bonus = 4500;
        return bonus;
    }

    int calc_NetSalary() {
        int netSalary = basicSalary - pf - med;
        return netSalary;
    }
};

int main() {
    struct Employee emp;
    cout << "Enter the employee id: ";
    cin >> emp.empID;
    cout << "Enter the basic salary: ";
    cin >> emp.basicSalary;
    cout << "Enter the PF amount: ";
    cin >> emp.pf;
    cout << "Enter the med amount: ";
    cin >> emp.med;
    cout << "Enter the sales percentage: ";
    cin >> emp.sales;
    if(emp.empID <= 0 || emp.basicSalary <= 0 || emp.pf <= 0 || emp.med <= 0 || emp.sales <= 0)
        cout << "Unable to calculate salary" << endl;
    else {
        int bonus = emp.calc_Bonus();
        int netSalary = emp.calc_NetSalary();
        int totalSalary = netSalary + bonus;
        cout << "Total salary with bonus: $" << totalSalary << endl;
    }
    return 0;
}