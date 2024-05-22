#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream out;
    ifstream in;
    string line;
    out.open("/home/kartik/Desktop/College/Assignment/destination.txt", ios::app);
    in.open("/home/kartik/Desktop/College/Assignment/source.txt");
    if(!out.is_open() && !in.is_open()) {
        cout << "Unable to open source file" << endl;
        exit(1);
    }
    while(getline(in, line))
        out << line << endl;
    in.close();
    out.close();
    in.open("/home/kartik/Desktop/College/Assignment/destination.txt");
    while(getline(in, line))
        cout << line << endl;
    in.close();
    return 0;
}