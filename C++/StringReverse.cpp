#include <iostream>

using namespace std;

char *reverseString(char *p) {
    char *str = p;
    int length = 0;
    while(*str != '\0') {
        str++;
        length++;
    }
    char *p1 = p;   //First character
    char *p2 = p + length - 1;  //Last character
    while(p1 < p2) {    //Swaps the first and last character in each iteration
        char temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
    }
    return p;
}

int main() {
    char str[100];
    cout << "Enter the string: ";
    cin >> str;
    char *p = str;
    cout << "Revresed string: ";
    char *result = reverseString(p);
    while(*result != '\0') {
        cout << *result;
        result++;
    }
    cout << endl;
    return 0;
}