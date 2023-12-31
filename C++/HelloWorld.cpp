#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    /*
    To print a random number we calculate the number of seconds from 1970.
    Then we use that number of generate a random number.
    This gives a very large random number so we just extract the last digit to get a random number from 0 - 9.
    */
    short min = 25;
    short max = 75;
    srand(time(nullptr));
    int r = (rand() % (max - min + 1)) + min;
    float a {0b11111111};   //255 = 0b11111111 = 0xff
    long b = 1'000'000L;
    bool value = false;
    cout << "Please enter any two numbers: ";
    cin >> a >> b;  //a = 2.1, b = 3
    auto c = floor(a);  //c = 2
    unsigned const int x = pow(a, b);    //x = 9
    cout << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl << "r = " << r << endl << "x = " << x << endl;
    cout << "z = " << ((x + r) / (c * b)) << endl;   //0xff = 255
    return 0;

}