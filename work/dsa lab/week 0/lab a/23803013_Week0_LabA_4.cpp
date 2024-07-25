#include <iostream>
using namespace std;
int main() {
    int length = 0;
    cout << "Please enter the length of the array: ";
    cin >> length;
    int array[length];
    cout << "Please enter the elements:" << endl;
    for(int index = 0; index < length; index++)
        cin >> array[index];
    int minimum = array[0];
    int second_smallest = array[0];
    for(int index = 1; index < length; index++) {
        if(minimum > array[index])
            minimum = array[index];
    }
    for(int index = 1; index < length; index++) {
        if(second_smallest > array[index] && array[index] != minimum)
            second_smallest = array[index];
    }
    cout << "Second smallest: " << second_smallest << endl;
    return 0;
}