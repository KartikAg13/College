#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int toFind) {
    int index = 0;
    int retVal = -1;
    for(index = 0; index < size; index++) {
        if(toFind == arr[index]) {
            retVal = index;
            break;
        }
    }
    return retVal;
}

bool binarySearch(int arr[], int key, int low, int high) {
    int middle = (low + high) / 2;
    while(low <= high) {
        if(arr[middle] == key)
            return true;
        else if(arr[middle] < key)
            low = middle + 1;
        else
            high = middle - 1;
        middle = (low + high) / 2;
    }
    return false;
}

int main() {
    int i = 0;
    int arr[10];
    int key = 0;
    cout << "Please enter 10 elements in ascending order: " << endl;
    for(i = 0; i < 10; i++)
        cin >> arr[i];
    cout << "Enter element to be searched: ";
    cin >> key;
    int linear = linearSearch(arr, 10, key);
    bool binary = binarySearch(arr, key, 0, 9);
    if(linear >= 0 && binary != false)
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}