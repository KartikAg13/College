#include <iostream>
using namespace std;
class Stack {
    public:
    char data;
    int size;
    int top;
    int *array;

    Stack(int value) {
        size = value;
        top = -1;
        array = new int[size];
    }

    void push(char value) {
        if(top == size - 1)
            cout << "Stack Overflow" << endl;
        else
            array[++top] = value;
    }

    char pop() {
        if(top == -1)
            cout << "Stack Underflow" << endl;
        else
            return array[top--];
    }

    char Top() {
        if(top == -1)
            cout << "Stack is empty" << endl;
        else
            return array[top];
    }

    int Size() {
        return top + 1;
    }

    bool isEmpty() {
        if(top == -1)
            return true;
        return false;
    }
};
int main() {
    int size = 0;
    string sentence;
    cout << "Please enter a string: ";
    cin >> sentence;
    size = sentence.length();
    Stack *stack = new Stack(size);
    char value = sentence[0];
    if(value == ')' || value == '}' || value == ']') {
        cout << "False" << endl;
        return 0;
    }
    else {
        stack->push(value);
        for(int index = 1; index < size; index++) {
            value = sentence[index];
            if(value == ')' && stack->Top() == '(' || value == ']' && stack->Top() == '[' || value == '}' && stack->Top() == '{')
                stack->pop();
            else if(value == '(' || value == '{' || value == '[')
                stack->push(value);
        }
        if(stack->isEmpty())
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}