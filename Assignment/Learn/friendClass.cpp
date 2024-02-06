#include <iostream>

using namespace std;

class Sub {
    int a, b;   //private data members

    public:
        Sub(int a, int b) {
            this->a = a;    //since the name of the data members and parameters is same, we have to use this keyword
            this->b = b;    //b = b is not correct
        }
    
        friend class Add;   //friend class
};

class Add {
    int x, y;

    public:
        Add(int x, int y) {
            this->x = x;
            this->y = y;
        }

        void display(Sub &s) {  
            int d = s.a - s.b;
            cout << "The difference is: " << d << endl;
            int a = x + y;
            cout << "The sum is: " << a << endl;
        }
};

int main() {
    Sub s(10, 5);
    Add a(10, 5);
    a.display(s);
    return 0;
}