#include <iostream>
using namespace std;
class Array {
    public:
    int *array;
    int length;

    Array() {}

    Array(int length) {
        this->length = length;
        array = new int[length];
    }

    void input() {
        cout << "Please enter the elements: " << endl;
        for(int index = 0; index < length; index++)
            cin >> array[index];
    }

    int &operator[](int index) {
        if(index < 0 && index >= length) {
            cout << "Wrong index position" << endl;
            exit(1);
        }
        return array[index];
    }
};
int main() {
    Array arr(5);
    arr[1] = 10;
    for(int index = 0; index < arr.length; index++)
        cout << arr[index] << " ";
    cout << endl;
    return 0;
}