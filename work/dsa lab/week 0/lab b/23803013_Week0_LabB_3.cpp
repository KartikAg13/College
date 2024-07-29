#include <iostream>
using namespace std;
class User {
public:
    string name;
    double p_cpu, p_keyboard, p_lan;
    int q_cpu, q_keyboard, q_lan;

    User() {
        name = " ";
        p_cpu = p_keyboard = p_lan = 0.0;
        q_cpu = q_keyboard = q_lan = 0;
    }

    void input() {
        cout << "Please enter the name: ";
        cin >> name;
        cout << "Quantity of CPU: ";
        cin >> q_cpu;
        cout << "Price of CPU: ";
        cin >> p_cpu;
        cout << "Quantity of Keyboard: ";
        cin >> q_keyboard;
        cout << "Price of Keyboard: ";
        cin >> p_keyboard;
        cout << "Quantity of LAN: ";
        cin >> q_lan;
        cout << "Price of LAN: ";
        cin >> p_lan;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Quantity and Price of CPU: " << q_cpu << "\t" << p_cpu << endl;
        cout << "Quantity and Price of Keyboard: " << q_keyboard << "\t" << p_keyboard << endl;
        cout << "Quantity and Price of LAN: " << q_lan << "\t" << p_lan << endl;
    }
};
int main() {
    User *vendor = new User[10];
    for(int index = 0; index < 3; index++) {
        cout << "Please enter the details of Vendor " << index + 1 << endl;
        vendor[index].input();
        cout << endl;
    }
    int max_q_lan = vendor[0].q_lan;
    double min_p_keyboard = vendor[0].p_keyboard;
    for(int index = 0; index < 3; index++) {
        if(max_q_lan < vendor[index].q_lan)
            max_q_lan = vendor[index].q_lan;
        if(min_p_keyboard > vendor[0].p_keyboard)
            min_p_keyboard = vendor[0].p_keyboard;
        cout << "User " << index + 1 << endl;
        vendor[index].print();
        cout << endl;
    }
    cout << "Maximum quantity of LAN Cable: " << max_q_lan << endl;
    cout << "Lowest selling price of Keyboard: " << min_p_keyboard << endl;
    return 0;
}