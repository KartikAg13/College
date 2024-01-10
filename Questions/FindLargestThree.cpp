#include <iostream>
#include <vector>

using namespace std;

class FindLargestThree {
    public:
    vector<int> numbers;
    int *maximum;

    FindLargestThree() {
        maximum = new int[3]();
    }

    int maximumInVector() {
        int max = numbers.at(0);
        int pos {0}; 
        for(int index = 1; index < numbers.size(); index++) {
            if(max < numbers.at(index)) {
                max = numbers.at(index);
                pos = index;
            }
        }
        numbers.erase(numbers.begin() + pos);
        return max;
    }
};

int main() {
    FindLargestThree object;
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
    if(length > 3) {
        for(index = 0; index < 3; index++)
            *(object.maximum + index) = object.maximumInVector();
    }
    else {
        for(index = 0; index < length; index++)
            *(object.maximum + index) = object.numbers.at(index);
    }   
    cout << "Largest: ";
    for(index = 0; index < 3; index++)
        cout << *(object.maximum + index) << " ";
    cout << endl;
    return 0;
}