#include <iostream>
using namespace std;
class Matrix {
    public:
    int matrix[2][2];

    void input() {
        cout << "Please enter the elements:" << endl;
        for(int row = 0; row < 2; row++) {
            for(int column = 0; column < 2; column++)
                cin >> matrix[row][column];
        }
    }

    bool operator==(const Matrix &object) {
        for(int row = 0; row < 2; row++) {
            for(int column = 0; column < 2; column++) {
                if(matrix[row][column] != object.matrix[row][column])
                    return false;
            }
        }
        return true;
    }
};
int main() {
    Matrix ob1, ob2;
    ob1.input();
    ob2.input();
    if(ob1 == ob2)
        cout << "Both are equal" << endl;
    else
        cout << "Not equal" << endl;
    return 0;
}