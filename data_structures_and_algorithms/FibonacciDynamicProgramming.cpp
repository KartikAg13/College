#include <iostream>

using namespace std;

int fibonacci(int);

int array[100] = {};

int main() {
    int number {0};
    cout << "Please enter any number: ";
    cin >> number;
    for(int i = 0; i < 100; i++) {
        array[i] = -1;
    }
    cout << fibonacci(number) << endl;
    return 0;
}

int fibonacci(int x) {
    if(x == 0 || x == 1)
        return x;
    else if(x == 2)
        return 1;
    if(array[x] != -1)
        return array[x];
    array[x] = fibonacci(x - 1) + fibonacci(x - 2);
    return array[x];
}