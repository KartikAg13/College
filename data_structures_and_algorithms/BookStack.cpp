#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char box[5][10];
    char bkNo[10];
    int ch = 0;
    int top = -1;
    int i = 0;
    do {
        cout << "1. Insert a book in the box" << endl;
        cout << "2. Delete a book from the box" << endl;
        cout << "3. Display book box" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch) {
            case 1:
                if(top >= 4)
                    cout << "The box is full" << endl;
                else {
                    cout << "Enter the book no.: ";
                    cin >> bkNo;
                    top++;
                    strcpy(box[top], bkNo);
                }
                break;
            case 2:
                if(top == -1)
                    cout << "The box is empty" << endl;
                else {
                    cout << "The book deleted from the box is: " << box[top] << endl;
                    top--;
                }
                break;
            case 3:
                if(top == -1)
                    cout << "The box is empty" << endl;
                else {
                    cout << "The books in the box: ";
                    for(i = top; i >= 0; i--)
                        cout << box[i] << " ";
                    cout << endl;
                }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid option" << endl;
        }
    } while(true);
    return 0;
}