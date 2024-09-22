#include<iostream>
using namespace std;
class Queue {
    private:
    int size;
    int front;
    int back;
    int *array;

    public:
    Queue(int value) {
        size = value;
        front = back = -1;
        array = new int[size];
    }

    void push(int value) {
        if(front == -1 && back == -1) {
            array[++back] = value;
            front = 0;
        }
        else if(back == size - 1)
            cout << "Stack Overflow" << endl;
        else
            array[++back] = value;
    }

    int Size() {
        return back - front + 1;
    }

    int pop() {
        if(front == back) {
            int value = array[front];
            front = back = -1;
            return value;
        }
        else if(front == -1)
            cout << "Stack Underflow" << endl;
        else
            return array[front++];
    }

    int poping() {
        int value = Size();
        for(int index = 1; index < value; index++) {
            int value = pop();
            push(value);
        }
        return pop();
    }

    int top() {
        if(front == -1)
            cout << "Stack is empty" << endl;
        else
            return array[back];
    }
};
int main() {
    int size = 0;
    cout << "Please enter the size of the queue: ";
    cin >> size;
    Queue *stack = new Queue(size);
    stack->push(10);
    stack->push(20);
    stack->push(30);
    stack->push(40);
    cout << "Deleted: " << stack->poping() << endl;
    cout << "Top Element: " << stack->top() << endl;
    cout << "Size: " << stack->Size() << endl;
    return 0;
}