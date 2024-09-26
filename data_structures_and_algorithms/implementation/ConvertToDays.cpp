#include <iostream>

using namespace std;

string convertToDays(int num) {
    if(num == 1)
        return "Monday";
    else if(num == 2)
        return "Tuesday";
    else if(num == 3)
        return "Wednesday";
    else if(num == 4)
        return "Thursday";
    else if(num == 5)
        return "Friday";
    else if(num == 6)
        return "Saturday";
    else if(num == 7)
        return "Sunday";
    else
        return "Invalid";
}

int main() {
    int num = 0;
    cout << "Please enter any number: ";
    cin >> num;
    cout << convertToDays(num) << endl;
    return 0;
}