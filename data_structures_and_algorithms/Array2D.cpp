#include <iostream>

using namespace std;

int main() {
    int row = 0;
    int column = 0;
    cout << "Please enter the number of rows and columns: " << endl;
    cin >> row >> column;
    int array[row][column];
    cout << "Please enter the elements of matrix: " << endl;
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < column; c++)
            cin >> array[r][c];
    }
    cout << "Matrix elements are: " << endl;
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < column; c++)
            cout << array[r][c] << " ";
        cout << endl;
    }
    return 0;
}