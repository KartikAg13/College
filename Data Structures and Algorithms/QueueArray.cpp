#include <iostream>
#define MAX 10

using namespace std;

class Queue {
    int front = 0;
    int rear = 0;
    int arr[MAX];

    public:
    Queue() {
        front = rear = -1;
    }

    void enQueue(int item);
    void deQueue();
};

void Queue::enQueue(int item) {
    if(rear == MAX - 1) 
        cout << "Queue Overflow" << endl;
    else if(front == -1 && rear == -1) {
        front = rear = 0;
        arr[rear] = item;
        cout << "Item inserted: " << item << endl;
    }
    else {
        rear++;
        arr[rear] = item;
        cout << "Item inserted: " << item << endl;
    }
}

void Queue::deQueue() {
    int item = 0;
    if(rear == -1)
        cout << "Queue Underflow" << endl;
    else {
        item = arr[front];
        if(front == rear)
            front = rear = -1;
        else
            front++;
        cout << "Item deleted: " << item << endl;
    }
}

int main() {
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    return 0;
}