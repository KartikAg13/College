#include <iostream>

using namespace std;

int minimumNumbers(int); 

int array[100] = {};

int main() {
    int number {0};
    cout << "Please enter any number: ";
    cin >> number;
    for(int i = 0; i < 100; i++) 
        array[i] = 999999;
    return 0;
}

int minimumNumbers(int x) {
    if(x > -1 && x < 4)
        return x;
    
    for(int i = 1; i * i <= x; i++) 
        answer = min(answer, 1 + minimumNumbers(x - i * i));
}