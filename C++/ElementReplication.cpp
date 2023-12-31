#include <iostream>
#include <exception>

using namespace std;

void elementReplication() {
    int n, pos;
    cout << "Enter the size of an array: ";
    cin >> n;
    int ar[n];
    cout << "Enter the array elements: " << endl;
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    cout << "Enter the position of the element to be replicated: ";
    cin >> pos;
    if(pos < n ) {
        ar[n] = ar[pos];
        for(int i = 0; i <= n; i++)
            cout << ar[i] << "\t";
    }
    else 
        throw runtime_error("Array index is out of range");
}

int main() {
    try {
        elementReplication();
    }
    catch(runtime_error &e) {
        cerr << e.what();   //standard error stream displaying the string identifying exception
    }
    return 0;
}