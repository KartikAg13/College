#include <iostream>
using namespace std;
double calculate_average(int *, int);
int main() {
    int length = 0;
    cout << "Please enter the length of the array: ";
    cin >> length;
    int array[length];
    cout << "Please enter the elements:" << endl;
    for(int index = 0; index < length; index++)
        cin >> array[index];
    double average = calculate_average(array, length);
    cout << "Average: " << average << endl;
    return 0;
}
double calculate_average(int *array, int length) {
    double sum = 0;
    for(int index = 0; index < length; index++)
        sum = sum + array[index];
    return (sum / length);
}