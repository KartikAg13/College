#include <iostream>
#include <vector>

using namespace std;

class SecondLargest {
    public:
    vector<int> numbers;
    int second_largest;

    SecondLargest() {
        second_largest = 0;
    }

    int secondLargestInVector(int largest) {
        int second_largest = -999999;
        for(int index = 1; index < numbers.size(); index++) {
            if(second_largest < numbers.at(index) && numbers.at(index) < largest)
                second_largest = numbers.at(index);
        }
        return second_largest;
    }
};

int main() {
    SecondLargest object;
    int number = 0, length = 0, index = 0, maximum = -999999;
    do {
        cout << "Please enter any number: ";
        cin >> length;
    } while(length <= 0);
    cout << "Please enter the elements:" << endl;
    for(index = 0; index < length; index++) {
        cin >> number;
        if(maximum < number)
            maximum = number;
        object.numbers.push_back(number);
    }
    cout << "Second Largest: " << object.secondLargestInVector(maximum) << endl;
    return 0;
}