#include <iostream>

using namespace std;

template <class T>
void swapValues(T val1, T val2) {
    T temp = val1;
    val1 = val2;
    val2 = temp;
    cout << "val1: " << val1 << "\t" << "val2: " << val2 << endl;
}

int main() {
    int x1, x2;
    double d1, d2;
    char c1, c2;
    cout << "Enter integer values: " << endl;
    cin >> x1 >> x2;
    cout << "Enter decimal values: " << endl;
    cin >> d1 >> d2;
    cout << "Enter character values: " << endl;
    cin >> c1 >> c2;
    cout << "Before Swap:" << endl;
    cout << "x1: " << x1 << "\t" << "x2: " << x2 << endl;
    cout << "d1: " << d1 << "\t" << "d2: " << d2 << endl;
    cout << "c1: " << c1 << "\t" << "c2: " << c2 << endl;
    cout << "After Swap:" << endl;
    swapValues <int> (x1, x2);
    swapValues <double> (d1, d2);
    swapValues <char> (c1, c2);
    return 0;
}