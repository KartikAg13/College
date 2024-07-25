#include <iostream>
using namespace std;
void display(int *, int);
int main() {
    int length = 0;
    cout << "Please enter the length of the array: ";
    cin >> length;
    int array[length];
    cout << "Please enter the elements:" << endl;
    for(int index = 0; index < length; index++)
        cin >> array[index];
    cout << "Array elements before rotating: ";
    display(array, length);
    for(int index = 0; index < length - 1; index++) {
        int swap = array[index];
        array[index] = array[index + 1];
        array[index + 1] = swap;
    }
    cout << "Array elements after rotating: ";
    display(array, length);
}
void display(int *array, int length) {
    for(int index = 0; index < length; index++)
        cout << array[index] << " ";
    cout << endl;
}