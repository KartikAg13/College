#include <iostream>
#include <vector>

using namespace std;

class MoveZeroesToEnd {
    public:
    vector<int> numbers;

    void moveZeroesToEnd(int index, int first_index) {
        int swap = 0;
        while(first_index < numbers.size()) {
            if(numbers.at(first_index) == 0) {
                first_index++;
                index--;
            }
            else if(numbers.at(index) == 0 && numbers.at(first_index) != 0) {
                swap = numbers.at(index);
                numbers.at(index) = numbers.at(first_index);
                numbers.at(first_index) = swap;
                first_index++;
            }
            index++;
        }
    }
};

int main() {
    MoveZeroesToEnd object;
    int number = 0, length = 0, index = 0, first_index = 0;
    do {
        cout << "Please enter any number: ";
        cin >> length;
    } while(length <= 0);
    cout << "Please enter the elements:" << endl;
    for(index = 0; index < length; index++) {
        cin >> number;
        object.numbers.push_back(number);
    }
    for(index = 0; object.numbers.at(index) != 0; index++);
    for(first_index = index; object.numbers.at(first_index) == 0; first_index++);
    object.moveZeroesToEnd(index, first_index);
    for(index = 0; index < length; index++)
        cout << object.numbers.at(index) << " ";
    cout << endl;
    return 0;
}