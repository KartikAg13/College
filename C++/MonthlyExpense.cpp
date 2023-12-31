#include <iostream>

using namespace std;

class MonthlyExpense {
    private:
    double household_exp;
    double medical;

    public:
    void setHouseHoldExpense(double houseExp) {
        household_exp = houseExp;
    }

    void setMedicalExpense(double medicalExp) {
        medical = medicalExp;
    }

    double calculateNovemberMonthExpense() {
        return household_exp + medical;
    }

    double calculateDecemberMonthExpense() {
        return household_exp + medical;
    }

    double calculateTotalExpense() {
        return household_exp + medical;
    }

    MonthlyExpense operator + (const MonthlyExpense b) {
        MonthlyExpense expense;
        expense.household_exp = household_exp + b.household_exp;
        expense.medical = medical + b.medical;
        return expense;
    }
};

int main() {
    MonthlyExpense budget1;
    MonthlyExpense budget2;
    MonthlyExpense budget3;
    double expenses = 0.0;
    double n1, n2, d1, d2;
    cout << "Enter the household expense of November: ";
    cin >> n1;
    cout << "Enter the medical expense of November: ";
    cin >> n2;
    cout << "Enter the household expense of December: ";
    cin >> d1;
    cout << "Enter the medical expense of December: ";
    cin >> d2;
    budget1.setHouseHoldExpense(n1);
    budget1.setMedicalExpense(n2);
    budget2.setHouseHoldExpense(d1);
    budget2.setMedicalExpense(d2);
    expenses = budget1.calculateNovemberMonthExpense();
    cout << "November Expenses: $" << expenses << endl;
    expenses = budget2.calculateDecemberMonthExpense();
    cout << "Decemeber Expenses: $" << expenses << endl;
    budget3 = budget1 + budget2;
    expenses = budget3.calculateTotalExpense();
    cout << "Total Expenses for the month of Nov and Dec: $" << expenses << endl;
    return 0;
}