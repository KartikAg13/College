#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int idx = 0;
    cout << "Please enter the size of array: ";
    cin >> n;
    int array[n];
    cout << "Please enter the elements of array: " << endl;
    for(idx = 0; idx < n; idx++)
        cin >> array[idx];
    cout << "Array elements are: " << endl;
    for(idx = 0; idx < n; idx++)
        cout << array[idx] << " ";
    return 0;
}