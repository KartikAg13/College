#include <iostream>
using namespace std;
class Complex {
    public:
    int real, imaginary;

    Complex() {
        real = imaginary = 0;
    }

    Complex operator+(const Complex &object) {
        Complex result;
        result.real = real + object.real;
        result.imaginary = imaginary + object.imaginary;
        return result;
    }

    void input() {
        cout << "Please enter the real part: ";
        cin >> real;
        cout << "Please enter the imaginary part: ";
        cin >> imaginary;
    }

    void display() {
        cout << "Complex number: " << real << " + " << imaginary << "i" << endl;
    }
};
int add(int n1, int n2) {
    return (n1 + n2);
}
Complex add(Complex c1, Complex c2) {
    return (c1 + c2);
}
int **add(int **m1, int **m2, int rows, int columns) {
    int **result = new int*[rows];
    for(int r = 0; r < rows; r++) {
        result[r] = new int[columns];
        for(int c = 0; c < columns; c++)
            result[r][c] = m1[r][c] + m2[r][c];
    }
    return result;
}
void input(int **matrix, int rows, int columns) {
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < columns; c++)
            cin >> matrix[r][c];
    }
}
void display(int **matrix, int rows, int columns) {
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < columns; c++)
            cout << matrix[r][c] << "\t";
        cout << endl;
    }
}
int main() {
    int n1, n2, n3;
    cout << "Natural number 1:" << endl;
    cin >> n1;
    cout << "Natural number 2:" << endl;
    cin >> n2;
    n3 = add(n1, n2);
    cout << "Natural number: " << n3 << endl;

    Complex c1, c2, c3;
    cout << endl << "Complex number 1:" << endl;
    c1.input();
    cout << "Complex number 2:" << endl;
    c2.input();
    c3 = add(c1, c2);
    c3.display();

    int rows, columns;
    cout << endl << "Please enter the number of rows: ";
    cin >> rows;
    cout << "Please enter the number of columns: ";
    cin >> columns;
    int **m1 = new int*[rows];
    int **m2 = new int*[rows];
    int **m3 = new int *[rows];
    for(int index = 0; index < rows; index++) {
        m1[index] = new int[columns];
        m2[index] = new int[columns];
        m3[index] = new int[columns];
    }
    cout << "Matrix 1:" << endl;
    input(m1, rows, columns);
    cout << "Matrix 2:" << endl;
    input(m2, rows, columns);
    m3 = add(m1, m2, rows, columns);
    cout << "Matrix: " << endl;
    display(m3, rows, columns);
    return 0;
}