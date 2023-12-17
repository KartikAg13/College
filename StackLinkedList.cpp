#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

class Stack {
    public:
    Node *top;

    Stack() {
        top = NULL;
    }

    void push(int data);
    void pop();
    int peek();
    void display();
};

void Stack::push(int n) {
    Node *newNode = new Node();
    newNode->data = n;
    if(top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    Node *temp;
    if(top == NULL) {
        cout << "Stack Underflow" << endl;
        return ;
    }
    temp = top;
    top = top->next;
    delete temp;
}

int Stack::peek() {
    if(top == NULL) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return top->data;
}

void Stack::display() {
    Node *temp;
    if(top == NULL) {
        cout << "Stack Underflow" << endl;
        return ;
    }
    else {
        temp = top;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    Stack st;
    st.push(30);
    st.push(20);
    st.push(50);
    st.push(70);
    st.display();
    st.pop();
    int top_value = st.peek();
    if(top_value != -1)
        cout << "Top value is: " << top_value << endl;
    cout << "Elements after pop operation: ";
    st.display();
    return 0;
}