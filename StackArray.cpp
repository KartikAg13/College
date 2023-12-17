#include <iostream>
#define MAX 10

using namespace std;

class Stack {
    int top;

    public:
    int arr[MAX];

    Stack() {
        top = -1;
    }

    void push(int item);
    int pop();
    int peek();
};

void Stack::push(int item) {
    if(top >= (MAX - 1))
        cout << "Stack Overflow" << endl;
    else {
        arr[++top] = item;
        cout << "Element added: " << item << endl;
    }
}

int Stack::pop() {
    if(top < 0) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
        return arr[top--];
}

int Stack::peek() {
    if(top < 0) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
        return arr[top--];
}

int main() {
    Stack st;
    st.push(8);
    st.push(4);
    st.push(5);
    st.push(9);
    int value = st.pop();
    if(value != -1)
        cout << "Deleted element: " << value << endl;
    int top = st.peek();
    if(top != -1)
        cout << "Top element: " << top << endl;
    return 0;
}