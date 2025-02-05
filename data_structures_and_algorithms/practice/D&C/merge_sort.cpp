#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &array, int low, int middle, int high) {
    int n1 = middle - low + 1;
    int n2 = high - middle;
    vector<int> left(n1), right(n2);

    for(int i = 0; i < n1; i++)
        left[i] = array[low + i];
    for(int j = 0; j < n2; j++)
        right[j] = array[middle + j + 1];
    
    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j])
            array[k] = left[i++];
        else
            array[k] = right[j++];
        k++;
    }

    while(i < n1)
        array[k++] = left[i++];
    while(j < n2)
        array[k++] = right[j++];
}

void mergeSort(vector<int> &array, int left, int right) {
    if(left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

int main() {
    vector<int> array = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int length = array.size();
    mergeSort(array, 0, length - 1);
    for(int index = 0; index < length; index++)
        cout << array[index] << " ";
    cout << endl;
    return 0;
}