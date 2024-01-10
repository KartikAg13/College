#include <iostream>
#include <vector>

using namespace std;

class MaxMinAlternate {
    public:
    int *array;
    vector<int> output;
    int *start, *end;

    MaxMinAlternate() {
        array = new int[100]();
        start = end = nullptr;
    }

    void rearrange() {
        int index = 0, number = 0;
        while(start < end) {
            output.push_back(*(array + ));
        }
    }
};

int main() {
    MaxMinAlternate object;
    int number = 0, length = 0, index = 0, first_index = 0;
    do {
        cout << "Please enter any number: ";
        cin >> length;
    } while(length <= 0);
    cout << "Please enter the elements:" << endl;
    for(index = 0; index < length; index++) {
        cin >> number;
        *(object.array + index) = number;
    }
    object.start = object.array;
    object.end = object.array + length - 1;
    object.rearrange();
    for(index = 0; index < length; index++) {
        cout << object.output.at(index) << " ";
    }
    return 0;
} 