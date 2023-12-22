#include <iostream>

using namespace std;

int main() {
    int noOfTickets = 0;
    int kingClass = 75;
    int queenClass = 150;
    float totalCost = .0F;
    char refreshment, couponCode, circle;
    cout << "Enter the no of ticket: ";
    cin >> noOfTickets;
    if(noOfTickets >= 5 && noOfTickets <= 40) {
        cout << "Do you want refreshment: ";
        cin >> refreshment;
        cout << "Do you have coupon code: ";
        cin >> couponCode;
        cout << "Enter the circle: ";
        cin >> circle;
        if(circle == 'k')
            totalCost = noOfTickets * kingClass;
        else if(circle == 'q')
            totalCost = noOfTickets * queenClass;
        else
            cout << "Invalid Input" << endl;
        if(noOfTickets > 20)
            totalCost = totalCost - totalCost * .1;
        if(couponCode == 'y')
            totalCost = totalCost - totalCost * .02;
        if(refreshment == 'y')
            totalCost = totalCost + noOfTickets * 50;
        cout << "Ticket Cost: $" << totalCost << endl;
    }
    else
        cout << "Minimum of 5 and Maximum of 40 Tickets" << endl;
} 