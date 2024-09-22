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
            cout << "Queue Overflow" << endl;
        else
            array[++top] = value;
    }

    int pop(Stack *queue) {
        if(top == -1)
            cout << "Queue Underflow" << endl;
        else {
            while(top > 0)
                queue->push(array[top--]);
            int value = array[0];
            while(queue->top > -1)
                array[top++] = queue->array[queue->top--];
            return value;
        }
    }

    int Top() {
        if(top == -1)
            cout << "Queue is empty" << endl;
        else
            return array[top];
    }

    int Size() {
        return top + 1;
    }
};
int main() {
    int size = 0;
    cout << "Please enter the size of the queue: ";
    cin >> size;
    Stack *q1 = new Stack(size);
    Stack *q2 = new Stack(size);
    q1->push(10);
    q1->push(20);
    q1->push(30);
    cout << "Deleted: " << q1->pop(q2) << endl;
    cout << "Top Element: " << q2->Top() << endl;
    cout << "Size: " << q1->Size() << endl;
    return 0;
}