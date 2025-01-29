#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &array, int low, int high, int key) {
    if(low > high)
        return -1;
    
    int middle = low + (high - low) / 2;
    
    if(array[middle] == key)
        return middle;
    else if(array[middle] < key)
        return binarySearch(array, middle + 1, high, key);
    else
        return binarySearch(array, low, middle - 1, key);
}

int main() {
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = array.size();
    int index = binarySearch(array, 0, length - 1, 11);
    cout << "Result: " << index << endl;
    return 0;
}