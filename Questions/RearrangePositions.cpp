#include <iostream>
#include <vector>

using namespace std;

class RearrangePositions {
    public:
    vector<int> numbers;

    void sort() {
        int swap {0};
        for(int i = 0; i < numbers.size(); i++) {
            for(int j = 0; j < numbers.size() - i - 1; j++) {
                if(numbers.at(j) > numbers.at(j + 1)) {
                    swap = numbers.at(j);
                    numbers.at(j) = numbers.at(j + 1);
                    numbers.at(j + 1) = swap;
                }
            }
        }
    }

    void rearrangePositions() {
        int index = 0, swap = 0;
        for(index = 1; index < numbers.size() - 1; index++) {
            if(index % 2 == 0 && numbers.at(index) > numbers.at(index + 1)) {
                swap = numbers.at(index);
                numbers.at(index) = numbers.at(index + 1);
                numbers.at(index + 1) = swap;
            }
            else if(index % 2 != 0 && numbers.at(index) < numbers.at(index + 1)) {
                swap = numbers.at(index);
                numbers.at(index) = numbers.at(index + 1);
                numbers.at(index + 1) = swap;
            }
        }
    }
};

int main() {
    RearrangePositions object;
    int number = 0, length = 0, index = 0;
    do {
        cout << "Please enter any number: ";
        cin >> length;
    } while(length <= 0);
    cout << "Please enter the elements:" << endl;
    for(index = 0; index < length; index++) {
        cin >> number;
        object.numbers.push_back(number);
    }
    object.sort();
    object.rearrangePositions();
    for(index = 0; index < length; index++)
        cout << object.numbers.at(index) << " ";
    return 0;
}