#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &array, int low, int high) {
    int pivot = array[high];
    int index = low - 1;
    for(int j = low; j < high; j++) {
        if(array[j] < pivot) {
            index++;
            swap(array[index], array[j]);
        }
    }
    swap(array[index + 1], array[high]);
    return index + 1;
}

void quickSort(vector<int> &array, int low, int high) {
    if(low < high) {
        int partition_index = partition(array, low, high);
        quickSort(array, low, partition_index - 1);
        quickSort(array, partition_index + 1, high);
    }
}

int main() {
    vector<int> array = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int length = array.size();
    quickSort(array, 0, length - 1);
    for(int index = 0; index < length; index++)
        cout << array[index] << " ";
    cout << endl;
    return 0;
}