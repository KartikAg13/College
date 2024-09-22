#include <iostream>
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
            cout << "Queue Overflow" << endl;
        else
            array[++back] = value;
    }

    int pop() {
        if(front == back) {
            int value = array[front];
            front = back = -1;
            return value;
        }
        else if(front == -1)
            cout << "Queue Underflow" << endl;
        else
            return array[front++];
    }

    int top() {
        if(front == -1)
            cout << "Queue is empty" << endl;
        else
            return array[front];
    }

    int Size() {
        return back - front + 1;
    }
};
int main() {
    int size = 0;
    cout << "Please enter the size of the queue: ";
    cin >> size;
    Queue *queue = new Queue(size);
    queue->push(10);
    queue->push(20);
    queue->push(30);
    queue->push(40);
    cout << "Deleted: " << queue->pop() << endl;
    cout << "Top Element: " << queue->top() << endl;
    cout << "Size: " << queue->Size() << endl;
    return 0;
}