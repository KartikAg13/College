#include<iostream>
using namespace std;
int main() {
// Initial value of var.
int var = 10;

cout << "Address of var" << &var << endl;
cout << "Value of var" << var << endl;
int *memory = new (&var) int (100);
cout << "After placement new - \n";
cout << "Address of var" << &var << endl;
cout << "Value of var" << var << endl;
cout << "Address of mem" << memory << endl;
return 0;
}