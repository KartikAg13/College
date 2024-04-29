#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class StringWrapper {
    public:
    char *word;
    int length;

    StringWrapper() {}

    StringWrapper(int length) {
        this->length = length;
        word = new char[length];
    }

    void input() {
        cout << "Please enter a word: ";
        cin >> word;
        length = strlen(word);
    }

    StringWrapper operator+(StringWrapper &object) {
        StringWrapper temp(length + object.length + 1);
        for(int index = 0; index < length; index++)
            temp.word[index] = word[index];
        for(int index = 0; index < object.length; index++)
            temp.word[length + index] = object.word[index];
        return temp;
    }

    bool operator==(StringWrapper &object) {
        if(length != object.length)
            return false;
        for(int index = 0; index < length; index++) {
            if(word[index] != object.word[index])
                return false;
        }
        return true;
    }

    friend ostream &operator<<(ostream &output, StringWrapper &object);
};
ostream &operator<<(ostream &output, StringWrapper &object) {
    output << "The word is " << object.word << endl;
    output << "The length is " << object.length << endl;
    return output;
} 
int main() {
    StringWrapper w1(10);
    StringWrapper w2(10);
    StringWrapper w3;
    w1.input();
    w2.input();
    w3 = w1 + w2;
    if(w1 == w2)
        cout << "Both are equal" << endl;
    cout << w3;
    return 0;
}