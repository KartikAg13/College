#include<iostream>
#include<math.h>
using namespace std;
int isPrime(int x) {
    for(int i = 2; i <= sqrt(x); i++) {
        if(x % i == 0)
            return 0;
    }
    return 1;
}  
int main() {
    int size, max = -999999;
    cout << "Please enter the size of the array: ";
    cin >> size;
    int array[size];
    cout << "Please enter the elements of the array: " << endl;
    for(int i = 0; i < size; i++) {
        cin >> array[i];
        if(max < array[i])
            max = array[i];
    }
    int number[max + 1] = {};
    for(int i = 0; i < size; i++) {
        if(array[i] > 0 && isPrime(array[i]))
            number[array[i]] = array[i];
        else if(array[i] > 0 && !isPrime(array[i]))
            number[array[i]] = -1;  
    }
    for(int i = 2; i <= max; i++) {
        if(number[i] == 0 && isPrime(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "No prime number missing" << endl;
    return 0;
}
