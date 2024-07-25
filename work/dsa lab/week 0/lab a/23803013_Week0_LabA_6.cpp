#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    int length = 0;
    cout << "Please enter the length of the array: ";
    cin >> length;
    int array[length];
    for(int index = 0; index < length; index++)
        array[index] = rand() % 100;
    for(int index = 0; index < length; index++) {
        if(array[index] % 2 == 0)
            cout << array[index] << " ";
    }
    for(int index = 0; index < length; index++) {
        if(array[index] % 2 != 0)
            cout << array[index] << " ";
    }
    cout << endl;
    return 0;
}