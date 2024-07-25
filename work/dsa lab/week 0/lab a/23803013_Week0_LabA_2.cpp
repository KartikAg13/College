#include <iostream>
using namespace std;
void find_frequency(int *, int);
bool search(int *, int, int);
int main() {
    int length = 0;
    cout << "Please enter the length of the array: ";
    cin >> length;
    int array[length];
    cout << "Please enter the elements:" << endl;
    for(int index = 0; index < length; index++)
        cin >> array[index];
    find_frequency(array, length);
    return 0;
}
void find_frequency(int *array, int length) {
    int count = 0;
    int unique[length];
    int unique_length = 0;
    for(int i = 0; i < length; i++) {
        if(!search(unique, unique_length, array[i])) {
            for(int j = i; j < length; j++) {
                if(array[i] == array[j])
                    count++;
            }
            cout << "Frequency of " << array[i] << " is " << count << endl;
            count = 0;
            unique[unique_length++] = array[i];
        }
    }
}
bool search(int *unique, int length, int value) {
    for(int index = 0; index < length; index++) {
        if(value == unique[index])
            return true;
    }
    return false;
}