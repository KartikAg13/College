/*
Smallest prime number missing in an array: Given an array containing n distinct
numbers. The task is to find the smallest prime which is not present in the array.
*/

#include <iostream>
#include <math.h>

using namespace std;

class Node {
    public:
    int value;
    Node *next;

    int isPrime(int x) {
        for(int i = 2; i <= sqrt(x); i++) {
            if(x % i == 0)
                return 0;
        }
        return 1;
    }
};

class LinkedList {
    public:
    Node *head;
    Node *tail;
    int *array;

    LinkedList(int size) {
        head = NULL;
        tail = NULL;
        array = new int[size]();
    }

    void insertNodeAtEnd(int number) {
        Node *current = new Node();
        current->value = number;
        current->next = NULL;
        if(head == NULL) {
            head = current;
            tail = head;
        }
        else {
            tail->next = current;
            tail = tail->next;
        }
    }

    void traversal() {
        Node *current = head;
        int data;
        while(current != NULL) {
            data = current->value;
            if(current->isPrime(data) && data > 0)
                *(array + data) = data;
            else if(!current->isPrime(data) && data > 0)
                *(array + data) = -1;
            current = current->next;
        }
        delete current;
    }

    int maximum() {
        Node *current = head;
        int max = current->value;
        while(current != NULL) {
            if(max < current->value)
                max = current->value;
            current = current->next;
        }
        delete current;
        return max;
    }
};

int main() {
    int number, choice = 1;
    LinkedList list(50);
    Node node;
    while(choice) {
        cout << "Please enter any number: ";
        cin >> number;
        list.insertNodeAtEnd(number);
        cout << "0. No other element" << endl << "1. Add another element" << endl;
        cin >> choice;
    }
    list.traversal();
    int max = list.maximum();
    for(int i = 2; i <= max; i++) {
        if(*(list.array + i) == 0 && node.isPrime(i)) {
            cout << "min: " << i << endl;
            return 0;
        }
    }
    cout << "No prime number missing" << endl;
    return 0;
}