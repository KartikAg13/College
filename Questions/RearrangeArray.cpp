#include <iostream>

using namespace std;

int *rearrange(int *array, int size) {
    int index = 0, correct_index = 0;
    while(index < size) {
        correct_index = *(array + index);
        if(*(array + index) != -1 && *(array + index) != *(array + correct_index))
            swap(*(array + index), *(array + correct_index));
        else
            index++;
    }
    return array;
}

int main() {
    int size = 0, index = 0;
    cout << "Please enter the size of the array: ";
    cin >> size;
    int *array = new int[size]();
    cout << "Please enter the elements:" << endl;
    for(index; index < size; index++)
        cin >> *(array + index);
    array = rearrange(array, size);
    for(index = 0; index < size; index++)
        cout << *(array + index) << ' ';
    cout << endl;
    return 0;
}