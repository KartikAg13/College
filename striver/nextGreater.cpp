#include <iostream>
using namespace std;
class Stack {
    private:
    int size;
    int top;
    int *array;

    public:
    Stack(int value) {
        size = value;
        top = -1;
        array = new int[size];
    }

    void push(int value) {
        if(top == size - 1)
            cout << "Stack Overflow" << endl;
        else
            array[++top] = value;
    }

    int pop() {
        if(top == -1)
            cout << "Stack Underflow" << endl;
        else
            return array[top--];
    }

    int Top() {
        if(top == -1)
            cout << "Stack is empty" << endl;
        else
            return array[top];
    }

    int Size() {
        return top + 1;
    }
};
int main() {
    
}