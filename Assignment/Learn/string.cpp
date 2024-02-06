#include <iostream>
#include <string.h>
using namespace std;
class MyString {
    public:
        char *name;
        int length;

        MyString() {
            length = 1;
            name = new char[length]();
        }

        MyString(const MyString &ms) {  //copy constructor
            length = ms.length;
            name = new char[length]();
            strcpy(name, ms.name);
        }

        void operator()(char *, int);
        //alternate to parameterized constructor
        //reference "&" not used because of no return type

        ~MyString();    //destructor

        MyString operator+(MyString &ob) const {    //concatenation operation not working
            MyString result;
            delete [] result.name;
            result.length = length + ob.length;
            result.name = new char[result.length]();
            strcpy(result.name, name);
            strcat(result.name, ob.name);
            return result;
        }

        friend int operator<(MyString &, MyString &);

        void display() {
            cout << "Name: " << name << endl;
            cout << "Length: " << length << endl;
        }
};

int operator<(MyString &ob1, MyString &ob2) {
    if(strcmp(ob1.name, ob2.name) < 0)
        return true;
    else
        return false;
}

void MyString::operator()(char *n, int l) {
    length = l;
    name = new char[length]();
    strcpy(name, n);
}

MyString::~MyString() {
    delete [] name;
}

int main() {
    MyString m;
    char *s = "hello";
    int l = 6;
    m(s, l);    //calls overloaded operator () for assigning the values
    m.display();
    MyString y = m; //copy constructor
    y.display();
    MyString c;
    c = m + y;  //not working
    c.display();
    if(c < m)   
        cout << "c is less than m" << endl;
    else
        cout << "m is less than c" << endl;
    return 0;
}